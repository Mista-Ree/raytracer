cmake_minimum_required(VERSION 2.8)

# Create and customise the various different build configurations we want
# ==============================================================
macro(add_configuration IN_CONFIG_NAME CONFIG_COMPILE_FLAGS CONFIG_LINK_FLAGS)
	if(CMAKE_CONFIGURATION_TYPES)
		set(CMAKE_CONFIGURATION_TYPES ${CMAKE_CONFIGURATION_TYPES} ${IN_CONFIG_NAME} CACHE STRING "Generated Configs" FORCE)
		list(REMOVE_DUPLICATES CMAKE_CONFIGURATION_TYPES)
	endif()
	string(TOUPPER ${IN_CONFIG_NAME} CONFIG_NAME)

	#Set the flags for this configuration
	foreach(FLAGS_NAME CXX_FLAGS C_FLAGS) #Compiler flags
		set("CMAKE_${FLAGS_NAME}_${CONFIG_NAME}" ${CONFIG_COMPILE_FLAGS})
	endforeach()

	foreach(FLAGS_NAME EXE_LINKER_FLAGS MODULE_LINKER_FLAGS SHARED_LINKER_FLAGS) #Linker flags
		set("CMAKE_${FLAGS_NAME}_${CONFIG_NAME}" ${CONFIG_LINK_FLAGS})
	endforeach()
endmacro(add_configuration)

# top level module define
# ==============================================================
project(raytracer)

# Target OS specific variables
# ==============================================================
# Set system name for include folders
if (WIN32)
	set( OS_NAME win32 )
elseif (UNIX)
	set( OS_NAME Linux )
endif()


# tell find_package() where our FindXXX.cmake files are
# ==============================================================
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/src)


# Common definitions to all projects
# ==============================================================
##add_definitions("-DADEFINE")

# This variable is only set for multi-config IDE generators like MSVC
if (CMAKE_CONFIGURATION_TYPES)

	# Specify which builds to use
	set(	CMAKE_CONFIGURATION_TYPES Debug)
	list(	REMOVE_DUPLICATES CMAKE_CONFIGURATION_TYPES)
	set(	CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}"
			CACHE STRING "Semicolon separated list of supported configuration types [Debug]"
			FORCE)
endif()


# Set default build type if not specified by user
# ==============================================================
if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
	message( "" )
	message( "" )
	message( "INFO: Build type not specified, defaulting to ${CMAKE_BUILD_TYPE}." )
	message( "" )
endif()


# Info header
message(" ")
message("==============================================================================" )
message("=========================     Comms     ======================================")
message("==============================================================================" )
message("OS Name:         ${OS_NAME}")
message("Host System:     ${CMAKE_HOST_SYSTEM}")
message("Local arch:      ${CMAKE_HOST_SYSTEM_PROCESSOR}")
if (CMAKE_CONFIGURATION_TYPES)
message("Build configs:   ${CMAKE_CONFIGURATION_TYPES}")
else()
message("Build type:      ${CMAKE_BUILD_TYPE}")
endif()
message("==============================================================================" )



# Platform specific arguments
# ==============================================================
if (MSVC)

	# Visual Studio flags
	# /WX - Warning as errors
	# /GR - Use  if your code uses dynamic_cast Operator or typeid
	# /Gd - the default setting, specifies the C calling convention for all functions except C++ member functions and functions marked __stdcall or __fastcall.
	# /Gr - specifies the __fastcall calling convention for all functions except C++ member functions and functions marked __cdecl or __stdcall. All __fastcall functions must have prototypes.
	# /Gz - specifies the __stdcall calling convention for all prototyped C functions except for functions that take a variable number of arguments and functions marked __cdecl or __fastcall. All
	#       __stdcall functions must have prototypes.
	# /c  - compile only
	# /TC - option specifies that C source files even if it doesn't have a .c extension.
	# /TP - option specifies that C++ source files, even if it doesn't have a .cpp or .cxx extension
	# /Fx - produces a copy of each source file with injected code merged into the source.
	# /Yc"Precompiled.h"

	# Definitions for all build types
	# ==============================================================
	set( BUILD_DEFINITIONS /vmg /DNOMINMAX /D_CRT_SECURE_NO_WARNINGS /D_SCL_SECURE_NO_WARNINGS )
	set( BUILD_DEFINITIONS ${BUILD_DEFINITIONS} /DNTDDI_XP=0x05010000 /DWIN32 /D_WINDOWS )
	set( BUILD_DEFINITIONS ${BUILD_DEFINITIONS} /GR /W3 /WX /EHsc /Gd /nologo )
	set( BUILD_DEFINITIONS ${BUILD_DEFINITIONS} /wd4996 )	# disable warning about strdup being deprecated

	## Dont allow this for Windows XP 32bit as it causes the compiler to crash
	string( COMPARE NOTEQUAL ${CMAKE_HOST_SYSTEM} Windows-5.1 USE_MULTIPROC_COMPILE )
	if( ${USE_MULTIPROC_COMPILE} )
		set( BUILD_DEFINITIONS ${BUILD_DEFINITIONS} /MP )
	endif()

	add_definitions( ${BUILD_DEFINITIONS} )


	# Add additional optimised debug builds
	# ==============================================================
	add_configuration(	DebugOptimised
						" /MT /O2 /Ob2 /Zi"
						" /debug /INCREMENTAL:NO")
					
	
	# Add various linker flags for different builds, two general types: debug and release
	# ==============================================================
	set(CMAKE_EXE_LINKER_FLAGS			"${CMAKE_EXE_LINKER_FLAGS}	/IGNORE:4099")			# /LTCG")	# defaults - Meta library inclusion means LTCG needs to be specified
	#set(CMAKE_EXE_LINKER_FLAGS			"${CMAKE_EXE_LINKER_FLAGS}	/INCREMENTAL:NO")		# dont allow incremental linking


	# Set the correct static runtime library, CMAKE defaults to dynamic
	# ==============================================================
	foreach(config_name IN LISTS CMAKE_CONFIGURATION_TYPES ITEMS ${CMAKE_BUILD_TYPE})
		string(TOUPPER "${config_name}" config_name)
		foreach(flag_name C CXX)
			set(FLAGS_VAR "CMAKE_${flag_name}_FLAGS_${config_name}")
			if (${${FLAGS_VAR}} MATCHES "/MD")
				string(REGEX REPLACE "/MD" "/MT" ${FLAGS_VAR} "${${FLAGS_VAR}}")
			endif()
		endforeach()
	endforeach()


	#Force cmake NOT to override the default stack size
	#The value CMake tries to use causes us to run out of memory when we have too many threads
	# ==============================================================
	string(REGEX REPLACE "/STACK:[0-9]+" "" CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
	set(CMAKE_CXX_STACK_SIZE "")

elseif(UNIX)

	# Linux only flags
	# ==============================================================
	add_definitions(-fPIC)				# Position independent code
	#add_definitions("-DLINUX -O -MD")
	add_definitions(-lrt)

endif()


# Make sure C++ build configurations are identical to C
# =================================================================================
foreach(config IN LISTS CMAKE_CONFIGURATION_TYPES ITEMS ${CMAKE_BUILD_TYPE})
	string(TOUPPER "${config}" config)
	set (CMAKE_CXX_FLAGS_${config}		"${CMAKE_C_FLAGS_${config}}")
endforeach()


# Add modules (directories)
# ==============================================================
add_subdirectory(src/)

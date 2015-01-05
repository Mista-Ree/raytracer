cmake_minimum_required(VERSION 2.8)

project( raytracer )


# define source
set	(	sources
		main.cpp
		maths.cpp
		ray.cpp
		sphere.cpp
		vector.cpp
		image.cpp
		colour.cpp
		intersection.cpp
		scene.cpp
		shape.cpp
		perspective_raytracer.cpp
	)


set	(	headers
		maths.h
		ray.h
		shape.h
		sphere.h
		vector.h
		image.h
		colour.h
		intersection.h
		ray_tracer.h
		scene.h
	)
	

include_directories( ${INCLUDE_DIRS} )

# add the actual library
add_executable( ${PROJECT_NAME} ${sources} ${headers} )

set_target_properties(${PROJECT_NAME} PROPERTIES 
  ARCHIVE_OUTPUT_NAME				${PROJECT_NAME}
  ARCHIVE_OUTPUT_NAME_DEBUG			${PROJECT_NAME}_debug
)
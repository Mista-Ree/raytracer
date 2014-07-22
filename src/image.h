#ifndef _IMAGE_H
#define _IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include "colour.h"

class Image{

private:
	Colour *pixels;
	int width;
	int height;
	int _max;

public:
	Image() : width(0), height(0), pixels(0) {}
	Image(int width, int height);

	~Image();

	void setColour(int x, int y, Colour colour); // colours are either black or white for now
	int getWidth();
	int getHeight();

	void writeTGA(const char *outfile, bool scale_color);

};


#endif
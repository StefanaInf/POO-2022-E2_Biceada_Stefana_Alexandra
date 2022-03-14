#include "Canvas.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Canvas::Canvas() {
	this->width_canvas = 0;
	this->height_canvas = 0;
	//this->nr_of_lines = 0;
	this->matrix = nullptr;
}

Canvas::Canvas(int width, int height) {
	this->width_canvas = width;
	this->height_canvas = height;
	this->matrix = (char**)(malloc(this->height_canvas * sizeof(char*)));
	for (int i = 0; i < height_canvas; i++) this->matrix[i] = (char*)(malloc(width_canvas * sizeof(char)));
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for(int i = 0; i < this->height_canvas; i++)
		for (int j = 0; j < this->width_canvas; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1)) 
				this->matrix[i][j] = ch;
			else
				this->matrix[i][j] = ' ';			
		}
}

void Canvas::Print() {
	for (int i = 0; i < this->height_canvas; i++) {
		for (int j = 0; j < this->width_canvas; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

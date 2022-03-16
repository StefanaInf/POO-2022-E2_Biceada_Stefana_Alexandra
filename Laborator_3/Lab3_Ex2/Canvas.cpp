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
	/*
	for(int i = 0; i < this->height_canvas; i++)
		for(int j = 0; j < this->width_canvas; j++)
			this->matrix[i][j] = ' ';
	*/
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

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->height_canvas; i++)
		for (int j = 0; j < this->width_canvas; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) < ray * ray)
				this->matrix[i][j] = ch;
			else
				this->matrix[i][j] = ' ';
		}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for(int i = 0; i < this->height_canvas; i++)
		for (int j = 0; j < this->width_canvas; j++) {
			this->matrix[i][j] = ' ';
			if (i >= top && i <= bottom && j <= right && j >= left)
				this->matrix[i][j] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {

	for (int i = 0; i < this->height_canvas; i++)
		for (int j = 0; j < this->width_canvas; j++)
			this->matrix[i][j] = ' ';

	for (int i = left; i <= right; i++) this->matrix[top][i] = ch;
	for (int i = left; i <= right; i++) this->matrix[bottom][i] = ch;
	for (int i = top; i <= bottom; i++) this->matrix[i][left] = ch;
	for (int i = top; i <= bottom; i++) this->matrix[i][right] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int x = x2 - x1;
	int y = y2 - y1;
	int error = 0;
	int deltaorrar;
	deltaorrar = y / x;
	y = y1;
	for (int i = x1; i <= x2; i++) {
		this->matrix[i][i] = ch;
		error = error + deltaorrar;
		if (error >= 0.5) {
			++y;
			error -= 1.0;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < this->height_canvas; i++) {
		for (int j = 0; j < this->width_canvas; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

void Canvas::Clear() {
	for (int i = 0; i < this->height_canvas; i++) {
		for (int j = 0; j < this->width_canvas; j++)
			this->matrix[i][j] = ' ';
	}
}


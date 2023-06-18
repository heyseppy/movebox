#pragma once
#include "SDL.h"
#include "Car.h"
#include <stdio.h>
#include <iostream>

class Simulation {

public:
	Simulation();
	~Simulation();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();

	void drawCar(Car vehicle);

	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

private:
	bool isRunning;
	int counter = 0;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;



};
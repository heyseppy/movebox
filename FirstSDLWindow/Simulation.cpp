#include "Simulation.h"
#include "Car.h"
#include <stdio.h>

Simulation::Simulation()
{}

Simulation::~Simulation()
{}

void Simulation::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{ 
	int flags = 0;

	// check if user requested fullscreen
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// runtime check to see whether SDL initialises correctly
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Everything initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else 
	{
		isRunning = false;
	}

	
}

void Simulation::update()
{
	counter++;
	std::cout << counter << std::endl;
}

void Simulation::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
}

void Simulation::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	drawCar();

	switch (event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;

	}
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

void Simulation::drawCar(Car vehicle)
{
	// draw car as a rectangle
	SDL_Rect rect;
	rect.x = 250;
	rect.y = 150;
	rect.w = 10;
	rect.h = 10;

	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &rect);
	std::cout << "Car drawn" << std::endl;
}
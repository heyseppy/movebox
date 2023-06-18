#include "Simulation.h"
#include "Car.h"

Simulation* simulation = nullptr;
Car* car = nullptr;

int main(int argc, char* argv[])
{
	car = new Car();
	car->init(250, 150, 10, 10);

	simulation = new Simulation();
	simulation->init("Movement Gym", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (simulation->running()) {
		simulation->handleEvents();
		simulation->update();
		simulation->render();
	}

	simulation->clean();

	return 0;
}
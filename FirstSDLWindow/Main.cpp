#include "Simulation.h"

Simulation* simulation = nullptr;

int main(int argc, char* argv[])
{
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
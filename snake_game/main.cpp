#include <stdafx.h>
#include "SDLApp.h"

int main(int argc, char* argv[])
{
	srand(static_cast<unsigned int>(time(nullptr)));

	SDLApp app;
	
	app.Init();

	app.Play();

	app.Finish();

	return 0;
}
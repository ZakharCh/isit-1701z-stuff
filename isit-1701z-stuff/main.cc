/*
 * main.cc
 *
 *  Created on: 19 мая 2020 г.
 *      Author: unyuu
 */

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

constexpr int WINDOW_WIDTH = 1920;
constexpr int WINDOW_HEIGHT = 1080;

void setup()
{
	glClearColor(.2f, .2f, .35f, 1.f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.,
			double(WINDOW_WIDTH) / double(WINDOW_HEIGHT),
			0.01,
			20.0);
	glMatrixMode(GL_MODELVIEW);
}


void render()
{
	static double a = 0;

	a += 0.7;
	if (a >= 360.0) a -= 360.0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(5., 5., 5., 0., 0., 0., 0., 0., 1.);

	glRotated(a, 0., 0., 1.);

	glBegin(GL_QUADS);
	glColor3d(1., 1., 0.);
	glVertex3d(-1., -1., -1.);
	glVertex3d(-1.,  1., -1.);
	glVertex3d( 1.,  1., -1.);
	glVertex3d( 1., -1., -1.);

	glColor3d(.47, .53, .42);
	glVertex3d(-1., -1.,  1.);
	glVertex3d(-1.,  1.,  1.);
	glVertex3d( 1.,  1.,  1.);
	glVertex3d( 1., -1.,  1.);

	glColor3d(0., 1., 1.);
	glVertex3d(1., -1., -1.);
	glVertex3d(1., -1.,  1.);
	glVertex3d(1.,  1.,  1.);
	glVertex3d(1.,  1., -1.);

	glColor3d(1., .5, .5);
	glVertex3d(-1., -1., -1.);
	glVertex3d(-1., -1.,  1.);
	glVertex3d(-1.,  1.,  1.);
	glVertex3d(-1.,  1., -1.);

	glEnd();
}


int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	auto window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"Форточка с OpenGL",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					WINDOW_WIDTH, WINDOW_HEIGHT,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (window == nullptr) {
		std::cerr << "Не могу создать окно: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	auto context = std::shared_ptr<void>(
			SDL_GL_CreateContext(window.get()),
			SDL_GL_DeleteContext);
	if (context == nullptr) {
		std::cerr << "Не могу создать контекст OpenGL: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	setup();

	bool want_quit = false;
	SDL_Event event;
	while (not want_quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				want_quit = true;
			if (event.type == SDL_KEYDOWN and
					event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				want_quit = true;
		}


		render();
		SDL_GL_SwapWindow(window.get());
	}

	return 0;
}



#include <SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Emitter.h"

void render(const Emitter &_emitter);

int main()
{
    Emitter emitter({0,0,0}, 15000);
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Error init SDL \n";
        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("Particle System",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1024, 720,
                                          SDL_WINDOW_OPENGL);

    if(!window)
    {
        std::cerr<<"Problem creating window \n";
        exit(EXIT_FAILURE);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);


    bool quit = false;
    SDL_Event event;
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1024.0/720.0, 0.5, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(10,10,100,0,0,0,0,1,0);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT : quit = true; break;
                case SDL_KEYDOWN : quit = true; break;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        render(emitter);
        emitter.update();
        SDL_GL_SwapWindow(window);
    }
    SDL_Quit();
}

// Add change direction and life
void render(const Emitter &_emitter)
{
    glPointSize(3);
    glBegin(GL_POINTS);
    //glVertex3f(-2,0,0);
    _emitter.renderGL();
    glEnd();
}


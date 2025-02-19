#if !defined(VOIDVOXEL__CAULDRIA__WINDOW_CPP)
#define VOIDVOXEL__CAULDRIA__WINDOW_CPP

#include <raylib.h>

#include "CauldriaEngine.hpp"
#include "Window.hpp"

#include "log.hpp"

voidvoxel::cauldria::Window::Window()
{
    // Open the window.
    TraceLog(LOG_DEBUG, "Opening window...");
    InitWindow(640, 480, "Cauldria");
    TraceLog(LOG_DEBUG, "Window opened.");

    this->startMainLoop();
}

voidvoxel::cauldria::Window::~Window()
{
    // Close the window.
#if DEBUG
    TraceLog(LOG_DEBUG, "Closing window...");
#endif
    CloseWindow();
#if DEBUG
    TraceLog(LOG_DEBUG, "Window closed.");
#endif
}

voidvoxel::cauldria::CauldriaEngine * voidvoxel::cauldria::Window::getCauldriaEngine()
{
    // Return the current instance of the Cauldria Engine.
    return this->_cauldriaEngine;
}

void voidvoxel::cauldria::Window::mainLoop()
{
    // Run the application's logic code.
    this->tick();

    // Render the application.
    this->render();
}

void voidvoxel::cauldria::Window::render()
{
    // Enter Drawing Mode.
    BeginDrawing();

    // Clear the screen with the background color.
    ClearBackground(BLACK);

    // Render the application.
    this->getCauldriaEngine()->render();

    // Exit Drawing Mode.
    EndDrawing();
}

bool voidvoxel::cauldria::Window::shouldClose()
{
    // Return `true` if the window should close, and `false` otherwise.
    return WindowShouldClose();
}

void voidvoxel::cauldria::Window::startCauldriaEngine()
{
    this->_cauldriaEngine = new CauldriaEngine();
}

void voidvoxel::cauldria::Window::stopCauldriaEngine()
{
    delete this->_cauldriaEngine;
}

void voidvoxel::cauldria::Window::startMainLoop()
{
    // Start the Cauldria Engine.
    this->startCauldriaEngine();

    // While the window should stay open:
    while (!this->shouldClose())
    {
        // Run the main event loop.
        this->mainLoop();
    }

    // Stop the Cauldria Engine.
    this->stopCauldriaEngine();
}

void voidvoxel::cauldria::Window::tick()
{
    // Run the application's logic code.
    this->getCauldriaEngine()->tick();
}

#endif

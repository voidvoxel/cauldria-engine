#include <cauldria_engine.h>

struct cauldria_engine * cauldria_start_engine ()
{
    // Create a new instance of the Cauldria Engine.
    struct cauldria_engine *cauldria_engine = malloc(sizeof(struct cauldria_engine));

    // Return the engine instance.
    return cauldria_engine;
}

struct cauldria_engine_application * cauldria_load_application (
    struct cauldria_engine *cauldria_engine,
    char *application_path
)
{
    // Create a new instance of the application.
    struct cauldria_engine_application *application = malloc(sizeof(struct cauldria_engine_application));

    // Return the application instance.
    return application;
}

int cauldria_start_application (
    struct cauldria_engine *cauldria_engine,
    struct cauldria_engine_application *application
)
{
    return 0;
}

void cauldria_stop_engine (
    struct cauldria_engine *cauldria_engine
)
{
    // TODO: Not yet implemented.
}

void cauldria_stop_application (
    struct cauldria_engine *cauldria_engine,
    struct cauldria_engine_application *application
)
{
    // TODO: Not yet implemented.
}

void caudria_GameObject_awake(struct caudria_GameObject applicationObject)
{
    // TODO: Not yet implemented.
}

void caudria_GameObject_render(struct caudria_GameObject applicationObject)
{
    // TODO: Not yet implemented.
}

void caudria_GameObject_start(struct caudria_GameObject applicationObject)
{
    // TODO: Not yet implemented.
}

void caudria_GameObject_tick(struct caudria_GameObject applicationObject)
{
    // TODO: Not yet implemented.
}

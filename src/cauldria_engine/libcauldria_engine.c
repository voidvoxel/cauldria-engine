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

    application->is_running = false;

    // Create a new Lua state for the application instance.
    lua_State *L = application->L = luaL_newstate();

    // Load the default standard libraries for the scripting instance.
    luaL_openlibs(L);

    // Return the application instance.
    return application;
}

int cauldria_start_application (
    struct cauldria_engine_application *application
)
{
    application->is_running = true;

    return 0;
}

void cauldria_stop_engine (
    struct cauldria_engine *cauldria_engine
)
{
    cauldria_stop_application(cauldria_engine->application);
}

void cauldria_stop_application (
    struct cauldria_engine_application *application
)
{
    // Close the Lua state for the application instance.
    lua_close(application->L);

    application->is_running = false;
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

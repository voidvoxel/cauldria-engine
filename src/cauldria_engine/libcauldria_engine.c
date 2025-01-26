#include <cauldria_engine.h>
#include <path.h>
#include <raylib.h>

/* Private API */

void _cauldria_initialize_script_engine (
    struct cauldria_engine_application *application
);

void _cauldria_load_application_source_code (
    struct cauldria_engine_application *application,
    char *application_path
);

void _cauldria_initialize_script_engine (
    struct cauldria_engine_application *application
)
{
    // Create a new Lua state for the application instance.
    lua_State *L = application->L = luaL_newstate();

    // Load the default standard libraries for the scripting instance.
    luaL_openlibs(L);
}

void _cauldria_load_application_source_code (
    struct cauldria_engine_application *application,
    char *application_path
)
{
    // Get the path to the application's `init.lua` file.
    char *init_script_path = path_combine(application_path, "init.lua");

    // Load the application's source code from the `init.lua` file.
    application->source_code = LoadFileText(init_script_path);
}

/* Public API */

struct cauldria_engine * cauldria_start_engine ()
{
    // Create a new instance of the Cauldria Engine.
    struct cauldria_engine *cauldria_engine = malloc(sizeof(struct cauldria_engine));

    // Note that the engine is running.
    cauldria_engine->is_running = true;

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

    // Note that the application is not running.
    application->is_running = false;

    // Load the application's source code.
    _cauldria_load_application_source_code(application, application_path);

    // Initialize the script engine.
    _cauldria_initialize_script_engine(application);

    // Return the application instance.
    return application;
}

int cauldria_start_application (
    struct cauldria_engine_application *application
)
{
    // TODO: Load the actual application code.
    lua_State *L = application->L;

    char * code = "print \"Hello, world!\"";

    if (luaL_dostring(L, code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }
    // Note that the application is running.
    application->is_running = true;

    // Stop the application instance if it's still running.
    cauldria_stop_application(application);

    // Return the error code returned by the application instance.
    return 0;
}

void cauldria_stop_engine (
    struct cauldria_engine *cauldria_engine
)
{
    // If the engine instance does not exist or is not running, return.
    if (cauldria_engine == NULL || cauldria_engine->is_running == false)
        return;

    // Note that the engine is no longer running.
    cauldria_engine->is_running = false;

    // Stop the application if one is loaded and running.
    cauldria_stop_application(cauldria_engine->application);
}

void cauldria_stop_application (
    struct cauldria_engine_application *application
)
{
    // If the application instance does not exist or is not running, return.
    if (application == NULL || application->is_running == false)
        return;

    // Close the Lua state for the application instance.
    lua_close(application->L);

    // Note that the application is no longer running.
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

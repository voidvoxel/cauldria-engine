#include <string.h>

#include <cauldria_engine.h>
#include <path.h>
#include <raylib.h>

/* Private API */

char* _cauldria_concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}


void _cauldria_initialize_script_engine (
    struct cauldria_engine_application *application
);

void _cauldria_load_application_source_code (
    struct cauldria_engine_application *application,
    char *application_path
);

char * _cauldria_wrap_application_code (
    char *source_code_body
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

void _cauldria_run_application (
    struct cauldria_engine_application *application
)
{
    // Get the application instance's Lua state.
    lua_State *L = application->L;

    // Get the application's source code.
    char *source_code_header = ""
        "-- Define the application default values.\n"
        "application = {\n"
        "   name = \"application\",\n"
        "   version = \"0.0.0\",\n"
        "   dependencies = {}\n"
        "}\n\n"
    ;

    char *source_code_footer = ""
        "-- Emit the exit event.\n"
        "if type(application.on_exit) == \"function\" then\n"
        "    application:on_exit()\n"
        "end\n"
        "print (application)\n"
    ;

    char *source_code = _cauldria_wrap_application_code(application->source_code);

    // Run the source code header.
    if (luaL_dostring(L, source_code_header) == LUA_OK) {
        // Remove the loaded function from the stack.
        lua_pop(L, lua_gettop(L));
    }

    // Run the application's source code.
    if (luaL_dostring(L, source_code) == LUA_OK) {
        // Remove the loaded function from the stack.
        lua_pop(L, lua_gettop(L));
    }

    // Run the source code footer.
    if (luaL_dostring(L, source_code_footer) == LUA_OK) {
        // Remove the loaded function from the stack.
        lua_pop(L, lua_gettop(L));
    }
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

char * _cauldria_wrap_application_code (
    char *source_code_body
)
{
    char *source_code_prefix = ""
        "-- Run the application's source code.\n"
        "(function ()\n"
    ;

    char *source_code_suffix = ""
        "\n"
        "end)()\n"
    ;

    char *_source_code_tmp = _cauldria_concat(source_code_prefix, source_code_body);
    char *source_code = _cauldria_concat(_source_code_tmp, source_code_suffix);

    free(_source_code_tmp);

    return source_code;
}

/* Public API */

struct cauldria_engine * cauldria_start_engine ()
{
    // Create a new instance of the Cauldria Engine.
    struct cauldria_engine *cauldria_engine = malloc(sizeof(struct cauldria_engine));

    // Note that the engine is running.
    cauldria_engine->is_running = true;

    // Set the trace log level to `LOG_ERROR`.
    SetTraceLogLevel(LOG_ERROR);

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

    // Run the application's source code.
    _cauldria_run_application(application);

    // Return the application instance.
    return application;
}

int cauldria_start_application (
    struct cauldria_engine_application *application
)
{
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

#ifndef CAULDRIA_ENGINE_H
#define CAULDRIA_ENGINE_H

#include <stdlib.h>
#include <stdint.h>

#include <lua.h>
#include <lualib.h>
#include <raylib.h>

/* Structs */

struct cauldria_engine {
    struct cauldria_engine_application *application;
};

struct cauldria_engine_application {
    struct cauldria_engine *engine;
    lua_State *L;
};

/* Functions */

// Start an instance of the Cauldria Engine.
struct cauldria_engine * cauldria_start_engine ();

// Load a Cauldria Engine application.
struct cauldria_engine_application * cauldria_load_application (
    struct cauldria_engine *cauldria_engine,
    char *application_path
);

// Start an instance of a Cauldria Engine application.
int cauldria_start_application (
    struct cauldria_engine *cauldria_engine,
    struct cauldria_engine_application *application
);

// Stop a running instance of the Cauldria Engine.
void cauldria_stop_engine (
    struct cauldria_engine *cauldria_engine
);

// Stop a running instance of a Cauldria Engine application.
void cauldria_stop_application (
    struct cauldria_engine *cauldria_engine,
    struct cauldria_engine_application *application
);

/* class caudria_GameObject */

struct caudria_GameObject {
    uint8_t scriptCount;
    struct Script *scripts;
};

typedef struct caudria_GameObject caudria_GameObject;

void caudria_GameObject_awake(struct caudria_GameObject applicationObject);
void caudria_GameObject_render(struct caudria_GameObject applicationObject);
void caudria_GameObject_start(struct caudria_GameObject applicationObject);
void caudria_GameObject_tick(struct caudria_GameObject applicationObject);

#endif

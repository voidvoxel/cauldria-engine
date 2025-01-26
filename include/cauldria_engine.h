#ifndef CAULDRIA_ENGINE_H
#define CAULDRIA_ENGINE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <raylib.h>

#include <cauldria_engine/id.h>
#include <cauldria_engine/voxel.h>

/* Typedefs */

typedef uint8_t cauldria_CameraMode;

/* Structs */

typedef struct cauldria_Engine cauldria_Engine;
typedef struct cauldria_EngineApplication cauldria_EngineApplication;
typedef struct cauldria_VoxelEngine cauldria_VoxelEngine;

typedef struct cauldria_Engine {
    bool is_running;
    cauldria_EngineApplication *application;
    cauldria_VoxelEngine *voxel_engine;
} cauldria_Engine;

typedef struct cauldria_EngineApplication {
    cauldria_Engine *engine;
    bool is_running;
    lua_State *L;
    char *source_code;
    Camera3D main_camera;
    cauldria_CameraMode camera_mode;
} cauldria_EngineApplication;

/* Functions */

cauldria_CameraMode cauldria_camera_mode_2d();
cauldria_CameraMode cauldria_camera_mode_3d();

// Start an instance of the Cauldria Engine.
cauldria_Engine * cauldria_start_engine ();

// Load a Cauldria Engine application.
cauldria_EngineApplication * cauldria_load_application (
    cauldria_Engine *cauldria_engine,
    char *application_path
);

// Start an instance of a Cauldria Engine application.
int cauldria_start_application (
    cauldria_EngineApplication *application
);

// Stop a running instance of the Cauldria Engine.
void cauldria_stop_engine (
    cauldria_Engine *cauldria_engine
);

// Stop a running instance of a Cauldria Engine application.
void cauldria_stop_application (
    cauldria_EngineApplication *application
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

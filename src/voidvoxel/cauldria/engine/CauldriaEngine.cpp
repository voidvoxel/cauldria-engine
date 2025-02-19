#if !defined(VOIDVOXEL__CAULDRIA__CAULDRIA_ENGINE_CPP)
#define VOIDVOXEL__CAULDRIA__CAULDRIA_ENGINE_CPP

#include <stdlib.h>
#include <string>

#include <raylib.h>

#include <voidvoxel/garbage_collection/gc.hpp>

#include "log.hpp"
#include "utils.hpp"

#include "CauldriaEngine.hpp"

voidvoxel::cauldria::CauldriaEngine::CauldriaEngine()
{

}

voidvoxel::cauldria::CauldriaEngine::~CauldriaEngine()
{

}

void voidvoxel::cauldria::CauldriaEngine::crash(const int errorCode, const char *message)
{
    std::string messageString = std::string("Error #") + voidvoxel::cauldria::toHex(errorCode);

    TraceLogFatal(messageString.c_str());

    exit(errorCode);
}

void voidvoxel::cauldria::CauldriaEngine::render()
{
    // Draw debug text.
    DrawText("Hello, world!", 16, 16, 16, PINK);
}

void voidvoxel::cauldria::CauldriaEngine::tick()
{

}

#endif

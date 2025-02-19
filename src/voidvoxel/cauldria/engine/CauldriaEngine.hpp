#if !defined(VOIDVOXEL__CAULDRIA__GAME_ENGINE_HPP)
#define VOIDVOXEL__CAULDRIA__GAME_ENGINE_HPP

namespace voidvoxel::cauldria
{
    class Window;

    /// @brief An instance of the Cauldria game engine.
    class CauldriaEngine
    {
    public:
        CauldriaEngine();
        ~CauldriaEngine();

        /// @brief Exit the program after logging the error code and message.
        /// @param errorCode The code of the error.
        /// @param message A brief message summarizing what caused the crash.
        void crash(const int errorCode, const char *message);

        /// @brief Render the game.
        void render();

        /// @brief Run the game logic.
        void tick();

    private:
        /// @brief The window bound to this instance of the Cauldria game engine.
        const Window *window;
    };
}

#endif // VOIDVOXEL__CAULDRIA__GAME_ENGINE_HPP

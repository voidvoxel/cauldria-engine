#if !defined(VOIDVOXEL__CAULDRIA__WINDOW_HPP)
#define VOIDVOXEL__CAULDRIA__WINDOW_HPP

#include <raylib.h>

namespace voidvoxel::cauldria
{
    class Window
    {
    public:
        /// @brief Open a new `Window`.
        Window();

        /// @brief Close the `Window`.
        ~Window();

        /// @brief Get the current instance of the Cauldria Engine.
        /// @return The current instance of the Cauldria Engine.
        CauldriaEngine *getCauldriaEngine();
    private:
        Color _backgroundColor;
        CauldriaEngine *_cauldriaEngine;

        /// @brief Run the main loop.
        void mainLoop();

        /// @brief Render the `Window`.
        void render();

        /// @brief Returns `true` if the `Window` should close; otherwise, returns `false`.
        /// @return Whether or not the `Window` should close.
        bool shouldClose();

        /// @brief Create a new instance of the Cauldria Engine.
        void startCauldriaEngine();

        /// @brief Stop the running instance of the Cauldria Engine.
        void stopCauldriaEngine();

        /// @brief Start the main loop.
        void startMainLoop();

        /// @brief Run the logic code.
        void tick();
    };

}


#endif

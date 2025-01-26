#include <cauldria_engine.h>

char *DEFAULT_APPLICATION_PATH = "debug";

int main(int argc, char **argv) {
    char *application_path = DEFAULT_APPLICATION_PATH;

    // Start the engine.
    struct cauldria_engine *cauldria_engine = cauldria_start_engine();

    // Load the application.
    struct cauldria_engine_application *application
        = cauldria_load_application(
            cauldria_engine,
            application_path
        );

    // Start the application.
    int error_code
        = cauldria_start_application(
            application
        );

    // Stop the engine.
    cauldria_stop_engine(cauldria_engine);

    // Return the exit code returned by the application.
    return error_code;
}

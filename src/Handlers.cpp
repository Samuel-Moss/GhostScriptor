#include "../inc/Handlers.h"

void hdl::outputResult(uint8_t successCode, std::string message) {
    // If the task was successful

    if (successCode == 0) {

        // Output [FAILURE] in red before message
        std::cout << "[\x1B[31m-\033[0m] " << message << std::endl;
    }
    else if (successCode == 1) {

        // Output [SUCCESS] in green before message
        std::cout << "[\x1B[32m+\033[0m] " + message << std::endl;

    }
    else {

        // Output [INFO] in yellow before message
        std::cout << "[\x1B[33mINFO\033[0m] " + message << std::endl;
    }

}
#include "main.h"

/**
 * install_dependencies - install dependencies of the application
 * basically ffmpeg, lame, libgtk and libglib by default
 * Return: void
 */

void install_dependencies() {
    printf("Initiating installation process...\n");
    printf("Updating package list...\n");

    if (process_handler("sudo apt-get update") != SUCCESS) {
        printf("Failed to update package list.\n");
        exit(FAILURE);
    }

    if (process_handler("sudo apt-get install -y libgtk2.0-dev") != SUCCESS) {
        printf("Failed to install gtk library.\n");
        exit(FAILURE);
    }

    if (process_handler("sudo apt-get install -y libglib2.0-dev") != SUCCESS) {
        printf("Failed to install g-library.\n");
        exit(FAILURE);
    }

    printf("Checking if packages are already installed...\n");
    if (process_handler("which ffmpeg > /dev/null 2>&1") == SUCCESS)
        printf("FFmpeg is already installed.\n");
    else
    {
        printf("Installing FFmpeg...\n");
        if (process_handler("sudo apt-get install -y ffmpeg") != SUCCESS)
        {
            printf("Failed to install FFmpeg.\n");
            exit(FAILURE);
        }
    }

    if (process_handler("which lame > /dev/null 2>&1") == SUCCESS)
        printf("Lame is already installed.\n");
    else
    {
        printf("Installing lame...\n");
        if (process_handler("sudo apt-get install -y lame") != SUCCESS)
        {
            printf("Failed to install lame.\n");
            exit(FAILURE);
        }
    }

    if (process_handler("ffmpeg -version") == SUCCESS &&
             process_handler("lame --version") == SUCCESS)
        printf("Dependencies successfully installed.\n");
    else
    {
        fprintf(stderr, "Error: Installation verification failed. Please restart installation...\n");
        exit(FAILURE);
    }
}


/**
 * main - call the install_dependencies_thread function
 * to install the required packages
 * Return: void
 */

void main(void)
{
    install_dependencies();
}

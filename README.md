# LINUX Audio Converter and Compressor (MP3)

## Overview
LINUX Audio Converter & Compressor is a graphical user interface (GUI) application designed to simplify the process of converting and compressing audio files to MP3 format on Linux systems. It leverages powerful tools like **FFmpeg** and **LAME** for audio processing and uses **GTK** for its user-friendly interface.

This project is ideal for users who need to process audio files efficiently and customize audio compression without navigating complex command-line options.

## Features
- **File Selection**: Select audio files via a file picker.
- **Conversion and Compression**: Converts audio files to MP3 and compresses them using FFmpeg and LAME.
- **Dependency Installation**: Ensures required dependencies like FFmpeg, LAME, GTK, and GLib are installed.
- **Multi-threading**: Utilizes threads to prevent the GUI from freezing during intensive operations.

## Prerequisites
Before using the application, ensure the following dependencies are installed or can be installed on your system:

- **FFmpeg**: For audio file conversion to MP3.
- **LAME**: For MP3 compression.
- **GTK+**: For simple GUI rendering.
- **GLib**: For thread and event handling.

The application is compatible with most Linux distributions that support GTK and the mentioned tools.

## Installation
### Step 1: Open a terminal and clone the Repository
```bash
git clone https://github.com/Abd-al-qudus/LINUX-Audio_Compressor.git
cd audio_compressor_v1/LINUX-Audio_Compressor
```

### Step 2: Compile the Source Code
Use GCC to compile the program:
```bash
gcc -o audio_converter main.c process_handler.c install.c `pkg-config --cflags --libs gtk+-2.0 gthread-2.0`
```

### Step 3: Run the Program
Execute the compiled binary and enter your sudo password if not run as root:
```bash
sudo ./audio_converter
```

## Usage
1. Launch the application.
2. Use the **"Convert & Compress"** button to select an audio file for conversion and compression.
3. Click **"Install Dependencies"** to install necessary tools at first launch.
4. Monitor the terminal for status updates during the process.

## Code Structure
### Files
- **`main.c`**: Contains the main function and GUI implementation.
- **`main.h`**: Header file with function prototypes and global definitions.
- **`process_handler.c`**: Implements system command execution.
- **`install.c`**: Handles installation of dependencies.

### Key Functions
- **`gui`**: Initializes and manages the GUI.
- **`picker`**: Allows users to select audio files for processing.
- **`conversion_thread`**: Handles audio conversion and compression in a separate thread.
- **`install_dependencies_thread`**: Installs required dependencies.

## How It Works
1. **File Selection**: Users select an audio file via a GTK file chooser dialog.
2. **Conversion**: The application generates FFmpeg and LAME commands to process the file.
3. **Compression**: LAME compresses the converted file to reduce its size.
4. **Dependency Management**: If dependencies are missing, the "Install Dependencies" button automates their installation.

## Error Handling
- Displays error messages in the terminal if command execution or dependency installation fails.
- Validates that dependencies are installed before conversion.

## Future Enhancements
- Add support for batch processing of multiple files.
- Provide options to customize output audio quality.
- Provide support for multiple operating systems.
- Enhance the GUI with progress bars and detailed status updates.

## License
This project is licensed under the MIT License.

---
For further assistance or contributions, feel free to open an issue or submit a pull request on the GitHub repository.


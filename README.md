# LINUX Audio Converter and Compressor to MP3

## Overview
The Linux MP3 Converter and Compressor is a lightweight and efficient C-based application designed to streamline audio conversion for Linux users. It is built with simplicity and performance in mind, making it a robust choice for both novice and advanced users.

## Why Choose this Audio Processing Tool?
1. **Performance**: Written in C for optimal performance, ensuring low resource usage.
2. **Simplicity**: Easy to set up, use, and integrate with existing systems.
3. **Open Source**: Fully open-source enabling contributions and customizations.
4. **Multiple Audio-Formats input**: Supports all audio format input to convert to MP3
5. **File Size Optimization**: The default bit rate of the compressed MP3 file is 16 bits. This enhances file size management for easy transfer

## Video Demonstration
[![Demo Video](https://img.youtube.com/vi/we4yRnO17kY/0.jpg)](https://www.youtube.com/watch?v=we4yRnO17kY)

This video provides a step-by-step walkthrough of the tool’s features, installation, and usage.

## Installation
Follow these steps to build and run the MP3 Converter and Compressor on your system:

### Prerequisites
- GCC Compiler and git. If not installed, open a terminal and type
   ```bash
   sudo apt update
   sudo apt install gcc git
   ```
Enter your sudo password to continue if necessary

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/Abd-al-qudus/LINUX-Audio_Compressor.git
   cd LINUX-Audio_Compressor
   ```

2. Compile and Install dependencies (for first time users):
   ```bash
   gcc process_handler.c install.c -o install
   ./install
   ```
Enter your sudo password to finish the dependencies installation

3. Compile and run the converter:
   ```bash
   gcc process_handler.c main.c -o converter `pkg-config --cflags --libs gtk+-2.0 gthread-2.0` -Wno-deprecated-declarations
   ./converter
   ```
This compiles the files by including glib and gtk as requirements. The last part supresses any compilation warning

## Usage Instructions
1. Launch the tool from the terminal.
2. Use the compress & convert button to select audio
3. Select the audio and the conversion process initiates in the terminal. The output MP3 file is 16 bits by default and can be found inside the conversion directory

## Contributing
We welcome contributions to enhance the tool’s functionality. Please fork the repository, create a feature branch, and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.


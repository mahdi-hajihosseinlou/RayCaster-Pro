# RayCaster Pro - A Retro-Style 3D Game Engine


**RayCaster Pro** is a custom-built 3D game engine using raycasting technology, developed in C with SDL2/raylib. This project creates a pseudo-3D environment from a 2D map, inspired by classic games like Wolfenstein 3D.

click the link blow and go to the official webpage of the project where you can download the source code and see the screenshots of the game
[Visit The WebPage Of The Project](https://mahdi-hajihosseinlou.github.io/RayCaster-Pro/)

## Features

- **Real-time Raycasting**: Converts 2D maps to immersive 3D-like environments
- **High Performance**: Steady 60 FPS on modern hardware
- **Textured Walls**: Custom texture mapping for realistic walls
- **Smooth Controls**: WASD movement with mouse look support
- **Dynamic Lighting**: Basic light/dark effects based on distance
- **Cross-Platform**: Runs on Windows, Linux, and macOS

## Quick Start

### Prerequisites
- GCC or Clang compiler
- raylib
- Git

### Installation
```bash
# Clone the repository
git clone https://github.com/mahdi-hajihosseinlou/RayCaster-Pro.git
cd RayCaster-Pro

# Install dependencies (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install build-essential libsdl2-dev

# Compile and run
make
./raycaster

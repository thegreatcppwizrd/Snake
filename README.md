# Snake Game (C++)

A classic Snake game built with **C++** and **raylib**. The goal is to control the snake, eat fruit, and grow without colliding with yourself.

## Features

- Classic Snake gameplay
- Grid-based movement
- Fruit spawning
- Snake growth
- Built using C++ and raylib

## How to Play

- Control the snake using the arrow keys configured in the game.
- Eat fruit to increase your score and grow.
- Avoid colliding with your own body.


<img width="752" height="782" alt="Recording 2026-10-31 092622" src="https://github.com/user-attachments/assets/dbc69971-3c8f-47d0-a703-944fa9c75f11" />


## Requirements

- Git
- A C++ compiler
- [raylib](https://www.raylib.com/)
- [CMake](https://cmake.org/)

## Getting Started

### 1. Clone the repository

Open a terminal and run:

```bash
git clone [YOUR_REPOSITORY_URL](https://github.com/thegreatcppwizrd/Snake)
```

Move into the project folder:

```bash
cd YOUR_FOLDER
```

### 2. Pull the latest changes

If you already have the repository on your computer, navigate to its folder and run:

```bash
git pull
```

This downloads and merges the latest changes from the remote repository.

**Before pulling:** Save or commit your own changes to avoid conflicts.

### 3. Build and run

If the project uses CMake, open a terminal in the project folder and run:

```bash
cmake -S . -B build
cmake --build build
```

Run the resulting executable from the build output directory. Its exact location depends on your CMake configuration and compiler.

If you're using Visual Studio, you can also open the project folder with **File → Open → Folder** and build it using the CMake integration.

## Project Structure

The project may be organised like this:

```text
Snake/
├── CMakeLists.txt
├── README.md
├── src/
│   ├── main.cpp
│   ├── Snake.h
│   ├── Snake.cpp
│   ├── Fruit.h
│   └── Fruit.cpp
└── resources/
```

Adjust this structure to match the actual files in your repository.

## Technologies

- **C++** — game logic
- **raylib** — graphics and input
- **CMake** — build configuration, if used
- **Git** — version control

## Future Improvements

- High-score saving
- Sound effects
- Main menu
- Difficulty settings

## License

No license has been specified yet.

# 🚧 Rubik's Cube Solver 🧩

⚠️ **Disclaimer: This project is still a work in progress!** ⚠️

This repository contains a collection of C++ programs designed to solve a Rubik's Cube using terminal inputs. The solver implements the advanced Fridrich (CFOP) method, breaking down the solving process into distinct phases: Cross, F2L (First Two Layers), OLL (Orientation of the Last Layer), and PLL (Permutation of the Last Layer).

## Programs Overview

### Core Components

- **cubeReader.cpp**: Reads the current state of the Rubik's Cube and generates an initial stage file (`stage_0.txt`).

- **translateStage.cpp**: Translates stage files into arrays for processing. The corresponding header file is `translateStage.h`.

- **stageValidator.cpp**: Validates the cube's state to ensure it is solvable (e.g., checks that each color appears exactly nine times).

- **moves.cpp**: Contains all possible moves that can be performed on the cube.

### Solving Stages

- **solveCross.cpp**: Positions and orients edge pieces to form a cross on one face of the cube.

- **solveF2L.cpp**: Pairs corner and edge pieces to complete the first two layers of the cube.

- **solveOLL.cpp**: Orients all pieces on the last layer so that the upper face is one solid color.

- **solvePLL.cpp**: Permutates the pieces on the last layer to solve the entire cube.

### Main Program

- **solveCube.cpp**: Integrates all the steps from reading the cube to solving it, coordinating the use of all the other programs.

## Cube Notation

The cube moves are represented using standard notation:

- **Single Moves:**
  - F: Front face clockwise
  - R: Right face clockwise
  - U: Upper face clockwise
  - L: Left face clockwise
  - B: Back face clockwise
  - D: Down face clockwise

- **Counterclockwise Moves:**
  - F': Front face counterclockwise
  - R': Right face counterclockwise
  - U': Upper face counterclockwise
  - L': Left face counterclockwise
  - B': Back face counterclockwise
  - D': Down face counterclockwise

- **Double Moves:**
  - F2: Front face 180 degrees
  - R2: Right face 180 degrees
  - U2: Upper face 180 degrees
  - L2: Left face 180 degrees
  - B2: Back face 180 degrees
  - D2: Down face 180 degrees

## Stages and State Files

Throughout the solving process, the program generates `stage_x.txt` files, where `x` represents the stage number, to store the current state of the cube after each solving phase. These files are essential for tracking the progress of the cube through its various stages of solving.

## Usage

### Compilation

You can already use the first stage (`stage_0`) by compiling the necessary files using the GNU compiler:

```bash
g++ -c translateStage.cpp
g++ -c stageValidator.cpp
g++ -c cubeReader.cpp
g++ -o stageValidator stageValidator.o translateStage.o
g++ -o cubeReader cubeReader.o

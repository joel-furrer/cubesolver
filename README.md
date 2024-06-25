# 🚧 Rubik's Cube Solver 🧩

⚠️ **Disclaimer: This project is still a work in progress!** ⚠️

This repository contains a collection of C++ programs designed to solve a Rubik's Cube using terminal inputs. The solver implements the advanced Fridrich (CFOP) method, breaking down the solving process into distinct phases: Cross, F2L (First Two Layers), OLL (Orientation of the Last Layer), and PLL (Permutation of the Last Layer).

## Programs Overview

- **Cross Solver:** Positions and orients edge pieces to form a cross on one face of the cube.
- **F2L Solver:** Pairs corner and edge pieces to complete the first two layers of the cube.
- **OLL Solver:** Orients all pieces on the last layer so that the upper face is one solid color.
- **PLL Solver:** Permutates the pieces on the last layer to solve the entire cube.

Each program is designed to operate independently but contributes to the overall solving process of the Rubik's Cube.

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

Throughout the solving process, the program generates `stage_x.txt` files, where x represents the stage number, to store the current state of the cube after each solving phase. These files are essential for tracking the progress of the cube through its various stages of solving.

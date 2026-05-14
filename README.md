# Tower of Hanoi Visualization in C++

Interactive visualization of the Tower of Hanoi puzzle developed in C++ using `graphics.h`. The program solves the puzzle recursively and displays each move step by step as the user presses a key.

## Problem Description

The Tower of Hanoi is a classic recursive problem in which a set of disks of different sizes must be moved from one tower to another following these rules:

1. Only one disk can be moved at a time.
2. A larger disk may never be placed on top of a smaller disk.
3. An auxiliary tower may be used during the process.

## Features

* Graphical representation of three towers and colored disks.
* Recursive solution of the Tower of Hanoi problem.
* Step-by-step execution controlled by keyboard input.
* Dynamic visualization of each disk movement.
* Color-coded disks for better visual understanding.

## Technologies Used

* C++
* Recursion
* Graphics Programming with `graphics.h`
* Keyboard Event Handling

## Core Algorithm

The program applies the classic recursive strategy:

1. Move `n-1` disks to the auxiliary tower.
2. Move the largest disk to the destination tower.
3. Move the `n-1` disks from the auxiliary tower to the destination.

## User Interaction

* Press the space bar (or any key) to perform the next movement.
* The puzzle is solved visually one step at a time.

## What I Learned

* Recursive algorithms
* State representation using arrays
* Graphical programming
* Interactive visualization of algorithm execution

## Academic Context

This project was developed as part of the Computer Systems Engineering program at ESCOM - Instituto Politécnico Nacional.

## Author

Gael Ignacio Castañeda Noguerón

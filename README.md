# DevWorkspace Manager

## Description

**DevWorkspace Manager** is a C++ utility that recursively scans a specified directory and displays detailed metrics about the files and folders it finds. The project is focused on analysis and reporting, making it useful for quickly understanding the structure and contents of a development workspace.

## Implemented Features

- Recursive scan of a main directory (`DIR_PRINCIPAL`)
- Identification and classification of files and directories
- Calculation and display of the following metrics in the terminal:
    - Total number of entries, files, and directories
    - Total and average file size
    - Largest file (name and size)
    - Total number of children in directories and the directory with the most items
    - File type breakdown (by extension)
    - Recursive metrics: total number of files and directories, total size, largest file in the entire structure, top 5 largest directories

## How to Run

1. Build the project with a C++17+ compiler and CMake.
2. Make sure `DIR_PRINCIPAL` is defined with the path to the directory you want to analyze.
3. Run the resulting binary. The metrics will be displayed directly in the terminal.

## Status

The project is currently focused on analysis and reporting metrics. There are no automation or graphical interface features yet.
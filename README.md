readme_content = """
# Personal Calculator Project

## Overview
This repository contains a personal calculator project created as a way to practice and expand programming skills. The project is designed to provide a customizable and expandable mathematical tool, with both basic and advanced functionality. Future plans include enhancements such as a graphical user interface (GUI) and AI-powered features.

## Current Version: 0.5.0

### Changelog
#### Version 0.2
- Added input validation to ensure proper operators and operands are used.
- Enhanced code readability by including detailed comments.

#### Version 0.3
- Introduced additional operators, including modulus (`%`) and exponentiation (`^`).
- Implemented a looping mechanism that keeps the program running until the user exits by typing `q`.
- Added JSON files for local program configuration (may require updates).

#### Version 0.3.1
- Hotfix for major bug that caused the program to not exit properly.

#### Version 0.4.0
- Added better error handling to program for when dividing or modulus by 0.
- Improved the menu for ease of use (still no GUI yet).
- Refactored code to modularize functionality across multiple files (e.g., `main.c`, `operations.c`, etc.).

#### Version 0.5.0
- Added new advanced mathematical operations:
  - **Square Root (`s`)**: Handles real numbers and errors for negative inputs.
  - **Logarithms (`l` and `g`)**: Supports natural log (`ln`) and base-10 log (`log10`) with error handling for non-positive inputs.
  - **Trigonometric Functions (`sin`, `cos`, `tan`)**: Allows inputs in radians, including support for `pi` expressions.
- Enhanced history functionality:
  - Users can view calculation history (`h`) and clear it (`c`) when needed.
  - History is dynamically updated after every operation.
- Input enhancements:
  - Added support for using `pi` in inputs (e.g., `pi`, `pi/2`, `2pi`).
  - Improved handling of invalid and edge-case inputs.
- Added more robust error messages (e.g., handling undefined tangent cases and small value approximations).
- Introduced a `Makefile` for easier building and cleaning of the project.

### Planned Features and Improvements
- [x] Implement a looping mechanism to eliminate the need to restart the program manually.
- [x] Add more complex mathematical operations (e.g., trigonometric functions, logarithms).
- [x] Modularize the code for easier maintenance and scalability.
- [x] Add a `Makefile` for streamlined builds.
- [ ] Develop a graphical user interface (GUI) for improved usability.
- [ ] Explore AI integration for enhanced functionality (long-term goal).

## How to Run
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```

2. Option 1: Using the Makefile
   - Build the program:
     ```bash
     make
     ```
     This compiles the program and creates the build/calculator executable.
   - Run the program:
     ```bash
     build/calculator
     ```
   - Clean the build directory:
     - To remove all build artifacts (including the executable):
       ```bash
       make clean
       ```
     - To remove only the object files:
       ```bash
       make clean-obj
       ```

3. Option 2: Using Plain Bash Commands
   - Compile the program:
     ```bash
     gcc -Wall -lm -o build/calculator src/main.c src/operations.c src/ui.c src/history.c
     ```
     This manually compiles the program and outputs the executable in the build/ directory.
   - Run the program:
     ```bash
     build/calculator
     ```
   - Clean up manually:
     - To remove all build artifacts:
       ```bash
       rm -rf build/
       ```
     - To remove only object files (if generated):
       ```bash
       rm -rf build/obj/
       ```

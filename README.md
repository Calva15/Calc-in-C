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

- Hotfix for a major bug that caused the program to not exit properly.

#### Version 0.4.0

- Added better error handling for division or modulus by 0.
- Improved the menu for ease of use (still no GUI yet).
- Refactored code to modularize functionality across multiple files (e.g., `main.c`, `operations.c`, etc.).

#### Version 0.5.0

- Added new advanced mathematical operations:
  - **Square Root (********`s`********\*\*\*\*)**: Handles real numbers and errors for negative inputs.
  - **Logarithms (********`l`********\*\*\*\* and ************`g`************)**: Supports natural log (`ln`) and base-10 log (`log10`) with error handling for non-positive inputs.
  - **Trigonometric Functions (********`$`********\*\*\*\*, ************`@`************, ************`#`************)**: Allows inputs in radians, including support for `pi` expressions.
- Enhanced history functionality:
  - Users can view calculation history (`h`) and clear it (`c`) when needed.
  - History is dynamically updated after every operation.
- Input enhancements:
  - Added support for using `pi` in inputs (e.g., `pi`, `pi/2`, `2pi`).
  - Improved handling of invalid and edge-case inputs.
- Added more robust error messages (e.g., handling undefined tangent cases and small value approximations).
- Introduced a `Makefile` for easier building and cleaning of the project.

### Planned Features and Improvements

-

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

## Contributing

I welcome contributions to this project! If you'd like to contribute, please follow these steps:

1. **Fork the Repository**

   - Click the `Fork` button at the top right of the repository page.

2. **Clone Your Fork**

   - Clone your forked repository to your local machine:
     ```bash
     git clone https://github.com/your-username/calculator-project.git
     ```

3. **Create a New Branch**

   - Create a branch for your feature or bug fix:
     ```bash
     git checkout -b feature-branch-name
     ```

4. **Make Your Changes**

   - Implement your changes and commit them with a descriptive message:
     ```bash
     git add .
     git commit -m "Added new feature or fixed a bug"
     ```

5. **Push to Your Fork**

   - Push your changes to your forked repository:
     ```bash
     git push origin feature-branch-name
     ```

6. **Submit a Pull Request**

   - Open a pull request (PR) from your fork's branch to the `main` branch of this repository.
   - Provide a detailed description of your changes and why they should be merged.

### Contribution Guidelines

- Follow clean coding practices and ensure proper documentation.
- Keep commits small and meaningful.
- Make sure your code compiles and runs correctly before submitting.
- If your change includes a new feature, update the documentation accordingly.
- Be respectful in code reviews and discussions.

I appreciate your contributions to this small weirdo project of mine!

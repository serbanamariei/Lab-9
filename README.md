# Lab 9 – Multidimensional Arrays: Dynamically Allocated Matrices
This folder contains solved problems from Lab 9 of the "Programming Fundamentals" course.
## Topics Covered
- Pointer to pointer (T**) matrix allocations
- Dynamic memory allocation for 2D arrays
- Deallocating memory for matrices
- Matrix operations using pointer arithmetic
- Sorting rows/columns and diagonals of matrices
- Matrix norms and region-based operations
- Recursive matrix calculations
## Problems
### Part 1 – Dynamic Allocation and Basic Processing
#### Problem 1.0 – Matrix Read & Display
- Dynamically allocate a matrix of integers (int**)
- Read and display the matrix
#### Problem 1.1 – Sort Rows by Maximum Element
- Sort matrix rows in ascending order based on the max value in each row
- Functions:
  - Allocation and deallocation
  - Read/display matrix
  - Row swapping
  - Max element detection
  - Row sorting logic
#### Problem 1.2 – Sort Rows, Columns, Diagonals
- Read square matrix (n ≤ 20)
- Menu options:
  - Sort first row
  - Sort first column
  - Sort main diagonal
- Functions:
  - Row/column swapping
  - Specific sort functions per option
#### Problem 1.3 – Diagonal & Centered Sorting Menu
- Matrix read and display
- Menu options:
  - Sort main diagonal ascending
  - Sort secondary diagonal descending
  - Sort vertical middle row ascending (if odd number of columns)
### Part 2 – Norms and Regional Analysis
#### Problem 2.1 – Matrix Norms
- Compute matrix norms:
  - ‖A‖∞ = max row sum
  - ‖A‖₁ = max column sum
  - ‖A‖₂ = sqrt(sum of squares of all elements)
- Menu to choose which norm to compute
#### Problem 2.2 – Region Operations and Mirror Images
- Matrix divided into four zones (north, south, east, west)
- Compute:
  - Sum of northern zone
  - Product of southern zone
  - Arithmetic mean of eastern zone
  - Geometric mean of western zone
- Mirror matrix:
  - Horizontally (right edge)
  - Vertically (bottom edge)
### Part 3 – Recursive Matrix Computation
#### Problem 3.1 – Compute Matrix B via Recursive Formula
- Read matrix A (real numbers, n × n with n ≤ 20)
- Compute matrix B using recurrence:
  - T₁ = A
  - Tₖ = A × Tₖ₋₁ for k ≥ 2
  - B = T₁ + T₂ + ... + Tₙ
- Must include:
  - Matrix validation
  - Matrix sum, scalar multiplication, product
  - Identity matrix generation
  - Multiple data set support
## Build Instructions
To compile and link programs using dynamically allocated matrices:
```bash
clang -Wall -c matrixUtils.c      # Utility functions for matrix operations
clang -Wall -c main.c             # Main program
clang matrixUtils.o main.o -o output
```
## Build with `makefile`
- To build the project:
```bash
make
```
- To clean up build files:
```bash
make clean
```

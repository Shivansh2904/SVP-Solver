
# Shortest Vector Problem (SVP) Solver

## Overview
This repository contains a C++ implementation for solving the Shortest Vector Problem (SVP) in lattice-based cryptography. The solution employs a Brute-Force search technique to find the shortest vector in a given lattice basis.

## Problem Statement
The Shortest Vector Problem involves finding the shortest non-zero vector in a lattice, given a basis of the lattice. This is a fundamental problem in lattice-based cryptography and has applications in various fields including cryptanalysis and cryptography.

## Implementation Details

### Algorithm
The implementation uses a Brute-Force search algorithm to solve the SVP. While advanced algorithms like the Lenstra–Lenstra–Lovász (LLL) algorithm were considered, the Brute-Force approach was chosen for its:
- Implementation simplicity
- Accuracy in results
- Reliability across different vector dimensions

### Optimizations
Several optimizations have been incorporated to enhance performance:
- Single-pass shortest vector calculations
- Efficient dynamic arrays for vector component storage
- Compiler optimization flags (e.g., -O2) for improved executable speed
- Memory optimization to prevent leaks

### Features
- Input validation to verify vector validity and consistency
- Error handling for robust execution
- Support for vectors of various dimensions (tested up to 2000 dimensions)
- Results output to both console and a text file

## Usage

### Compilation
```bash
make all
```

### Running the Program
```bash
./runme [vector1] [vector2] ... [vectorN]
```

Example:
```bash
./runme [1.0 0.0 0.0] [0.0 1.0 0.0] [0.0 0.0 1.0]
```

### Testing
```bash
make test
```

### Cleaning
```bash
make clean
```

## Input Format
- Each vector must be enclosed in square brackets
- Vector components can be separated by spaces or commas
- The number of vectors must equal the dimension of each vector (full rank lattice)

## Output
The program outputs:
- Vector dimension
- Number of vectors processed
- The shortest vector found
- Norm of the shortest vector
- The norm is also saved to a file named `result.txt`

## Performance Analysis

### Space Complexity
O(n²) where n is the dimension of the lattice

### Time Complexity
O(cⁿ) where c is a constant that depends on the range of coefficients and n is the dimension

### System Requirements
The program was tested on:
- Processor: AMD Ryzen 5 5625U with Radeon Graphics, 2.30 GHz
- RAM: 16.0 GB
- System: 64-bit operating system, x64-based processor

## Limitations
While the Brute-Force approach works well for lower dimensions, it becomes computationally intensive for very high-dimensional lattices. For more complex applications, advanced techniques like the LLL algorithm may be more appropriate.

## Future Work
- Implementation of more advanced algorithms like LLL
- Parallel processing to improve performance
- Support for sparse lattices

## References
- Codecademy. (n.d.). Brute Force Algorithms: Cheatsheet. Retrieved from https://www.codecademy.com/learn/learn-data-structures-and-algorithms-with-python/modules/brute-force-algorithms/cheatsheet
- Shoup, V. (n.d.). NTL: A Library for doing Number Theory. Retrieved from https://libntl.org/
- The Lattice Challenge. (n.d.). Retrieved from https://www.latticechallenge.org/
- Wikipedia contributors. (n.d.). Lenstra–Lenstra–Lovász lattice basis reduction algorithm. Retrieved from https://en.wikipedia.org/wiki/Lenstra%E2%80%93Lenstra%E2%80%93Lov%C3%A1sz_lattice_basis_reduction_algorithm

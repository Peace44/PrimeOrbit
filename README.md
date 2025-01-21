# PrimeOrbit

**PrimeOrbit** is a simple C++ application to check the primality of one or more 64-bit integers. It demonstrates:

- **Object-Oriented Design** (via a `PrimeChecker` class)
- **Modern C++** usage (C++17 or newer)
- **CMake**-based build system
- **Automated testing** using Google Test

## Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Directory Structure](#directory-structure)  
4. [Build Instructions](#build-instructions)  
5. [Usage](#usage)  
6. [Running Tests](#running-tests)  
7. [Example Inputs/Outputs](#example-inputsoutputs)  
8. [License](#license)  
9. [Contact](#contact)

---

## Overview

This project was created as part of a software engineering internship recruitment exercise. The primary goals were to:

1. Implement a prime checking library in modern C++ (using OOP principles).  
2. Provide a command-line interface (CLI) that accepts multiple numeric inputs.  
3. Use CMake for building both the main executable and the unit tests.  
4. Demonstrate clean code structure, test coverage, and good use of version control (Git).

---

## Features

- **Prime Checking**  
  - Uses an **efficient** 6k ± 1 strategy for checking primality.  
  - Supports **64-bit** integers (`unsigned long long int`).

- **Command-Line Interface (CLI)**  
  - Pass one or more integer arguments.  
  - Reports if each argument is prime or not.  
  - Basic validation: handles negative inputs, out-of-range values, etc...

- **Automated Testing**  
  - Google Test suite covering:
    - Edge cases (0, 1, negative numbers).  
    - Small primes/non-primes.  
    - Very large integers near 2^64 boundaries.

- **CMake Build**  
  - Easily configurable cross-platform builds.  
  - Separate libraries for **prime_checker** and an executable for `prime_app`.  
  - Isolates test code in a dedicated `tests/` folder.

---

## Directory Structure

```
PrimeOrbit/
├── CMakeLists.txt              # Top-level CMake configuration
├── include/
│   └── prime_checker.hpp       # Declaration of the PrimeChecker class
├── src/
│   ├── CMakeLists.txt          # CMake config for library + main app
│   ├── main.cpp                # Main entry point for prime_app
│   └── prime_checker.cpp       # Implementation of the PrimeChecker class
├── tests/
│   ├── CMakeLists.txt          # CMake config for building/running tests
│   ├── googletest/             # Google Test submodule / cloned repo
│   └── test_prime_checker.cpp  # Test cases for PrimeChecker
└── README.md                   # This file
```

---

## Build Instructions

You will need:

1. **A modern C++ compiler** (supporting C++17 or later):
   - GCC, Clang, or MSVC  
2. **CMake** (version 3.10 or newer recommended)

**Steps**:

1. **Clone or Download the Repository**  
   ```bash
   git clone https://github.com/Peace44/PrimeOrbit.git
   cd PrimeOrbit
   ```
2. **Create and Enter a Build Directory**  
   ```bash
   mkdir build && cd build
   ```
3. **Run CMake to Configure**  
   ```bash
   cmake ..
   ```
4. **Build the Project**  
   ```bash
   make
   ```
   - This compiles both the **prime_checker** library and the **prime_app** executable.  
   - By default, build artifacts will be placed in the `build` directory.

---

## Usage

After a successful build:

1. **Locate the Main Executable**  
   - `prime_app` (or `prime_app.exe` on Windows), residing in `build/src/`

2. **Run with One or More Arguments** (in the `build/src/` folder)  
   ```bash
   ./prime_app 2 3 4 99999999
   ```

3. **Sample Output**  
   - For each argument, the program prints whether it is prime or not.  
   - If an argument is invalid (negative or out-of-range), you’ll see an error message.

---

## Running Tests

We use [Google Test](https://github.com/google/googletest) for unit tests. After building, you can run:

1. **CTest** (in the `build` folder)  
   ```bash
   ctest
   ```
   or verbose:
   ```bash
   ctest --verbose
   ```

2. **Direct Execution** (in the `build/tests` folder)  
   ```bash
   ./test_prime_checker
   ```

**Expected Output**  
- A summary of test results, indicating which test suites and cases passed/failed.

---

## Example Inputs/Outputs (in the `build/src/` folder)   
**Example 1**
```bash
./prime_app 2 16 999983
```
**Output**  
```
2 is prime!
16 is not prime!
999983 is prime!
```

**Example 2**  
```bash
./prime_app -5 abc 18446744073709551615 18446744073709551557
```
**Output**  
```
Error: Invalid or Out-Of-Range input for argument "-5"
Error: Invalid or Out-Of-Range input for argument "abc"
18446744073709551615 is not prime!
18446744073709551557 is prime!
```

---

## Contact

**Author**: Iragukujije Peace BONERABOSE
**Email**: [iragukujije.peace.bonerabose@gmail.com](mailto:iragukujije.peace.bonerabose@gmail.com)

For questions, suggestions, or contributions, feel free to open an issue or submit a pull request.

---

### Thanks for Checking Out PrimeOrbit!

Please let me know if you have any feedback or if you’d like to suggest new features. Happy prime-checking!
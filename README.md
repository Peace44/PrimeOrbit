# PrimeOrbit

**PrimeOrbit** is a straightforward C++ application designed to determine the primality of one or more 64-bit integers and compute their prime factor decomposition. It demonstrates:

- **Object-Oriented Design** (via `PrimeChecker` and `PrimeFactorizer` classes)
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
7. [Example Inputs/Outputs](#example-inputoutput)
8. [Future Enhancements](#future-enhancements)
9. [Contact](#contact)

---

## Overview

This project was created as part of a software engineering internship recruitment exercise. 

The primary goals were to:
1. Implement a modern C++ library (using OOP principles) for prime checking and prime factor decomposition.
2. Provide a command-line interface (CLI) that accepts multiple numeric inputs.  
3. Use CMake for building both the main executable and the unit tests.  
4. Demonstrate clean code structure, test coverage, and good use of version control (Git).

PrimeOrbit includes **two core classes**:
- `PrimeChecker`: Determines if a number is prime.
- `PrimeFactorizer`: Decomposes a number into its prime factors. 

Among these, the **`PrimeFactorizer` class** is the most crucial as it powers both the prime factor decomposition and the primality test indirectly through its methods.

---

## Features

- **Prime Checking**  
  - Uses an **efficient** 6k ± 1 strategy for checking primality.  
  - Supports **64-bit** integers (`unsigned long long int`).

- **Prime Factorization**  
  - Decomposes a number into its prime factors (with multiplicity).  
  - Supports **64-bit** integers (`unsigned long long int`).  

- **Command-Line Interface (CLI)**  
  - Pass one or more integer arguments.  
  - Reports if each argument is prime or not, as well as its prime factor decomposition.  
  - Basic validation: handles negative inputs, out-of-range values, etc...

- **Automated Testing**  
  - Google Test suite covering:
    - Edge cases (0, 1, negative numbers).  
    - Small primes/non-primes.  
    - Very large integers near 2^64 boundaries.

- **CMake Build**  
  - Easily configurable cross-platform builds.  
  - Separate libraries for **prime_checker** and **prime_factorizer**.
  - An executable for `prime_app`.  
  - Isolates test code in a dedicated `tests/` folder.

---

## Directory Structure

```
PrimeOrbit/
├── CMakeLists.txt                  # Top-level CMake configuration
├── include/
│   └── prime_checker.hpp           # Declaration of the PrimeChecker class
│   └── prime_factorizer.hpp        # Declaration of the PrimeFactorizer class
├── src/
│   ├── CMakeLists.txt              # CMake config for library + main app
│   ├── main.cpp                    # Main entry point for prime_app
│   └── prime_checker.cpp           # Implementation of the PrimeChecker class
│   └── prime_factorizer.cpp        # Implementation of the PrimeFactorizer class
├── tests/
│   ├── CMakeLists.txt              # CMake config for building/running tests
│   ├── googletest/                 # Google Test submodule / cloned repo
│   └── test_prime_checker.cpp      # Test cases for PrimeChecker
│   └── test_prime_factorizer.cpp   # Test cases for PrimeFactorizer
└── README.md                       # This file
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
   git clone --recursive https://github.com/Peace44/PrimeOrbit.git
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
   - This compile the **prime_checker** and **prime_factorizer** libraries, as well as the **prime_app** executable.  
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
   - For each argument, the program prints whether the argument is prime or not, as well as its prime factor decomposition.  
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

   ```bash
   ./test_prime_factorizer
   ```

**Expected Output**  
- A summary of test results, indicating which test suites and cases passed/failed.

---

## Example Input/Output

- In `build/src/` run:
```bash
./prime_app 2 16 999983 -5 abc 18446744073709551615 18446744073709551557 0 1
```
**Output**  
```
2 is prime! <==> 2 = (2 ^ 1) 
16 is not prime! <==> 16 = (2 ^ 4) 
999983 is prime! <==> 999983 = (999983 ^ 1) 
ERROR: Input "-5" is out of range for a 64-bit unsigned integer!
ERROR: Invalid input "abc"!
18446744073709551615 is not prime! <==> 18446744073709551615 = (3 ^ 1) (5 ^ 1) (17 ^ 1) (257 ^ 1) (641 ^ 1) (65537 ^ 1) (6700417 ^ 1) 
18446744073709551557 is prime! <==> 18446744073709551557 = (18446744073709551557 ^ 1) 
0 is not prime! <==> WARNING: Factorization is not defined for integers < 2 ==> 0 doesn't have prime factors!
1 is not prime! <==> WARNING: Factorization is not defined for integers < 2 ==> 1 doesn't have prime factors!
```

---

## Future Enhancements

While the current implementation efficiently checks the primality and determines the canonical representation (prime factor decomposition) of 64-bit integers, future work could involve:

1. Extending to handle **128-bit integers**:
   - Implementing a deterministic **Miller-Rabin primality test** for numbers between `2^64` and `2^128`.
2. Supporting input files for batch processing.
3. Expanding test coverage with parameterized tests and performance benchmarks.
4. Optimizing the `PrimeFactorizer` class for larger numbers using advanced factorization techniques.
5. Enhancing the CLI with additional options (e.g., `--help`, verbose output).

---

## Contact

**Author**: Iragukujije Peace BONERABOSE

**Email**: [iragukujije.peace.bonerabose@gmail.com](mailto:iragukujije.peace.bonerabose@gmail.com)

For questions, suggestions, or contributions, feel free to open an issue or submit a pull request.

---

### Thanks for Checking Out PrimeOrbit!

Please let me know if you have any feedback or if you’d like to suggest new features. Happy prime-checking and prime factor decomposition!
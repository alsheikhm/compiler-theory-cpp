# compiler-theory-cpp
Compiler Theory

## Overview
This project implements a simplified compiler-style delimiter parser in C++. The program reads lines of compressed C++-like code from a text file and scans each line to detect the first mismatched closing delimiter.

The goal of the project is to simulate part of the front-end parsing process used by compilers. By using stack-based logic, the program identifies mismatched parentheses, brackets, and braces, then converts each mismatch position into an ASCII character to reveal a hidden message.

## Features

- Compiler-style parsing
  - Scans each line character by character
  - Detects mismatched closing delimiters
  - Focuses on `()`, `[]`, and `{}` symbols

- Stack-based delimiter matching
  - Uses a `std::stack<char>` to track opening delimiters
  - Applies last-in, first-out logic to verify matching pairs

- File-based input
  - Reads multiple lines of code-like text from an external file
  - Processes each line independently

- Hidden message decoding
  - Stores mismatch positions in a vector
  - Converts each position into an ASCII character using modulo 256
  - Builds and prints the decoded message

- Error handling
  - Checks whether the input file opens successfully before processing

## How It Works

1. The program opens and reads from `programs.txt`.
2. Each line is scanned one character at a time.
3. Opening delimiters `(`, `[`, and `{` are pushed onto a stack.
4. When a closing delimiter is found, the program checks whether it matches the delimiter on top of the stack.
5. If the closing delimiter does not match, the program returns the 1-based column position of the mismatch.
6. Each mismatch position is stored in a vector.
7. The program converts each position to an ASCII character using modulo 256.
8. The ASCII characters are combined to reveal the hidden message.

## Example Output

```text
[decoded hidden message]
```

## Key Concepts Demonstrated

- **Stack-Based Parsing**  
  Uses `std::stack` to match opening and closing delimiters using last-in, first-out behavior.

- **Compiler Front-End Logic**  
  Simulates a portion of how compilers analyze source code structure during parsing.

- **File Input Processing**  
  Reads and processes each line from an external text file.

- **String Traversal**  
  Iterates through each character in a string to identify and evaluate delimiters.

- **ASCII Conversion**  
  Converts numeric positions into ASCII characters to reconstruct a hidden message.

- **Use of STL Containers**  
  Utilizes `stack` and `vector` for efficient data handling and state tracking.

## Design Highlights

- **Single-Purpose Parsing Function**  
  Encapsulates delimiter checking logic in a dedicated function for clarity and reuse.

- **Efficient Delimiter Matching**  
  Leverages stack behavior to handle nested structures cleanly and efficiently.

- **Line-by-Line Processing**  
  Processes each line independently, improving readability and scalability.

- **Data Transformation Pipeline**  
  Converts raw input → mismatch positions → ASCII characters → final decoded message.

## File Structure

- **Source Files**
  - `compiler.cpp` — Handles file input, parsing logic, and message decoding

- **Data Files**
  - `programs.txt` — Contains compressed program lines with mismatched delimiters

## Summary

This project demonstrates how stack-based parsing techniques can be used to analyze structured text similar to a compiler’s front-end. By detecting mismatched delimiters and transforming positional data into ASCII characters, the program combines data structures, file processing, and algorithmic logic into a cohesive decoding system.

# How to Run

1. **Place all files in the same directory**
   - Source file (`.cpp`)
   - Data file (`programs.txt`)

2. **Compile the program**
   ```bash
   g++ -std=c++17 compiler.cpp -o compiler

3. **Run the Executable**
   ```bash
   ./compiler

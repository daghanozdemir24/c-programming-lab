# C Programming Laboratory & Practice

This repository contains C programming practice implementations, lab quizzes, and data structure exercises developed during the Programming II curriculum at Kocaeli University.

## 📌 Repository Contents

| Source File | Description | Core Topics Covered |
| :--- | :--- | :--- |
| `Prog II Quiz I.c` | Matrix row-sum analysis, dynamic condition checks, and transpose matrix multiplication. | 2D Arrays, Functions, Matrix Math |
| `Prog II Quiz II.c` | 4x4 matrix processing: lower-triangle summation, upper-triangle product, and outer border bounds. | Pointer Arithmetic, Memory Traversal |
| `Prog_II_Quiz_IV.c` | Log string parsing, tokenization, number extraction, and selection sort. | Strings (`string.h`), Parsing, Sorting |
| `Prog_II_Quiz_V.c` | Fleet fuel management, cost calculation, threshold alerting, and driver search. | Structures (`struct`), Array of Structs |
| `Struct_example_1.c` | Precise age and lifetime duration calculation using nested date representations. | Custom Structures, Input Validation |
| `Struct_example_2.c` | Automated candidate pool generation, multi-criteria chronological sorting, and scoring. | Struct Sorting, Pseudo-randomness |
| `Struct_example_3.c` | Student registry system with strict input validation and formatted table reporting. | Data Formatting, Bounds Checking |
| `C_Trials.c` | Experimental routines: custom substring search, buffer formatting, and struct storage. | `sprintf` / `sscanf`, Memory Buffers |

## 🛠️ Build and Execution

To compile and run any source file with strict compiler warnings enabled via GCC:

```bash
# Example for Quiz II
gcc -Wall -Wextra "Prog II Quiz II.c" -o quiz2
./quiz2

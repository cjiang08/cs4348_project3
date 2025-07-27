# CS 4348 (OS): Project 3 - Simulated Memory Management System

## Project Information
| Category          | Details                           |
|-------------------|-----------------------------------|
| **Semester**      | Summer 2025                       |
| **Course**        | CS 4348 - Operating Systems       |
| **Project Title** | Simulated Memory Management System|
| **Due Date**      | Thursday, July 27, 2025           |
| **Group**         | #12                               |
| **Members**       | Jaszmine DeFranco, Carolyn Jiang  |

## Overview
This project implements a simulated memory management system that supports:
- Paging
- Memory allocation and deallocation
- Virtual-to-physical address translation
- Page fault handling
- Page replacement algorithms (FIFO and LRU)

Implemented in C and tested on UTD CS Linux machines.

---

## Files & Directories -  Descriptions

| File/Directory       | Description                                                                 |
|----------------------|-----------------------------------------------------------------------------|
| `src/main.c`         | Entry point of the program; parses input commands and invokes operations.   |
| `src/memory.c/h`     | Implements physical memory and frame table management.                      |
| `src/page_table.c/h` | Defines and manages per-process page tables and page entries.               |
| `src/manager.c/h`    | Coordinates memory allocation, access, deallocation, and page faults.       |
| `src/replacement.c/h`| Implements FIFO and LRU page replacement algorithms.                        |
| `test/`              | Contains test input files for simulation of memory operations.              |
| `test/testcase1.txt` | Basic alloc and access (no page fault).                                     |
| `test/testcase2.txt` | Page fault with available frames.                                           |
| `test/testcase3.txt` | Page replacement test with full memory (FIFO or LRU).                       |
| `test/testcase4.txt` | Memory free and reuse validation.                                           |
| `Makefile`           | Compiles all `.c` files into the final executable `memory_manager`.         |
| `README.md`          | Project overview, build/run instructions, test documentation.               |

## Compilation & Execution
### Prerequisites
- UTD CS Lab Access (GlobalProtect VPN required if off-campus)
- GCC compiler

### Steps
```bash
# 1. Connect to CS server
ssh netid@cs1.utdallas.edu

# 2. Navigate to project directory
cd ~/sum25_os/cs4348_project3

# 3. Compile the project
make

# 4. Run a test case
./memory_manager < test/testcase1.txt (four test case already there)

# 5. To switch replacement strategy, edit src/manager.c:
#    Change use_fifo = 1 (FIFO) or 0 (LRU), then recompile

###
Each test case has a corresponding `.txt` file in the `test/` directory:

| Test Case             | Input File              | Output File                |
|-----------------------|-------------------------|----------------------------|
| Basic Access          | `testcase1.txt`         | `testcase1_output.txt`     |
| Page Fault            | `testcase2.txt`         | `testcase2_output.txt`     |
| Page Replacement(FIFO)| `testcase3.txt`         | `testcase3_output_fifo.txt`|
| Page Replacement(LRU) | `testcase3.txt`         | `testcase3_output_lru.txt` |
| Free & Reuse          | `testcase4.txt`         | `testcase4_output.txt`     |

### Additional Information
* Languages & Tools:
    * Language: C
    * IDE used in development: VS Code
    * Version Control: Git (with GitHub for remote repository)



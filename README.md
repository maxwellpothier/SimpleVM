# SimpleVM

This is a simple virtual machine (VM) implemented in C++. It supports three operations: ADD, SUB, and HALT.

## Instructions

- ADD: This instruction increments the accumulator by 1.
- SUB: This instruction decrements the accumulator by 1.
- HALT: This instruction stops the execution of the program.

## Usage

1. Create an instance of SimpleVM.
2. Load a program into the VM's memory. A program is a vector of OpCode.
3. Execute the program.

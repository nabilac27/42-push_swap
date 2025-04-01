# Push_swap Project

The **Push_swap** project is a C program that sorts a list of integers using a series of **push** and **swap** operations. The goal is to implement a sorting algorithm with a limited number of operations and to improve efficiency by minimizing the number of operations needed.

In this implementation, I am using the **Turk Algorithm** to optimize the sorting process. The Turk Algorithm is a sorting strategy that efficiently organizes the stack with minimal moves by strategically pushing and swapping elements.

## Key Concepts
- **Push**: Move an element from one stack to another.
- **Swap**: Swap the top two elements of a stack.
- **Rotate**: Shift all elements of the stack up by one position.
- **Reverse Rotate**: Shift all elements of the stack down by one position.

## Turk Algorithm Overview

The **Turk Algorithm** is a modified version of traditional sorting algorithms that focuses on efficiency by reducing the number of required operations. Here's a simplified description of the steps it follows:

1. **Identifying the median**: The algorithm first identifies a median value of the stack and divides the stack into two parts: smaller and larger than the median.
2. **Partitioning**: Using **push** operations, elements greater than the median are pushed onto a secondary stack, leaving the smaller elements in the original stack.
3. **Sorting the larger half**: The larger half of the elements is then sorted using a set of **swap**, **rotate**, and **reverse rotate** operations.
4. **Final merge**: The elements from the secondary stack are moved back into the original stack, ensuring they are sorted.

By doing this, the algorithm minimizes the number of operations needed to sort the stack compared to traditional methods.

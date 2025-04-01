# Push_swap Project

The **Push_swap** project sorts a list of integers using only **push**, **swap**, **rotate**, and **reverse rotate** operations. 

The goal is to implement an efficient sorting algorithm with a minimal number of operations.

In this implementation, I use the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) to optimize the sorting process.

## Key Concepts

- **Push**: Move the top element from one stack to another.
- **Swap**: Swap the top two elements of a stack.
- **Rotate**: Shift all elements of the stack up by one position.
- **Reverse Rotate**: Shift all elements of the stack down by one position.

## Turk Algorithm Overview

The [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) minimizes the number of operations needed to sort the stack. It works by:

1. Finding the median of the stack.
2. Partitioning the stack into two parts (larger and smaller than the median).
3. Sorting the larger half of the stack.
4. Merging the stacks back together.

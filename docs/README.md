
# **push_swap**

The **Push_swap** project sorts a list of integers using only **push**, **swap**, **rotate**, and **reverse rotate** operations. 

The goal is to implement an efficient sorting algorithm with a minimal number of operations.

In this implementation, I use the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) to optimize the sorting process.

## **Key Concepts**

- **Push**: Move the top element from one stack to another.
- **Swap**: Swap the top two elements of a stack.
- **Rotate**: Shift all elements of the stack up by one position.
- **Reverse Rotate**: Shift all elements of the stack down by one position.

## What this project demonstrates

This project focuses on **sorting data efficiently under strict constraints**.

It is based on the concept of a **stack**, a fundamental data structure that follows the **Last In, First Out (LIFO)** principle — similar to a stack of plates, where the last item placed on top is the first one removed.

Using two stacks (**Stack A** and **Stack B**), the program sorts a list of integers **without using standard sorting functions**.  
Only a limited set of operations is allowed (push, swap, rotate, reverse rotate), which forces a structured and optimized approach instead of brute-force solutions.

To achieve efficiency, this implementation applies the **Turk Algorithm**, which determines optimal moves, minimizes unnecessary operations, and balances correctness with performance.

Overall, this project demonstrates **algorithmic thinking**, **process optimization under constraints**, and **systematic problem-solving** — skills that are directly applicable to IT-driven business and logistics systems.

## **Turk Algorithm Overview**

The [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) minimizes the number of operations needed to sort the stack. It works by:

- Finding the median of the stack.
- Partitioning the stack into two parts (larger and smaller than the median).
- Sorting the larger half of the stack.
- Merging the stacks back together.

## How to Run

To run the project, follow these steps:

1. Compile the program with `make`.
2. Run the executable with your desired input (e.g., `./push_swap 3 2 1`).

## Example

```bash
$ make
$ ./push_swap 3 2 1
$ ./push_swap_v2 5 3 7 4 2 1
$ ./push_swap 5 3 7 4 2 1 | ./checker_Mac
```

---

## Folder Structures

```
push_swap/
│
├── docs/
│   ├── README.md
│   └── en.subject.pdf
│
├── include/
│   ├── lib/
│   │   └── libft.h
│   └── push_swap.h
│
├── src/
│   ├── main.c
│
│   ├── parsing/
│   │   ├── check_args.c
│   │   ├── fill_stack_a.c
│   │   └── utils.c
│
│   ├── operation/
│   │   ├── push.c
│   │   ├── swap.c
│   │   ├── rotate.c
│   │   └── rev_rotate.c
│
│   ├── turk/
│       ├── turk.c
│       ├── fill_stacks.c
│       ├── turk_rotates.c
│       └── utils.c
│
└── Makefile
```

---

## Function Overview

| **Step**            | **Function**                      | **Description**                                                                 |
|---------------------|-----------------------------------|---------------------------------------------------------------------------------|
| **Parsing**         | `check_valid_args`                | Validates the command-line arguments passed to the program.                     |
|                     | `check_whitespace_str`            | Checks if the string contains only whitespaces.                                   |
|                     | `get_input_num`                   | Extracts the input numbers from the arguments.                                  |
|                     | `check_sorted_stack`              | Verifies if the stack is already sorted.                                        |
| **Fill Stack A**    | `fill_stack_a`                    | Fills the first stack (A) with numbers.                                         |
|                     | `check_valid_num`                 | Ensures the number is valid.                                                    |
|                     | `ft_atol`                         | Converts a string to a long integer.                                            |
|                     | `check_dup_num`                   | Checks if a number is a duplicate in stack A.                                   |
|                     | `add_node_to_stack_a`             | Adds a number to stack A.                                                      |
| **Sorting**         | `sort_3`                          | Sorts the top 3 elements in stack A.                                            |
|                     | `find_value`                      | Finds a value in the stack based on its type.                                   |
|                     | `free_stack`                      | Frees the memory used by the stack.                                             |
| **Turk Algorithm**  | `turk_algorithm`                  | Main function that runs the Turk Algorithm to minimize operations for sorting.   |
|                     | `calc_moves_fill_stack_b`         | Calculates the number of moves required to fill stack B.                        |
|                     | `fill_stack_b`                    | Fills stack B using calculated moves.                                           |
|                     | `calc_moves_fill_back_stack_a`    | Calculates the number of moves to fill stack A back from stack B.               |
|                     | `fill_back_stack_a`               | Fills back stack A using calculated moves.                                      |
|                     | `final_sort`                      | Final sorting of stack A.                                                      |
| **Rotate & Rev-Rotate** | `rotate_both`                  | Rotates both stack A and stack B simultaneously.                                |
|                     | `rev_rotate_both`                 | Reverses both stack A and stack B simultaneously.                               |
|                     | `rotate_one_stack`                | Rotates one stack (A or B).                                                     |
| **Operations**      | `push`                            | Pushes the top element from one stack to another.                               |
|                     | `pa`                              | Pushes the top element from stack B to stack A.                                 |
|                     | `pb`                              | Pushes the top element from stack A to stack B.                                 |
|                     | `swap`                            | Swaps the top two elements of the stack.                                        |
|                     | `sa`                              | Swaps the top two elements of stack A.                                          |
|                     | `sb`                              | Swaps the top two elements of stack B.                                          |
|                     | `ss`                              | Swaps the top two elements of both stacks A and B.                              |
|                     | `rotate`                          | Rotates the stack (shifts elements to the top).                                 |
|                     | `ra`                              | Rotates stack A.                                                                |
|                     | `rb`                              | Rotates stack B.                                                                |
|                     | `rr`                              | Rotates both stacks A and B.                                                   |
|                     | `rev_rotate`                      | Reverses the rotation of the stack (shifts elements to the bottom).             |
|                     | `rra`                             | Reverses the rotation of stack A.                                              |
|                     | `rrb`                             | Reverses the rotation of stack B.                                              |
|                     | `rrr`                             | Reverses the rotation of both stacks A and B.                                  |


---


## More Detailed How To Run

Compile the program:
```bash
make
```

Run the executable with a list of integers:
```bash
./push_swap 3 2 1
```

Example Output
```bash
$ ./push_swap 3 2 1
sa
rra
```

What this output means:
- sa → swap the top two elements of stack A
- rra → reverse rotate stack A

When these operations are applied in order, the initial input 3 2 1 becomes sorted as 1 2 3.

Verifying the result
You can verify that the output operations correctly sort the numbers by piping them into the checker program:

```bash
$ ./push_swap 5 3 7 4 2 1 | ./checker_Mac
OK
```

Explanation:
- push_swap outputs a sequence of operations
- checker_Mac executes these operations on the input
- OK confirms that the stack is correctly sorted
- If the operations are incorrect, the checker will output KO.



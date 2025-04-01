/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:02:30 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/13 22:25:42 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/lib/ft_printf/ft_printf.h"
# include "../include/lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;

	int				move_cost;
	bool			median;
	bool			cheapest_move;

	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}					t_stack;

typedef enum e_value
{
	FIND_MIN_VALUE,
	FIND_MAX_VALUE
}					t_value;

typedef enum e_stack_type
{
	STACK_A,
	STACK_B
}					t_stack_type;

/* **********	PARSING ********** */
// check_args.c
char				**check_valid_args(int argc, char *argv[]);
bool				check_whitespace_str(char **argv);
char				**get_input_num(char **argv);
bool				check_sorted_stack(t_stack *stack);

// fill_stack_a.c
void				fill_stack_a(t_stack **stack_a, char **num);
bool				check_valid_num(char *str);
long				ft_atol(const char *str);
bool				check_dup_num(t_stack *stack_a, int current_num);
void				add_node_to_stack_a(t_stack **stack_a, int num);

// utils.c
void				sort_3(t_stack **stack_a);
t_stack				*find_value(t_stack *stack, t_value value_type);
void				free_stack(t_stack **stack);
void				error_free_stack(t_stack **stack);
int					count_stack_len(t_stack *stack);

/* ********** TURK ********** */
// turk.c
void				turk_algorithm(t_stack **stack_a, t_stack **stack_b);

// fill_stacks.c
void				calc_moves_fill_stack_b(t_stack *stack_a, t_stack *stack_b);
void				fill_stack_b(t_stack **stack_a, t_stack **stack_b);
void				calc_moves_fill_back_stack_a(t_stack *stack_a,
						t_stack *stack_b);
void				fill_back_stack_a(t_stack **stack_a, t_stack **stack_b);
void				final_sort(t_stack **stack_a);

// turks_rotate.c
void				rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void				rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void				rotate_one_stack(t_stack **stack, t_stack *best,
						t_stack_type type);

// utils.c
void				get_index(t_stack *stack);
void				get_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void				calc_cost(t_stack *stack_a, t_stack *stack_b);
void				get_cheapest(t_stack *stack_a);
void				get_target_stack_a(t_stack *stack_a, t_stack *stack_b);

/* ********** OPERATION ********** */
// push.c
void				push(t_stack **dst, t_stack **src);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);

// swap.c
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);

// rotate.c
void				rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **a, t_stack **b);
t_stack				*get_current_end(t_stack *stack);

// rev_rotate.c
void				rev_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **a, t_stack **b);

#endif

/*
	MEMORY CHECK
	void	check_leaks(void)
	{
	pid_t   pid;
	char    cmd[256];
	pid = getpid();
	snprintf(cmd, sizeof(cmd), "leaks %d", pid);
	system(cmd);
	}
	atexit(check_leaks);

	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 6 2 4 3 666 111 7753

	RANDOM NUMBER GENERATOR
	https://www.calculatorsoup.com/calculators/statistics/
	random-number-generator.php

	PRINT STACK
	void	print_stack(t_stack *stack)
	{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
	}
	printf("\nstack a: ");
	print_stack(*stack_a);
	printf("\nstack b: ");
	print_stack(*stack_b);
	printf("\n-------\n");
*/

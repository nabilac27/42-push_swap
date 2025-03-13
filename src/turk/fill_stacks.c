/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:31:18 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/13 02:09:41 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	calc_moves_fill_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	get_index(stack_a);
	get_index(stack_b);
	get_target_stack_b(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	get_cheapest(stack_a);
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = *stack_a;
	while (cheapest && !cheapest->cheapest_move)
		cheapest = cheapest->next;
	if (!cheapest)
		error_free_stack(stack_a);
	if (cheapest->median && cheapest->target->median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->median && !cheapest->target->median)
		rev_rotate_both(stack_a, stack_b, cheapest);
	rotate_one_stack(stack_a, cheapest, STACK_A);
	rotate_one_stack(stack_b, cheapest->target, STACK_B);
	pb(stack_b, stack_a);
}

void	calc_moves_fill_back_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	get_index(stack_a);
	get_index(stack_b);
	get_target_stack_a(stack_a, stack_b);
}

void	fill_back_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_one_stack(stack_a, (*stack_b)->target, STACK_A);
	pa(stack_a, stack_b);
}

void	final_sort(t_stack **stack_a)
{
	while ((*stack_a)->value != find_value(*stack_a, FIND_MIN_VALUE)->value)
	{
		if (find_value(*stack_a, FIND_MIN_VALUE)->median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

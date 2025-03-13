/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:48:11 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/11 05:24:09 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rr(stack_a, stack_b);
	get_index(*stack_a);
	get_index(*stack_b);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rrr(stack_a, stack_b);
	get_index(*stack_a);
	get_index(*stack_b);
}

void	rotate_one_stack(t_stack **stack, t_stack *cheapest, t_stack_type type)
{
	while (*stack != cheapest)
	{
		if (type == STACK_A)
		{
			if (cheapest->median == true)
				ra(stack);
			else
				rra(stack);
		}
		else if (type == STACK_B)
		{
			if (cheapest->median == true)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

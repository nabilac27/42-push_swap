/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:15:06 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/11 05:22:40 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*new_end;
	t_stack	*current_end;

	if (!*stack || !(*stack)->next)
		return ;
	current_end = get_current_end(*stack);
	new_end = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current_end->next = new_end;
	new_end->prev = current_end;
	new_end->next = NULL;
}

t_stack	*get_current_end(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:00:31 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/12 22:22:15 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*max;

	max = find_value(*stack_a, FIND_MAX_VALUE);
	if (max == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a);
}

t_stack	*find_value(t_stack *stack, t_value value_type)
{
	int		find_value;
	t_stack	*find_value_node;

	find_value_node = NULL;
	if (value_type == FIND_MIN_VALUE)
		find_value = INT_MAX;
	else if (value_type == FIND_MAX_VALUE)
		find_value = INT_MIN;
	while (stack)
	{
		if ((value_type == FIND_MIN_VALUE && stack->value <= find_value)
			|| (value_type == FIND_MAX_VALUE && stack->value >= find_value))
		{
			find_value = stack->value;
			find_value_node = stack;
		}
		stack = stack->next;
	}
	return (find_value_node);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	error_free_stack(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	count_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

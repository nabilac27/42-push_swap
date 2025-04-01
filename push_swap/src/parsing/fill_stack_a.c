/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:36:42 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/13 22:25:18 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	fill_stack_a(t_stack **stack_a, char **num)
{
	long	long_num;
	int		i;

	i = 0;
	while (num[i])
	{
		if (check_valid_num(num[i]) == false)
		{
			free_2d(num);
			error_free_stack(stack_a);
		}
		long_num = ft_atol(num[i]);
		if (long_num < INT_MIN || long_num > INT_MAX)
		{
			free_2d(num);
			error_free_stack(stack_a);
		}
		if (!check_dup_num(*stack_a, (int)long_num))
		{
			free_2d(num);
			error_free_stack(stack_a);
		}
		add_node_to_stack_a(stack_a, (int)long_num);
		i++;
	}
	free_2d(num);
}

bool	check_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if ((str[i] < '0' && str[i] > '9') || str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

long	ft_atol(const char *str)
{
	int		i;
	int		negative;
	long	result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1 * negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * negative);
}

bool	check_dup_num(t_stack *stack_a, int current_num)
{
	while (stack_a)
	{
		if (stack_a->value == current_num)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	add_node_to_stack_a(t_stack **stack_a, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->value = num;
	node->next = NULL;
	node->cheapest_move = false;
	if (!(*stack_a))
	{
		node->prev = NULL;
		*stack_a = node;
	}
	else
	{
		last_node = *stack_a;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}

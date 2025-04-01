/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:57:39 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/13 22:24:34 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input_num;

	stack_a = NULL;
	stack_b = NULL;
	input_num = check_valid_args(argc, argv);
	if (!input_num)
		return (0);
	fill_stack_a(&stack_a, input_num);
	if (check_sorted_stack(stack_a) == false)
	{
		if (count_stack_len(stack_a) == 2)
			sa(stack_a);
		else if (count_stack_len(stack_a) == 3)
			sort_3(&stack_a);
		else
			turk_algorithm(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

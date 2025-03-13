/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:52:27 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/12 22:22:09 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**check_valid_args(int argc, char *argv[])
{
	char	**input_num;

	if (argc < 2)
		exit(0);
	if (!argv[1] || check_whitespace_str(argv))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	if (check_whitespace_str(argv) == true)
		return (NULL);
	else if (argc == 2)
		input_num = ft_split(argv[1], ' ');
	else
		input_num = get_input_num(argv);
	return (input_num);
}

bool	check_whitespace_str(char **argv)
{
	int	i;

	if (!argv || !argv[1])
		return (false);
	i = 0;
	while (argv && argv[1][i])
	{
		if (ft_isspace(argv[1][i]))
			i++;
		else
			return (false);
	}
	return (true);
}

char	**get_input_num(char **argv)
{
	int		i;
	int		argc;
	char	**input_num;

	i = 0;
	argc = 0;
	while (argv[argc])
		argc++;
	input_num = (char **)malloc(sizeof(char *) * argc);
	if (!input_num)
		return (NULL);
	while (argv[i + 1])
	{
		input_num[i] = ft_strdup(argv[i + 1]);
		if (!input_num[i])
		{
			while (i > 0)
				free(input_num[--i]);
			free(input_num);
			return (NULL);
		}
		i++;
	}
	input_num[i] = NULL;
	return (input_num);
}

bool	check_sorted_stack(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

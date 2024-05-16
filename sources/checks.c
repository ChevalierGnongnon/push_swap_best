/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:38:12 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 11:07:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_doubles(t_node **stack)
{
	t_node	*current;
	t_node	*next_one;

	current = (*stack);
	while (current->next)
	{
		next_one = current->next;
		while (next_one)
		{
			if (current->value != next_one->value)
				next_one = next_one->next;
			else
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_sorted(t_node **stack)
{
	t_node	*current;
	t_node	*previous;

	if (!(*stack) || !(*stack)->next)
		return (1);
	previous = (*stack);
	current = (*stack)->next;
	while (current)
	{
		if (previous->value < current->value)
		{
			current = current->next;
			previous = previous->next;
		}
		else
			return (0);
	}
	return (1);
}

int	check_small(t_node *target, t_node **stack)
{
	t_node	*current;
	int		size;
	int		i;

	current = (*stack);
	size = chain_size(stack);
	i = 0;
	while (current && current->value > target->value)
	{
		i++;
		current = current->next;
	}
	if (i == size)
		return (0);
	return (1);
}

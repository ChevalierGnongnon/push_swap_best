/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:38:12 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:51:20 by chhoflac         ###   ########.fr       */
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
		if (argv[i][0] == '-')
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

int	check_doubles(t_node **head)
{
	t_node	*current;
	t_node	*next_one;

	current = (*head);
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

int	check_sorted(t_node **chain)
{
	t_node	*current;
	t_node	*previous;

	if (!(*chain) || !(*chain)->next)
		return (1);
	previous = (*chain);
	current = (*chain)->next;
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

void	check_stackb_begin(t_node **stack_b)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
	{	
		ft_printf("rb\n");
		rotate(stack_b);
	}
}

int	check_small(t_node *target, t_node **head)
{
	t_node	*current;
	int		size;
	int		i;

	current = (*head);
	size = chain_size(head);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:42:39 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 14:05:54 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chain_size(t_node **stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_node	*get_last(t_node **stack)
{
	t_node	*buffer;

	buffer = (*stack);
	while (buffer->next)
		buffer = buffer->next;
	return (buffer);
}

void	clear_list(t_node **stack)
{
	t_node	*current;

	while ((*stack))
	{
		current = (*stack)->next;
		free((*stack));
		(*stack) = current;
	}
}

t_node	*get_min(t_node **stack)
{
	t_node	*min;
	t_node	*current;

	current = (*stack);
	min = (*stack);
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*get_max(t_node **stack)
{
	t_node	*max;
	t_node	*current;

	max = (*stack);
	current = (*stack);
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

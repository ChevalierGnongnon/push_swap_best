/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:42:39 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:53:06 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chain_size(t_node **lst)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = (*lst);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_node	*get_last(t_node **lst)
{
	t_node	*buffer;

	buffer = (*lst);
	while (buffer->next)
		buffer = buffer->next;
	return (buffer);
}

void	clear_list(t_node **list)
{
	t_node	*current;

	while ((*list))
	{
		current = (*list)->next;
		free((*list));
		(*list) = current;
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

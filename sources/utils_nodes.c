/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:15:40 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/12 16:05:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_place(t_node **head, int target_value)
{
	t_node	*current;
	int		place;

	current = (*head);
	place = 1;
	while (current->next && current->value != target_value)
	{
		place++;
		current = current->next;
	}
	return (place);
}

void	change_stack(t_node *node)
{
	if (node->stack == 'a')
		node->stack = 'b';
	else
		node->stack = 'a';
}

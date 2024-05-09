/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:37:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/09 15:46:47 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_under(t_node *node, t_node **head)
{
	t_node	*current;
	t_node	*under;

	under = malloc(sizeof(t_node *));
	current = (*head);
	under->value = INT_MIN;
	under->next = NULL;
	under->stack = 'b';
	while (current)
	{
		if (current->value < node->value)
		{
			if (under->value < current->value)
				under = current;
		}
		current = current->next;
	}
	return (under);
}

int	rotation_sense(t_node **head, t_node *target)
{
	int	size;
	int	target_place;

	size = chain_size(head);
	target_place = get_place(head, target->value);
	if (target_place > size / 2)
		return (1);
	return (0);
}

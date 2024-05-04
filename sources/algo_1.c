/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:37:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:31 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_under(t_node *node, t_node **head)
{
	t_node	*current;

	current = (*head);
	while (current && current->value > node->value)
		current = current->next;
	return (current);
}

t_node	*get_upper(t_node *node, t_node **head)
{
	t_node	*current;

	current = (*head);
	while (current && current->value < node->value)
		current = current->next;
	return (current);
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

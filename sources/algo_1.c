/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:37:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 14:07:40 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_under(t_node *node, t_node **stack)
{
	t_node	*current;
	t_node	*under;

	under = get_min(stack);
	current = (*stack);
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

int	rotation_sense(t_node **stack, t_node *target)
{
	int	size;
	int	target_place;

	size = chain_size(stack);
	target_place = get_place(stack, target->value);
	if (target_place > size / 2)
		return (1);
	return (0);
}

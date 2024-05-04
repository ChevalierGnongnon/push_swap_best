/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:30:47 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:51:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_up(t_node **head, t_node *target)
{
	int		i;
	t_node	*current;

	i = 0;
	if (rotation_sense(head, target))
	{
		current = target->next;
		while (current)
		{
			i++;
			current = current->next;
		}
		return (i + 1);
	}
	else if (!rotation_sense(head, target))
	{
		current = (*head);
		while (current != target)
		{
			i++;
			current = current->next;
		}
		return (i);
	}
	return (0);
}

int	count(t_node **head1, t_node **head2, t_node *target)
{
	int		moves;
	t_node	*under;

	under = get_under(target, head2);
	if (!check_small(target, head2))
		moves = count_up(head1, target) + 2;
	else
		moves = count_up(head1, target) + 1 + count_up(head2, under) + 2;
	return (moves);
}

t_node	*get_best(t_node **head1, t_node **head2)
{
	t_node	*current;
	t_node	*best;

	current = (*head1);
	best = current;
	while (current)
	{
		if (count(head1, head2, current)
			< count(head1, head2, best))
			best = current;
		current = current->next;
	}
	return (best);
}

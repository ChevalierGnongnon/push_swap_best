/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:30:47 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 13:58:39 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_up(t_node **stack, t_node *target)
{
	int		i;
	t_node	*current;

	i = 0;
	if (rotation_sense(stack, target))
	{
		current = target->next;
		while (current)
		{
			i++;
			current = current->next;
		}
		return (i + 1);
	}
	else if (!rotation_sense(stack, target))
	{
		current = (*stack);
		while (current != target)
		{
			i++;
			current = current->next;
		}
		return (i);
	}
	return (0);
}

int	count(t_node **stack1, t_node **stack2, t_node *target)
{
	int		moves;
	int		dif;
	t_node	*under;

	under = get_under(target, stack2);
	if (!check_small(target, stack2))
		moves = count_up(stack1, target) + 1;
	else
	{
		if ((rotation_sense(stack1, target) == rotation_sense(stack2, under))
			&& !rotation_sense(stack1, target))
		{
			if (count_up(stack2, under) > count_up(stack1, target))
				dif = count_up(stack2, under) - count_up(stack1, target);
			else
				dif = count_up(stack1, target) - count_up(stack2, under);
			moves = count_up(stack1, target) + 1 + dif;
		}
		else
			moves = count_up(stack1, target) + 1 + count_up(stack2, under);
	}
	return (moves);
}

t_node	*get_best(t_node **stack1, t_node **stack2)
{
	t_node	*current;
	t_node	*best;

	current = (*stack1);
	best = current;
	while (current)
	{
		if (count(stack1, stack2, current)
			< count(stack1, stack2, best))
			best = current;
		current = current->next;
	}
	return (best);
}

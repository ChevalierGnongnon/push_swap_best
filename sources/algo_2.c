/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:35:55 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 15:01:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_up(t_node **stack, t_node *target)
{
	if (rotation_sense(stack, target))
	{
		while ((*stack)->value != target->value)
			do_reverse_rotate(stack);
	}
	else
	{
		while ((*stack)->value != target->value)
			do_rotate(stack);
	}
}

void	replace_in_a(t_node **stack_a, t_node **stack_b)
{
	int		rotate_available;

	rotate_available = 3;
	while (chain_size(stack_b) > 0)
	{
		if (get_last(stack_a)->value > (*stack_b)->value && rotate_available)
		{
			do_reverse_rotate(stack_a);
			rotate_available--;
		}
		else
			push(stack_b, stack_a);
	}
}

void	do_best(t_node **stack_a, t_node **stack_b, t_node *best)
{
	t_node	*under;

	under = get_under(best, stack_b);
	if (best->value > get_max(stack_b)->value
		|| best->value < get_min(stack_b)->value)
	{
		go_up(stack_a, best);
		go_up(stack_b, get_max(stack_b));
	}
	else
	{
		if (rotation_sense(stack_a, best) == rotation_sense(stack_b, under)
			&& !rotation_sense(stack_a, best)
			&& !rotation_sense(stack_b, under))
			doublerup(stack_a, stack_b, best, under);
		else
		{
			go_up(stack_a, best);
			go_up(stack_b, under);
		}
	}
	push(stack_a, stack_b);
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;

	while (chain_size(stack_a) > 3)
	{
		if (chain_size(stack_b) < 2)
			push(stack_a, stack_b);
		else
		{
			best = get_best(stack_a, stack_b);
			do_best(stack_a, stack_b, best);
		}
	}
	go_up(stack_b, get_max(stack_b));
	small_sort(stack_a);
	replace_in_a(stack_a, stack_b);
	go_up(stack_a, get_min(stack_a));
}

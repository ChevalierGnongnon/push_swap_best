/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:57:16 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:48 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_instruction_1(t_node **stack_a)
{
	rotate(stack_a);
	swap(stack_a);
}

static void	double_instruction_2(t_node **stack_a)
{
	reverse_rotate(stack_a);
	swap(stack_a);
}

void	small_sort(t_node **stack_a)
{
	t_node	*one;
	t_node	*two;
	t_node	*three;

	one = (*stack_a);
	two = (*stack_a)->next;
	if (chain_size(stack_a) > 2)
		three = (*stack_a)->next->next;
	if (chain_size(stack_a) == 2 && !check_sorted(stack_a))
		swap(stack_a);
	else if (check_sorted(stack_a))
		return ;
	else if (one->value > two->value && two->value > three->value)
		double_instruction_1(stack_a);
	else if (one->value < two->value && two->value > three->value
		&& one->value > three->value)
		reverse_rotate(stack_a);
	else if (one->value > two->value && two->value < three->value
		&& one->value < three->value)
		swap(stack_a);
	else if (one->value < two->value && two->value > three->value
		&& one->value < three->value)
		double_instruction_2(stack_a);
	else
		rotate(stack_a);
}

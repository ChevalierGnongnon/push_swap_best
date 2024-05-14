/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:13:02 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/14 11:28:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*temp_node;

	if (stack && (*stack)->next)
	{
		temp_node = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		temp_node->next = (*stack);
		(*stack) = temp_node;
	}
}

void	push(t_node **from, t_node **to)
{
	t_node	*temp;
	char	stack;

	stack = (*from)->stack;
	change_stack((*from));
	temp = (*from)->next;
	(*from)->next = (*to);
	(*to) = (*from);
	(*from) = temp;
	if (stack == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*temp;

	temp = (*stack);
	(*stack) = (*stack)->next;
	last = get_last(stack);
	temp->next = NULL;
	last->next = temp;
}

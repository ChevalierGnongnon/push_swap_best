/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:05:35 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/10 09:28:33 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*new_first;
	t_node	*last;

	last = (*stack);
	while (last->next->next)
		last = last->next;
	new_first = last->next;
	last->next = NULL;
	new_first->next = (*stack);
	(*stack) = new_first;
	ft_printf("rr%c\n", (*stack)->stack);
}

void	double_reverse_rotate(t_node **stack_1, t_node **stack_2)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
	ft_printf("rrr\n");
}

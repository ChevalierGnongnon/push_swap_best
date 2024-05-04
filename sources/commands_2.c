/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:05:35 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:51:37 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*new_first;
	t_node	*last;

	last = (*head);
	while (last->next->next)
		last = last->next;
	new_first = last->next;
	last->next = NULL;
	new_first->next = (*head);
	(*head) = new_first;
	ft_printf("rr%c\n", (*head)->stack);
}

void	double_reverse_rotate(t_node **head1, t_node **head2)
{
	reverse_rotate(head1);
	reverse_rotate(head2);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:13:02 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/30 15:48:21 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*temp_node;

	if (head && (*head)->next)
	{
		temp_node = (*head)->next;
		(*head)->next = (*head)->next->next;
		temp_node->next = (*head);
		(*head) = temp_node;
		ft_printf("s%c\n", (*head)->stack);
	}
}

int	double_swap(t_node **head1, t_node **head2)
{
	if ((head1 && (*head1)->next) && (head2 && (*head2)->next))
	{
		swap(head1);
		swap(head2);
		ft_printf("ss\n");
	}
	return (0);
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

void	rotate(t_node **head)
{
	t_node	*last;
	t_node	*temp;

	temp = (*head);
	(*head) = (*head)->next;
	last = get_last(head);
	temp->next = NULL;
	last->next = temp;
	ft_printf("r%c\n", (*head)->stack);
}

void	double_rotate(t_node **head1, t_node **head2)
{
	rotate(head1);
	rotate(head2);
	ft_printf("rr\n");
}

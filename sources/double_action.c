/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:59:08 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 09:58:37 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	doubledup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	int	tog;
	int	dif;

	if (get_place(staca, targa->value) < get_place(stacb, targb->value))
	{
		dif = get_place(stacb, targb->value) - get_place(staca, targa->value);
		tog = get_place(stacb, targb->value) - dif;
		while ((*staca)->value != targa->value)
			do_double_rotate(staca, stacb);
		while ((*stacb)->value != targb->value)
			do_rotate(stacb);
	}
	else
	{
		dif = get_place(staca, targa->value) - get_place(stacb, targb->value);
		tog = get_place(staca, targa->value) - dif;
		while ((*stacb)->value != targb->value && tog--)
			do_double_rotate(staca, stacb);
		while ((*staca)->value != targa->value && dif--)
			do_rotate(staca);
	}
}

void
	doublerup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	if (get_place(staca, targa->value) == get_place(stacb, targb->value))
	{
		while ((*staca)->value != targa->value
			&& (*stacb)->value != targb->value)
			do_double_rotate(staca, stacb);
	}
	else if (get_place(staca, targa->value) != get_place(stacb, targb->value))
		doubledup(staca, stacb, targa, targb);
}

/*void
	doubledrrup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	int	dif;
	int	tog;

	if ()
}

void
	doublerrup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	if (get_place(staca, targa->value) == get_place(stacb, targb->value))
	{
		while ((*staca)->value != targa->value
			&& (*stacb)->value != targb->value)
			do_double_reverse_rotate(staca, stacb);
	}
	else
		doubledrrup(staca, stacb, targa, targb);
}*/



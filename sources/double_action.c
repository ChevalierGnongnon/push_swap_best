/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:59:08 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/13 15:13:44 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	doublerup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	while ((*staca)->value != targa->value
		&& (*stacb)->value != targb->value)
		do_double_rotate(staca, stacb);
}

void
	doublerrup(t_node **staca, t_node **stacb, t_node *targa, t_node *targb)
{
	while ((*staca)->value != targa->value
		&& (*stacb)->value != targb->value)
		do_double_rotate(staca, stacb);
}
	
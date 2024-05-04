/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:34 by chhoflac          #+#    #+#             */
/*   Updated: 2024/04/28 15:13:12 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int n)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof (t_node));
	new->value = n;
	new->stack = 'a';
	new->next = NULL;
	return (new);
}

t_node	*create_chain(char **argv)
{
	int		i;
	t_node	*first;
	t_node	*current;

	i = 1;
	first = create_node(ft_atoi(argv[i]));
	i++;
	current = first;
	while (argv[i])
	{
		current->next = create_node(ft_atoi(argv[i]));
		current = current->next;
		i++;
	}
	return (first);
}

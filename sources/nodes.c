/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:34 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 16:21:23 by chhoflac         ###   ########.fr       */
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
	int		value;

	i = 1;
	first = create_node(ft_atoi(argv[i]));
	i++;
	current = first;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		current->next = create_node(value);
		current = current->next;
		i++;
	}
	return (first);
}

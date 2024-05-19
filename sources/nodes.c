/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:34 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/19 16:11:02 by chhoflac         ###   ########.fr       */
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
	first = NULL;
	current = NULL;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			clear_list(&first);
			return (NULL);
		}
		if (!current)
		{
			first = create_node(ft_atol(argv[i]));
			current = first;
		}
		else
		{
			current->next = create_node(ft_atol(argv[i]));
			current = current->next;
		}
		i++;
	}
	return (first);
}

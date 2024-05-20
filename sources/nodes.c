/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:34 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/20 18:21:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int n)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof (t_node));
	if (!new)
		return (NULL);
	new->value = n;
	new->stack = 'a';
	new->next = NULL;
	return (new);
}

t_node	*create_middle_node(t_node *current, char *argv)
{
	current->next = create_node(ft_atol(argv));
	if (!current->next)
		return (NULL);
	current = current->next;
	return (current);
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
			return (clear_list(&first));
		if (!current)
		{
			first = create_node(ft_atol(argv[i]));
			current = first;
		}
		else
			current = create_middle_node(current, argv[i]);
		if (!current)
			return (clear_list(&first));
		i++;
	}
	return (first);
}

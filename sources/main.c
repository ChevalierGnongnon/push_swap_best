/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:48 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/19 16:14:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*check_everything(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc > 1 && check_numeric(argc, argv))
	{
		stack_a = create_chain(argv);
		if (stack_a && check_doubles(&stack_a) && !check_sorted(&stack_a))
			return (stack_a);
		else if (check_sorted(&stack_a))
			clear_list(&stack_a);
		else if (!stack_a || !check_doubles(&stack_a))
		{
			ft_putstr_fd("Error\n", 2);
			clear_list(&stack_a);
		}
	}
	else if (!check_numeric(argc, argv))
		ft_putstr_fd("Error\n", 2);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = check_everything(argc, argv);
	stack_b = NULL;
	if (stack_a)
	{
		if (chain_size(&stack_a) <= 3)
			small_sort(&stack_a);
		else
			big_sort(&stack_a, &stack_b);
	}
	clear_list(&stack_a);
	clear_list(&stack_b);
}

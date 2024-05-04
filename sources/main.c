/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:12:48 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/01 11:20:13 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*check_everything(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc > 2 && check_numeric(argc, argv))
	{
		stack_a = create_chain(argv);
		if (check_doubles(&stack_a) &&!check_sorted(&stack_a))
			return (stack_a);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = check_everything(argc, argv);
	if (stack_a)
	{
		stack_b = NULL;
		if (chain_size(&stack_a) <= 3)
			small_sort(&stack_a);
		else
			big_sort(&stack_a, &stack_b);
	}
}

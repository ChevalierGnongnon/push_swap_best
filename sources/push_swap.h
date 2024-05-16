/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:14:26 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/16 14:27:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	char			stack;
	struct s_node	*next;
}	t_node;

int		check_numeric(int argc, char **argv);
int		check_doubles(t_node **stack);
int		check_sorted(t_node **stack);

t_node	*create_node(int value);
t_node	*create_chain(char **argv);
void	clear_list(t_node **stack);

void	change_stack(t_node *node);

void	swap(t_node **stack);
void	push(t_node **from, t_node **to);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

int		chain_size(t_node **stack);

t_node	*get_last(t_node **stack);
t_node	*get_under(t_node *node, t_node **stack);
t_node	*get_upper(t_node *node, t_node **stack);
t_node	*get_best(t_node **stack1, t_node **stack2);
int		get_place(t_node **stack, int target_value);
int		rotation_sense(t_node **stack, t_node *target);
int		count_up(t_node **stack, t_node *target);
int		count_left(t_node *target, t_node **stack2);
int		check_small(t_node *target, t_node **stack);
void	display_lists(t_node **stack_a, t_node **stack_b);

void	small_sort(t_node **stack_a);
void	big_sort(t_node **stack_a, t_node **stack_b);
t_node	*get_min(t_node **stack);
t_node	*get_max(t_node **stack);

void	do_swap(t_node **stack);
void	do_double_swap(t_node **stack_a, t_node **stack_b);
void	do_rotate(t_node **stack);
void	do_double_rotate(t_node **stack_a, t_node **stack_b);
void	do_reverse_rotate(t_node **stack);
void	do_double_reverse_rotate(t_node **stack_a, t_node **stack_b);
void	doublerup(t_node **staca, t_node **stacb, t_node *best, t_node *under);

#endif
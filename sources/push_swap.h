/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:14:26 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/01 17:16:34 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				pos_finale;
	int				pos_actuelle;
	char			stack;
	int				cout;
	struct s_node	*next;
}	t_node;

int		check_numeric(int argc, char **argv);
int		check_doubles(t_node **start);
int		check_sorted(t_node **chain);
void	check_stackb_begin(t_node **stack_b);

t_node	*create_node(int value);
t_node	*create_chain(char **argv);
void	clear_list(t_node **head);

void	change_stack(t_node *node);

void	swap(t_node **head);
int		double_swap(t_node **head1, t_node **head2);
void	push(t_node **from, t_node **to);
void	rotate(t_node **head);
void	double_rotate(t_node **head1, t_node **head2);
void	reverse_rotate(t_node **head);
void	double_reverse_rotate(t_node **head1, t_node **head2);

int		chain_size(t_node **lst);

t_node	*get_last(t_node **lst);
t_node	*get_under(t_node *node, t_node **head);
t_node	*get_upper(t_node *node, t_node **head);
t_node	*get_best(t_node **head1, t_node **head2);
int		get_place(t_node **head, int target_value);
int		rotation_sense(t_node **head, t_node *target);
int		count_up(t_node **head, t_node *target);
int		count_left(t_node *target, t_node **head2);
int		check_small(t_node *target, t_node **head);
void	display_lists(t_node **stack_a, t_node **stack_b);

void	small_sort(t_node **stack_a);
void	big_sort(t_node **stack_a, t_node **stack_b);
t_node	*get_min(t_node **head);
t_node	*get_max(t_node **head);
void	try_algo(t_node **stack_a, t_node **stack_b);

#endif
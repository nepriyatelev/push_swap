/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:28:34 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/25 18:10:33 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct buffer
{
	long int			index;
	int					decimal;
	int					flag;
	struct buffer		*next;
}	t_buffer;

/*====================ERROR_PROCESSING====================*/
void		replay_checking(t_buffer **node);
int			sort_checking(t_buffer **node);
/*=====================FUNCTION_UTILS=====================*/
int			ft_atoi(const char *str);
int			ft_abs(int decimal);
/*=======================LIST_UTILS=======================*/
t_buffer	*create_node(char **set_decimal, int argc);
int			number_of_nodes(t_buffer **node);
void		sorting_by_indices(t_buffer **node);
int			middle_index(t_buffer **node);
int			search_for_a_number_by_index(t_buffer **node, int index);
/*==========================PUSH==========================*/
void		pa(t_buffer **node_a, t_buffer **node_b);
void		pb(t_buffer **node_b, t_buffer **node_a);
/*======================REVERSE_ROTATE====================*/
void		rra(t_buffer **node_a);
void		rrb(t_buffer **node_a);
void		rrr(t_buffer **node_a, t_buffer **node_b);
/*=========================ROTATE=========================*/
void		ra(t_buffer **node_a);
void		rb(t_buffer **node_a);
void		rr(t_buffer **node_a, t_buffer **node_b);
/*==========================SWAP==========================*/
void		sa(t_buffer **node);
void		sb(t_buffer **node);
void		ss(t_buffer **node_a, t_buffer **node_b);
/*=========================PUSH_B=========================*/
void		push_b(t_buffer **node_a, t_buffer **node_b);
/*======================ROTATE_STACKS=====================*/
void		rotate_stacks(t_buffer **node_a, t_buffer **node_b,
				int rotate_a, int rotate_b);
/*=========================BIG_SORT=======================*/
int			number_of_rotate(t_buffer **node, int decimal);
int			find_adjacent_larger_number(t_buffer **node_a, int decimal);
void		number_of_rotate_before_stack_a(t_buffer **node_a,
				t_buffer **node_b);
int			find_the_minimum_number(t_buffer **node_b);
void		sort_big_stack(t_buffer **node_a, t_buffer **node_b);
/*========================SMALL_SORT======================*/
void		sorting_two_numbers(t_buffer **node);
void		sorting_three_numbers(t_buffer **node);
void		sorting_four_numbers(t_buffer **node_a, t_buffer **node_b);
void		sorting_five_numbers(t_buffer **node_a, t_buffer **node_b);
#endif

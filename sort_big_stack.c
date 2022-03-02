/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:02:33 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/25 17:58:15 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_rotate(t_buffer **node, int decimal)
{
	t_buffer	*tmp;
	int			rotate;
	int			reverse_rotate;

	tmp = *node;
	rotate = 0;
	while (tmp != NULL)
	{
		if (tmp->decimal == decimal)
			break ;
		tmp = tmp->next;
		rotate++;
	}
	reverse_rotate = rotate - number_of_nodes(node);
	if (rotate > ft_abs(reverse_rotate))
		return (reverse_rotate);
	else
		return (rotate);
}

int	find_adjacent_larger_number(t_buffer **node_a, int decimal)
{
	t_buffer	*tmp;
	int			max_decimal;

	tmp = *node_a;
	max_decimal = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->decimal > decimal && tmp->decimal < max_decimal)
			max_decimal = tmp->decimal;
		tmp = tmp->next;
	}
	return (max_decimal);
}

void	number_of_rotate_before_stack_a(t_buffer **node_a, t_buffer **node_b)
{
	t_buffer	*tmp;

	tmp = *node_b;
	while (tmp != NULL)
	{
		tmp->flag = ft_abs(number_of_rotate(node_b, tmp->decimal));
		tmp->flag += ft_abs(number_of_rotate(node_a,
					find_adjacent_larger_number(node_a, tmp->decimal)));
		tmp = tmp->next;
	}
}

int	find_the_minimum_number(t_buffer **node_b)
{
	t_buffer	*tmp;
	int			min_flag;
	int			min_decimal;

	min_flag = INT_MAX;
	tmp = *node_b;
	while (tmp != NULL)
	{
		if (tmp->flag < min_flag)
		{
			min_flag = tmp->flag;
			min_decimal = tmp->decimal;
		}
		tmp = tmp->next;
	}
	return (min_decimal);
}

void	sort_big_stack(t_buffer **node_a, t_buffer **node_b)
{
	int	rotate_stack_a;
	int	rotate_stack_b;

	push_b(node_a, node_b);
	while (number_of_nodes(node_b))
	{
		number_of_rotate_before_stack_a(node_a, node_b);
		rotate_stack_a = number_of_rotate(node_a,
				find_adjacent_larger_number(node_a,
					find_the_minimum_number(node_b)));
		rotate_stack_b = number_of_rotate(node_b,
				find_the_minimum_number(node_b));
		rotate_stacks(node_a, node_b, rotate_stack_a, rotate_stack_b);
		pa(node_a, node_b);
	}
	rotate_stacks(node_a, node_b,
		number_of_rotate(node_a,
			search_for_a_number_by_index(node_a, 0)), 0);
}

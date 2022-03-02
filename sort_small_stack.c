/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:03 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 19:35:56 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sorting_two_numbers(t_buffer **node)
{
	if ((*node)->decimal > (*node)->next->decimal)
		sa(node);
}

void	sorting_three_numbers(t_buffer **node)
{
	while (sort_checking(node))
	{
		if ((*node)->index == 1
			&& (*node)->next->index == 2)
			rra(node);
		else if ((*node)->index == 2
			&& (*node)->next->index == 0)
			ra(node);
		else
			sa(node);
	}
}

void	sorting_four_numbers(t_buffer **node_a, t_buffer **node_b)
{
	int	max;

	max = number_of_nodes(node_a) - 1;
	while (number_of_nodes(node_b) != 1)
	{
		if ((*node_a)->index == max)
			pb(node_b, node_a);
		else if ((*node_a)->next->index == max)
			sa(node_a);
		else
			rra(node_a);
	}
	sorting_three_numbers(node_a);
	pa(node_a, node_b);
	ra(node_a);
}

void	sorting_five_numbers(t_buffer **node_a, t_buffer **node_b)
{
	int	max;

	max = number_of_nodes(node_a) - 1;
	while (number_of_nodes(node_b) != 2)
	{
		if ((*node_a)->index == max
			|| (*node_a)->index == max - 1)
			pb(node_b, node_a);
		else if ((*node_a)->next->index == max
			|| (*node_a)->next->index == max - 1)
			sa(node_a);
		else
			rra(node_a);
	}
	if ((*node_a)->index > (*node_a)->next->index
		&& (*node_b)->index > (*node_b)->next->index)
		ss(node_a, node_b);
	if ((*node_b)->index > (*node_b)->next->index)
		sb(node_b);
	sorting_three_numbers(node_a);
	pa(node_a, node_b);
	ra(node_a);
	pa(node_a, node_b);
	ra(node_a);
}

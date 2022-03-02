/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_push_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:45:56 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 14:52:21 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	middle_push(t_buffer **node_a, t_buffer **node_b)
{
	int	i;
	int	rotate;

	i = 0;
	rotate = number_of_rotate(node_a,
			search_for_a_number_by_index(node_a, middle_index(node_a)));
	if (rotate > 0)
	{
		while (i++ < rotate)
			ra(node_a);
	}
	else
	{
		while (i-- > rotate)
			rra(node_a);
	}
	pb(node_b, node_a);
}

void	push_b(t_buffer **node_a, t_buffer **node_b)
{
	int			max_decimal;
	int			min_decimal;
	int			middle_decimal;

	min_decimal = search_for_a_number_by_index(node_a, 0);
	max_decimal = search_for_a_number_by_index(node_a,
			number_of_nodes(node_a) - 1);
	middle_push(node_a, node_b);
	middle_decimal = (*node_b)->decimal;
	while (number_of_nodes(node_a) > 2)
	{
		if ((*node_a)->decimal != min_decimal
			&& (*node_a)->decimal != max_decimal)
		{
			pb(node_b, node_a);
			if ((*node_b)->decimal > middle_decimal)
				rb(node_b);
		}
		else
			ra(node_a);
	}
}

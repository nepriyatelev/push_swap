/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:00:06 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 15:00:16 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_a(t_buffer **node_a, int rotate_a)
{
	while (rotate_a != 0)
	{
		if (rotate_a > 0)
		{
			ra(node_a);
			rotate_a--;
		}
		else
		{
			rra(node_a);
			rotate_a++;
		}
	}
}

static void	rotate_stack_b(t_buffer **node_b, int rotate_b)
{
	while (rotate_b != 0)
	{
		if (rotate_b > 0)
		{
			rb(node_b);
			rotate_b--;
		}
		else
		{
			rrb(node_b);
			rotate_b++;
		}
	}
}

void	rotate_stacks(t_buffer **node_a,
		t_buffer **node_b, int rotate_a, int rotate_b)
{
	while (rotate_a > 0 && rotate_b > 0)
	{
		rr(node_a, node_b);
		rotate_a--;
		rotate_b--;
	}
	while (rotate_a < 0 && rotate_b < 0)
	{
		rrr(node_a, node_b);
		rotate_a++;
		rotate_b++;
	}
	rotate_stack_a(node_a, rotate_a);
	rotate_stack_b(node_b, rotate_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:32:28 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/23 20:43:00 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operation_reverse_rotate(t_buffer **node)
{
	t_buffer	*tmp;
	t_buffer	*end;

	if (*node && (*node)->next)
	{
		end = *node;
		while (end != NULL)
		{
			if (end->next->next == NULL)
			{
				tmp = end->next;
				end->next = NULL;
			}
			end = end->next;
		}
		tmp->next = *node;
		*node = tmp;
	}
}

void	rra(t_buffer **node)
{
	operation_reverse_rotate(node);
	write(1, "rra\n", 4);
}

void	rrb(t_buffer **node)
{
	operation_reverse_rotate(node);
	write(1, "rrb\n", 4);
}

void	rrr(t_buffer **node_a, t_buffer **node_b)
{
	if ((*node_a && (*node_a)->next)
		&& (*node_b && (*node_b)->next))
	{
		operation_reverse_rotate(node_a);
		operation_reverse_rotate(node_b);
		write(1, "rrr\n", 4);
	}
}

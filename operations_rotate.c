/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:13:18 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/23 20:43:48 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operation_rotate(t_buffer **node)
{
	t_buffer	*head;
	t_buffer	*end;

	if (*node && (*node)->next)
	{
		end = *node;
		head = (*node)->next;
		while (end->next != NULL)
			end = end->next;
		end->next = *node;
		end->next->next = NULL;
		*node = head;
	}
}

void	ra(t_buffer **node)
{
	operation_rotate(node);
	write(1, "ra\n", 3);
}

void	rb(t_buffer **node)
{
	operation_rotate(node);
	write(1, "rb\n", 3);
}

void	rr(t_buffer **node_a, t_buffer **node_b)
{
	if ((*node_a && (*node_a)->next)
		&& (*node_b && (*node_b)->next))
	{
		operation_rotate(node_a);
		operation_rotate(node_b);
		write(1, "rr\n", 3);
	}
}

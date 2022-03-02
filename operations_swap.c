/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:57:24 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/23 20:44:02 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	operation_swap(t_buffer **node)
{
	t_buffer	*tmp;

	if (*node && (*node)->next)
	{
		tmp = (*node)->next;
		(*node)->next = (*node)->next->next;
		tmp->next = *node;
		*node = tmp;
	}
}

void	sa(t_buffer **node)
{
	operation_swap(node);
	write(1, "sa\n", 3);
}

void	sb(t_buffer **node)
{
	operation_swap(node);
	write(1, "sb\n", 3);
}

void	ss(t_buffer **node_a, t_buffer **node_b)
{
	if ((*node_a && (*node_a)->next)
		&& (*node_b && (*node_b)->next))
	{
		operation_swap(node_a);
		operation_swap(node_b);
		write(1, "ss\n", 3);
	}
}

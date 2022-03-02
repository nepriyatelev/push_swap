/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:46:46 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/23 20:42:31 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_buffer **node_a, t_buffer **node_b)
{
	t_buffer	*tmp;

	if (*node_b != NULL)
	{
		tmp = *node_b;
		*node_b = (*node_b)->next;
		tmp->next = *node_a;
		*node_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_buffer **node_b, t_buffer **node_a)
{
	t_buffer	*tmp;

	if (*node_a != NULL)
	{
		tmp = *node_a;
		*node_a = (*node_a)->next;
		tmp->next = *node_b;
		*node_b = tmp;
	}
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:40:28 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 19:32:42 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checking(t_buffer **node)
{
	t_buffer	*tmp;

	tmp = *node;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	replay_checking(t_buffer **node)
{
	t_buffer	*tmp;
	t_buffer	*step;
	int			result;

	tmp = *node;
	while (tmp != NULL)
	{
		result = 0;
		step = *node;
		while (step != NULL)
		{
			if (tmp->decimal == step->decimal)
				result++;
			step = step->next;
		}
		tmp = tmp->next;
	}
	if (result != 1)
	{
		write(1, "Enter numbers without repetitions\n", 35);
		exit(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:47:35 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 18:52:16 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_buffer	*create_node(char **set_decimal, int argc)
{
	t_buffer	*node;
	t_buffer	*tmp;
	int			i;

	i = 2;
	node = (t_buffer *)malloc(sizeof(t_buffer));
	tmp = node;
	node->decimal = ft_atoi(set_decimal[1]);
	node->index = -1;
	node->flag = 0;
	node->next = NULL;
	while (argc > 2)
	{
		node->next = (t_buffer *)malloc(sizeof(t_buffer));
		node = node->next;
		node->decimal = ft_atoi(set_decimal[i++]);
		node->index = -1;
		node->flag = 0;
		node->next = NULL;
		argc--;
	}
	return (tmp);
}

int	number_of_nodes(t_buffer **node)
{
	int			i;
	t_buffer	*tmp;

	i = 0;
	tmp = *node;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sorting_by_indices(t_buffer **node)
{
	long		min_value;
	int			i;
	int			len_node;
	t_buffer	*tmp;
	t_buffer	*min_node;

	i = 0;
	len_node = number_of_nodes(node);
	while (i < len_node)
	{
		tmp = *node;
		min_value = LONG_MAX;
		while (tmp != NULL)
		{
			if (tmp->decimal < min_value && tmp->index == -1)
			{
				min_node = tmp;
				min_value = tmp->decimal;
			}
			tmp = tmp->next;
		}
		min_node->index = i++;
	}
}

int	middle_index(t_buffer **node)
{
	int	result;

	result = (number_of_nodes(node) - 1) / 2 + 1;
	return (result);
}

int	search_for_a_number_by_index(t_buffer **node, int index)
{
	t_buffer	*tmp;

	tmp = *node;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp->decimal);
		tmp = tmp->next;
	}
	return (0);
}

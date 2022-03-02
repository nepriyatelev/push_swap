/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:28:21 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/25 17:57:41 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_argc(t_buffer **node_a, t_buffer **node_b, int argc)
{
	sorting_by_indices(node_a);
	sort_checking(node_a);
	if (!(sort_checking(node_a)))
	{
		write(1, "Nothing to sort\n", 17);
		exit (0);
	}
	replay_checking(node_a);
	if (argc == 3)
		sorting_two_numbers(node_a);
	else if (argc == 4)
		sorting_three_numbers(node_a);
	else if (argc == 5)
		sorting_four_numbers(node_a, node_b);
	else if (argc == 6)
		sorting_five_numbers(node_a, node_b);
	else
		sort_big_stack(node_a, node_b);
}

int	main(int argc, char **argv)
{
	t_buffer	*a;
	t_buffer	*b;
	t_buffer	*tmp;

	a = NULL;
	b = NULL;
	if (argc == 2)
		return (write(1, "Nothing to sort\n", 17));
	if (argc >= 3)
	{
		a = create_node(argv, argc);
		check_argc(&a, &b, argc);
	}
	else
		return (write(1, "Enter numbers\n", 15));
	tmp = a;
	while (tmp)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	a = NULL;
	return (0);
}

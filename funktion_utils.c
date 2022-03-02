/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funktion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:39:59 by modysseu          #+#    #+#             */
/*   Updated: 2021/12/24 18:48:57 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_for_numbers(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		if (str[i] == 45 || str[i] == 43)
		{
			i++;
		}
		else if (!(str[i] >= 48 && str[i] <= 57))
		{
			write(1, "Enter only numbers\n", 20);
			exit(0);
		}
		i++;
	}
}

static void	check_integer(long long int decimal)
{
	if (decimal > INT_MAX || decimal < INT_MIN)
	{
		write(1, "Enter numbers from -2147483648 to 2147483647\n", 52);
		exit(0);
	}
}

int	ft_atoi(const char *str)
{
	long long int	result;
	int				sign;
	size_t			i;

	i = 0;
	sign = 1;
	result = 0;
	check_for_numbers(str);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{	
		result = (result * 10) + (str[i++] - 48);
	}
	check_integer(result * sign);
	return (result * sign);
}

int	ft_abs(int decimal)
{
	if (decimal < 0)
		return (-decimal);
	return (decimal);
}

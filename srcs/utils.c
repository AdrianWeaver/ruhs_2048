/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:55:51 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 13:53:41 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_2048.h"

int	is_power_2(int n)
{
	if (n <= 0)
		return (FALSE);
	while (n > 1)
	{
		if (n % 2 == 1)
			return (FALSE);
		n = n / 2;
	}
	return (TRUE);
}

int	get_random(void)
{
	int	i;
	time_t	t;

	srand((unsigned)time(&t));
	i = rand() % 100;
	if (i < 80)
		return (2);
	return (4);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

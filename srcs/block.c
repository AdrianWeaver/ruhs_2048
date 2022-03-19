/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:42:25 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 12:02:05 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

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

void	new_block(t_block *plate, int size)
{
	int	i;
	
	srand((unsigned)time(NULL));
	i = rand() % (size * size);
	while (plate[i].number != HOLLOW)
		i = rand() % (size * size);
	plate[i].number = get_random();
}

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

int	winning(t_block *plate, int size)
{
	int	i;

	i = 0;
	if (WIN_VALUE <= 0 && !(is_power_2(WIN_VALUE)))
		return (FALSE);
	while (i < (size * size))
	{
		if (plate[i].number == WIN_VALUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_block	*initialisation(int size)	
{
	t_block *res;
	int	i;
	int	n;

	res = (t_block *)malloc(sizeof(t_block) * (size * size));
	n = (size * size);
	i = 0;
	while (i < n)
	{
		res[i].number = HOLLOW;
		res[i].fusion = FALSE;
		i++;
	}
	new_block(res, size);
	new_block(res, size);
	return (res);
}

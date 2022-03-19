/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:56:28 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 13:30:09 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_2048.h"

void	right(t_block *plate, int size)
{
	int	i;
	int	n;

	i = 0;
	n = (size * size) - size;
	while (i < n)
	{
		p
		i++;	
	}
}

void	left(t_block *plate, int size)
{
	int	i;
	int	j;
	int	temp;
	int	n;

	i = 1;
	n = (size * size) - size;
	while (i < n)
	{
		j = i;
		while (i % size != 0)
		{
			if (plate[i - 1].number == HOLLOW)
				swap(&(plate[i - 1].number), &(plate[i].number));
			else if (!fusion(&(plate[i - 1]), &(plate[i])))
				break;
			i--;
		}
		i = j;
		i++;
		if (i % size == 0)
			i++;
	}
}

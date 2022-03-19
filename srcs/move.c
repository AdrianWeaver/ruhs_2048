/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:56:28 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 16:42:48 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_2048.h"

int	movemenent(int direction, t_block *plate, int size, int win)
{
	int	res;

	if (direction == KEY_RIGHT)
		right(plate, size);
	else if (direction == KEY_LEFT)
		left(plate, size);	
	else if (direction == KEY_UP)
		up(plate, size);
	else if (direction == KEY_DOWN)
		down(plate, size);
	else
		return (0);
	if (win == 0)
	{
		res = winning(plate, size);
		if (res != 0)
			return (res);
	}
	res = lose(plate, size);
	if (res == 0)
		return (2);
	return (0);
}


void	right(t_block *plate, int size)
{
	int	i;
	int	puissance;
	int	j;
	int	n;

	puissance = size;
	i = puissance - 1;
	n = (size * size);
	while (i < n)
	{
		j = i;
		while ((i + 1) % size != 0)
		{
			if (plate[i + 1].number == HOLLOW)
				swap(&(plate[i + 1].number), &(plate[i].number));
			else if (!fusion(&(plate[i + 1]), &(plate[i])))
				break;
			i++;
		}
		i = j;
		if (i % size == 0)
		{
			puissance += size;
			i = puissance;
		}
		i--;
	}
}

void	left(t_block *plate, int size)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	n = (size * size);
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
	}
}

void	up(t_block *plate, int size)
{
	int	i;
	int	compteur;
	int	j;
	int	n;

	n = (size * size);
	compteur = 0;
	i = 0;
	while (compteur < size)
	{
		j = i;
		while (i >= size)
		{
			if (plate[i - size].number == HOLLOW)
				swap(&(plate[i - size].number), &(plate[i].number));
			else if (!fusion(&(plate[i - size]), &(plate[i])))
				break;
			i -= size;
		}
		i = j;
		i += size;
		if (i >= n)
		{
			compteur++;
			i = compteur;
		}
	}
}

void	down(t_block *plate, int size)
{	
	int	i;
	int	compteur;
	int	j;
	int	n;

	n = (size * size);
	compteur = 0;
	i = n - size;
	while (i < n)
	{
		j = i;
		while ((i + size) < n)
		{
			if (plate[i + size].number == HOLLOW)
				swap(&(plate[i + size].number), &(plate[i].number));
			else if (!fusion(&(plate[i + size]), &(plate[i])))
				break;
			i += size;
		}
		i = j;
		i -= size;
		if (i < 0)
		{
			compteur++;
			i = n - size + compteur;
		}
	}
}

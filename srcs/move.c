/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:56:28 by douattar          #+#    #+#             */
/*   Updated: 2022/03/20 10:37:55 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_2048.h"

int	movement(int direction, t_block *plate, int size, int win, int *score)
{
	int	res;

	res = 0;
	if (direction == KEY_RIGHT)
		res = right(plate, size, score);
	else if (direction == KEY_LEFT)
		res = left(plate, size, score);
	else if (direction == KEY_UP)
		res = up(plate, size, score);	
	else if (direction == KEY_DOWN)
		res = down(plate, size, score);
	else
		return (0);
	if (reset(plate, size) == 3)
		return (3);
	if (res == 0)
		return (0);
	new_block(plate, size, res);	
	if (win == 0 && winning(plate, size) == 1)
		return (1);
	return (lose(plate, size));
}


int	down(t_block *plate, int size, int *score)
{
	int	i;
	int	puissance;
	int	j;
	int	n;
	int	res;

	res = 0;
	puissance = size;
	i = puissance - 1;
	n = (size * size);
	while (i < n)
	{
		j = i;
		while ((i + 1) % size != 0 && plate[i].number != HOLLOW)
		{
			if (plate[i + 1].number == HOLLOW)
			{
				swap(&(plate[i + 1].number), &(plate[i].number));
				swap(&(plate[i + 1].fusion), &(plate[i].fusion));
			}
			else if (fusion(&(plate[i + 1]), &(plate[i])))
			{
				*score += plate[i + 1].number;
				res++;
			}
			else
				break;
			res++;
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
	return (res);
}

int	up(t_block *plate, int size, int *score)
{
	int	i;
	int	j;
	int	n;
	int	res;

	res = 0;
	i = 1;
	n = (size * size);
	while (i < n)
	{
		j = i;
		while (i % size != 0 && plate[i].number != 0)
		{
			if (plate[i - 1].number == HOLLOW)
			{
				swap(&(plate[i - 1].number), &(plate[i].number));
				swap(&(plate[i - 1].fusion), &(plate[i].fusion));
			}
			else if (fusion(&(plate[i - 1]), &(plate[i])))
			{
				*score += plate[i - 1].number;
				res++;
			}
			else
				break;
			res++;
			i--;
		}
		i = j;
		i++;
	}
	return (res);
}

int	left(t_block *plate, int size, int *score)
{
	int	i;
	int	compteur;
	int	j;
	int	n;
	int	res;

	res = 0;
	n = (size * size);
	compteur = 0;
	i = 0;
	while (compteur < size)
	{
		j = i;
		while (i >= size && plate[i].number != HOLLOW)
		{
			if (plate[i - size].number == HOLLOW)
			{
				swap(&(plate[i - size].number), &(plate[i].number));
				swap(&(plate[i - size].fusion), &(plate[i].fusion));
			}
			else if (fusion(&(plate[i - size]), &(plate[i])))
			{
				*score += plate[i - size].number;
				res++;
			}
			else
				break;
			res++;
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
	return (res);
}

int	right(t_block *plate, int size, int *score)
{	
	int	i;
	int	compteur;
	int	j;
	int	n;
	int	res;

	res = 0;
	n = (size * size);
	compteur = 0;
	i = n - size;
	while (i < n)
	{
		j = i;
		while (i + size < n && plate[i].number != HOLLOW)
		{
			if (plate[i + size].number == HOLLOW)
			{
				swap(&(plate[i + size].number), &(plate[i].number));
				swap(&(plate[i + size].fusion), &(plate[i].fusion));
			}
			else if (fusion(&(plate[i + size]), &(plate[i])))
			{
				*score += plate[i + size].number;
				res++;
			}
			else
				break;
			res++;
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
	return (res);
}

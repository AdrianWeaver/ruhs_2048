/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:42:25 by douattar          #+#    #+#             */
/*   Updated: 2022/03/20 10:33:25 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	new_block(t_block *plate, int size, unsigned int key)
{
	int	i;
	
	srand(key);
	i = rand() % (size * size);
	while (plate[i].number != HOLLOW)
		i = rand() % (size * size);
	plate[i].number = get_random();
}

int	fusion(t_block *a, t_block *b)
{
	if (a->number != b->number)
		return (FALSE);
	if (a->fusion || b->fusion)
		return (FALSE);
	a->number *= 2;	
	a->fusion = TRUE;
	b->number = HOLLOW;
	b->fusion = FALSE;
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

t_block	*copy(t_block *original, int size)
{
	t_block	*new;
	int	i;

	new = (t_block *)malloc(sizeof(t_block) * (size * size));
	if (new == NULL)
		return (t_block *)(NULL);
	i = 0;
	while (i < (size * size))
	{
		new[i].number = original[i].number;
		new[i].fusion = FALSE;
		i++;
	}
	return (new);
}

// Return true les 2 listes sont identiques
int	compare(t_block *original, t_block *copy, int size)
{
	int	i;

	i = 0;
	while (i < size)	
	{
		if (copy[i].number != original[i].number || copy[i].fusion || original[i].fusion)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	reset(t_block *plate, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		plate[i].fusion = FALSE;
		if (plate[i].number == 2048)
			return (3);
		i++;
	}
	return (0);
}

int	lose(t_block *plate, int size)
{
	t_block *temp;

	temp = copy(plate, size);
	if (temp == NULL)
		return (2);
	right(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (0);
	}
	reset(temp, size);
	left(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (0);
	}
	reset(temp, size);
	up(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (0);
	}
	reset(temp, size);
	down(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (0);
	}
	reset(temp, size);
	free(temp);
	return (2);
}

t_block	*initialisation(int size)	
{
	t_block *res;
	int	i;
	int	n;

	res = (t_block *)malloc(sizeof(t_block) * (size * size));
	if (res == NULL)
		return (t_block *)(NULL);
	n = (size * size);
	i = 0;
	while (i < n)
	{
		res[i].number = HOLLOW;
		res[i].fusion = FALSE;
		i++;
	}
	new_block(res, size, time(NULL));
	new_block(res, size, size * size);
	return (res);
}

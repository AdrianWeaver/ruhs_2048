/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:42:25 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 20:39:53 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	new_block(t_block *plate, int size)
{
	int	i;
	
	srand((unsigned)time(NULL));
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
		if (copy[i].number != original[i].number || original[i].fusion)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	lose(t_block *plate, int size)
{
	t_block *temp;

	temp = copy(plate, size);
	if (temp == NULL)
		return (1);
	right(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (1);
	}
	left(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (1);
	}
	up(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (1);
	}
	down(temp, size);
	if (!compare(plate, temp, size))
	{
		free(temp);
		return (1);
	}
	return (0);
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
	new_block(res, size);
	new_block(res, size);
	return (res);
}

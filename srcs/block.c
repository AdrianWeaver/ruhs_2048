/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:42:25 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 13:35:37 by douattar         ###   ########.fr       */
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
	if (a->fusion == TRUE)
		return (FALSE);
	a->number *= 2;	
	a->fusion = TRUE;
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
	i = 0;
	while (i < (size * size))
	{
		new[i].number = original[i].number;
		new[i].fusion = FALSE;
		i++;
	}
	return (new);
}

int	lose(t_block *plate, int size)
{
	t_block *temp;

	temp = copy(plate, size);
	free(temp);
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

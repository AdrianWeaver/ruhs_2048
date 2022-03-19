/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:26:50 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 11:38:32 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_2048.h"

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

int	fusion(t_block *old, t_block *fuse)
{
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


int	main(void)
{
	t_block *plateau;
	int	i;
	int	n;

	plateau = initialisation(4);
	return (0);
}

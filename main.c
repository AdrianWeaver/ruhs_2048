/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:26:50 by douattar          #+#    #+#             */
/*   Updated: 2022/03/19 10:46:28 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_2048.h"

int	get_random(void)
{
	int	i;

	srand((unsigned)time(NULL));
	i = rand() % 100;
	if (i < 70)
		return (2);
	return (4);
}

int	main(void)
{
	printf("%d\n", get_random());
	return (0);
}

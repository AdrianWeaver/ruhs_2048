/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:22:12 by douattar          #+#    #+#             */
/*   Updated: 2022/03/20 14:39:32 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int	get_score(void)
{
	FILE	*fd;
	int	res;

	fd = fopen("score.txt", "r+");
	if (fd == NULL)
		return (0);
	fscanf(fd, "%d", &res);
	fclose(fd);
	return (res);
}

int	new_score(int best);
{
	FILE	*fd;
	char	*str;

	fd = fopen("score.txt", "w");
	if (fd == NULL)
		return (1);
	str = ft_itoa(best);
	fwrite(str, 1, sizeof(str), fd);
	fclose(fd);
	free(str);
	return (0);
}

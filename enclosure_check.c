/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enclosure_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:47:26 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/27 13:56:20 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_enclosure(t_game *game)
{
	if (enclosure_x(game) == -1 || enclosure_y(game) == -1)
		return (-1);
	else
		return (0);
}

int	enclosure_x(t_game *game)
{
	int	j;
	int	y;

	j = 0;
	y = game->y - 1;
	while (game->map[0][j] != '\0')
	{
		if (game->map[0][j] != '1' && game->map[0][j] != '\n')
			return (-1);
		j++;
	}
	j = 0;
	while (game->map[y][j] != '\0')
	{
		if (game->map[y][j] != '1' && game->map[y][j] != '\n')
			return (-1);
		j++;
	}
	return (0);
}

int	enclosure_y(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	x = game->x - 1;
	while (i < game->y)
	{
		if (game->map[i][0] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < game->y)
	{
		if (game->map[i][x] != '1')
			return (-1);
		i++;
	}
	return (0);
}

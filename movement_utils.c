/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:46:25 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/27 13:53:43 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_collectible(t_game *game, char c)
{
	int	y;
	int	x;

	y = game->py;
	x = game->px;
	if (c == 'w')
	{
		if (game->map[y - 1][x] == 'C')
			update(game, x, y - 1);
	}
	if (c == 'a')
	{
		if (game->map[y][x - 1] == 'C')
			update(game, x - 1, y);
	}
	if (c == 's')
	{
		if (game->map[y + 1][x] == 'C')
			update(game, x, y + 1);
	}
	if (c == 'd')
	{
		if (game->map[y][x + 1] == 'C')
			update(game, x + 1, y);
	}
}

void	check_win(t_game *game)
{
	if (game->nbrcollect == game->collected)
	{
		printf("steps taken: %i\n", game->steps + 1);
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
}

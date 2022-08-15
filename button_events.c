/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:16:19 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/28 11:36:49 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_esc(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	event_w(t_game *game)
{
	if (game->map[game->py - 1][game->px] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->px * 64, (game->py - 1) * 64);
		if (game->map[game->py - 1][game->px] == 'E')
			check_win(game);
		if (game->map[game->py][game->px] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->px * 64, game->py * 64);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->px * 64, game->py * 64);
		}
		check_for_collectible(game, 'w');
		game->py = game->py - 1;
		game->steps++;
		printf("steps taken: %i\n", game->steps);
	}
}

void	event_a(t_game *game)
{
	if (game->map[game->py][game->px - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			(game->px - 1) * 64, game->py * 64);
		if (game->map[game->py][game->px - 1] == 'E')
			check_win(game);
		if (game->map[game->py][game->px] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->px * 64, game->py * 64);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->px * 64, game->py * 64);
		}
		check_for_collectible(game, 'a');
		game->px = game->px - 1;
		game->steps++;
		printf("steps taken: %i\n", game->steps);
	}
}

void	event_s(t_game *game)
{
	if (game->map[game->py + 1][game->px] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->px * 64, (game->py + 1) * 64);
		if (game->map[game->py + 1][game->px] == 'E')
			check_win(game);
		if (game->map[game->py][game->px] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->px * 64, game->py * 64);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->px * 64, game->py * 64);
		}
		check_for_collectible(game, 's');
		game->py = game->py + 1;
		game->steps++;
		printf("steps taken: %i\n", game->steps);
	}
}

void	event_d(t_game *game)
{
	if (game->map[game->py][game->px + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			(game->px + 1) * 64, game->py * 64);
		if (game->map[game->py][game->px + 1] == 'E')
			check_win(game);
		if (game->map[game->py][game->px] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->px * 64, game->py * 64);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->px * 64, game->py * 64);
		}
		check_for_collectible(game, 'd');
		game->px = game->px + 1;
		game->steps++;
		printf("steps taken: %i\n", game->steps);
	}
}

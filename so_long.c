/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:13:37 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/18 13:31:16 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j] != 'P')
	{
		if (game->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else if (game->map[i][0] != '\n')
			j++;
	}
	game->px = j;
	game->py = i;
}

void	initiate_game(t_game *game, char **argv)
{
	int	wid;
	int	hght;

	wid = 64;
	hght = 64;
	game->mlx = mlx_init();
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&wid, &hght);
	game->player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm",
			&wid, &hght);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm",
			&wid, &hght);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm",
			&wid, &hght);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./sprites/collect.xpm",
			&wid, &hght);
	read_map(game, argv);
}

int	button_event(int keycode, t_game *game)
{
	if (keycode == 53)
		event_esc(game);
	if (keycode == 13)
		event_w(game);
	if (keycode == 0)
		event_a(game);
	if (keycode == 1)
		event_s(game);
	if (keycode == 2)
		event_d(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	initiate_game(&game, argv);
	check_valid_map(&game);
	get_player_position(&game);
	game.win = mlx_new_window(game.mlx, (game.x * 64),
			(game.y * 64), "so_long");
	paint_map(&game);
	mlx_hook(game.win, 2, (1L << 0), button_event, &game);
	mlx_hook(game.win, 17, (1L << 17), exit_game, &game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}

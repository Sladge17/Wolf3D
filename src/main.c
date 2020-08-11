/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <vkaron@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:24:16 by vkaron            #+#    #+#             */
/*   Updated: 2020/07/27 18:20:52 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		main_selector(t_game *game)
{
	while (game->status > 0) {
		if (game->status == 1)
		{
			load_music(game);
			sdl_cycle(game);
		}
		else if (game->status == 2)
			map_editor(game);
		else if (game->status == 3)
			game->status = 0;
	}
}

int			main(int ac, char *av[])
{
	t_game		*game;
	int			cheat;
	int			status;

	status = 1;
	if (ac == 2) {
		cheat = ft_strcmp(av[1], "cheat");
		//printf("cheat = %d\n", cheat);
		if (!ft_strcmp(av[1], "editor"))
			status = 2;
	}
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		ft_exit("Failed to alloc t_game");
	
	init_player(game);
	load_map(&(game->level), &(game->player));
	if (!init_sdl(game))
		return (free_init_sdl(game));
	game->status = status;
	main_selector(game);
	close_sdl(game);
	return (0);
}



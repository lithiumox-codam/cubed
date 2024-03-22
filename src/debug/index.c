/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 13:32:43 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/22 13:41:36 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Prints the array to the terminal
 *
 * @param data The main struct
 */
void	print_array(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x] == WALL)
				printf("🟥");
			else if (data->map.array[y][x] == FLOOR)
				printf("⬜️");
			else if (data->map.array[y][x] == PLAYER)
				printf("👶");
			else if (data->map.array[y][x] == EMPTY)
				printf("⬛️");
			else if (data->map.array[y][x] == CLOSED_DOOR)
				printf("🚪");
			x++;
		}
		printf("\n");
		y++;
	}
}

static int	shift(int num, int shift)
{
	return ((num >> shift) & 0xFF);
}

static void	print_floor_and_ceiling(t_textures *t)
{
	int	r;
	int	g;
	int	b;

	r = shift(t->floor, 24);
	g = shift(t->floor, 16);
	b = shift(t->floor, 8);
	printf("  \033[1;33mfloor:\033[0m ");
	printf("\033[48;2;%d;%d;%dm  \033[0m\n", r, g, b);
	r = shift(t->ceiling, 24);
	g = shift(t->ceiling, 16);
	b = shift(t->ceiling, 8);
	printf("  \033[1;33mceiling:\033[0m ");
	printf("\033[48;2;%d;%d;%dm  \033[0m\n\n", r, g, b);
}

void	debug_bonus(t_data *data)
{
	t_textures	*textures;

	textures = &data->textures;
	printf("\n");
	printf("\033[1;36mDoor textures:\033[0m\n");
	printf("  \033[1;33mClosed:\033[0m %p\n", textures->door_closed.north);
	printf("  \033[1;33mOpen:\033[0m %p\n", textures->door_open.north);
	printf("\n");
	printf("\033[1;36mSprite:\033[0m\n");
	printf("  \033[1;33mCurrent:\033[0m %d\n", textures->sprite.current);
	printf("  \033[1;33mAmount:\033[0m %zu\n", textures->sprite.images.length);
	printf("\n");
}

void	print_data(t_data *data)
{
	if (!DEBUG)
		return ;
	printf("\n");
	printf("\033[1;36mMap:\033[0m\n");
	printf("  \033[1;33mwidth:\033[0m %d\n", data->map.width);
	printf("  \033[1;33mheight:\033[0m %d\n\n", data->map.height);
	printf("\033[1;36mTextures:\033[0m\n");
	printf("  \033[1;33mWall:\033[0m\n");
	printf("    \033[1;33mnorth:\033[0m %p\n", data->textures.wall.north);
	printf("    \033[1;33msouth:\033[0m %p\n", data->textures.wall.south);
	printf("    \033[1;33meast:\033[0m %p\n", data->textures.wall.east);
	printf("    \033[1;33mwest:\033[0m %p\n", data->textures.wall.west);
	print_floor_and_ceiling(&data->textures);
	printf("\033[1;36mPlayer:\033[0m\n");
	printf("  \033[1;33mx:\033[0m %f\n", data->player.x);
	printf("  \033[1;33my:\033[0m %f\n", data->player.y);
	printf("  \033[1;33mdir:\033[0m %f\n", data->player.dir);
	if (BONUS)
		debug_bonus(data);
}

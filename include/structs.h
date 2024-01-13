/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 19:33:48 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/13 17:32:14 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>

/**
 * @brief The different types of map elements
 *
 * EMPTY is used for the map array to indicate that the element is empty
 * FLOOR is used for the map array to indicate that the element is a floor
 * WALL is used for the map array to indicate that the element is a wall
 * PLAYER is used for the map array to indicate that the element is the player
 */
typedef enum e_map_types
{
	EMPTY = 0,
	FLOOR = 1,
	WALL = 2,
	PLAYER = 3,
}					t_map_types;

/**
 * @brief The struct that holds the map
 *
 * @param map The map array
 * @param width The width of the map
 * @param height The height of the map
 */
typedef struct s_map
{
	t_map_types		**array;
	int				width;
	int				height;
}					t_map;

/**
 * @brief The struct that holds the player's metadata.
 *
 * @param x The x position of the player
 * @param y The y position of the player
 * @param dir The direction the player is facing
 */
typedef struct s_player
{
	double			x;
	double			y;
	double			dir;
}					t_player;

/**
 * @brief The struct that holds the loaded textures
 * and the floor and ceiling colors.
 *
 * @param north The north texture
 * @param south The south texture
 * @param east The east texture
 * @param west The west texture
 * @param floor The floor color
 * @param ceiling The ceiling color
 */
typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				floor;
	int				ceiling;
}					t_textures;

/**
 * @brief The main data struct for the program.
 *
 * @param map The map struct containing the map array and its dimensions.
 * @param player The player struct containing the player's metadata.
 * @param strings The vector containing the strings read from the file.
 * @param textures The textures struct with the loaded textures.
 */
typedef struct s_data
{
	t_map			map;
	t_player		player;
	t_vector		strings;
	t_textures		textures;
}					t_data;

/**
 * @brief The struct that holds the function pointers for the different
 * elements in the map file. So the parser knows which function to call
 * when it encounters a certain element. This makes the order of the elements
 * in the map file irrelevant.
 */
typedef struct s_func
{
	char			*str;
	bool			(*func_ptr)(char *, t_data *);
}					t_func;

#endif

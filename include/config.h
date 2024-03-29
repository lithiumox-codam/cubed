/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 16:10:16 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/28 15:44:25 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <MLX42.h>

# define WIDTH 2060
# define HEIGHT 1440

# define ARGUMENTS "Invalid number of arguments"
# define INVALID_INFO "Invalid info type found: "
# define INVALID_DOOR "Door path provided does not contain: "
# define MAP_ERROR "Map is not correct!"
# define BONUS_ERROR "Bonus not enabled!"
# define MALLOC "Malloc failed"
# define DUPLICATE "Duplicate argument found!"
# define MISSING "Missing argument: "
# define MULTIPLE_PLAYER "Multiple players found!"
# define INVALID_CHAR_MAP "Invalid character in map: "
# define MAP_NOT_CLOSED "Map is not closed"
# define INVALID_COLOR "Invalid color: "
# define INVALID_PATH "Invalid path: "
# define NO_SPRITES "No sprites found in the path."
# define MLX_ERROR "MLX error: "
# define DOOR_NOT_CLOSED "Door is not supported by walls."
# define CUB_ERROR "Invalid file type use a .cub file instead."
# define FILE_ERROR "File does not exist or is not accessible."
# define PNG_ERROR "Invalid file type use a .png file instead of: "
# define NO_PLAYER "No player found in the map. You should add one :-)"

#endif

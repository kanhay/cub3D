# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 11:07:24 by iassafe           #+#    #+#              #
#    Updated: 2024/02/07 16:33:08 by khanhayf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = mandatory/cub3D.h
SRC = mandatory/main.c mandatory/get_next_line.c mandatory/utils.c \
	mandatory/libft.c mandatory/parsing.c mandatory/parsing_read.c \
	mandatory/parsing_ck_map.c mandatory/parsing_ck_cf.c \
	mandatory/parsing_ck_dir.c mandatory/parsing_utils.c \
	mandatory/updates.c mandatory/player.c mandatory/init.c \
	mandatory/draw_win.c mandatory/moves_init.c mandatory/exit.c \
	mandatory/intercept.c mandatory/init_var_raycast.c mandatory/wall_distance.c \
	mandatory/rendering_walls.c mandatory/parsing_utils1.c
OBJ = $(SRC:.c=.o)

BONUS = cub3D_bonus
HEADER_B = bonus/cub3D_bonus.h
SRC_B = bonus/main_bonus.c bonus/get_next_line_bonus.c bonus/utils_bonus.c \
	bonus/libft_bonus.c bonus/parsing_bonus.c bonus/parsing_read_bonus.c \
	bonus/parsing_ck_map_bonus.c bonus/parsing_ck_cf_bonus.c \
	bonus/parsing_ck_dir_bonus.c bonus/parsing_utils_bonus.c\
	bonus/updates_bonus.c bonus/player_bonus.c bonus/init_bonus.c \
	bonus/draw_player_bonus.c bonus/draw_win_bonus.c bonus/moves_init_bonus.c \
	bonus/exit_bonus.c bonus/intercept_bonus.c bonus/init_var_raycast_bonus.c \
	bonus/wall_distance_bonus.c bonus/rendering_walls_bonus.c bonus/door_bonus.c \
	bonus/file2img_bonus.c bonus/mouse_rotation_bonus.c
OBJ_B = $(SRC_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./mlx/
RM = rm -rf
MLX = ./mlx/libmlx.a


all : mk_mlx $(NAME) 

mk_mlx :
	make -C ./mlx 2>/dev/null

bonus : mk_mlx $(BONUS)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS) : $(OBJ_B) $(HEADER_B)
	$(CC) $(CFLAGS) $(MLX) $(OBJ_B) -framework OpenGL -framework AppKit -o $(BONUS)

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADER_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_B)
	make clean -C ./mlx

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all
re_bonus : fclean bonus
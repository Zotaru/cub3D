# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonier <amonier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 22:27:42 by amonier           #+#    #+#              #
#    Updated: 2023/12/28 17:20:42 by amonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

NAME_BONUS	= cub3D_bonus

DIR_SRCS	= srcs

DIR_BONUS	= srcs_bonus

DIR_OBJS	= obj

DIR_OBJS_B	= obj_bonus

SRCS_NAMES		=	\
	main.c				\
	my_mlx_pixel_put.c	\
	sprite_ges.c		\
	mlx/init.c					\
	mlx/destroy.c				\
	hook/all_hook.c					\
	hook/cross.c					\
	hook/keyboard.c					\
	hook/mouse_hook.c				\
	parsing/parsing.c						\
	parsing/parsing1.c						\
	parsing/parsing2.c						\
	parsing/free_double_tab_char.c			\
	parsing/use_file.c						\
	parsing/extract_map.c					\
	parsing/nb_line_double_tab.c			\
	parsing/free_t_pars.c					\
	parsing/new_map.c						\
	parsing/check_map.c						\
	parsing/ft_lst_wall_new.c				\
	parsing/ft_lst_wall_last.c				\
	parsing/ft_lst_wall_clear.c				\
	parsing/ft_lst_wall_addback.c			\
	parsing/create_wall_lst.c				\
	free_t_infos.c							\
	mini_map/create_mini_map.c						\
	mini_map/create_player_point.c					\
	mini_map/ft_lst_point_new.c						\
	mini_map/ft_lst_point_addback.c					\
	mini_map/ft_lst_point_clear.c					\
	mini_map/color_point_lst.c						\
	mini_map/ft_lst_point_last.c					\
	mini_map/draw_ray.c								\
	mini_map/rotate_ray.c							\
	mini_map/create_player_utils.c					\
	hook/mouv/verification_point.c								\
	hook/mouv/change_sprite.c									\
	hook/mouv/mouv.c											\
	utils/degree_to_radian.c												\
	utils/simplifying_obj.c													\
	utils/create_FOV_ray_tab.c												\
	raycasting/method_one.c															\
	raycasting/raycast.c															\
	raycasting/method_two.c															\
	raycasting/raycast_two.c														\
	raycasting/preselection_wall.c													\
	raycasting/preselection_sprite.c												\
	raycasting/raycast_bis.c														\
	raycasting/draw_ray_if.c														\
	raycasting/draw_ray_two.c															\
	raycasting/draw_sprite_bis.c														\
	parsing/texture_ges.c					\
	parsing/texture_ges1.c					\
	parsing/texture_ges2.c					\
	parsing/color_ges.c						\
	parsing/color_ges_bis.c					\
	parsing/sprite_mapping.c				\
	parsing/new_map_bis.c					\
	parsing/check_map_exit.c				\
	parsing/create_wall_bis.c				\
	utils/ft_lst_sprite.c										\
	raycasting/method_two_for_sprite.c												\
	raycasting/sprite.c																\
	


BONUS_SRCS_NAMES	=	\
	main.c				\
	my_mlx_pixel_put.c	\
	sprite_ges.c		\
	mlx/init.c					\
	mlx/destroy.c				\
	hook/all_hook.c					\
	hook/cross.c					\
	hook/keyboard.c					\
	hook/mouse_hook.c				\
	parsing/parsing.c						\
	parsing/parsing1.c						\
	parsing/parsing2.c						\
	parsing/free_double_tab_char.c			\
	parsing/use_file.c						\
	parsing/extract_map.c					\
	parsing/nb_line_double_tab.c			\
	parsing/free_t_pars.c					\
	parsing/new_map.c						\
	parsing/check_map.c						\
	parsing/ft_lst_wall_new.c				\
	parsing/ft_lst_wall_last.c				\
	parsing/ft_lst_wall_clear.c				\
	parsing/ft_lst_wall_addback.c			\
	parsing/create_wall_lst.c				\
	free_t_infos.c							\
	mini_map/create_mini_map.c						\
	mini_map/create_player_point.c					\
	mini_map/ft_lst_point_new.c						\
	mini_map/ft_lst_point_addback.c					\
	mini_map/ft_lst_point_clear.c					\
	mini_map/color_point_lst.c						\
	mini_map/ft_lst_point_last.c					\
	mini_map/draw_ray.c								\
	mini_map/rotate_ray.c							\
	mini_map/create_player_utils.c					\
	hook/mouv/verification_point.c								\
	hook/mouv/change_sprite.c									\
	hook/mouv/mouv.c											\
	utils/degree_to_radian.c												\
	utils/simplifying_obj.c													\
	utils/create_FOV_ray_tab.c												\
	raycasting/method_one.c															\
	raycasting/raycast.c															\
	raycasting/method_two.c															\
	raycasting/raycast_two.c														\
	raycasting/preselection_wall.c													\
	raycasting/preselection_sprite.c												\
	raycasting/raycast_bis.c														\
	raycasting/draw_ray_if.c														\
	raycasting/draw_ray_two.c															\
	raycasting/draw_sprite_bis.c														\
	parsing/texture_ges.c					\
	parsing/texture_ges1.c					\
	parsing/texture_ges2.c					\
	parsing/color_ges.c						\
	parsing/color_ges_bis.c					\
	parsing/sprite_mapping.c				\
	parsing/new_map_bis.c					\
	parsing/check_map_exit.c				\
	parsing/create_wall_bis.c				\
	utils/ft_lst_sprite.c										\
	raycasting/method_two_for_sprite.c												\
	raycasting/sprite.c																\

OBJS_NAMES	= ${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	= ${BONUS_SRCS_NAMES:.c=.o}

SRCS		= $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B		= $(addprefix $(DIR_BONUS)/,$(BONUS_SRCS_NAMES))

OBJS		= $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_BONUS	= $(addprefix $(DIR_OBJS_B)/,$(OBJS_NAMES_B))

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror 
CFLAGSBONUS	= -g3 -O2 -O3 -march=native -funroll-loops -ffast-math -fomit-frame-pointer
# CFLAGSBONUS	= -pthread
HEAD		= -IIncludes -Iminilibx-linux
MLX			= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

RM			= rm -f
# MAKEFLAGS	= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(MLX) -lXext -lX11 -lm -lz -o $(NAME)
	$(info CREATED $(NAME))
	@echo "\033[34;5mcub3D\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

bonus: all $(NAME_BONUS)
	
$(DIR_OBJS_B)/%.o: $(DIR_BONUS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CFLAGSBONUS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(CFLAGSBONUS) $(OBJS_BONUS) libft/libft.a $(MLX) -lXext -lX11 -lm -lz -o $(NAME_BONUS)
	$(info CREATED $(NAME_BONUS))
	@echo "\033[34;5mcub3D BONUS\033[0m"


clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:

##
## Makefile for scroller in /home/antoine.casse/Desktop/scroller
## 
## Made by Antoine Casse
## Login   <antoine.casse@epitech.net>
## 
## Started on  Sun Jan  1 19:43:23 2017 Antoine Casse
## Last update Thu Jun  1 15:15:54 2017 LAABID Zakaria

CC	=	gcc

SRC	=	src/main.c				\
		src/help.c				\
		src/loop.c				\
		src/tools.c				\
		src/grid.c				\
		src/colors.c				\
		src/frees.c				\
		src/actions.c				\
		src/mouse.c				\
		src/check_pos.c				\
		src/check_class.c			\
		src/show_player.c			\
		src/fill_player.c			\
		src/position.c				\
		src/hover_gesture.c			\
		src/show_tp.c				\
		src/aff_decor.c				\
		src/event_manager.c			\
		src/hover_button.c			\
		src/hover_second.c			\
		src/mouse_check.c			\
	   	src/get_texture.c			\
		src/bfs.c				\
		src/bfs_prep.c				\
		src/anim.c				\
		src/config/conf_manager.c		\
		src/config/conf_fill.c			\
		src/config/conf_gen.c			\
		src/config/conf_utils.c			\
		src/config/epur_str.c			\
		src/config/conf_map.c			\
		src/config/conf_teleports_utils.c	\
		src/config/conf_events_utils.c		\
		src/config/getconf.c			\
		src/config/check_file.c			\
		src/config/build_graph.c		\
		src/config/conf_verif.c			\
		src/config_map.c			\
		src/hud_modal.c				\
		src/quest_character.c			\
		src/game_sound.c			\
		src/decor_manager.c			\
		src/config/conf_isempty.c		\
		src/config/conf_map_verif.c		\
		src/config/conf_teleporter_verif.c	\
		src/config/conf_free.c			\
		src/config/conf_map_second.c		\
		src/config/conf_events.c		\
		src/config/conf_event_verif.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tekadventure

CFLAGS	+=	-Wextra -Wall -Werror -I./include -lm

LDFLAGS	+=	-L./lib/ -lkaas

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) -lc_graph_prog_full -lm -lc_graph_prog

clean:
	make clean -C ./lib/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ./lib/
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re

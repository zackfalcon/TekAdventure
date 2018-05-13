/*
** tekadv.h for  in /home/BlackBIrdz/tekadventure/include
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 23:25:52 2017 LAABID Zakaria
** Last update Sun May 28 23:26:04 2017 LAABID Zakaria
*/


#ifndef TEKADV_H
# define TEKADV_H

/*
** ***************************************************
**                     - INCLUDE -
** ***************************************************
*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include "config.h"

/*
** ***************************************************
**                     - MACRO -
** ***************************************************
*/
# define SUCCESS	(0)
# define NORMAL		(0)
# define FAIL		(-1)
# define ERROR		(84)
# define EOB		(-42)
# define S_TILE         (32)
# define SCR_H	        (663)
# define SCR_W		(1280)
# define STMENU_S	(4)

# define MENU		(0)
# define CHARAC		(1)
# define PLAY		(2)
# define MULTI		(3)
# define CLOSE		(4)
# define START		(5)
# define NEWS		(6)
# define OPTION		(7)
# define SHOP		(8)
# define FECA		(9)
# define IOP		(10)
# define ECA		(11)
# define OSA		(12)
# define S_FECA		(13)
# define S_ECA		(14)
# define S_OSA		(15)
# define CONFIG		(16)
# define BT_OFF		(17)
# define BT_SAVE	(18)
# define BT_BACK	(19)
# define BT_ON_V       	(20)
# define BT_ON_B       	(21)
# define BT_ON_D       	(22)
# define BT_OF_V       	(23)
# define BT_OF_B       	(24)
# define BT_OF_D       	(25)
# define LOAD_ONE	(26)
# define LOAD_TWO	(27)
# define LOAD_THREE	(28)
# define TABMOUSE_S	(3)

# define ERR_ARGS	"Invalid use.\nTry ./tekadventure -h.\n"
# define INV_SPECS	"Error : Invalid specifications.\n"
# define INV_MAP	"Error : Invalid map.\n"

# define HELP		"USAGE:\t./tekadventure [file]\n\tfile : map config file.\n"

# define MENU_PIC	(29)
# define STMENU_MAIN	"./ressources/menus/guimainmenu.png"
# define STMENU_CHARAC	"./ressources/menus/guicharacter.png"
# define STMENU_OPTION	"./ressources/menus/guiconfiguration.png"
# define MLOAD_ONE	"./ressources/menus/chargement_1.png"
# define MLOAD_TWO	"./ressources/menus/chargement_2.png"
# define MLOAD_THREE	"./ressources/menus/chargement_3.png"

# define MENU_NEWS	"./ressources/elements/nouveaute.png"
# define MENU_NEWS_H	"./ressources/elements/nouveaute_hover.png"
# define MENU_OPTION	"./ressources/elements/configuration.png"
# define MENU_OPTION_H	"./ressources/elements/configuration_hover.png"
# define BUTTON_BACK	"./ressources/elements/button_back.png"
# define BUTTON_BACK_H	"./ressources/elements/button_back_hover.png"
# define BUTTON_ON	"./ressources/elements/button_on.png"
# define BUTTON_ONH	"./ressources/elements/button_on_hover.png"
# define BUTTON_OFF	"./ressources/elements/button_off.png"
# define BUTTON_SAVE	"./ressources/elements/button_save.png"
# define BUTTON_SAVE_H	"./ressources/elements/button_save_hover.png"
# define MENU_SHOP	"./ressources/elements/sprite.png"
# define MENU_SHOP_H	"./ressources/elements/sprite_hover.png"
# define CHARAC_FECA	"./ressources/elements/feca.png"
# define CHARAC_FECA_H	"./ressources/elements/feca_hover.png"
# define CHARAC_IOP	"./ressources/elements/iop.png"
# define CHARAC_IOP_H	"./ressources/elements/iop_hover.png"
# define CHARAC_ECA	"./ressources/elements/eca.png"
# define CHARAC_ECA_H	"./ressources/elements/eca_hover.png"
# define CHARAC_OSA	"./ressources/elements/osamoda.png"
# define CHARAC_OSA_H	"./ressources/elements/osamoda_hover.png"

# define STMENU_PLAY	"./ressources/elements/jouer.png"
# define STMENU_PLAY_H	"./ressources/elements/jouer_hover.png"
# define STMENU_MULTI	"./ressources/elements/multijoueurs.png"
# define STMENU_CLOSE	"./ressources/elements/close.png"
# define STMENU_CLOSE_H	"./ressources/elements/close_hover.png"
# define STMENU_START	"./ressources/elements/start.png"
# define STMENU_START_H	"./ressources/elements/start_hover.png"

# define MUSIC_MAIN	"./ressources/music/dofas_menu.ogg"
# define MUSIC_CHARAC	"./ressources/music/dofas_character.ogg"
# define MUSIC_LOADING	"./ressources/music/dofas_loading.ogg"

# define TEXPLY		"./ressources/spritesheet/.png"
# define HUD_PLAYER	"./ressources/elements/hud.png"

# define GRID_PATH      "./ressources/misc/tile2.png"
# define GRID_CONFIG	"./ressources/misc/tile.png"
# define GRID_PATH_TP	"./ressources/misc/tile_tp.png"

# define OSA_BOARD	"./ressources/spriteboard/osa.png"
# define FECA_BOARD	"./ressources/spriteboard/feca.png"
# define ECA_BOARD	"./ressources/spriteboard/eca.png"
# define IOP_BOARD	"./ressources/spriteboard/iop.png"
# define CLASSE_BOARD	"./ressources/spriteboard/classe.png"
# define HEAD_BOARD	"./ressources/spriteboard/head.png"

# define STR_END	"[END]"

/*
** ***************************************************
**                     - STRUCTURE -
** ***************************************************
*/
typedef struct		s_menu_conf
{
  char	*tex_path;
  char	*music_path;
  char	*hover_path;
}			t_menu_conf;

typedef struct		s_game_conf
{
  int	vol;
  int	border;
  int	debug;
}			t_game_conf;

typedef struct		s_stat
{
  int			class;
  int			strengh;
  int			speed;
  int			mana;
  int			endurance;
  int			luck;
  int			patern;
}			t_stat;

typedef struct		s_list
{
  int			x;
  int			y;
  struct s_list		*next;
  struct s_list		*links;
}			t_list;

typedef struct		s_player
{
  sfTexture		*classe_texture;
  sfSprite		*classe;
  sfTexture		*spriteboard;
  int			class;
  int			dir;
  int			pv;
  int			pa;
  int			pm;
  int			level;
  sfVector2i		pos;
  sfVector2i		dest;
  sfVector2i		next;
  int			status;
  int			s;
  int			sprt;
  t_stat		*stat;
}			t_player;

typedef struct          s_menu
{
  sfTexture             *tex;
  sfTexture             *tex_h;
  sfSprite              *sprite;
  sfSprite              *sprite_h;
  int                   hover;
  sfVector2f            pos;
  sfVector2f            pos_h;
  sfVector2u            size;
  sfVector2u            size_h;
  sfMusic               *music;
}			t_menu;

typedef struct          s_game
{
  t_level		*level;
  int			map_status;
  sfVector2i            tile;
  int			actions;
  char			stop[2];
  int			m;
  int			s;
  t_menu		**menu;
  int			idx;
  sfFont		*font;
  sfSprite		*bg;
  t_player		*player;
  char			end;
  sfMusic		*music;
}			t_game;

typedef struct		s_tabmouse
{
  sfVector2i		pos;
  int			bt;
}			t_tabmouse;

/*
** ***************************************************
**             - ARGS GESTURE / HELP / MAP -
** ***************************************************
*/
int			show_help(int, char **);
t_game			*get_file(char *);
int			free_map(int **);

/*
** ***************************************************
**                   - MOUSE EVENT -
** ***************************************************
*/
int			my_check_class(sfRenderWindow *, t_player *);
int			check_class_pos(sfVector2i, sfVector2i, sfVector2i);
int			my_check_click(sfRenderWindow *, int);
int			my_check_config(sfVector2i);
int			mouse_func(sfRenderWindow *, int, t_game *, t_menu **);
int			my_check_exit(sfVector2i);

/*
** ***************************************************
**                   - GAME MANAGER -
** ***************************************************
*/
int			get_osa(t_player *);
int			get_ecaflip(t_player *);
int			get_iop(t_player *);
int			get_feca(t_player *);
int			hud_placing(sfRenderWindow *, t_game *);
int			quest_manager(t_game *);
int			show_player(sfRenderWindow *, t_player *, t_game *);
int			sound_manager(t_game *);
int			show_events(sfRenderWindow *, t_game *, t_event **);
int			decor_manager(sfRenderWindow *, t_game *);
int			check_hud_click(sfRenderWindow *, int, t_game *);
int			set_quest_disp(sfRenderWindow *, t_event *);
int			clean_music(sfMusic *);

/*
** ***************************************************
**                   - MAP MANAGER -
** ***************************************************
*/
sfVector2i		resize_tile(sfVector2i, sfSprite *);
sfVector2i		get_dim(int **);
int			draw_grid(int **, sfVector2i *, sfRenderWindow *, sfSprite *);
int			config_map(sfRenderWindow *, t_game *, int **);
int			show_tp(t_game *, t_player *, sfRenderWindow *);

/*
** ***************************************************
**                   - MENU MANAGER -
** ***************************************************
*/
void			hover_button(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_panels(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_character(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_play(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_config(sfRenderWindow *, sfVector2i, t_menu **);
void			music_change(int, t_menu **);
void			sprite_change(sfRenderWindow *, int, t_menu **);
int			start_menu(t_game *, t_player *);
sfRenderWindow		*create_window(void);
t_menu			**disp_startmenu(void);
void			set_position_panels(t_menu **);
void			set_position_button(t_menu **);
void			set_position_start(t_menu **);
void			set_position_character(t_menu **);
void			set_position_config(t_menu **);
void			set_position_config_s(t_menu **);
int			my_config(sfRenderWindow *, int, t_menu **, t_game *);
void			hover_config_second(sfRenderWindow *, sfVector2i, t_menu **);

/*
** ***************************************************
**                    - SOME FUNC.. -
** ***************************************************
*/
void			debug(t_game *);
sfVector2i		get_mouse_pos(sfRenderWindow *);
int			show_grid(sfRenderWindow *, t_game *, int **);
sfVector2i		raw_click(t_game *, sfRenderWindow *);
t_game			*config_fill(char **);
int			check_pos(t_player *, t_game *);
int			print_bg(t_game *);

/*
** ***************************************************
**                   - LIB FUNC UTILS -
** ***************************************************
*/
int			my_puterr(char *, int);
int			my_atoi(char *);
char			*get_next_line(int);
int			my_putstr(char *);
char			*my_strdup(char *);

/*
** **************************************************
**                    -AFF PERSO
** **************************************************
*/
sfSprite		*get_static_char(sfTexture *, sfVector2i, t_game *, sfVector2i);
int			my_move(sfRenderWindow *, t_game *, t_player *);
sfVector2f		convert_pos(sfVector2i, sfVector2i);
sfVector2f		get_vector(t_game *, t_player *);
sfVector2f		get_mult_size(sfVector2i, sfVector2i);
sfVector2i		bfs_find(int **, sfVector2i, sfVector2i);
sfVector2i		my_bfs(const sfVector2i, const sfVector2i, int **);
sfVector2i		project_pos(sfVector2f, sfVector2i);

#endif /* !TEKADV_H */

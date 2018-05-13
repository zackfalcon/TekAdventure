/*
** config.h for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 16:53:19 2017 LAABID Zakaria
** Last update Sun May 28 23:25:44 2017 LAABID Zakaria
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include <SFML/Graphics.h>
# include <SFML/Graphics/Sprite.h>

# define TXT_EXT	".txt"
# define PIC_EXT	".png"
# define MUSIC_EXT	".ogg"
# define FILECONF	".yml"
# define BAD_EXTENSION	"Bad extension for this path\n"
# define ERRCONF_NAME	"Config file must be an (.yml) file\n"
# define ERRCONF_CONF	"Config file invalid NO CONF-LEVEL- Find\n"
# define ERRCONF_OPEN	"Failed to open config file\n"
# define ERRCONF_DEL	"Error while deleting commentary\n"

# define CONF_LEVEL	"CONF-LEVEL-"
# define MOBS_NB	"mobs-nb:"
# define EVENT_NB	"event-nb:"
# define TELEP_NB	"teleporter-nb:"

# define L_CONF		(11)
# define L_TPNAME	(7)
# define L_MOB		(5)
# define L_NAME		(5)
# define L_TEXT		(8)
# define L_LIFE		(5)
# define L_DMG		(7)
# define L_PM		(3)
# define L_PA		(3)
# define L_COORD	(7)
# define L_EVENT	(6)
# define L_LOAD		(8)
# define L_TILE		(8)
# define L_PNJ		(4)
# define L_QUEST	(9)
# define L_DIALOG	(6)

# define MOBS		"mobs:"
# define TELEPORTER	"teleporter:"
# define EVENT		"event:"

# define MOBS_LIST	"8"
# define MOBS_NAME	"name:"
# define MOBS_TEXT	"texture:"
# define MOBS_LIFE	"life:"
# define MOBS_DMG	"damage:"
# define MOBS_PM	"pm:"
# define MOBS_PA	"pa:"
# define MOBS_COORD	"coords:"
# define MOBS_TYPE	"monster-"

# define TELEP_TYPE	"tp-"
# define TELEP_COORD	"coords:"
# define TELEP_NAME	"tp-name:"
# define TELEP_LOAD	"tp-load:"

# define EVENT_TYPE	"items-"
# define EVENT_NAME	"name:"
# define EVENT_COORD	"coords:"
# define EVENT_TEXT	"texture:"
# define EVENT_PNJ	"pnj:"
# define EVENT_QUEST	"quest-pic:"
# define EVENT_DIALOG	"dialog:"

# define MAP_START	"map:"
# define MAP_CONTENT	"map-content:"
# define MAP_NAME	"map-name:"
# define MAP_DEBUG	"map-debug:"
# define MAP_BG		"map-bg:"
# define MAP_MUSIC	"map-music:"
# define MAP_PLAYER	"map-player:"
# define MAP_DECOR	"map-decor:"
# define MAP_TILE	"map-tile:"

# define ERR_MAP_BG	"Error: no background defined for a map\n"
# define ERR_MAP_DECOR	"Error: no decor defined for a map\n"
# define ERR_MAP_START	"Error: no stat position defined for a map\n"
# define ERR_MAP_DEBUG	"Error: no debug value defined for a map\n"
# define ERR_MAP_MUSIC	"Error: no music defined for a map\n"
# define ERR_MAP_NAME	"Error: no name defined for a map\n"
# define ERR_MAP_CONT	"Error: no content mapc defined for a map\n"
# define ERR_MAP_TILE	"Error: no tile defined for a map\n"

# define ERR_DECOR_PATH "Error: decor bad path detected\n"
# define ERR_BG_PATH	"Error: background bad path detected\n"
# define ERR_MUSIC_PATH	"Error: music bad path detected\n"
# define ERR_TILE_PATH	"Error: tile bad path detected\n"

# define ERR_TELEP_LOAD	"\nError: no load defined for the teleportation\n"
# define ERR_TELEP_NB	"Error: At the teleporter number : "
# define ERR_TELEP_NEG	"\nError: coords to a teleporter can't be negative\n"
# define ERR_TELEP_NAME	"\nError: bad name for this teleporter\n"
# define ERR_TELEP_MAP	"\nMAP NUMBER : "

# define ERR_EVENT_NB	"Error: At the event number :"
# define ERR_EVENT_NAME	"\nError: name not defined for this event\n"
# define ERR_EVENT_DIAL	"\nError: dialog not defined for this event\n"
# define ERR_EVENT_QPIC	"\nError: quest picture not defined for this event\n"
# define ERR_EVENT_TEX	"\nError: texture not defined for this event\n"

typedef struct	s_line
{
  char	*conf;
  int	find;
}		t_line;

typedef struct	s_map
{
  int		**content;
  int	        map_player[2];
  char		*name;
  char		*music;
  int		debug;
  char		*bg;
  char		*decor;
  char		*tile;
}		t_map;

typedef struct	s_level t_level;

typedef struct	s_tp
{
  int		coords[2];
  char		*next_map;
  char		*path_tile;
  int		load;
  t_level	*room;
}		t_tp;

typedef struct	s_mob
{
  char		*name;
  char		*texture;
  int		life;
  int		damage;
  int		pm;
  int		pa;
  int		coords[2];
}		t_mob;

typedef struct	s_event
{
  char		*name;
  char		*texture;
  int		pnj;
  char		active;
  char		*dialog;
  char		*quest_pic;
  int		stop[2];
  int		coords[2];
  int		actions;
}		t_event;

typedef struct	s_level
{
  t_map		*map;
  t_tp		**tp;
  t_mob		**mob;
  t_event	**event;
}		t_level;

/*
** ***************************************************
**                  - CONFIF FILE -
** ***************************************************
*/
int		conf_isempty(t_level **, char **);
int		config_goto(char *, char **, int);
int		config_mob_one(t_level **, char **, int, int);
int		config_mob_two(t_level **, char **, int, int);
int		config_mob_three(t_level **, char **, int, int);
int		config_mob_four(t_level **, char **, int, int);
int		nbrepur(char *);
int		map_content_index(char **, int);
int		**map_content_fill(char **, int, char *, int);
t_level		**config_map_fill(t_level **, char **, int);
int		config_mob_fill(t_level **, char **, int);
int		config_event_fill(t_level **, char **, int);
int		config_telep_fill(t_level **, char **, int);
int		getconf_nbr(char **, char *);
char		*getconf(char **, char *);
char		*unquote(char *);
char		**conf_init(char **, int, int);
void		conf_disp(char **);
t_level		**config_data(char **);
t_level		**gen_config_space(t_level **, char **);
t_level		**gen_event_space(t_level **, char **, int);
t_level		**gen_telep_space(t_level **, char **, int);
t_level		**gen_mob_space(t_level **, char **, int);
int		conf_counter(char **, char *);
char		*getconf(char **, char *);
int		find_to_zero(int);
char		*my_str_nbr(int);
int		is_here(char **, char *, const int);
int		getconf_index(char **, char *, int);
char		**del_commentary(char **);
int		verif_conf_open(char *, char *);
int		map_verif_second(t_map *);
int		map_verif(t_map *);
int		teleporter_verif(t_tp **, int, int);
t_level		**config_map_fill_three(t_level **, char **, int);
t_level		**config_map_fill_four(t_level **, char **, int);
void		config_event_three(t_level **, char **, int, int);
void	        config_event_four(t_level **, char **, int, int);
int		config_event_goto(char *, char **, int);
int		event_verif(t_event **, int, int);
int		event_verif_second(t_event **, int, int);
void		config_telep_loop(t_level **, char *, int, int);

/*
** ***************************************************
**                  - UTILS FUNC -
** ***************************************************
*/
char		**wordtab(char *, char);
void		free_cat(char *, char *);
char		*my_strdup(char *str);
int		my_strlen(char *str);
int		my_printf(char *str,...);
int		my_put_nbr(int nb);
void		my_putchar(char c);
void		my_put_error(char *str_error);
int		my_getnbr(char *str);
int		my_putstr(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(const char *s1, const char *s2, const int n);
char		*epur_str(char *str);
char		*my_strcat(char *dest, char *src);
int		my_atoi(char *);
int		*my_intdup(char *);
int		check_file(char *);			
int		my_puterr(char *, int);
char		*get_next_line(const int);
char		*my_strcat(char *, char *);
t_level		*build_graph(t_level **);
void		*my_puterrnull(const char *);

#endif /* CONFIG_H_ */

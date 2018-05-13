/*
** position.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat Apr 22 20:40:56 2017 LAABID Zakaria
** Last update Sun May 28 11:28:30 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void	        set_position_config(t_menu **menu)
{
  menu[BT_SAVE]->pos = ((sfVector2f) {580.0, 525.0});
  menu[BT_ON_V]->pos = ((sfVector2f) {735.0, 287.0});
  menu[BT_ON_B]->pos = ((sfVector2f) {735.0, 344.0});
  menu[BT_ON_D]->pos = ((sfVector2f) {735.0, 410.0});
  sfSprite_setPosition(menu[BT_SAVE]->sprite, menu[BT_SAVE]->pos);
  sfSprite_setPosition(menu[BT_SAVE]->sprite_h, menu[BT_SAVE]->pos);
  sfSprite_setPosition(menu[BT_ON_V]->sprite, menu[BT_ON_V]->pos);
  sfSprite_setPosition(menu[BT_ON_V]->sprite_h, menu[BT_ON_V]->pos);
  sfSprite_setPosition(menu[BT_ON_B]->sprite, menu[BT_ON_B]->pos);
  sfSprite_setPosition(menu[BT_ON_B]->sprite_h, menu[BT_ON_B]->pos);
  sfSprite_setPosition(menu[BT_ON_D]->sprite, menu[BT_ON_D]->pos);
  sfSprite_setPosition(menu[BT_ON_D]->sprite_h, menu[BT_ON_D]->pos);
}

void	        set_position_start(t_menu **menu)
{
  sfVector2f    start_iop;
  sfVector2f    start_feca;
  sfVector2f    start_eca;
  sfVector2f    start_osa;

  start_iop = ((sfVector2f) {302.0, 530.0});
  start_feca = ((sfVector2f) {490.0, 530.0});
  start_eca = ((sfVector2f) {675.0, 530.0});
  start_osa = ((sfVector2f) {855.0, 530.0});
  menu[BT_BACK]->pos = ((sfVector2f) {275.0, 182.0});
  sfSprite_setPosition(menu[START]->sprite, start_iop);
  sfSprite_setPosition(menu[START]->sprite_h, start_iop);
  sfSprite_setPosition(menu[S_FECA]->sprite, start_feca);
  sfSprite_setPosition(menu[S_FECA]->sprite_h, start_feca);
  sfSprite_setPosition(menu[S_ECA]->sprite, start_eca);
  sfSprite_setPosition(menu[S_ECA]->sprite_h, start_eca);
  sfSprite_setPosition(menu[S_OSA]->sprite, start_osa);
  sfSprite_setPosition(menu[S_OSA]->sprite_h, start_osa);
  sfSprite_setPosition(menu[BT_BACK]->sprite, menu[BT_BACK]->pos);
  sfSprite_setPosition(menu[BT_BACK]->sprite_h, menu[BT_BACK]->pos);
}

void	        set_position_character(t_menu **menu)
{
  menu[IOP]->pos = ((sfVector2f) {335, 280.0});
  menu[IOP]->pos_h = ((sfVector2f) {335 - (55/2), 280.0 - (49/2)});
  menu[FECA]->pos = ((sfVector2f) {520, 275.0});
  menu[FECA]->pos_h = ((sfVector2f) {520 - (33/2), 275.0 - (45/2)});
  menu[ECA]->pos = ((sfVector2f) {708, 290.0});
  menu[ECA]->pos_h = ((sfVector2f) {708 - (49/2), 290.0 - (49/2)});
  menu[OSA]->pos = ((sfVector2f) {885, 280.0});
  menu[OSA]->pos_h = ((sfVector2f) {885 - (50/2), 280.0 - (49/2)});
  sfSprite_setPosition(menu[IOP]->sprite, menu[IOP]->pos);
  sfSprite_setPosition(menu[IOP]->sprite_h, menu[IOP]->pos_h);
  sfSprite_setPosition(menu[FECA]->sprite, menu[FECA]->pos);
  sfSprite_setPosition(menu[FECA]->sprite_h, menu[FECA]->pos_h);
  sfSprite_setPosition(menu[ECA]->sprite, menu[ECA]->pos);
  sfSprite_setPosition(menu[ECA]->sprite_h, menu[ECA]->pos_h);
  sfSprite_setPosition(menu[OSA]->sprite, menu[OSA]->pos);
  sfSprite_setPosition(menu[OSA]->sprite_h, menu[OSA]->pos_h);
}

void	        set_position_button(t_menu **menu)
{
  sfVector2f	play;
  sfVector2f	play_hover;
  sfVector2f	multi;
  sfVector2f	close;
  sfVector2f    close_hover;

  play = ((sfVector2f) {515.0, 250.0});
  play_hover = ((sfVector2f) {515 - (50 / 2), 250.0 - (57 / 2)});
  multi = ((sfVector2f) {515.0, 305.0});
  close = ((sfVector2f) {515.0, 360.0});
  close_hover = ((sfVector2f) {515 - (50 / 2), 360.0 - (57 / 2)});
  sfSprite_setPosition(menu[PLAY]->sprite, play);
  sfSprite_setPosition(menu[PLAY]->sprite_h, play_hover);
  sfSprite_setPosition(menu[MULTI]->sprite, multi);
  sfSprite_setPosition(menu[CLOSE]->sprite, close);
  sfSprite_setPosition(menu[CLOSE]->sprite_h, close_hover);
}

void	        set_position_panels(t_menu **menu)
{
  sfVector2f    option;
  sfVector2f	option_hover;
  sfVector2f    shop;
  sfVector2f    shop_hover;
  sfVector2f	news;
  sfVector2f    news_hover;

  option = ((sfVector2f) {455.0, 513.0});
  option_hover = ((sfVector2f) {455.0 - (51 / 2), 513.0 - (54 / 2)});
  shop = ((sfVector2f) {630.0, 513.0});
  shop_hover = ((sfVector2f) {630.0 - (54 / 2), 513.0 - (54 / 2)});
  news = ((sfVector2f) {795.0, 513.0});
  news_hover = ((sfVector2f) {800 - (60 / 2), 513.0 - (52 / 2)});
  sfSprite_setPosition(menu[OPTION]->sprite, option);
  sfSprite_setPosition(menu[SHOP]->sprite, shop);
  sfSprite_setPosition(menu[NEWS]->sprite, news);
  sfSprite_setPosition(menu[OPTION]->sprite_h, option_hover);
  sfSprite_setPosition(menu[SHOP]->sprite_h, shop_hover);
  sfSprite_setPosition(menu[NEWS]->sprite_h, news_hover);
}

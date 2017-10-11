/*
** signal.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:33:30 2016 Mehdi Meridja
** Last update Tue Apr 12 11:16:41 2016 Mehdi Meridja
*/

#include <signal.h>

#include "minishell2.h"
#include "my.h"

void	basic_prompt(void)
{
  my_putstr("-> ");
}

void	print_path_not_found(char *path)
{
  my_put_error(path);
  my_put_error(": Aucun fichier ou dossier de ce type.\n");
  return ;
}

void	print_not_found(char *command)
{
  my_put_error(command);
  my_put_error(": Command not found.\n");
  return ;
}

void	ctrl_prompt()
{
  my_putstr("\b\b  \n");
  basic_prompt();
  return ;
}

 void	signal_and_basic(void)
 {
   signal(SIGINT, ctrl_prompt);
   basic_prompt();
   return ;
 }

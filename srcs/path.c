/*
** my_tabber.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:30:49 2016 Mehdi Meridja
** Last update Mon Apr 11 16:23:27 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "minishell2.h"
#include "my.h"

int     cpt_custom(char *str)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != 0 && str[i] != '\t' && str[i] != ':')
      {
          cpt++;
          while (str[i] != 0 && str[i] != '\t' && str[i] != ':')
            i++;
      }
      if (str[i] != 0)
	i++;
    }
  return (cpt);
}

char    **wordtab_custom(char *str)
{
  int   i;
  int   j;
  int   k;
  char  **tab;

  i = 0;
  k = 0;
  if ((tab = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[k] != '\0')
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(char) * my_strlen(str))) == NULL)
        return (NULL);
      while (str[k] != ':' && str[k] != '\0')
        tab[i][j++] = str[k++];
      tab[i][j++] = '/';
      tab[i++][j++] = 0;
      k++;
    }
  return (tab);
}

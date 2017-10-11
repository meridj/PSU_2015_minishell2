/*
** minishell2.h for minishell2 in /home/meridj/Rendu/minishell1/inc/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Mon Apr 11 08:20:41 2016 Mehdi Meridja
** Last update Tue Apr 12 20:04:31 2016 Mehdi Meridja
*/

#ifndef MINISHELL2_H_
# define MINISHELL2_H_

typedef struct	s_shell
{
  char		**tab;
  char		*command;
  char		**env;
  char		**path;
  int		ret;
  int		nb;
}		t_shell;

/* main.c */
int	mysh(t_shell *sh);

char	*recupere_env(char *str, char **env);
char	*glob_creation(char *str, t_shell *sh);
char	*cd_3(t_shell *sh, char *pwd);
int	my_command(t_shell *sh);

/* cd.c */
int	go_to_cd(t_shell *sh);

void	my_create_env(t_shell *sh);
void	my_unsetenv(t_shell *sh, int index, int count , int nb);

/* check_command.c */
int	end_unsetenv(char **new_path, char *tmp, int i, t_shell *sh);
int	parcour_chaine(t_shell *sh);
int	parse(t_shell *sh);

/* bulins.c */
int	check_builtins(t_shell *sh);
void	set_env_re(t_shell *sh, int nb, int index, int count);
int	set_env(t_shell *sh);
int	my_hidestr(char *s1, char *s2);

/* exit.c */
int	go_to_exit(char **tab);
int	check_for_exit(char *command);

/* path.c */
int	cpt_custom(char *str);
char	**wordtab_custom(char *str);

/* copy_env.c */
char	**copy_my_env(char **env);

/* free.c */
int	free_struct(t_shell *sh);

/* print.c */
void	basic_prompt(void);
void	ctrl_prompt();
void	signal_and_basic(void);
void	print_not_found(char *command);
void	print_path_not_found(char *command);

/* print_2.c */
int	env(t_shell *sh);

#endif /* !MINISHELL2_H_ */

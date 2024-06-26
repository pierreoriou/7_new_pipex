/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/15 12:44:08 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_cmd
{
	char			**content;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_args
{
	char	*file1;
	char	*file2;
	t_cmd	*cmd;
}			t_args;

int		main(int argc, char *argv[], char *envp[]);
void	close_both_fd(int fd1, int fd2);
/* INIT */
void	init_args(t_args *args, int argc, char *argv[]);
void	init_pipe(int pipefd[2], t_args args);
pid_t	init_fork(t_args args, int pipefd[]);
void	init_dup2_cpid1(t_args args, int pipefd, int infile_fd);
void	init_dup2_cpid2(t_args args, int pipefd, int outfile_fd);
/* CHILD */
void	exec_cpid1(t_args *args, char *envp[], int pipefd[]);
void	exec_cpid2(t_args *args, char *envp[], int pipefd[]);
/* GETTERS */
char	*get_envp_path(char *envp[]);
char	*get_cmd1_path(t_args args, char *path, int pipefd, int fd);
char	*get_cmd2_path(t_args args, char *path, int pipefd, int fd);
/* PRINTS */
void	print_argv(char **arguments);
void	print_commands(t_cmd *cmd);
void	print_args(t_args *args);
void	print_cpid_status(int wstatus);
/* FREE */
void	free_args(t_args *args);
void	free_exit_cpid(t_args args, int pipefd, int fd, int exitcode);

#endif

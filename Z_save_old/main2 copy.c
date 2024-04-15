/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2 copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:03:07 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 15:14:32 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	pid_t	cpid1;
	pid_t	cpid2;
	int		wstatus;
	int		pipefd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit (EXIT_FAILURE);
	}
	init_args(&args, argc, argv);
	initiate_pipe(pipefd);
	cpid1 = initiate_fork();
	if (cpid1 == 0)
	{
		close(pipefd[0]);
		exec_cpid1(args, envp, pipefd);
	}
	cpid2 = initiate_fork();
	if (cpid2 == 0)
	{
		close(pipefd[1]);
		exec_cpid2(args, envp, pipefd);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	initiate_waitpid(cpid1, &wstatus);
	initiate_waitpid(cpid2, &wstatus);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus));
	// print_cpid_status(wstatus);
	free_args(&args);
	return (0);
}

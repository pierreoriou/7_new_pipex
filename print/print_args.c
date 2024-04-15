/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:46:43 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 17:12:56 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_args(t_args *args)
{
	ft_printf(1, "%33?\n", "--PRINT ARGS--");
	printf("args->file1 = %s\n", args->file1);
	printf("args->file2 = %s\n", args->file2);
	print_commands(args->cmd);
}

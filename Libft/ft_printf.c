/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:17:33 by poriou            #+#    #+#             */
/*   Updated: 2024/04/15 10:57:13 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print	*ft_initialize_tab(t_print *tab, int fd)
{
	tab->width = 0;
	tab->color = 0;
	tab->total_length = 0;
	tab->spaces = 0;
	tab->fd = fd;
	tab->error = 0;
	return (tab);
}

static int	parse_str(t_print *tab, const char *str, int fd)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = pf_eval_format(tab, str, i + 1);
			if (i == -1)
				return (0);
		}
		else
			result += write(fd, &str[i], 1);
		i++;
	}
	return (result);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		result;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialize_tab(tab, fd);
	va_start(tab->args, str);
	result = parse_str(tab, str, fd);
	va_end(tab->args);
	result += tab->total_length;
	free(tab);
	return (result);
}

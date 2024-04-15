/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_colored_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:46 by poriou            #+#    #+#             */
/*   Updated: 2024/04/15 10:43:28 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_colored_print(t_print *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		tab->total_length += write(tab->fd, &str[i], 1);
		i++;
	}
	tab->total_length -= 11;
}

void	pf_print_colored_str(t_print *tab)
{
	char	*str;
	char	*new_str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	if (tab->width != 0)
	{
		new_str = pf_color_string(tab, str);
		if (!new_str)
			return ;
	}
	pf_colored_print(tab, new_str);
	free(new_str);
	tab->width = 0;
	tab->color = 0;
}

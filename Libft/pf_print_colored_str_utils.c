/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_colored_str_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:46 by poriou            #+#    #+#             */
/*   Updated: 2024/04/15 10:42:42 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*attach_color_prefix(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin("\033[1;", color);
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free (color);
	return (new);
}

static char	*attach_color_suffix(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin(color, "m");
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

static char	*attach_color_to_string(t_print *tab, char *color, char *str)
{
	char	*new;

	new = ft_strjoin(color, str);
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

static char	*attach_end_of_string(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin(color, "\033[0m");
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

char	*pf_color_string(t_print *tab, char *str)
{
	char	*color;
	char	*tmp_1;
	char	*tmp_2;

	color = ft_itoa(tab->width);
	if (!color)
		return (NULL);
	tmp_1 = attach_color_prefix(tab, color);
	if (!tmp_1)
		return (NULL);
	tmp_2 = attach_color_suffix(tab, tmp_1);
	if (!tmp_2)
		return (NULL);
	tmp_1 = attach_color_to_string(tab, tmp_2, str);
	if (!tmp_1)
		return (NULL);
	str = attach_end_of_string(tab, tmp_1);
	if (!str)
		return (NULL);
	return (str);
}

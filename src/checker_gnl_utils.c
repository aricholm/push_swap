/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:28:05 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:29:50 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "utilities.h"

static void	glue(char **to, const char *from)
{
	char	*out;

	if (!from)
		return ;
	if (!*to)
	{
		*to = ft_strdup(from);
		return ;
	}
	out = ft_strjoin(*to, from);
	free (*to);
	*to = out;
}

int	read_input(char **string)
{
	const size_t	buffersize = 1;
	char			*buff;
	int				chars_read;

	buff = malloc((buffersize + 1) * sizeof(char));
	if (!buff)
		return (-1);
	chars_read = read(0, buff, buffersize);
	if (chars_read < 0)
		return (chars_read);
	buff[chars_read] = 0;
	glue(string, buff);
	free(buff);
	if (!chars_read)
		free (*string);
	return (chars_read);
}

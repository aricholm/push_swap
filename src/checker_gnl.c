/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:20:24 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:17:47 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_operation	convert2(char *input)
{
	if (input[1] == 'a' && input [2] == 0)
		return (RA);
	if (input[1] == 'b' && input [2] == 0)
		return (RB);
	if (input[1] == 'r')
	{
		if (input[2] == 'r' && input [3] == 0)
			return (RRR);
		if (input[2] == 'a' && input [3] == 0)
			return (RRA);
		if (input[2] == 'b' && input [3] == 0)
			return (RRB);
		if (input[2] == 0)
			return (RR);
	}
	return (ERROR);
}

static t_operation	convert(char *input)
{
	if (!input)
		return (OVER);
	if (input[0] == 's')
	{
		if (input[1] == 'a' && input [2] == 0)
			return (SA);
		if (input[1] == 'b' && input [2] == 0)
			return (SB);
		if (input[1] == 's' && input [2] == 0)
			return (SS);
	}
	if (input[0] == 'p')
	{
		if (input[1] == 'a' && input [2] == 0)
			return (PA);
		if (input[1] == 'b' && input [2] == 0)
			return (PB);
	}
	if (input[0] == 'r')
	{
		return (convert2(input));
	}
	return (ERROR);
}

static char	*snip(char **string)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*out;

	i = 0;
	if (!(*string) && !string)
		return (0);
	while ((*string)[i] != 0 && (*string)[i] != '\n')
		i++;
	out = ft_substr(*string, 0, i);
	if ((*string)[i])
	{
		tmp = malloc(sizeof(char) * (ft_strlen(*string) - i++));
		if (!tmp)
			return (NULL);
		j = 0;
		while ((*string)[i])
			tmp[j++] = (*string)[i++];
		tmp[j] = 0;
		free (*string);
		*string = tmp;
	}
	return (out);
}

static t_bool	has_newline(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (FALSE);
	while (string[i])
	{
		if (string[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_operation	get_next_operation(void)
{
	static char	*string;
	int			chars_read;
	char		*operation;
	t_operation	out;

	chars_read = 1;
	while (!has_newline(string) && chars_read > 0)
	{
		chars_read = read_input(&string);
		if (chars_read < 0)
		{
			free (string);
			return (ERROR);
		}
		if (!chars_read)
			return (OVER);
	}
	operation = snip(&string);
	out = convert(operation);
	if (out == ERROR)
		free (string);
	free(operation);
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:52:09 by hthomas           #+#    #+#             */
/*   Updated: 2020/09/25 13:43:08 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int		open_quotes(char *input, char ***command)
{
	int	i;
	int	c;
	int	pos;
	int	in_simple;
	int	in_double;

	in_simple = 0;
	in_double = 0;
	i = 0;
	c = 0;
	while (input[i])
	{
		if(input[i] == '\'' && !in_double)
		{
			if (!in_simple)
				pos = i;
			else
			{
				(*command)[c++] = ft_strndup(input, pos);
			}			
			in_simple += (in_simple == 0 ? 1 : -1);
		}



		//same same... but different
		else if(input[i] == '\"' && !in_simple)
		{

			in_double += (in_double == 0 ? 1 : -1);
		}
		i++;
	}
	return (in_simple || in_double);
}

int		parse_input(char *input, char ***command)
{
	if (open_quotes(input, command))
		return (1);
	*command = ft_split_set(input, " \t");
	return (0);
}

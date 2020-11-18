/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:16:41 by vmoreau           #+#    #+#             */
/*   Updated: 2020/11/18 16:24:20 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	**catch_arg(t_list_cmd *args)
{
	char	**ret;
	int		i;

	i = c_lst_size(args);
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (args)
	{
		ret[i] = ft_strdup(args->str);
		args = args->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	lst_del_next_node(t_list *env, char *var)
{
	t_list	*tmp;

	if (!env || !env->next)
		return ;
	while (env->next)
	{
		if (!ft_strncmp(env->next->content, var, ft_strlen(var)))
		{
			tmp = env->next->next;
			free(env->next->content);
			free(env->next);
			env->next == NULL;
			env->next = tmp;
			break ;
		}
	env = env->next;
	}
}

int		check_id(char *key)
{
	int		i;

	i = 0;
	while (key[i])
	{
		if (!ft_isalpha(key[i]))
			return (0);
		i++;
	}
	if (key[i] == '\0')
		return (1);
}

char	*ft_unset(t_list_cmd *args, t_list *env)
{
	char	**var;
	int		i;

	g_glob.exit = 0;
	if (!args || !args->str || (args->flags == 256 && args->str[0] == '\0'))
		return (ft_strdup(""));
	var = catch_arg(args);
	i = 0;
	while (var[i])
	{
		if (check_id(var[i]))
			lst_del_next_node(env, var[i]);
		else
		{
			g_glob.exit = 1;
			ft_printf("minishell: unset: « %s » : not valid identifier\n", var[i]);
		}
		i++;
	}
	ft_free_tab(var);
	return (ft_strdup(""));
}

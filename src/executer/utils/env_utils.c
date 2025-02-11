/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:18:29 by malena-b          #+#    #+#             */
/*   Updated: 2024/07/02 14:15:49 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

t_env	*ft_get_envvar(t_env *env, char *var_name)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		if (ft_strcmp(aux->key, var_name) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

int	ft_change_envvar(t_env *env, char *var_name, char *new_value)
{
	t_env	*aux;

	aux = ft_get_envvar(env, var_name);
	// ft_putstr_fd(var_name, 2);
	// ft_putstr_fd("\n", 2);
	// ft_putstr_fd(new_value, 2);
	// ft_putstr_fd("\n", 2);
	if (!aux)
		return (0);//PORHACER otra vez lo de la mierda de control de errores
	free (aux->content);
	aux->content = ft_strdup(new_value);
	return (1);
}

void	ft_swap_envnodes(t_env *prev, t_env *act, t_env *next, t_env *last)
{
	prev->next = next;
	next->next = act;
	act->next = last;
}

t_env	*new_env_exp(char *key, char *content)
{
	t_env	*env;

	env = malloc (sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = ft_strdup(key);
	if (content)
		env->content = ft_strdup(content);
	if ((!env->content && content) || !env->key)
		return (NULL);
	env->next = NULL;
	return (env);
}

void	ft_save_env_mat(t_minishell *mshll, int i, int size)
{
	t_env	*env_runner;
	char	*join_aux;
	char	*aux;

	if (mshll->env_mat)
		ft_free_mat(mshll->env_mat);
	mshll->env_mat = NULL;
	env_runner = mshll->env;
	while (env_runner)
	{
		size ++;
		env_runner = env_runner->next;
	}
	env_runner = mshll->env;
	mshll->env_mat = ft_calloc(size, sizeof(char *));
	while (++i < size)
	{
		aux = ft_strdup(env_runner->key);
		join_aux = ft_strjoin(aux, "=");
		mshll->env_mat[i] = ft_strjoin(join_aux, env_runner->content);
		// free (join_aux);
		env_runner = env_runner->next;
	}
}

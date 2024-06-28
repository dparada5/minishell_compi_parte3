/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:39:37 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/28 10:37:18 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

char	*ft_get_exec_path(t_minishell *mshll, char *cmd)
{
	int	i;
	t_env	*path_var;
	char	**path_splitted;
	char	*exec_line;
	char	*join_aux;

	path_var = ft_get_envvar(mshll->env, "PATH");
	path_splitted = ft_split(path_var->content, ':');
	i = -1;
	while (path_splitted[++i])
	{
		join_aux = ft_strjoin(path_splitted[i], "/");
		exec_line = ft_strjoin(join_aux, cmd);
		free(join_aux);
		join_aux = NULL;
		if (access(exec_line, F_OK | X_OK) == 0)
			return (exec_line);
		free(exec_line);
		exec_line = NULL;
	}
	ft_free_mat(path_splitted);
	path_splitted = NULL;
	return (NULL);
}

void	ft_set_cmds_index(t_minishell *mshll)
{
	int	i;
	t_cmds	*cmd_runner;

	i = 0;
	cmd_runner = mshll->cmds;
	while (cmd_runner)
	{
		cmd_runner->index = i++;
		cmd_runner = cmd_runner->next;
	}
}

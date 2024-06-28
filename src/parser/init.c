/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 14:31:47 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/minishell.h"
//912

void	init_ev_exp(t_minishell *minishell, char **env)
{
	minishell->env = save_env(env, -1, minishell);
	minishell->exp = save_env(env, -1, minishell);
	minishell->val_error = 0;
}

void	check_line(t_minishell *minishell)
{
	states(minishell->line, minishell);
	minishell->tokens = get_tokens(minishell->line, minishell);
	check_expansion(minishell->tokens, minishell);
	//printf_tokens(minishell->tokens);
	token_actions(minishell);
	//printf_cmds(minishell->cmds);
}

void	init_minishell(t_minishell *minishell)
{
	minishell->line = readline("minishell$ ");
	while (minishell->line)
	{
		minishell->tokens = NULL;
		minishell->cmds = NULL;
		if (!ft_strlen(minishell->line))
		{
			minishell->line = readline("minishell$ ");
			continue ;
		}
		add_history(minishell->line);
		check_line(minishell);
		if (minishell->flag != 1)
		{
			minishell->val_error = 0;
			ft_executor(minishell);
		}
		minishell->line = readline("minishell$ ");
	}
	rl_clear_history();
}

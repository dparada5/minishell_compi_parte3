/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 14:25:30 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/minishell.h"
//912

int	main(int argc, char **argv, char **env)
{
	t_minishell	*minishell;

	(void)argv;
	if (argc == 1)
	{
		minishell = malloc(sizeof(t_minishell));
		if (!minishell)
			msj_error(MALLOC_FAILED, minishell, 0);
		init_ev_exp(minishell, env);
		init_minishell(minishell);
	}
}
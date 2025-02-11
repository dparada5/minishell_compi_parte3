/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:56:09 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 10:34:57 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

int	ft_pipes_count(t_minishell *mshll)
{
	t_token	*runner;
	int		pipes;

	runner = mshll->tokens;
	pipes = 0;
	while (runner)
	{
		if (runner->token == T_P)
			pipes++;
		runner = runner->next;
	}
	return (pipes);
}

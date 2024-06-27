/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:29 by dparada           #+#    #+#             */
/*   Updated: 2024/06/27 13:20:49 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

void	ft_echo(t_cmds *cmd)
{
	int	nnl_flag;
	int	i;

	nnl_flag = 0;
	i = 1;
	if (!ft_strncmp(cmd->cmds_flags[1], "-n", 3))
	{
		nnl_flag = 1;
		i = 2;
	}
	while (cmd->cmds_flags[i])
	{
		ft_putstr_fd(cmd->cmds_flags[i], 1);
		if (cmd->cmds_flags[i + 1])
			write (1, " ", 1);
		i++;
	}
	if (!nnl_flag)
		ft_putstr_fd("\n", 1);
}

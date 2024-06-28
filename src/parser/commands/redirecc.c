/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:53 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 14:26:04 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

t_token	*open_append(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD, minishell, 1);
	cmds->flag = 0;
	cmds->executor = 1;
	return (token);
}

t_token	*open_trunc(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD, minishell, 1);
	cmds->flag = 2;
	cmds->executor = 1;
	return (token);
}

t_token	*open_infile(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_in != 0)
		close(cmds->fd_in);
	cmds->fd_in = open(token->content, O_RDONLY);
	if (cmds->fd_in < 0)
		msj_error(ERROR_FD, minishell, 1);
	cmds->flag = 2;
	cmds->executor = 1;
	return (token);
}

void	check_heredoc_line(char *line, t_minishell *minishell, int fd)
{
	ft_putstr_fd(expansion(line, minishell), fd);
	ft_putstr_fd("\n", fd);
	free(line);
}

t_token	*here_doc(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	int		fd;
	char	*line;

	if (cmds->fd_in != 0)
		close(cmds->fd_in);
	fd = open (".here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		msj_error(ERROR_FD, minishell, 1);
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, token->content) == 0)
		{
			free(line);
			break ;
		}
		check_heredoc_line(line, minishell, fd);
	}
	close (fd);
	cmds->fd_in = open (".here_doc.tmp", O_RDONLY);
	cmds->flag = 1;
	return (token);
}

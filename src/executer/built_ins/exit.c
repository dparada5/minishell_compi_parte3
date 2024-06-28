/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:39 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 13:37:18 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

//Esto hay que revisarlo por que aún no entiendo bien como funciona lo de
//los códigos de error en la salida
void	ft_exit(int error_code, t_minishell *minishell)
{
	ft_free_minishell(minishell, 1);
	ft_putstr_fd("exit\n", 1);
	exit(error_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:33 by dparada           #+#    #+#             */
/*   Updated: 2024/06/28 10:34:30 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../inc/minishell.h"

void	ft_env(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		ft_putstr_fd(aux->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(aux->content, 1);
		aux = aux->next;
	}
}

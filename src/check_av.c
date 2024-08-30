/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:04 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:07 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_ac(int ac)
{
    if (ac < 2)
	{
		ft_error("Hello???Map is missing...!");
		exit(EXIT_FAILURE);	
	}
	else if (ac > 2)
	{
		ft_error("Choose only 1 map!!");
		exit(EXIT_FAILURE);
	}
}

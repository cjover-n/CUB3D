/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:35 by cjover-n          #+#    #+#             */
/*   Updated: 2020/10/17 18:56:32 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_parameters(t_structcub *cub)
{
    cub->width = 100;
    cub->height = 100;
    cub->rotspeed = 0.1;
    cub->movespeed = 0.25;
    cub->dirx = 0;
    cub->diry = -1;
}
/*
void    ft_init_raycaster(t_structcub *cub, int argc, char **argv)
{

}*/
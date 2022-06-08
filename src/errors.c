/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:29:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 12:55:23 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error_exit(const char *message, t_param *world)
{
	/*	Outputs an error message, free what needs to be freed
		and exits the program.	*/

	(void)world;
	ft_putendl_fd("Error", 2);
	perror(message);
	//free(world);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:29:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 19:28:03 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error_exit(const char *message)
{
	/*	Outputs an error message, free what needs to be freed
		and exits the program.	*/

	ft_putendl_fd("Error", 2);
	perror(message);
	//free(something);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:46 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:06 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"


int	main(int argc, char **argv)
{
	if (argparser(argc, argv))
		if (!init_philo(argc, argv))
			return (error_message());
	return (0);
}

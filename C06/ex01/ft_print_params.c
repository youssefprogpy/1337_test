/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c     		                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbi <youssbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:02:03 by youbi             #+#    #+#             */
/*   Updated: 2025/05/27 16:50:33 by youbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char	*c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

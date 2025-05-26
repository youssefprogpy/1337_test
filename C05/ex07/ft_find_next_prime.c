/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c  		 	                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <elyoubiy@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:35:39 by youssbi           #+#    #+#             */
/*   Updated: 2023/08/09 12:41:49 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 2)
		return (2);
	while (!(ft_is_prime(nb)))
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}

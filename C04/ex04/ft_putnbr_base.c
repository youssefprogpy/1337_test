/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c  				          	        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelyoubi <yelyoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:17:50 by yelyoubi          #+#    #+#             */
/*   Updated: 2025/05/16 16:00:00 by yelyoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid(char	*base)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char	*base)
{
	unsigned int	u_nbr;
	int				base_len;

	if (!is_valid(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		u_nbr = (unsigned int)(-nbr);
	}
	else
		u_nbr = (unsigned int)nbr;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (u_nbr >= base_len)
		ft_putnbr_base(u_nbr / base_len, base);
	ft_putchar(base[u_nbr % base_len]);
}

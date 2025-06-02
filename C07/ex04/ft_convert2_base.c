/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:00:00 by youssbi           #+#    #+#             */
/*   Updated: 2025/06/01 12:00:00 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	convert_string_to_int(char *str, char *base, int len, int i)
{
	int	nbr;
	int	j;
	int	value;

	nbr = 0;
	while (str[i])
	{
		value = -1;
		j = 0;
		while (j < len && base[j] != str[i])
			j++;
		if (j < len)
			value = j;
		if (value == -1)
			break ;
		nbr = nbr * len + value;
		i++;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	len;
	int	sign;
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	len = ft_strlen(base);
	sign = ft_sign(str, &i);
	nbr = convert_string_to_int(str, base, len, i);
	return (nbr * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c  	                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yelyoubi <yelyoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:00:00 by yelyoubi          #+#    #+#             */
/*   Updated: 2025/05/24 12:00:00 by yelyoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_whitespace_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	digit;

	if (!is_valid_base(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	i = skip_whitespace_and_sign(str, &sign);
	result = 0;
	digit = get_index_in_base(str[i], base);
	while (digit != -1)
	{
		result = result * base_len + digit;
		i++;
		digit = get_index_in_base(str[i], base);
	}
	return (result * sign);
}

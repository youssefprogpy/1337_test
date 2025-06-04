/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <youssbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:31:00 by youssbi           #+#    #+#             */
/*   Updated: 2025/06/04 15:29:00 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*src)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(src);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_all(t_stock_str *arr, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
	{
		free(arr[i].copy);
		i++;
	}
	free(arr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char	**av)
{
	t_stock_str	*array;
	int			i;

	i = 0;
	array = (char *) malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i].size = ft_strlen(src);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
		{
			free_all(array, i);
			return (NULL);
		}
		i++;
	}
	array[i].str = NULL;
	return (array);
}

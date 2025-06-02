/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <youssbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:32:00 by youssbi           #+#    #+#             */
/*   Updated: 2025/05/30 14:32:00 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *) malloc(size * (sizeof (int)));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	size = max - min;
	return (size);
}

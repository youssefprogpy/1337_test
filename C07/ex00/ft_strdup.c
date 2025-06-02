/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <youssbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:32:00 by youssbi           #+#    #+#             */
/*   Updated: 2025/05/30 14:32:00 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char	*src)
{
	char	*cpy;
	int		length;
	int		c;

	length = 0;
	c = 0;
	while (src[length] != '\0')
		length++;
	cpy = malloc(length + 1);
	if (cpy == NULL)
		return (NULL);
	if (src[0] == '\0')
	{
		*cpy = '\0';
		return (cpy);
	}
	while (c < length)
	{
		cpy[c] = src[c];
		c++;
	}
	cpy[c] = '\0';
	return (cpy);
}

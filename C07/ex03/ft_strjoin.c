/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c 		                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: youssbi <youssbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:32:00 by youssbi           #+#    #+#             */
/*   Updated: 2025/05/30 14:32:00 by youssbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Count total length of all strings in strs
int	ft_total_length(char **strs, int size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	return (total);
}

// Append sep into result, updating the index via pointer
void	ft_add_sep(char *result, char *sep, int *k)
{
	int	i;

	i = 0;
	while (sep[i])
		result[(*k)++] = sep[i++];
}

// Fill the result string by copying strs and separators
void	ft_fill_result(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		if (i < size - 1)
			ft_add_sep(result, sep, &k);
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		sep_len;
	int		total_len;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	sep_len = ft_strlen(sep);
	total_len = ft_total_length(strs, size) + sep_len * (size - 1);
	result = malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_fill_result(result, strs, sep, size);
	return (result);
}

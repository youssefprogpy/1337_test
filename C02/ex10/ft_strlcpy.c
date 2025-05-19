/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelyoubi <yelyoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:00:00 by yelyoubi          #+#    #+#             */
/*   Updated: 2025/05/16 16:00:00 by yelyoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char	*dest, char	*src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_leng;

	i = 0;
	src_leng = 0;
	while (src[src_leng] != '\0')
	{
		src_leng++;
	}
	if (size > 0)
	{
		while (i < size -1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_leng);
}

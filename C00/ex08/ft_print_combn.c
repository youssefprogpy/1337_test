/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelyoubi <yelyoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:00:00 by yelyoubi          #+#    #+#             */
/*   Updated: 2025/05/16 16:00:00 by yelyoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_comb(char *comb, int n, int is_last)
{
	write(1, comb, n);
	if (!is_last)
		write(1, ", ", 2);
}

void	build_comb(int pos, int n, char *comb, int start_digit)
{
	int	digit;

	digit = start_digit;
	while (digit <= 10 - (n - pos))
	{
		comb[pos] = digit + '0';
		if (pos == n - 1)
			write_comb(comb, n, comb[0] == '0' + (10 - n));
		else
			build_comb(pos + 1, n, comb, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[9];

	if (n < 1 || n > 9)
		return ;
	build_comb(0, n, comb, 0);
}

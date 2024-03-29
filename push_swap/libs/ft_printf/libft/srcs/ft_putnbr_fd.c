/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:56:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 17:47:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		printed;
	long	num;

	printed = 0;
	num = (long) n;
	if (num < 0)
	{
		printed += ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (10 <= num)
		printed += ft_putnbr_fd(num / 10, fd);
	printed += ft_putchar_fd('0' + (num % 10), fd);
	return (printed);
}

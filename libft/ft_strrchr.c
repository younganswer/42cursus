/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 19:34:53 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*res;

	target = (char) c;
	res = 0;
	while (*s)
	{
		if (*s == target)
			res = s;
		s++;
	}
	if (*s == target)
		res = s;
	if (res)
		return (res);
	return (0);
}

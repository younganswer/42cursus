/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:12:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/11 13:41:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t sz_)
{
	void	*res;

	res = malloc(sz_ * count);
	if (!res)
		return (0);
	ft_bzero(res, (sz_ * count));
	return (res);
}

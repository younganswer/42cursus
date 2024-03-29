/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:17:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/11 00:21:40 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_del;

	tmp = *lst;
	while (tmp)
	{
		to_del = tmp;
		tmp = tmp->next;
		ft_lstdelone(to_del, del);
	}
	*lst = 0;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:30:31 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 16:27:39 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

void		sort(int *arr, int start, int end);
static void	ft_swap(int *a, int *b);

void	sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (end <= start)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (start < j && arr[pivot] <= arr[j])
			j--;
		if (j < i)
			ft_swap(&arr[pivot], &arr[j]);
		else
			ft_swap(&arr[i], &arr[j]);
	}
	sort(arr, start, j - 1);
	sort(arr, j + 1, end);
	return ;
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:58:17 by chorse            #+#    #+#             */
/*   Updated: 2022/06/10 11:40:13 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*s;
	int		i;

	i = 0;
	s = lst;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

static void	ft_sort(int **tmp, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*tmp)[j] > (*tmp)[j + 1])
			{
				buff = (*tmp)[j];
				(*tmp)[j] = (*tmp)[j + 1];
				(*tmp)[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_massive(t_list *list)
{
	int	*mass;
	int	i;

	mass = malloc(sizeof(int) * ft_lstsize(list));
	if (!mass)
		return (0);
	i = 0;
	while (list)
	{
		mass[i] = list->num;
		i++;
		list = list->next;
	}
	return (mass);
}

void	ft_get_id(t_list *list)
{
	int		*tmp;
	int		i;
	int		size;
	t_list	*ptr;

	ptr = list;
	size = ft_lstsize(list);
	tmp = ft_massive(list);
	ft_sort(&tmp, size);
	i = 0;
	list = ptr;
	while (ptr)
	{
		i = 0;
		while (tmp[i] != ptr->num)
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
	free(tmp);
}

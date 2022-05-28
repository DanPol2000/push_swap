/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:01:29 by chorse            #+#    #+#             */
/*   Updated: 2022/02/20 16:16:51 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **s_a)
{
	int	tmp;

	tmp = 0;
	tmp = (*s_a)->num;
	(*s_a)->num = (*s_a)->next->num;
	(*s_a)->next->num = tmp;
	*s_a = (*s_a)->next;
	write (1, "sa\n", 3);
}

void	ft_sort_three(t_list **s_a)
{
	int		tmp;
	t_list	*head;

	head = *s_a;
	tmp = 0;
	if ((*s_a)->num < (*s_a)->next->num)
		(*s_a) = (*s_a)->next;
	else
		ft_sa(s_a);
	if ((*s_a)->num > (*s_a)->next->num)
	{
		(*s_a) = head;
		tmp = (*s_a)->num;
		(*s_a)->num = (*s_a)->next->next->num;
		(*s_a)->next->next->num = (*s_a)->next->num;
		(*s_a)->next->num = tmp;
		write (1, "rra\n", 4);
		if ((*s_a)->num > (*s_a)->next->num)
			ft_sa(s_a);
	}
	*s_a = head;
}

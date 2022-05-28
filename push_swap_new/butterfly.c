/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:44:51 by chorse            #+#    #+#             */
/*   Updated: 2022/05/28 17:46:25 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_choose_fwd(int ac)
{
	if (ac <= 15)
		return (2);
	else if (ac <= 100)
		return (15);
	else if (ac <= 250)
		return (20);
	else if (ac <= 500)
		return (30);
	return (ac / 12);
}

void	ft_big_sort(t_list **s_a, t_list **s_b)
{
	int	fwd;
	int	len;
	int	len_nd;

	len = 0;
	len_nd = 0;
	ft_get_id(*s_a);
	len = ft_lstsize(*s_a);
	fwd = ft_choose_fwd(len);
	ft_create_butterfly(s_a, s_b, fwd, len);
	len_nd = ft_lstsize(*s_b);
	while (len_nd > 0)
	{
		ft_to_the_top(len_nd - 1, s_b, len_nd);
		ft_pa(s_b, s_a);
		len_nd--;
	}
}

void	ft_to_the_top(int index, t_list **s_b, int len)
{
	int	pos;
	int	size;

	size = len;
	pos = ft_find_stack_position(s_b, index, len);
	if (pos > size / 2)
		ft_cast_operation(size - pos, s_b, ft_rrb);
	else
		ft_cast_operation(pos, s_b, ft_rb);
}

void	ft_create_butterfly(t_list **s_a, t_list **s_b, int fwd, int len)
{
	int	point;

	point = 0;
	while (point != len)
	{
		if ((*s_a)->index <= point)
		{
			ft_pb(s_a, s_b);
			ft_rb(s_b);
		}
		else if ((*s_a)->index <= point + fwd)
			ft_pb(s_a, s_b);
		else
		{
			ft_ra(s_a);
			continue ;
		}
		point++;
	}
}

int	ft_find_stack_position(t_list **s_b, int index, int len)
{
	int		i;
	t_list	*lst;

	lst = (*s_b);
	i = -1;
	while (++i < len)
	{
		if (lst->index == index)
		{
			return (i);
		}
		lst = lst->next;
	}
	return (-1);
}

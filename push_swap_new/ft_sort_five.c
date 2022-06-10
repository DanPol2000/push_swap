/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:13:04 by chorse            #+#    #+#             */
/*   Updated: 2022/06/07 19:51:22 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_list_front(t_list **stack, t_list *new_list)
{
	if (!new_list)
		return ;
	new_list -> next = *stack;
	*stack = new_list;
}

static void	f_out(t_list **s_a, int *tmp, int *snd)
{
	t_list	*head;

	head = (*s_a);
	*tmp = (*s_a)->num;
	(*s_a) = (*s_a)->next;
	while ((*s_a))
	{
		if ((*s_a)->num < *tmp)
			*tmp = (*s_a)->num;
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;
	if ((*s_a)->num == *tmp)
		(*s_a) = (*s_a)->next;
	*snd = (*s_a)->num;
	(*s_a) = (*s_a)->next;
	while ((*s_a))
	{
		if ((*s_a)->num < *snd && (*s_a)->num != *tmp)
			*snd = (*s_a)->num;
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;
}

void	ft_sort_five(t_list **s_a, t_list **s_b)
{
	int	tmp;
	int	snd;
	int	i;

	i = -1;
	tmp = 0;
	snd = 0;
	f_out(s_a, &tmp, &snd);
	if (ft_lstsize(*s_a) == 4)
	{
		ft_sort_four(s_a, s_b, tmp);
		exit(0);
	}
	while (++i < 5)
	{
		if ((*s_a)->num == tmp || (*s_a)->num == snd)
			ft_pb(s_a, s_b);
		else
			ft_ra(s_a);
	}
	ft_sort_three((s_a));
	if ((*s_b)->num < (*s_b)->next->num)
		ft_sb(s_b);
	while ((*s_b))
		ft_pa(s_b, s_a);
}

void	ft_sort_four(t_list **s_a, t_list **s_b, int tmp)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*s_a)->num == tmp)
			ft_pb(s_a, s_b);
		else
			ft_ra(s_a);
		i++;
	}
	ft_sort_three((s_a));
	ft_pa(s_b, s_a);
}

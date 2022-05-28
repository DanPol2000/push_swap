/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:58:38 by chorse            #+#    #+#             */
/*   Updated: 2022/05/28 18:50:25 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_stack(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head -> next)
	{
		if (head->num > head -> next -> num)
			return (0);
		head = head -> next;
	}
	return (1);
}

int	ft_is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c < 58))
		return (1);
	else
		return (0);
}

void	ft_ss(t_list **s_a, t_list **s_b)
{
	ft_sa(s_a);
	ft_sb(s_b);
	write(1, "ss\n", 3);
}

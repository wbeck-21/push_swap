/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:11:47 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 20:24:04 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_listadd_front(t_stack ***lst, t_stack *new)
{
	if (**lst)
	{
		new->next = **lst;
		**lst = new;
	}
	else
		**lst = new;
}

void	ft_listadd_back(t_stack **lst, t_stack *new_list)
{
	t_stack	*p;

	if (*lst == NULL)
		*lst = new_list;
	else
	{
		p = ft_listlast(*lst);
		p->next = new_list;
	}
}

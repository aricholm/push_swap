/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:39:10 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/16 12:21:49 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "utilities.h"

void	stack_swap(t_list **list)
{
	t_list	*tmp;

	if (*list && (*list)->next)
	{
		tmp = (*list)->next;
		(*list)->next = tmp->next;
		tmp->next = *list;
		*list = tmp;
	}
}

void	stack_push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;

	if (*stack_from)
	{
		tmp = (*stack_from)->next;
		(*stack_from)->next = *stack_to;
		*stack_to = *stack_from;
		*stack_from = tmp;
	}
}

void	stack_rotate(t_list **list)
{
	t_list	*tmp;

	if (*list && (*list)->next)
	{
		(ft_lstlast(*list))->next = *list;
		tmp = (*list)->next;
		(*list)->next = NULL;
		*list = tmp;
	}
}

void	stack_reverse_rotate(t_list **list)
{
	t_list	*penultimate;
	t_list	*ultimate;

	if (*list && (*list)->next)
	{
		penultimate = *list;
		while ((penultimate->next)->next)
			penultimate = penultimate->next;
		ultimate = penultimate->next;
		penultimate->next = NULL;
		ultimate->next = *list;
		*list = ultimate;
	}
}

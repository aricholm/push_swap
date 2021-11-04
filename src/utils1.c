/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:22:43 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 23:29:33 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->a = NULL;
	new->b = NULL;
	return (new);
}

void	fill_stack(t_list **stack, int value)
{
	ft_lstadd_back(stack, ft_lstnew(value));
}

void	free_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->b;
	while (tmp)
	{
		tmp = tmp->next;
		free (stack->b);
		stack->b = tmp;
	}
	tmp = stack->a;
	while (tmp)
	{
		tmp = tmp->next;
		free (stack->a);
		stack->a = tmp;
	}
}

t_list	*duplicate_stack(t_list *list)
{
	t_list	*new_stack;

	new_stack = NULL;
	if (list)
	{
		new_stack = ft_lstnew(list->value);
		list = list->next;
		while (list)
		{
			fill_stack(&new_stack, list->value);
			list = list->next;
		}
	}
	return (new_stack);
}

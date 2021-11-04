/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:06:25 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/11 12:26:52 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list.h"
#include "utilities.h"

t_list	*find_value(t_list *stack_from, t_list *stack_to, int number)
{
	while (stack_from)
	{
		if (stack_from->value == number)
			return (stack_to);
		else
		{
			stack_from = stack_from->next;
			stack_to = stack_to->next;
		}
	}
	return (NULL);
}

int	second_smallest(t_list *stack, int small)
{
	int	smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->value < smallest && stack->value > small)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	get_smallest(t_list *stack)
{
	int	smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

static void	free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		free (list);
		list = tmp;
	}
}

void	renumber(t_stack *stack)
{
	size_t	len;
	size_t	i;
	t_list	*elem;
	t_list	*renumbered;
	int		smallest;

	i = 0;
	renumbered = duplicate_stack(stack->a);
	if (stack->a && stack->a->next)
	{
		len = ft_lstsize(stack->a);
		smallest = get_smallest(stack->a);
		while (i < len)
		{
			elem = find_value(stack->a, renumbered, smallest);
			smallest = second_smallest(stack->a, smallest);
			elem->value = i + 1;
			i++;
		}
		free_list(stack->a);
		stack->a = renumbered;
	}
}

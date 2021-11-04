/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:35:22 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:21:37 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "utilities.h"

static int	error(t_stack stack)
{
	write(2, "Error\n", 6);
	free_stack(&stack);
	return (-1);
}

static t_bool	check(t_stack stack)
{
	t_list	*tmp;

	if (stack.b)
		return (FALSE);
	tmp = stack.a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

static size_t	checker_solve(t_stack *stack, t_operation operation)
{
	if (operation == SA)
		return (ch_sa(stack));
	if (operation == SB)
		return (ch_sb(stack));
	if (operation == PA)
		return (ch_pa(stack));
	if (operation == PB)
		return (ch_pb(stack));
	if (operation == RA)
		return (ch_ra(stack));
	if (operation == RB)
		return (ch_rb(stack));
	if (operation == RRA)
		return (ch_rra(stack));
	if (operation == RRB)
		return (ch_rrb(stack));
	if (operation == SS)
		return (ch_ss(stack));
	if (operation == RR)
		return (ch_rr(stack));
	if (operation == RRR)
		return (ch_rrr(stack));
	if (operation == ERROR)
		write(2, "Error\n", 6);
	return (0);
}

static t_bool	input_solve(t_stack *stack)
{
	t_operation	operation;

	operation = 1;
	while (operation != OVER && operation != ERROR)
	{
		operation = get_next_operation();
		checker_solve(stack, operation);
	}
	if (operation != ERROR)
		return (TRUE);
	return (FALSE);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 1;
	if (argc == 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	while (i < argc)
	{
		if (is_valid(stack.a, argv[i]))
			fill_stack(&stack.a, ft_atoi(argv[i]));
		else
			return (error(stack));
		i++;
	}
	if (input_solve(&stack))
	{
		if (check(stack))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3 );
	}
	free_stack(&stack);
}

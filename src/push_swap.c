/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:27:21 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:42:30 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utilities.h"
#include "operations.h"

static int	error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	return (-1);
}

static void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
}

static void	optimal_sort(t_stack *stack)
{
	size_t	divider;

	divider = optimal_divide(*stack);
	while (push_lowest_x(stack, divider))
		solve_right_x(stack, divider);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 1;
	if (argc == 1)
		return (0);
	stack_init(&stack);
	while (i < argc)
	{
		if (is_valid(stack.a, argv[i]))
			fill_stack(&stack.a, ft_atoi(argv[i]));
		else
			return (error(&stack));
		i++;
	}
	renumber(&stack);
	if (argc > 20)
		optimal_sort(&stack);
	slow_solve(&stack);
	while (stack.b)
		ft_pa(&stack);
	free_stack(&stack);
}

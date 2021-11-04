/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:49:24 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 16:59:31 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include "utilities.h"
# include "operations.h"

typedef enum e_operation{
	OVER,
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR,
	ERROR,
}	t_operation;

t_operation	get_operation(void);
size_t		ch_sa(t_stack *stack);
size_t		ch_sb(t_stack *stack);
size_t		ch_pa(t_stack *stack);
size_t		ch_pb(t_stack *stack);
size_t		ch_ra(t_stack *stack);
size_t		ch_rb(t_stack *stack);
size_t		ch_rra(t_stack *stack);
size_t		ch_rrb(t_stack *stack);
size_t		ch_ss(t_stack *stack);
size_t		ch_rr(t_stack *stack);
size_t		ch_rrr(t_stack *stack);

t_operation	get_next_operation(void);
int			read_input(char **string);
size_t		ft_strlen(const char *s);

#endif
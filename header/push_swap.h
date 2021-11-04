/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:39:37 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:42:27 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef enum e_bool{FALSE, TRUE}	t_bool;
typedef enum e_side{LEFT, RIGHT}	t_side;

size_t	optimal_divide(t_stack stack);
#endif
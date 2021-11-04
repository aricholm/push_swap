/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:56:33 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 18:29:04 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include "push_swap.h"

void	fill_stack(t_list **stack, int value);
t_list	*duplicate_stack(t_list *list);
void	print_stack(t_stack stack);
void	free_stack(t_stack *stack);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_stack	*new_stack(void);
t_bool	is_valid(t_list *stack, char *value);
void	renumber(t_stack *stack);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:44:58 by uolle             #+#    #+#             */
/*   Updated: 2024/01/06 19:41:53 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/includes/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// -----------------------------------------------------------------------

// -- STRUCTURE
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// -----------------------------------------------------------------------

// -- Utils for common
int					ft_stack_sorted(t_stack *stack);
int					ft_duplicate_check(char **values);
int					ft_duplicate_sign_check(char **argv);
char				**ft_join_split(char **argv);
int					ft_count_values(char **values);
int					ft_is_digit(char *str);

// -- Utils for stack
void				ft_push_bottom(t_stack **head, t_stack *new_node);
t_stack				*ft_get_last_stack(t_stack *stack);
int					ft_stack_len(t_stack *stack);
void				ft_free_stack(t_stack **stack);

// -- Initialization
void				ft_new_stack(t_stack **head, int nbr);
void				ft_indexation(t_stack *stack, int ssize);
void				ft_init_stack(int len_values, char **values,
						t_stack **stack);

// -- Sort
void				ft_sort_three(t_stack **stack_a);
void				ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_five(t_stack **stack_a, t_stack **stack_b);
// -- Radix
void				ft_radix(t_stack **stack_a, t_stack **stack_b);

// -----------------------------------------------------------------------

// -- Push
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

// -- Rotate
void				ft_ra(t_stack **stack);
void				ft_rb(t_stack **stack);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

// -- Reverse rotate
void				ft_rra(t_stack **stack);
void				ft_rrb(t_stack **stack);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

// -- Swap
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

#endif

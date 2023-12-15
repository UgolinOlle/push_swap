/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:44:58 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 20:29:54 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libs/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// -- STRUCTURE
typedef struct s_stack {
  int value;
  int index;
  int pos;
  int target_pos;
  int cost_a;
  int cost_b;
  struct s_stack *next;
} t_stack;

// -- UTILS
int ft_stack_sorted(t_stack *stack);
int ft_duplicate_check(char **argv);
int ft_duplicate_sign_check(char **argv);
char **ft_join_split(char **argv);

// -- UTILS STACK
void ft_push_bottom_stack(t_stack *stack, t_stack *new_stack);
t_stack *ft_get_last_stack(t_stack *stack);
int ft_stack_len(t_stack *stack);

// -- INIT
void ft_new_stack(t_stack *stack, int nbr);
void ft_indexation(t_stack *stack, int ssize);
void ft_init_stack(int argc, char **argv, t_stack *stack);

// -- PUSH
void ft_pa(t_stack *stack_a, t_stack *stack_b);
void ft_pb(t_stack *stack_a, t_stack *stack_b);

// -- ROTATE
void ft_ra(t_stack *stack);
void ft_rb(t_stack *stack);
void ft_rr(t_stack *stack_a, t_stack *stack_b);

// -- REVERSE ROTATE
void ft_rra(t_stack *stack);
void ft_rrb(t_stack *stack);
void ft_rrr(t_stack *stack_a, t_stack *stack_b);

// -- SWAP
void ft_sa(t_stack *stack_a);
void ft_sb(t_stack *stack_b);
void ft_ss(t_stack *stack_a, t_stack *stack_b);

#endif

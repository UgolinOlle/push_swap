/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:44:58 by uolle             #+#    #+#             */
/*   Updated: 2023/12/14 14:55:08 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libs/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

// -- UTILS STACK
int ft_stack_len(t_stack *stack);
void ft_new_stack(t_stack *stack, int nbr);
void ft_init_stack(char **argv, t_stack *stack);

// -- SWAP
void ft_sa(t_stack *stack_a);
void ft_sb(t_stack *stack_b);
void ft_ss(t_stack *stack_a, t_stack *stack_b);

#endif

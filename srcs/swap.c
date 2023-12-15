/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:07:01 by uolle             #+#    #+#             */
/*   Updated: 2023/12/14 11:40:33 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

static void ft_swap(t_stack *stack) {
  long int tmp;

  if (stack == NULL && stack->next == NULL)
    return;
  tmp = stack->value;
  stack->value = stack->next->value;
  stack->next->value = tmp;
  tmp = stack->index;
  stack->index = stack->next->index;
  stack->next->index = tmp;
}

void ft_sa(t_stack *stack_a) {
  ft_swap(stack_a);
  ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void ft_sb(t_stack *stack_b) {
  ft_swap(stack_b);
  ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void ft_ss(t_stack *stack_a, t_stack *stack_b) {
  ft_swap(stack_a);
  ft_swap(stack_b);
  ft_putstr_fd("ss\n", STDOUT_FILENO);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:11:03 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 16:59:07 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

static void ft_reverse_rotate(t_stack *stack) {
  t_stack *before_last_node;
  t_stack *last_node;

  last_node = stack;
  before_last_node = NULL;

  while (last_node->next) {
    before_last_node = last_node;
    last_node = last_node->next;
  }
  before_last_node->next = NULL;
  last_node->next = stack;
  stack = last_node;
}

void ft_rra(t_stack *stack) {
  ft_reverse_rotate(stack);
  ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void ft_rrb(t_stack *stack) {
  ft_reverse_rotate(stack);
  ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void ft_rrr(t_stack *stack_a, t_stack *stack_b) {
  ft_reverse_rotate(stack_a);
  ft_reverse_rotate(stack_b);
  ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

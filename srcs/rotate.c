/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:54:22 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 16:56:20 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

/**
 * Rotates the stack.
 *
 * @param stack The stack to be rotated.
 *
 * Moves the first node of the stack to the end of the stack.
 */
static void ft_rotate(t_stack *stack) {
  t_stack *tmp_node;
  t_stack *last_node;

  tmp_node = stack;
  stack = stack->next;
  last_node = ft_get_last_stack(stack);
  tmp_node->next = NULL;
  last_node->next = stack;
}

void ft_ra(t_stack *stack) {
  ft_rotate(stack);
  ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void ft_rb(t_stack *stack) {
  ft_rotate(stack);
  ft_putstr_fd("rb", STDOUT_FILENO);
}

void ft_rr(t_stack *stack_a, t_stack *stack_b) {
  ft_rotate(stack_a);
  ft_rotate(stack_b);
  ft_putstr_fd("rr\n", STDOUT_FILENO);
}

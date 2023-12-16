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

/**
 * @brief Rotate the last stack to the top of the stack
 *
 * @param stack The stack to be rotated.
 */
static void ft_reverse_rotate(t_stack *stack) {
  int last_value;
  int last_index;

  last_value = stack->value;
  last_index = stack->index;
  while (stack->next) {
    stack->value = stack->next->value;
    stack->index = stack->next->index;
    stack = stack->next;
    printf("last_value: %d\n", last_value);
    printf("last_index: %d\n", last_index);
  }
  stack->value = last_value;
  stack->index = last_index;
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

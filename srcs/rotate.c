/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:54:22 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 17:52:36 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate the first element of the stack to the bottom.
 *
 * @param stack The stack to be rotated.
 */
static void ft_rotate(t_stack **stack) {
  t_stack *tmp;
  t_stack *last;

  if (!*stack || !(*stack)->next)
    return;
  tmp = *stack;
  last = *stack;
  while (last->next)
    last = last->next;
  *stack = (*stack)->next;
  tmp->next = NULL;
  last->next = tmp;
}

void ft_ra(t_stack **stack) {
  ft_rotate(stack);
  ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void ft_rb(t_stack **stack) {
  ft_rotate(stack);
  ft_putstr_fd("rb", STDOUT_FILENO);
}

void ft_rr(t_stack **stack_a, t_stack **stack_b) {
  ft_rotate(stack_a);
  ft_rotate(stack_b);
  ft_putstr_fd("rr\n", STDOUT_FILENO);
}

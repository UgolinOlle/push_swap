/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:11:03 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 17:52:50 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate the last stack to the top of the stack
 *
 * @param stack The stack to be rotated.
 * @return void
 */
static void ft_reverse_rotate(t_stack **stack) {
  t_stack *tmp;
  t_stack *last;

  if (!*stack || !(*stack)->next)
    return;
  tmp = *stack;
  while (tmp->next->next)
    tmp = tmp->next;
  last = tmp->next;
  tmp->next = NULL;
  last->next = *stack;
  *stack = last;
}

void ft_rra(t_stack **stack) {
  ft_reverse_rotate(stack);
  ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void ft_rrb(t_stack **stack) {
  ft_reverse_rotate(stack);
  ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b) {
  ft_reverse_rotate(stack_a);
  ft_reverse_rotate(stack_b);
  ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

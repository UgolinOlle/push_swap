/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:08:41 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/16 17:51:21 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Push a new node to the bottom of the stack.
 *
 * @param head t_stack The head of the stack.
 * @param new t_stack The new node to be added at bottom to the stack.
 */
void ft_push_bottom(t_stack **head, t_stack *new_node) {
  t_stack *current;

  if (!head || !new_node)
    return;
  if (!*head) {
    *head = new_node;
    return;
  }
  current = *head;
  while (current->next) {
    current = current->next;
  }
  current->next = new_node;
}

int ft_stack_sorted(t_stack *stack) {
  while (stack->next) {
    if (stack->value > stack->next->value)
      return (0);
    stack = stack->next;
  }
  return (1);
}

t_stack *ft_get_last_stack(t_stack *stack) {
  while (stack && stack->next)
    stack = stack->next;
  return (stack);
}

/**
 * @brief Get length of stack.
 *
 * @param stack The stack to be counted.
 * @return int The length of the stack.
 */
int ft_stack_len(t_stack *stack) {
  int i;

  i = 0;
  if (!stack)
    return (0);
  while (stack) {
    stack = stack->next;
    i++;
  }
  return (i);
}

/**
 * @brief Print all element of the stack.
 *
 * @param stack The stack to be printed.
 */
void ft_print_stack(t_stack *stack) {
  while (stack) {
    ft_putnbr_fd(stack->value, 1);
    ft_putchar_fd('\n', 1);
    stack = stack->next;
  }
}

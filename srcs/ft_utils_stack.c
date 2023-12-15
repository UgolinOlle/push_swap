/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:08:41 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/15 20:29:42 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push_bottom_stack(t_stack *stack, t_stack *new_stack) {
  t_stack *tmp;

  if (!stack) {
    stack = new_stack;
    return;
  }
  if (!new_stack)
    return;
  tmp = ft_get_last_stack(stack);
  tmp->next = new_stack;
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

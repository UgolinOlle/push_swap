/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:08:41 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/15 16:00:16 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

t_stack *ft_get_last_stack(t_stack *stack) {
  while (stack && stack->next)
    stack = stack->next;
  return (stack);
}

static void ft_push_bottom_stack(t_stack *stack, t_stack *new_stack) {
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

void ft_new_stack(t_stack *stack, int nbr) {
  stack = malloc(sizeof(&stack));
  if (!stack)
    return;
  stack->value = nbr;
  stack->index = 0;
  stack->pos = -1;
  stack->target_pos = -1;
  stack->cost_a = -1;
  stack->cost_b = -1;
  stack->next = NULL;
}

void ft_indexation(t_stack *stack, int ssize) {
  t_stack *current;
  t_stack *max_node;
  int max_value;

  while (ssize-- > 0) {
    current = stack;
    max_value = INT_MIN;
    max_node = NULL;

    while (current) {
      if (current->value > max_value && current->index == 0) {
        max_value = current->value;
        max_node = current;
      }
      current = current->next;
    }
    if (max_node)
      max_node->index = ssize + 1;
  }
}

void ft_init_stack(char **argv, t_stack *stack) {
  int i;
  int tmp;
  t_stack *new;

  i = 1;
  tmp = 0;
  new = NULL;
  while (argv[i]) {
    tmp = ft_atoi(argv[i]);
    if (tmp < INT_MIN && tmp > INT_MAX)
      ft_handle_error("[ERROR] - Wrong digit.");
    if (i == 1)
      ft_new_stack(stack, tmp);
    else {
      ft_new_stack(new, tmp);
      ft_push_bottom_stack(stack, new);
    }
    ft_print_list(stack);
    i++;
  }
}

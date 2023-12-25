/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:31:35 by uolle             #+#    #+#             */
/*   Updated: 2023/12/17 17:36:45 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Assigns positions to all elements in the stack.
 *
 * @param stack The stack to which positions will be assigned.
 * @return void
 */
static void ft_find_pos(t_stack **stack) {
  t_stack *tmp;
  int i;

  i = 0;
  tmp = *stack;
  while (tmp) {
    tmp->pos = i;
    tmp = tmp->next;
    i++;
  }
}

/**
 * @brief Get the target position in stack_a for the element in stack_b based on
 * index.
 *
 * @param stack_a t_stack The main stack.
 * @param index int The index of the element in stack_b.
 * @return int The target position in stack_a.
 */
static int ft_find_target_pos(t_stack **stack_a, int index) {
  t_stack *tmp;
  int ret;
  int i;

  tmp = *stack_a;
  ret = 0;
  i = 0;
  while (tmp) {
    if (tmp->index > index && tmp->index < INT_MAX) {
      i = tmp->index;
      ret = tmp->pos;
    }
    tmp = tmp->next;
    i++;
  }
  return (ret);
}

/**
 * @brief Find the target position for each element in stack_b. the target
 * position is the position where the element should be placed in stack_a.
 *
 * @param stack_a The main stack.
 * @param stack_b The assist stack.
 * @return void
 */
void ft_find_target(t_stack **stack_a, t_stack **stack_b) {
  t_stack *tmp;
  int i;

  i = 0;
  ft_find_pos(stack_a);
  ft_find_pos(stack_b);
  tmp = *stack_b;
  while (tmp) {
    i = ft_find_target_pos(stack_a, tmp->index);
    tmp->target_pos = i;
    tmp = tmp->next;
  }
}

/**
 * @brief Find the cost to move each element of stack_b to stack_a.
 *
 * @param stack_a The main stack.
 * @param stack_b The assist stack.
 * @return void
 *
 * @note cost_b is the cost to move the element to the top of stack_b.
 * cost_a is the cost to move the element to the right position in stack_a.
 */
void ft_find_cost(t_stack **stack_a, t_stack **stack_b) {
  t_stack *tmp;
  int i;

  i = 0;
  ft_find_target(stack_a, stack_b);
  tmp = *stack_b;
  while (tmp) {
    i = ft_stack_len(*stack_b) - tmp->pos;
    if (tmp->target_pos > i) {
      tmp->cost_b = i;
    } else {
      tmp->cost_b = tmp->target_pos;
    }
    tmp->cost_a = ft_stack_len(*stack_a) - tmp->target_pos;
    tmp = tmp->next;
  }
}

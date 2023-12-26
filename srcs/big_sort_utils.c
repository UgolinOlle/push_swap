/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:31:35 by uolle             #+#    #+#             */
/*   Updated: 2023/12/26 11:29:16 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Updates the 'pos' attribute of each element in a linked list of
 * t_stack structures.
 *
 * @note This function iterates through the linked list pointed to by the given
 * stack pointer, assigning incremental positions (starting from 0) to the 'pos'
 * attribute of each node.
 *
 * @param stack Pointer to a pointer to the head of the linked list.
 *              Upon completion, the 'pos' attribute of each node in the linked
 * list will be updated.
 *
 * @note The 'pos' attribute of each node is updated incrementally starting from
 * 0. This function assumes that the 'next' pointer of each t_stack node is
 * properly set.
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
 * @brief Get the best position for an element in stack_b in stack_a.
 *
 * @note This function determines the best position in stack_a for an element in
 *
 * @param stack_a Pointer to a pointer to the head of the main stack (stack_a).
 * @param index The index of the element in stack_b.
 * @return An integer representing the best position for the element in stack_a.
 */
static int ft_find_target_pos(t_stack **stack_a, int index) {
  t_stack *tmp;
  int tpos;
  int i;

  tmp = *stack_a;
  tpos = 0;
  i = INT_MAX;
  while (tmp) {
    if (tmp->index > index && tmp->index < i) {
      i = tmp->index;
      tpos = tmp->pos;
    }
    tmp = tmp->next;
  }
  if (i != INT_MAX) {
    return (tpos);
  }
  tmp = *stack_a;
  while (tmp) {
    if (tmp->index < i) {
      i = tmp->index;
      tpos = tmp->pos;
    }
    tmp = tmp->next;
  }
  return (tpos);
}

/**
 * @brief Find the target position for each element in stack_b in stack_a.
 *
 * @note This function determines the target position in stack_a for each
 * element in stack_b based on their indices.
 *
 * @param stack_a Pointer to a pointer to the head of the main stack
 * (stack_a).
 * @param stack_b Pointer to a pointer to the head of the assist stack
 * (stack_b).
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

/**
 * @brief Get the lowest position of the lowest index in stack.
 *
 * @param stack The assist stack.
 * @return An integer representing the lowest position of the lowest index in
 * stack_b.
 */
int ft_get_lowest_pos(t_stack **stack) {
  t_stack *tmp;
  int lowest_pos;
  int lowest_index;

  tmp = *stack;
  ft_find_pos(stack);
  lowest_pos = tmp->pos;
  lowest_index = INT_MAX;
  while (tmp) {
    if (tmp->index < lowest_index) {
      lowest_pos = tmp->pos;
      lowest_index = tmp->index;
    }
    tmp = tmp->next;
  }
  return (lowest_pos);
}

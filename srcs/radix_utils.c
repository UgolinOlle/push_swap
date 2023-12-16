/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:10 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 20:27:20 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Transfer all elements from stack a to stack b except the last three.
 * Performs a preliminary sort based on index.
 *
 * @param stack_a t_stack Top of stack a.
 * @param stack_b t_stack Top of stack b.
 *
 * @note This function pushes elements from stack A to stack B, except for the
 * last three elements. It pushes smaller values (with an index smaller than the
 * median index) to stack B first, then rotates stack A for the remaining
 * elements before pushing them to stack B. The last three elements are left in
 * stack A.
 */
void ft_push_to_b(t_stack **stack_a, t_stack **stack_b) {
  int median;
  int i;
  int ssize;

  ssize = ft_stack_len(*stack_a);
  median = ssize / 2;
  i = 0;
  while (i < ssize - 3) {
    if ((*stack_a)->index < median) {
      ft_pb(*stack_a, *stack_b);
      i++;
    } else
      ft_ra(*stack_a);
  }
}

/**
 * @brief Calculates the current positions of each value in both stacks.
 *
 * @param stack_a t_stack Top of stack a.
 * @param stack_b t_stack Top of stack b.
 * @return void
 *
 */
void ft_calc_index(t_stack **stack_a, t_stack **stack_b) {
  int i;
  int j;
  t_stack *tmp;

  i = 0;
  tmp = *stack_a;
  while (tmp) {
    j = 0;
    tmp->index = i;
    while (tmp->next && tmp->value > tmp->next->value) {
      tmp = tmp->next;
      j++;
    }
    tmp->index = i - j;
    tmp = tmp->next;
    i++;
  }
  tmp = *stack_b;
  while (tmp) {
    j = 0;
    tmp->index = i;
    while (tmp->next && tmp->value > tmp->next->value) {
      tmp = tmp->next;
      j++;
    }
    tmp->index = i - j;
    tmp = tmp->next;
    i++;
  }
}

/**
 * @brief Calculates the target position of each value in stack A. A where all
 * element should be moved to.
 *
 * @param stack_a t_stack Top of stack a.
 * @param stack_b t_stack Top of stack b.
 * @return void
 */
void ft_calc_target(t_stack **stack_a, t_stack **stack_b) {
  t_stack *current_b = *stack_b;
  t_stack *current_a;
  int target_pos;

  while (current_b != NULL) {
    target_pos = 0;
    current_a = *stack_a;
    while (current_a != NULL) {
      if (current_b->value < current_a->value) {
        break;
      }
      target_pos++;
      current_a = current_a->next;
    }
    current_b->target_pos = target_pos;
    current_b = current_b->next;
  }
}

/**
 * @brief Calculates the cost in terms of actions to move a value from stack B
 * to its target position in stack A. Considers both rotation and reverse
 * rotation.
 *
 * @param stack_a t_stack Top of stack a.
 * @param stack_b t_stack Top of stack b.
 * @return void
 */
void ft_calc_cost(t_stack **stack_a, t_stack **stack_b) {
  t_stack *current_b = *stack_b;
  t_stack *current_a;
  int cost;

  while (current_b != NULL) {
    cost = 0;
    current_a = *stack_a;
    while (current_a != NULL) {
      if (current_b->value < current_a->value) {
        break;
      }
      cost++;
      current_a = current_a->next;
    }
    current_b->cost_b = cost;
    current_b = current_b->next;
  }
}

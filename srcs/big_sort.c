/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:29:27 by uolle             #+#    #+#             */
/*   Updated: 2023/12/17 17:39:45 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Transfer elements from stack_a to stack_b except the three first one.
 *
 * @param stack_a t_stack The main stack.
 * @param stack_b t_stack The stack to which elements will be transferred.
 * @return void
 */
static void ft_transfer(t_stack **stack_a, t_stack **stack_b) {
  int ssize;
  int pushed;
  int i;

  ssize = ft_stack_len(*stack_a);
  pushed = 0;
  i = 0;
  while (ssize > 6 && i < ssize && pushed < ssize - 6) {
    if ((*stack_a)->index < ssize / 2) {
      ft_pb(stack_a, stack_b);
      pushed++;
    } else {
      ft_ra(stack_a);
    }
    i++;
  }
  while (ssize - pushed > 3) {
    ft_pb(stack_a, stack_b);
    pushed++;
  }
}

/**
 * @brief Sorts more than three elements in stack_a.
 *
 * @param stack_a t_stack The main stack.
 * @param stack_b t_stack The second stack.
 * @return void
 */
void ft_big_sort(t_stack **stack_a, t_stack **stack_b) {
  ft_transfer(stack_a, stack_b);
  ft_sort_three(stack_a);
  while (*stack_b) {
    ft_find_target(stack_a, stack_b);
    ft_find_cost(stack_a, stack_b);
  }
  ft_print_stack(*stack_b);
}

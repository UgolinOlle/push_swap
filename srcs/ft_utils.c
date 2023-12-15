/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:53:03 by uolle             #+#    #+#             */
/*   Updated: 2023/12/14 14:54:33 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_stack_sorted(t_stack *stack) {
  while (stack->next) {
    if (stack->value > stack->next->value)
      return (0);
    stack = stack->next;
  }
  return (1);
}

void ft_print_list(t_stack *stack) {
  t_stack *temp = stack;
  while (temp != NULL) {
    printf("Value: %d, Index: %d, Pos: %d, Target Pos: %d, Cost A: %d, Cost B: "
           "%d\n",
           temp->value, temp->index, temp->pos, temp->target_pos, temp->cost_a,
           temp->cost_b);
    temp = temp->next;
  }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:07:01 by uolle             #+#    #+#             */
/*   Updated: 2023/12/14 11:40:33 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Swap the first two elements at the top of the stack.
 *
 * @param stack The stack to be swapped.
 */
static void ft_swap(t_stack *stack) {
  int tmp_value;
  int tmp_index;

  if (!stack || !stack->next)
    return;
  tmp_value = stack->value;
  tmp_index = stack->index;
  stack->value = stack->next->value;
  stack->index = stack->next->index;
  stack->next->value = tmp_value;
  stack->next->index = tmp_index;
}

/**
 * @brief Swap the first two elements at the top of the stack a.
 *
 * @param stack_a The stack to be swapped.
 */
void ft_sa(t_stack *stack_a) {
  ft_swap(stack_a);
  ft_putstr_fd("sa\n", STDOUT_FILENO);
}

/**
 * @brief Swap the first two elements at the top of the stack b.
 *
 * @param stack_b The stack to be swapped.
 */
void ft_sb(t_stack *stack_b) {
  ft_swap(stack_b);
  ft_putstr_fd("sb\n", STDOUT_FILENO);
}

/**
 * @brief Swap the first two elements at the top of the stack a and b.
 *
 * @param stack_a The stack to be swapped.
 * @param stack_b The stack to be swapped.
 */
void ft_ss(t_stack *stack_a, t_stack *stack_b) {
  ft_swap(stack_a);
  ft_swap(stack_b);
  ft_putstr_fd("ss\n", STDOUT_FILENO);
}

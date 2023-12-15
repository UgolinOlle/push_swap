/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:42:34 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 00:52:25 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Get the max value in stack.
 *
 * @param stack The stack to be checked.
 * @return int The max value in stack.
 */
static int ft_get_max(t_stack *stack) {
  int max;

  max = INT_MIN;
  while (stack) {
    if (stack->value > max)
      max = stack->value;
    stack = stack->next;
  }
  return (max);
}

/**
 * @brief Get the min value in stack.
 *
 * @param stack The stack to be checked.
 * @return int The min value in stack.
 */
static int ft_get_min(t_stack *stack) {
  int min;

  min = INT_MAX;
  while (stack) {
    if (stack->value < min)
      min = stack->value;
    stack = stack->next;
  }
  return (min);
}

/**
 * @brief Sorts an array of three integers using minimal operations.
 *
 * This function sorts a small array of three integers using a set of
 * predefined operations: 'ra' (rotate upwards), 'rra' (rotate downwards), and
 * 'sa' (swap first two elements). The sorting algorithm is based on the
 * position of the largest number in the array. The function selects the
 * appropriate operation(s) to sort the array in ascending order.
 *
 * Algorithm:
 *   1. If the first number is the largest, perform 'ra'.
 *   2. Otherwise, if the second number is the largest, perform 'rra'.
 *   3. Finally, if the first number is larger than the second, perform 'sa'.
 *
 * @param array An array of three integers. The function assumes the array
 * size is exactly three.
 *
 * Usage:
 *     int arr[] = {3, 1, 2};
 *     sortThreeNumbers(arr);
 *     // After the call, 'arr' will be sorted in ascending order.
 *
 * Note:
 *   - The function modifies the array in place.
 *   - The operations 'ra', 'rra', and 'sa' are assumed to be defined
 * elsewhere and are used to manipulate the array.
 *   - This algorithm is specifically tailored for an array of size three and
 * may not be suitable for larger arrays.
 *
 * @return Void. The array is sorted in place.
 */
void ft_sort_three(t_stack **stack_a) {
  int max;
  int min;

  max = ft_get_max(*stack_a);
  min = ft_get_min(*stack_a);
  if ((*stack_a)->value == max && (*stack_a)->next->value == min)
    ft_sa(*stack_a);
  else if ((*stack_a)->value == max)
    ft_ra(*stack_a);
  else if ((*stack_a)->next->value == max)
    ft_rra(*stack_a);
  else if ((*stack_a)->value > (*stack_a)->next->value)
    ft_sa(*stack_a);
}

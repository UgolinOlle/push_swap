/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:51:15 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 17:00:51 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

static void ft_push(t_stack *stack, t_stack *head) {
  t_stack *tmp;

  if (stack == NULL)
    return;
  tmp = stack->next;
  stack->next = head;
  head = stack;
  stack = tmp;
}

void ft_pa(t_stack *stack_a, t_stack *stack_b) {
  ft_push(stack_a, stack_b);
  ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void ft_pb(t_stack *stack_a, t_stack *stack_b) {
  ft_push(stack_b, stack_a);
  ft_putstr_fd("pb\n", STDOUT_FILENO);
}
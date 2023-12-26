/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:29:27 by uolle             #+#    #+#             */
/*   Updated: 2023/12/26 11:20:11 by ugolin-olle      ###   ########.fr       */
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
 * @brief Making move to the right position in stack_a.
 *
 * @param stack_a t_stack The main stack.
 * @param stack_b t_stack The second stack.
 * @param i int The number of times to rotate stack_a.
 * @param j int The number of times to rotate stack_b.
 * @return void
 */
static void ft_move(t_stack **stack_a, t_stack **stack_b, int i, int j) {
  while (i > 0 && j > 0) {
    ft_rr(stack_a, stack_b);
    i--;
    j--;
  }
  while (i < 0 && j < 0) {
    ft_rrr(stack_a, stack_b);
    i++;
    j++;
  }
  while (i) {
    if (i > 0) {
      ft_ra(stack_a);
      i--;
    } else {
      ft_rra(stack_a);
      i++;
    }
  }
  while (j > 0) {
    if (j > 0) {
      ft_rb(stack_b);
      j--;
    } else {
      ft_rrb(stack_b);
      j++;
    }
  }
  ft_pa(stack_a, stack_b);
}

/**
 * @brief Determine the cost of actions it take to put each element from stack_b
 * to the right position in stack_a.
 *
 * @param stack_a t_stack The main stack.
 * @param stack_b t_stack The second stack.
 * @return void
 */
static void ft_exec(t_stack **stack_a, t_stack **stack_b) {
  t_stack *tmp;
  int i;
  int j;
  int cost;

  (void)stack_a;
  tmp = *stack_b;
  i = 0;
  j = 0;
  cost = INT_MAX;
  while (tmp) {
    if (tmp->cost_a + tmp->cost_b < cost) {
      cost = tmp->cost_a + tmp->cost_b;
      i = tmp->cost_a;
      j = tmp->cost_b;
    }
    tmp = tmp->next;
  }
  ft_move(stack_a, stack_b, i, j);
}

/**
 * @brief Sorts more than three elements in stack_a.
 *
 * @param stack_a t_stack The main stack.
 * @param stack_b t_stack The second stack.
 * @return void
 */
void ft_big_sort(t_stack **stack_a, t_stack **stack_b) {
  int lpos;

  ft_transfer(stack_a, stack_b);
  ft_sort_three(stack_a);
  while (*stack_b) {
    ft_find_target(stack_a, stack_b);
    ft_find_cost(stack_a, stack_b);
    ft_exec(stack_a, stack_b);
  }
  if (ft_stack_sorted(*stack_a) == 0) {
    lpos = ft_get_lowest_pos(stack_a);
    if (lpos > ft_stack_len(*stack_a) / 2) {
      while (lpos < ft_stack_len(*stack_a)) {
        ft_rra(stack_a);
        lpos++;
      }
    } else {
      while (lpos > 0) {
        ft_ra(stack_a);
        lpos--;
      }
    }
  }
}

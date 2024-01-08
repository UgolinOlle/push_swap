/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:17:10 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/01/07 12:22:54 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Get the highest index of the stack.
 *
 * @param stack The stack to be checked.
 * @return int The highest index of the stack.
 */
static int	ft_get_highest_index(t_stack *stack)
{
	int	highest_index;

	highest_index = 0;
	while (stack)
	{
		if (stack->index > highest_index)
			highest_index = stack->index;
		stack = stack->next;
	}
	return (highest_index);
}

/**
 * @brief Sort the stack of 3 numbers by the index rather than value.
 *
 * @param stack The stack to be sorted.
 * @return void
 */
void	ft_sort_three(t_stack **stack)
{
	int	highest_index;

	highest_index = ft_get_highest_index(*stack);
	if ((*stack)->index == highest_index)
		ft_ra(stack);
	else if ((*stack)->next->index == highest_index)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

/**
 * @brief Sort the stack of 4 numbers by the index rather than value.
 *
 * @param t_stack stack_a The primary stack to be sorted.
 * @param t_stack stack_b The secondary stack.
 * @return void
 */
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	ssize;

	ssize = ft_stack_len(*stack_a);
	while (ssize--)
	{
		if ((*stack_a)->index == 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
}

/**
 * @brief Sort the stack of 5 numbers by the index rather than value.
 *
 * @param t_stack stack_a The primary stack to be sorted.
 * @param t_stack stack_b The secondary stack.
 * @return void
 */
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	ssize;

	ssize = ft_stack_len(*stack_a);
	while (ssize--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
}

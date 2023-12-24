/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:41:12 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 17:53:35 by ugolin-olle      ###   ########.fr       */
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
 */
void	ft_sort_three(t_stack **stack)
{
	int	highest_index;

	highest_index = ft_get_highest_index(*stack);
	if ((*stack)->index == highest_index)
		ft_ra(*stack);
	else if ((*stack)->next->index == highest_index)
		ft_rra(*stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(*stack);
}
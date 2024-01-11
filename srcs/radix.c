/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:50:45 by uolle             #+#    #+#             */
/*   Updated: 2024/01/10 22:05:03 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Get the maximum bit of the stack.
 *
 * @param stack The stack to be checked.
 * @return int The maximum bit of the stack.
 */
static int	get_max_bits(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		max_bits;

	tmp = *stack;
	max = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * @brief Radix sort
 *
 * @param stack_a The primary stack to be sorted.
 * @param stack_b The secondary stack (not used in this function).
 * @return void
 *
 * @note Sorts the stack using radix sort.
 */
void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = ft_stack_len(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_stack_len(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}

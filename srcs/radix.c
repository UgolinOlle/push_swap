/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:50:45 by uolle             #+#    #+#             */
/*   Updated: 2023/12/26 22:18:48 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	ssize;

	i = 0;
	ssize = ft_stack_len(*stack_a);
	while (ft_stack_sorted(*stack_a) == 0)
	{
		j = 0;
		while (j < ssize)
		{
			if ((((*stack_a)->value >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		i++;
	}
}

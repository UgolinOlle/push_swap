/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:50:45 by uolle             #+#    #+#             */
/*   Updated: 2024/01/04 23:16:10 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Get the maximum bit of the stack.
 *
 * @param stack The stack to be checked.
 * @return int The maximum bit of the stack.
 */
static int	ft_get_max_bit(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		max_bit;

	tmp = *stack;
	max = tmp->index;
	max_bit = 0;
	while (tmp)
	{
		if (tmp->index > max_bit)
			max_bit = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
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
	t_stack	*tmp;
	int		i;
	int		j;
	int		ssize;
	int		max_bit;

	tmp = *stack_a;
	i = 0;
	ssize = ft_stack_len(*stack_a);
	max_bit = ft_get_max_bit(stack_a);
	while (i < max_bit)
	{
		j = 0;
		while (j++ < ssize)
		{
			tmp = *stack_a;
			if (((tmp->value >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_stack_len(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}

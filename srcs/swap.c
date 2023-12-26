/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:07:01 by uolle             #+#    #+#             */
/*   Updated: 2023/12/26 22:19:40 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Swap the first two elements at the top of the stack.
 *
 * @param stack The stack to be swapped.
 * @return void
 */
static void	ft_swap(t_stack **stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!*stack || !(*stack)->next)
		return ;
	tmp_value = (*stack)->value;
	tmp_index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp_value;
	(*stack)->next->index = tmp_index;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

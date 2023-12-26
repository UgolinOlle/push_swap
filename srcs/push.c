/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:51:15 by uolle             #+#    #+#             */
/*   Updated: 2023/12/26 22:18:41 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Push a new node to the top of the stack.
 *
 * @param stack The stack to be pushed.
 * @param head The head of the stack.
 * @return void
*/
static void	ft_push(t_stack **stack, t_stack **head)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = *head;
	*head = *stack;
	*stack = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

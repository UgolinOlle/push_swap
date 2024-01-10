/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:57:38 by uolle             #+#    #+#             */
/*   Updated: 2024/01/10 10:53:46 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Free the values array.
 *
 * @param values The array of values to be freed.
 * @return void
 */
static void	ft_free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

/**
 * @brief Checks the command-line arguments for validity.
 *
 * @param argc The count of arguments.
 * @param argv The array of arguments.
 * @return void
 *
 * @note Verifies that the number of arguments is sufficient and each argument
 * represents a valid digit. If an error is found, the function triggers
 * an error handling routine.
 */
static void	ft_check_args(int argc, char **values)
{
	int	i;

	if (argc < 2)
	{
		ft_free_values(values);
		ft_handle_error("Error\n");
	}
	i = 0;
	while (values[i] != NULL)
	{
		if (ft_is_digit(values[i]) == 0 || ft_duplicate_check(values) == 0
			|| ft_duplicate_sign_check(values) == 0)
		{
			ft_free_values(values);
			ft_handle_error("Error\n");
		}
		if (ft_atol(values[i]) > INT_MAX || ft_atol(values[i]) < INT_MIN)
		{
			ft_ree_values(values);
			ft_handle_error("Error\n");
		}
		i++;
	}
}

/**
 * @brief Sorts the stack of integers if the stack size is 2.
 *
 * @param stack_a The primary stack to be sorted.
 * @param stack_b The secondary stack (not used in this function).
 * @param ssize The size of the primary stack.
 * @return void
 *
 * @note Checks if the size of the stack is 2 and if the stack is not already
 * sorted. If these conditions are met, it performs a swap operation.
 */
static void	ft_sorting(t_stack **stack_a, t_stack **stack_b, int ssize)
{
	if (ft_stack_sorted(*stack_a) == 1)
		return ;
	if (ssize == 2)
		ft_sa(stack_a);
	else if (ssize == 3)
		ft_sort_three(stack_a);
	else if (ssize == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ssize == 5)
		ft_sort_five(stack_a, stack_b);
	else if (ssize > 5)
		ft_radix(stack_a, stack_b);
}

/**
 * @brief The main function of the push_swap program. Initializes stacks, checks
 * arguments, performs sorting operations, and manages the overall flow of the
 * push_swap program.
 *
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return An integer to signal the end of the program.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**values;
	int		len_values;
	int		ssize;

	values = ft_join_split(argv);
	ft_check_args(argc, values);
	stack_a = NULL;
	stack_b = NULL;
	len_values = ft_count_values(values);
	ft_init_stack(len_values, values, &stack_a);
	ssize = ft_stack_len(stack_a);
	ft_indexation(stack_a, ssize);
	ft_sorting(&stack_a, &stack_b, ssize);
	ft_free_values(values);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

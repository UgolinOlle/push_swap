/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:53:03 by uolle             #+#    #+#             */
/*   Updated: 2024/01/10 10:20:50 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Check if there are no duplicate numbers in values provided.
 *
 * @param values char The count of command-line arguments.
 * @return int 1 if no duplicate numbers, 0 if duplicate numbers.
 */
int	ft_duplicate_check(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i] != NULL)
	{
		j = i + 1;
		while (values[j] != NULL)
		{
			if (ft_atol(values[i]) == ft_atol(values[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Check if there is no duplicate sign in argv
 *
 * @param argv char The count of command-line arguments.
 * @return int 1 if no duplicate sign, 0 if duplicate sign.
 */
int	ft_duplicate_sign_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '-' && argv[i][j + 1] == '-')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '+')
				|| (argv[i][j] == '-' && argv[i][j + 1] == '+')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Join and split all values in argv
 *
 * @param argv char The count of command-line arguments.
 * @return char** The array of values from the command-line arguments.
 */
char	**ft_join_split(char **argv)
{
	int		i;
	char	*str;
	char	*temp;
	char	**split;

	i = 1;
	if (argv[i] == NULL || ft_strlen(argv[i]) == 0)
		ft_handle_error("Error\n");
	str = ft_strdup("");
	while (argv[i] != NULL)
	{
		temp = str;
		str = ft_strjoin(str, argv[i]);
		free(temp);
		temp = str;
		str = ft_strjoin(str, " ");
		free(temp);
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

/**
 * @brief Count number of values inside double pointer
 *
 * @param values char The count of command-line arguments.
 * @return int The number of values inside double pointer.
 */
int	ft_count_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief Check if argv[i] is a digit
 *
 * @param argv char The count of command-line arguments.
 * @return int 1 if argv[i] is a digit, 0 if not.
 */
int	ft_is_digit(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
		i++;
	else if (argv[i] == '-' || argv[i] == '+')
		return (0);
	while (argv[i] != '\0')
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

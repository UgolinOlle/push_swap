/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:53:03 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 20:30:21 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check if argv don't have duplicated number
 *
 * @param argv char The count of command-line arguments.
 */
int ft_duplicate_check(char **argv) {
  int i;
  int j;

  i = 1;
  while (argv[i] != NULL) {
    j = i + 1;
    while (argv[j] != NULL) {
      if (ft_atoi(argv[i]) == ft_atoi(argv[j])) {
        return (0);
      }
      j++;
    }
    i++;
  }
  return (1);
}

/**
 * Check if there is no duplicate sign in argv
 *
 * @param argv char The count of command-line arguments.
 */
int ft_duplicate_sign_check(char **argv) {
  int i;
  int j;

  i = 1;
  while (argv[i] != NULL) {
    j = 0;
    while (argv[i][j] != '\0') {
      if ((argv[i][j] == '-' && argv[i][j + 1] == '-') ||
          (argv[i][j] == '+' && argv[i][j + 1] == '+') ||
          (argv[i][j] == '-' && argv[i][j + 1] == '+') ||
          (argv[i][j] == '+' && argv[i][j + 1] == '-'))
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

/**
 * Join and split all values in argv
 *
 * @param argv char The count of command-line arguments.
 */
char **ft_join_split(char **argv) {
  char *str;
  char **split;
  int i;

  i = 1;
  str = ft_strdup("");
  while (argv[i] != NULL) {
    str = ft_strjoin(str, argv[i]);
    str = ft_strjoin(str, " ");
    i++;
  }
  split = ft_split(str, ' ');
  return (split);
}

/**
 * Count number of values inside double pointer
 *
 * @param values char The count of command-line arguments.
 */
int ft_count_values(char **values) {
  int i;

  i = 0;
  while (values[i] != NULL)
    i++;
  return (i);
}

/**
 * Check if argv[i] is a digit
 *
 * @param argv char The count of command-line arguments.
 */
int ft_is_digit(char *argv) {
  int i;

  i = 0;
  while (argv[i] != '\0') {
    printf("argv[i] = %c\n", argv[i]);
    if (argv[i] == '-' || argv[i] == '+' || argv[i + 1] == ' ')
      i++;
    if (argv[i] == '\0' && ft_isdigit(argv[i]) == 0)
      return (0);
    i++;
  }
  return (1);
}

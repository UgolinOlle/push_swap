/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:31:35 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 12:31:55 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long ft_atol(const char *str) {
  int sign;
  int i;
  long res;

  sign = 1;
  i = 0;
  res = 0;
  while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  if (str[i] == '-' || str[i] == '+')
    sign = 1 - 2 * (str[i++] == '-');
  while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + str[i] - '0';
    if (sign == 1 && res < 0) // Détection de dépassement pour positif
      return (LONG_MAX);
    if (sign == -1 && res < 0) // Détection de dépassement pour négatif
      return (LONG_MIN);
    i++;
  }
  return (res * sign);
}

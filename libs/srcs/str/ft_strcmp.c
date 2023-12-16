/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:56:09 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 11:56:53 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int ft_strcmp(const char *s1, const char *s2) {
  int i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if ((unsigned char)s1[i] != (unsigned char)s2[i])
      return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    i++;
  }
  return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

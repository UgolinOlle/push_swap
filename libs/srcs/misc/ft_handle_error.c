/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:00:08 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/16 00:57:24 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <unistd.h>

void ft_handle_error(char *content) {
  ft_putstr_fd(content, STDERR_FILENO);
  exit(EXIT_FAILURE);
}

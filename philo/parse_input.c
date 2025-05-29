/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 04:26:41 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/29 22:10:43 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_av(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int	parse_input(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (check_av(av[i]) == 0)
			return (0);
		else if (check_space(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

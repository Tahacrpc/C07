/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:00:40 by tcirpici          #+#    #+#             */
/*   Updated: 2024/09/03 22:57:28 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	range_size;
	int	*range;

	range_size = 0;
	index = max - min;
	if (min == max || min > max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (index));
	if (range == NULL)
		return (NULL);
	while (min < max)
	{
		range[range_size] = min;
		min++;
		range_size++;
	}
	return (range);
}

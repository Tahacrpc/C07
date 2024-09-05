/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 06:44:11 by tcirpici          #+#    #+#             */
/*   Updated: 2024/09/04 10:44:03 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *src)
{
	int	index;

	index = 0;
	if (src == NULL)
		return (0);
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	ft_src_len(char **src, int size)
{
	int	index;
	int	total;

	index = 0;
	total = 0;
	while (index < size)
	{
		if (src[index] != NULL)
			total += ft_len(src[index]);
		index++;
	}
	return (total);
}

char	*ft_put_str(char *dest, char **strs, char *sep, int size)
{
	int	h;
	int	i;
	int	j;
	int	k;

	h = 0;
	i = 0;
	while (h < size)
	{
		if (strs[h] != NULL)
		{
			j = 0;
			while (strs[h][j] != '\0')
				dest[i++] = strs[h][j++];
		}
		if (h < size - 1 && sep != NULL)
		{
			k = 0;
			while (sep[k] != '\0')
				dest[i++] = sep[k++];
		}
		h++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	char	*dest;

	if (size == 0)
	{
		dest = (char *)malloc(1);
		if (dest != NULL)
			dest[0] = '\0';
		return (dest);
	}
	total = ft_src_len(strs, size) + (ft_len(sep) * (size - 1));
	dest = (char *)malloc(total + 1);
	if (dest == NULL)
		return (NULL);
	return (ft_put_str(dest, strs, sep, size));
}

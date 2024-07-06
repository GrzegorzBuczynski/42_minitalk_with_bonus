/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:59:12 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/03/17 16:34:15 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	j = 0;
	while (s1[i + j])
		j++;
	while (j && ft_is_in_set(s1[i + j - 1], set))
		j--;
	ptr = malloc(j + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[j] = '\0';
	while (j--)
	{
		ptr[j] = s1[i + j];
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:07:35 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/03/17 15:23:53 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_word_length(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static char	*allocate_word(char const *s, char c)
{
	char	*word;
	size_t	k;

	k = 0;
	word = malloc(ft_word_length(s, c) + 1);
	if (word == NULL)
		return (NULL);
	while (s[k] && s[k] != c)
	{
		word[k] = s[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

static char	**allocate_words(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ptr[j] = allocate_word(s + i, c);
			if (ptr[j] == NULL)
			{
				while (j--)
					free(ptr[j]);
				free(ptr);
				return (NULL);
			}
			i += ft_word_length(s + i, c);
			(j)++;
		}
		else
			(i)++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	ptr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr = allocate_words(s, c, ptr);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

/* #include <stdio.h>
int	main(void)
{
	char	*str;
	char	**tab;
	int		i;

	str = "Hello World";
	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misung <misung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:15:41 by misung            #+#    #+#             */
/*   Updated: 2021/09/26 16:12:26 by misung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	ft_sep_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	if (c == '\0')
		return (true);
	return (false);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	while (str[i] != '\0')
	{
		if (ft_sep_check(str[i + 1], charset)
			&& !ft_sep_check(str[i], charset))
			word_cnt++;
		i++;
	}
	return (word_cnt);
}

void	ft_fill_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!ft_sep_check(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_fill_str2d(char **str2d, char *str, char *charset)
{
	int	i;
	int	j;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	while (str[i] != '\0')
	{
		if (ft_sep_check(str[i], charset))
		{
			i++;
		}
		else
		{
			j = 0;
			while (!ft_sep_check(str[i + j], charset))
				j++;
			str2d[word_cnt] = (char *)malloc(sizeof(char) * (j + 1));
			ft_fill_word(str2d[word_cnt], str + i, charset);
			i += j;
			word_cnt++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**str2d;
	int		word_cnt;

	word_cnt = ft_word_count(str, charset);
	str2d = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (str2d == NULL)
		return (0);
	str2d[word_cnt] = 0;
	ft_fill_str2d(str2d, str, charset);
	return (str2d);
}

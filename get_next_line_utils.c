/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:10:16 by luribero          #+#    #+#             */
/*   Updated: 2024/05/01 20:51:44 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_string(char a, char *line, int *len)
{
	if (a == '\n')
	{
		*len = *len - 1;
		*line = '\n';
		line++;
	}
	return (line);
}

struct s_reading	*fix(struct s_reading *ptr, int *sum_char_read)
{
	int					len = 0;
	int					a = 0;
	struct s_reading	*temp = NULL;
	int					mover = 0;

	len = *sum_char_read;
	temp = (struct s_reading *)malloc(sizeof(struct s_reading));
	if (temp == NULL)
		return (NULL);
	temp -> char_read = len;
	while (ptr -> buff[mover] != '\n')
		mover++;
	while (len > 0)
	{
		mover++;
		temp -> buff[a] = ptr -> buff [mover];
		len--;
		a++;
	}
	temp -> buff[a] = '\0';
	free(ptr);
	return (temp);
}

void	clean(struct s_reading *first)
{
	struct s_reading	*ptr = NULL;
	struct s_reading	*temp = NULL;

	if (first == NULL)
		return ;
	ptr = first;
	while (ptr -> link != NULL)
	{
		temp = ptr -> link;
		free(ptr);
		ptr = temp;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*a;

	a = s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (*a != (char)c)
	{
		if (*a == '\0')
		{
			return (NULL);
		}
		i++;
		a++;
	}
	return ((char *)(s + i));
}

struct s_reading	*new_struct(struct s_reading *last)
{
	struct s_reading	*ptr = NULL;

	free(last);
	return (ptr);
}

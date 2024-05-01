/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:16:41 by luribero          #+#    #+#             */
/*   Updated: 2024/05/01 20:52:20 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct s_reading	*n_read(struct s_reading *last, int fd, int *total)
{
	struct s_reading	*new;

	new = NULL;
	new = (struct s_reading *)malloc(sizeof(struct s_reading));
	if (new == NULL)
		return (NULL);
	last -> link = new;
	new -> link = NULL;
	new -> char_read = read(fd, new -> buff, BUFFER_SIZE);
	new -> buff[new -> char_read] = '\0';
	*total = *total + new -> char_read;
	return (new);
}

void	f_read(struct s_reading **head, struct s_reading **ptr, int fd,
			int *total)
{
	*head = (struct s_reading *)malloc(sizeof(struct s_reading));
	*ptr = *head;
	(*head)-> char_read = read(fd, (*head)-> buff, BUFFER_SIZE);
	(*head)-> buff[(*head)-> char_read] = '\0';
	*total = *total + (*head)-> char_read;
}

char	*concat(struct s_reading *init, int *len)
{
	char				*line = NULL;
	int					mover = 0;
	struct s_reading	*ptr = init;
	char				*start;

	line = (char *)malloc(sizeof(char) * (*len + 1));
	if (line == NULL)
		return (NULL);
	start = line;
	while ((*len > 0) && (ptr -> buff[mover] != '\n'))
	{
		if (ptr -> buff[mover] == '\0')
		{
			mover = 0;
			ptr = ptr -> link;
		}
		*line = ptr -> buff[mover];
		line++;
		mover++;
		*len = *len - 1;
	}
	line = end_string(ptr -> buff[mover], line, len);
	*line = '\0';
	return (start);
}

char	*get_next_line(int fd)
{
	static struct s_reading	*head = NULL;
	struct s_reading		*ptr = NULL;
	int						sum_char_read = 0;
	char					*line = NULL;

	if ((fd < 0) || (fd > (FD_SETSIZE - 1)) || (BUFFER_SIZE < 1))
		return (NULL);
	if (head != NULL)
	{
		ptr = head;
		sum_char_read = ptr -> char_read;
	}
	else
		f_read(&head, &ptr, fd, &sum_char_read);
	while ((!ft_strchr(ptr -> buff, '\n')) && (ptr -> char_read > 0))
		ptr = n_read(ptr, fd, &sum_char_read);
	line = concat(head, &sum_char_read);
	clean(head);
	if (sum_char_read > 0)
		head = fix(ptr, &sum_char_read);
	else
		head = new_struct(ptr);
	return (line);
}

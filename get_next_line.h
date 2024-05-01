/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:18:17 by luribero          #+#    #+#             */
/*   Updated: 2024/05/01 20:31:41 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// Include Libraries:
# include <stdlib.h>					//malloc, free
# include <unistd.h>					//write
# include <limits.h>					//LONG_MIN, INT_MAX, ULONG_MAX, etc
# include <fcntl.h>						//open
# include <stdio.h>						//testing
//# define BUFFER_SIZE 3 					//buffer size

# define GET_NEXT_LINE_H

struct s_reading
{
	char				buff [BUFFER_SIZE + 1];
	int					char_read;
	struct s_reading	*link;
};

char				*end_string(char a, char *line, int *len);

struct s_reading	*fix(struct s_reading *ptr, int *sum_char_read);

void				clean(struct s_reading *first);

char				*ft_strchr(const char *s, int c);

struct s_reading	*new_struct(struct s_reading *last);

struct s_reading	*n_read(struct s_reading *last, int fd, int *total);

void				f_read(struct s_reading **head, struct s_reading **ptr,
						int fd, int *total);

char				*concat(struct s_reading *init, int *len);

char				*get_next_line(int fd);

#endif

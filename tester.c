/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:51:46 by luribero          #+#    #+#             */
/*   Updated: 2024/04/30 23:56:27 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		times = 0;
	char	*line = NULL;
	int		round = 0;
	int		fd = 0;

	if (argc != 3)
	{
		printf ("Error!\n\tPlease provide 2 arguments.\n");
		printf ("\tA1:\tPath to file to read.\n");
		printf ("\tA2:\tNumber of lines to read.\n");
		return (1);
	}
	times = atoi(argv[2]);
	round = 1;
	fd = open(argv[1], O_RDONLY);
	while (times > 0)
	{
		line = get_next_line(fd);
		printf ("-line: %d-\n", round);
		if (line == 0)
		{
			printf ("-END OF DOCUMENT-\n");
			return (1);
		}
		printf("%s", line);
		times--;
		round++;
		printf("-end-\n\n");
	}
	close(fd);
	return (0);
}

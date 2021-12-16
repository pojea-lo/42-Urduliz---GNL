/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:58:58 by pojea-lo          #+#    #+#             */
/*   Updated: 2021/12/16 12:47:58 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
int	main(void)
{
	int			fd;
	int			j;
	char		*line;

	j = 0;
	fd = open ("multiple_line_with_nl", O_RDWR);
	line = "1";
	while (line != NULL)
	{
		j++;
		line = get_next_line (fd);
		printf("\n---------%d-----------\n", j);
		printf ("\n*-*-*-:  *-%s-*\n", line);
	}
	return (0);
}
*/
char	*get_next_line(int fd)
{
	char		*buf;
	char		*s;
	static char	*rest[4096];
	int			bread;

	bread = 1;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr (rest[fd], '\n') != 1 && bread != 0)
	{
		bread = read (fd, buf, BUFFER_SIZE);
		buf[bread] = '\0';
		if (bread == -1)
		{
			free (buf);
			return (NULL);
		}
		rest[fd] = ft_join (rest[fd], buf);
	}
	s = ft_line(rest[fd], buf, bread);
	rest[fd] = ft_updrest(rest[fd], bread);
	return (s);
}

char	*ft_line(char *rest, char *buf, int bread)
{
	int		i;
	char	*s;

	free (buf);
	i = 0;
	if (*rest != '\0' || bread != 0)
	{
		while (rest[i] != '\0')
		{
			if (rest[i] == '\n')
			{
				i++;
				s = ft_substr (rest, 0, i);
				return (s);
			}
			i++;
		}
		s = ft_substr (rest, 0, i);
	}
	else
		s = NULL;
	return (s);
}

char	*ft_updrest(char *rest, int bread)
{
	char	*des;
	size_t	i;

	i = 0;
	if (*rest != '\0' || bread != 0)
	{
		while (rest[i] != '\n' && rest[i] != '\0')
			i++;
		if (rest[i] == '\0')
		{
			free(rest);
			return (NULL);
		}
		else
			des = ft_copyrest(rest, i);
		free (rest);
	}
	else
	{
		free (rest);
		rest = NULL;
		return (NULL);
	}
	return (des);
}

char	*ft_copyrest(char *rest, size_t i)
{
	char	*des;
	int		j;

	j = 0;
	des = (char *)malloc (sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!des)
		return (NULL);
	while (i++ < (size_t) ft_strlen(rest))
		des[j++] = rest[i];
	des[j] = '\0';
	return (des);
}

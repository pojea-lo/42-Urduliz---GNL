/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:20:40 by pojea-lo          #+#    #+#             */
/*   Updated: 2021/12/13 10:27:04 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strchr(char *s, char c);
int		ft_strlen(char *str);
char	*ft_line(char *rest, char *buf, int bread);
char	*ft_updrest(char *rest, int bread);
void	*ft_memcpy(void *dest, const void *org, size_t n);
char	*ft_copyrest(char *rest, size_t i);

#endif

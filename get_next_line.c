/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:08:48 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:48:29 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_remember_text(int fd, char *remember)
{
	int		bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 1 + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_strchr_checker(remember))
	{
		bytes = read(fd, buf, 1);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		remember = ft_strjoin_checker(remember, buf);
	}
	free(buf);
	return (remember);
}

char	*ft_copy(char *remember)
{
	char	*line;
	int		bytes;

	bytes = 0;
	if (!(*remember))
		return (NULL);
	while (remember[bytes] && remember[bytes] != '\n')
		bytes++;
	line = (char *)malloc(sizeof(char) * (bytes + 2));
	if (line)
	{
		bytes = 0;
		while (*remember && *remember != '\n')
			line[bytes++] = *remember++;
		if (*remember == '\n')
			line[bytes++] = '\n';
		line[bytes] = '\0';
		return (line);
	}
	return (NULL);
}

char	*ft_new_remember(char *remember)
{
	int		i;
	int		j;
	char	*new_remember;

	i = 0;
	j = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (!remember[i])
	{
		free(remember);
		return (NULL);
	}
	new_remember = malloc(sizeof(char) * (ft_strlen_checker(remember) - i + 1));
	if (new_remember)
	{
		i++;
		while (remember[i])
			new_remember[j++] = remember[i++];
		new_remember[j] = '\0';
		free(remember);
		return (new_remember);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remember;

	if (fd < 0)
		return (NULL);
	remember = ft_remember_text(fd, remember);
	if (!remember)
		return (NULL);
	line = ft_copy(remember);
	remember = ft_new_remember(remember);
	return (line);
}

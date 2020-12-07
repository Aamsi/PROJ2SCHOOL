/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:44:48 by iouali            #+#    #+#             */
/*   Updated: 2020/12/07 19:50:12 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			read_file(int fd, char **tmp_char)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (!ft_strchr(*tmp_char, '\n') && ret > 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		if (*tmp_char == 0)
			*tmp_char = ft_strdup(buff);
		else
			*tmp_char = ft_strjoin(*tmp_char, buff);
	}
	return (ret);
}

int			ft_strlen_nl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char		*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char		*ft_strdup(char *s)
{
	size_t	i;
	char	*tmp_s;
	char	*result;

	result = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!result)
		return (NULL);
	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i])
	{
		result[i] = tmp_s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int			get_next_line(int fd, char **line)
{
	static char		*tmp_char[256];
	int				ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if ((ret = read_file(fd, &tmp_char[fd])) == -1)
		return (free_for_all(tmp_char[fd], *line));
	if (!(*line = ft_strndup(tmp_char[fd], ft_strlen_nl(tmp_char[fd]))))
		return (free_for_all(tmp_char[fd], *line));
	if (!(tmp_char[fd] = delete_former_str(tmp_char[fd], '\n')))
		return (free_for_all(tmp_char[fd], *line));
	if (ret == 0)
	{
		free(tmp_char[fd]);
		tmp_char[fd] = NULL;
		return (0);
	}
	return (1);
}

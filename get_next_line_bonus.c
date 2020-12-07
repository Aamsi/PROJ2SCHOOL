/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:09:44 by iouali            #+#    #+#             */
/*   Updated: 2020/12/07 18:12:23 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	if (!s)
		return (NULL);
	tmp_s = (char *)s;
	i = 0;
	while (i < ft_strlen(tmp_s) + 1)
	{
		if (tmp_s[i] == (unsigned char)c)
			return (tmp_s + i);
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

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	if ((ret = read_file(fd, &tmp_char[fd])) == -1)
		return (-1);
	if (!(*line = ft_strndup(tmp_char[fd], ft_strlen_nl(tmp_char[fd]))))
		return (-1);
	if (!(tmp_char[fd] = delete_former_str(tmp_char[fd], '\n')))
		return (-1);
	if (ret == 0)
	{
		free(tmp_char[fd]);
		tmp_char[fd] = NULL;
		return (0);
	}
	return (1);
}
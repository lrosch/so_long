/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:46:12 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/27 14:30:46 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** helper function that checks if a newline is in the read 
** string
*/

int	ft_check(char **str, int check, int fd)
{	
	int	i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0' && i < 10)
	{
		i++;
		if (str[fd][i] == '\n')
			check = 1;
	}
	return (check);
}

/*
** little helper function that frees the string and sets it to 
** NULL when the file is completely read
*/

void	setnull(char **str, int fd)
{
	free(str[fd]);
	str[fd] = NULL;
}

/*
** function that extracts the line with newline from the static string
** first it goes to the newline and marks the position of it in the array
** after that it extracts the line from the string and deletes the newline
** from the string via temporary string
*/

char	*ft_getline(char **str, int fd)
{
	int		i;
	int		len;
	char	*line;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != 0)
		i++;
	len = ft_strlen(str[fd]);
	if (str[fd][i] == '\n')
	{
		line = ft_substr(str[fd], 0, i + 1);
		tmp = ft_substr(str[fd], i + 1, len);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			setnull(str, fd);
	}
	else
	{
		line = ft_substr(str[fd], 0, len);
		setnull(str, fd);
	}
	return (line);
}

/*
** function that assigns the read buffer to the static string 
** and returns 0 if it was successful and 1 if it wasn't
*/

int	ft_assign(int readl, char **str, char *buf, int fd)
{
	char	*tmp;

	if ((readl == 0 && str[fd] == NULL) || readl < 0)
	{
		free(buf);
		return (1);
	}
	buf[readl] = '\0';
	if (str[fd] == NULL)
		str[fd] = ft_substr(buf, 0, readl + 1);
	else
	{
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	return (0);
}

/*
** main get_next_line function that reads lines into buf 
** as long as it A. doesn't find a newline in said buf
** or B. hits the end of file
*/

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buf;
	int			readl;
	int			check;

	check = 0;
	readl = 1;
	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(10 + 1);
	if (buf == NULL)
		return (NULL);
	while (readl > 0 && check == 0)
	{
		readl = read(fd, buf, 10);
		if (ft_assign(readl, str, buf, fd) == 1)
			return (NULL);
		check = ft_check(str, check, fd);
	}
	free (buf);
	return (ft_getline(str, fd));
}

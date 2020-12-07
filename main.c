#include "get_next_line.h"

int main()
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;

	char *line;

	line = '\0';
	fd1 = open("text1.txt", O_RDONLY);
	if(fd1 == -1)
	{
		printf("Open failed\n");
		return (-1);
	}
	fd2= open("text2.txt", O_RDONLY);
	if(fd2 == -1)
	{
		printf("Open failed\n");
		return (-1);
	}
	fd3 = open("text3.txt", O_RDONLY);
	if(fd3 == -1)
	{
		printf("Open failed\n");
		return (-1);
	}
	fd4 = open("text.txt", O_RDONLY);
	if(fd4 == -1)
	{
		printf("Open failed\n");
		return (-1);
	}
	printf("fd 1: retour gnl = %i\n", get_next_line(fd1, &line));
	printf("fd 1: line = %s\n", line);
	free(line);
	printf("fd 2: retour gnl = %i\n", get_next_line(fd2, &line));
	printf("fd 2:line = %s\n", line);
	free(line);
	printf("fd 3:retour gnl = %i\n", get_next_line(fd3, &line));
	printf("fd 3:line = %s\n", line);
	free(line);
	printf("fd 4:retour gnl = %i\n", get_next_line(fd4, &line));
	printf("fd 4:line = %s\n", line);
	free(line);
	printf("fd 1:retour gnl = %i\n", get_next_line(fd1, &line));
	printf("fd 1:line = %s\n", line);
	free(line);
	printf("fd 2:retour gnl = %i\n", get_next_line(fd2, &line));
	printf("fd 2:line = %s\n", line);
	free(line);
	printf("fd 3:retour gnl = %i\n", get_next_line(fd3, &line));
	printf("fd 3:line = %s\n", line);
	free(line);
	printf("fd 4:retour gnl = %i\n", get_next_line(fd4, &line));
	printf("fd 4:line = %s\n", line);
	free(line);
	if(close(fd1) == -1)
		return (-1);
	if(close(fd2) == -1)
		return (-1);
	if(close(fd3) == -1)
		return (-1);
	if(close(fd4) == -1)
		return (-1);
	return (0);
}
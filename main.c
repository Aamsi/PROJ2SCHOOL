#include "get_next_line.h"

int     main(int argc, char **argv)
{
    int fd;
    char *line = 0;
    int ret;

    line = 0;
    if (argc == 1)
        fd = 0;
    else
        fd = open(argv[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
	    printf("line = [%s] / ret: %d\n", line, ret);
        free(line);
    }
    free(line);
    // ret = get_next_line(-1, &line);
    // printf("line = [%s] / ret: %d\n", line, ret);
    // free(line);
}
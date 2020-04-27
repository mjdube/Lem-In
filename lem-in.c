#include "src/lem_in.h"
#include "libft/libft.h"

int         main(int argc, char **argv)
{
    char    *line;
    int     fd;

    fd = 1;

    while (get_next_line(fd, &line))
    {
        ft_putstr_fd(&line, fd);
    }
    return (0);
}
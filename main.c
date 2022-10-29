#include "cub3d.h"

int main(int argc, char **argv)
{
    char *line = NULL;
    int fd;
    if (argc != 2)
        print_error("Invalid arguments ");
    if (!check_map_ext(argv[1]))
        print_error("Invalid map !");
    fd = open(argv[1], O_RDONLY);
    if ( fd == -1)
        print_error("Cannot open the map ");
    while(1)
    {
        line = get_next_line(fd);
        if (line && !ft_strchr(line, '\n'))
			break ;
        else if (!line)
            print_error("Empty map ");
        else if (line[0] == '\n')
            print_error("New line ");
        free(line);

    }
}
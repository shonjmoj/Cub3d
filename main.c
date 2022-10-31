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
        print_error("Cannot open this file ");
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        else if (!valid_texture(line))
            print_error("Invalid type ");
        else if (valid_texture(line) == -1)
            print_error("hhhhhhhh ");
        // printf("%s", line);
        free(line);
    }
    // while (1)
    // {
    //     /* code */
    // }
    
}
#include "cub3d.h"

int main(int argc, char **argv)
{
    char *line = NULL;
    int fd;
    t_map map;

    init_map(&map);
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
        if (!valid_side(line) || !get_textures(line, &map))
            print_error("Invalid texture !");
        free(line);
    }
    if (!completed_textures(&map))
        print_error("Missed texture !");
    // while(1){}
}
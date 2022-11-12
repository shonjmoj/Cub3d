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
        if (line[0] != '\n')
            get_textures(line, &map);
        free(line);
    }
    if (!completed_textures(&map) || !get_colors(&map))
        print_error("texture error !");
    printf("floor %s\nceilling %s\nc_red %d\nc_green %d\nc_blue %d\nf_red %d\nf_green %d\nf_blue %d\n",map.floor, map.ceilling, map.colors.c_red, map.colors.c_green, map.colors.c_blue, map.colors.f_red, map.colors.f_green, map.colors.f_blue);
    while(1){}
}
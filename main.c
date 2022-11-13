#include "cub3d.h"



int main(int argc, char **argv)
{
    t_map map;
    int fd;
    
    if (argc != 2)
        print_error("Invalid arguments ");
    if (!check_map_ext(argv[1]))
        print_error("Invalid map !");
    fd = open(argv[1], O_RDONLY);
    if ( fd == -1)
        print_error("Cannot open this file ");
    if (!valid_parsing(&map, fd) || !completed_config(&map)) {
        print_error("Invalid config ");
    }
    while(1){}
}
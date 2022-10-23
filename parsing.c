#include "cub3d.h"

char *get_ext(char *filename)
{
    int i;
    int j;
    char *ext;

    i = 0;
    ext = NULL;
    j = ft_strlen(filename);
    while (filename[j - 1] >= 0)
    {
        if (filename[j - 1] == '.')
        {
            j--;
            break;
        }
        j--;
    }
    ext = malloc(sizeof(char) * (j + 2));
    while (filename[i + j])
    {
        ext[i] = filename[i + j];
        i++;
    }
    ext[i] = '\0';
    return (ext);
}

int check_map_ext(char *filname)
{
    char *ext;

    if (ft_strnstr(filname, ".cub", ft_strlen(filname)) == NULL)
        return (0);
    ext = get_ext(filname);
    if (ft_strncmp(".cub", ext, ft_strlen(".cub")) != 0 || *filname == '.')
    {
        free(ext);
        return (0);
    }
    free(ext);
    return (1);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;
    if (check_map_ext(argv[1]))
    {
        printf("OK\n");
        return (0);
    }
    else
    {
        printf("KO\n");
        return 1;
    }
    return (0);
}
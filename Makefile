NAME = cub3D

FLAGS = -Wall -Wextra -Werror -fsanitize=address

INCLUDES = cub3d.h
		
SRC = config_parsing_utils2.c \
		get_next_line.c \
		map_parsing.c \
        config_parsing.c \
		main.c \
		map_parsing_utils.c \
        config_parsing_utils.c \
		error.c \
		map_parsing_utils2.c \
		key_hook.c \
		handel_map_2.c \
		drawing_field_of_view.c \
		raycasting_1.c \
		raycasting_2.c \
		our_put_pixel.c \
		check_walls.c \
		render.c \
		render_wall.c \
		get_textures_data.c

	

OBJECTS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	cd ./Libft && make && cd ..	
	@$(CC) $(FLAGS) -lmlx -lm -framework OpenGL -framework AppKit Libft/libft.a $(OBJECTS) -o $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(FLAGS) -Imlx -Ofast  -c $< -o $@


clean:
	@rm -rf $(OBJECTS)  

fclean: clean
	cd Libft && make fclean && cd ..
	rm -rf $(NAME)

re: fclean all
NAME = RT

CPP = gcc

SDLFLAGS = -framework SDL2 -F ./frameworks

SDL2_HEADER = -I ./frameworks/SDL2.framework/Headers/

SDL2_P = -rpath @loader_path/frameworks/

CFLAGS = -Wall -Wextra -Werror

HEADER = includes

SOURCES = main.c			\
		  	sdl_quit.c 			\
		  	ft_cone.c			\
		  	ft_img.c			\
			ft_cylinder.c		\
		 	ft_damier.c			\
		  	ft_light.c			\
		  	ft_plan.c			\
		 	ft_prep_shadow.c	\
		  	ft_reflection.c		\
		  	ft_rt.c				\
		  	ft_shadow.c			\
		  	ft_sphere.c			\
			ft_init.c 			\
			ft_parse.c 			\
			ft_parse_camera.c 	\
			ft_parse_cone.c 	\
			ft_parse_cylinder.c \
			ft_parse_light.c 	\
			ft_parse_main_properties.c \
			ft_parse_plane.c 	\
			ft_parse_sphere.c 	\
			ft_parse_tools.c 	\
			ft_concat_c_params.c \
			ft_tools.c \
			ft_texture.c				\
			ft_tools_2.c				\
			sepia.c						\
			red.c						\
			green.c						\
			yellow.c					\
			negative.c					\
			export.c					\

DIR_O = obj

DIR_S = srcs

LIB = libft

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

${NAME}: $(OBJS)
	@make -C $(LIB)
	@${CPP} $(CFLAGS) -o $@ $^ -L $(LIB) $(SDL2_P) $(SDLFLAGS) $(SDL2_HEADER) ./libft/libft.a

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(CPP) $(CFLAGS) -I $(HEADER) $(SDL2_HEADER) -c -o $@ $<

obj:
	mkdir -p obj

clean:
	rm -rf obj
	make -C $(LIB) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB) fclean

re: clean fclean all

.PHONY: all $(NAME)

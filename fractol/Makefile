
CFLAGS = -Wall -Werror -Wextra

CC = gcc
NAME = fractol

SRC = events.c init.c main.c math_utils.c render.c render2.c string_utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo " "
	@echo "$(GRAY)Dossier obj créé.$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo " "
	@echo "$(GREEN)Compilation terminée -> $(NAME)$(RESET)"
	@echo " "
	@echo "$(GREEN)1 -> ./fractol mandelbrot$(RESET)"
	@echo "$(GREEN)2 -> ./fractol julia -0.8 +0.156$(RESET)"
	@echo " "

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)Fichier $@ $(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GRAY)Dossier obj et fichiers objets supprimés.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)Exécutable supprimé.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

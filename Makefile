# *******************************************************
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 11:49:35 by uolle             #+#    #+#              #
#    Updated: 2023/12/14 11:50:13 by uolle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR       = includes
SRCSDIR      = srcs
LIBSDIR      = libs
OBJDIR       = objs

SRC_FILES = $(wildcard $(SRCSDIR)/*.c)
OBJ_FILES = $(patsubst $(SRCSDIR)/%.c,$(OBJDIR)/%.o,$(SRC_FILES))

CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
INC_FLAGS = -I $(HDRDIR)
RM = rm -rf
MKDIR = mkdir -p

NAME = push_swap

COLOR_RESET = \033[0m
COLOR_INFO = \033[0;94m
COLOR_SUCCESS = \033[0;92m

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(COLOR_INFO)Linking: $(NAME) $(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJ_FILES) -L$(LIBSDIR) -lft -o $(NAME)
	@echo "$(COLOR_SUCCESS)$(NAME) has been successfully compiled$(COLOR_RESET)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR) libft
	@echo "$(COLOR_INFO)Compiling: $< $(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJDIR):
	@$(MKDIR) $(OBJDIR)

libft:
	@make -C $(LIBSDIR)

clean:
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBSDIR)
	@echo "$(COLOR_INFO)$(NAME) object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_SUCCESS)$(NAME) executable has been cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_SUCCESS)Cleaned and rebuilt successfully!$(COLOR_RESET)"


## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: uolle <uolle>                              +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2023/12/05 19:59:58 by uolle             #+#    #+#             ##
##   Updated: 2023/12/05 20:04:56 by uolle            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

# -- Variables
HDRDIR       = includes
SRCSDIR      = srcs
LIBSDIR      = libs
OBJDIR			 = objs

SRC_FILES = $(wildcard $(SRCSDIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)

CC = cc
CFLAG = -Wall -Werror -Wextra
INC_FLAGS = -I $(HDRDIR)
RM = rm -rf
MKDIR = mkdir -p

NAME = push_swap

COLOR_RESET = \033[0m
COLOR_INFO = \033[0;94m
COLOR_SUCCESS = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@cp $(LIBSDIR)/libft.a .
	@mv libft.a $(NAME)
	@$(CC) $(CFLAGS) -I $(HDRDIR) $(OBJS) $(LIBSDIR)/libft.a -o $(NAME)
	@echo "$(COLOR_SUCCESS)ft_printf has been successfully compiled$(COLOR_RESET)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@make -C $(LIBSDIR)
	@mkdir -p $(OBJDIR)
	@echo "$(COLOR_INFO)Compiling: $< $(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FILES)
	@make clean -C $(LIBSDIR)
	@echo "$(COLOR_INFO)$(NAME) object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -f $(LIBSDIR)/libft.a
	@echo "$(COLOR_SUCCESS)$(NAME) executable has been cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_SUCCESS)Cleaned and rebuilt successfully!$(COLOR_RESET)"

.PHONY: all clean fclean re

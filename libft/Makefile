# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/12/02 14:03:20 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Library name
NAME     = libft.a

# Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
YELLOW2  = \033[1;33m
NC       = \033[0m

# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
AR       = ar -rsc

# Includes
INCLUDES = -I includes/

# Source files
SRC_DIR  = srcs/
SRCS     = fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c fd/ft_putstr_fd.c                                                                                                                                                                                            \
           memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c                                                                                                                                 \
           lists/ft_lstnew_bonus.c lists/ft_lstadd_front_bonus.c lists/ft_lstsize_bonus.c lists/ft_lstlast_bonus.c lists/ft_lstadd_back_bonus.c lists/ft_lstdelone_bonus.c lists/ft_lstclear_bonus.c lists/ft_lstiter_bonus.c lists/ft_lstmap_bonus.c lists/ft_lstdelmiddle.c   \
           char/ft_tolower.c char/ft_toupper.c char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c char/ft_isdigit.c char/ft_isprint.c                                                                                                                                        \
           str/ft_atoi.c str/ft_itoa.c str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c str/ft_substr.c \
		   printf/ft_printf.c printf/ft_print_content.c                                                                                                                                                                                                                         \
		   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# Object files directory
OBJ_DIR  = .obj/
OBJ      = $(SRCS:%.c=$(OBJ_DIR)%.o)

# Remake all if modified
REMAKE   = includes/libft.h includes/ft_printf.h Makefile

# Pattern rule for object files
$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(REMAKEALL)
	@mkdir -p $(dir $@)
	@echo "$(GREEN)[Compiling] $(NC)$<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

all : start_message $(NAME)

start_message:
	@if [ ! -f $(NAME) ] || [ `for file in $(SRCS); do find $(SRC_DIR)$$file -newer $(NAME); done` ]; then \
		echo "$(YELLOW)Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...\n$(NC)";                                            \
	fi

end_message:
	@echo "$(YELLOW)\nCompilation of $(YELLOW2)$(NAME)$(YELLOW) finished successfully!$(NC)"; \

$(NAME) : $(OBJ)
	@echo "$(GREEN)[Creating library] $(NC)$(NAME)"
	@$(AR) $@ $?
	@make end_message

clean :
	@echo "$(RED)[Removing] $(NC)libft object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@echo "$(RED)[Removing] $(NC)library $(NAME)"
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re start_message end_message

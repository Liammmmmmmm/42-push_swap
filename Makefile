# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:16:20 by lilefebv          #+#    #+#              #
#    Updated: 2024/12/10 16:44:39 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Program name
NAME     = push_swap
BONUS    = checker

# Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
YELLOW2  = \033[1;33m
NC       = \033[0m

# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g3

# libft
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)/libft.a

# Includes
INCLUDES = -I includes/ -I $(LIBFTDIR)includes/

# Source files
SRC_DIR  = srcs/
SRCS     = push_swap.c args.c maths.c  \
           stacks/circular_buffer.c stacks/init.c stacks/instr_p.c stacks/instr_r.c stacks/instr_rr.c stacks/instr_s.c stacks/conditions.c stacks/get_number.c stacks/index.c \
           sort/first_sort.c sort/utils.c sort/sort.c sort/controls.c sort/radix.c sort/mysort.c sort/mysort_little.c sort/mysort_utils.c sort/bubble.c sort/basics_a.c sort/basics_b.c sort/is_sorted.c \
           sort/bbeg/bbeg_sort.c sort/bbeg/bbeg_bubble.c sort/bbeg/bbeg_from_a.c sort/bbeg/bbeg_from_b.c sort/bbeg/bbeg_lists.c sort/bbeg/bbeg_utils.c

SRCS_BONUS = stacks/circular_buffer.c stacks/init.c stacks/instr_p.c stacks/instr_r.c stacks/instr_rr.c stacks/instr_s.c stacks/conditions.c stacks/get_number.c stacks/index.c \
             checker/checker.c args.c sort/is_sorted.c

# Object files directory
OBJ_DIR   = .obj/
OBJ       = $(SRCS:%.c=$(OBJ_DIR)%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)%.o)

# Remake all if modified
REMAKE   = libft/includes/libft.h libft/includes/ft_printf.h libft/includes/get_next_line.h libft/Makefile  \
           Makefile includes/push_swap.h includes/stacks.h includes/sort.h
ALGO_DEP = .algo_dep

# NORMINETTE
NORM_RET = Norminette ERROR
NORM	 = $(shell norminette | grep -c 'Error!')
ifeq ($(NORM), 0)
	NORM_RET = $(GREEN)[DONE] $(YELLOW2)Norminette.$(NC)
else
	NORM_RET = $(RED)[ERROR] $(YELLOW2)Norminette.$(NC)
endif

# Pattern rule for object files
$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(REMAKE)
	@mkdir -p $(dir $@)
	@echo "$(GREEN)[Compiling] $(NC)$<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

all : libft_make start_message $(NAME)

start_message:
	@if [ ! -f $(NAME) ] || [ `for file in $(SRCS); do find $(SRC_DIR)$$file -newer $(NAME); done` ] || [ $(LIBFT) -nt $(NAME) ] || [ -f $(ALGO_DEP) ]; then \
		echo "$(YELLOW)Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...\n$(NC)";                                                     \
	else                                                                                                                               \
		echo "$(YELLOW)Nothing to be done for $(YELLOW2)$(NAME)$(NC)";                                                                 \
	fi
	@if [ -f $(ALGO_DEP) ]; then \
		touch srcs/sort/sort.c; \
	fi

end_message:
	@echo "$(YELLOW)\nCompilation of $(YELLOW2)$(NAME)$(YELLOW) finished successfully!$(NC)";
	@echo "\n$(NORM_RET)";
	@rm -f $(ALGO_DEP)

$(NAME) : ${LIBFT} $(OBJ)
	@echo "$(GREEN)[Compiling program] $(NC)$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTDIR)libft.a
	@make --no-print-directory end_message

libft_make:
	@make --no-print-directory -C $(LIBFTDIR) all

clean :
	@make --no-print-directory -C $(LIBFTDIR) clean
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

rmprogram :
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi

fclean : clean rmprogram
	@make --no-print-directory -C $(LIBFTDIR) fclean
	@if [ -f $(BONUS) ]; then \
		echo "$(RED)[Removing] $(NC)program $(BONUS)"; \
		rm -f $(BONUS); \
    fi

re : fclean all

touchsort :
	@touch srcs/sort/sort.c

$(ALGO_DEP):
	@touch $(ALGO_DEP)

radix: CFLAGS += -D ALGO=1
radix: touchsort $(NAME)
	@touch $(ALGO_DEP)
.PHONY: radix

mysort: CFLAGS += -D ALGO=2
mysort: touchsort $(NAME)
	@touch $(ALGO_DEP)
.PHONY: mysort

mylittle: CFLAGS += -D ALGO=3
mylittle: touchsort $(NAME)
	@touch $(ALGO_DEP)
.PHONY: mylittle

bbeg: CFLAGS += -D ALGO=4
bbeg: touchsort $(NAME)
	@touch $(ALGO_DEP)
.PHONY: bbeg

bubble: CFLAGS += -D ALGO=5
bubble: touchsort $(NAME)
	@touch $(ALGO_DEP)
.PHONY: bubble

bonus : libft_make $(BONUS)

$(BONUS) : ${LIBFT} $(OBJ_BONUS)
	@echo "$(GREEN)[Compiling program] $(NC)$(BONUS)"
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS) $(LIBFTDIR)libft.a
	@echo "$(YELLOW)\nCompilation of $(YELLOW2)$(BONUS)$(YELLOW) finished successfully!$(NC)";
	@echo "\n$(NORM_RET)";

.PHONY: all clean fclean re start_message end_message libft_make bonus rmprogram touchsort

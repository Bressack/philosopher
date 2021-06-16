# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 16:56:08 by tharchen          #+#    #+#              #
#    Updated: 2021/06/16 02:52:41 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

UNAME_S			=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CC			=	clang-9
else
	CC			=	clang
endif

# FLAGS			=	-Wall -Wextra -Werror -Ofast
FLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

# **************************************************************************** #

HEADER_DIR		=	includes/

HEADER_LIST		=	\
					philo.h	\
					color_shell.h	\

HEADER			=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

# **************************************************************************** #

SRCS_DIR		=	srcs/

SRCS_LIST		=	\
					main.c \
					error.c \
					init.c \
					simulation.c \
					eatting.c \
					tools.c \
					utils.c \

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# **************************************************************************** #

OBJS_DIR		=	objs/

OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ $(CC) $(FLAGS) $(HDIR) $(OBJS) -pthread -o $@ -I $(HEADER_DIR)
	@ printf "\033[31mProgram \033[32m%s: \033[34mCompilation \033[36m%-30s\033[0m\n" $(NAME) "succeed !"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(OBJS_DIR)
	@ $(CC) $(FLAGS) -pthread -I $(HEADER_DIR) -c -o $@ $<
	@ printf "\033[31mProgram \033[32m%s: \033[34mCompilation of \033[36m%-30s\033[0m\r" $(NAME) $(notdir $<)

norm:
	norminette $(SRCS) $(HEADER)

clean:
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

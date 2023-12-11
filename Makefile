# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:44:46 by avolcy            #+#    #+#              #
#    Updated: 2023/12/11 16:11:47 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -rf
EXEC = fractol
NAME = .fractol.a
HEADER = fractol.h
BUILT_LIB = ar rcs
FLAG = -Wall -Wextra -Werror -Imlx 
MLXFLAG =  -Lmlx -lmlx -framework OpenGL -framework AppKit

#========|_PATH_|===========#
INC = ./inc/$(HEADER)
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
MLXDIR = ./mlx/
MLX = $(MLXDIR)libmlx.a
SRCD = srcs/
OBJD = .temp/
#___________________________#

#========|_SCRS_|===========#
SRC = $(SRCD)fractol.c $(SRCD)initializing.c $(SRCD)julia.c


OBJ = $(addprefix $(OBJD), $(SRC:$(SRCD)%.c=%.o))

#=======|_TARGETS_|======#

all : $(EXEC)

.temp :
	@mkdir -p .temp
#________________________#
$(LIBFT):
	@$(MAKE) -C $(LIBDIR) $(SIL)

$(MLX) :
	@$(MAKE) -C $(MLXDIR) $(SIL)
#-----------------------------#

$(OBJD)%.o: $(SRCD)%.c | .temp #$(SRC) 
	$(CC) $(FLAG) -c -o $@ $< 
#========================================#
$(EXEC) : $(NAME) $(LIBFT) $(MLX) 
	$(CC) $(MLXFLAG) $^ -o $@

$(NAME) : $(OBJ) $(INC) Makefile 
	$(BUILT_LIB) $@ $^
#----------------------------------------#

.PHONY: all clean fclean re

#==========|_CLEAN_UP_|========#
clean :
	@$(MAKE) clean -C $(LIBDIR)
	@$(MAKE) clean -C $(MLXDIR)
	@$(RM) $(OBJD) 

fclean : clean 
	@$(RM) $(OBJD) 
	@$(RM) $(EXEC) $(NAME) 
	@$(MAKE) fclean -C $(LIBDIR)
	@$(MAKE) fclean -C $(LIBDIR)

re : fclean all
#-----------------------------------------------------#
#----|_COLORS_|-----#
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"
M = "\033[35m"
C = "\033[36m"
W = "\033[37m"
DEF = "\033[39m"
GRAY = "\033[30m"
SEQ = "\033[2K\r"
SIL = --no-print-directory
#------------------#

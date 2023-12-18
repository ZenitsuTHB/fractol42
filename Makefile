# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:44:46 by avolcy            #+#    #+#              #
#    Updated: 2023/12/18 14:12:39 by avolcy           ###   ########.fr        #
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
SRC = $(SRCD)fractol.c $(SRCD)initializing.c $(SRCD)julia.c $(SRCD)mandelbrot.c \
	  $(SRCD)tricorn.c $(SRCD)hooks.c

OBJ = $(addprefix $(OBJD), $(SRC:$(SRCD)%.c=%.o))

#=======|_TARGETS_|======#

all : $(EXEC)

.temp :
	@mkdir -p .temp
#________________________#
$(LIBFT):
	@$(MAKE) -s -C $(LIBDIR) --no-print-directory
	@$(MSG_LIB) 

$(MLX) :
	@$(MAKE) -s -C $(MLXDIR) --no-print-directory
#-----------------------------#

$(OBJD)%.o: $(SRCD)%.c $(INC) | .temp #$(SRC) 
	@$(CC) $(FLAG) -c -o $@ $<

#========================================#
$(EXEC) : $(NAME) $(LIBFT) $(MLX) 
	@$(CC) $(MLXFLAG) $^ -o $@
	@$(MSG_EXE)

$(NAME) : $(OBJ) $(INC) $(MLX) Makefile  
	@$(BUILT_LIB) $@ $^
#----------------------------------------#

.PHONY: all clean clean1 fclean re

#==========|_CLEAN_UP_|========#	
clean : 
	@$(RM) $(OBJD)
	@$(MAKE) clean -C $(LIBDIR) --no-print-directory
	@$(MAKE) clean -C $(MLXDIR) --no-print-directory
	@$(MSG_CLEAN) 

fclean : clean 
	@$(RM) $(OBJD) 
	@$(RM) $(EXEC) $(NAME) 
	@$(MAKE) fclean -C $(LIBDIR) --no-print-directory
	@$(MAKE) fclean -C $(MLXDIR) --no-print-directory
	@$(MSG_FCLEAN) 

re : fclean all
#-----------------------------------------------------#
#----|_COLORS_|-----#
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
M = \033[35m
C = \033[36m
W = \033[37m
DEF = \033[39m
GRAY = \033[30m
SEQ = \033[2Kr
#------------------#


#---|_MESSAGES_|---#
MSG_LIB = @echo "$(G)LIBFT COMPILED SUCCESSFULLY !$(DEF)"
MSG_EXE = @echo "$(G)EXECUTABLE CREATED SUCCESSFULLY !$(DEF)"
MSG_CLEAN = @echo "$(R)ALL OBECTS DELETED SUCCESSFULLY !$(DEF)"
MSG_FCLEAN = @echo "$(M)ALL LIBRARIES AND EXECUTABLES DELETED SUCCESSFULLY !$(DEF)"

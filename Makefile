# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 14:29:20 by lpilotto          #+#    #+#              #
#    Updated: 2016/04/26 14:34:44 by lpilotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OUT=LINUX
OUT=MAC
NAME=wolf3d
SRCFOLDER=src/
SRCFILES=program.c \
		 binary_reader.c \
		 game.c \
		 game2.c \
		 graphic_helper.c \
		 key_hook.c \
		 loop_hook.c \
		 map.c \
		 parse.c \
		 parse_tex.c \
		 parse_tiles.c \
		 vector2.c
OBJFOLDER=obj/
INCLUDEFOLDER=./include
OBJ=$(addprefix $(OBJFOLDER),$(subst .c,.o,$(SRCFILES)))
SRC=$(addprefix $(SRCFOLDER),$(SRCFILES))

LIBFTFOLDER=./libft
LIBFT=$(LIBFTFOLDER)/libft.a

LIBSDLFOLDER=./SDL2-2.0.4
LIBSDL=$(LIBSDLFOLDER)/build/libSDL2main.a
LIBSDLMAKEFILE=$(LIBSDLFOLDER)/Makefile

ifeq ($(OUT),MAC)
DYNSDL=libSDL2-2.0.0.dylib
CPLIB=cp $(LIBSDLFOLDER)/build/.libs/$(DYNSDL) .
EDITLIB=install_name_tool -change /usr/local/lib/$(DYNSDL) @executable_path/$(DYNSDL) $(NAME)
else
DYNSDL=libSDL2-2.0.so.0
CPLIB=cp $(LIBSDLFOLDER)/build/.libs/$(DYNSDL) .
PATHSOSDLGCC=-Wl,-R`pwd`/$(LIBSDLFOLDER)/build/.libs
endif

EFLAGS=-Wall -Werror -Wextra -g
IFLAGS=-I$(LIBFTFOLDER) -I$(INCLUDEFOLDER) -I$(LIBSDLFOLDER)/include
LFLAGS=-L$(LIBFTFOLDER) -lft -lm $(PATHSOSDLGCC) -L`pwd`/$(LIBSDLFOLDER)/build/.libs -lSDL2  

.PHONY: all cleanwolf clean fclean re norme rewolf

$(NAME): $(LIBFT) $(OBJ) $(DYNSDL)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)
	$(EDITLIB)

all: $(NAME)

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	@if ! [ -d "$(OBJFOLDER)" ]; then mkdir $(OBJFOLDER); fi
	gcc -c $< $(EFLAGS) $(IFLAGS) -o $@

$(LIBSDL): $(LIBSDLMAKEFILE)
	make -C $(LIBSDLFOLDER)
	
$(DYNSDL): $(LIBSDL)
	$(CPLIB)

$(LIBSDLMAKEFILE):
	echo $(LIBSDLMAKEFILE)
	cd $(LIBSDLFOLDER) && ./configure

$(LIBFT):
	make -C $(LIBFTFOLDER) all

cleanwolf:
	rm -f $(NAME)

clean:
	rm -rf $(OBJFOLDER)
	make -C $(LIBFTFOLDER) clean
	make -C $(LIBSDLFOLDER) clean

fclean: cleanwolf clean
	rm -f $(DYNSDL)
	make -C $(LIBFTFOLDER) fclean
	make -C $(LIBSDLFOLDER) distclean

re: fclean all

norme:
	norminette src include libft/*.[ch]

rewolf: cleanwolf all

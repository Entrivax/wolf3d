# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 14:29:20 by lpilotto          #+#    #+#              #
#    Updated: 2016/05/09 15:29:30 by lpilotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OUT=LINUX
OUT=MAC
COMPILE_SDL=NO

NAME=wolf3d
SRCFOLDER=src/
SRCFILES=program.c \
		 binary_reader.c \
		 init.c \
		 game.c \
		 game2.c \
		 graphic_helper.c \
		 key_hook.c \
		 loop_hook.c \
		 map.c \
		 parse.c \
		 parse_tex.c \
		 parse_tiles.c \
		 str_helpers.c \
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

ifeq ($(COMPILE_SDL),NO)
IFLAGS=-I$(LIBFTFOLDER) -I$(INCLUDEFOLDER) -I./SDL2.framework/Headers
LFLAGS=-L$(LIBFTFOLDER) -lft -lm -L./SDL2.framework/Versions/Current -F. -framework SDL2 -framework Cocoa
EDITLIB=install_name_tool -change @executable_path/../Frameworks/SDL2.framework/SDL2 @executable_path/SDL2.framework/SDL2 $(NAME)
else
IFLAGS=-I$(LIBFTFOLDER) -I$(INCLUDEFOLDER) -I$(LIBSDLFOLDER)/include
LFLAGS=-L$(LIBFTFOLDER) -lft -lm -L`pwd`/$(LIBSDLFOLDER)/build/.libs -lSDL2
EDITLIB=install_name_tool -change /usr/local/lib/$(DYNSDL) @executable_path/$(DYNSDL) $(NAME)
endif
DYNSDL=libSDL2-2.0.0.dylib
CPLIB=cp $(LIBSDLFOLDER)/build/.libs/$(DYNSDL) .

else
DYNSDL=libSDL2-2.0.so.0
CPLIB=cp $(LIBSDLFOLDER)/build/.libs/$(DYNSDL) .
PATHSOSDL=-Wl,-R`pwd`/$(LIBSDLFOLDER)/build/.libs
IFLAGS=-I$(LIBFTFOLDER) -I$(INCLUDEFOLDER) -I$(LIBSDLFOLDER)/include
LFLAGS=-L$(LIBFTFOLDER) -lft -lm $(PATHSOSDL) -L`pwd`/$(LIBSDLFOLDER)/build/.libs -lSDL2  

endif

EFLAGS=-Wall -Werror -Wextra -g

.PHONY: all cleanwolf clean fclean re norme rewolf

ifeq ($(COMPILE_SDL),NO)
$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)
	$(EDITLIB)
else
$(NAME): $(LIBFT) $(OBJ) $(DYNSDL)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)
	$(EDITLIB)
endif

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
	rm -rf $(OBJFOLDER)
	rm -f $(NAME)

ifeq ($(COMPILE_SDL),NO)

clean:
	make -C $(LIBFTFOLDER) clean

fclean: cleanwolf clean
	make -C $(LIBFTFOLDER) fclean

else

clean:
	make -C $(LIBFTFOLDER) clean
	make -C $(LIBSDLFOLDER) clean

fclean: cleanwolf clean
	rm -f $(DYNSDL)
	make -C $(LIBFTFOLDER) fclean
	make -C $(LIBSDLFOLDER) distclean

endif

re: fclean all

norme:
	norminette src include libft/*.[ch]

rewolf: cleanwolf all

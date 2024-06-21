# ======= source =======

SRC = utils.cpp \
		glib.cpp \
		Canvas.cpp \
		render_core.cpp
CSRC = glad.c

vpath	%.cpp src
vpath	%.cpp src/utils
vpath	%.c	  src

OBJ_DIR	= obj
OBJ		=  $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ		+= $(CSRC:%.c=$(OBJ_DIR)/%.o)

INC_DIR = include/

DEPS 	= $(OBJ:%.o=%.d)

NAME    = libg.a

# ======= Compilation flags =======

CXX =	    clang++
CXXFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD
INC      = -I $(INC_DIR)
LDFLAGS  = ${shell pkg-config --libs glfw3} -GL

AR		 = ar rcs
RM		 = rm -fr

# ======= Rules =======

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o:		%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR)/%.o:		%.c
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	mkdir -vp $(OBJ_DIR)

test:		$(NAME)
	$(CXX) $(CXXFLAGS) test.cpp -lg -L. $(LDFLAGS) $(INC)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(GLEW_COMP_TARGET)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

debug:
	echo $(SRC)

-include $(DEPS)

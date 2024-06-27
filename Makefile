# ======= source =======

SRC = utils.cpp \
		Glib.cpp \
		Canvas.cpp \
		render_core.cpp \
		Texture.cpp \
		ShaderProgram.cpp
CSRC = glad.c

vpath	%.cpp src
vpath	%.cpp src/utils
vpath	%.cpp src/base
vpath	%.c	  src

OBJ_DIR	= obj
OBJ		=  $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ		+= $(CSRC:%.c=$(OBJ_DIR)/%.o)

INC_DIR = include/

DEPS 	= $(OBJ:%.o=%.d)

NAME    = libg.a

TEST	= test

# ======= Compilation flags =======

CXX =	    clang++
CXXFLAGS = -Wall -Werror -Wextra
ifdef DEBUG
	CXXFLAGS += -DDEBUG
endif

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

$(TEST):		$(NAME)
	$(CXX) $(CXXFLAGS) test.cpp -o $@ -lg -L. $(LDFLAGS) $(INC)

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(TEST)

re: fclean all

-include $(DEPS)

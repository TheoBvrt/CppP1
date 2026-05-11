NAME = a.out
SRCS = main.cpp ./srcs/HumanA.cpp ./srcs/HumanB.cpp ./srcs/Weapon.cpp

OBJS = ${SRCS:.cpp=.o}
CC = c++
RM = rm -f
CFLAGS = -Iheaders -std=c++98 -Wall -Wextra -Werror

all : ${NAME}

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

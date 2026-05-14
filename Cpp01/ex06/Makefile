NAME = harlFilter
SRCS = main.cpp ./srcs/Harl.cpp

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

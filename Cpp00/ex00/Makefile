NAME = megaphone
SRCS =	megaphone.cpp

OBJS = ${SRCS:.cpp=.o}
CC = c++
RM = rm -f
CFLAGS = -std=c++98 -Wall -Wextra -Werror

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

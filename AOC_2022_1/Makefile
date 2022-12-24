FLAGS := -o
NAME := jungle
CC := g++
DEBUG := -fsanitize=address -g

BLK =    \e[30m
RED    =    \e[31m
GRN =    \e[32m
YLW =    \e[33m
BLU    =    \e[34m
PPL    =    \e[35m
CYA    =    \e[36m
END    =    \e[0m

$(NAME): main.o 
	@$(CC) main.o  $(DEBUG) $(FLAGS) $(NAME)
	@printf "\t$(GRN)compiling of [$(PPL)$(NAME)$(GRN)] complete$(END)\n"
	

all: $(NAME)

main.o: main.cpp
	@printf "\t$(GRN)compiling [$(PPL)main.cpp$(GRN)]$(END)\n"
	@$(CC) -c main.cpp $(DEBUG)
	

#utils.o: utils.c
#	@$(CC) -c utils.cpp $(DEBUG)

clean:
	@rm -f $(NAME)
	@rm -f *.o

re: clean $(NAME)
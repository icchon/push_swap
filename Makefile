NAME = push_swap
CC     = cc
INCDIR = ./
CFLAGS = -Wall -Wextra -Werror 
FILES = *.c 
SRCS := $(addprefix src/,$(FILES)) main.c 
SUBDIR = libft
SUBNAME = libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SUBDIR) $(OBJS)
	@make -C $(SUBDIR) all
	cp $(SUBDIR)/$(SUBNAME) $(NAME)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $(OBJS) $(SUBDIR)/$(SUBNAME)

.c.o: 
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: 
	rm -f $(OBJS) 
	@make -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
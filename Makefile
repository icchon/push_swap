NAME = push_swap
CC     = cc
INCDIR = ./
CFLAGS = -Wall -Wextra -Werror 

OP_FILES := pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c
OP_SRCS := $(addprefix operations/,$(OP_FILES)) 

SOLVER_FILES = general_solver.c solver.c special_solver.c
SOLVER_SRCS := $(addprefix solvers/,$(SOLVER_FILES)) 

UTIL_FILES := display_util.c init_util.c operation_util.c optimize.c sort.c stack_util.c
UTIL_SRCS := $(addprefix utils/,$(UTIL_FILES)) 

VALID_FILES := parse.c 
VALID_SRCS := $(addprefix utils/,$(VALID_FILES)) 

FILES = $(addprefix src/,$(OP_SRCS)) $(addprefix src/,$(SOLVER_SRCS)) $(addprefix src/,$(UTIL_SRCS)) $(VALID_SRCS) src/push_swap.c 

SRCS := $(FILES) main.c 
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
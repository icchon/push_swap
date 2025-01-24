NAME := push_swap
BONUS_NAME := checker
CC     := cc
INCDIR := ./
CFLAGS := -Wall -Wextra -Werror 

OP_FILES := pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c
OP_SRCS := $(addprefix operations/,$(OP_FILES)) 

SOLVER_FILES := general_solver1.c general_solver2.c solver.c special_solver.c 
SOLVER_SRCS := $(addprefix solvers/,$(SOLVER_FILES)) 

UTIL_FILES := display_util.c init_util.c operation_util.c optimize.c sort.c stack_util.c 
UTIL_SRCS := $(addprefix utils/,$(UTIL_FILES)) 

VALID_FILES := parse.c 
VALID_SRCS := $(addprefix validation/,$(VALID_FILES)) 

WRAPPER_FILES := lst.c twlst1.c twlst2.c 
WRAPPER_SRCS :=  $(addprefix wrappers/,$(WRAPPER_FILES)) 

CHECKER_FILES := checker.c 
CHECKER_SRCS :=  $(addprefix checker/,$(CHECKER_FILES)) 

FILES := $(OP_SRCS) $(SOLVER_SRCS) $(UTIL_SRCS) $(VALID_SRCS) $(WRAPPER_SRCS) push_swap.c 
BONUS_FILES := $(OP_SRCS) $(SOLVER_SRCS) $(UTIL_SRCS) $(VALID_SRCS) $(WRAPPER_SRCS) $(CHECKER_SRCS)

SRCS := $(addprefix src/,$(FILES))  main.c 
BONUS_SRCS := $(addprefix src/, $(BONUS_FILES)) 
SUBDIR := libft
SUBNAME := libft.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SUBDIR) $(OBJS)
	@make -C $(SUBDIR) all
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $(OBJS) $(SUBDIR)/$(SUBNAME)

$(BONUS_NAME): $(SUBDIR) $(BONUS_OBJS)
	@make -C $(SUBDIR) all
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $(BONUS_OBJS) $(SUBDIR)/$(SUBNAME)

.c.o: 
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus : $(BONUS_NAME)

.PHONY: all clean fclean re bonus
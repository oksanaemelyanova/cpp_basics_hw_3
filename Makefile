CC		= g++

NAME	= hw3
OBJDIR	= obj
SRCS	= $(wildcard *.cpp)
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
HEADERS	= hw1.hpp



all: $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC)  $^ -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re
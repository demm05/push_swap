HDIR				=	include
SDIR				=	srcs
ODIR				=	objs
LIB_DIR				=	libft

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I$(HDIR)

PUSH_SWAP			=	push_swap
CHECKER				=	checker

MAKE_LIB			=	@make --no-print-directory -C

PRINTF_DIR			=	$(LIB_DIR)/printf
PRINTF_FILE			=	printf.a	
PRINTF				=	$(PRINTF_DIR)/$(PRINTF_FILE)
CFLAGS				+=	-I$(PRINTF_DIR)/include

LIBFT_DIR			=	$(LIB_DIR)/libft
LIBFT_FILE			=	libft.a
LIBFT				=	$(LIBFT_DIR)/$(LIBFT_FILE)
CFLAGS				+=	-I$(LIBFT_DIR)/include

VPATH				=	$(SDIR):$(SDIR)/shared:$(SDIR)/push_swap:$(SDIR)/checker:$(HDIR)

PUSH_SWAP_SRCS		:=	$(wildcard $(SDIR)/push_swap/*.c)
PUSH_SWAP_OBJS		:=	$(patsubst $(SDIR)/push_swap/%.c, $(ODIR)/push_swap/%.o, $(PUSH_SWAP_SRCS))

CHECKER_SRCS		:=	$(wildcard $(SDIR)/checker/*.c)
CHECKER_OBJS		:=	$(patsubst $(SDIR)/checker/%.c, $(ODIR)/checker/%.o, $(CHECKER_SRCS))

SHARED_SRCS			:=	$(wildcard $(SDIR)/shared/*.c)
SHARED_OBJS			:=	$(patsubst $(SDIR)/shared/%.c, $(ODIR)/shared/%.o, $(SHARED_SRCS))

DIRS				=	$(ODIR)/shared $(ODIR)/checker $(ODIR)/push_swap

LIB					= $(PRINTF) $(LIBFT)

all: $(LIB) $(PUSH_SWAP) 

$(DIRS):
	@mkdir -p $@

$(ODIR)/%.o: srcs/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PUSH_SWAP): $(SHARED_OBJS) $(PUSH_SWAP_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER): $(SHARED_OBJS) $(CHECKER_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(CHECKER)

$(PRINTF):
	$(MAKE_LIB) $(PRINTF_DIR)

$(LIBFT):
	$(MAKE_LIB) $(LIBFT_DIR)

lib_clean:
	$(MAKE_LIB) $(PRINTF_DIR) clean
	$(MAKE_LIB) $(LIBFT_DIR) clean

lib_fclean:
	$(MAKE_LIB) $(PRINTF_DIR) fclean
	$(MAKE_LIB) $(LIBFT_DIR) fclean

lib_re:
	$(MAKE_LIB) $(PRINTF_DIR) re
	$(MAKE_LIB) $(LIBFT_DIR) re

clean: lib_clean
	@rm -rf $(ODIR)

fclean: clean lib_fclean
	@rm -rf $(PUSH_SWAP) $(CHECKER)

re: lib_re all

.PHONY: all lib_fclean lib_clean clean fclean bonus

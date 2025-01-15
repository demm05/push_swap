HDIR				=	include
SDIR				=	srcs
ODIR				=	objs
CC					=	gcc
CFLAGS				=	-g -Wall -Wextra -Werror -I$(HDIR)
PUSH_SWAP			=	push_swap
CHECKER				=	checker

MAKE_LIB			=	@make --no-print-directory -C

PRINF_DIR			=	printf
PRINF_FILE			=	libftprintf.a	
PRINTF				=	$(PRINF_DIR)/$(PRINF_FILE)
CFLAGS				+=	-I$(PRINF_DIR)/include

VPATH				=	$(SDIR):$(SDIR)/shared:$(SDIR)/push_swap:$(SDIR)/checker:$(HDIR)

PUSH_SWAP_SRCS		:=	$(wildcard $(SDIR)/push_swap/*.c)
PUSH_SWAP_OBJS		:=	$(patsubst $(SDIR)/push_swap/%.c, $(ODIR)/push_swap/%.o, $(PUSH_SWAP_SRCS))

CHECKER_SRCS		:=	$(wildcard $(SDIR)/checker/*.c)
CHECKER_OBJS		:=	$(patsubst $(SDIR)/checker/%.c, $(ODIR)/checker/%.o, $(CHECKER_SRCS))

SHARED_SRCS			:=	$(wildcard $(SDIR)/shared/*.c)
SHARED_OBJS			:=	$(patsubst $(SDIR)/shared/%.c, $(ODIR)/shared/%.o, $(SHARED_SRCS))

LIB					=	$(PRINTF)
DIRS				=	$(ODIR)/shared $(ODIR)/checker $(ODIR)/push_swap

all: $(LIB) $(PUSH_SWAP) 

$(DIRS):
	@mkdir -p $@

$(ODIR)/%.o: srcs/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PUSH_SWAP): $(SHARED_OBJS) $(PUSH_SWAP_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER): $(SHARED_OBJS) $(CHECKER_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(PRINTF):
	$(MAKE_LIB) $(PRINF_DIR)

bonus: $(CHECKER)

lib_clean:
	$(MAKE_LIB) $(PRINF_DIR) clean

lib_fclean:
	$(MAKE_LIB) $(PRINF_DIR) fclean

clean: lib_clean
	@rm -rf $(ODIR)

fclean: clean lib_fclean
	@rm -rf $(PUSH_SWAP) $(CHECKER)

.PHONY: all lib_fclean lib_clean clean fclean bonus

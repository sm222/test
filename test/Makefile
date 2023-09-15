NAME	=	a.out

SRC	=	test_str.c\
		main.c

all : lib
	gcc $(SRC) C_tools/C_tool.a lib_ft/libft.a -o $(NAME)

lib :
	make -C lib_ft
	make -C C_tools
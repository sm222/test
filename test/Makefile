NAME	=	a.out

all : lib
	gcc main.c C_tools/C_tool.a lib_ft/libft.a -o $(NAME)

lib :
	make -C lib_ft
	make -C C_tools
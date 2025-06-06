#!/bin/sh

cc -Wall -Wextra -Werror -c ft_putchar.c putstr.c ft_swap.c ft_strlen.c ft_strcmp.c
ar rcs libft.a ft_putchar.o putstr.o ft_swap.o ft_strlen.o ft_strcmp.o

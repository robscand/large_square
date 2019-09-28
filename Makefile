# ############################## #
#       GNU make. Makefile       #
# ############################## #

.PHONY: all clean fclean re

name := lsq 
src_dirs := list func main 

src_files := $(notdir $(wildcard $(addsuffix /*.c, $(src_dirs))))
obj_files := $(patsubst %.c, %.o, $(src_files))

all: $(name)

$(name): $(obj_files)
	gcc $(obj_files) -o $(name)

VPATH := $(src_dirs)

%.o: %.c
	gcc -Wall -Wextra -Werror -c -MD $(addprefix -I , $(src_dirs)) $<

include $(wildcard *.d)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.d

fclean: clean
	/bin/rm -f $(name)

re: fclean all

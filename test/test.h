
#ifndef TEST_H
# define TEST_H

# include "lib_ft/libft.h"
# include "C_tools/inc/C_tool.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "readline/readline.h"
# include <limits.h>


# define spec '$'

short	set_mode(char c);
char	*make_new_str(char *old, size_t *r);


#endif // TEST_H

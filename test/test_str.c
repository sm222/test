
#include "test.h"

char	*make_new_str(char *old, size_t *r)
{
	char	*new;
	char	*skip;

	new = ft_strndup(old, *r);
	skip = ft_strdup_c(old + *r + 2, '\'');
	ft_printf(2, "%s||\n", skip);
	free(old);
	return (new);
}


//$PWD $'PWD'
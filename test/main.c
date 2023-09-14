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

char	*get_env(char **en, char *seed, size_t j)
{
	size_t	i;
	size_t	name;

	i = 0;
	Ct_mprintf(seed, ft_strlen(seed) + 1, 1, 'A');
	while (en && en[i])
	{
		name = 0;
		while (en[i][name] && en[i][name] != '=')
			name++;
		if (ft_strncmp(en[i], seed, name) == 0 && !ft_isalpha(seed[name]))
			return (en[i] + name + 1);
		i++;
	}
	return (NULL);
}

char	*edit_str(char *s, size_t i, char **en)
{
	char	*s1;
	char	*s2;
	char	*new;
	size_t	j;

	j = i + 1;
	s1 = ft_strndup(s , i);
	while (s[j] && ft_isalpha(s[j]))
		j++;
	s2 = ft_strdup(s + j);
	ft_printf(NO_PRINT, "%o%S%s%S", &new, s1, get_env(en, s + i + 1, j - i) ,s2);
	ft_free(s);
	return (new);
}

char	*pros_or_dolar(char *s, size_t i, char c)
{
	char	*s1;
	char	*s2;
	char	*new;
	size_t	j;

	j = i + 1;
	s1 = ft_strndup(s , i);
	j++;
	s2 = ft_strdup(s + j);
	printf("char = %c\n", c);
	if (c == '?')
		ft_printf(NO_PRINT, "%o%S%d%S", &new, s1, 255 ,s2);
	if (c == '$')
		ft_printf(NO_PRINT, "%o%S%c%S", &new, s1, '$' ,s2);
	ft_free(s);
	return (new);
}

short	set_mode(char c)
{
	static	short last = 0;

	if (last == 0 && c == '"')
		last = 2;
	if (last == 0 && c == '\'')
		last = 1;
	return (last);
}

void	change_dolar(char **old, char **en)
{
	char	*new;
	t_index	index;

	ft_bzero(&index, sizeof(t_index));
	new = *old;
	index.j = ft_strlen(new);
	while (index.j > index.i)
	{
		if (new[index.i] == spec && (new[index.i + 1] == ' ' || new[index.i + 1] == '\0'))
			index.i++;
		else if (new[index.i] == spec && (new[index.i + 1] == spec || (new[index.i + 1] == '?')))
			new = pros_or_dolar(new, index.i, new[index.i + 1]);
		else if (new[index.i] == spec)
			new = edit_str(new, index.i, en);
		index.i++;
		index.j = ft_strlen(new);
	}
	*old = new;
}

int	main(int ac, char **av, char **en)
{
	char	*t;
	char	*s;

	s = "t";
	while (s)
	{
		s = get_next_line(0);
		if (!s)
			return (1);
		s[ft_strlen(s) - 1] = '\0';
		change_dolar(&s, en);
		printf("out = %s\n", s);
		ft_free(s);
	}
}


/*
int	main(void)
{
	int	(*ft[2])(char *, int);

	(ft[1]) = &ft_putstr_fd;
	((*ft)("test\n", 2));
}
*/



/*
int	main(void)
{
	struct stat f;
	struct stat l;
	mode_t flag;

	int fd = open("a", O_CREAT | O_TRUNC | O_RDWR, 0644);
	stat("a", &l);
	flag = l.st_mode;
	printf("%d===%d\n", flag , l.st_mode);
	printf("ici\n");
	if (fd == -1)
	{
		perror("a");
		unlink("a");
		return (1);
	}
	char	*t = "y";
	while (t)
	{
		if (stat("a", &f) != 0 || f.st_mode != flag)
		{
			printf("%d===%d\n", flag , l.st_mode);
			perror("a");
			break ;
		}
		printf("%d\n", f.st_mode);
		t = readline(">>");
		ft_printf(2, "%o//%d\n", NULL ,ft_putendl_fd(t, fd));
		stat("a", &l);
	}
}
*/

/*
# define T_OK 0b01010101
# define U_OK 0b00000001

int	main(void)
{
	int fd =  open("nuber", O_CREAT | O_RDWR | O_TRUNC, 0644);

	int i = 1000;
	while (i > 0)
	{
		ft_printf(fd, "%o%d ", NULL, i);
		i -= 2;
	}
	i = 1;
	while (i < 1000)
	{
		ft_printf(fd, "%o%d ", NULL, i);
		i += 2;
	}
}
*/

/*
int main(void)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (pid == 0)
	{
		char *tmp2 = "t";
		dup2(fd[0], STDIN_FILENO);
		while (tmp2)
		{
			tmp2 = get_next_line(STDIN_FILENO);
			printf("--%s\n", tmp2);
		}
	}
	else
	{
		char	*tmp = "t";
		while (tmp)
		{
			tmp = get_next_line(0);
			write(fd[1], tmp, ft_strlen(tmp));
		}
		close(fd[1]);
	}
	printf("ici\n");
	return (0);
}

int	atoi_base(char *s, int base)
{
	int		rez = 0;
	char	*hex = "0123456789abcdef";
	int	i = 0;
	int j = 0;
	if (!s || base < 1 || base > 16)
		return (0);
	while (s[i])
	{
		j = 0;
		while (hex[j] != s[i])
			j++;
		rez = rez * base + j;
		i++;
	}
	return (rez);
}
printf("[%d]%s\n", i , sys_errlist[i]);
*/

/*
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_doc
{
	int				i;
	struct stat		old;
	struct stat		new;
	char			*f_name;
	int				fd;
	struct s_doc	*next; 
}		t_doc;

t_doc	*make_new(int i, int *f)
{
	t_doc	*new;
	
	if (i < 0 || !f)
		return (NULL);
	new = ft_calloc(1, sizeof(t_doc));
	*f = -1;
	if (!new)
		return (NULL);
	if (ft_printf(NO_PRINT, "%o/tmp/.here_doc%d", &new->f_name, i))
	{
		ft_free(new);
		return (NULL); 
	}
	new->i = i;
	return (new);
}


void	free_all_node(t_doc *list)
{
	t_doc	*tmp;

	while (list)
	{
		ft_free(list->f_name);
		tmp = list->next;
		ft_free(list);
		list = tmp;
	}
}


short	make_here_doc(t_doc **list, int index)
{
	static int	i = -1;
	t_doc		*tmp;

	if (i == -1)
	{
		ft_return_ptr(&i, 1);
		i = 0;
	}
	if (!list || index < 0)
		return (-1);
	if (!*list)
	{

	}
	//printf("%s %d fd\n", new ,open(new, O_CREAT | O_TRUNC | O_RDWR, 0644));
	return (1);
}


int main(int ac, char **av)
{
	t_doc	*node;

	(void)ac;
	(void)av;
	//if (ac < 2)
	//	return (printf("bad args\n"));
	//make_last(&node, "file");
	//node = make_new(av[1]);
	//if (!node)
	//	return(printf("mfail\n"));
	//printf("name = %s\n", node->f_name);
	//free_all_node(node);
	return (0);
}
*/
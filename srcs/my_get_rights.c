#include "../includes/ft_ls.h"

char	*my_initright()
{
	char 	*right;
	int	i;

	i = 0;
	right = (char *)malloc(sizeof(char) * (11));
	while (i < 10)
	{
		right[i] = '-';
		i++;
	}
	right[i] = '\0';
	return (right);
}

void	my_setread(char **right, int mode)
{
	if ((S_IRUSR & mode) == S_IRUSR)
		ft_strncpy(*right + 1, "r", 1);
	if ((S_IRGRP & mode) == S_IRGRP)
		ft_strncpy(*right + 4, "r", 1);
	if ((S_IROTH & mode) == S_IROTH)
		ft_strncpy(*right + 7, "r", 1);
}

void	my_setwrite(char **right, int mode)
{
	if ((S_IWUSR & mode) == S_IWUSR)
		ft_strncpy(*right + 2, "w", 1);
	if ((S_IWGRP & mode) == S_IWGRP)
		ft_strncpy(*right + 5, "w", 1);
	if ((S_IWOTH & mode) == S_IWOTH)
		ft_strncpy(*right + 8, "w", 1);
}

void	my_setexec(char **right, int mode)
{
	if ((S_IXUSR & mode) == S_IXUSR)
		ft_strncpy(*right + 3, "x", 1);
	if ((S_IXGRP & mode) == S_IXGRP)
		ft_strncpy(*right + 6, "x", 1);
	if ((S_IXOTH & mode) == S_IXOTH)
		ft_strncpy(*right + 9, "x", 1);
}

char	*my_get_rights(int mode)
{ 
	char	*right;

	right = my_initright();
	if (S_ISDIR(mode))
		right[0] = 'd';
	if (S_ISLNK(mode))
		right[0] = 'l';
	my_setread(&right, mode);
	my_setwrite(&right, mode);
	my_setexec(&right, mode);
	return (right);
}

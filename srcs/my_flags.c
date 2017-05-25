#include "../includes/ft_ls.h"

bool	my_flagscmp(char *arg, char *s1, char *s2, bool *flags)
{
	if (s1 && s2 && ft_strscmp(arg, s1, s2))
		return (false);
	else if (s1 && !s2 && ft_strcmp(arg, s1))
		return (false);
	*flags = true;
	return (true);
}

bool	my_flags3(t_ls *ls, char *arg)
{
	bool	ret;

	ret = false;
	my_flagscmp(arg, "r", "-reverse", &ls->flags.reverse) ? (ret = 1) : 0;
	my_flagscmp(arg, "l", "-listing", &ls->flags.listing) ? (ret = 1) : 0;
	my_flagscmp(arg, "G", "-no-group", &ls->flags.no_group) ? (ret = 1) :0;
	if (!ft_strscmp(arg, "t", "-time"))
	{
		ls->flags.time = true;
		ls->flags.file_size = false;
		ls->flags.not_sort = false;
		ret = true;
	}
	if (!ft_strcmp(arg, "S"))
	{
		ls->flags.file_size = true;
		ls->flags.time = false;
		ls->flags.not_sort = false;
		ret = true;
	}
	return (ret);
}

bool	my_flags2(t_ls *ls, char *arg)
{
	bool	ret;

	ret = false;
	if (my_flagscmp(arg, "R", "-recursive", &ls->flags.recursive))
		ret = 1;
	if (!ft_strcmp(arg, "U"))
	{
		ls->flags.not_sort = true;
		ls->flags.reverse = false;
		ls->flags.time = false;
		ls->flags.file_size = false;
		ret = true;
	}
	if (!ft_strcmp(arg, "f"))
	{
		ls->flags.not_sort = true;
		ls->flags.all = true;
		ls->flags.listing = false;
		ls->flags.reverse = false;
		ls->flags.time = false;
		ls->flags.file_size = false;
		ret = true;
	}
	return (ret);
}

bool	my_flags1(t_ls *ls, char *arg)
{
	bool	ret;

	ret = 0;
	my_flags2(ls, arg) ? (ret = 1) : 0;
	my_flags3(ls, arg) ? (ret = 1) : 0;
	my_flagscmp(arg, "a", "-all", &ls->flags.all) ? (ret = 1) : 0;
	if (my_flagscmp(arg, "A", "-almost-all", &ls->flags.almost_all))
		ret = 1;
	my_flagscmp(arg, "B", "-ignore-backups", &ls->flags.ignore_backups) ?\
		(ret = 1) : 0;
	my_flagscmp(arg, "s", "-size", &ls->flags.size) ? (ret = 1) : 0;
	my_flagscmp(arg, "Q", "-quote-name", &ls->flags.quote) ? (ret = 1) : 0;
	my_flagscmp(arg, "p", "-indicator-style", &ls->flags.indicator_style)?\
		(ret = 1) : 0;
	my_flagscmp(arg, "d", "-directory", &ls->flags.directory) ?\
		(ret = 1) : 0;
	my_flagscmp(arg, "-help", NULL, &ls->flags.help) ? (ret = 1) : 0;
	if (!ft_strcmp(arg, "o"))
	{
		ls->flags.listing = true;
		ls->flags.no_group = true;
		ret = 1;
	}
	return (ret);
}

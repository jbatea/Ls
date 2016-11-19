/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:03:16 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 18:54:47 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <limits.h>

typedef struct		s_lst
{
	char			*cpy;
	int				len;
	struct s_lst	*next;
}					t_lst;

void				ft_putstrnull(char const *s, int len);
int					ft_printf(const char *format, ...);
int					ft_isspecifier(int c);
int					ft_whichspec(char *tmp);
int					ft_isflag(int c);
int					ft_eolflag(char *tmp);
char				*ft_lflag(char *tmp);
char				*ft_specret(const char *format);
int					ft_speccnt(const char *format);
int					ft_checkformat(const char *format, t_lst *lst);
void				ft_printarg(const char *format, va_list pa, t_lst *lst);
char				*ft_patype(va_list pa, int c, int *tab, t_lst *lst);
t_lst				*ft_listinit();
void				ft_newelem(t_lst *node, char *str);
void				ft_printlist(t_lst *lst);
char				*ft_isstr(char *tmp);
char				*ft_elemspec(char *tmp, va_list pa, t_lst *lst);
char				*ft_strlower_free(char *str);
int					ft_validflags(char *str);
char				*ft_normtmp(char *tmp);
char				*ft_whichflags(char *str, va_list pa, t_lst *lst);
char				*ft_applyflag(char *tmp, char f, char s, int *tab);
char				*ft_sharpflag(char spec);
char				*ft_signflag(char *tmp, char spec, char flag);
int					ft_orderflags(char *str);
int					ft_islenflag(char c);
int					ft_basicflags(char c);
int					ft_lenchr(char *tmp);
int					ft_precchr(char *tmp);
char				*ft_leftalig(char *tmp, int len);
char				*ft_fillflag(char *tmp, int len);
char				*ft_flagpriority(char *str);
char				*ft_rightalig(char *tmp, int len);
int					ft_leftflagchr(char *str);
char				*ft_precflag(char *str);
int					ft_lenmod(char *str);
char				*ft_pamodtype(va_list pa, int c, t_lst *lst, int *tab);
char				*ft_pamodind(va_list pa, int lenmod);
char				*ft_pamodx(va_list pa, int lenmod, int c);
char				*ft_wstos(wchar_t *str);
int					ft_lststrlen(t_lst *lst);
void				ft_lstfree(t_lst **lst);
int					ft_eolspec(char *tmp);
int					ft_checkflags(const char *format);
char				*ft_dtos(double g, char *s);
int					ft_isbspec(int c);
char				*ft_snotation(char *str);
char				*ft_doubleprec(char *tmp, int prec);
char				*ft_dprecsci(char *tmp, int prec);
int					ft_ispoint(char *s, int i);
char				*ft_islennorm(char *str);
char				*ft_sharpnfill(char *tmp, char spec);
char				*ft_patypefloat(int c, int *tab, char *s);
char				*ft_applypa(int c, va_list pa, t_lst *lst, int *tab);
int					ft_countdouble(double g);
char				*ft_lenandprec(char *str, int *tab);
long long int		*ft_tablen(long long int *tab, double g, double n2);
long long int		*ft_initlongtab(void);
int					ft_cnt(int cnt);
char				*ft_unbehaviour(long long int u, int c);
char				*ft_applylenmod(int c, long long int u);
long int			ft_lenfourafive(int lenmod, va_list pa);
int					ft_sizeb(unsigned long n);
char				*ft_wctos(wchar_t wcs);
int					ft_increaselen(t_lst *lst);
int					ft_isspace(char *str);
char				*ft_litox(unsigned long n);
char				*ft_llitox(unsigned long long n);
char				*ft_llutoa(unsigned long long n);
char				*ft_flagorder(char *str, char c);
char				*ft_lenandzero(char s, char *tmp, int *tab, char f);
int					ft_iss(char s);
char				*ft_applysharp(char s, char *tmp, char f);
char				*ft_pacnull(char *str, int len);
void				ft_freeall(int *tab, int *tab1, char *tmp);
char				*ft_iscnull(char *s, t_lst *lst, int *tab);

#endif

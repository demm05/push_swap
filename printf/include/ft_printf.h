/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:28:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 18:11:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format_info
{
	int	is_valid;
	int	len;
	int	f_len;
}	t_format_info;
typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
}	t_flags;

typedef struct s_spec_info
{
	t_flags	flags;
	int		width;
	int		precision;
	int		is_precision;
	int		is_width;
	int		is_char;
}	t_spec_info;

typedef char	*(*t_spec_formatter)(va_list, t_spec_info *);

int		ft_printf(const char *format, ...);
char	*do_int_precision(char *buffer, t_spec_info s_info);
char	*pf_37(va_list val, t_spec_info *s_info);
char	*pf_char(va_list val, t_spec_info *s_info);
char	*pf_string(va_list val, t_spec_info *s_info);
char	*pf_integer(va_list val, t_spec_info *s_info);
char	*pf_unsigned(va_list val, t_spec_info *s_info);
char	*pf_lhex(va_list val, t_spec_info *s_info);
char	*pf_uhex(va_list val, t_spec_info *s_info);
char	*pf_pointer(va_list val, t_spec_info *s_info);

void	parse_specifier(const char *format, t_format_info *t_info, va_list val);
int		parse_flags(const char *format, t_spec_info *s_info, int *i);
void	parse_width(const char *format, t_spec_info *s_info, int *i);
void	parse_precision(const char *format, t_spec_info *s_info, int *i);
int		check_flag(char c, t_flags *flags);
int		_putchar(char c);
int		_pf_putstr(char *s, int fd);
int		pf_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif

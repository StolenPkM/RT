/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:32:51 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/22 16:57:45 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100000
# define BUFF_5IZE(x) (x > 0 ? x : 1)
# define READCHECK(x, y) if (!x && y < 0) return (0);
# define ABS(x) x < 0 ? x * - 1.0 : x
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <time.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_attr
{
	int				file_type;
	blkcnt_t		blockcount;
	off_t			filesize;
	char			*filename;
	uid_t			uid;
	gid_t			gid;
	time_t			creation_time;
	time_t			last_edit_time;
	struct s_attr	*next;
}				t_attr;

unsigned int	ft_strtol(char *line);
t_vect			vmv(t_vect v1, t_vect v2);
unsigned int	uimin(unsigned int a, unsigned int b);
void			uiclamp(unsigned int *ui, unsigned int min, unsigned int max);
void			iclamp(int *ui, int min, int max);
void			rgb_add(unsigned int *color, unsigned int add);
double			fclamp(double d, double min, double max);
double			ft_eq_second(double delta, double a, double b);
void			ft_list_push_back(t_list **beginlist, void *data);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_atoi(const char *c);
double			ft_atof(const char *c);
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_itoa(int n);
void			*ft_memmove(void *dst, void const *src, size_t n);
char			*ft_strncat(char *dst, const char *src, size_t n);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
int				ft_iswp(int c);
char			*ft_strtrim(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_putnbr(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_toupper(int c);
void			ft_putstr(char const *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_tolower(int c);
size_t			ft_strlen(const char *s);
size_t			ft_strclen(const char *s, char c);
size_t			ft_countcwords(const char *s, char c);
void			ft_putchar(char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strrcpy(const char *src, size_t from);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strstr(const char *big, const char *little);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strctrim(const char *s, char c);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_attr			*ft_fill_attr(char *path, char *filename);
void			ft_list_sort(t_attr ***list, int (*compare)(t_attr*, t_attr*));
void			ft_ptrswap(void **data_1, void **data_2);
void			*ft_realloc(void *ptr, size_t size);

t_vect			vrotateinv(t_vect v, t_vect angle);
t_vect			vectsub(t_vect vect1, t_vect vect2);
t_vect			vectadd(t_vect vect1, t_vect vect2);
double			norm2(t_vect v);
double			norm(t_vect v);
t_vect			normalize(t_vect v);
double			dot(t_vect v1, t_vect v2);
t_vect			vrotate(t_vect v, t_vect angle);
t_vect			coord_v(double x, double y, double z);
t_vect			vmult(t_vect v, double mult);

int				get_next_line(const int fd, char **line);

#endif

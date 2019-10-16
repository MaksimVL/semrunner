#ifndef DLIST_H
# define DLIST_H

# include "libft.h"

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist		*ft_dlstnew(void const *content, size_t content_size);
void		ft_dlstadd(t_dlist **alst, t_dlist *new);
void		ft_dlst_addback(t_dlist **alst, t_dlist *new);
void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));

#endif

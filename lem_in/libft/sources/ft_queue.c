#include "libft.h"

void			del_intcontent(void *content, size_t size)
{
	if (size == 0 && size != 0)
		return ;
	ft_memdel((void**)&content);
}

int				int_content(t_dlist *list)
{
	if (list != NULL)
		return (*(int*)(list->content));
	else
		return (NO_DEFINE);
}

void			queue_init(t_queue *queue)
{
	queue->len = 0;
	queue->top = NULL;
	queue->bottom = NULL;
}

void			qi_del(t_queue *queue)
{
	if (queue->len != 0)
		ft_dlstdel(&(queue->top), del_intcontent);
	queue->bottom = NULL;
	queue->len = 0;
}

void			*qi_push(t_queue *queue, int value)
{
	t_dlist		*temp;

	temp = ft_dlstnew(&value, sizeof(value));
	if (temp == NULL)
		return (NULL);
	if (queue->top == NULL)
	{
		queue->len = 1;
		queue->top = temp;
		queue->bottom = temp;
	}
	else
	{
		ft_dlstadd(&(queue->top), temp);
		queue->top = temp;
		queue->len += 1;
	}
	return (queue);
}

int				qi_pop(t_queue *queue)
{
	int		ret;
	t_dlist	*tmp_lst;

	if (queue->len == 0)
		return (NO_DEFINE);
	else
	{
		ret = int_content(queue->bottom);
		tmp_lst = queue->bottom;
		if (queue->len == 1)
		{
			queue->top = NULL;
			queue->bottom = NULL;
		}
		else
		{
			queue->bottom = queue->bottom->prev;
			queue->bottom->next = NULL;
		}
		queue->len--;
		ft_dlstdel(&tmp_lst, del_intcontent);
		return (ret);
	}
}

int				qi_front(t_queue *queue)
{
	if (queue->len == 0)
		return (NO_DEFINE);
	return (int_content(queue->bottom));
}

int				qi_back(t_queue *queue)
{
	if (queue->len == 0)
		return (NO_DEFINE);
	return (int_content(queue->top));
}

int				qi_empty(t_queue *queue)
{
	if (queue->len == 0)
		return (1);
	else
		return (0);
}

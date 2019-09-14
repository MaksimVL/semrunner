
#include "libft.h"

t_dict		*ft_dictnew(void const *content, size_t content_size, int key)
{
	t_dict	*ptr;

	if (!(ptr = (t_dict*)malloc(sizeof(t_dict))))
		return (NULL);
	ptr->next = NULL;
	ptr->key = key;
	if (content)
	{
		if (!(ptr->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	return (ptr);
}

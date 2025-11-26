#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int count;
	t_list *temp;

	count = 0;
	if(!begin_list)
		return(0);
	temp = begin_list;
	while(temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return(count);
}
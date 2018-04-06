#include "t_list.h"
#include <stdlib.h>
#include <stdio.h>

int asc(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *buf;
	int		nbuf;

	buf = lst;
	while (buf->next)
	{
		if (asc(buf->data, buf->next->data))
		{
			nbuf = buf->data;
			buf->data = buf->next->data;
			buf->next->data = nbuf;
			return (sort_list(lst, cmp));
		}
	}
	return (lst);
}

int main (int c, char **v)
{
	if (c > 2)
	{
		t_list *lst1 = (t_list *)malloc(sizeof(t_list) * 1);
		t_list *lst2 = (t_list *)malloc(sizeof(t_list) * 1);
		t_list *lst3 = (t_list *)malloc(sizeof(t_list) * 1);
		t_list *lst4 = (t_list *)malloc(sizeof(t_list) * 1);
		t_list *lst5 = (t_list *)malloc(sizeof(t_list) * 1);

		lst1->data = atoi(v[1]);
		lst1->next = lst2;
		lst1->data = atoi(v[2]);
		lst1->next = lst3;
		lst1->data = atoi(v[3]);
		lst1->next = lst4;
		lst1->data = atoi(v[4]);
		lst1->next = lst5;
		lst1->data = atoi(v[5]);
		lst1->next = NULL;

		sort_list(lst1, &asc);

		while (lst1)
		{
			printf("%i\n", lst1->data);
			lst1 = lst1->next;
		}
	}
	else
		printf("Waiting for nums!\n");
}
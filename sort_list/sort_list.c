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
		if (!(asc(buf->data, buf->next->data)))
		{
			nbuf = buf->data;
			buf->data = buf->next->data;
			buf->next->data = nbuf;
			return (sort_list(lst, cmp));
		}
		else
			buf = buf->next;
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
		lst2->data = atoi(v[2]);
		lst2->next = lst3;
		lst3->data = atoi(v[3]);
		lst3->next = lst4;
		lst4->data = atoi(v[4]);
		lst4->next = lst5;
		lst5->data = atoi(v[5]);
		lst5->next = NULL;

		t_list *res = sort_list(lst1, &asc);

		while (res)
		{
			printf("%i\n", res->data);
			res = res->next;
		}
	}
	else
		printf("Waiting for nums!\n");
}
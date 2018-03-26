#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *find_head(char *str)
{
	char *res;
	int i;
	int j;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char *find_tail(char *str, int len)
{
	char *res;
	int i;
	int j;

	i = 0;
	while (len && str[len] != ' ' && str[len] != '\t')
	{
		i++;
		len--;
	}
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = str[len + 1];
		j++;
		len++;
	}
	res[j] = '\0';
	return (res);
}

char *create_body(char *str, int start, int finish, int len)
{
	char *res;
	int i;

	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (start != finish)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

int main(int c, char **v)
{
	if (c == 2)
	{
		char *head;
		char *tail;
		char *body;
		char *res;
		int len;
		int h_len;
		int t_len;
		int b_len;
		int i;
		int j;
		int k;

		len = ft_strlen(v[1]);
		head = find_head(v[1]);
		h_len = ft_strlen(head);
		tail = find_tail(v[1], len);
		t_len = ft_strlen(tail);
		body = create_body(v[1], h_len, len - t_len, len - (t_len + h_len));
		b_len = ft_strlen(body);

		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		i = 0;
		while (i < t_len)
		{
			res[i] = tail[i];
			i++;
		}
		j = 0;
		while (i < (t_len + b_len))
		{
			res[i] = body[j];
			i++;
			j++;
		}
		k = 0;
		while (i < len)
		{
			res[i] = head[k];
			i++;
			k++;
		}
		res[i] = '\0';
		free(head);
		free(tail);
		free(body);
		ft_putstr(res);
		ft_putstr("\n");
		free(res);
	}
	else
	{
		ft_putstr("\n");
		return (0);
	}
}
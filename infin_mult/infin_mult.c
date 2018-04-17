//248978423648168364128649283648721648721469237649759
//649283648721641286492836487216487216492836487216234

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_put(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int get_int(char *str, int i)
{
	if (i < 0)
		return (0);
	return (str[i] - '0');
}

char *str_new(int len)
{
	char *res;

	if ((res = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (len >= 0)
		{
			res[len] = '\0';
			len--;
		}
	}
	return (res);
}

int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char mult_one(int a, int b, int *o)
{
	int res;

	res = a * b + *o;
	*o = res / 10;
	return ((res % 10) + '0');
}

char *mult(char *str, int num, int zero)
{
	char *res;
	int len;
	int o;

	len = 1 + str_len(str) + zero;
	if ((res = str_new(len)))
	{
		--len;
		while (zero)
		{
			res[len--] = '0';
			zero--;
		}
		o = 0;
		while (len >= 0)
		{
			res[len] = mult_one(get_int(str, len - 1), num, &o);
			len--;
		}
	}
	return (res);
}

char **combine(char *a, char *b)
{
	char **res;
	int len;
	int i;

	len = str_len(b);
	if ((res = (char **)malloc(sizeof(char *) * (len + 1))))
	{
		res[len] = NULL;
		len--;
		i = 0;
		while (len >= 0)
		{
			//printf("%i\n", len);
			res[len] = mult(a, get_int(b, len), i++);
			//ft_put(res[len]);
			//ft_put("\n");
			len--;
		}
	}
	return (res);
}

char add_one(int a, int b, int *o)
{
	char res;

	res = a + b + *o;
	*o = res / 10;
	return (res % 10 + '0');
}

char *add(char *a, char *b)
{

//printf("add a: %s    add b: %s\n", a, b);
	char *res;
	int alen;
	int blen;
	int len;
	int o;

	alen = str_len(a);
	blen = str_len(b);
	len = alen + 1;
	if ((res = str_new(len)))
	{
		len--;
		o = 0;
		while (len >= 0)
		{
			res[len] = add_one(get_int(a, --alen), get_int(b, --blen), &o);
			len--;
		}
	}
	//printf("add res: %s\n", res);
	return (res);
}

char *result(char **arr)
{
	char *res;

	res = arr[0];
	arr++;
	while (*arr)
		res = add(res, *(arr++));
	return (res);
}

int is_pos(char **str)
{
	if ((*str)[0] == '-')
	{
		(*str)++;
		return (0);
	}
	return (1);
}

void process(char *a, char *b)
{
	int pos;
	char *res;

	pos = 0;
	if (is_pos(&a) == is_pos(&b))
		pos = 1;
	res = result(combine(a, b));
	while (*res == '0' && *(res + 1))
		res++;
	if (!pos && *res != '0')
		ft_put("-");
	ft_put(res); 
}

int main(int c, char **v)
{
	if (c == 3)
	{
		process(v[1], v[2]);
	}
		ft_put("\n");
}
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void ft_put(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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
		i++;
	return (i);
}

int get_int(char *str, int i)
{
	if (i < 0)
		return (0);
	return (str[i] - '0');
}

char add_one(int a, int b, int *o)
{
	int res;

	res = a + b + *o;
	*o = res / 10;
	return (res % 10 + '0');
}

char minus_one(int a, int b, int *p)
{
	int res;

	if ((res = a - b - *p) < 0)
	{
		*p = 1;
		res += 10;
	}
	else
		*p = 0;
	return (res + '0');
}

char *minus(char *a, char *b)
{
	char *res;
	int alen;
	int blen;
	int len;
	int p;

	p = 0;
	alen = str_len(a);
	blen = str_len(b);
	len = alen > blen ? alen + 1 : blen + 1;
	if ((res = str_new(len)))
	{
		len--;
		while (len >= 0)
		{
			res[len] = minus_one(get_int(a, --alen), get_int(b, --blen), &p);
			len--;
		}
	}
	return (res);
}

char *add(char *a, char *b)
{
	char *res;
	int o;
	int alen;
	int blen;
	int len;

	o = 0;
	alen = str_len(a);
	blen = str_len(b);
	len = alen > blen ? alen + 1 : blen + 1;
	if ((res = str_new(len)))
	{
		len--;
		while (len >= 0)
		{
			res[len] = add_one(get_int(a, --alen), get_int(b, --blen), &o);
			len--;
		}
	}
	return (res);
}

int is_pos(char **num)
{
	if ((*num)[0] == '-')
	{
		(*num)++;
		return (0);
	}
	return (1);
}

int if_equal(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] > b[i])
			return (1);
		else if (a[i] < b[i])
			return (0);
		i++;
	}
	return (-1);
}

int cmp(char *a, char *b)
{
	int alen;
	int blen;

	alen = str_len(a);
	blen = str_len(b);
	if (alen > blen)
		return (1);
	else if (blen > alen)
		return (0);
	else
		return (if_equal(a, b));

}			

void cut_zeros(char **num)
{
	while (**num == '0' && *(*num + 1))
		(*num)++;
}

void process(char *a, char *b)
{
	int apos;
	int bpos;
	int comp;
	char *res;

	apos = is_pos(&a);
	bpos = is_pos(&b);
	comp = cmp(a, b);
	if (apos == bpos)
	{
		if (!apos)
			ft_put("-");
		res = add(a, b);
	}
	else
	{
		if ((comp == 1 && !apos) || (comp == 0 && !bpos))
			ft_put("-");
		if (comp == 1)
			res = minus(a, b);
		else
			res = minus(b, a);
	}
	cut_zeros(&res);
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
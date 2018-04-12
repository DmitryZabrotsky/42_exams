#include <stdio.h>
#include <stdlib.h>

int isprime(int n)
{
	int d;

	d = 2;
	while (d < n)
	{
		if (n % d == 0)
			return (0);
		d++;
	}
	return (1);
}

int find_d(int d)
{
	d++;

	while(1)
	{
		if (isprime(d))
			return (d);
		d++;
	}
}

int main(int c, char **v)
{
	if (c == 2)
	{
		int num;
		int d;

		d = 2;
		num = atoi(v[1]);
		if (num <= 1)
			printf("%d", num);
		while (num > 1)
		{
			if (num % d == 0)
			{
				printf("%d", d);
				num /= d;
				if (num != 1)
					printf("*");
			}
			else
			{
				d = find_d(d);
			}
		}
		printf("\n");
	}
	else
	{
		printf("\n");
		return (0);
	}
}
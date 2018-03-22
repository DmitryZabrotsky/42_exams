#include <stdio.h>

void print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while(i != size)
	{
		printf("[%i]", arr[i]);
		i++;
	}
	printf("\n");
}

// each with each
/*void	sort_int_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int 	i;
	unsigned int 	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				(tab, 4);
			}
			j += 1;
		}
		i += 1;
	}
}*/

// buble sort
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int buf;

	i = 0;
	while (i != size)
	{
		if (tab[i] > tab[i + 1])
		{
			buf = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buf;
			while (i != 0 && tab[i - 1] > tab[i])
			{	
				buf = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = buf;
				i--;
			}
		}
		i++;
	}
}

int main(void)
{
	int tab[4] = {8,10,10,1};
	sort_int_tab(tab, 4);
	print_arr(tab, 4);
}
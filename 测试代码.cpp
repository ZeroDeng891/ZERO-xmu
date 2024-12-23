# include<stdio.h>
# include<stdlib.h>

int n;
int tree[31];

void Create(int i)
{
	if (i > n)return;
	scanf("%d", &tree[i]);
	Create(2 * i);
	Create(2 * i + 1);
}

int main()
{
	scanf("%d", &n);
	Create(1);
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)printf(" ");
		printf("%d", tree[i]);
	}
	return 0;
}

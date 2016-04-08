
#include <stdio.h>
#include <string.h>

int m[102][102], b[102][102];
char text1[100], text2[100];

int  LCS(char text1[], char text2[]);
void print_LCS(int i, int k);

int main()
{
	int max;

	scanf(" %[^\n] %[^\n]", &text1, &text2);

//	printf("%s\n%s\n", text1, text2);

	max = LCS(text1, text2);
	printf("max lenght : %d\n", max);

	print_LCS(strlen(text1), strlen(text2));
	printf("\n");

	return 0;
}

int  LCS(char text1[], char text2[])
{
	int i, k, n1, n2;

	n1 = strlen(text1);
	n2 = strlen(text2);

	for( i = 0; i <= n1; i++)		m[i][0] = 0;
	for( i = 0; i <= n2; i++)		m[0][i] = 0;

	for( i = 1; i <= n1; i++)
	{
		for( k = 1; k <= n2; k++)
		{
			if( text1[i-1] == text2[k-1])
				m[i][k] = m[i-1][k-1] + 1, b[i][k] = 1;

			else if( m[i-1][k] >= m[i][k-1])
				m[i][k] = m[i-1][k], b[i][k] = 2;

			else
				m[i][k] = m[i][k-1], b[i][k] = 3;
		}
	}
	return m[n1][n2];
}

void print_LCS(int i, int k)
{
	if( i == 0 || k == 0)		return;

	if( b[i][k] == 1)
	{
		print_LCS(i-1, k-1);
		printf("%c", text1[i-1]);
	}
	else if( b[i][k] == 2)
		print_LCS(i-1, k);
	else
		print_LCS(i, k-1);
}

#include <stdio.h>

int main()
{
	char str[12]; // '-52'
	scanf_s("%s\0", str, sizeof(char) * 20); // '-2'
	//str = "five";
	printf("%s", str);

	return 0;
}
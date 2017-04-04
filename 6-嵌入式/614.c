#include <stdio.h>

int main(int argc, char const *argv[])
{
	int score;

	scanf("%d", &score);
	switch (score) {
		case 0:
		case 1:
		case 2:
		case 3:
			printf("Fail\n");
			break;
		case 4:
		case 5:
		    printf("Pass\n");
		    break;
		default:
			printf("Uncertain\n");
			break;
	}

	return 0;
}
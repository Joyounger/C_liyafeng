#include <stdio.h>

typedef struct engineer_p {
	char Name[10];
	int Id;
	char Department[10];	
} __attribute__((__packed__)) A;

typedef struct engineer1 {
	char Name[10];
	int Id;
	char Department[10];	
} B;

typedef struct engineer2 {	
	int Id;
	char Name[10];
	char Department[10];	
} C;

int main()
{
	printf("%d %d %d\n", sizeof(A), sizeof(B), sizeof(C));
	
	return 0;	
}
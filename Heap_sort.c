#include <stdio.h>
#include <stdlib.h>

int Pinakas[10];
int Hsize;
char c;

void PRINT_ARRAY();
void INSERT_HEAP();
void HEAPIFY(int i);
void BUILT_HEAP();
void HEAPSORT();

int main(void)
{
	/*c = '*'
	while(c!='q')
	{
		printf("\nEnter i to Insert, b to Built heap, s to heapsort, p to Print, q to quit:");
		scanf("%c", &c);
		if(c=='i')
			INSERT_HEAP();
		else if(c=='b')
			BUILT_HEAP();
		else if(c=='s')
			HEAPSORT();
		else if(c=='p')
			PRINT_ARRAY();
			
		printf("\nPress any key to continue...");
		getchar();
		getchar();
	}*/
	INSERT_HEAP();
	PRINT_ARRAY();
	BUILT_HEAP();
	PRINT_ARRAY();
	HEAPSORT();
	return 0;
}

void PRINT_ARRAY()
{
	int j;
	printf("\nO pinakas apoteleite apo:\n");
	for(j=0; j<10; j++)
		printf("\nA[%d] = %d", j, Pinakas[j]);
}

void INSERT_HEAP()
{
	int i;
	printf("\nInsert 10 new elements ston pinaka\n");
	for(i=0; i<10; i++)
	{
		printf("\nA[%d] = ", i);
		scanf("%d", &Pinakas[i]);
	}
	Hsize = 9;
}

void BUILT_HEAP()
{
	int m;
	for(m=4; m>=0; m--)
		HEAPIFY(m);
}

void HEAPIFY(int i)
{
	int l, k, r, largest;
	
	l = 2*i + 1;
	r = 2*i + 2;
	if((l <= Hsize) && (Pinakas[l] > Pinakas[i]))
		largest = l;
	else
		largest = i;
	if((r <= Hsize) && (Pinakas[r] > Pinakas[largest]))
		largest = r;
	if(largest != i)
	{
		k = Pinakas[i];
		Pinakas[i] = Pinakas[largest];
		Pinakas[largest] = k;
		HEAPIFY(largest);
	}
}

void HEAPSORT()
{
	int i, k;
	BUILT_HEAP();
	for(i=9; i>=1; i--)
	{
		k = Pinakas[0];
		Pinakas[0] = Pinakas[i];
		Pinakas[i] = k;
		Hsize = Hsize - 1;
		HEAPIFY(0);
	}
	printf("\nO pinakas taksinomithike");
	PRINT_ARRAY();
}

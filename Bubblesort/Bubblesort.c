#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Bubblesort (int data[],int n) {
	int tmp,i,j;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (data[j] > data[j+1]) {
                tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
}


int main(int argc, char **argv)
{


int i,vetor[20];

    for(i=0;i<20;i++){
        vetor[i]= rand()%20;
        printf("%d ;", vetor[i]);
    }
    Bubblesort (vetor, 20 );

    printf("\n");
    for(i=0;i<20;i++){


        printf("%d ;", vetor[i]);
    }
	return 0;
}

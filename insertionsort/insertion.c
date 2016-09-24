#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Insertionsort (int data[], int n) {
	int tmp,i,j;
	for (j=1; j<n; j++) {
		i =j - 1;
		tmp = data[j];
		while ( (i>=0) && (tmp < data[i]) ) {
			data[i+1] = data[i];
			 i--;
		}//while

		data[i+1] = tmp;
	}//for

}//Insertionsort


int main(int argc, char **argv)
{


int i,vetor[10];

    for(i=0;i<10;i++){
        vetor[i]= rand()%10;
        printf("%d", vetor[i]);
    }
    Insertionsort (vetor, 10);

    printf("\n");
    for(i=0;i<10;i++){


        printf("%d", vetor[i]);
    }
	return 0;
}


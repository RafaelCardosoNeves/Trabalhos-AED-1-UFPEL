#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Selectsort (int data[],int n) {
   int min,tmp,i,j,min_id;
   for (i=0; i<n-1; i++) {
     min = data[i];
     for (j=i+1; j<n; j++)
       if (data[j] < min) {
         min = data[j];
         min_id = j;
     	 }
     tmp = data[i];
     data[i] = data[min_id];
     data[min_id] = tmp;
     min_id = i+1;
  }
}


int main(int argc, char **argv)
{


int i,vetor[15];

    for(i=0;i<15;i++){
        vetor[i]= rand()%10;
        printf("%d", vetor[i]);
    }
    Selectsort(vetor, 15 );

    printf("\n");
    for(i=0;i<15;i++){


        printf("%d", vetor[i]);
    }
	return 0;
}

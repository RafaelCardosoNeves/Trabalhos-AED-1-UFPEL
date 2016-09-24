#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Quicksort (int data[],int left,int right) {
  int mid,tmp,i,j;
  i = left;
  j = right;
  mid = data[(left + right)/2];
  do {
    while(data[i] < mid)
      i++;
    while(mid < data[j])
      j--;
    if (i <= j) {
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j)
    Quicksort(data,left,j);
  if (i < right)
    Quicksort(data,i,right);
}



int main(int argc, char **argv)
{

int i,vetor[20];

    for(i=1;i<21;i++){
        vetor[i]= rand()%20;
        printf("%d ;", vetor[i]);
    }
    Quicksort(vetor, 1, 20);

    printf("\n");
    printf("ordenado: \n");
    for(i=1;i<21;i++){


        printf("%d ;", vetor[i]);
    }
	return 0;
}

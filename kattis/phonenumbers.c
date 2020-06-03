//https://open.kattis.com/problems/phonelist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* int mycmp(char buf1[], char buf2[], int n) { */
/*   for (int i=0; i < n; i++) { */
/*     if (buf1[i] != buf2[i]) { */
/*       return 1; */
/*     } */
/*   } */
/*   return 0; */
/* } */


int check_prefix(int numbers[], int n) {//Man burde kunne gøre det sådan her med [n] i stedet for at tilføje en
  char buf1[11];
  char buf2[11];
  for (int i=0; i < n-1; i++) {
    for (int j=i+1; j < n; j++) {
      int l;
      if (numbers[i] == 0) l = 1;
      else l = floor(log10(fabs(numbers[i]))) + 1;
      sprintf(buf1, "%d", numbers[i]);
      sprintf(buf2, "%d", numbers[j]);
      printf("Size of buf1: %d\n", l);
      if (!strncmp(buf2, buf1, l)) {
        printf("buf1: %s\nbuf2: %s\n", buf1, buf2);
        /* printf("buf1 chars: %c, %c, %c\n", buf1[0], buf1[1], buf1[2]); */
        /* printf("buf2 chars: %c, %c, %c\n", buf2[0], buf2[1], buf2[2]); */
        return 0;//NO
      }
      else continue;
    }
  }
  return 1;//YES
}

/* int comp (const void * elem1, const void * elem2) { */
/*     int f = *((int*)elem1); */
/*     int s = *((int*)elem2); */
/*     if (f > s) return  1; */
/*     if (f < s) return -1; */
/*     return 0; */

void radix_sort(int arr[], int n)
{
 int bucket[10][5],buck[10],b[10];
 int i,j,k,l,num,div,large,passes;

 div=1;
 num=0;
 large=arr[0];

 for(i=0 ; i<n ; i++)
 {
  if(arr[i] > large)
   {
    large = arr[i];
   }

  while(large > 0)
  {
   num++;
   large = large/10;
  }

  for(passes=0 ; passes<num ; passes++)
  {
   for(k=0 ; k<10 ; k++)
   {
    buck[k] = 0;
   }
   for(i=0 ; i<n  ;i++)
   {
    l = ((arr[i]/div)%10);
    bucket[l][buck[l]++] = arr[i];
   }

   i=0;
   for(k=0 ; k<10 ; k++)
   {
    for(j=0 ; j<buck[k] ; j++)
    {
     arr[i++] = bucket[k][j];
    }
   }
   div*=10;
  }
 }


}

int main() {
  int tc;
  int n;
  fscanf(stdin, "%d", &tc);
  for (int i=0; i < tc; i++) {
    fscanf(stdin, "%d", &n);
    int *numbers = calloc(n, sizeof(int));
    for (int j=0; j < n; j++) {
      fscanf(stdin, "%d", &numbers[j]);
    }
    /* qsort(numbers, sizeof(numbers)/sizeof(numbers[0]), sizeof(numbers[0]), comp); */
    radix_sort(numbers, n);

    printf("Sorted numbers: ");
    for (int j=0; j < n; j++) {
      printf("%d, ", numbers[j]);
    }
    printf("\n");

    int x = check_prefix(numbers, n);
    printf("x: %d\n", x);
    if (x) {
      fprintf(stdout, "NO\n");
    }
    else fprintf(stdout, "YES\n");
  }

  return 0;
}

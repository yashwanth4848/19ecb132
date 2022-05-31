# include <stdio.h>
int main(void) {
  int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
  // Elements are hard coded

  for (int i=1; i<10; i++) {
    int element = input[i];
    int j = i-1;
    while ( j >= 0 && input[j] > element) {
      input[j+1] = input[j];
      j--;
    }
    input[j+1] = element;
  }

  printf("\nElements after sorting are ...\n");
  for(int i=0; i<10; i++)
    printf("%d\t", input[i]);
  return 0;  
}

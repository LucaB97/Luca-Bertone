#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 10
#define KERNEL 5

int main() {

float k = KERNEL;
int s = (k-1)/2;

short int * old_ptr;
short int * new_ptr;
short int * kernel_ptr;
int current_index;

old_ptr = (unsigned short int*)calloc( MATRIX_WIDTH*MATRIX_HEIGHT, sizeof(short int) );
new_ptr = (unsigned short int*)calloc( MATRIX_WIDTH*MATRIX_HEIGHT, sizeof(short int) );
kernel_ptr = (unsigned short int*)calloc( KERNEL*KERNEL, sizeof(short int) );

srand(time(NULL));
printf("Initial matrix:\n");
for (int i=0 ; i<MATRIX_HEIGHT*MATRIX_WIDTH ; i++) {
    old_ptr[i] = rand() % 265;
    printf("%5.d    " , old_ptr[i]);
    if ((i+1) % MATRIX_WIDTH == 0)
        printf("\n");
}




printf("\n\n(Mean) Kernel matrix:\n");
for (int i=0 ; i<KERNEL*KERNEL ; i++) {
        kernel_ptr[i] = 1;
        printf("%d  " , kernel_ptr[i]);
        if ((i+1) % KERNEL == 0)
            printf("\n");
}


for ( int new_element = 0 ; new_element < MATRIX_WIDTH*MATRIX_HEIGHT ; new_element++ ) {
   new_ptr[new_element] = 0;
   current_index = new_element - s*MATRIX_WIDTH - s;

   for (int rows = 0 ; rows < KERNEL ; rows++) {
      for (int i=0 ; i < KERNEL ; i++) {
         if (current_index >= 0 & current_index < MATRIX_WIDTH*MATRIX_HEIGHT & ((current_index % MATRIX_WIDTH) <= ((current_index + KERNEL + 1) % MATRIX_WIDTH))) {
	        new_ptr[new_element] += old_ptr[current_index] * kernel_ptr[i];
         }
	     ++current_index;
      }
      current_index += MATRIX_WIDTH - k - 1;
   }
}


printf("Final matrix:\n");
for (int i=0 ; i<MATRIX_HEIGHT*MATRIX_WIDTH ; i++) {
    printf("%5.d    " , new_ptr[i]);
    if ((i+1) % MATRIX_WIDTH == 0)
        printf("\n");
}


return 0;
}


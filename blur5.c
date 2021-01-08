#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc , char **argv ) {

int xsize = 9;
int ysize = 11;
int kernel; 
int s;

kernel = atoi (*(argv+1));
s = (kernel-1)/2; 

short int * old_ptr;
short int * new_ptr;
short int * kernel_ptr;
int current_index;

old_ptr = (unsigned short int*)calloc( xsize*ysize, sizeof(short int) );
new_ptr = (unsigned short int*)calloc( xsize*ysize, sizeof(short int) );
kernel_ptr = (unsigned short int*)calloc( kernel*kernel, sizeof(short int) );

srand(time(NULL));
printf("Initial matrix:\n");
for (int i=0 ; i<xsize*ysize ; i++) {
    old_ptr[i] = rand() % 265;
    printf("%5.d  " , old_ptr[i]);
    if ((i+1) % xsize == 0)
        printf("\n");
}




printf("\n\n(Mean) Kernel matrix:\n");
for (int i=0 ; i<kernel*kernel ; i++) {
        kernel_ptr[i] = 1;
        printf("%d  " , kernel_ptr[i]);
        if ((i+1) % kernel == 0)
            printf("\n");
}


for ( int new_element = 0 ; new_element < xsize*ysize ; new_element++ ) 
{
   new_ptr[new_element] = 0;
   current_index = new_element - s*xsize - s;
   int i = 0;
   
   for (int rows = -s ; rows <= s ; rows++) {
      
      int row_middle = new_element+rows*xsize;
      if (row_middle<0)
         row_middle += s*xsize+1;







      for (int columns = -s ; columns <= s ; columns++) {         
         if (current_index >= 0 & current_index < xsize*ysize & (current_index / xsize) == ((row_middle ) / xsize))
            new_ptr[new_element] += old_ptr[current_index] * kernel_ptr[i];
         ++current_index;
         ++i;
      }
      current_index += xsize - kernel;
   }
}


printf("Final matrix:\n");
for (int i=0 ; i<xsize*ysize ; i++) {
    printf("%5.d  " , new_ptr[i]);
    if ((i+1) % xsize == 0)
        printf("\n");
}


return 0;
}


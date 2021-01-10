#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 10
#define KERNEL 5

int main() {

float k = KERNEL;
int s = (k-1)/2;
int old_matrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {0};
float new_matrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {0};
float mean_kernel[KERNEL][KERNEL] = {1};

srand(time(NULL));
printf("Initial matrix:\n");
for (int i=0 ; i<MATRIX_HEIGHT ; i++) {
    for (int j=0 ; j<MATRIX_WIDTH ; j++) {
        old_matrix[i][j] = rand() % 265;
        printf("%5.d    " , old_matrix[i][j]);
    }
    printf("\n");
}

printf("\n\n(Mean) Kernel matrix:\n");
for (int i=0 ; i<KERNEL ; i++) {
    for (int j=0 ; j<KERNEL ; j++) {
        mean_kernel[i][j] = 1;
        printf("%-4.2f  " , mean_kernel[i][j]);
    }
    printf("\n");
}

for (int i=0 ; i<MATRIX_HEIGHT ; i++) {
    for (int j=0 ; j<MATRIX_WIDTH ; j++) {
        for (int m=i-s , p=0 ; m<=i+s ; m++ , p++) {
            for (int n=j-s , q=0 ; n<=j+s ; n++ , q++) {
                if (m>=0 & m<MATRIX_HEIGHT & n>=0 & n<MATRIX_WIDTH)
                    new_matrix[i][j] += old_matrix[m][n] * mean_kernel[p][q];
            }
        }
    }
}



printf("\n\nFinal matrix:\n");
for (int i=0 ; i<MATRIX_HEIGHT ; i++) {
    for (int j=0 ; j<MATRIX_WIDTH ; j++) {
        printf("%7.2f  " , new_matrix[i][j]);
    }
    printf("\n");
}


printf("\n\nFinal matrix (integer values):\n");
for (int i=0 ; i<MATRIX_HEIGHT ; i++) {
    for (int j=0 ; j<MATRIX_WIDTH ; j++) {
        printf("%5.0f    " , new_matrix[i][j]);
    }
    printf("\n");
}

return 0;
}

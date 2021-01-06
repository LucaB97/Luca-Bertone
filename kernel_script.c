#include <stdio.h>
#include <stdlib.h>


void generate_kernel (float * kernel , const int type , const int dimension , const float weight)
{

switch (type) {
	case 0:
		for (int i = 0 ; i < dimension*dimension ; i++) {
			kernel[i] = 1 / (float)(dimension*dimension);
		}
		break;
                
	case 1:
		for (int i = 0 ; i < dimension*dimension ; i++) {
			if (i != (((dimension*dimension-1)/2)))
				kernel[i] = (1-weight)/(dimension*dimension-1);	
			else
				kernel[i] = weight;
		}
}
}


int main ( int argc, char **argv) {

float * kernel;
int kernel_type;
int kernel_dimension;
float kernel_weight;

if (argc > 2) {
	kernel_type = atoi ( *(argv + 1) );
	if (kernel_type == 0 | kernel_type == 1 | kernel_type == 2) {
		kernel_dimension = atoi ( *(argv + 2) );
		if (kernel_dimension % 2 == 0) {
			printf("The kernel dimension you entered is a even number (%d), but a odd number is required: %d + 1 = %d will be used.\n" , kernel_dimension , kernel_dimension , kernel_dimension + 1);
			++kernel_dimension; 
		}
	}
	else 
		printf("Admissable values for kernel type are: 0=mean kernel , 1=weighted kernel , 2=gaussian kernel\n");
	
	if (kernel_type == 1) {
		if (argc > 3) {
			kernel_weight = atof ( *(argv+3) );
			if (kernel_weight < 0 | kernel_weight > 1) {
				printf("You entered a weight which is out of the range (0,1). The default value of 1/(kernel_dimension^2) will be used.\n");
				kernel_weight = 1/(float)(kernel_dimension*kernel_dimension);
			}
		}
		else {
			printf("You did not specify a weight for central element of the Weighted kernel. The default value of 1/(kernel_dimension^2) will be used.\n");
			kernel_weight = 1/(float)(kernel_dimension*kernel_dimension);
		}
	}

kernel = (float *) calloc (kernel_dimension*kernel_dimension , sizeof(float) );
generate_kernel (kernel , kernel_type , kernel_dimension , kernel_weight);

printf("Kernel matrix:\n");
for (int i = 0 ; i < kernel_dimension*kernel_dimension ; i++) {
	printf("%.3f   " , *(kernel+i));
	if (i % kernel_dimension == kernel_dimension - 1)
		printf("\n");
}
}
else {
	printf("You should enter at least two values: one for kernel type and one for its dimension.\n");
}

return 0;

}


#include <stdio.h>
#include <stdlib.h>


void generate_kernel (float * kernel , int type , int dimension , float weight)
{

switch (type) {
	case 0:
		for (int i = 0 ; i < dimension*dimension ; i++)
			kernel[i] = 1 / (dimension*dimension);
                
	case 1:
		if (weight >= 0 & weight <= 1) {
			for (int i = 0 ; i < dimension*dimension ; i++)
					if (i != (((dimension*dimension-1)/2)))
						kernel[i] = (1-weight)/(dimension*dimension-1);	
					else
						kernel[i] = weight;
		
		}
		else 
			printf("You entered a weight which is out of range.\n");
               	
        

	
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
	
	if (kernel_type == 1) {
		if (argc > 3)
			kernel_weight = atof ( *(argv+3) );
		else {
			printf("You did not specify a value for the weight of central element of the Weighted kernel.\n");
			kernel_weight = 0;
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


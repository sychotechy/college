#include<stdio.h>
int main(){
	int rows,columns,i,j,k,zero,elements;
	float sparse;
	int count=0;
	printf("Enter the number of rows : ");
	scanf("%d",&rows);
	printf("Enter the number of columns : ");
	scanf("%d",&columns);
	int matrix[rows][columns];
	printf("Enter the elements of the matrix : ");
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(matrix[i][j]!=0){
				count++;
			}
		}
	}
	
	int sparseMatrix[count+1][3];
	sparseMatrix[0][0] = rows;
	sparseMatrix[0][1] = columns;
	sparseMatrix[0][2] = count;
	k=1;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(matrix[i][j]!=0){
				sparseMatrix[k][0] = i;
				sparseMatrix[k][1] = j;
				sparseMatrix[k][2] = matrix[i][j];
				k++;
			}
		}
	}
	
	printf("\n***** Normal Matrix *****\n");
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
	printf("\n***** Sparse Matrix *****\n");
	for(i=0;i<count+1;i++){
		for(j=0;j<3;j++){
			printf("%d\t",sparseMatrix[i][j]);
		}
		printf("\n");
	}
	
	elements = rows*columns;
	zero = elements-count;
	sparse = (float)zero/elements;
	printf("Sparcity of the matrix : %f",sparse);
}

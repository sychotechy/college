#include<stdio.h>
int a[50][3];
int matrix[50][3];
int matrixTranspose[50][3];


void read(int a[][3]){
	int rows,i,j;
	printf("Enter the number of non zero elements : ");
	scanf("%d",&rows);
	printf("Enter the sparse representation : ");
	for(i=0;i<rows;i++){
		for(j=0;j<3;j++){
			printf("Enter the element [%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}

void transpose(int matrix[][3], int matrixTranspose[][3]){
	int k,m,n;
	int i,j;
	matrixTranspose[0][0]=matrix[0][0];
	matrixTranspose[0][1]=matrix[0][1];
	matrixTranspose[0][2]=matrix[0][2];
 
	k=1;
	m=matrix[0][1];
	n=matrix[0][2];
 
	for(i=0;i<m;i++){
		for(j=1;j<n+1;j++){
			if(a[j][1]==i){
				matrixTranspose[k][0]=matrix[j][1];
	 			matrixTranspose[k][1]=matrix[j][0];
	 			matrixTranspose[k][2]=matrix[j][2];
	 			k++;
	 		}
	 	}
	}
	
	printf("Original matrix : \n");
	for(i=0;i<k;i++){
 		for(j=0;j<3;j++){
	 		printf("%d \t",matrix[i][j]);
	 	}
 		printf("\n");
 	}
 	printf("The transpose of the sparse matrix : \n");
	for(i=0;i<k;i++){
	 	for(j=0;j<3;j++){
	 		printf("%d \t",matrixTranspose[i][j]);
	 	}
		printf("\n");
	}
}
int main(){
	read(matrix);
	transpose(matrix,matrixTranspose);
}

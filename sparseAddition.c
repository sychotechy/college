#include<stdio.h>
int matrixOne[50][3];
int matrixTwo[50][3];
int resultMatrix[50][3];

void sparseAdd(int matrixOne[][3],int matrixTwo[][3], int resultMatrix[][3]){
	int row1,col1,row2,col2,i,j;
	row1 = matrixOne[0][0];
	col1 = matrixOne[0][1];
	row2 = matrixTwo[0][0];
	col2 = matrixTwo[0][1];
	if(row1!=row2 || col1!=col2){
		printf("Incomplete matrix size");
	}
	else{
		resultMatrix[0][0] = matrixOne[0][0];
		resultMatrix[0][1] = matrixOne[0][1];
		int m=1,n=1,k=1;
		for(i=0;i<row1;i++){
			for(j=0;j<col1;j++){
				if((matrixOne[m][0]==i && matrixOne[m][1]==j) && (matrixTwo[n][0]==i && matrixTwo[n][1]==j)){
					resultMatrix[k][0] = matrixOne[m][0];
					resultMatrix[k][1] = matrixOne[m][1];
					resultMatrix[k][2] = matrixOne[m][2] + matrixTwo[n][2];
					m++;
					n++;
					k++;
				}
				else if(matrixOne[m][0]==i && matrixOne[m][1]==j){
 					resultMatrix[k][0]=matrixOne[m][0];
 					resultMatrix[k][1]=matrixOne[m][1];
 					resultMatrix[k][2]=matrixOne[m][2];
 					m++;
 					k++;
 				}
	 			else if(matrixTwo[n][0]==i && matrixTwo[n][1]==j){
 					resultMatrix[k][0]=matrixTwo[n][0];
 					resultMatrix[k][1]=matrixTwo[n][1];
 					resultMatrix[k][2]=matrixTwo[n][2];
 					k++;
 					n++;
 				}
 			}
 		}
 		resultMatrix[0][2] = k-1;
 		printf("The sum of the sparse matrices : \n");
 		for(i=0;i<k;i++){
 			for(j=0;j<3;j++){
 				printf("%d\t",resultMatrix[i][j]);
 			}
 			printf("\n");
 		}
 	}
 }
					

int main(){
	int i,j,k,rows,columns;
	printf("\n**** Matrix One ****\n");
	printf("Enter the number of non zero elements : ");
	scanf("%d",&rows);
	printf("Enter the sparse representation : ");
	for(i=0;i<rows;i++){
		for(j=0;j<3;j++){
			printf("Enter the element [%d][%d] : ",i,j);
			scanf("%d",&matrixOne[i][j]);
		}
	}
	
	
	printf("\n**** Matrix Two ****\n");
	printf("Enter the number of non zero elements : ");
	scanf("%d",&rows);
	printf("Enter the sparse representation : ");
	for(i=0;i<rows;i++){
		for(j=0;j<3;j++){
			printf("Enter the element [%d][%d] : ",i,j);
			scanf("%d",&matrixTwo[i][j]);
		}
	}
	
	sparseAdd(matrixOne,matrixTwo,resultMatrix);
}

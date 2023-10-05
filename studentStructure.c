#include<stdio.h>
struct student{
	int rollno;
	char name[20];
	int physicsMark;
	int chemistryMark;
	int mathsMark;
	int englishMark;
	int computerMark;
	int totalMark;
}batch[50],temp;
void printDetails(struct student batch[],int maxStudent){
	int i;
	printf("\n");
	for(i=0;i<maxStudent;i++){
		printf("\n**** Student %d Details ****\n",i+1);
		printf("Rollno : %d\n",batch[i].rollno);
		printf("Name : %s\n",batch[i].name);
		printf("Physics Mark : %d\n",batch[i].physicsMark);
		printf("Chemistry Mark : %d\n",batch[i].chemistryMark);
		printf("Maths Mark : %d\n",batch[i].mathsMark);
		printf("English Mark : %d\n",batch[i].englishMark);
		printf("Computer Mark : %d\n",batch[i].computerMark);
		printf("Total Mark : %d\n",batch[i].totalMark);
	}
}
void calculateTotalMarks(struct student batch[],int maxStudent){
	int i;
	for(i=0;i<maxStudent;i++){
		batch[i].totalMark = batch[i].physicsMark+batch[i].chemistryMark+batch[i].mathsMark+batch[i].englishMark+batch[i].computerMark;
	}
}
void sortStudent(struct student batch[],int maxStudent){
	int i,j;
	for(i=0;i<maxStudent-1;i++){
		for(j=i+1;j<maxStudent;j++){
			if(batch[i].totalMark>batch[j].totalMark){
				temp = batch[i];
				batch[i] = batch[j];
				batch[j] = temp;
			}
		}
	}
}
int main(){
	int i,maxStudent;
	printf("Enter the number of students : ");
	scanf("%d",&maxStudent);
	printf("Enter details of students : ");
	for(i=0;i<maxStudent;i++){
		printf("Enter rollno (Student %d) : ",i+1);
		scanf("%d",&batch[i].rollno);
		printf("Enter name (Student %d) : ",i+1);
		scanf("%s",batch[i].name);
		printf("Enter marks of Physics,Chemistry,Maths,English and Computer (Student %d) : ",i+1);
		scanf("%d%d%d%d%d",&batch[i].physicsMark,&batch[i].chemistryMark,&batch[i].mathsMark,&batch[i].englishMark,&batch[i].computerMark);
	}
	calculateTotalMarks(batch,maxStudent);
	sortStudent(batch,maxStudent);
	printDetails(batch,maxStudent);
}

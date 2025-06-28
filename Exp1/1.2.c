#include<stdio.h>
#include<string.h>

struct Student {
	char name[100];
	int marks;
};

int main(){
	int n;
	printf("Enter the Number of Student: ");
	scanf("%d",&n);
	struct Student v[n];
	
	for(int i = 0 ; i < n ; i++){
		printf("Enter the Name: ");
		scanf("%s",v[i].name);
		printf("Enter the marks: ");
		scanf("%d",&v[i].marks);
	}
	FILE *fout;
	fout = fopen("student_data.txt","w");
	for(int i = 0 ; i < n ; i++){
		fprintf(fout,"Name:%s\n",v[i].name);
		fprintf(fout,"Marks:%d\n",v[i].marks);
		fprintf(fout,"\n");
	}
	fclose(fout);
	printf("Data is available in student_data.txt file\n");
	return 0;
}
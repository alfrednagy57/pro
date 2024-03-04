#include"../HeaderFiles/Fncs.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/*
	u16 StudentIndex=0,CouStd=0;
	u16 Course1[30]={0},Course2[30]={0},Course3[30]={0},Course4[30]={0};
	float	Avg[30]={0};
	ch8 Name[30][40];
	*/
//Main window
void MainWin(ch8 Name[][40], u16 *StudentIndex,u16*CouStd ,u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	printf("1-Enter student degree.\n");
	printf("2-Get 5 highest gpa.\n");
	printf("3-Get 5 lowest gpa.\n");
	printf("4-Press e to close the program.\n");
	sleep(5);
	//printf("\n\nThe system has %d Students\n\nStd index %d \n\n",GetCouStd(*CouStd),*StudentIndex);

	printf("\n\nEnter your choice : ");
	ch8 Select=0;
	Select=0;
	scanf(" %c",&Select);
	switch(Select){
		
		case '1':
			Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
			break;
		
		case '2':
			DisplayHigh5(Name, StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
			break;
		
		case '3':
			Displaylow5(Name, StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
			break;
		case 'e':
		case 'E':
		break;
		
		default:
			printf("Invalid option\n\n");
			MainWin(Name,StudentIndex,CouStd,C1,C2,C3,C4,State,Avg);
		break;
	}
}
//imp fnc
u16 GetCouStd(u16 CouStd)
{
	
	return CouStd;
}
u16 IsEmpty(u16 CouStd){
	
	if(0==CouStd) return 1;
	else return 0;
}
void GetName(ch8 Name[][40], u16 *StudentIndex,u16*CouStd){
	*CouStd++;
	printf("Enter student full name : ");
	scanf(" %[^\n]s",Name+*StudentIndex);
	*StudentIndex++;
	
}
void DisplayName(ch8 Name[][40], u16 StudentIndex){
	printf("%s",*(Name+StudentIndex));
}

//Student part
void Option1(ch8 Name[][40], u16 *StudentIndex,u16 *CouStd ,u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8 *State,float*Avg){
	system("cls");
	
	GetName(Name,StudentIndex,CouStd);
 	
	system("cls");
	GetDegree(C1,*StudentIndex,1);
	GetDegree(C2,*StudentIndex,2);
	GetDegree(C3,*StudentIndex,3);
	GetDegree(C4,*StudentIndex,4);
	printf("%d",*CouStd);
	system("cls");
	*(Avg + *StudentIndex)=GetAvg(C1,C2,C3,C4,*StudentIndex);
	DisplayDegree(C1,C2,C3,C4,*StudentIndex,Name,*Avg);
	sleep(10);
	system("cls");
	
	
	
	printf("1-Enter 1 to exit.\n");
	printf("2-Add another student.\n");
	printf("3-Back to first page.\n");
	sleep(5);
	printf("\n\nEnter your choice : ");
	ch8 Select=0;
	scanf("%d",&Select);
	if(1==Select){
		/*nothing*/
	}
	else if(2==Select){
		Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else if(3==Select){
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\n");
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
}
void GetDegree(u16 *C,u16 StudentIndex,u16 courseind){
		u16 Score=0;
		printf("\n\nEnter course %d degree : ",courseind);
		scanf("%d",&Score);
		if(Score>100||Score<0){
			printf("Invaild degree entered\n\nRe-enter a valid degree\n\n");
			GetDegree(C,StudentIndex,courseind);
		}
		else{
			*(C+StudentIndex)=Score;
		}
}
float GetAvg(u16*C1,u16*C2,u16*C3,u16*C4,u16 StudentIndex){
	float Avg=(float)(*(C1+StudentIndex)+*(C2+StudentIndex)+*(C3+StudentIndex)+*(C4+StudentIndex))/4;
	return (float)Avg;
}
void DisplayDegree(u16 *C1,u16 *C2,u16 *C3,u16 *C4,u16 StudentIndex,ch8 Name[][40],float Avg){
	if(60<=Avg)
	{
		printf("%s has successed with %0.5f%%\n",*(Name+StudentIndex),Avg);
		printf("He got %d/100 in course 1 \n",*(C1+StudentIndex));
		printf("He got %d/100 in course 2 \n",*(C2+StudentIndex));
		printf("He got %d/100 in course 3 \n",*(C3+StudentIndex));
		printf("He got %d/100 in course 4 \n",*(C4+StudentIndex));
	}
	else{
		
		printf("%s has failed with %0.5f%%\n\n",*(Name+StudentIndex),Avg);
		printf("He got %d/100 in course 1 \n",*(C1+StudentIndex));
		printf("He got %d/100 in course 2 \n",*(C2+StudentIndex));
		printf("He got %d/100 in course 3 \n",*(C3+StudentIndex));
		printf("He got %d/100 in course 4 \n",*(C4+StudentIndex));

	}
}
void swap (float*x,float *y){

	*y=*x+*y;
	*x=*y-*x;
	*y=*y-*x;
}	
void Sort(float*Avg){
	
	for(int Cou1=0;Cou1<9;Cou1++){
		for(int Cou2=0;Cou2<9-Cou1;Cou2++){
				if(*(Avg+Cou2)>*(Avg+Cou2+1)){
					swap(Avg+Cou2,Avg+Cou2+1);
				}
		}
	}
}


//option 2

void DisplayHigh5(ch8 Name[][40], u16 *StudentIndex,u16*CouStd ,u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	if(*CouStd==0){
		printf("You have to enter some students firsly\n\n");
		sleep(10);
		Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else if(*CouStd<5){
		printf("You have to enter %d students firsly\n\n",5-*CouStd);
		sleep(10);
		Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else {
		Sort(Avg);
		for(int Cou=29;Cou>4;Cou--){
		printf("The %d got %f\n",30-Cou,Avg+Cou);
		}
	}
	sleep(5);
	system("cls");
	printf("1-Enter 1 to exit.\n");
	printf("2-Add another student.\n");
	sleep(5);
	printf("\n\nEnter your choice : ");
	ch8 Select=0;
	scanf("%d",&Select);
	if(1==Select){
		/*nothing*/
	}
	else if(2==Select){
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\nYou will be directed to main page\n\n");
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
}


// option 3
void Displaylow5(ch8 Name[][40], u16 *StudentIndex,u16*CouStd ,u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	
	if(IsEmpty(*CouStd)==1){
		printf("You have to enter some students firsly\n\n");
		sleep(10);
		Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else if(*CouStd<5){
		printf("You have to enter %d students firsly\n\n",5-*CouStd);
		sleep(10);
		Option1(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else {
		Sort(Avg);
		for(int Cou=0;Cou<5;Cou++){
		printf("The %d got %f\n",30-Cou,Avg+Cou);
		}
		
	}
	sleep(5);
	system("cls");
	printf("1-Enter 1 to exit.\n");
	printf("2-Add another student.\n");
	sleep(5);
	printf("\n\nEnter your choice : ");
	ch8 Select=0;
	scanf("%d",&Select);
	if(1==Select){
		/*nothing*/
	}
	else if(2==Select){
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\nYou will be directed to main page\n\n");
		MainWin(Name,StudentIndex,CouStd ,C1,C2,C3,C4,State,Avg);
	}
}
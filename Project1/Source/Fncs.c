#include"../Headers/MainWin.h"
#include"../Headers/Fncs.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern u16 CouStd,CouS,CouF;

//imp fnc
void displayALL(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,float *Avg){
		
		for(int i=0;i<CouStd;i++)
		{
			printf("%s is %d %d %d %d %f\n",*(Name+i),*(C1+i),*(C2+i),*(C3+i),*(C4+i),*(Avg+i));
		}
}

void GetTotalFail_Succ(float *Avg){
	CouS=0;CouF=0;
	for(int i=0;i<CouStd;i++)
	{
		if(*(Avg+i)>=60) CouS++;
		else CouF++;			
	}
}

void GetName(ch8 Name[][40]){
	CouStd++;
	printf("Enter student full name : ");
	scanf(" %[^\n]s",Name+CouStd-1);	
}

void DisplayName(ch8 Name[][40], u16 StudentIndex){
	printf("%s",*(Name+StudentIndex));
}

//Student part
void Option1(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8 *State,float*Avg){
	system("cls");
	
	GetName(Name);
 	
	system("cls");
	GetDegree(C1,CouStd-1,1);
	GetDegree(C2,CouStd-1,2);
	GetDegree(C3,CouStd-1,3);
	GetDegree(C4,CouStd-1,4);
	system("cls");
	GetAvg(C1,C2,C3,C4,CouStd-1,Avg);
	DisplayDegree(C1,C2,C3,C4,CouStd-1,Name,*(Avg + CouStd-1));
	//GetTotalFail_Succ(Avg);
	*(Avg + CouStd-1)>=60?CouS++:CouF++;
	printf("\n\nTotal successed student is %d \nWhile failed are %d\n\n",CouS,CouF);
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
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else if(3==Select){
		system("cls");
		MainWin(Name,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\n");
		MainWin(Name,C1,C2,C3,C4,State,Avg);
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

void GetAvg(u16*C1,u16*C2,u16*C3,u16*C4,u16 StudentIndex,float *avg){
	*(avg+StudentIndex)=(float)( *(C1+StudentIndex)+ *(C2+StudentIndex) + *(C3+StudentIndex) + *(C4+StudentIndex) )/4;
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

void DisplayHigh5(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	if(CouStd==0){
		printf("You have to enter some students firstly\n\n");
		sleep(10);
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else if(CouStd<5){
		printf("You have to enter at least %d more students firstly\n\n",5-CouStd);
		sleep(10);
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else {
		Sort(Avg);
		for(int Cou=CouStd-1;Cou>CouStd-6;Cou--){
		printf("The %d got %f\n",CouStd-Cou,*(Avg+Cou));
		}
	}
	sleep(5);
	system("cls");
	printf("1-Enter 1 to exit.\n");
	printf("2-Add another student.\n");
	printf("3-Go to main main.\n");

	sleep(5);
	printf("\n\nEnter your choice : ");
	u16 Select=0;
	scanf("%d",&Select);
	if(1==Select){
		/*nothing*/
	}
	else if(2==Select){
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\nYou will be directed to main page\n\n");
		MainWin(Name,C1,C2,C3,C4,State,Avg);
	}
}


// option 3
void Displaylow5(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	
	if(CouStd==0){
		printf("You have to enter some students firstly\n\n");
		sleep(10);
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else if(CouStd<5){
		printf("You have to enter at least %d more students firstly\n\n",5-CouStd);
		sleep(10);
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else {
		Sort(Avg);
		for(int Cou=0;Cou<5;Cou++){
		printf("The %d got %f\n",CouStd-Cou,*(Avg+Cou));
		}
	}
	sleep(5);
	system("cls");
	printf("1-Enter 1 to exit.\n");
	printf("2-Add another student.\n");
	printf("3-Go to main main.\n");
	sleep(5);
	printf("\n\nEnter your choice : ");
	u16 Select=0;
	scanf("%d",&Select);
	if(1==Select){
		/*nothing*/
	}
	else if(2==Select){
		Option1(Name,C1,C2,C3,C4,State,Avg);
	}
	else{
		printf("Invalid option\nYou will be directed to main page\n\n");
		MainWin(Name,C1,C2,C3,C4,State,Avg);
	}
}
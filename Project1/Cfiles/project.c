#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include"../HeaderFiles/Fncs.h"



int main(){
	
	u16 StudentIndex=0,CouStd=0;
	u16 Course1[30]={0},Course2[30]={0},Course3[30]={0},Course4[30]={0};
	float	Avg[30]={0};
	ch8 Name[30][40];
	ch8 State=' ';
	do{
		sleep(3);
		system("cls");
		printf("Welcome to school management system\n\n\n");
		MainWin(Name,&StudentIndex,&CouStd ,Course1,Course2,Course3,Course4,&State,Avg);
		
		if(State!='e'&&State!='E') break;
		sleep(3);
		system("cls");
		printf("If you want to exit press e : ");
		scanf(" %c",&State);
	}while(State!='e'&&State!='E');
	return 0;
}
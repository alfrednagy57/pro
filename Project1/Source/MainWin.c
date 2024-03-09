#include"../Headers/MainWin.h"
#include"../Headers/Fncs.h"
#include<stdio.h>

//Main window
void MainWin(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg){
	
	printf("1-Enter student degree.\n");
	printf("2-Get 5 highest gpa.\n");
	printf("3-Get 5 lowest gpa.\n");
	printf("4-Press e to close the program.\n");
	printf("\n\nEnter your choice : ");
	ch8 Select=0;
	Select=0;
	scanf(" %c",&Select);
	switch(Select){
		
		case '1':
			Option1(Name,C1,C2,C3,C4,State,Avg);
			break;
		
		case '2':
			displayALL(Name,C1,C2,C3,C4,Avg);
			DisplayHigh5(Name,C1,C2,C3,C4,State,Avg);
			displayALL(Name,C1,C2,C3,C4,Avg);
			break;
		
		case '3':
			displayALL(Name,C1,C2,C3,C4,Avg);
			Displaylow5(Name,C1,C2,C3,C4,State,Avg);
			displayALL(Name,C1,C2,C3,C4,Avg);
			break;
		case 'e':
		case 'E':
		break;
		
		default:
			printf("Invalid option\n\n");
			MainWin(Name,C1,C2,C3,C4,State,Avg);
		break;
	}
}

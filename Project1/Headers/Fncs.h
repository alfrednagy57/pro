#ifndef Fncs_h
#define Fncs_h


//imp fncs
void GetName(ch8 Name[][40]);
void DisplayName(ch8 Name[][40], u16 StudentIndex);
void Sort(float*Avg);
void swap (float*x,float *y);
void displayALL(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,float * Avg);

void GetTotalFail_Succ(float *Avg);

//Student option 1 fnc
void Option1(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8 *State,float*Avg);
void GetDegree(u16 *C,u16 StudentIndex,u16 courseind);
void GetAvg(u16*C1,u16*C2,u16*C3,u16*C4,u16 StudentIndex,float *avg);
void DisplayDegree(u16 *C1,u16 *C2,u16 *C3,u16 *C4,u16 StudentIndex,ch8 Name[][40],float Avg);


//Student option 2 fnc
void DisplayHigh5(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg);
// option 3 fnc
void Displaylow5(ch8 Name[][40],u16 *C1,u16 *C2,u16 *C3,u16 *C4,ch8* State,float *Avg);
#endif
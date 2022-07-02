#include <stdio.h>
#include"adt.h"
#include<conio.h>
#define go(r,c) gotoxy(c,r)
#include<windows.h>

void clreol(int n){
	int i;
	for(i=1;i<=n;i++)
		putchar(' ');
	for(i=1;i<=n;i++)
	    putchar('\b');
}

void screen1();
void screen1_2();
void screen1_1();
void screen2();
void screen2_1();
void screen2_2();
void screen2_3();
void changepassword();
void screen2_1_1();
void screen2_1_2();
void screen2_1_3();
void screen2_1_4();
void screen2_2_1();
void screen2_2_2();
void screen2_2_3();
void screen2_2_4();
void screen2_1_1_1();
void screen2_2_1_1();
void screen2_2_1_2();
void screen2_2_1_3();
void screen2_2_1_4();
void screen2_2_2_1();
void screen2_2_2_2();
void screen2_2_2_3();
void screen2_2_2_4();
void screen2_2_3_1();
void screen2_2_3_2();
void screen2_2_3_3();
void screen2_2_3_4();
void screen2_2_4_1();
void screen2_2_4_2();
void screen2_2_4_3();
void screen2_2_4_4();
int screen_border(char title[])
 
{
//intializations
clrscr();
 
int i;
 
//exceptions
 
if(strlen(title) > 75) return 1;
 
//corners
 
gotoxy(1, 1);printf("%c", 201);
 
gotoxy(79, 1);printf("%c", 187);
 
gotoxy(1, 25);printf("%c", 200);
 
gotoxy(79, 25);printf("%c", 188);
 
//vertical lines
 
for (i = 1 + 1; i < 79; i++)
 
{
 
gotoxy(i, 1);printf("%c", 205);
 
gotoxy(i, 25);printf("%c", 205);
 
}
 
//horizontal lines
 
for (i = 1 + 1; i < 25; i++)
 
{
 
gotoxy(1, i);printf("%c", 186);
 
gotoxy(79, i);printf("%c", 186);
 
}
 
//printing title
 
gotoxy((79/2)-(strlen(title)/2),4);
 
printf("%s",title);
 
//making divider
 
gotoxy(1,6);
 
printf("%c",204);
 
for(i = 2 ; i < 79 ; i++) printf("%c",205);
 
printf("%c",185);
 
return 0;
 
}

 struct Student
{
	float maths,physics,chemistry,english,optional,biology,accountacy,bstd,economics,history,geography,political;
	float per;
	char *pcmgrade;
	char *cmgrade;
	char *pcbgrade;
	char *ahgrade;
	char *apt,*com;
	char *civil,*en,*ec,*cs,*me,*che;
	
}p;

typedef struct{char name[20],username[20],password[11],confirm[11],mobile[11];}user;
user u;
FILE *fp;
void screen1()
{ClearConsoleToColors(17,15);
	char ch,y,n;

	system("cls");
	go(10,20);screen_border("WELCOME TO THE STUDENT GUIDE");
	go(15,18);printf("Are you a new user!");
	go(20,22);printf("ENTER y for yes and n for no");
	for(;;){fflush(stdin);
	go(15,38);ch=getchar();
	switch(ch){
	case 'y': case'Y': screen1_1();break;
	case 'n': case'N': screen1_2();break;
	
	default: go(23,20);printf("INVALID INPUT");sleep(2);
	        go(23,20);clreol(15);go(15,38);clreol(8);

	}
	}
	}
int main(){
    screen1();
return 0;
}


void screen1_2(){ClearConsoleToColors(17,15);
	char userid[51],password[51],ch;int found=0;
	int i=0;
	clrscr();
	go(5,20); screen_border("User Authentication");
	go(8,20);printf("Username");
	go(10,20);printf("Password");fflush(stdin);
	go(8,32);gets(userid);
	go(10,32);
	while(i<50){
		ch=getch();
		if(ch==13) break;
		else if(ch==8){
			if(i>0){
				int n;
				i--;
				go(10,32);clreol(50);
				go(10,32);
				for(n=0;n<i;n++) putchar('*');
			}
		}
		else{
			password[i]=ch;
			putchar('*');
			i++;
		}
	}
	password[i]='\0';
	fp=fopen("newuser.dat","rb+");
	rewind(fp);
	while(fread(&u,sizeof(u),1,fp))
	{
	if(strcmp(userid,u.username)==0 && strcmp(password,u.password)==0)
	{
			found=1;
			break;
	}
	}
	if(found){
	go(15,20);	printf("Record found ");sleep(2);fclose(fp);
	screen2();
	}


	else
	{
		go(15,20);printf("Sorry Invalid authentication");
		sleep(2);fclose(fp);exit(0);

	}
}
void screen1_1()
{   ClearConsoleToColors(17,15);
	char ch;
	int i=0;
	fp=fopen("newuser.dat","rb+");

	if(fp==NULL)fp=fopen("newuser.dat","wb+");
	system("cls");
	go(10,30);//textcolor(YELLOW);
	screen_border("NEW USER");
	go(12,15);printf("Name:");go(12,35);//colorbox(20);
	go(14,15);printf("Username:");go(14,35);//colorbox(20);
	go(16,15);printf("Mobile no.:");go(16,35);//colorbox(20);
	go(18,15);printf("Password:");go(18,35);//colorbox(20);
	go(20,15);printf("Confirm password:");go(20,35);//colorbox(20);
	go(22,35);//textcolor(YELLOW);
	printf("PLEASE ENTER YOUR NAME");fflush(stdin);
	go(12,35);//textcolor(YELLOW);
	gets(u.name);
	go(22,35);clreol(20);
	printf("ENTER   YOUR   USERNAME");
	go(14,35);gets(u.username);//textcolor(YELLOW);
	go(22,35);clreol(25);
	printf("ENTER YOUR MOBILE NO.");

	for(;;){   go(16,35);                 clreol(10);
	gets(u.mobile);//textcolor(YELLOW);
	if(strlen(u.mobile)!=10){go(22,35);clreol(20);
	printf("enter 10 digit mobile no.");
	continue;}
	else{break;}}
	go(22,35);clreol(25);
	printf("ENTER YOUR PASSWORD");
	go(18,35); fflush(stdin);
	while(i<50){
		ch=getch();
		if(ch==13) break;
		if(ch==8){
			if(i>0){
				int n;
				i--;
				go(18,35);clreol(10);
				go(18,35);
				for(n=0;n<i;n++) putchar('*');
			}
		}
		else{
		       u.password[i]=ch;
			putchar('*');
			i++;
		}
	}
	u.password[i]='\0';

	//textcolor(YELLOW);
	go(22,35);clreol(20);
	printf("RE-ENTER YOUR PASSWORD");
		//textcolor(YELLOW);

 do{  
    go(22,35);clreol(22);
    printf("enter   above   password");
    i=0;
	  go(20,35);clreol(11);
	while(i<50)
	{
		ch=getch();
		if(ch==13) break;
		if(ch==8){
			if(i>0){
				int n;
				i--;
				go(20,35);clreol(11);
				go(20,35);
				for(n=0;n<i;n++) putchar('*');
			}
		}
		else{
		       u.confirm[i]=ch;
			putchar('*');
			i++;
		}
		}

	u.confirm[i]='\0';
    }
	while(strcmp(u.password,u.confirm)!=0);


	fseek(fp,0,SEEK_END);
	fwrite(&u,sizeof(u),1,fp);
	fclose(fp);go(23,40);
	printf("record added");go(24,40);
	system("pause");fclose(fp);screen2();
}




void screen2(){
	char choice;

		clrscr();
		ClearConsoleToColors(17,15);
		go(6,25);screen_border("Main menu");
		go(8,20);printf("1.Carrier Counseling");
		go(10,20);printf("2.Courses");
		go(12,20);printf("3.Exam");
        go(14,20);printf("4.Change Password");
	    go(16,20);printf("5.Quit");
		go(19,20);printf("Enter Your Choice 1/2/3/4/5:");
		for(;;){
		fflush(stdin);
		go(19,54);choice=getchar();
		switch(choice){
			case '1':
				screen2_1();break;
			case '2':
				screen2_2();break;
			case '3':
				screen2_3();break;
			case '4':
				changepassword();break;
			
            case '5':
			         exit(0);break;    
            default :
              go(22,20);printf("please give right input");
              sleep(2);go(22,20);clreol(47);go(19,54);clreol(5);
		       
				 
		}
	}
}


void screen2_1(){
char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>Carrier Counseling for 12th Pass Student<<<");
		go(9,21);printf("Select Your Stream and enter accordingly");
		go(12,20);printf("1.PCM");
		go(14,20);printf("2.PCB");
		go(16,20);printf("3.COMMERCE");
		go(18,20);printf("4.ARTS & HUMANITIES");
		go(20,20);printf("Return to main menu");
		go(22,20);printf("Enter 1/2/3/4 to continue r to return main menu:");
		for(;;){
		fflush(stdin);
		go(22,68);choice=getchar();
		switch(choice){
			case '1': 
				screen2_1_1();
				break;
			case '2':
				screen2_1_2();
				break;
			case '3':
				screen2_1_3();
				break;
			case '4':
				screen2_1_4();
				break;
			case 'r': 
				screen2();break;
			default:
			      go(24,22);printf("please give right input:");
		sleep(2);go(24,22);clreol(27);
		go(22,68);clreol(5);
		}
	}
}
void screen2_2(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>>COURSES<<<<<<");
		go(7,22);printf("*Choose Your Stream*");
		go(10,20);printf("1.Engineering");
		go(12,20);printf("2.Medical");
		go(14,20);printf("3.Commerce");
		go(16,20);printf("4.Arts & Humanities ");
		go(18,20);printf("Return to Main Menu");
		go(22,20);printf("Enter Choice:1/2/3/4/r or R:");
		for(;;){
         fflush(stdin);
		go(22,48);choice=getchar();
		switch(choice){
			case '1': 
				screen2_2_1();
				break;
			case '2': 
				screen2_2_2();
				break;
			case '3':
				screen2_2_3();
				break;
			case '4':
				screen2_2_4();
				break;
			case 'r': case 'R':
				screen2();break;
			default:
			    go(24,22);printf("invalid input");
                sleep(2);go(24,22);clreol(15);
                go(22,48);clreol(5);
		}
	}
}
void screen2_3(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>>EXAMS<<<<<<");
		go(7,22);printf("*Choose Your Stream*");
		go(10,20);printf("1.Engineering Entrance Exam");
		go(12,20);printf("2.Medical Entrance Exam");
		go(14,20);printf("3.Commerce Entrance Exam");
		go(16,20);printf("4.Arts & Humanities Entrance Exam");
		go(18,20);printf("Return to Main Menu");
		go(22,20);printf("Enter 1/2/3/4/r or R:");
		for(;;){
         fflush(stdin);
		go(22,58);choice=getchar();
		switch(choice){
			case '1':
				screen2_3_1();system("pause");screen2_3();
				break;
			case '2':
				screen2_3_2();system("pause");screen2_3();
				break;
			case '3': 
				screen2_3_3();system("pause");screen2_3();
				break;
			case '4': 
				screen2_3_4();system("pause");screen2_3();
				break;
			case 'r': case 'R':
				screen2();break;
			default:
			    go(24,22);printf("invalid input");sleep(2);go(24,22);clreol(15);
                go(22,58);clreol(5);

		}
	}
}



void screen2_3_1(){
	FILE *fp=fopen("Engineering Entrance Exam.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
    

}

void screen2_3_2(){
	FILE *fp=fopen("Medical Entrance Exam.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_3_3(){
	FILE *fp=fopen("Commerce Entrance Exam.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_3_4(){
	FILE *fp=fopen("Arts & Humanities Entrance Exam.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_1(){
	FILE *fp=fopen("Electronics & Communication Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_2(){
	FILE *fp=fopen("Computer science Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_3(){
	FILE *fp=fopen("Mechanical Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_4(){
	FILE *fp=fopen("Chemical Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_5(){
	FILE *fp=fopen("Electrical Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_1_6(){
	FILE *fp=fopen("Civil Engineering.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_2_1(){
	FILE *fp=fopen("MBBS.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_2_2(){
	FILE *fp=fopen("BDS.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_2_3(){
	FILE *fp=fopen("B-Pharm.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_2_4(){
	FILE *fp=fopen("BAMS.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_3_1(){
	FILE *fp=fopen("B.com.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_3_2(){
	FILE *fp=fopen("CMA.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();

}
void screen2_2_3_3(){
	FILE *fp=fopen("BBA.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_2_3_4(){
	FILE *fp=fopen("CA.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_2_4_1(){
	FILE *fp=fopen("Humanities & Social Sciences.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_2_4_2(){
	FILE *fp=fopen("BA.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_2_4_3(){
	FILE *fp=fopen("BFA","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}
void screen2_2_4_4(){
	FILE *fp=fopen("B Des.txt","r");
	char ch;
	clrscr();
	ch=fgetc(fp);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp);
	}
    fclose(fp);
    getch();
}


int validmarks(float n){if(!(n>=1&&n<100))
return 0;
}
void screen2_1_1(){
	clrscr();
    go(5,22);printf("Please Enter Marks");
    for(;;){
	go(8,22);clreol(50);printf("Maths : ");
    go(8,32);scanf("%f",&p.maths);if(validmarks(p.maths)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(10,22);clreol(50);printf("Physics : ");
    go(10,32);scanf("%f",&p.physics);if(validmarks(p.physics)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(12,22);clreol(50);printf("Chemistry:");
    go(12,32);scanf("%f",&p.chemistry);if(validmarks(p.chemistry)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(14,22);clreol(50);printf("English : ");
    go(14,32);scanf("%f",&p.english);if(validmarks(p.english)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(16,22);clreol(50);printf("Optional : ");
    go(16,32);scanf("%f",&p.optional);if(validmarks(p.optional)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
     p.per=(p.maths+p.physics+p.chemistry+p.english+p.optional)/5.0;
	 if(p.per>=80)
       p.pcmgrade="You are a brilliant student";
    else if(p.per>=60 &&p.per<80)
      p.pcmgrade="You are a good student";
    else if(p.per>=33 &&p.per<60)
      p.pcmgrade="you are an average student";
    else
     p.pcmgrade="You are too weak in studies";
    go(17,16);printf("Student Marks Has Been submitted ");
	go(20,16);printf("Press any key to continue...");
	go(20,58);getch();
	go(24,20);printf("loading...");
	sleep(2);
	screen2_1_1_q1();
}
void screen2_1_1_q1(){
	clrscr();
	go(5,22); screen_border(">>Hey there! Your goal to discover right career has begun<<");
	go(8,22);printf("Please wait...");
    sleep(3);
	
	clrscr();
    go(8,20); printf("Are you a good problem solver?");
   
    go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    { fflush(stdin);
	go(14,35);
	char ch=getchar();
    switch (ch)
    {
	case '1':
    
    go(18,20);  printf("press any key continue:");
    go(18,50);getch();
    screen2_1_1_q2();break;


    case '2':
     p.apt="YOU DON'T HAVE PROBLEM SOLVING SKILLS...PLEASE DO DEVELOP IT";
     go(18,20);  printf("press any key continue:");
     go(18,50);getch();
	 screen2_1_1_q3();
     break;
    default:
        go(22,22); printf("please Enter right input:[1/2]");
        sleep(2);go(22,22);clreol(35);
		go(14,35);
	    clreol(5);
    }
    
}
}

void screen2_1_1_q2(){
	
	clrscr();
	go(8,20); printf("The difference between the value of the number increased by 20%% and .");
	go(10,20);printf("the value of the number decreased by 25%% is 36 What is the number?");
	go(12,20);printf("1. 720");
	go(14,20);printf("2. 80");
	go(16,20);printf("3. 72");
	go(18,20);printf("4.360");
	go(20,20);printf("Please select option:");
	for(;;){
	fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch(choice){
	case '2':
		p.apt="You are a good problem solver";
         go(22,22);printf("press Enter to continue");
        go(22,50);getch();
		screen2_1_1_q3();break;
	
	case '1': case '3' : case '4':
	
		p.apt="You have to improve your problem solving skill";
        go(22,22);printf(" Enter to continue");
        go(22,50);getch();
		screen2_1_1_q3();break;
	
	default:
		go(22,22);printf("give right input");
		sleep(2);go(22,22);clreol(18);go(20,45);clreol(5);
		
	}
}
}
void screen2_1_1_q3(){
	
	
	clrscr();
    go(8,20); printf("How good are your communication skill?");
    
    go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);
	
	char cn=getchar();
	switch (cn)
	{
	
	case '1':
    
		
     screen2_1_1_q4();
     break;


   case '2':
     p.com="YOU DON'T HAVE GOOD COMMUNICATION SKILLS...PLEASE DO DEVELOP IT";
	 screen2_1_1_q5();
     break;
    
    default:
       go(22,22); printf("please Enter right input:[1/2]");
      sleep(2);go(22,22);clreol(35);go(14,35);clreol(5);
	  
	}
    
    }

}
void screen2_1_1_q4(){
	clrscr();
	
	go(10,20); printf("Do you have a tendency to steer clear of certain subject areas, ");
    go(12,20);printf(" (e.g. money, household chores) in order to avoid conflict?");

	go(14,20);printf("1. YES");
	go(16,20);printf("2. NO");
	go(20,20);printf("Please select option:");
	for(;;){fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch (choice)
	{
	case '1':
	
		p.com="You are  good in communication";
         go(22,22);printf("press any to continue");
         go(22,40);getch();
		 go(20,45);
		screen2_1_1_q5();break;
	
	case '2':
	
		p.com="You have to improve your communication skill";
        go(22,22);printf(" press any key to continue:");
        go(22,40);getch();
		screen2_1_1_q5();break;
	
	default:
		go(22,22);printf("give right input:");
        sleep(2);go(22,22);clreol(18);go(20,45);clreol(5);
	}
}
}
void screen2_1_1_q5(){
	clrscr();
	go(5,18);screen_border("Questions below are the situations you face in your everyday life:");
	sleep(4);
	go(7,18);screen_border("<<Please choose the option which appeals to you the most>>");
	go(9,20);printf("**BEST OF LUCK**");
	go(11,20);printf("Lets Continue:");
	go(11,35);getch();
	int i;

     for(i=1;i<=4;i++)
     {
    clrscr();
    int r1=i;
     switch(r1)
		{
		case 1:
		for(;;){
			clrscr();
		go(5,18);printf("Do you really keen interested in knowing how the buildings are constructed?:");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.civil="You can choose civil Engineering";
				break;
}
		else if ((getch())=='2')
		       {
		          p.civil=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
		
	}
		
    case 2:
		for(;;){
			clrscr();
		go(4,15);printf("Suppose at your home any of the home appliance get damaged.");
		go(6,15);printf("Do you eager to fix it yourself?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.go to mechanic");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.en="You can choose Electrical Engineering";
				break;
}
		else if ((getch())=='2')
		       {
		          p.en=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	 case 3:
		for(;;){
		clrscr();
		go(5,15);printf("What do you think Earth looks beautiful from land or space?");
		go(8,22);printf("1.land");
		go(10,22);printf("2.space");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.ec="";
				break;
				

}
		else if ((getch())=='2')
		       {
		          p.ec="You can choose Electronic and Communication Engineering ";
				  
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	case 4:
		for(;;){
		clrscr();
		go(4,18);printf("During your chemistry lab class,a chemical explosion happened.");
        go(6,18);printf("Do you know why?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.doesn't matter");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.che="You can choose Chemical Engineering";
				break;
}
		else if ((getch())=='2')
		       {
		          p.che=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	default:

	  clrscr();
	  go(5,22);screen_border("**Thank You for using our platform**");
	  go(8,22);printf("Press any key to continue:");
	  go(8,50);
	  getch();
	  output1();
		}
	 }
}

void screen2_1_2(){
	clrscr();fflush(stdin);
    go(5,28);printf("Please Enter Marks ");
    for(;;){
	go(8,22);clreol(50);printf("Biology : ");
    go(8,32);scanf("%f",&p.biology);if(validmarks(p.biology)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(10,22);clreol(50);printf("Physics : ");
    go(10,32);scanf("%f",&p.physics);if(validmarks(p.physics)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(12,22);clreol(50);printf("Chemistry:");
    go(12,32);scanf("%f",&p.chemistry);if(validmarks(p.chemistry)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(14,22);clreol(50);printf("English : ");
    go(14,32);scanf("%f",&p.english);if(validmarks(p.english)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(16,22);clreol(50);printf("Optional : ");
    go(16,32);scanf("%f",&p.optional);if(validmarks(p.optional)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
     p.per=(p.biology+p.physics+p.chemistry+p.english+p.optional)/5.0;
    if(p.per>=80)
       p.pcbgrade="You are a brilliant student";
    else if(p.per>=60 &&p.per<80)
      p.pcbgrade="You are a good student";
    else if(p.per>=33 &&p.per<60)
      p.pcbgrade="you are an average student";
    else
     p.pcbgrade="You are too weak in studies";
    go(17,16);printf("Student Marks Has Been Submitted ");
	go(20,16);printf("Press any key to continue...");
	getch();
	sleep(3);
	screen2_1_1_b1();

}
void screen2_1_1_b1(){
	clrscr();
	go(5,22); screen_border(">>Hey there! Your goal to discover right career has begun<<");
	go(8,22);printf("Please wait...");
    sleep(3);

	clrscr();
    go(8,20); printf("Are you a good problem solver?");
    
    go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);
	char ch=getchar();
    switch (ch)
    {
	case '1':
    
      go(18,20);  printf("press any key continue:");
     go(18,50);getch();
     screen2_1_1_b2();break;

    case '2':
     p.apt="YOU DON'T HAVE PROBLEM SOLVING SKILLS...PLEASE DO DEVELOP IT";
     go(18,20);  printf("press any key continue:");
     go(18,50);getch();
	 screen2_1_1_b3();
     break;
    default:
        go(22,22); printf("please Enter right input:[1/2]");
        sleep(1);go(22,22);clreol(38);
		go(14,35);clreol(5);
		
    }
}
}

void screen2_1_1_b2(){
	
	clrscr();
	go(8,20); printf("The difference between the value of the number increased by 20%% and .");
	go(10,20);printf("the value of the number decreased by 25%% is 36 What is the number?");
	go(12,20);printf("1. 720");
	go(14,20);printf("2. 80");
	go(16,20);printf("3. 72");
	go(18,20);printf("4.360");
	go(20,20);printf("Please select option:");
	for(;;){
	fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch(choice){
	case '2':
		p.apt="You are a good problem solver";
         go(22,22);printf("press Enter to continue");
        go(22,50);getch();
		screen2_1_1_b3();break;
	
	case '1': case '3' : case '4':
	
		p.apt="You have to improve your problem solving skill";
        go(22,22);printf(" Enter to continue");
        go(22,50);getch();
		screen2_1_1_b3();break;
	
	default:
		go(22,22);printf("give right input");
		sleep(2);go(22,22);clreol(17);go(20,45);clreol(5);
		
	}
}
}
void screen2_1_1_b3(){
	
	clrscr();
    go(8,20); printf("Are you good in communication skills?");
      go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);
	
	char cn=getchar();
	switch (cn)
	{
	
	case '1': 
     screen2_1_1_b4();
     break;


   case '2':
     p.com="YOU DON'T HAVE GOOD COMMUNICATION SKILLS...PLEASE DO DEVELOP IT";
	 screen2_1_1_b4();
     break;
    
    default:
       go(22,22); printf("please Enter right input:[1/2]");
      sleep(2);go(22,22);clreol(35);go(14,35);clreol(5);
	  
	}
    
    }

}
void screen2_1_1_b4(){
	clrscr();
	
	go(10,20); printf(" Do you have a tendency to steer clear of certain subject areas, ");
    go(12,20);printf(" (e.g. money, household chores) in order to avoid conflict?");

	go(14,20);printf("1. YES");
	go(16,20);printf("2. NO");
	go(20,20);printf("Please select option:");
	for(;;){fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch (choice)
	{
	case '1':
	
		p.com="You are  good in communication";
         go(22,22);printf("press any to continue");
         go(22,40);getch();
		 go(20,45);
		screen2_1_1_b5();break;
	
	case '2':
	
		p.com="You have to improve your communication skill";
        go(22,22);printf(" press any key to continue:");
        go(22,40);getch();
		screen2_1_1_b5();break;
	
	default:
		go(22,22);printf("give right input:");
        sleep(2);go(22,22);clreol(17);go(20,45);clreol(5);
	
	}
}
	

}
void screen2_1_1_b5(){
	clrscr();
	go(5,18);screen_border("Questions below are the interests you face in your everyday life:");
	sleep(2);
	go(7,18);printf("<<Please choose the option which appeals to you the most>>");
	go(9,20);printf("**BEST OF LUCK**");
	go(11,20);printf("Lets Continue:");
	go(11,35);getch();
	int i;

     for( i=1;i<=4;i++)
     {
    clrscr();
    int r1=i;
     switch(r1)
		{
		case 1:
		for(;;){
			clrscr();
		go(4,18);printf("Do you have investigative, realistic, artistic interests? ");
		
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.civil="You can go for BDS";
				break;
}
		else if ((getch())=='2')
		       {
		          p.civil=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
		
	}
		
    case 2:
		for(;;){
			clrscr();
		go(4,15);printf("Are you interested to know how ayurveda and modern medicines relate with each other?");		
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.en="you can choose BAMS";
				break;
}
		else if ((getch())=='2')
		       {
		          p.en=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	 case 3:
		for(;;){
			clrscr();
		go(5,15);printf("Are you interested to work in a range of industries related to the ");
		go(7,15);printf("prescription, manufacture & provision of medicines.");
		go(9,22);printf("1.Yes");
		go(11,22);printf("2.No");
		go(13,22);printf("Enter [1/2]:");
		go(15,34);
		if ((getch())=='1')
			{
			    p.ec="You can go for B.PHARMA";
				break;
				

}
		else if ((getch())=='2')
		       {
		          p.ec="";
				  
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	case 4:
		for(;;){
			clrscr();
		go(5,15);printf("Do you have commitment to human service, rural patient care, etc?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.No");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.che="You can choose MBBS";
				break;
}
		else if ((getch())=='2')
		       {
		          p.che=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	default:

	clrscr();
	  go(5,22);screen_border("**Thank You for using our platform**");
	  go(8,22);printf("Press any key to continue:");
	  go(8,50);
	  getch();
	  output2();
		}
	 }
}

void screen2_1_3(){
	clrscr();
    go(5,28);printf("Please Enter Marks ");
    for(;;){
	
    go(8,22);clreol(50);printf("Accountancy : ");
    go(8,35);scanf("%f",&p.accountacy);if(validmarks(p.accountacy)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(10,22);clreol(50);printf("Business Studies : ");
    go(10,40);scanf("%f",&p.bstd);if(validmarks(p.bstd)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(12,22);clreol(50);printf("Economics : ");
    go(12,34);scanf("%f",&p.economics);if(validmarks(p.economics)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;)
	{
	go(14,22);clreol(50);printf("English : ");
    go(14,32);scanf("%f",&p.english);if(validmarks(p.english)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(16,22);clreol(50);printf("Optional : ");
    go(16,32);scanf("%f",&p.optional);if(validmarks(p.optional)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
    p.per=(p.accountacy+p.bstd+p.economics+p.english+p.optional)/5;
    if(p.per>=80)
       p.cmgrade="You are a brilliant student";
    else if(p.per>=60 &&p.per<80)
      p.cmgrade="You are a good student";
    else if(p.per>=33 &&p.per<60)
      p.cmgrade="you are an average student";
    else
     p.cmgrade="You are too weak in studies";
    go(17,16);printf("Student Marks Has Been Submitted ");
	go(20,16);printf("Press any key to continue...");
	getch();
	sleep(2);
		screen2_1_1_c1();

}
void screen2_1_1_c1(){
	clrscr();
	go(5,22); screen_border(">>Hey there! Your goal to discover right career has begun<<");
	go(8,22);printf("Please wait...");
    sleep(3);

	clrscr();
    go(8,20); printf("Are you a good problem solver?");
    
    go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);

	
	
	char ch=getchar();
    switch (ch)
    {
	case '1':
    
      go(18,20);  printf("press any key continue:");
     go(18,50);getch();
     screen2_1_1_c2();break;


    case '2':
     p.apt="YOU DON'T HAVE PROBLEM SOLVING SKILLS...PLEASE DO DEVELOP IT";
     go(18,20);  printf("press any key continue:");
     go(18,50);getch();
	 screen2_1_1_c3();
     break;
    default:
        go(22,22); printf("please Enter right input:[1/2]");
        sleep(2);go(22,22);clreol(37);
		go(14,35);clreol(5);
		
    }
    
}
}


void screen2_1_1_c2(){

	clrscr();
	go(8,20); printf("The difference between the value of the number increased by 20%% and .");
	go(10,20);printf("the value of the number decreased by 25%% is 36 What is the number?");
	go(12,20);printf("1. 720");
	go(14,20);printf("2. 80");
	go(16,20);printf("3. 72");
	go(18,20);printf("4.360");
	go(20,20);printf("Please select option:");
		for(;;){
	fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch(choice){
	case '2':
		p.apt="You are a good problem solver";
         go(22,22);printf("press Enter to continue");
        go(22,50);getch();
		screen2_1_1_c3();break;
	
	case '1': case '3' : case '4':
	
		p.apt="You have to improve your problem solving skill";
        go(22,22);printf(" Enter to continue");
        go(22,50);getch();
		screen2_1_1_c3();break;
	
	default:
		go(22,22);printf("give right input");
		sleep(2);go(22,22);clreol(17);go(20,45);
		clreol(5);
		
	}
}
}
void screen2_1_1_c3(){
	
	
	clrscr();
    go(8,20); printf("Are you good in communication skills?");  
	go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);
	
	char cn=getchar();
	switch (cn)
	{
	
	case '1': 
    
		
     screen2_1_1_c4();
     break;


   case '2':
     p.com="YOU DON'T HAVE GOOD COMMUNICATION SKILLS...PLEASE DO DEVELOP IT";
	 screen2_1_1_c4();
     break;
    
    default:
       go(22,22); printf("please Enter right input:[1/2]");
      sleep(1);go(22,22);clreol(38);go(14,35);clreol(5);
	  
	}
    
    }

}
void screen2_1_1_c4(){
	clrscr();

		clrscr();
	go(10,20); printf(" Do you have a tendency to steer clear of certain subject areas, *");
    go(12,20);printf(" (e.g. money, household chores) in order to avoid conflict?");

	go(14,20);printf("1. YES");
	go(16,20);printf("2. NO");
	go(20,20);printf("Please select option:");
		for(;;){fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch (choice)
	{
	case '1':
	
		p.com="You are  good in communication";
         go(22,22);printf("press any to continue");
         go(22,40);getch();
		 go(20,45);
		screen2_1_1_c5();break;
	
	case '2':
	
		p.com="You have to improve your communication skill";
        go(22,22);printf(" press any key to continue:");
        go(22,40);getch();
		screen2_1_1_c5();break;
	
	default:
		go(22,22);printf("give right input:");
        sleep(2);go(22,22);clreol(17);go(20,45);clreol(5);

	}
}
	

}
void screen2_1_1_c5(){
	clrscr();
	go(5,18);screen_border("Questions below are the interests you face in your everyday life:");
	sleep(2);
	go(7,18);screen_border("<<Please choose the option which appeals to you the most>>");
	go(9,20);printf("**BEST OF LUCK**");
	go(11,20);printf("Lets Continue:");
	go(11,35);getch();
	int i;

     for( i=1;i<=4;i++)
     {
    clrscr();
    int r1=i;
     switch(r1)
		{
		case 1:
		for(;;){
			clrscr();
		go(4,18);printf("Are you comfortable to keep track of share price on a daily basis");
		go(6,18);printf(" and advise people for investing in shares?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.civil="You can choose CMA";
				break;
}
		else if ((getch())=='2')
		       {
		          p.civil=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
		
	}
		
    case 2:
		for(;;){
			clrscr();
		go(4,15);printf("Can you work as a professional who prepares accounting records,");
		go(6,15);printf("processes taxes give reports regarding expenses to company?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.en="You can prepare for CA";
				break;
}
		else if ((getch())=='2')
		       {
		          p.en=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	 case 3:
		for(;;){
			clrscr();
		go(4,15);printf("Can you work as professional who use mathematical and satistical skills");
		go(6,15);printf("to make financial concepts easy for understanding?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.ec="You can go for B.com";
				break;
				

}
		else if ((getch())=='2')
		       {
		          p.ec=" ";
				  
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	case 4:
		for(;;){
			clrscr();
		go(5,15);printf("Do you have the ability to read the country's economy?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.che="You can choose BBA";
				break;
}
		else if ((getch())=='2')
		       {
		          p.che=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	default:

	clrscr();
	  go(5,22);screen_border("**Thank You for using our platform**");
	  go(8,22);printf("Press any key to continue:");
	  go(8,50);
	  getch();
	  output3();
		}
	 }
}


void screen2_1_4(){
	clrscr();
    go(5,28);printf(">>Please Enter Marks <<");
    for(;;){
	
    go(8,22);clreol(50);printf("History : ");
    go(8,32);scanf("%f",&p.history);if(validmarks(p.history)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	go(10,22);clreol(50);printf("Geography : ");
    go(10,35);scanf("%f",&p.geography);if(validmarks(p.geography)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(12,22);clreol(50);printf("Political Science : ");
    go(12,42);scanf("%f",&p.political);if(validmarks(p.political)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(14,22);clreol(50);printf("English : ");
    go(14,32);scanf("%f",&p.english);if(validmarks(p.english)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
	for(;;){
	
	go(16,22);clreol(50);printf("Optional : ");
    go(16,32);scanf("%f",&p.optional);if(validmarks(p.optional)){break;
	}
	else {
	go(18,16);printf("invalid marks");sleep(1);go(18,16);clreol(15);}}
     p.per=(p.history+p.geography+p.political+p.english+p.optional)/5.0;
    if(p.per>=80)
       p.ahgrade="You are a brilliant student";
    else if(p.per>=60 &&p.per<80)
      p.ahgrade="You are a good student";
    else if(p.per>=33 &&p.per<60)
      p.ahgrade="you are an average student";
    else
     p.ahgrade="You are too weak in studies";
    go(17,32);printf("Student Marks Has Been Submitted ");
	go(19,16);printf("Press any key to continue...");
	getch();
	sleep(2);
	screen2_1_1_h1();

}
void screen2_1_1_h1(){
	clrscr();
	go(5,22); screen_border(">>Hey there! Your goal to discover right career has begun<<");
	go(8,22);printf("Please wait...");
    sleep(3);
	
		clrscr();
    go(8,20); printf("Are you a good problem solver?");
    fflush(stdin);
    go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);

	
	
	char ch=getchar();
    switch (ch)
    {
	case '1':
    
     go(18,20);  printf("press any key continue:");
     go(18,50);getch();
     screen2_1_1_h2();break;


    case '2':
     p.apt="YOU DON'T HAVE PROBLEM SOLVING SKILLS...PLEASE DO DEVELOP IT";
     go(18,20);  printf("press any key continue:");
     go(18,50);getch();
	 screen2_1_1_h3();
     break;
    default:
        go(22,22); printf("please Enter right input:[1/2]");
        sleep(2);go(22,22);clreol(38);
		go(14,35);clreol(5);
	
    }
    
}
}


void screen2_1_1_h2(){

	clrscr();
	go(8,20); printf("The difference between the value of the number increased by 20%% and .");
	go(10,20);printf("the value of the number decreased by 25%% is 36 What is the number?");
	go(12,20);printf("1. 720");
	go(14,20);printf("2. 80");
	go(16,20);printf("3. 72");
	go(18,20);printf("4.360");
	go(20,20);printf("Please select option:");
		for(;;){
	fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch(choice){
	case '2':
		p.apt="You are a good problem solver";
         go(22,22);printf("press Enter to continue");
        go(22,50);getch();
		screen2_1_1_h3();break;
	
	case '1': case '3' : case '4':
	
		p.apt="You have to improve your problem solving skill";
        go(22,22);printf(" Enter to continue");
        go(22,50);getch();
		screen2_1_1_h3();break;
	
	default:
		go(22,22);printf("give right input");
		sleep(2);go(22,22);clreol(17);go(20,45);clreol(5);
		
	}
}
}
void screen2_1_1_h3(){
	
	
	clrscr();
    go(8,20); printf("How good are your communication skill?");  go(10,22);printf("1. YES");
    go(12,22);printf("2. NO");
    go(14,22);printf("ENTER 1/2");
    for (;;)
    {fflush(stdin);
	go(14,35);
	
	char cn=getchar();
	switch (cn)
	{
	
	case '1': 
    
		
     screen2_1_1_h4();
     break;


   case '2':
     p.com="YOU DON'T HAVE GOOD COMMUNICATION SKILLS...PLEASE DO DEVELOP IT";
	 screen2_1_1_h4();
     break;
    
    default:
       go(22,22); printf("please Enter right input:");
      sleep(2);	go(22,22);clreol(38);go(14,35);clreol(5);
	  
	}
    
    }

}
void screen2_1_1_h4(){
	clrscr();
	
	go(10,20); printf(" Do you have a tendency to steer clear of certain subject areas, ");
    go(12,20);printf(" (e.g. money, household chores) in order to avoid conflict?");

	go(14,20);printf("1. YES");
	go(16,20);printf("2. NO");
	go(20,20);printf("Please select option:");
	for(;;){fflush(stdin);
	go(20,45);
	char choice=getchar();
	switch (choice)
	{
	case '1':
	
		p.com="You are  good in communication";
         go(22,22);printf("press any to continue");
         go(22,40);getch();
		 go(20,45);
		screen2_1_1_h5();break;
	
	case '2':
	
		p.com="You have to improve your communication skill";
        go(22,22);printf(" press any key to continue:");
        go(22,40);getch();
		screen2_1_1_h5();break;
	
	default:
		go(22,22);printf("give right input:");
        sleep(2);go(22,22);clreol(18);go(20,45);clreol(5);
	
	}
}
	

}
void screen2_1_1_h5(){
	clrscr();
	go(5,18);screen_border("Questions below are the situations you face in your everyday life:");
	sleep(2);
	go(7,18);screen_border("<<Please choose the option which appeals to you the most>>");
	go(9,20);printf("**BEST OF LUCK**");
	go(11,20);printf("Lets Continue:");
	go(11,35);getch();
	int i;

     for( i=1;i<=4;i++)
     {
    clrscr();
    int r1=i;
     switch(r1)
		{
		case 1:
		for(;;){
			
			clrscr();
		go(4,18);printf("Are you comfortable to cover any recent news,event,innovation or development");
		go(6,18);printf("and write to broadcast it in the world");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.NO");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.civil="You can try for journalism";
				break;
}
		else if ((getch())=='2')
		       {
		          p.civil=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
		
	}
		
    case 2:
		for(;;){
			clrscr();
		go(4,15);printf("Are you comfortable to work non stop for long hour to reach .");
		go(6,15);printf("up to positon for betterment of country?");
		go(8,22);printf("1.YES");
		go(10,22);printf("2.No");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.en="you can try for public administrative service";
				break;
}
		else if ((getch())=='2')
		       {
		          p.en=" "; 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	 case 3:
		for(;;){
		clrscr();
		go(5,15);printf("Are you comfortable to whether forecasting and natural calamaties ");
		go(8,22);printf("1.Yes");
		go(10,22);printf("2.No");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.ec="you can become a geographer";
				break;
				

}
		else if ((getch())=='2')
		       {
		          p.ec="";
				  
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	case 4:
		for(;;){
		clrscr();
		go(4,15);printf("Do like to know about ancient India and Contemporary world");
	
		go(8,22);printf("1.YES");
		go(10,22);printf("2.No");
		go(12,22);printf("Enter [1/2]:");
		go(12,34);
		if ((getch())=='1')
			{
			    p.che="You can become a Historian";
				break;
}
		else if ((getch())=='2')
		       {
		          p.che=" ";
				 
		       break;
		       }
		else
		{
			go(22,22);printf("please enter right input");
			sleep(2);
		}
	}
	default:

	clrscr();
	  go(5,22);screen_border("**Thank You for using our platform**");
	  go(8,22);printf("Press any key to continue:");
	  go(8,50);
	  getch();
	  output4();
		}
	 }
}
	


void screen2_2_1(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>>ENGINEERING COURSES<<<<<<");
		go(7,22);printf("*Choose Your Branch*");
		go(10,20);printf("A.Electronics and Communication Engineering (ECE)");
		go(12,20);printf("B.Computer Science Engineering (CSE)");
		go(14,20);printf("C.Mecahanical Engineering");
		go(16,20);printf("D.Chemical Engineering ");
		go(18,20);printf("E.Electrical Engineering ");
		go(20,20);printf("F.Civil Engineering ");
		go(22,20);printf("G.Return to Main Menu");
		go(24,20);printf("Enter Choice:A/B/C/D/E/F/G:");
		for(;;){
         fflush(stdin);
		go(24,50);choice=getchar();
		switch(choice){
			case 'A': case 'a':
				screen2_2_1_1();system("pause");screen2_2_1();
				break;
			case 'B': case 'b':
			    screen2_2_1_2();system("pause");screen2_2_1();
				break;
			case 'C': case 'c':
				screen2_2_1_3();system("pause");screen2_2_1();
				break;
			case 'D': case 'd':
				screen2_2_1_4();system("pause");screen2_2_1();
				break;
			case 'E': case 'e':
			    screen2_2_1_5();system("pause");screen2_2_1();
				break;
			case 'F': case 'f':
			     screen2_2_1_6();system("pause");screen2_2_1();
				break;
			case 'G': case 'g':
				screen2();break;
			default:
			    go(24,55);printf("invalid input");
                sleep(2);go(24,55);clreol(15);go(24,50);clreol(5);
	}
}
}

void screen2_2_2(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>> MEDICAL COURSES<<<<<<");
		go(7,22);printf("*Select Courses*");
		go(10,20);printf("1.MBBS");
		go(12,20);printf("2.BDS");
		go(14,20);printf("3.PHARMA");
		go(16,20);printf("4.BAMS ");
		go(18,20);printf("Return to Main Menu");
		go(22,20);printf("Enter Choice:1/2/3/4/ R or r to return main menu:");
		for(;;){
         fflush(stdin);
		go(22,70);choice=getchar();
		switch(choice){
			case '1': 
				screen2_2_2_1();system("pause");screen2_2_2();
				break;
			case '2':
				screen2_2_2_2();system("pause");screen2_2_2();
				break;
				case '3':
				screen2_2_2_3();system("pause");screen2_2_2();
				break;
				case '4': 
				screen2_2_2_4();system("pause");screen2_2_2();
				break;
			case 'r': case 'R':
				screen2();break;
			default:
			    go(24,22);printf("invalid input");sleep(2);go(24,22);clreol(15);go(22,70);clreol(5);
		}
	}
}

void screen2_2_3(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>>COMMERCE COURSES<<<<<<");
		go(7,22);printf("*Select Courses*");
		go(10,20);printf("1.Bcom");
		go(12,20);printf("2.CMA");
		go(14,20);printf("3.BBA");
		go(16,20);printf("4.CA ");
		go(18,20);printf("Return to Main Menu");
		go(22,20);printf("Enter Choice:1/2/3/4/ R or r to return main menu:");
		for(;;){
         fflush(stdin);
		go(22,72);choice=getchar();
		switch(choice){
			case '1': 
				screen2_2_3_1();system("pause");screen2_2_3();
				break;
			case '2':
				screen2_2_3_2();system("pause");screen2_2_3();
				break;
				case '3': 
				screen2_2_3_3();system("pause");screen2_2_3();
				break;
				case '4':
				screen2_2_3_4();system("pause");screen2_2_3();
				break;
			case 'r': case 'R':
				screen2();break;
			default:
			   go(24,22); printf("invalid input");
               sleep(2);go(24,22);clreol(15);go(22,72);clreol(5);
		}
	}
}
void screen2_2_4(){
	char  choice;
	
		clrscr();
		go(5,22);screen_border(">>>>>ARTS & HUMANITIES COURSES<<<<<<");
		go(7,22);printf("*Select Courses*");
		go(10,20);printf("1.BA in Humanities and social science");
		go(12,20);printf("2.Ba in arts");
		go(14,20);printf("3.BFA");
		go(16,20);printf("4.BDes ");
		go(18,20);printf("Return to Main Menu");
		go(22,20);printf("Enter Choice:1/2/3/4/ R or r to return main menu:");
		for(;;){
         fflush(stdin);
		go(22,70);choice=getchar();
		switch(choice){
			case '1':
				screen2_2_4_1();system("pause");screen2_2_4();
				break;
			case '2': 
				screen2_2_4_2();system("pause");screen2_2_4();
				break;
				case '3': 
				screen2_2_4_3();system("pause");screen2_2_4();
				break;
				case '4':
				screen2_2_4_4();system("pause");screen2_2_4();
				break;
			case 'r': case 'R':
				screen2();break;
			default:
			    go(24,22);printf("invalid input");
                sleep(2);go(24,22);clreol(16);go(22,70);clreol(5);
		}
	}
}
void output1(){
	
	clrscr();fflush(stdin);
	outline();
	system("color 71");
	go(4,18);screen_border(">>Hey! we tried to conclude that according to your inputs<< ");
	sleep(2);
	go(8,15);printf("%s",p.pcmgrade);sleep(2);
	go(10,15);printf("%s",p.apt);sleep(2);
	go(12,15);printf("%s",p.com);sleep(2);
	go(14,15);printf("%s",p.civil);sleep(2);
	go(16,15);printf("%s",p.en);sleep(2);
	go(18,15);printf("%s",p.ec);sleep(2);
	go(20,15);printf("%s",p.che);sleep(2);
	for(;;){
	fflush(stdin);
	go(22,13);printf("for more information about courses in engineering press [1] or");
	go(24,13);printf("press [2] for exams or r to return to main menu:");

	go(24,65);clreol(8);
	char ch=getchar();
	switch (ch)
	{
		case '1':
		screen2_2_1();system("pause");screen2_2_1();
		break;
		case '2':
		screen2_3_1();system("pause");screen2_3();break;
		case 'r': case 'R':
		   screen2();break;
		default:
		go(27,22);printf("enter right input");sleep(2);go(27,22);clreol(20);
	}
	}
	
}
void output2(){
	
	clrscr();fflush(stdin);
	outline();
	system("color 71");
	go(4,18);screen_border(">>Hey! we tried to conclude that according to your inputs<< ");
	sleep(2);
	go(8,15);printf("%s",p.pcbgrade);sleep(2);
	go(10,15);printf("%s",p.apt);sleep(2);
	go(12,15);printf("%s",p.com);sleep(2);
	go(14,15);printf("%s",p.civil);sleep(2);
	go(16,15);printf("%s",p.en);sleep(2);
	go(18,15);printf("%s",p.ec);sleep(2);
	go(20,15);printf("%s",p.che);sleep(2);
	
	for(;;){
	fflush(stdin);
	go(22,13);printf("for more information about courses in medical press [1] or");
	go(24,13);printf("press [2] for exams or r to return to main menu:");

	go(24,65);clreol(8);
	char ch=getchar();
	switch (ch)
	{
		case '1':
		screen2_2_2();system("pause");screen2_2();	break;
		case '2':
		screen2_3_2();system("pause");screen2_3();break;
		break;
		case 'r': case 'R':
		   screen2();break;
		default:
		go(27,22);printf("enter right input");
		sleep(2);go(27,22);clreol(20);
	}
}
}
void output3(){

	clrscr();fflush(stdin);
	outline();
	system("color 71");
	go(4,18);screen_border(">>Hey! we tried to conclude that according to your inputs<< ");
	sleep(2);
	go(8,15);printf("%s",p.cmgrade);sleep(2);
	go(10,15);printf("%s",p.apt);sleep(2);
	go(12,15);printf("%s",p.com);sleep(2);
	go(14,15);printf("%s",p.civil);sleep(2);
	go(16,15);printf("%s",p.en);sleep(2);
	go(18,15);printf("%s",p.ec);sleep(2);
	go(20,15);printf("%s",p.che);sleep(2);

for(;;){
	fflush(stdin);
	go(22,13);printf("for more information about courses in commerce press [1] or");
	go(24,13);printf("press [2] for exams or r to return to main menu:");

	go(24,65);clreol(8);
	char ch=getchar();
	switch (ch)
	{
		case '1':
		screen2_2_3();system("pause");screen2_2();
		break;
		case '2':
		screen2_3_3();system("pause");screen2_3();break;
		break;
		case 'r': case 'R':
		   screen2();break;
		default:
		go(27,22);printf("enter right input");
		sleep(2);go(27,22);clreol(20);
	}
}
}
void output4(){
	
	clrscr();fflush(stdin);
	outline();
	system("color 71");
	go(4,18);screen_border(">>Hey! we tried to conclude that according to your inputs<< ");
	sleep(2);
	go(8,15);printf("%s",p.ahgrade);sleep(2);
	go(10,15);printf("%s",p.apt);sleep(2);
	go(12,15);printf("%s",p.com);sleep(2);
	go(14,15);printf("%s",p.civil);sleep(2);
	go(16,15);printf("%s",p.en);sleep(2);
	go(18,15);printf("%s",p.ec);sleep(2);
	go(20,15);printf("%s",p.che);sleep(2);
for(;;){
	fflush(stdin);
	go(22,13);printf("for more information about courses in humanities press [1] or");
	go(24,13);printf("press [2] for exams or r to return to main menu:");

	go(24,65);clreol(8);
	char ch=getchar();
	switch (ch)
	{
		case '1':
		screen2_2_4();system("pause");screen2_2();
		break;
		case '2':
		screen2_3_4();system("pause");screen2_3();break;
		break;
		case 'r': case 'R':
		   screen2();break;
		default:
		go(27,22);printf("enter right input");sleep(2);go(27,22);clreol(20);
		
	}
	}
}

void changepassword(){
    char un[51],ch;
	int found=0,i=0;
	system("cls");go(8,20);screen_border("Change password");
	fp=fopen("newuser.dat","rb+");
	if(fp==NULL)fp=fopen("newuser.dat","wb+");
	go(10,15);printf("Enter username : "); fflush(stdin);go(10,35);gets(un);
	rewind(fp); // send the file pointer to top of the file
	while(fread(&u,sizeof(u),1,fp)){
			if(strcmp(un,u.username)==0){
			found=1;
			break;
		}
	}
	switch(found){
		case 1: 
		go(12,15);printf("new password : "); fflush(stdin);go(12,35);
		while(i<50){
		ch=getch();
		if(ch==13) break;
		else if(ch==8){
			if(i>0){
				int n;
				i--;
				go(12,35);clreol(50);
				go(12,35);
				for(n=0;n<i;n++) putchar('*');
			}
		}
		else{
			u.password[i]=ch;
			putchar('*');
			i++;
		}
	}
    	u.password[i]='\0';
		fseek(fp,-sizeof(u),SEEK_CUR); //Move file pointer to start of searached record
		fwrite(&u,sizeof(u),1,fp); //update the record
		go(20,15);printf("Password updated...\n");system("pause");screen2();
	    case 0:	
		go(20,15);printf("User not found\n");system("pause");screen2();
	}
}






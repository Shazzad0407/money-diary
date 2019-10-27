#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
typedef struct
{
	int d,m,y;
}Date;
typedef struct 
{
	char name[30],uname[15],pass[20];
}profile;
struct Data
{
	char type[7],scource[100];
	Date date;
	int amount;
};
typedef struct Data info;
struct node
{
	info data;
	struct node *next;
};
typedef struct node node;
node *start1=NULL;
node *start2=NULL;
node* sortByDate(node *pa, char a); //merge algorithm have used
node* sortByAmount(node *pa, char a);  //merge algorithm have used
void printSortData(node *income,node *cost,char uName[],char heading[]);
void printSpecificSortData(node *income,char uName[],char heading[]);
void deleteFromMemory(node *list);
int top=-1, stack[15]; //global variable for stack
void push (int x);
int pop();
//void getCursorXY(int &x, int &y);
void showAll(char fName[],char uName[]);
void incomeOfSpecificScource(char fName[],char uName[]);
void costOfSpecificScource(char fName[],char uName[]);
void monthlyStatement(char fName[],char uName[]);
void yearlyStatement(char fName[],char uName[]);
void dailyStatement(char fName[],char uName[]);
void details(char fName[],char uName[]);
int whichMonth(char str[]);
int whichYear(char str[]);
void intToChar(int x,char a[]);
void charToIntDate(char str[],int d[]);
void intToCharDate(int d[],char date[]);
void makeDate(char date[]);
void statistic(profile *userInfo);
void modify(profile *userInfo);
void Delete(profile *userInfo);
void updateCost(profile *userInfo);
void updateIncome(profile *userInfo);
int spaceCheacker(char str[]);
void gotoXY(int x, int y);
void makeBox(int x,int y, int a, int b,int col, char shape);
void color(int c);
void newProfile();
void logIn();
//for passwords...
bool keyHit(void);
bool getChar(TCHAR &ch);
TCHAR getChar(void);
void password(char pass[]);
void main()
{
	int choice;
	while(1)
	{  
		
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
		makeBox(9, 2, 62,22,2,'x');  //create a box 
		makeBox(10, 3, 60,20,2,'x'); // create a box 
		//giving a heading into box
			gotoXY(35,5);
			color(63);
			printf("MONEY DAIRY\n");
		//available option showing into box
			gotoXY(25,10);
			color(63); printf("press <1> ");
			color(52); printf("for NEW PROFILE\n\n");
			gotoXY(25,13);
			color(63); printf("press <2> ");
			color(52); printf("for LOG IN\n\n");
			gotoXY(25,16); 
			color(63); printf("press <3> ");
			color(52); printf("for EXIT\n\n");
		//select user choice
			gotoXY(25,20);
			color(49);
			printf("Enter Your Choice: ");
			scanf("%d",&choice);
			gotoXY(25,22);
		switch(choice)
		{
		case 1:
			newProfile();
			break;
		case 2: 
			logIn();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Wrong Input\n");
		}
	}
}

void newProfile()
{
	system("cls");   //clear screen
	char rePass[20],choice;
	profile info;
	int flag=-1,passCheck;
	FILE *fp;
	while(1)
	{
		system("COLOR 3C");  // default consol background & text color
		makeBox(9, 2, 62,22,2,'x');  //create a box 
		makeBox(10, 3, 60,20,2,'x'); // create a box 
		//giving a heading into box
			gotoXY(35,5);
			color(63);
			printf("NEW PROFILE\n");
		//Sign up form
			gotoXY(25,9); color(63); printf("NAME: ");
			color(52); fflush(stdin); gets(info.name);
			gotoXY(25,11); color(63); printf("USER NAME: ");
			color(52); gets(info.uname);
			gotoXY(25,13); color(63); printf("PASSWARD: ");
			color(52);password(info.pass);
			gotoXY(25,15); color(63); printf("RE-Enter PASSWARD: ");
			color(52); password(rePass);
		//checking validation of user name
			// check is there any space in uname
			int space;
			space=spaceCheacker(info.uname);
			if(space==1)
			{
				system("cls");
				gotoXY(20,20);
				printf("please do not use any space in user name\n");
			}
			else
			{
				profile checkUname;
				fp=fopen("userName.txt","rb");
				while( fread(&checkUname,sizeof(checkUname),1,fp) >0 )
				{
					flag=strcmp(checkUname.uname,info.uname);
					if(flag==0)
					{
						system("cls");
						gotoXY(30,20);
						printf("User name already used\n");
						break;
					}

				}
				fclose(fp);
			
			//checking validation of passward
				if(flag!=0)
				{
					passCheck=strcmp(info.pass,rePass);
					if(passCheck!=0)
					{
						system("cls");
						gotoXY(32,20);
						printf("Passward don't match\n");
					}
				}
			}
		// if passward & username both are okay
			if(passCheck==0 && flag!=0)
			{
				//input the user name & other info into userName.txt file
					fp=fopen("userName.txt","ab");
					fwrite(&info,sizeof(info),1,fp);
					fclose(fp);
				//create a file as name as user name and input pass here
					strcat(info.uname,".txt");
					fp=fopen(info.uname,"a");
					fclose(fp);

				//successfully profile created messege
					system("cls");
					makeBox(9, 2, 62,22,2,'x');  //create a box 
					makeBox(10, 3, 60,20,2,'x'); // create a box 
					gotoXY(20,15);
					color(52); printf("Congratulation %s.",info.name);
					gotoXY(20,17);
					printf("Your Profile has been created sucessfully\n");
				// get out from new profile page
					gotoXY(20,20);
					color(63); printf("press enter to continue... ");
					choice=getchar();
					if(choice=='\n')
						break;
					else 
						break;
					
			}
	}
		

}

void logIn()
{
	system("cls");   //clear screen
	char uname[20],pass[25],name[30];
	int flag=0,choice;
	profile check;
	
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY(36,5);
		color(63);
		printf("LOG IN\n");
	//Sign up form
		gotoXY(25,9); color(63); printf("USER NAME: ");
		color(52); fflush(stdin); gets(uname);
		gotoXY(25,11); color(63); printf("PASSWARD: ");
		color(52); password(pass);
		
		

	//checking user name & passward
		FILE *fp;
		fp=fopen("userName.txt","rb");
		while( fread(&check,sizeof(check),1,fp) > 0 )
		{
			int a,b;
			a=strcmp(check.uname,uname);
			b=strcmp(check.pass,pass);
			if(a==0 && b==0)
			{
				flag=1;
				break;
			}
		}
	//if wrong username or invalid pass
		if(flag==0)
		{
			system("cls");
			makeBox(9, 2, 62,22,2,'x');  //create a box 
			makeBox(10, 3, 60,20,2,'x'); // create a box 
			gotoXY(25,10); color(52); printf("Invalid User Name or Invalid Passward\n");
		//available option for user after an unsuccesfull login attempt
			gotoXY(25,15);
			color(63); printf("press <1> ");
			color(52); printf("for TRY AGAIN\n\n");
			gotoXY(25,17);
			color(63); printf("press <2> ");
			color(52); printf("EXIT\n\n");
		//select user choice
			gotoXY(25,19);
			color(49);
			printf("Enter Your Choice: ");
			scanf("%d",&choice);
			//gotoXY(25,22);
			switch(choice)
			{
			case 1:
				logIn();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Wrong Input\n");
				exit(0);
			}
		}
		//if user name & passward is valid
		else if(flag==1)
		{
			while(1)
			{
				choice='\0';
				system("cls");   //clear screen
				system("COLOR 3C");  // default consol background & text color
				makeBox(9, 2, 62,26,2,'x');  // create a box 
				makeBox(10, 3, 60,24,2,'x'); // create a box 
				//Show the name of the User

					gotoXY((60-strlen(check.name))/2+10,5);
					color(63);
					printf("%s",check.name);
				//available option for user showing into box
					gotoXY(25,8); color(63); printf("press <1> for ");
					color(52); printf("UPDATE INCOME\n");
					gotoXY(25,10); color(63); printf("press <2> for ");
					color(52); printf("UPDATE COST\n");
					gotoXY(25,12); color(63); printf("press <3> for ");
					color(52); printf("VIEW STATISTIC\n");
					gotoXY(25,14); color(63); printf("press <4> for ");
					color(52); printf("Modify\n\n");
					gotoXY(25,16); color(63); printf("press <5> for ");
					color(52); printf("DELETE\n\n");
					gotoXY(25,18); color(63); printf("press <6> for ");
					color(52); printf("SIGN OUT\n\n");
					gotoXY(25,20); color(63); printf("press <0> for ");
					color(52); printf("EXIT\n");
				//select user choice
					gotoXY(25,23);
					color(49);
					printf("Enter Your Choice: ");
					scanf("%d",&choice);
					int p=0;
				switch(choice)
				{
				case 1:
					updateIncome(&check);
					break;
				case 2: 
					updateCost(&check);
					break;
				case 3:
					statistic(&check);
					break;
				case 4:
					modify(&check);
					break;
				case 5:
					Delete(&check);
					break;
				case 6:
					p=1;
					break;
				case 0:
					exit(0);
					break;
				default:
					printf("Wrong Input\n");
				}
				if(p==1)
					break;
			}
	}
}

void updateIncome(profile *userInfo)
{
	char fName[15],dateByUser[12];
	int d[3];
	info in;
	strcpy(fName,userInfo->uname);  //copy the user name for making file name
	strcat(fName,".txt"); 
	
	FILE *fp;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((60-strlen(userInfo->name))/2+10,5); color(63); printf("%s",userInfo->name);
		gotoXY((60-13)/2+10,7);printf("UPDATE INCOME");
		makeBox((60-13)/2+8, 8,16,1,63,'='); // create a box 

	//Sign up form
		strcpy(in.type,"income");
		gotoXY(25,11); color(63); printf("DATE");
		gotoXY(30,11); color(61); printf("(dd/mm/yy): ");
		color(52); fflush(stdin); gets(dateByUser);
		gotoXY(25,13); color(63); printf("Scource: ");
		gotoXY(25,18); color(62); printf("note* in scource use max 15 charecter");
		gotoXY(34,13); color(52); gets(in.scource);
		gotoXY(25,15); color(63); printf("Amount: ");
		color(52); scanf("%d",&in.amount);
	//make date in my way
		makeDate(dateByUser);
	//make date character to intiger
		charToIntDate(dateByUser,d);
	//assign date into in variable
		in.date.d=d[0];
		in.date.m=d[1];
		in.date.y=d[2];
	// collect the information into File
		fp=fopen(fName,"ab");
		fwrite(&in,sizeof(in),1,fp);
		fclose(fp);
	//successfully information update Messege
		system("cls");
		makeBox(9, 2, 62,22,2,'x');  //create a box 
		makeBox(10, 3, 60,20,2,'x'); // create a box 
		gotoXY(20,15);
		color(52); printf("Your income list has been updated succesfully\n");
	// get out from update income page
		int choice;
		gotoXY(20,17);
		color(63); printf("press enter to continue... ");
		fflush(stdin);
		choice=getchar();
}

void updateCost(profile *userInfo)
{
	char fName[15],dateByUser[12];
	int d[3];
	info in;
	strcpy(fName,userInfo->uname);  //copy the user name for making file name
	strcat(fName,".txt"); 
	
	FILE *fp;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((60-strlen(userInfo->name))/2+10,5); color(63); printf("%s",userInfo->name);
		gotoXY((60-11)/2+10,7);printf("UPDATE COST");
		makeBox((60-11)/2+8,8,14,1,63,'='); // create a box 

	//Sign up form
		strcpy(in.type,"cost");
		gotoXY(25,11); color(63); printf("DATE");
		gotoXY(30,11); color(61); printf("(dd/mm/yy): ");
		color(52); fflush(stdin); gets(dateByUser);
		gotoXY(25,13); color(63); printf("Scource: ");
		gotoXY(25,18); color(62); printf("note* in scource use max 15 charecter");
		gotoXY(34,13); color(52); gets(in.scource);
		gotoXY(25,15); color(63); printf("Amount: ");
		color(52); scanf("%d",&in.amount);
	//make date in my way
		makeDate(dateByUser);
	//make date character to intiger
		charToIntDate(dateByUser,d);
	//assign date into in variable
		in.date.d=d[0];
		in.date.m=d[1];
		in.date.y=d[2];
	// collect the information into File
		fp=fopen(fName,"ab");
		fwrite(&in,sizeof(in),1,fp);
		fclose(fp);
	//successfully information update Messege
		system("cls");
		makeBox(9, 2, 62,22,2,'x');  //create a box 
		makeBox(10, 3, 60,20,2,'x'); // create a box 
		gotoXY(20,15);
		color(52); printf("Your COST list has been updated succesfully\n");
	// get out from update income page
		int choice;
		gotoXY(20,17);
		color(63); printf("press enter to continue... ");
		fflush(stdin);
		choice=getchar();
}

void statistic(profile *userInfo)
{
	char fName[15];
	info in;
	int p=0;
	strcpy(fName,userInfo->uname);  //copy the user name for making file name
	strcat(fName,".txt"); 
	FILE *fp;
	while(1)
	{
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
		makeBox(9,2,62,40,2,'x');  //create a box 
		makeBox(10,3,60,38,2,'x'); // create a box 
		//giving a heading into box
			gotoXY((60-strlen(userInfo->name))/2+10,5); color(63); printf("%s",userInfo->name);
			gotoXY((60-14)/2+10,7);printf("VIEW STATISTIC");
			makeBox((60-14)/2+8,8,17,1,63,'='); // create an underline
		//current Month balance heading
			gotoXY((60-21)/2+10,11); color(53); printf("Current Month Records\n");
			makeBox((60-21)/2+8,12,24,1,53,'_');
		//find out current time
			struct tm *myTime;
			time_t currentTime;
			currentTime=time(NULL);
			myTime=localtime(&currentTime);
		//compare current month with file data.
			fp=fopen(fName,"rb");
			int totalCost=0,totalIncome=0;
			while( fread(&in,sizeof(in),1,fp) > 0 )
			{
				int cmp1,cmp2;
				cmp1=strcmp(in.type,"cost");
				cmp2=strcmp(in.type,"income");
				if(cmp1==0 && in.date.m==myTime->tm_mon+1 && in.date.y==myTime->tm_year+1900)
				{
					totalCost+=in.amount;
				}
				else if(cmp2==0 && in.date.m==myTime->tm_mon+1 && in.date.y==myTime->tm_year+1900)
				{
					totalIncome+=in.amount;
				}
			}
			fclose(fp);
		// print current month Record;
			gotoXY(29,14); color(53); printf("total income: %d taka",totalIncome);
			gotoXY(29,15); printf("total cost  : %d taka",totalCost);
			gotoXY(29,16); printf("Balance     : %d taka",totalIncome-totalCost);
		//available option showing into box
				gotoXY(25,19);
				color(63); printf("press <1> for ");
				color(52); printf("DETAILS\n");
				gotoXY(25,21);
				color(63); printf("press <2> for ");
				color(52); printf("DAILY STATEMENT\n");
				gotoXY(25,23); 
				color(63); printf("press <3> for ");
				color(52); printf("MONTHLY STATEMENT\n");
				gotoXY(25,25);
				color(63); printf("press <4> for ");
				color(52); printf("YEARLY STATEMENT\n");
				gotoXY(25,27);
				color(63); printf("press <5> for ");
				color(52); printf("COST OF SPECIFIC SCOURCE\n");
				gotoXY(25,29); 
				color(63); printf("press <6> for ");
				color(52); printf("INCOME OF SPECIFIC SCOURCE\n");
				gotoXY(25,31); 
				color(63); printf("press <7> for ");
				color(52); printf("SHOW ALL\n");
				gotoXY(25,33); 
				color(63); printf("press <8> for ");
				color(52); printf("BACK\n");
			//select user choice
				int choice;
				gotoXY(25,36);
				color(49);
				printf("Enter Your Choice: ");
				scanf("%d",&choice);
				gotoXY(25,22);
			switch(choice)
			{
			case 1:
				details(fName,userInfo->name);
				break;
			case 2:
				dailyStatement(fName,userInfo->name);
				break;
			case 3:
			    monthlyStatement(fName,userInfo->name);
				break;
			case 4:
				yearlyStatement(fName,userInfo->name);
				break;
			case 5:
				costOfSpecificScource(fName,userInfo->name);
				break;
			case 6:
				incomeOfSpecificScource(fName,userInfo->name);
				break;
			case 7:
			    showAll(fName,userInfo->name);
				break;
			case 8:
			    p=1;
				break;
			default:
				printf("Wrong Input\n");
			}
			if(p==1)break;
	}	
}

void modify(profile *userInfo)
{
	char fName[15],dateByUser[12];
	int d[3],found=0;
	info in,out;
	strcpy(fName,userInfo->uname);  //copy the user name for making file name
	strcat(fName,".txt"); 
	
	FILE *fp,*fpTemp;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,34,2,'x');  //create a box 
	makeBox(10, 3, 60,32,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((60-strlen(userInfo->name))/2+10,5); color(63); printf("%s",userInfo->name);
		gotoXY((60-11)/2+10,7);printf("Modify Data");
		makeBox((60-11)/2+8, 8,14,1,63,'='); // create a box 

	//searching data form
		gotoXY(25,10); printf("Enter the below information to search");
		gotoXY(25,11); printf("the data which you want to modify");
		gotoXY(25,13); color(63); printf("Data Type ");
		color(61); printf("(income/cost): ");
		color(52);fflush(stdin); gets(in.type);
		gotoXY(25,15); color(63); printf("DATE");
		gotoXY(30,15); color(61); printf("(dd/mm/yy): ");
		color(52); fflush(stdin); gets(dateByUser);
		gotoXY(25,17); color(63); printf("Scource: ");
		color(52); gets(in.scource);
		gotoXY(25,19); color(63); printf("Amount: ");
		color(52); scanf("%d",&in.amount);
	//make date in my way
		makeDate(dateByUser);
	//make date character to intiger
		charToIntDate(dateByUser,d);
	//assign date into in variable
		in.date.d=d[0];
		in.date.m=d[1];
		in.date.y=d[2];
	// open the both user file & temprary file and input all the data in temporary file with modify data
		fp=fopen(fName,"rb");
		fpTemp=fopen("temp.txt","wb");
		while( fread(&out,sizeof(out),1,fp) >0 )
		{
			
			if(found==0 && strcmp(out.type,in.type)==0 && strcmp(out.scource,in.scource)==0 && out.amount==in.amount && out.date.d==in.date.d && out.date.m==in.date.m && out.date.y==in.date.y)  
			{
				// asking for new modified data
				gotoXY(25,22);
				printf("Enter the modify Information\n");
				gotoXY(25,24); color(63); printf("Data Type ");
				color(61); printf("(income/cost): ");
				color(52);fflush(stdin); gets(in.type);
				gotoXY(25,26); color(63); printf("DATE");
				gotoXY(30,26); color(61); printf("(dd/mm/yy): ");
				color(52); fflush(stdin); gets(dateByUser);
				gotoXY(25,28); color(63); printf("Scource: ");
				color(52); gets(in.scource);
				gotoXY(25,30); color(63); printf("Amount: ");
				color(52); scanf("%d",&in.amount);
			//make date in my way
				makeDate(dateByUser);
			//make date character to intiger
				charToIntDate(dateByUser,d);
			//assign date into in variable
				in.date.d=d[0];
				in.date.m=d[1];
				in.date.y=d[2];
				fwrite(&in,sizeof(in),1,fpTemp);
				found=1;
			}
			else
			{
				fwrite(&out,sizeof(out),1,fpTemp);
			}
		}
		fclose(fp);
		fclose(fpTemp);
		if(found==0)
		{
			system("cls");
			makeBox(9, 2, 62,34,2,'x');  //create a box 
			makeBox(10, 3, 60,32,2,'x'); // create a box 
			gotoXY(25,16);
			color(52); printf("Searching data Not Found\n");
		}
		else
		{
		//copy all the modify data in user file
			fpTemp=fopen("temp.txt","rb");
			fp=fopen(fName,"wb");
			while( fread(&out,sizeof(out),1,fpTemp) >0 )
			{
				fwrite(&out,sizeof(out),1,fp);
			}
			fclose(fp);
			fclose(fpTemp);
		//successfully information update Messege
			system("cls");
			makeBox(9, 2, 62,34,2,'x');  //create a box 
			makeBox(10, 3, 60,32,2,'x'); // create a box 
			gotoXY(25,16);
			color(52); printf("The data has been modified succesfully\n");
		}
		
	// get out from update income page
		int choice;
		gotoXY(25,18);
		color(63); printf("press enter to continue... ");
		fflush(stdin);
		choice=getchar();
}

void Delete(profile *userInfo)
{
	char fName[15],dateByUser[12];
	int d[3],found=0;
	info in,out;
	strcpy(fName,userInfo->uname);  //copy the user name for making file name
	strcat(fName,".txt"); 
	
	FILE *fp,*fpTemp;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,34,2,'x');  //create a box 
	makeBox(10, 3, 60,32,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((60-strlen(userInfo->name))/2+10,5); color(63); printf("%s",userInfo->name);
		gotoXY((60-11)/2+10,7);printf("Delete Data");
		makeBox((60-11)/2+8,8,14,1,63,'='); // create a box 

	//searching data form
		gotoXY(25,10); printf("Enter the below information to search");
		gotoXY(25,11); printf("the data which you want to delete");
		gotoXY(25,13); color(63); printf("Data Type ");
		color(61); printf("(income/cost): ");
		color(52);fflush(stdin); gets(in.type);
		gotoXY(25,15); color(63); printf("DATE");
		gotoXY(30,15); color(61); printf("(dd/mm/yy): ");
		color(52); fflush(stdin); gets(dateByUser);
		gotoXY(25,17); color(63); printf("Scource: ");
		color(52); gets(in.scource);
		gotoXY(25,19); color(63); printf("Amount: ");
		color(52); scanf("%d",&in.amount);
	//make date in my way
		makeDate(dateByUser);
	//make date character to intiger
		charToIntDate(dateByUser,d);
	//assign date into in variable
		in.date.d=d[0];
		in.date.m=d[1];
		in.date.y=d[2];
	// open the both user file & temprary file and input all the data in temporary file without searching data
		fp=fopen(fName,"rb");
		fpTemp=fopen("temp.txt","wb");
		while( fread(&out,sizeof(out),1,fp) >0 )
		{
			
			if(found==0 && strcmp(out.type,in.type)==0 && strcmp(out.scource,in.scource)==0 && out.amount==in.amount && out.date.d==in.date.d && out.date.m==in.date.m && out.date.y==in.date.y)  
			{
				found=1;
			}
			else
			{
				fwrite(&out,sizeof(out),1,fpTemp);
			}
		}
		fclose(fp);
		fclose(fpTemp);
		if(found==0)
		{
			system("cls");
			makeBox(9, 2, 62,34,2,'x');  //create a box 
			makeBox(10, 3, 60,32,2,'x'); // create a box 
			gotoXY(25,16);
			color(52); printf("Searching data Not Found\n");
		}
		else
		{
		//copy all the modify data in user file
			fpTemp=fopen("temp.txt","rb");
			fp=fopen(fName,"wb");
			while( fread(&out,sizeof(out),1,fpTemp) >0 )
			{
				fwrite(&out,sizeof(out),1,fp);
			}
			fclose(fp);
			fclose(fpTemp);
		//successfully information update Messege
			system("cls");
			makeBox(9, 2, 62,34,2,'x');  //create a box 
			makeBox(10, 3, 60,32,2,'x'); // create a box 
			gotoXY(25,16);
			color(52); printf("The data has been deleted succesfully\n");
		}
		
	// get out from update income page
		int choice;
		gotoXY(25,18);
		color(63); printf("press enter to continue... ");
		fflush(stdin);
		choice=getchar();
}

void details(char fName[],char uName[])
{
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color

	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//current Month balance heading
		gotoXY((79-24)/2,10); color(49); printf("Records of Current Month\n");
		makeBox((79-24)/2-2,11,27,1,49,'_');
	//find out current time
		struct tm *myTime;
		time_t currentTime;
		currentTime=time(NULL);
		myTime=localtime(&currentTime);
	//compare current month with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			inpoX=8;
			copoX=42;
			int cmp1,cmp2;
			cmp1=strcmp(in.type,"income");
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 && in.date.m==myTime->tm_mon+1 && in.date.y==myTime->tm_year+1900)
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total income of current month
				totalIncome+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				inpoY+=2;

			}
			else if(cmp2==0 && in.date.m==myTime->tm_mon+1 && in.date.y==myTime->tm_year+1900)
			{
				//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total cost of searching Date
				totalCost+=in.amount; 
				//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
				//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				copoY+=2;
			}
		}
		fclose(fp);
	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print current month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3
		
	//available Sorting option
	node *sort1=NULL, *sort2=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		char heading[]="Records of Current Month";
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			sort2=sortByDate(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			sort2=sortByDate(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			sort2=sortByAmount(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			sort2=sortByAmount(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		deleteFromMemory(sort2);
		start1=start2=NULL;
}

void dailyStatement(char fName[],char uName[])
{
	info in;
	int d[3];
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,5); color(63); printf("%s",uName);
		gotoXY((79-14)/2,7);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,8,17,1,63,'='); // create an underline
	//Asking user for A DATE
		char searchDate[14];
		gotoXY(20,13); color(63); printf("Searching Date ");
		color(61); printf("(dd/mm/yy): ");
		color(52);
		fflush(stdin);
		gets(searchDate);
		makeDate(searchDate); //make date in my way
	//again clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//make the date char too int
		charToIntDate(searchDate,d);
	//Searching date balance heading
		char heading[30]="Records of ";
		strcat(heading,searchDate);
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			inpoX=8;
			copoX=42;
			int cmp1,cmp2;
			cmp1=strcmp(in.type,"income");
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 && in.date.d==d[0] && in.date.m==d[1] && in.date.y==d[2] )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total cost of searching Date
				totalIncome+=in.amount; 
			//printing details into the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",searchDate);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				inpoY+=2;

			}
			else if( cmp2==0 && in.date.d==d[0] && in.date.m==d[1] && in.date.y==d[2] )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total cost of searching Date
				totalCost+=in.amount; 
			//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",searchDate);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				copoY+=2;
			}
		}
		fclose(fp);
	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print current month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3
		
	//available Sorting option
	node *sort1=NULL, *sort2=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			sort2=sortByDate(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			sort2=sortByDate(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			sort2=sortByAmount(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			sort2=sortByAmount(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		deleteFromMemory(sort2);
		start1=start2=NULL;

}

void monthlyStatement(char fName[],char uName[])
{
	info in;
	int d[3];
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,5); color(63); printf("%s",uName);
		gotoXY((79-14)/2,7);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,8,17,1,63,'='); // create an underline
	//Asking user for A Month of an year
		char searchDate[20];
		gotoXY(20,15); color(62); printf("(*note:search like: january,2016)");
		gotoXY(20,13); color(63); printf("Searching Month: ");
		color(52);
		fflush(stdin);
		gets(searchDate);
	//make int month & intiger year
		int month,year;
		month=whichMonth(searchDate);
		year=whichYear(searchDate);
	//again clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//Searching month balance heading
		char heading[30]="Records of ";
		strcat(heading,searchDate);
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			inpoX=8;
			copoX=42;
			int cmp1,cmp2;
			cmp1=strcmp(in.type,"income");
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 && in.date.m==month && in.date.y==year )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total cost of searching Date
				totalIncome+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details into the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				inpoY+=2;

			}
			else if( cmp2==0 && in.date.m==month && in.date.y==year )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total cost of searching Date
				totalCost+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
				//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				copoY+=2;
			}
		}
		fclose(fp);
	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print searching month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3
	
	//available Sorting option
	node *sort1=NULL, *sort2=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			sort2=sortByDate(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			sort2=sortByDate(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			sort2=sortByAmount(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			sort2=sortByAmount(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		deleteFromMemory(sort2);
		start1=start2=NULL;

}

void yearlyStatement(char fName[],char uName[])
{
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,5); color(63); printf("%s",uName);
		gotoXY((79-14)/2,7);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,8,17,1,63,'='); // create an underline
	//Asking user for An year
		int searchYear;
		gotoXY(25,13);
		printf("Searching Year: ");
		color(52);
		fflush(stdin);
		scanf("%d",&searchYear);
	//again clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//Searching date balance heading
		char heading[30]="Records of ", a[5];
		intToChar(searchYear,a);
		strcat(heading,a);
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			inpoX=8;
			copoX=42;
			int cmp1,cmp2;
			cmp1=strcmp(in.type,"income");
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 && in.date.y==searchYear )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total income of current month
					totalIncome+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				inpoY+=2;

			}
			else if(cmp2==0 && in.date.y==searchYear)
			{
				//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total cost of current month
				totalCost+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
				//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				copoY+=2;
			}
		}
		fclose(fp);
	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print current month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3
		
	//available Sorting option
	node *sort1=NULL, *sort2=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			sort2=sortByDate(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			sort2=sortByDate(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			sort2=sortByAmount(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			sort2=sortByAmount(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		deleteFromMemory(sort2);
		start1=start2=NULL;
}

void costOfSpecificScource(char fName[],char uName[])
{
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,5); color(63); printf("%s",uName);
		gotoXY((79-14)/2,7);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,8,17,1,63,'='); // create an underline
	//Asking user for An specific scource of cost
		char costSubject[16];
		gotoXY(20,13);
		printf("Searching scource of cost: ");
		color(52);
		fflush(stdin);
		gets(costSubject);
	//again clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//Searching scource of cost balance heading
		char heading[40]="Cost Records of ";
		strcat(heading,costSubject);
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,slCost=1,cosX,cosY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			cosX=18;
			int cmp1,cmp2;
			cmp1=strcmp(in.scource,costSubject);
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 && cmp2==0)
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total income of current month
					totalCost+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(cosX,cosY);
				color(63); printf("%d.",slCost); slCost++;
				cosX+=3;
				gotoXY(cosX,cosY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				cosY+=2;

			}
		}
		fclose(fp);
	//find the current cursor position
		int z=cosY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print  Total cost;
		color(63);
		gotoXY(27,13); printf("total cost  : %d taka",totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(37,17); printf("COST");
	//making a table box....to display.
		makeBox(16,15,47,1,48,'.'); //row1
		makeBox(16,18,47,1,48,'.'); //row2
		makeBox(17,z,45,1,48,'.'); //row3	
		makeBox(16,16,0,z-15,48,'|'); //col1
		makeBox(63,16,0,z-15,48,'|'); //col3
	
		//available Sorting option
	node *sort1=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start2,'a');
			start2=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start2,'d');
			start2=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start2,'a');
			start2=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start2,'a');
			start2=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		start2=NULL;

}

void incomeOfSpecificScource(char fName[],char uName[])
{
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	makeBox(9, 2, 62,22,2,'x');  //create a box 
	makeBox(10, 3, 60,20,2,'x'); // create a box 
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,5); color(63); printf("%s",uName);
		gotoXY((79-14)/2,7);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,8,17,1,63,'='); // create an underline
	//Asking user for An specific scource of cost
		char costSubject[16];
		gotoXY(20,13);
		printf("Searching scource of income: ");
		color(52);
		fflush(stdin);
		gets(costSubject);
	//again clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//Searching scource of cost balance heading
		char heading[40]="Cost Records of ";
		strcat(heading,costSubject);
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,slCost=1,cosX,cosY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			cosX=18;
			int cmp1,cmp2;
			cmp1=strcmp(in.scource,costSubject);
			cmp2=strcmp(in.type,"income");
			if(cmp1==0 && cmp2==0)
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total income of current month
					totalCost+=in.amount;
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(cosX,cosY);
				color(63); printf("%d.",slCost); slCost++;
				cosX+=3;
				gotoXY(cosX,cosY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				cosY+=2;

			}
		}
		fclose(fp);
	//find the current cursor position
		int z=cosY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print  Total cost;
		color(63);
		gotoXY(27,13); printf("total income  : %d taka",totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(36,17); printf("INCOME");
	//making a table box....to display.
		makeBox(16,15,47,1,48,'.'); //row1
		makeBox(16,18,47,1,48,'.'); //row2
		makeBox(17,z,45,1,48,'.'); //row3	
		makeBox(16,16,0,z-15,48,'|'); //col1
		makeBox(63,16,0,z-15,48,'|'); //col3
	//available Sorting option
	node *sort1=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			start1=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			start1=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			start1=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			start1=sort1;
			printSpecificSortData(sort1,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		start1=NULL;

}

void showAll(char fName[],char uName[])
{
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	
	//Searching All records heading
		gotoXY(33,10); color(49); printf("All Records\n");
		makeBox(32,11,13,1,49,'_');
	//compare searching date with file data.
		FILE *fp;
		fp=fopen(fName,"rb");
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		while( fread(&in,sizeof(in),1,fp) > 0 )
		{
			inpoX=8;
			copoX=42;
			int cmp1,cmp2;
			cmp1=strcmp(in.type,"income");
			cmp2=strcmp(in.type,"cost");
			if(cmp1==0 )
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start1==NULL)  //for first node
				{
					start1= temp;
				}
				else
				{
					temp->next=start1;
					start1=temp;
				}
			//sum the total income of current month
				totalIncome+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				inpoY+=2;

			}
			else if(cmp2==0)
			{
			//make a link list....of getting data
				node *temp;
				temp=(node*)malloc(sizeof(node));
				temp->data.amount=in.amount;
				temp->data.date.d=in.date.d;
				temp->data.date.m=in.date.m;
				temp->data.date.y=in.date.y;
				strcpy(temp->data.scource,in.scource);
				temp->next=NULL;
				if(start2==NULL)  //for first node
				{
					start2= temp;
				}
				else
				{
					temp->next=start2;
					start2=temp;
				}
			//sum the total cost of current month
				totalCost+=in.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=in.date.d;
				d[1]=in.date.m;
				d[2]=in.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
				//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",in.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",in.amount);
				copoY+=2;
			}
		}
		fclose(fp);
	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print current month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3

	//available Sorting option
	node *sort1=NULL, *sort2=NULL;
	int f=0;
	while(1)
	{
		gotoXY(7,z+2);
		color(63); printf("press <1> for ");
		color(52); printf("SORT BY DATE(ASCENDING ORDER)\n");
		gotoXY(7,z+4);
		color(63); printf("press <2> for ");
		color(52); printf("SORT BY DATE(DECENDING ORDER)\n");
		gotoXY(7,z+6); 
		color(63); printf("press <3> for ");
		color(52); printf("SORT BY AMOUNT(ASCENDING ORDER)\n");
		gotoXY(7,z+8);
		color(63); printf("press <4> for ");
		color(52); printf("SORT BY AMOUNT(DECENDING ORDER)\n");
		gotoXY(7,z+10);
		color(63); printf("press <0> for ");
		color(52); printf("BACK\n");
	//select user choice
		int choice;
		char heading[]="All Records";
		gotoXY(7,z+12);
		color(49);
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			sort1=sortByDate(start1,'a');
			sort2=sortByDate(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 2:
			sort1=sortByDate(start1,'d');
			sort2=sortByDate(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 3:
			sort1=sortByAmount(start1,'a');
			sort2=sortByAmount(start2,'a');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 4:
			sort1=sortByAmount(start1,'d');
			sort2=sortByAmount(start2,'d');
			start1=sort1;
			start2=sort2;
			printSortData(sort1,sort2,uName,heading);
			break;
		case 0:
			f=1;
			break;
		default:
				printf("Wrong Input\n");
		}
		if(f==1)
			break;
	}
	
//	before out from these function delete all created node
		deleteFromMemory(sort1);
		deleteFromMemory(sort2);
		start1=start2=NULL;
}

node* sortByAmount(node *pa, char a)
{
	if(pa==NULL || pa->next==NULL)
		return pa;
	node *left=NULL;
	node *right=NULL;
	node *black, *white, *l,*r;
	white=pa;
	black=pa->next;
	while(black->next !=NULL)  //finding the middle node
	{
	    black=black->next;
	    if(black->next!=NULL)
	    {
			black=black->next;
			white=white->next;
	    }
	}
  //make the partition
	right=white->next;
	white->next=NULL;
	left= pa;
	l=sortByAmount(left,a);
	r=sortByAmount(right,a);
 //merge the unsorted node
	pa=NULL;
	node* temp=pa;
	while(l!=NULL && r!=NULL)
	{
		if(a=='a')
		{
			if(l->data.amount <= r->data.amount)
			{
				if(pa==NULL)
				{
					pa=l;
					temp=pa;
					l=l->next;
				}
				else
				{
					temp->next=l;
					temp=temp->next;
					l=l->next;
				}
			}
			else
			{
				if(pa==NULL)
				{
					pa=r;
					temp=pa;
					r=r->next;
				}
				else
				{
					temp->next=r;
					temp=temp->next;
					r=r->next;
				}
			}
		}
		else if(a=='d')
		{
			if(l->data.amount >= r->data.amount)
			{
				if(pa==NULL)
				{
					pa=l;
					temp=pa;
					l=l->next;
				}
				else
				{
					temp->next=l;
					temp=temp->next;
					l=l->next;
				}
			}
			else
			{
				if(pa==NULL)
				{
					pa=r;
					temp=pa;
					r=r->next;
				}
				else
				{
					temp->next=r;
					temp=temp->next;
					r=r->next;
				}
			}
		}
	}
	while(l!=NULL)
	{
		temp->next=l;
		temp=temp->next;
		l=l->next;
	}
	while(r!=NULL)
	{
		temp->next=r;
		temp=temp->next;
		r=r->next;
	}
	
	return pa;

}

node* sortByDate(node *pa, char a)
{
	if(pa==NULL || pa->next==NULL)
		return pa;
	node *left=NULL;
	node *right=NULL;
	node *black, *white, *l,*r;
	white=pa;
	black=pa->next;
	while(black->next !=NULL)  //finding the middle node
	{
	    black=black->next;
	    if(black->next!=NULL)
	    {
			black=black->next;
			white=white->next;
	    }
	}
  //make the partition
	right=white->next;
	white->next=NULL;
	left= pa;
	l=sortByDate(left,a);
	r=sortByDate(right,a);
 //merge the unsorted node
	pa=NULL;
	node* temp=pa;
	while(l!=NULL && r!=NULL)
	{
		if(a=='a')
		{
			if( (l->data.date.y < r->data.date.y) || (l->data.date.y == r->data.date.y && l->data.date.m < r->data.date.m ) ||  (l->data.date.y == r->data.date.y && l->data.date.m == r->data.date.m && l->data.date.d < r->data.date.d) )        
			{
				if(pa==NULL)
				{
					pa=l;
					temp=pa;
					l=l->next;
				}
				else
				{
					temp->next=l;
					temp=temp->next;
					l=l->next;
				}
			}
			else
			{
				if(pa==NULL)
				{
					pa=r;
					temp=pa;
					r=r->next;
				}
				else
				{
					temp->next=r;
					temp=temp->next;
					r=r->next;
				}
			}
		}
		else if(a=='d')
		{
			if( (l->data.date.y > r->data.date.y) || ((l->data.date.y == r->data.date.y)&&(l->data.date.m > r->data.date.m)) || ( (l->data.date.y == r->data.date.y)&&(l->data.date.m == r->data.date.m)&&(l->data.date.d > r->data.date.d)) )
			{
				if(pa==NULL)
				{
					pa=l;
					temp=pa;
					l=l->next;
				}
				else
				{
					temp->next=l;
					temp=temp->next;
					l=l->next;
				}
			}
			else
			{
				if(pa==NULL)
				{
					pa=r;
					temp=pa;
					r=r->next;
				}
				else
				{
					temp->next=r;
					temp=temp->next;
					r=r->next;
				}
			}
		}
	}
	while(l!=NULL)
	{
		temp->next=l;
		temp=temp->next;
		l=l->next;
	}
	while(r!=NULL)
	{
		temp->next=r;
		temp=temp->next;
		r=r->next;
	}
	
	return pa;

}

void printSpecificSortData(node *income,char uName[],char heading[])
{
	
	//clear screen
		system("cls");   //clear screen
		system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	//Searching scource of cost balance heading
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');

		int totalCost=0,slCost=1,cosX,cosY=22;
		node *temp=income;
		while(temp!=NULL)
		{
			cosX=18;
			//sum the total income of current month
			totalCost+=temp->data.amount; 
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=temp->data.date.d;
				d[1]=temp->data.date.m;
				d[2]=temp->data.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(cosX,cosY);
				color(63); printf("%d.",slCost); slCost++;
				cosX+=3;
				gotoXY(cosX,cosY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Scource: ");
				color(63); printf("%s",temp->data.scource);
				cosY+=1;
				gotoXY(cosX,cosY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",temp->data.amount);
				cosY+=2;
				//stepping
				temp=temp->next;
		}
	//find the current cursor position
		int z=cosY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print  Total cost;
		color(63);
		gotoXY(27,13); printf("total cost  : %d taka",totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(37,17); printf("COST");
	//making a table box....to display.
		makeBox(16,15,47,1,48,'.'); //row1
		makeBox(16,18,47,1,48,'.'); //row2
		makeBox(17,z,45,1,48,'.'); //row3	
		makeBox(16,16,0,z-15,48,'|'); //col1
		makeBox(63,16,0,z-15,48,'|'); //col3
}

void printSortData(node *income,node *cost,char uName[], char heading[])
{
	
	info in;
	system("cls");   //clear screen
	system("COLOR 3C");  // default consol background & text color
	//giving a heading into box
		gotoXY((79-strlen(uName))/2,4); color(63); printf("%s",uName);
		gotoXY((79-14)/2,6);printf("VIEW STATISTIC");
		makeBox((79-14)/2-2,7,17,1,63,'='); // create an underline
	
	//Searching All records heading
		gotoXY((79-strlen(heading))/2,10); color(49); printf("%s\n",heading);
		makeBox((79-strlen(heading))/2-2,11,strlen(heading)+3,1,49,'_');
	// pirnt income data from link list 
		int totalCost=0,totalIncome=0,slInc=1,slCost=1,inpoX,inpoY=22,copoX,copoY=22;
		node *temp1= income;
		while(temp1!=NULL)
		{
			inpoX=8;
			totalIncome+=temp1->data.amount; //sum the total income of current month
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=temp1->data.date.d;
				d[1]=temp1->data.date.m;
				d[2]=temp1->data.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(inpoX,inpoY);
				color(63); printf("%d.",slInc); slInc++;
				inpoX+=3;
				gotoXY(inpoX,inpoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",temp1->data.scource);
				inpoY+=1;
				gotoXY(inpoX,inpoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",temp1->data.amount);
				inpoY+=2;
			//stepping
				temp1=temp1->next;
		}
		//printing cost data from link list
		temp1= cost;
		while(temp1!=NULL)
		{
			copoX=42;
			totalCost+=temp1->data.amount; //sum the total cost of current month
			//make the date int to char
				int d[3];
				char date[12];
				d[0]=temp1->data.date.d;
				d[1]=temp1->data.date.m;
				d[2]=temp1->data.date.y;
				intToCharDate(d, date);  
				makeDate(date); //make date in my way
			//printing details in to the box.
				gotoXY(copoX,copoY);
				color(63); printf("%d.",slCost); slCost++;
				copoX+=3;
				gotoXY(copoX,copoY);
				color(52); printf("Date:    ");
				color(63); printf("%s",date);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Scource: ");
				color(63); printf("%s",temp1->data.scource);
				copoY+=1;
				gotoXY(copoX,copoY);
				color(52); printf("Amount:  ");
				color(63); printf("%d",temp1->data.amount);
				copoY+=2;
			//stepping
				temp1=temp1->next;

		}

	//find the current cursor position
		int z;
		(inpoY>copoY)?z=inpoY:z=copoY;
	//border print
		makeBox(0, 0, 79,z+16,2,'x');  //create a box 
	    makeBox(1, 1, 77,z+14,2,'x'); // create a box 
	// print current month Record;
		gotoXY(27,13); color(49); printf("total income: %d taka",totalIncome);
		gotoXY(27,14); printf("total cost  : %d taka",totalCost);
		gotoXY(27,15); printf("Balance     : %d taka",totalIncome-totalCost);
		
	//giving title of the table
		color(62);
		gotoXY(20,19); printf("INCOME");
		gotoXY(54,19); printf("COST");
	//making a table box....to display.
		makeBox(6,17,67,1,48,'.'); //row1
		makeBox(6,20,67,1,48,'.'); //row2
		makeBox(7,z,65,1,48,'.'); //row3	
		makeBox(6,18,0,z-17,48,'|'); //col1
		makeBox(40,18,0,z-17,48,'|'); //col2
		makeBox(73,18,0,z-17,48,'|'); //col3

}

void deleteFromMemory(node *list)
{
	node* temp;
	while(list!=NULL)
	{
		temp=list;
		list=list->next;
		free(temp);
	}

}

/*
void getCursorXY(int &x, int &y) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}

*/

void push(int x)
{
    top++;
    stack[top]=x;
}

int pop()
{
    int p;
    p=stack[top];
    top--;
    return p;
}

void gotoXY(int x, int y)
{
	HANDLE hCon;   // hCon er jaigai Amar name o deua jabe
	hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;  // cursor position er jaigai tomar name o deua jabe.
	cursorPosition.X=x;
	cursorPosition.Y=y;
	SetConsoleCursorPosition(hCon,cursorPosition);
}

void color(int c)
{
	HANDLE X;
	X= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(X,c);

}

void makeBox(int x,int y, int a, int b,int col, char shape)
{
	int i;

	for(i=0; i<a; i++)
    {
        gotoXY(i+x,y);
		color(col);
        printf("%c",shape);
    }
	for(i=0; i<b-1; i++)
    {
        gotoXY(x,y+i+1);
		color(col);
        printf("%c",shape);
    }
	for(i=0; i<a; i++)
    {
        gotoXY(i+x,y+b-1);
		color(col);
        printf("%c",shape);
    }
    for(i=0; i<b; i++)
    {
        gotoXY(x+a,y+i);
		color(col);
        printf("%c",shape);
    }
}

int spaceCheacker(char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
			return 1;
		i++;
	}
	return 0;
}

void makeDate(char date[])
{
    int i,flag=0,j=0,f=0;
    char qu[10]; 
	char faltu[12];
    for(i=0; date[i]!='\0'; i++)
    {
        if(date[i]>='0' && date[i]<='9')
        {
            qu[f]=date[i];
            f++;
        }
        else if(f<2)
        {
            faltu[j]='0';
            j++;
            faltu[j]=qu[0];
            j++;
            flag=1;
        }
        else if(f>1)
        {
            faltu[j]=qu[0];
            j++;
            faltu[j]=qu[1];
            j++;
            flag=1;
        }
        if(flag==1)
        {
            faltu[j]='/';
            j++;
            f=0;
            flag=0;
        }
    }
    qu[f]=NULL;

    if(f==2)
    {
        faltu[j]='2'; 
		j++;
        faltu[j]='0'; 
		j++;
    }
    faltu[j]=NULL; 
	strcat(faltu,qu); 
    strcpy(date,faltu);
}

void charToIntDate(char str[],int d[])
{

    int i,j=0,num,number=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            num=str[i]-'0';
            number=number*10+num;
        }
        else
        {
            d[j]=number;
            j++;
            number=0;
        }
    }
    d[j]=number;
}

void intToCharDate(int d[],char date[])
{
    int i,num,mod;
    for(i=2; i>=0; i--)
    {
        num=d[i];
        while(num>0)
        {
           mod= num%10;
           push(mod);
           num/=10;
        }
        if(i>0)
            push(109);
    }
    i=0;
    while(top>-1)
    {
        num=pop();
        if(num==109)
        {
            date[i]='/' ;
            i++;
        }
        else
        {
            date[i]= num+'0';
            i++;
        }
    }
    date[i]='\0';
}

int whichMonth(char str[])
{
		if( (str[0]=='j'||str[0]=='J')&&(str[1]=='a'||str[1]=='A')&&(str[2]=='n'||str[2]=='N') )
			return 1;
		else if( (str[0]=='f'||str[0]=='F')&&(str[1]=='e'||str[1]=='E')&&(str[2]=='b'||str[2]=='B') )
			return 2;
		else if( (str[0]=='m'||str[0]=='M')&&(str[1]=='a'||str[1]=='A')&&(str[2]=='r'||str[2]=='R') )
			return 3;
		else if( (str[0]=='a'||str[0]=='A')&&(str[1]=='p'||str[1]=='P')&&(str[2]=='r'||str[2]=='R') )
			return 4;
		else if( (str[0]=='m'||str[0]=='M')&&(str[1]=='a'||str[1]=='A')&&(str[2]=='y'||str[2]=='Y') )
			return 5;
		else if( (str[0]=='j'||str[0]=='J')&&(str[1]=='u'||str[1]=='U')&&(str[2]=='n'||str[2]=='N') )
			return 6;
		else if( (str[0]=='j'||str[0]=='J')&&(str[1]=='u'||str[1]=='U')&&(str[2]=='l'||str[2]=='L') )
			return 7;
		else if( (str[0]=='a'||str[0]=='A')&&(str[1]=='u'||str[1]=='U')&&(str[2]=='g'||str[2]=='G') )
			return 8;
		else if( (str[0]=='s'||str[0]=='S')&&(str[1]=='e'||str[1]=='E')&&(str[2]=='p'||str[2]=='P') )
			return 9;
		else if( (str[0]=='o'||str[0]=='O')&&(str[1]=='c'||str[1]=='C')&&(str[2]=='t'||str[2]=='T') )
			return 10;
		else if( (str[0]=='n'||str[0]=='N')&&(str[1]=='o'||str[1]=='O')&&(str[2]=='v'||str[2]=='V') )
			return 11;
		else if( (str[0]=='d'||str[0]=='D')&&(str[1]=='e'||str[1]=='E')&&(str[2]=='c'||str[2]=='C') )
			return 12;
}

int whichYear(char str[])
{
	int i=0,j=0,q;
	char p[5];
	while(str[i]!='\0')
	{
		if(str[i]>='0' && str[i]<='9')
		{
			p[j]=str[i];
			j++;
		}
		i++;
	}
	p[j]='\0';
	i=0,j=0;
	while(p[i]!='\0')
	{
		q=p[i]-'0';
		j=j*10+q;
		i++;
	}
	return j;
		
}

void intToChar(int x,char a[])
{
	int i=0,mod;
	while(x>0)
	{
		mod=x%10;
		a[i]=mod+'0';
		i++;
		x/=10;
	}
	a[i]='\0';
	strrev(a);
}

//making passward syntex...
bool keyHit(void)
{
  HANDLE  stdIn = GetStdHandle(STD_INPUT_HANDLE);

  DWORD   saveMode;
  GetConsoleMode(stdIn, &saveMode);
  SetConsoleMode(stdIn, ENABLE_PROCESSED_INPUT);

  bool  ret = false;

  if (WaitForSingleObject(stdIn, 1) == WAIT_OBJECT_0) ret = true;

  SetConsoleMode(stdIn, saveMode);

  return(ret);
}

bool getChar(TCHAR &ch)
{
  bool    ret = false;

  HANDLE  stdIn = GetStdHandle(STD_INPUT_HANDLE);

  DWORD   saveMode;
  GetConsoleMode(stdIn, &saveMode);
  SetConsoleMode(stdIn, ENABLE_PROCESSED_INPUT);

  if (WaitForSingleObject(stdIn, INFINITE) == WAIT_OBJECT_0)
  {
    DWORD num;
    ReadConsole(stdIn, &ch, 1, &num, NULL);

    if (num == 1) ret = true;
  }

  SetConsoleMode(stdIn, saveMode);

  return(ret);
}

TCHAR getChar(void)
{
  TCHAR ch = 0;
  getChar(ch);
  return(ch);
}

void password(char pass[])
{
	char ch;
	int i=0;
	while(1)
	{
		ch=getChar();
		if(ch==13 || ch== 9)  //enter or tab
		{	
			pass[i]='\0';
			break;
		}
		else if(ch==8)  //backSpace
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pass[i]=ch;
			printf("*");
			i++;
		}
	}
}

							//Done By Shazzad
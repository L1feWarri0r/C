/*INCLUDING                        HEADER                FILES */
#include<stdio.h>           
#include<conio.h>      
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<time.h>
/*                 CREATING                      USER-DEFINED               DATA        TYPE       */
struct motors
{
	int car,bus,taxi,bike,truck;
};
struct date
{
	int day,month,year,d1,m1,y1;
};
struct time
{
	int hr,min,sec,h,m,s;
};
struct customer
{
    float a; 
	struct date d;
	struct time t;
	char dl[40],name[50],ph[11],v[30],vc[25];
};
/* DECLARE       GLOBAL         VARIABLES      */
int ca=50,b=100,t=20,bs=30,a=100;
struct customer cus;
/*DECLARATION        OF        FUNCTIONS         */
void l1();
void customer();
int menu();
void bill();
void ncus();
void ncus();
void ocus();
void manager();
void mmenu();
void search();
void date();
void name();
void vn();
void ln();
void nm();
void l();
void p();
void vo();
void today();
/*            DEFINITION                OF                   FUNCTIONS        */
void today()
{   system("cls");
	struct customer c;
	FILE *f;
	float p=0;
	int da,m,y,z=0;
	printf("enter date:");
	scanf("%d/%d/%d",&da,&m,&y);
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if(da==c.d.day&&m==c.d.month&&y==c.d.year)
		{z++;
		     p=p+c.a;
	       	 printf("\n%d/%d/%d\t%s    \t%f\n",c.d.day,c.d.month,c.d.year,c.vc,c.a);
		}
	}
	if(z==0) printf("entered date not match.");
	else
	printf("TOTAL RECEIVED AMOUNT TODAY:\t%f",p);
	fclose(f);
}
void vn()
{   system("cls");
	struct customer c;
	int i,z=0;
	FILE *f;
	char nm[30];
	printf("enter Vechiles Code:");
	fflush(stdin);
	gets(nm);	
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if((i=strcmp(nm,c.vc))==0)
		{   z++;
		    printf("Booking details:\nNAME:%s\n",c.name);
        	printf("License No:%s\n",c.dl);
        	printf("Phone No:%s\n",c.ph);
        	printf("Vechiles Type:%s\n",c.v);
        	printf("Vechiles Code:%s\n",c.vc);
        	printf("Total Amount:%f\n",c.a);      
            printf("\nDate of Booking:%d/%d/%d",c.d.day,c.d.month,c.d.year);
            printf("\nTime:%d:%d:%d",c.t.hr,c.t.min,c.t.sec);
        	
		}
	}
	if(z==0)
	{
		printf("Entered data not found.");
	}
	fclose(f);
}
void ln()
{   system("cls");
	struct customer c;
	int i,z=0;
	FILE *f;
	char nm[30];
	printf("enter License No::");
	fflush(stdin);
	gets(nm);	
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if((i=strcmp(nm,c.dl))==0)
		{   z++;
			printf("Booking details:\nNAME:%s\n",c.name);
        	printf("License No:%s\n",c.dl);
        	printf("Phone No:%s\n",c.ph);
        	printf("Vechiles Type:%s\n",c.v);
        	printf("Vechiles Code:%s\n",c.vc);
        	printf("Total Amount:%f\n",c.a);
            printf("Date of Booking:%d/%d/%d",c.d.day,c.d.month,c.d.year);
            printf("\nTime:%d:%d:%d",c.t.hr,c.t.min,c.t.sec);
    
		}
	}
	if(z==0)
	{
		printf("Entered data not found.");
	}
	fclose(f);
}
void name()
{   system("cls");
	struct customer c;
	int i,z=0;
	FILE *f;
	char nm[30];
	printf("enter Name:");
	fflush(stdin);
	gets(nm);	
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if((i=strcmp(nm,c.name))==0)
		{   z++;
			printf("Booking details:\nNAME:%s\n",c.name);
        	printf("License No:%s\n",c.dl);
        	printf("Phone No:%s\n",c.ph);
         	printf("Vechiles Type:%s\n",c.v);
        	printf("Vechiles Code:%s\n",c.vc);
        	printf("Total Amount:%f\n",c.a);
            printf("Date of Booking:%d/%d/%d",c.d.day,c.d.month,c.d.year);
            printf("\nTime:%d:%d:%d",c.t.hr,c.t.min,c.t.sec);
        	
		}
	}
	if(z==0)
	{
		printf("Entered data not found.");
	}
	fclose(f);
}
void date()
{   system("cls");
	struct customer c;
	FILE *f;
	int da,m,y,z=0;
	printf("enter date:");
	scanf("%d/%d/%d",&da,&m,&y);
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if(da==c.d.day&&m==c.d.month&&y==c.d.year)
		{   z++;
			printf("Booking details:\nNAME:%s\n",c.name);
        	printf("License No:%s\n",c.dl);
           	printf("Phone No:%s\n",c.ph);
           	printf("Vechiles Type:%s\n",c.v);
           	printf("Vechiles Code:%s\n",c.vc);
           	printf("Total Amount:%f\n",c.a);
            printf("Date of Booking:%d/%d/%d",c.d.day,c.d.month,c.d.year);
            printf("\nTime:%d:%d:%d",c.t.hr,c.t.min,c.t.sec);
        	
		}
	}
	if(z==0)
	{
		printf("Entered data not found.\n");
	}
	fclose(f);
}
void search()
{   system("cls");
    char i;
    do{
    	printf("\nSEARCH MENU\n1.\tSearch by Date\n2.\tSearch by Name\n3.\tSearch by Vechiles Code\n4.\tSearch by License number\n5.\tEXIT\n");
    	printf("Please enter your choice:");
    	fflush(stdin);
		i=getchar();
    	switch(i)
        	{
	        	case '1':date();break;
	        	case '2':name();break;
	        	case '3':vn();break;
	        	case '4':ln();break;
	        	case '5':exit(0);
	        	default:printf("wrong choice.\n");
        	}
      }
    while(i!='5');
}
void mmenu()
{
	l1();
    printf("                   WELCOME IN BAJRANGI AUTOMOBILES PARKING LOT");
    l1();
    printf("                                   MENU\n");
    printf("                         ---------------------------");
    printf("\nVECHILES TYPE       \tPRICE     \tTOTAL SPACE(in nos)\n----------------------------------------------------------");
    printf("\nCAR                \t100/day   \t50\nBUS                 \t200/day   \t30\nTRUCK               \t400/day   \t20");
    printf("\nAUTO-RICKSAW        \t80/day   \t100\nMOTOR-BIKE          \t20/day    \t100\n");
    printf("TERMS AND CONDITIONS\n1.  Payment non-refundable.\n2.  License are compulsory\n3.  Extra charges will being applied on exceeding 24 hrs.\n");
    printf("4.  20 percent discount is available on advance booking for a month.");
    return;
}
void manager()
{   system("cls");
    char i;
    do
	  {
	     printf("\nMENU\n");
	     printf("\n1.\tSEARCH\n2.\tTOTAL RECEIVED AMOUNT BY DATE\n3.\tTOTAL RECEIVED AMOUNT\n4.\tEXIT\nplease enter your choice:");
	     fflush(stdin);
	     i=getchar();
       	 switch(i)
        	{
           		case '1':search();break;
	        	case '2':today();break;
	        	case '3':bill();break;
	        	case '4':exit(0);
	        	default:printf("you entered wrong choice.\n");
	        }
      }
    while(i!='4');
}
void ocus()
{   system("cls");
	struct customer c,c1;
	FILE *f,*fp;
	SYSTEMTIME time1;
    time_t today;
    struct tm *local;
    GetSystemTime(&time1);
  	today=time(NULL);
	local=localtime(&today);
	char ch[25];
	float total=0;
	int i,j,a,b,cw;
	printf("Enter your vechile code:");
	fflush(stdin);
	gets(ch);
	f=fopen("newcustomer.txt","rb");
	fp=fopen("oldcustomer.txt","ab+");
	while(fread(&c,sizeof(c),1,f)>0)
	{
		if((i=strcmp(ch,c.vc))==0)
		{      
	        while(fread(&c1,sizeof(c1),1,fp)>0)	
		       {
		       	if((j=strcmp(ch,c1.vc))==0)
		        	{
		       	    	printf("Entered vechicles code already checked out.");return;
				    }
			   }
		       c1=c;
		       
		       c1.d.y1=time1.wYear;c1.d.m1=time1.wMonth;c1.d.d1=time1.wDay;
               c1.t.h=local->tm_hour;c1.t.m=local->tm_min;c1.t.s=local->tm_sec;
               a=c1.t.h-c.t.hr;b=c1.t.m-c.t.m;cw=c1.t.s-c.t.s;
               if(a<=24)
                 {
                 	total=c.a;
			     }
			   else 
			     {
			    	printf("You will have been paid extra charges for extra time:%d:%d:%d\nAmount paid:%f",a,b,cw,total=2*c.a);
			     }
			 fwrite(&c1,sizeof(c1),1,fp);
			 if((j=strcmp("CAR",c.vc))==0)
			     {
			    	ca++;
			     }
			else if((j=strcmp("BUS",c.vc))==0)
			     {
				    bs++;
		         }
			else if((j=strcmp("TRUCK",c.vc))==0)
		    	{
		    		t++;
		    	}
		 	else if((j=strcmp("AUTO-RICKSAW",c.vc))==0)
		       	{
			    	a++;
		    	}
			else if((j=strcmp("MOTOR-BIKE",c.vc))==0)
		    	{
			    	b++;	
		    	}	
	    }
	}
	fclose(f);fclose(fp);
	fp=fopen("oldcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,fp)>0)
        {      if((j=strcmp(ch,c1.vc))==0)
                {
		            printf("\nYour booking details:\nNAME:%s\nLicense No:%s\nPhone No:%s\nVechiles Type:%s\nVechiles Code:%s\nTotal Amount:%f\n",c.name,c.dl,c.ph,c.v,c.vc,total);
		            printf("check in date:%d/%d/%d\ncheck in time:%d:%d:%d\ncheck out date :%d/%d/%d\ncheck out time:%d:%d:%d\n",c.d.day,c.d.month,c.d.year,c.t.hr,c.t.min,c.t.sec,c.d.d1,c.d.m1,c.d.y1,c.t.h,c.t.m,c.t.s);
			        printf("\nHAPPY JOURNEY!\nVISIT AGAIN.\nTHANK YOU.\n");
				}
		}
    fclose(fp);
}
void l()
{
	char x[30];
	printf("License No:");
	fflush(stdin);
	gets(x);
	int j,z=0;
	  for(j=0;x[j]!='\0';j++)
        { 
		    if(!((x[j]>=65&&x[j]<=90)||(x[j]>=97&&x[j]<=122)||(x[j]>=48&&x[j]<=57)))
            	{
				    z++;
		        	printf("invalid license no.");
					break;
		    	}
		}
		if(z>0) 
		l();
		else
	strcpy(cus.dl,x);
}
void nm()
{   
	char x[30];
	int j,z=0;
	printf("NAME:");
	fflush(stdin);
	gets(x);
	  for(j=0;x[j]!='\0';j++)
        { 
		
		    if(x[j]==32) 
			{
				if(isspace(x[0]))
		        	{  
					    z++;
				        printf("name not startrd with space.\n");
						break;
					}
        	}
		
		    else if(!((x[j]>=65&&x[j]<=90)||(x[j]>=97&&x[j]<=122)))
            	{   
				    z++;
		        	printf("invalid name.\n");
					break;
		    	}
		}
		if(z>0)
		{
			nm();
		}
		else 
		 {
			 strcpy(cus.name,x);
		 }
}
void p()
{
	char x[30];
	printf("Phone No:");
	fflush(stdin);
	gets(x);
	int j,z=0,t=0;
	  for(j=0;x[j]!='\0';j++)
        { 
		   t++;
		   if(!(x[j]>=48&&x[j]<=57))
           	{
			    z++;
		       	printf("Invalid Phone No:");
				break;
			}
		}
		if(z>0) p();
		if(t>10||t<10)
		    {
		      printf("Phone no invalid.\nplease enter 10-digits phone number.\n");
			  p();
	    	}
		else	strcpy(cus.ph,x);
}
void vo()
{
	char x[30];
	printf("Vechile Code:");
	fflush(stdin);
	gets(x);
	int j,z=0;
	  for(j=0;x[j]!='\0';j++)
        { 
		    if(!((x[j]>=48&&x[j]<=57)||(x[j]==45)||(x[j]==47)||(x[j]>=65&&x[j]<=90)||(x[j]>=97&&x[j]<=122)))
        	    {
				    z++;
		        	printf("invalid Vechile code.");
					break;
		    	}
		}
	  if(z>0)
	   vo();
	  else
	   strcpy(cus.vc,x);	
}

void bill()
{   system("cls");
	struct customer c;
	FILE *f;
	float p=0;
	printf("DATE      \tVECHILES CODE  \tAMOUNT PAID\n");
	f=fopen("newcustomer.txt","rb");
	while(fread(&c,sizeof(c),1,f)>0)
	{   
	    p=p+c.a;
		printf("\n%d/%d/%d\t%s    \t%f\n",c.d.day,c.d.month,c.d.year,c.vc,c.a);
	}
	printf("\nTOTAL RECEIVED AMOUNT TODAY:\t%f",p);
	fclose(f);
}
int menu()
{char i;
	FILE *f;
	f=fopen("vechcles.txt","ab");
	fwrite(&c,sizeof(c),1,f);
	fclose(f);
do
{
  printf("                                   MENU\n");
  printf("                         ---------------------------");
  printf("\nVECHILES TYPE       \tPRICE     \tSPACE AVAILABLE\n----------------------------------------------------------");
  printf("\n1.   CAR                \t100/day   \t%d\n2.   BUS                 \t200/day   \t%d\n3.   TRUCK               \t400/day   \t%d",ca,bs,t);
  printf("\n4.   AUTO-RICKSAW        \t80/day   \t%d\n5.   MOTOR-BIKE          \t20/day    \t%d\n",a,b);
  printf("6.   EXIT");
  printf("\nRECEPTION GIRL: HELLO! SIR/MAM\nPlease enter your choice:");
  fflush(stdin);
  i=getchar();
  switch(i)
    {
	  case '1':return 1;break;
	  case '2':return 2;break;
	  case '3':return 3;break;
	  case '4':return 4;break;
	  case '5':return 5;break;
	  case '6':exit(0);
	  default:printf("\nSorry!you entered wrong choice.\n");
	}
}
while(i!='6');
}
void customer()
{  
   system("cls");
   char c;
   mmenu();
   do
   {
      printf("\n\n\nAre you a new customer(y/n):");
      fflush(stdin);
	  c=getchar();
      if(c=='y'||c=='Y')
	    {   
		    ncus();return;
        }
      else if(c=='n'||c=='N')
        {
		    ocus();
        }
      else
	    {
		    printf("Sorry!you entred wrong choice.\n");
        }
    } while(c!='y'&&c!='n');
}
void l1()
{
	printf("\n            --------------------------------------------------------\n");
}
void ncus()
{
	system("cls");
    SYSTEMTIME time1;
    time_t today;
    struct tm *local;
    struct customer c;
    GetSystemTime(&time1);
  	today=time(NULL);
	local=localtime(&today);
	int j;
	FILE *f;
	f=fopen("newcustomer.txt","ab");
    j=menu();
    switch(j)
    {
    	case 1:strcpy(c.v,"CAR");c.a=100;--ca;c.d.year=time1.wYear;c.d.month=time1.wMonth;c.d.day=time1.wDay;
               c.t.hr=local->tm_hour;c.t.min=local->tm_min;c.t.sec=local->tm_sec;break;
    	case 2:strcpy(c.v,"BUS");c.a=200;bs--;c.d.year=time1.wYear;c.d.month=time1.wMonth;c.d.day=time1.wDay;
               c.t.hr=local->tm_hour;c.t.min=local->tm_min;c.t.sec=local->tm_sec;break;
    	case 3:strcpy(c.v,"TRUCK");c.a=400;t--;c.d.year=time1.wYear;c.d.month=time1.wMonth;c.d.day=time1.wDay;
               c.t.hr=local->tm_hour;c.t.min=local->tm_min;c.t.sec=local->tm_sec;break;
    	case 4:strcpy(c.v,"AUTO-RICKSAW");c.a=80;a--;c.d.year=time1.wYear;c.d.month=time1.wMonth;c.d.day=time1.wDay;
               c.t.hr=local->tm_hour;c.t.min=local->tm_min;c.t.sec=local->tm_sec;break;
    	case 5:strcpy(c.v,"MOTOR-BIKE");c.a=20;b--;c.d.year=time1.wYear;c.d.month=time1.wMonth;c.d.day=time1.wDay;
               c.t.hr=local->tm_hour;c.t.min=local->tm_min;c.t.sec=local->tm_sec;break;
	}
	printf("Please give your details:\n");
	nm();
	strcpy(c.name,cus.name);
	l();
	strcpy(c.dl,cus.dl);
	p();
	strcpy(c.ph,cus.ph);
	vo();
	strcpy(c.vc,cus.vc);
	fwrite(&c,sizeof(c),1,f);
	fclose(f);
	system("cls");
	printf("Your booking details:\nNAME:%s\n",c.name);
	printf("License No:%s\n",c.dl);
	printf("Phone No:%s\n",c.ph);
	printf("Vechiles Type:%s\n",c.v);
	printf("Vechiles Code:%s\n",c.vc);
	printf("Total Amount:%f\n",c.a);
    printf("Date of Booking:%d/%d/%d",time1.wDay,time1.wMonth,time1.wYear);
    printf("\nTime:%d:%d:%d",local->tm_hour,local->tm_min,local->tm_sec);
	printf("\n\nTHANKYOU !");
}
/*        DEFINITION            OF               MAIN()       */
int main()
{
   char c;
   system("cls");
   mmenu();
   do
     {
	    printf("\nRECEPTION\n1.\tMANAGER\n2.\tCUSTOMER\n3.\tEXIT\nPlease enter your choice:");
        fflush(stdin);
		c=getchar();
        switch(c)
          {
	         case '1':manager();break;
	         case '2':customer();break;
           	 case '3':exit(0);break;
             default:printf("\nSorry!you entered wrong choice.\n");	    	      
          }
     }while(c!='3');
getch();
	return 0;
}


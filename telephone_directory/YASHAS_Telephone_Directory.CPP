#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main();




int del(long int n[], int j, char name[][100], char city[][100])
{
   long int d; int pos;
   printf("\nEnter the Phone number: ");
   scanf("%ld",&d);
   for(int i=0;i<j;i++)
   {
     if(d==n[i])
     pos=i;
   }
   for(i=pos;i<j-1;i++)
   {
      n[i]=n[i+1];
      strcpy(name[i],name[i+1]);
      strcpy(city[i],city[i+1]);
   }
   return(--j);
}





void display(long int n[], char name[][100], char city[][100], int j)
{
   for(int i=0;i<j;i++)
   {
      printf("\nNumber: %ld",n[i]);fflush(stdin);
      printf("\nName: %s",name[i]);fflush(stdin);
      printf("\nCity: %s\n",city[i]);fflush(stdin);
   }
   main();
}





void update(long int n[], int j, char name[][100], char city[][100])
{
   int ch;long int up;int pos;
   printf("Enter your number: ");
   scanf("%ld",&up);
   for(int k=0;k<j;k++)
   {
      if(n[k]==up)
      pos=k;

   }
  long int tn; char tname[100]; char tcity[100];
   printf("\nPress\n1 to update Phone number\n2 to update Name\n3 to update City: ");
   fflush(stdin);
   scanf("%d",&ch);
   fflush(stdin);
   printf("\n");
   switch(ch)
   {
      case 1:
      printf("Enter your New number: ");
      scanf("%ld",&tn);
      fflush(stdin);
      n[pos]=tn;
      break;
      case 2:
      printf("Enter your New name: ");
      scanf("%s",tname);fflush(stdin);
      strcpy(name[pos],tname);
      break;
      case 3:
      printf("Enter your New City: ");
      scanf("%s",tcity);fflush(stdin);
      strcpy(city[pos],tcity);
      break;
      default:
      printf("Wrong Input!");
   }
}






int main()
{
   int ch;
   static int i=0;
   printf("\n**********TELEPHONE DIRECTORY**********\n");
   printf("Enter 1 to ADD, 2 to DISPLAY, 3 to DELETE, 4 to UPDATE or 0 to EXIT: ");
   scanf("%d",&ch);
   static long int n[100];static char name[100][100];static char city[100][100];



   switch(ch)
   {
      case 1:
      for(;ch!=0;i++)
      {
	 if(ch==2||ch==3||ch==4)
	 {
	      break;
	 }
	 else if(ch==0)
	 exit(0);
	 printf("Enter Phone Number: ");
	 scanf("%ld",&n[i]);
	 printf("Enter Name: ");
	 scanf("%s",name[i]);fflush(stdin);
	 printf("Enter City: ");
	 scanf("%s",city[i]);fflush(stdin);
	 printf("Enter 1 to ADD, 2 to DISPLAY, 3 to DELETE, 4 to UPDATE or 0 to EXIT: ");
	 scanf("%d",&ch);
      }
	 if(ch==2)
	 {
	   display(n,name,city,i);
	 }
	 if(ch==3)
	 {
	   del(n,i,name,city);printf("Deletion successful!");main();
	 }
	 if(ch==4)
	 {
	   update(n,i,name,city);printf("Update successful!");main();
	 }
	 if(ch==0)
	 exit(0);
	 break;

	case 2:
	display(n,name,city,i);
	break;

	case 3:
	i=del(n,i,name,city);
	printf("Deletion successful!");main();
	break;

	case 4:
	update(n,i,name,city);
	printf("Update successful!");main();
	break;


	case 0:
	exit(0);
   }
   return 0;
}
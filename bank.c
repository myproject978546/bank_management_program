#include<stdio.h>
#include<conio.h>
//  *****************  bank management program  ***************
main()
{
  struct nkp
  {
    char name[50],type[15];
    long int bal,*k;
  }*ptr,*ptr1,*ptr2,*ptr3,*temp,*temp1;
  int count=0,in,a=0,b=0,c=0,tempamount;
  char x,tempname[60];
  clrscr();
  do
  {      clrscr();
	 printf("******************************  Welcome to NKP Bank  ***************************\n");
	 printf("Press 1 for create new account\nPress 2 for login account\nPress 3 for see all customer : ");
	 scanf("%d",&in);
	 switch(in)
	 {
	   case 1 : ptr=(struct nkp*)malloc(1*sizeof(struct nkp));
		    if(count==0)
		    ptr1=ptr2=ptr;
		    else
		    {
		      ptr2->k=ptr;
		      ptr2=ptr;
		    }
		    fflush(stdin);
		    printf("Enter your full name : ");
		    gets(ptr->name);
		    printf("Press 1 for savings account and press 2 for current account : ");
		    scanf("%d",&in);
		    if(in==1 && printf("You choose savings account\n"))
		    strcpy(ptr->type,"savings");
		    else
		    {
		      printf("you choose current account\n");
		      strcpy(ptr->type,"current");
		    }
		    printf("Enter amount : ");
		    scanf("%ld",&(ptr->bal));
		    count++;
		    break;
	   case 2 : fflush(stdin);
		    printf("enter account holder name : ");
		    gets(tempname);
		    temp=ptr1;
		    for(a=0;a<count;a++)
		    {
			b=strcmp(tempname,temp->name);
			if(b==0)
			{
			  a=-1;
			  printf("Press 1 for add amount to your account\nPress 2 for withraw amount to your account\nPress 3 for see your aaccount details\nPress 4 for delete\n");
			  scanf("%d",&in);
			  switch(in)
			  {
			    case 1 : fflush(stdin);
				     printf("enter amount : ");
				     scanf("%d",&(tempamount));
				     temp->bal=(temp->bal)+tempamount;
				     printf("amount added successfully\n");
				     break;
			    case 2 : fflush(stdin);
				     printf("enter amount : ");
				     scanf("%d",&(tempamount));
				     if(temp->bal>=tempamount)
				     {
					temp->bal=(temp->bal)-tempamount;
					printf("amount withdrawl sucessfully\ncollect your cash\nNow available balance is %ld\n",temp->bal);
				     }
				     else
				     printf("Insufficient balance\n");
				     break;
			    case 3 : printf("\n\nHolder name : %s\nAccount type : %s\nAvailable balance : %ld\n",temp->name,temp->type,temp->bal);
				     printf("press 1 for change account details otherwise press 0 for continue : ");
				     scanf("%d",&in);
				     if(in==1)
				     {
					fflush(stdin);
					printf("press 1 for change account holder name\npress 2 for change account type :  ");
					scanf("%d",&in);
					if(in==1)
					{  fflush(stdin);
					  printf("Enter new name : ");
					  gets(temp->name);
					  printf("your details saved sucessfully\n");
					}
					else
					{
					   fflush(stdin);
					   printf("Press 1 for savings and press 2 for current account : ");
					   scanf("%d",&in);
					   if(in==1)
					   strcpy(temp->type,"saving");
					   else
					   strcpy(temp->type,"current");
					}
				      }
				      break;
			     case 4 : if(ptr1==temp)
				      ptr1=ptr1->k;
				      else
				      temp1->k=temp->k;
				      printf("Account deleted Successfully\n",count--);
				      break;
			    default : printf("Not a valid command\n");
			  }
			  break;
			}
			temp1=temp;
			temp=temp->k;
		    }
		    if(a!=-1)
		    printf("'%s' is not find\n",tempname);
		    break;
	   case 3 : if(count==0)
		       printf("No Customers\n");
		    else
		       for(temp=ptr1,a=0;a<count;a++,temp=temp->k)
		       printf("Name : '%s'     Account type : '%s'     Balance : '%ld'\n",temp->name,temp->type,temp->bal);
		    break;
	   default : printf("Invalid command\n");
	 }
	 printf("Press 1 for Menu\tPress 0 for exit : ");
	 scanf("%d",&in);
  }while(in);
getch();
}

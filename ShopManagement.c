#include<stdio.h>
#include<string.h>

static char empid[10], productid[20];

void get()
{
   int s;
   double percost;
   double persell;
   double profit;

   double cost;
   double sell;
   char name[50];
   int quan;
   printf("\nnumber of products produced?\n");
   scanf("%d",&s);
   for(int i=0;i<s;i++)
   {
      printf("\ninput product name: \n");
      scanf("%s",name);
      printf("\ninput product id: \n");
      scanf("%s",productid);
      printf("\ninput cost price of product: \n");
      scanf("%lf",&percost);
      printf("\ninput selling price of product: \n");
      scanf("%lf",&persell);
      printf("\ntotal product quantity: \n");
      scanf("%d",&quan);
   }

}


void getstaff()
{
   double salary;
   char post[12];
   
   int postquan;

   printf("\ninput salary: \n");
   scanf("%lf",&salary);
   printf("\ninput number of employees: \n");
   scanf("%d",&postquan);
   for(int i=0;i<postquan;i++)
   {
      printf("input employee name\n");
      scanf("%s",post);
      printf("\ninput employee ID\n");
      scanf("%s",empid);
   }
}


void add()
{
	int ch;
	while(1)
	{
		printf("1.)Input for product\n2.)Input for employee\n3.)Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		if(ch==1)
      {
			get();
		}
		else if(ch==2)
      {
			getstaff();
		}
		else if(ch==3)
			break;
		else
			printf("Invalid Option. Please re-enter\n");
	}
}


void update_item()
{
	char id[20];
	char pid[20];
   char name[20];
	char c;
   double percost;
   double persell;
   double profit;

   double cost;
   double sell;

   int quan;
	printf("\nINPUT product ID to modify\n");
	scanf("%s",id);

   if (strcmp(id,productid))
   {
   
      printf("\n  Update product name:           ");
      scanf("%s",name);
      printf("\n  Update percost of product:     ");
      scanf("%lf",&percost);
      printf("\n  Update persell of product:     ");
      scanf("%lf",&persell);
      printf("\n  Update total product quantity: ");
      scanf("%d",&quan);

      cost=percost*quan;
      sell=persell*quan;
      profit=profit +(sell-cost)*365;
   }
   else
   {
      printf("\nWrong ID\n");
   }
}


void update_emp()
{
	char id[20];
   char post[12];
   float salary;
   printf("\nINPUT employee ID to modify: ");
   scanf("%s",id);
   if (strcmp(id,empid))
   {
      printf("modify employee name: \n");
      scanf("%s",post);
   }
}


int passwords()
{

	char p1,p2,p3;
	printf("\n\n********************************************************************************");
	printf("\n\n\t\t\tENTER THE PASSWORD: ");
	printf("\n\n\t\t\tPress 1 For Hint -> ");
	int hint;
	scanf("%d",&hint);
	if(hint==1)
	{
      printf("\n\n\t\tPassword Hint : 'eln' or 'ELN' ");
	}
	printf("\n\n\t\t\tENTER THE PASSWORD: ");
	scanf("%c",&p1);
	printf("*");
	scanf("%c",&p2);
	printf("*");
	scanf("%c",&p3);
	printf("*");

	if ((p1=='e'||p1=='E')&&(p2=='l'||p2=='L')&&(p3=='n'||p3=='N'))
		return 1;
	else
		return 0;
}
// END of Password.

int admin()
{
   char opt;
   while(1)
   {
		pass:
		printf("\n\t\t\t1. Add Entries\n\n\t\t\t2. Modify Product Details\n\n\t\t\t3. Modify Employee Details\n\n\t\t\t4. Billing\n\n\t\t\t5. Exit");
		printf("\n\n\t\t\tSelect your choice:- ");
		int u;
		scanf("%d",&u);
		if(u==1)
		{
		   add();
		}
      else if(u==2)
      {
         update_item();
      }
      else if(u==3)
      {
         update_emp();
      }
      else if(u==4)
      {
         char ch;
         int a=1;
         if(!(a==passwords()))
         {
            for(int i=0;i<2;i++)
            {
               printf("\nWrong password try once more\n");
               if(passwords())
               {
                  goto last;
               }
               else
               {
                  printf("\n\n\t\t\t all attempts failed.....");
                  printf("\n\n\n\t\t\t see you.................. ");
                  return 0;
               }
            }
            printf("\t\t\t sorry all attempts failed............. \n \t\t\tinactive");
         }
         else
         {
            last:
            do
            {
               start:
                  printf("\n\n\t\t\t------------------------------");
                  printf("\n\t\t\tShop Billing Management System");
                  printf("\n\t\t\t------------------------------");
                  printf("\n\n\t\t\tWhat you want to do?");
                  printf("\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n");
                  printf("\n\nEnter your option: ");
                  scanf("%c",&opt);
               switch(opt)
               {
                        case '1':
                           // vatcal();
                           // outputs();
                           goto start;

                        case '2':
                           goto start;

                        case '3':
                           goto pass;

                        default:
                           printf("\a");
                           break;
               }//End of switch

            }//End of do
            while(opt!=3);
         }//End of Else
	   } //End of else...if
	   else if(u==5)
	   {
         break;
      }
      else 
      {
         printf("Invalid option. Please select one of the available options\n");
      }
	}//End of while
}// End of Admin


int main()
{
   int ch;
   while(1)
   {
      printf("\n \t\t\t=========================\n");
      printf("\n \t\t\t   WELCOME TO SHOPEASY    \n");
      printf("\n \t\t\t=========================\n\n");
      printf("\n \t\t\t* * * * * * * * * * * * ");
      printf("\n\t\t\t  1. ENTER SYSTEM");
      printf("\n\t\t\t  2. About...");
      printf("\n\t\t\t  3. EXIT");
      printf("\n\t\t\t* * * * * * * * * * * *\n");
      printf("\n\t\t\t Enter Your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
            case 1:
				   admin();
				   break;
            case 2:
               printf("\n \t\t\t|************************|  \n\t\t\t|	        	 |");
               printf("\n \t\t\t|        SHOPEASY        |  \n\t\t\t|                        |\n\t\t\t|                        |");
               printf("\n \t\t\t|      Devoloped By:     |  \n\t\t\t|		         |");
               printf("\n \t\t\t|      Arati Jadhav      |    ");
               printf("\n \t\t\t|     Tushar Gaikwad     |    ");
               printf("\n \t\t\t|************************|\n\n");

               break;
            case 3:
               return 0;
               break;
            default:
				   printf("Enter valid choice\n");
				break;
      }
   }
   return 0;
}
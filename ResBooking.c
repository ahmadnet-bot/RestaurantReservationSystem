//Stage A complete
//Stage B complete
//Stage C partially complete (Implemented malloc)
//Stage D partially (Implemented Hidden option 9 to display Total revenue)

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#define MAX 25

typedef enum 			//Enum to store burger type
{
	Chicken=1,
	Ham, 
	Vegie
	
}variety; 

typedef struct 			//Struct for burger
{
	float quantity;
	float totalprice;
	variety pick;
	
}burger;

typedef struct			//Struct for Order
{
	char brec[6];
	float finalOrder;
	burger* b;			
	
}order;

order* recarray[MAX];	//Array storing 25 orders and pointing towards the order struct
int i = 0;


void burgerOrder()
{
	float qty;
	float totprice;
	char select;
	char bill[6] = "B00";
	
	burger* b =(burger*)malloc(sizeof(burger));			//Allocating memory burger
	order* o = (order*)malloc(sizeof(order));			//Allocating memory to order struct
	
	do
	{
		printf("Select the Burger type \n");
		printf("A - Chicken Burger - 15$\n");
		printf("B - Ham Burger - 17$\n");
		printf("C - Vegie Burger - 13$\n");
		printf("X - To return to Main Menu\n");
		
		printf("Select your burger type:\n");
		scanf("%s", &select);
		fflush(stdin);
		
		switch(select)					//Switch present to give the burger type options
		{
			case 'A' : 
			
				b->pick = Chicken;		//Enum value Chicken is assigned inside the burger struct
				
				printf("You have selected Chicken. How many burgers would you like to order?\n");
				scanf("%f", &qty);
				fflush(stdin);
				
				if(qty>=5)
				{
					printf("Your Total bill value is $%.2f.\n", 15.0 * qty);
					printf("Discount 10 - $%.2f\n", (15.0 * qty) - (15.0 * 0.9 * qty));
					printf("Final bill value is	 $%.2f\n", qty * 15.0 * 0.9);
					
					sprintf(bill+3, "%d", i+1);		//Generates receipt number and stores it in char bill from the 4th index
													//sprintf is used since to store the statement in a string format 
					
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
					
					o->b = b;								// Assigning the allocated memory to b of the Order struct
					o->finalOrder = 15.0 * 0.9 * qty;		//Storing the value recieved from the final bill to the finalOrder field in the Order struct
					strcpy(o->brec, bill);					//Copying the values in bill into the brec field in the Order structure
					recarray[i]=o;							//Assigning the memory address of Order struct "o" to the i'th index of the recarray
					i++;									//Increments the value of i by 1
				
				}
				
				else
				{
					printf("Your Total bill value is $%.2f.\n", 15.0 * qty);
					
					sprintf(bill+3, "%d", i+1);
				
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
		
					o->b = b;								
					o->finalOrder = 15.0 * qty;		
					strcpy(o->brec, bill);					
					recarray[i]=o;							
					i++;
					
				}
				
			break;
				
			case 'B' :
			
				b->pick = Ham;		
				
				printf("You have selected Ham. How many burgers would you like to order?\n");
				scanf("%f", &qty);
				fflush(stdin);
				
				if(qty>=5)
				{
					printf("Your Total bill value is $%.2f.\n", 17.0 * qty);
					printf("Discount 10 - $%.2f\n", (17.0 * qty) - (17.0 * 0.9 * qty));
					printf("Final bill value is	 $%.2f\n", qty * 17.0 * 0.9);
					
					sprintf(bill+3, "%d", i+1);
					
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
					
					o->b = b;								
					o->finalOrder = 17.0 * 0.9 * qty;		
					strcpy(o->brec, bill);					
					recarray[i]=o;							
					i++;									
				
				}
				
				else
				{
					printf("Your Total bill value is $%.2f.\n", 17.0 * qty);
					
					sprintf(bill+3, "%d", i+1);
				
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
		
					o->b = b;								
					o->finalOrder = 17.0 * qty;		
					strcpy(o->brec, bill);					
					recarray[i]=o;							
					i++;
					
				}
				
			break;
			
			case 'C' :
			
				b->pick = Vegie;		
				
				printf("You have selected Vegie. How many burgers would you like to order?\n");
				scanf("%f", &qty);
				fflush(stdin);
				
				if(qty>=5)
				{
					printf("Your Total bill value is $%.2f.\n", 13.0 * qty);
					printf("Discount 10 - $%.2f\n", (13.0 * qty) - (13.0 * 0.9 * qty));
					printf("Final bill value is	 $%.2f\n", qty * 13.0 * 0.9);
					
					sprintf(bill+3, "%d", i+1);
					
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
					
					o->b = b;								
					o->finalOrder = 13.0 * 0.9 * qty;		
					strcpy(o->brec, bill);					
					recarray[i]=o;							
					i++;									

				}
				
				else
				{
					printf("Your Total bill value is $%.2f.\n", 13.0 * qty);
					
					sprintf(bill+3, "%d", i+1);
				
					printf("Your Receipt number is %s\n",bill);
					printf("Please go to a register and make the paymeny by quoting the Receipt Number - %s\n", bill);
		
					o->b = b;								
					o->finalOrder = 13.0 * qty;		
					strcpy(o->brec, bill);					
					recarray[i]=o;							
					i++;
					
				}
				
			break;
			
			case 'X' :
			
				return;
				
			break;
		}

		printf("<<Press Any Key to show the main menu >>\n");
		return;
			
	}while(select=1);

}	

void cancelOrder()
{
	char rec[6];
	int flag = 0;
	
	printf("Enter the receipt number: \n");
    scanf("%s", rec);
	
	
	for(int j = 0; j < i; j++)						//Variable j used to access elements of recarray
	{												//The for loop is used to check whether the order that's to be cancelled is present in the recarray
		if(strcmp(recarray[j]->brec, rec) == 0)		//String comparison checks if the user input is identical order stored in recarray
		{
			flag = 1;								//If Order is present flag is set to 1 
			
			free(recarray[j]->b);					//Frees the allocated memory for "b" of the Order struct
			free(recarray[j]);						//Frees the allocated memory that was used to store recarray at index j
			
			for(int k = j; k < i -1; k++)			//Used to shift all the elements to the left starting from index j
			{
				recarray[k] = recarray[k+1];		//The memory address of the next order struct in the array is moved to the current index of the array
			}										//This is done to shift the elements in the array down by one
			
			printf("Order %s is cancelled.\n", rec);
			
			break;
		}
		
	}
	
	if(flag==0)
	{
		printf("No Order found, enter a valid receipt number \n");
	}
	
}

void TotalRevenue()
{
	char pass[15];
	float tot_revenue = 0;
	
	printf("Enter the password : ");
	scanf("%s", pass);
	
	
	if(strcmp("TastyBurger", pass) == 0)								//String comparison to check whether user input matches
	{
		for(int j = 0; j < i; j++)										//The loop iterates through all the elements in recarray
		{																//Loop continues to execute as long as j < i
			tot_revenue += recarray[j]->finalOrder;
		}
		
		printf("Total Revenue for today is : $%.2f\n", tot_revenue);
	}
	
	else
	{
		printf("Invalid Password\n");
	}
	
	printf("<<Press Any Key to show the main menu >>\n");
	
}

int main()
{
	int choice;
	
	do
	{	
		printf("Welcome to Tasty Burgers\n");
		printf("Place your order here...\n");
		printf("\t 1. Order Burger\n");
		printf("\t 2. Cancel\n");
		printf("\t 3. Exit\n");
		
		printf("Select your Option: \n");
		scanf("%d", &choice);
		
		
		switch(choice)					//Switch present to give options in the main menu
		{
			case 1 :
			
				burgerOrder();			
				
				break;
			
			case 2 :
				
		        cancelOrder();
				
				break;
				
			case 3 :
			    
			    break;
			    
			 case 9 :
			 
			    TotalRevenue();
			    
			   break;
			
		}
	
	}while(choice!=3);
	
return 0;
}
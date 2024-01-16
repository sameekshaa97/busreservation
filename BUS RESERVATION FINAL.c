#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;
void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
int main()

{
		
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|             BUS TICKET RESERVATION            |\n");
	printf("\t\t|                    SYSTEM                     |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("     BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Bus");
	printf("\n------------------------");
	printf("\n3>> Cancel booking");
	printf("\n------------------------");
	printf("\n4>> EXIT");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3: 
		    cancel();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}


void viewdetails(void)
{
	system("cls");
	printf("---------------------------------------------------------------------------------------");
	printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n1001\tGodavari Travels     \tHyderabad to Vizag    \tRs.500    \t\t9:00  AM");
	printf("\n1002\tDevit Travels        \tVizag To Hyderabad    \tRs.500  \t\t12:00 PM");
	printf("\n1003\tHero Travels         \tBenighat To Pokhara   \tRs.450   \t\t1:50  PM");
	printf("\n1004\tSuper Deluxe         \tPokhara To Benigha    \tRs.450   \t\t11:00 AM");
	printf("\n1005\tSai Baba Travels     \tShirdi To Hyderabad   \tRs.400  \t\t7:05  AM");
	printf("\n1006\tShine On Travels     \tHyderabad To Shirdi   \tRs.400   \t\t9:30  AM");
    printf("\n1007\tMayur Travels        \tJumla To Humla        \tRs.350   \t\t1:00  PM");
    printf("\n1008\tShree Travels        \tHumla To Jumla        \tRs.350   \t\t4:00  PM");
    printf("\n1009\tKathmandu Express    \tKathmandu To Pokhara  \tRs.600  \t\t5:35  PM");
    printf("\n1010\tSajha Yatayat        \tPokhara To Kathmandu  \tRs.600   \t\t4:15  PM");

}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}
	

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation confirmed\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation unsucessful!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}
float charge(int bus_num,int num_of_seats)
{

	if (bus_num==1001)
	
	{
		return(500*num_of_seats);
	}
	if (bus_num==1002)
	{
		return(500*num_of_seats);
	}
	if (bus_num==1003)
	{
		return(450*num_of_seats);
	}
	if (bus_num==1004)
	{
		return(450*num_of_seats);
	}
	if (bus_num==1005)
	{
		return(400*num_of_seats);
	}
	if (bus_num==1006)
	{
		return(400*num_of_seats);
	}
	if (bus_num==1007)
	{
		return(350*num_of_seats);
	}
	if (bus_num==1008)
	{
		return(350*num_of_seats);
	}
	if (bus_num==1009)
	{
		return(600*num_of_seats);
	}
	if (bus_num==1010)
	{
		return(600*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nbus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}


void specificbus(int bus_num)
{

	if (bus_num==1001)
	{
		printf("\nbus:\t\t\tGodavari Travels ");
		printf("\nDestination:\t\tDharan to Kavre");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==1002)
	{
		printf("\nbus:\t\t\tDevit Travels ");
		printf("\nDestination:\t\tKavre to Dharan");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==1003)
	{
		printf("\nbus:\t\t\tHero Travels ");
		printf("\nDestination:\t\tBenighat to Pokhara");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==1004)
	{
		printf("\nbus:\t\t\tSuper Deluxe ");
		printf("\nDestination:\t\tPokhara to Benighat");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==1005)
	{
		printf("\nbus:\t\t\tSai Baba Travels ");
		printf("\nDestination:\t\tMaitidevi to Janakpur");
		printf("\nDeparture:\t\t7am");
	}
	if (bus_num==1006)
	{
		printf("\nbus:\t\t\tShine On Travels ");
		printf("\nDestination:\t\tJanakpur to Maitidevi ");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (bus_num==1007)
	{
		printf("\nbus:\t\t\tMayur Travels");
		printf("\nDestination:\t\tHumla toJumla ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (bus_num==1008)
	{
		printf("\nbus:\t\t\tShree Travels ");
		printf("\n Destination:\t\tJumla to Humla");
		printf("\nDeparture:\t\t4pm ");
	}
	if (bus_num==1009)
	{
		printf("\nbus:\t\t\tKathmandu Express");
		printf("\nDestination:\t\tKathmandu to Pokhara");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (bus_num==1010)
	{
		printf("\nbus:\t\t\tSajha Yatayat");
		printf("\nDestination:\t\tPokhara to Kathmandu");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void cancel(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}
	printf("\n\nCancel Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation cancelled, refund intiated\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
	printf("cancellation unsucessful!");
    }
}

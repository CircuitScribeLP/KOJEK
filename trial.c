#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STUDENT NAME - M.L.M.PERERA
   STUDENT NUMBER - PE/2021/015
   GROUP ID -  36  */


int main()
{
	//Introduction to entering juice bar
	printf("\t\t-------------------------------------------------------------------\n\n");
	printf("\t\t\033[1;33mWELCOME TO THE JIUCE BAR AUTOMATED SYSTEM OF UNIVERSITY OF KELANIYA\033[0m\n\n");
	printf("\t\t-------------------------------------------------------------------\n\n\n\n");

	printf("\t\t\t    ----------------------------------------\n");
	printf("\t\t\t      This is the MAIN JUICE MENU we have.\n\t\t\t    You can select your choice through this\n");
	printf("\t\t\t    ----------------------------------------\n\n\n");



	//Function calling to display an array

    myFunction1();

	//enter what juice you want

	linefunction();     //This function is  at the final line
	printf("\t\tIf you want to select any juice you like\t---> \033[1;35mTHEN PRESS 1\n\n\033[0m");
	printf("\t\tIf you don't want to select any juice\t\t---> \033[1;35mTHEN PRESS 0 \033[0m\n\n\n");

	int stat;
	printf("\t\tWHAT'S YOUR CHOICE? [0/1]  ");
    printf("------------------------>\t \033[1;35m");

	scanf("%d",&stat);
	    printf("\033[0m\n");

    if(stat==0 || stat==1){
        if(stat==1)
        {
            int count,cycle;
            linefunction();
            printf("\t\tHow Many Varieties You Want?  \t\033[1;32m>>>>>>>>>>>>>>>>> \033[0m\t \033[1;32m");
            scanf("%d",&count);
                printf("\033[0m");
                //call a line
                linefunction();

            if(count<=5)
                {
                while(cycle<count)
                    {
                    cycle++;
                    //Function calling to main process
                    mainpross();
                    }
                //print the final message
                printfunc();
                }

            else{
                    printf("\t\t\t    \033[1;33m----------------------------------------\n");
                    printf("\t\t\t\t       Add a value BELOW 5\t\t\t\n");
                    printf("\t\t\t    ----------------------------------------\033[0m\n\n\n");
                //call a function to ask about the different choices
                funreturn();

                }
        }

		else
            {
                //print hashes and final message when press 0 in the begining
                hashfunction();
                printf("\n\n\n\t\t\t\t    ------> HAVE A NICE DAY <-----\n\n\n\n");
            }
    }
    else
    {
        printf("\n\t\tYOU HAVE ONLY ONE CHANCE TO ENTER THE CORRECT DIGIT AMONG FROM 1 OR 0\n\n\n");
        begfunction();
    }



	return 1;
  }


//This function is to get information about details of juices.
//In here, quantity of juices are get as a string value and it's convert to the integer values

void myFunction1()
{
    FILE*fruit_file;
	char fruit[20][20];
	char qty[20][10];
	int j = 0;
	int l = 0;
	int n = 0;
	int number = 0;
	int int_qty[20];

	fruit_file=fopen("product.txt", "r");
	if(fruit_file==NULL)
	{
		printf("Failed to open product.txt\n");
		return 1;
	}
    while(fscanf(fruit_file,"%s",fruit[j])!= EOF)
    {
        j++;
        number++;
    }
    for(int k=0; k<number; k++)
    {
        if(k%2==0)
        {
            strcpy(fruit[n], fruit[k]);
            n++;
        }
        else
        {
            strcpy(qty[l], fruit[k]);
            l++;
        }
    }

    for(int i = 0; i<n; i++)
    {
        // Convert the string quantity to an int quantity.
        int_qty[i]=atoi(qty[i]);
    }

    for(int i = 0; i < n; i++)
    {
       printf("\t\t\t\t    %s\t--> ", fruit[i]);
       printf("\t%d\n", int_qty[i]);
    }


    fclose(fruit_file);
    return 1;

}

//Get inputs as digits and print outputs as what got

void mainpross(){
    //get the juice number to identify the juice

            int quantity=0;
            int keyword;
            printf("\n\n\t\t***********************************************************\n");
            printf("\t\t*\t");
            printf("ENTER WHAT JUICE YOU WANT USING THIER DIGIT\t");
            printf("  *\n");
            printf("\t\t***********************************************************\n\n");
            printf("\t\t\t\tDIGIT PLEASE \033[1;34m>>>>>\033[0m\t");

            scanf("%d",&keyword);
                switch(keyword){

                    //ask the quantity what client want
                    case 1:
                        printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
                        scanf(" %d",&quantity);
                        printf("\n\t\t\t\t---------------------------\n");
                        printf("\t\t\t\tYou got selected %d MANGO(S)\n",quantity);
                        printf("\t\t\t\t---------------------------\n");
                        linefunction();
                        break;
                    case 2:
                        printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
                        scanf("%d",&quantity);
                        printf("\n\t\t\t\t----------------------------\n");
                        printf("\t\t\t\tYou got selected %d ORANGE(S)\n",quantity);
                        printf("\t\t\t\t----------------------------\n");
                        //print a horizontal line
                        linefunction();
                        break;
                    case 3:
                        printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
                        scanf("%d",&quantity);
                        printf("\n\t\t\t\t-----------------------------\n");
                        printf("\t\t\t\tYou got selected %d AVACADO(S)\n",quantity);
                        printf("\t\t\t\t-----------------------------\n");
                        //print a horizontal line
                        linefunction();
                        break;
                    case 4:
                        printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
                        scanf("%d",&quantity);
                        printf("\n\t\t\t\t---------------------------\n");
                        printf("\t\t\t\tYou got selected %d APPLE(S)\n",quantity);
                        printf("\t\t\t\t---------------------------\n");
                        //print a horizontal line
                        linefunction();
                        break;
                    case 5:
                        printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
                        scanf("%d",&quantity);
                        printf("\n\t\t\t\t---------------------------\n");
                        printf("\t\t\t\tYou got selected %d GUVAVA(S)\n",quantity);
                        printf("\t\t\t\t---------------------------\n");
                        //print a horizontal line
                        linefunction();
                        break;
                    default:
                        printf("\n\033[1;34mPlease Enter a VALID DIGIT >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
                        //Get inputs as digits and print outputs as what got when the digits wrong
                        mainpross();
                        break;}
                return 1;}


//ask about the different choices
void funreturn(){
int count,cycle;
printf("\t\tHow Many Varieties You Want?  \t\033[1;32m>>>>>>>>>>>>>>>>> \033[0m\t \033[1;32m");
scanf("%d",&count);
    printf("\033[0m");
    linefunction();
if(count<=5)
    {
    while(cycle<count)
        {
        cycle++;
        //Function calling to main process
        mainpross();
        }
    //print the final message
    printfunc();
    }
else{printf("\033[1;31mSORRY!! ---> You can't go ahead\033[0m\n");
}
}


//Final message to print
void printfunc(){
hashfunction();
printf("\n\n\t\t\t\033[1;31m________________________________________________\033[0m\n");
printf("\n\n\n\t\t\t-->\t\033[1;31m  YOUR ORDER HAS BEEN PLACED\033[0m\t   <--\n");
printf("\n\t\t\t\t   ------------------------\n");
printf("\t\t\t\t   \033[1;34mYour ORDER NUMBER is \033[0m---\n");
printf("\t\t\t\t   ------------------------\n\n");
printf("\t\t\t     * PLEASE WAIT! IT WILL TAKE A WHILE *\n\n\n\n");
printf("\t\t\t\033[1;31m________________________________________________\033[0m\n\n\n");}


//
void begfunction(){
int stat;
printf("\t\tWHAT'S YOUR CHOICE? [0/1]  ");
printf("------------------------>\t \033[1;35m");

scanf("%d",&stat);
printf("\033[0m\n");

if(stat==1)
    {
    int count,cycle;
    linefunction();
    printf("\t\tHow Many Varieties You Want?  \t\033[1;32m>>>>>>>>>>>>>>>>> \033[0m\t \033[1;32m");
    scanf("%d",&count);
    printf("\033[0m");
    //call a line
    linefunction();

    if(count<=5)
        {
        while(cycle<count)
            {
            cycle++;
            //Function calling to main process
            mainpross();
            }
            //print the final message
            printfunc();
            }

    else{
        printf("\t\t\t    \033[1;33m----------------------------------------\n");
        printf("\t\t\t\t       Add a value BELOW 5\t\t\t\n");
        printf("\t\t\t    ----------------------------------------\033[0m\n\n\n");
        //call a function to ask about the different choices
        funreturn();

        }
    }

    else
        {
        //print hashes and final message when press 0 in the begining
        hashfunction();
        printf("\n\n\n\t\t\t\t    ------> HAVE A NICE DAY <-----\n\n\n\n");
        } }



//print a horizontal line
void linefunction(){
printf("\n\033[1;31m_______________________________________________________________________________________________________\033[0m\n\n\n");
}


//print hashes
void hashfunction(){
printf("\n\n\033[1;23m#######################################################################################################\033[0m\n\n");
}

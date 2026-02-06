/*Student Name :O.W.P.Madushan | M.L.M.Perera | M.K.N.M. Sandaruwan
Student No: PE/2021/014 | PE/2021/015 | PE/2021/005
Group No: 36*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void start();
void body();
void timer(int totalWT);
int main()
{

    start();
    body();
}


void start()
{
	//Introduction to entering juice bar
	printf("\t\t-------------------------------------------------------------------\n\n");
	printf("\t\t\033[1;33mWELCOME TO THE JIUCE BAR AUTOMATED SYSTEM OF UNIVERSITY OF KELANIYA\033[0m\n\n");
	printf("\t\t-------------------------------------------------------------------\n\n\n\n");

	printf("\t\t\t    ----------------------------------------\n");
	printf("\t\t\t      This is the MAIN JUICE MENU we have.\n\t\t\t    You can select your choice through this\n");
	printf("\t\t\t    ----------------------------------------\n\n\n");

}


void body()
{
    FILE *fruit_file;
    int totalWT=0;
    FILE *order_file;
    char fruit[20][20];
    char qty[20][10];
    char fruit_o[20][20]; // New array to store ordered items
    char qty_o[20][10];   // New array to store ordered quantities
    int j = 0;
    int l = 0;
    int m = 0;
    int n_menu = 0;  // Separate index for menu items
    int n_order = 0; // Separate index for ordered items
    int no = 1;
    int number = 0;
    int int_qty[20];
    int int_qty_o[20]; // New array to store ordered quantities

    fruit_file = fopen("product.txt", "r"); // Open the menu file in read mode

    if (fruit_file == NULL)
    {
        printf("Failed to open fruits.txt\n");

    }

    while (fscanf(fruit_file, "%s", fruit[j]) != EOF)
    {
        j++;
        number++;
    }

    for (int k = 0; k < number; k++)
    {
        if (k % 2 == 0)
        {
            strcpy(fruit[n_menu], fruit[k]);
            n_menu++;
        }
        else
        {
            strcpy(qty[l], fruit[k]);
            l++;
        }
    }

    // Convert the string quantity to an int quantity for menu items
    for (int i = 0; i < n_menu; i++)
    {
        int_qty[i] = atoi(qty[i]);
    }

    // Print Menu
    printf("\n\t\t\t\t   No\tDrinks\t\tQuantity\n\n");
    for (int i = 0; i < n_menu; i++)
    {
        printf("\t\t\t\t   %d\t%s\t\t   %d\n", no, fruit[i], int_qty[i]);
        no = no + 1;
    }
    linefunction();
    int p = 1;

    // Open "order.txt" in write mode to clear its contents
    order_file = fopen("order.txt", "w");

    if (order_file == NULL)
    {
        printf("Failed to open order.txt\n");

    }

    for (int i = 0; i < p; i++)
    {
        int choice = 0;
        printf("\t\t*********************************************************************\n");
        printf("\t\t*     \033[33mSELECT THE JUICE YOU WANT BY ENTERING THE RELEVANT NUMBER\033[0m     *\n");
        printf("\t\t*********************************************************************\n");
        printf("\t\t\t\tDIGIT PLEASE \033[1;34m    >>>>>>>>>\033[0m\t");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= n_menu)
        {
            int elementCount;
            printf("\n\t\tENTER THE QUANTITY YOU WANT\t\033[1;34m>>>>>>>>>>>>>>>>>\033[0m\t ");
            scanf("%d", &elementCount);
            fprintf(order_file, "%s %d\n", fruit[choice - 1], elementCount);

            // Subtract the selected quantity from menu items
            int_qty[choice - 1] -= elementCount;

            // Update the qty string with the new quantity (convert int back to string)
            sprintf(qty[choice - 1], "%d", int_qty[choice - 1]);

            // Print the updated menu
            fruit_file = fopen("product.txt", "w");
            // fprintf(fruit_file,"No\tDrinks\t\tQuantity\n");
            for (int i = 0; i < n_menu; i++)
            {
                fprintf(fruit_file, "%s %s\n", fruit[i], qty[i]);
            }
linefunction();
totalWT = totalWT+5;
        printf("\n\033[34m.......................................*************************.......................................\033[0m\n");
        printf("\n\t\t\033[33m.................ORDER MORE OR PLACE YOUR ODER BY PRESSING [0].............\033[0m\n");
        printf("\n\033[34m.......................................*************************.......................................\033[0m\n\n\n");
        linefunction();
            p = p + 1;
        }
        else
        {
            if (choice == 0)
            {linefunction();
                printf("\n\033[32m.......................................*************************.......................................\033[0m\n");
                printf("\n\t\t\033[33m\t...................HERE IS YOUR BILL..................\t\t\033[0m\n");
                fclose(order_file);                   // Close the order file before reopening it for reading
                order_file = fopen("order.txt", "r"); // Open the order file in read mode
                int number1 = 0;
                m = 0;
                l = 0;

                if (order_file == NULL)
                {
                    printf("Failed to open orders.txt\n");

                }

                while (fscanf(order_file, "%s", fruit_o[m]) != EOF)
                {
                    m++;
                    number1++;
                }

                for (int k = 0; k < number1; k++)
                {
                    if (k % 2 == 0)
                    {
                        strcpy(fruit_o[n_order], fruit_o[k]);
                        n_order++;
                    }
                    else
                    {
                        strcpy(qty_o[l], fruit_o[k]);
                        l++;
                    }
                }

                // Convert the string quantity to an int quantity for ordered items
                for (int i = 0; i < n_order; i++)
                {
                    int_qty_o[i] = atoi(qty_o[i]);
                }

                no = 1;
                printf("\n\t\t\t\tNo\tDrinks\t\tOrdered Quantity\n");
                printf("\t\t\033[33m\t______________________________________________________\t\t\033[0m\n");

                for (int i = 0; i < n_order; i++)
                {
                    printf("\n\t\t\t\t%d\t%s\t\t     %d\n", no, fruit_o[i], int_qty_o[i]);
                    no = no + 1;
                }
                printf("\n\033[32m.......................................*************************.......................................\033[0m\n\n\n");
                hashfunction();

                timer(totalWT);
                printfunc();

		hashfunction();

		printf("\n\n\033[34m..............................................UPDATED MENU.............................................\033[0m\n\n");
                printf("\n\t\t\t        No\tDrinks\t\tQuantity\n");
                no = 1;
                for (int i = 0; i < n_menu; i++)
                {
                    printf("\t\t\t         %d\t%s\t\t   %d\n", no, fruit[i], int_qty[i]);
                    no = no + 1;
                }
            }
            else
            {
                printf("Invalid Choice. try again!!\n");
                body();
            }
        }
    }

    fclose(fruit_file);
    fclose(order_file); // Close the order file


}

void timer(int totalWT)
{


    printf("\n\n\t\t\t.................PREPARING YOUR ORDER..................\n");
    printf("\t\t\033[34m\t______________________________________________________\t\t\033[0m\n\n");
    printf("\t\t\t                      PLEASE WAIT                 \n");
    printf("\t\t\033[34m\t______________________________________________________\t\t\033[0m\n\n");
    hashfunction();
  // Calculation of waiting time.
    sleep(totalWT);


    printf("			    \t\t\t  +\n			  \t\t\t+ + + \n			\t\t      + + + + +\n\n   \t\t\t.*.*.*.*.*.*.*.*.  ORDER COMPLETED  .*.*.*.*.*.*.*.*.\n\n		\t\t\t      + + + + +\n			  \t\t\t+ + + \n			    \t\t\t  +\n");

}




//print a horizontal line
void linefunction(){
printf("\n\033[1;31m_______________________________________________________________________________________________________\033[0m\n\n\n");
}


//print hashes
void hashfunction(){
printf("\n\n\033[1;23m#######################################################################################################\033[0m\n\n");
}

//ENTER WHAT JUICE YOU WANT USING THIER DIGIT
void printcom(){
printf("\n\n\t\t***********************************************************\n");
printf("\t\t*\t");
printf("ENTER WHAT JUICE YOU WANT USING THIER DIGIT\t");
printf("  *\n");
printf("\t\t***********************************************************\n\n");
printf("\t\t\t\tDIGIT PLEASE \033[1;34m>>>>>\033[0m\t");}

//Final message to print
void printfunc(){
hashfunction();
printf("\n\n\t\t\t\033[1;31m________________________________________________\033[0m\n");
printf("\n\n\n\t\t\t-->\t\033[1;31m  YOUR ORDER HAS BEEN TAKEN\033[0m\t   <--\n");
printf("\n\t\t\t\t   ------------------------\n");
printf("\t\t\t\t   \033[1;34m     HAVE A NICE DAY\033[0m\n");
printf("\t\t\t\t   ------------------------\n\n");
printf("\t\t\t     * THIS PROJECT IS CALLED KOJEC!!! *\n\n\n\n");
printf("\t\t\t\033[1;31m________________________________________________\033[0m\n\n\n");}

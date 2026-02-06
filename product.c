//Student Name :O.W.P.Madushan
//Student No: PE/2021/014
//Group No: 36

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void start();
void body();
int main()
{

    start();
    body();
}


void start()
{
    // Print Title with color
    printf("\n\n\t\t\033[34m................................................*************************...............................................\033[0m\n");
    printf("\n\t\t\t\t\t\t\033[33m.................UNIVERSITY JUICE BAR.............\033[0m\n");
    printf("\n\t\t\033[34m................................................*************************...............................................\033[0m\n");

    // Print Menu
    printf("\n\n\n\t\t\t\t\t\t\t\033[33m..............***MENU***...........\033[0m\n");
}


void body()
{
    FILE *fruit_file;
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
    printf("\n\t\t\t\t\t\t\t   No\tDrinks\t\tQuantity\n\n");
    for (int i = 0; i < n_menu; i++)
    {
        printf("\t\t\t\t\t\t\t   %d\t%s\t\t   %d\n", no, fruit[i], int_qty[i]);
        no = no + 1;
    }

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

        printf("\n\n\n\t\t\033[33mSelect the juice you want by entering the relevant number ------>\033[0m ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= n_menu)
        {
            int elementCount;
            printf("\n\t\t\033[33mEnter the quantity required ------>\033[0m ");
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

	printf("\n\n\t\t\033[34m................................................*************************...............................................\033[0m\n");
        printf("\n\t\t\t\t\t\t\033[33m.................ODER MORE OR PLACE YOUR ODER PRESSING [0].............\033[0m\n");
        printf("\n\t\t\033[34m................................................*************************...............................................\033[0m\n");
            p = p + 1;
        }
        else
        {
            if (choice == 0)
            {
		printf("\n\n\t\t\033[34m................................................*************************...............................................\033[0m");
       	 	printf("\n\t\t\t\t\t\t\033[33m.................YOUR BILL.............\033[0m\n");
        	printf("\t\t\033[34m................................................*************************...............................................\033[0m\n");
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
                printf("\n\t\tNo\tDrinks\t\tOrdered Quantity\n");
                for (int i = 0; i < n_order; i++)
                {
                    printf("\n\t\t%d\t%s\t\t     %d\n", no, fruit_o[i], int_qty_o[i]);
                    no = no + 1;
                }
		printf("\n\n\t\t\033[34m................................................*************************...............................................\033[0m\n");
                printf("\t\t\t\t\t\t\t   \033[33mOrder placed successfully\n\t\t\t\t\t\t\t   Thank you, come again!!.\033[0m\n");

		printf("\t\t\033[34m................................................*************************...............................................\033[0m\n\n\n");

		printf("\n\n\t\t\033[34m................................................UPDATED MENU...............................................\033[0m\n\n");
                printf("\n\t\t\t\t\t\t\t   No\tDrinks\t\tQuantity\n");
                no = 1;
                for (int i = 0; i < n_menu; i++)
                {
                    printf("\t\t\t\t\t\t\t   %d\t%s\t\t   %d\n", no, fruit[i], int_qty[i]);
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

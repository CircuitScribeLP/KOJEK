//PE/2021/005 , //M.K.N.M.Sandaruwan , Group ID - 36

#include <stdio.h>
#include <unistd.h>  // sleep function.



//THIS CODE IS TO HELP US TO ORDER TRACKING
int main()
{
    int drinkCodes[5] = {1, 2, 3, 4, 5};  // Input the drink code into the array.
    int numDrinks;

    	 printf("Enter the number of drinks you want to order:(MAX 05 oder)  ");
   	 scanf("%d", &numDrinks);

    if (numDrinks <= 0 || numDrinks > 5)
	{
        printf("Invalid number of drinks\n"); // Input Invalid number of drinks.
        return 1;   //input error code.
    	}

    int totalWT = 0;
    int count = 0;

    printf("Enter the drink codes \n Mango drink   = 01\n Orange drink  = 02\n Avacado drink = 03\n Apple drink   = 04\n Guava drink   = 05\n");

    while (count < numDrinks)
	{
        int drinkCode;
        printf("Enter drink code %d: ", count + 1);  // Add to drink code.
        scanf("%d", &drinkCode);

        if (drinkCode < 1 || drinkCode > 5) {
            printf("Invalid drink code: %d\n", drinkCode);
            continue;  // add to invalid input and continue the programe.
        }

        totalWT += drinkCodes[drinkCode - 1]; // Subtract 1 to map to array pointer.
        count = count + 1;
    	}

    printf(".................Preparing the drink(s)..................\n       ...............please wait ...............\n");
  // Calculation of waiting time.
    sleep(totalWT);


    printf("			    +\n			  + + + \n			+ + + + +\n   .*.*.*.*.*.*.*.*  ODER COMPLETE  .*.*.*.*.*.*.*.*\n			+ + + + + \n			  + + + \n			    +\n");

    return 0;
}

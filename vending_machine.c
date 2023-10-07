#include <stdio.h>
int main()
{
    int menu, purchase, admin, exit, password;
    while (1){
    printf("Hi! Welcome to the UOWD Vending Machine! \n\n What would you like to do? \n");
    printf("1. Purchase Item for the customer \n");
    printf("2. Admin mode for the Vending machine operator \n");
    printf("3. Exit \n\n");
    printf("Select an option:  ");
    scanf("%d",&menu);

     switch (menu) {
            case 1:
                while (1) { 
                    // Purchasing item
                    printf("\nHere are the products available: \n");
                    printf("1. A for AED 3.25 \n");
                    printf("2. B for AED 2 \n");
                    printf("3. C for 4.5 \n\n");
                    
                    printf("Enter your product of choice: ");
                    scanf("%d", &purchase);

                    printf("\nYou have selected option %d\n ", purchase);
                    printf("If correct, enter 'y' to continue. If incorrect, enter 0 to cancel purchase - \n");
                    scanf("%c%d", &purchase);

                    if(purchase==0)
                    printf("Purchase Cancelled.");
                    return purchase;


/*
                    switch (subChoice) {
                        case 1:
                            printf("You selected Sub-Option 1.\n");
                            break;
                        case 2:
                            printf("You selected Sub-Option 2.\n");
                            break;
                        case 3:
                            printf("Returning to Main Menu.\n");
                            break;
                        default:
                            printf(" \n");
                    }

                    if (subChoice == 3) {
                        break; // Exit the sub-menu loop and return to the main menu
                    }
                }
                break;
             switch () 
             */  
            case 2: // Admin mode
                while (1) { 
                    printf("Welcome to the Admin Mode! \n");
                    printf("Please enter the password: \n");
                    scanf("%d",admin);

                if (password==2020)
                    printf("What would you like to do: \n");
                    printf("1. Replenish items \n");
                    printf("2. Change item prices \n");
                    printf("3. Display total sale \n");
                    printf("4. Display item availability\n");
                    printf("0. Exit admin mode \n");

                    printf("Select option: ");
                    scanf("%d", &admin);
                else if
                    printf("Password incorrect. Please try again.");
                   scanf("%d",&admin);
                else
                   printf("Password incorrect. Exiting ADMIN MODE."); break;

            default:
                printf("Thank you! \n");
        }
    }

    return 0;

}
}
}
}

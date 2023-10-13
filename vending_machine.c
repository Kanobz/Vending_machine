#include <stdio.h>
int main()
{
    int menu, purchase, A, B, C, amount_paid, coin_options, admin, exit, password;
    while (1){
    printf("\nHi! Welcome to the UOWD Vending Machine! \n\nWhat would you like to do? \n");
    printf("1. Purchase Item for the customer \n");
    printf("2. Admin mode for the Vending machine operator \n");
    printf("3. Exit \n\n");
    printf("Select an option: ");
    scanf("%d",&menu);

     switch (menu) {
            case 1:
                while (1) { 
                    // Purchasing item
                    A = 3.25, B =2.0, C = 4.5, amount_paid = 0, coin_options = [1, 0.25, 0.5];
                    printf("\nHere are the products availableand their quantities: \n");
                    printf("1. A for AED 3.25 (8)\n");
                    printf("2. B for AED 2.0 (3)\n");
                    printf("3. C for 4.5 (5)\n\n");
                    
                    printf("Enter your product of choice: ");
                    scanf("%d", &purchase);

                    printf("\nYou have selected option %d which costs AED %.2f\n", purchase);
                    scanf("%d%f", &purchase);
                    printf("If correct, enter 'y' to continue. If incorrect, enter 0 to cancel purchase - ");
                    scanf("%c%d", &purchase);
                    
                    if(purchase!=0){
                        while (amount_paid < A || B || C){
                           printf("\nPay for the item by inserting one of these 3 coins: AED 1, AED 0.5, AED 0.25");
                           scanf("%f",&coin_options);
                     
                           if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5 ||){
                              amount_paid += coin_options;
                              printf("Total amount paid: AED %.2f\n", amount_paid);}
                             else 
                             printf("Invalide coin. Please insert a valid coin.");
                           }
                          printf("Thank you! Here is your item.\n"); 

                          return 0;
                                   }
                    else
                    printf("Purchase Cancelled.");
                    return menu; break;
            case 2: // Admin mode
                while (1) { 
                    printf("Welcome to the Admin Mode! \n");
                    printf("Please enter the password: \n");
                    scanf("%d",password);

                if (password==2020){
                    printf("What would you like to do: \n");
                    printf("1. Replenish items \n");
                    printf("2. Change item prices \n");
                    printf("3. Display total sale \n");
                    printf("4. Display item availability\n");
                    printf("0. Exit admin mode \n");

                    printf("Select option: ");
                    scanf("%d", &admin);
                    
                    switch (admin){
                        case 1: //Replenish items
                            printf("You selected Sub-Option 1.\n");
                            break;
                        case 2: //Change item prices
                            printf("You selected Sub-Option 2.\n");
                            break;
                        case 3: //Display total sales
                            printf("Returning to Main Menu.\n");
                            break;
                        case 4: //Display item availability    
                        default:
                            printf("Exit Admin mode\n");     
                    }
                  else if {
                    printf("Password incorrect. Please try again."); break;
                    scanf("%d",&password);}
                else{
                    printf("Password incorrect. Exiting ADMIN MODE.");} break;

            default:
                printf("Thank you! \n");
        }
    }

    return 0;

   }
  }
 }
}

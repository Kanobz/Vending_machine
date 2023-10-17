#include <stdio.h>

int main() {
  int menu, purchase, admin, password, min;
  float A = 3.25, B = 2.0, C = 4.5, amount_paid = 0, change = 0;
  while (1) {
    printf("\nHi! Welcome to the UOWD Vending Machine! \n\nWhat would you like to do? \n");
    printf("1. Purchase Item for the customer \n");
    printf("2. Admin mode for the Vending machine operator \n");
    printf("3. Exit \n\n");
    printf("Select an option: ");
    scanf(" %d", &menu);

    switch (menu) {
    case 1:
      while (1) {
        // Purchasing item
        float coin_options;;
        printf("\nHere are the products availableand their quantities: \n");
        printf("1. A for AED 3.25 (8)\n");
        printf("2. B for AED 2.00 (3)\n");
        printf("3. C for 4.50 (5)\n\n");

        printf("Enter your product of choice: ");
        scanf("%d", &purchase);

        printf("\nYou have selected option %d which costs AED %.2f\n", purchase);

        printf("If correct, enter 'y' to continue. If incorrect, enter 0 to cancel purchase - ");
        scanf(" %c", &purchase);

        if (purchase = 1) {
          printf("You have selected option A for AED 3.25\n");
          while (amount_paid < 3.25) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", & coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 3.25;
              printf("Amount paid: AED %.2f\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n", change);
              }
            } else {
              printf("Invalid coin. Please insert a valid coin.\n");
            }
          }
          printf("Thank you for your purchase! Here is your item.\n");
        } else if (purchase = 2) {
          printf("You have selected option B for AED 2.0\n");
          while (amount_paid < 2.0) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", & coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 2.0;
              printf("Amount paid: AED %.2f\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n", change);
              }
            } else {
              printf("Invalid coin. Please insert a valid coin.\n");
            }
          }
          printf("Thank you for your purchase! Here is your item.\n");
        } else if (purchase = 3) {
          printf("You have selected option C for AED 4.5\n");
          while (amount_paid < 4.5) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", & coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 4.5;
              printf("Amount paid: AED %.2f\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n", change);
              }
            } else {
              printf("Invalid coin. Please insert a valid coin.\n");
            }
          }
          printf("Thank you for your purchase! Here is your item.\n");
        } else {
          printf("Purchase Cancelled.\n");
        }
      }
      break;

    case 2: // Admin mode
      while (1) {
        printf("Welcome to the Admin Mode! \n");
        printf("Please enter the password: \n");
        scanf("%d", & password);

        if (password == 2020) {
          printf("What would you like to do: \n");
          printf("1. Replenish items \n");
          printf("2. Change item prices \n");
          printf("3. Display total sale \n");
          printf("4. Display item availability\n");
          printf("0. Exit admin mode \n");

          printf("Select option: ");
          scanf("%d", & admin);

          switch (admin) {
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
        } else {
          printf("Password incorrect. Please try again.");
          scanf("%d", & password);
        }
      }

      break;

    default:
      printf("Thank you! \n");
      break;
    }
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 5

int main() {
  srand(time(NULL));

  int A = 8, B = 3, C = 5, menu, purchase, admin, password, min;
  float amount_paid = 0, change = 0, total_amount, new_price;
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
        printf("\nHere are the products available and their quantities: \n");
        printf("1. A for AED 3.25 (8)\n");
        printf("2. B for AED 2.00 (3)\n");
        printf("3. C for 4.50 (5)\n\n");

        printf("Enter your product of choice: ");
        scanf(" %d", &purchase);

        printf("\nYou have selected option %d\n\n", purchase);

        printf("If correct, enter 'y' to continue. If incorrect, enter 0 to cancel purchase - ");
        scanf(" %c", &menu);

        if (purchase = 1) {
          A = A-1;
          printf("\nYou have selected option A for AED 3.25\n\n");
          while (amount_paid < 3.25) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", &coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 3.25;
              printf("Amount paid: AED %.2f\n\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n\n", change);
                if (A < MIN) {
                  printf("The quantity of A is less than the minimum amount.\n", admin);
                }
              }
            } else {
              printf("Invalid coin. Please insert a valid coin.\n");
            }
          }
          printf("\nThank you for your purchase! Here is your item.\n");
          break;
          return menu;
        } else if (purchase = 2) {
          B = B-1;
          printf("You have selected option B for AED 2.0\n");
          while (amount_paid < 2.0) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", &coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 2.0;
              printf("Amount paid: AED %.2f\n\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n\n", change);
                if (B < MIN) {
                  printf("The quantity of B is less than the minimum amount.\n", admin);
                }
              }
            } else {
              printf("Invalid coin. Please insert a valid coin.\n");
            }
          }
          printf("Thank you for your purchase! Here is your item.\n");
          break;
          return menu;
        } else if (purchase = 3) {
          C = C-1;
          printf("You have selected option C for AED 4.5\n");
          while (amount_paid < 4.5) {
            printf("Please insert one of the following coin options to make the payment (1, 0.25, 0.5): ");
            scanf("%f", &coin_options);
            if (coin_options == 1 || coin_options == 0.25 || coin_options == 0.5) {
              amount_paid += coin_options;
              change = amount_paid - 4.5;
              printf("Amount paid: AED %.2f\n\n", amount_paid);
              if (change > 0) {
                printf("Your change is AED %.2f\n\n", change);
                if (C < MIN) {
                  printf("The quantity of C is less than the minimum amount.\n", admin);
                }
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
      return menu;

    case 2: // Admin mode
      while (1) {
        printf("\nWelcome to the Admin Mode! ");
        printf("\n\nPlease enter the password: ");
        scanf("%d", &password);

        if (password == 2020) {
          total_amount = amount_paid;
          printf("\n\nWhat would you like to do: \n");
          printf("1. Replenish items \n");
          printf("2. Change item prices \n");
          printf("3. Display total sales \n");
          printf("4. Display item availability\n");
          printf("0. Exit admin mode \n\n");

          printf("Select option: ");
          scanf("%d", &admin);

          if (admin == 1) { //Replenish items
            printf("You selected Option 1 which is to - Replenish items\n");
            
            printf("These are the initial quantities of the products.\n");
            printf("A: 8\n", A);
            printf("B: 3\n", B);
            printf("C: 5\n\n", C);
            A = 1 + rand() % 20;
            B = 1 + rand() % 20;
            C = 1 + rand() % 20;
            printf("Here are the new quantities for the products:\n");
            printf("A: %d\n", A);
            printf("B: %d\n", B);
            printf("C: %d\n\n", C);
          } else if (admin == 2) { //Change item prices
            printf("You selected Option 2 which is to - Change price items\n");
            printf("\nHere are the products available and their prices: \n");
            printf("1. A for AED 3.25 \n");
            printf("2. B for AED 2.00 \n");
            printf("3. C for 4.50 \n\n");

            printf("Select option whose price you would like to update: ");
            scanf("%d", &admin);
            printf("Enter the new price for selected item: ");
            scanf("%.2f", &new_price);
            printf("This item now costs AED %.2f\n", new_price);

          } else if (admin == 3) { //Display total sales
            total_amount = amount_paid - change;
            printf("The total sales amount is AED %.2f\n\n", total_amount);
            printf("Would you like to reset it to zero?(y/n)- ");
            scanf(" %c", &admin);

            if (admin == 'y') {
              total_amount -= total_amount;
              printf("Total amount successfully reset to AED %.2f \n\n", total_amount);
              printf("Please collect money from the machine!");
            } else {
              printf("\nReset denied.\n");
            }
          } else if (admin == 4) { //Display item availability 
            printf("Here are the items on sale along with quantities available:\n");
            printf("A: 8\n", A);
            printf("B: 3\n", B);
            printf("C: 5\n\n", C);
          } else
            printf("Exiting Admin Mode.\n\n");
          printf("\nTHANK YOU!\n\n");
        } else {
          printf("Password incorrect. Please try again.");
          scanf("%d", &password);
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
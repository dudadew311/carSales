//
//  main.c
//  carSales
//
//  Created by Raul Diaz on 9/3/15.
//  Copyright (c) 2015 Raul Diaz. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>

#define SIZE 50000

void displayMenu ();
double firstTimeBuyer (double);
double getSalesPrice (double);
double lastDayDiscount (double);
double revenue (double);
double studentDiscount (double);
double veteranDiscount (double);

int main(int argc, const char * argv[]) {
	int selection = 0 ;
	double salesPrice = 0, stickerPrice = 0, cumilativeTotal = 0, history[SIZE] = {0};
	int index = 0;
	
	do{
		displayMenu();
		scanf("%i", &selection);
		
		switch (selection) {
			case 1:
				printf("What is the sticker Price? ");
				scanf("%lf", &stickerPrice);
				
				salesPrice = getSalesPrice(stickerPrice);
				history[index++]= salesPrice;
				cumilativeTotal += salesPrice;
				printf("\nThe sales price is = %.2lf\n", salesPrice);
				break;
			case 2:
				printf("The number of cars sold is: %i\n", index);
				break;
			case 3:
				printf("The average price of cars sold is: %.2lf\n", cumilativeTotal/index);
				break;
			case 4:
				printf("The Dealer has made $%.2lf\n", revenue(cumilativeTotal));
				break;
			case 5:
				break;
			default:
				printf("Error, that is not a valid selection\n\n");
		}
	} while (selection != 5);
    return 0;
}

void displayMenu (){
	printf("Menu\n\n");
	printf("1. New Sale\n");
	printf("2. Total Cars sold\n");
	printf("3. Average car Sold Price\n");
	printf("4. Total Revenue Collected\n");
	printf("5. EXIT Program\n\n");
	printf("Make a Selection: ");
}

double firstTimeBuyer (double price){
	return price - 500;
}

double getSalesPrice (double stickerPrice){
	double result = 0;
	int firstTimeBuyerFlag = 0;
	char answer;
	
	do {
		printf("Is this the last day of the Month? ");
		scanf(" %ch", &answer);
		switch (answer) {
			case 'Y':
			case 'y':
				result = stickerPrice - lastDayDiscount(stickerPrice);				
				answer = 0;
				break;
			case 'N':
			case 'n':
				result = stickerPrice;
				answer = 0;
				break;
			default:
				printf("Not a valid answer!!\n");
		}
	} while (answer != 0);
	do {
		printf("Is this your first car ever? ");
		scanf(" %ch", &answer);
		switch (answer) {
			case 'Y':
			case 'y':
				firstTimeBuyerFlag = 1;
				result = firstTimeBuyer(result);
				answer = 0;
				break;
			case 'N':
			case 'n':
				firstTimeBuyerFlag = 0;
				answer = 0;
				break;
			default:
				printf("Not a valid answer!!\n");
		}
	} while (answer != 0);
	do {
		printf("Are you a student? ");
		scanf(" %ch", &answer);
		switch (answer) {
			case 'Y':
			case 'y':
				result = studentDiscount(result);
				if (firstTimeBuyerFlag == 1) {
					result -= 500;
				}
				answer = 0;
				break;
			case 'N':
			case 'n':
				answer = 0;
				break;
			default:
				printf("Not a valid answer!!\n");
		}
	} while (answer != 0);
	do {
		printf("Are you a veteran? ");
		scanf(" %ch", &answer);
		switch (answer) {
			case 'Y':
			case 'y':
				result -= veteranDiscount(result);
				
				answer = 0;
				break;
			case 'N':
			case 'n':
				answer = 0;
				break;
			default:
				printf("Not a valid answer!!\n");
		}
	} while (answer != 0);

	return result;
}

double lastDayDiscount (double price){
	return price * .05;
}

double revenue ( double price ){
	return price * .05;
}

double studentDiscount (double price){
	return price -700;
}

double veteranDiscount (double price){
	return price * .01;
}

/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: n892s973
 *      Name: Sales Report Description
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* ptr;

    ptr = fopen("input.txt", "r");

    /*
    if(NULL == ptr)
    {
    	printf("File is unable to be opened \n");
    	return 0;
    }
    */

    /*
    double january = fgetc(ptr);
    double february = fgetc(ptr);
    double march = fgetc(ptr);
    double april = fgetc(ptr);
    double may = fgetc(ptr);
    double june = fgetc(ptr);
    double july = fgetc(ptr);
    double august = fgetc(ptr);
    double september = fgetc(ptr);
    double october = fgetc(ptr);
    double november = fgetc(ptr);
    double december = fgetc(ptr);
    */
	char* months[] = { "January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"October",
			"November",
			"December"};
	double costs[12];
	ptr = fopen("input.txt", "r");
	for(int i=0; i<12; i++)
	{
			fscanf(ptr,"%lf",&costs[i]);
	}

/*
    double january;
    double february;
    double march;
    double april;
	double may;
	double june;
	double july;
	double august;
	double september;
	double october;
	double november;
	double december;



	fscanf(ptr, "%lf", &january);
	fscanf(ptr, "%lf", &february);
	fscanf(ptr, "%lf", &march);
	fscanf(ptr, "%lf", &april);
	fscanf(ptr, "%lf", &may);
	fscanf(ptr, "%lf", &june);
	fscanf(ptr, "%lf", &july);
	fscanf(ptr, "%lf", &august);
	fscanf(ptr, "%lf", &september);
	fscanf(ptr, "%lf", &october);
	fscanf(ptr, "%lf", &november);
	fscanf(ptr, "%lf", &december);

	months[0] = january;
	months[1] = february;
	months[2] = march;
	months[3] = april;
	months[4] = may;
	months[5] = june;
	months[6] = july;
	months[7] = august;
	months[8] = september;
	months[9] = october;
	months[10] = november;
	months[11] = december;
*/
    fclose(ptr);
/*
    printf("Month     Sales\n");
    printf("January   %lf \n", january);
    printf("February  %lf \n", february);
    printf("March     %lf \n", march);
    printf("April     %lf \n", april);
    printf("May       %lf \n", may);
    printf("June      %lf \n", june);
    printf("July      %lf \n", july);
    printf("August    %lf \n", august);
    printf("September %lf \n", september);
    printf("October   %lf \n", october);
    printf("November  %lf \n", november);
    printf("December  %lf \n", december);
*/

    //prints sales report in order
	printf("Monthly sales report for 2022:\n");
	printf("Month         Sales\n");
	for(int i=0; i<12; i++)
	{
		printf("%-14s%.2lf\n",months[i], costs[i]);
	}
	//calculates min, max, and average of the months
    double min = months[0];
    int minPlaceholder = 0;
    double max = months[0];
    int maxPlaceholder = 0;
    double sum = 0;
    //find min
    for(int i = 0; i < 11; i++)
    {
    	if(months[i] < min)
    	{
    		min = months[i];
    		minPlaceholder = i;
    	}
    }
    //find max
    for(int a = 0; a < 11; a++)
    {
    	if(months[a] > max)
    	{
    		max = months[a];
    		maxPlaceholder = a;
    	}
    }
    //find average
    for(int b = 0; b < 11; b++)
    {
    	sum = sum + months[b];
    }
    double average = sum / 12;

    //prints min max and average of the months
    printf("\n");
    printf("Sales summary: \n");
    printf("\n");
    printf("Minimum sales: $%.2lf  (%s) \n", min, months[minPlaceholder]);
    printf("Maximum sales: $%.2lf  (%s) \n", max, months[maxPlaceholder]);
    printf("Average sales: $%.2lf \n", average);

    //prints six month moving average report
    double movingAverage;
	printf("\n\nSix-Month Moving Average Report:\n\n");
	for(int i = 0; i < 7; i++)
	{
	    movingAverage=0;
		for(int a = i; a < i+6; a++)
    	{
    		movingAverage += costs[a];
    	}
    	printf("%-10s-  %-10s $%.2lf\n", months[i], months[i+5], movingAverage/6);
	}

	//prints Sales Report from highest to lowest by eliminating highest month each iteration
	printf("\n\nSales Report (Highest to Lowest):\n");
	printf(" Month      Sales\n");
	printf(" %-10s$%.2lf\n", months[maxPlaceholder], costs[maxPlaceholder]);
	int curMonths = 11;
	int curMax;
	while(curMonths > 0)
	{
		curMax = months[0];
		for(int j = 0; j < 12; j++)
		{
		    if(costs[j] < max && costs[j]>curMax)
		    {
		        curMax = costs[j];
		        maxPlaceholder = j;
		    }
		}
		max = curMax;
		curMonths--;
		printf(" %-12s$%.2lf\n", months[maxPlaceholder], costs[maxPlaceholder]);
	}
    return 0;
}



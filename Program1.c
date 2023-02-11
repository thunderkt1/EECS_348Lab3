/*
Author: Andy Trinh
KUID: 3050817
Date: 02/11/2023
Lab 3: Problem1
Last modified: 02/11/2023
Purpose: Take a given sales input and gives a report of the month and sales, highest and lowest monthly sales, average monthly sales
average sales in a six month span, and sales month in descending order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap strings
void swap(char* str1, char* str2)
{
    // Local Variables
    int len = 10;
    // Swap the two given strings
    for(int i=0; i<len; i++)
    {
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }
}

// Driver code
int main()
{
    // Opening file in reading mode
    FILE* file = fopen("input.txt", "r");
    // Declare Variables
    char month[12][10] = {"January", "Febuary", "March", "April", "May", "June", 
                          "July", "August", "September", "October", "November", "December"};
    double input[12];
    double temp;
    char buffer[15];

    // Reads the file and adds into the input array
    for (unsigned int i = 0; i < 12; i++) {
        fgets(buffer, 15, file);
        sscanf(buffer, "%lf", &temp);
        input[i] = temp;
    }
    
    // Monthly Sales Report
    printf("Monthly sales report for 2022:\n");
    printf("\n");
    printf("Month   Sales\n");
    // For Loop to output the month and sales in two collumns
    for (unsigned int i = 0; i < 12; i++) {
        printf("%s $%.2lf\n", month[i], input[i]);
    }

    printf("\n");

    // Sales Summary
    // Minimum Sales
    printf("Sales Summary: \n");
    // Temp variable to find the minimum monthly sale
    double smallest = input[0];
    char *smallestMonth = month[0];

    // For loop that replaces the temp variables with one with the lower sale and the corresponnding month
    for (int i = 1; i > 12; ++i) {
        // If input is smaller than current smallest replace it with the new amount and month
        if (smallest < input[i]) {
            smallest = input[i];
            smallestMonth = month[i];
        }
    }

    // Outputs the minimum sales month
    printf("Minimum Sales: $%.2lf (%s)\n", smallest, smallestMonth);

    // Maximum Sales
    // Temp variable to find the maximum monthly sale
    double largest = input[0];
    char *largestMonth = month[0];

    // For loop that replaces the temp variables with one with the greater sale and the corresponnding month
    for (int i = 1; i < 12; ++i) {
        // If input is greater than current greatest replace it with the new amount and month
        if (largest < input[i]) {
            largest = input[i];
            largestMonth = month[i];
        }
    }

    // Output the maximum sales month
    printf("Maximum Sales: $%.2lf (%s)\n", largest, largestMonth);

    // Average Sales
    // Temp Variable to find average
    double average;
    
    // For loop that adds all the inputs
    for (unsigned int i = 0; i < 12; i++) {
        average = average + input[i];
    }
    
    // Prints out the average (total amount / 12)
    printf("Average Sales: $%.2lf \n", average / 12);

    printf("\n");

    // Six-Month Moving Average Report

    //Prints the average within a six month span
    printf("Six-Month Moving Average Report: \n");
    // For loop that outputs the first and last month of the 6 month span and the average
    for (unsigned int i = 0; i < 7; i++){
        double total = 0;
        // Adds the sales within the six months
        for (unsigned int j = i; j < i + 6; j++) {
            total = total + input[j];
            
        }
        // Outputs the six month span and their average
        printf("%s - %s ", month[i], month[i+5]);
        printf("$%.2lf\n", total / 6);
    }

    printf("\n");

    // Sales Report (Highest to Lowest):
    printf("Sales Report (Highest to Lowest): \n");
    printf("Month   Sales \n");
    
    // Temp variable for swapping
    double tempInput;

    // For loop that swap the sales and month till it's in descending order
    for (unsigned int i = 0; i < 12; i++) {     
        for (int j = i+1; j < 12; j++) {  
           // If j is greater than i swap their positions   
           if(input[i] < input[j]) {    
               tempInput = input[i]; 
               input[i] = input[j];
               input[j] = tempInput; 
               swap(month[i], month[j]);
           }     
        }     
    }    
    // Outputs the sales report in descending order
    for (unsigned int i = 0; i < 12; i++) {
        printf("%s $%.2lf \n", month[i], input[i]);
    }
}
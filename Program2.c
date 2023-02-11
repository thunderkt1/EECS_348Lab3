/*
Author: Andy Trinh
KUID: 3050817
Date: 02/11/2023
Lab 3: Problem2
Last modified: 02/11/2023
Purpose: This Program take a user inputted NFL game score then prints out all scoring possibilities. Program stops if inputted score is less than 2
*/

#include <stdio.h>

// Global Variables to store the score combination and position
int storage[1000][5];
int position = 0;

int storeScore (int S, int FG, int TD, int TDFG, int TDC) {
    // Local Variables
    int n = 0;
    // Stores the score combination in a temp array
    int temp[5] = {S,FG,TD,TDFG,TDC};

    // Check if the new score is a duplicate of a currently stored one
    for (n; n < position; n++) {
        // If duplicate does not store the combination
        if (storage[n][0] == temp[0] && storage[n][1] == temp[1] && storage[n][2] == temp[2] && storage[n][3] == temp[3] && storage[n][4] == temp[4]) {
            return 0;
        }
    }

    // Stores the combination to the global storage
    for (int i = 0 ; i < 5 ; i++) {
        storage[position][i] = temp[i];
    }

    // Prints out the score possiblities
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", storage[position][4],storage[position][3],storage[position][2],storage[position][1],storage[position][0]);

    // Position Counter
    position++;
}

// Reset the global storage to be reuse for new combinatation of a different score
int reset () {
    // Local Variables
    int i,j;

    // Zero out all use arrays
    for (i = 0; i < position; i++) {
        for (j = 0; j < 5; j++) {
            storage[i][j] = 0;
        }
    }
    
    // Reset the position back to 0
    position = 0;
}

// Returns number of ways to reach score n
int score(int n, int i, int S, int FG, int TD, int TDFG, int TDC)
{   
    
    // Prints Combination if equal to the inputted score n
    if (i == n) {
        storeScore(S,FG,TD,TDFG,TDC);
        return 0;
    }
        
    // Recursively loop until it reaches a combination that equals the inputted score
    if (i+8 <= n) {
        score(n-8,i,S,FG,TD,TDFG,TDC+1);
    }
    if (i+7 <= n) {
        score(n-7,i,S,FG,TD,TDFG+1,TDC);
    }
    if (i+6 <= n) {
        score(n-6,i,S,FG,TD+1,TDFG,TDC);
    }
    if (i+3 <= n) {
        score(n-3,i,S,FG+1,TD,TDFG,TDC);
    }
    if (i+2 <= n) {
        score(n-2,i,S+1,FG,TD,TDFG,TDC);
    }
    return 0;
}

// Main Program
int main(void)
{
    int n;
    // While loop asking user to input a score then printing out all score combination
    while (n != 1)
    {
        
        printf("Enter 0 or 1 to STOP \n");
        printf("Input a score: ");
        scanf("%d", &n);
        // If input less than 2 break loop
        if (n < 2){
            break;
        }
        // Function to find all score combinations
        score(n,0,0,0,0,0,0);  
        // Reset the storage
        reset();
    }

}

/* guessing game b/w 1-100
1) random number generation, 2) guess with if else, 3) attempts print.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LOW 1
#define UPPER 100

int main() {
    int number, attempts = 0;
    
    srand(time(0));
    int random = (rand() % UPPER) + LOW;
    
    printf("Welcome to Guessing Game!\n\n");
    printf("LETS BEGIN\n\n");
    
    do {
        printf("%d attempt: \n", attempts + 1);
        scanf("%d", &number);
        attempts++;
        if( number < random) {
            printf("Number is greater\n");
        }
        else if (number > random) {
            printf("Number is lesser\n");
        }
        else {
            printf("Number %d found after %d attempts\n", number, attempts);
        }
    }
    while (number != random);
return 0;
}
    

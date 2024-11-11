#include <stdio.h>

int main(){

// declaration of left & right inputs (long long type), whitch will be used later to calculate the output

    long long s1,s2;

// start of the infinite while loop (ends only with the break function)

    while (1){ 

/*output to the terminal using the printf function, to prompt the user to input the left cost 
using the scanf function, in a long long type to s1

*/
        printf("Please enter the cost of going left:");

/*
with the help of the function if and the input of the user , at  each ederation of the while loop
the program checks if the left intput is EOF(-1)

*/
        if (scanf("%lld", &s1)!=  EOF){

// if the left value is not (!=) EOF the program outputs again to the terminal (printf) to get the right value (scanf)

            printf("Please enter the cost of going right:");

// the given right input is tested for any imperfections with the if function 

            if (scanf("%lld", &s2) != EOF){
// if the right value in the specifications, the two given answers are used to output the best possible route for the trolley(tram)to take 

             if (s2 >= s1){
             printf("Go left.\n");
             }
             else{
             printf("Go right. \n");
             }
            
            }
            else {

//if the right value is not in the specifications, the program outputs to the terminal to inform the user of its wrong behavior, returns 1 and breaks the while loop (ending the program)
                printf("No right cost provided. \n");
                return 1;
                break;
            }

        }
        else {
/*
if the left value is EOF, the program outputs to the terminal to inform the user that the program finished succesfully,
 returns 0 and breaks the while loop 
*/
            printf("Terminating.");
            return 0;
            break;
    
        }

    }

    
}

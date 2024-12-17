#include <stdio.h>
#include <stdlib.h> // added for the atoll function




long long gcd(long long s1, long long s2) {  //this fuction returns in a long long value the gcd(Greatest Common Divisor)of the two long long numbers that are given
    //this is a simple form of the Euclidean Algorithm
    if (s1%s2 == 0){    //we check if s1 mod s2 = 0
        return s2; 
    } else { 
        return gcd(s2, s1 % s2); //otherwise the fuctions calls itself again(until s1 mod s2 = 0)
    }
}


int main(int argc ,char * argv[]){  // we save the numbers in a dynamic array (argv[]), and save the count of different strings in the integer (argc)

    if (argc !=3){    // checks if the numbers num0,num1 are provided.
        printf("Usage: ./gcd <num1> <num2> "); // if the numbers are not provided correctly, the program prompts the user the right usage
        return 1; // also returns an exit code of 1 as requested 
        // due to the exit code the program closes, this prevents errors like segmentation faults
    }

    long long num0 = atoll(argv[1]); // converts the given strings to num0 and num1 using the atoll function
    long long num1 = atoll(argv[2]);   

    if ( num1 == 0 || num0 == 0){ //checks if both numbers are not equal to 0 , using || also known as or  (Ορισμός 1)
        return 1;   // if one or both the numbers are 0 , it returns exit code 1 as requested 
        // due to the exit code the program closes, this prevents the malfunction of the program, for example a wrong result or an infinite loop of the gcd function
    }
    
    if (num1 <0){ // checks if the first number is negative 
        num1 = num1*(-1);  // if the first number is negative, we multiply it by (-1) to make it positive
    }
    if (num0 <0){ // checks if the second number is negative
        num0 = num0*(-1); // if the second number is negative, we multiply it by (-1) to make it positive
    }

    printf("gcd(%lld,%lld)= %lld",num0,num1,gcd(num0,num1)); // calls the function gcd with the given long long numbers as function parameters and prints it
    return 0; // if all goes well , the program returns exit code 0 as requested.
    
}


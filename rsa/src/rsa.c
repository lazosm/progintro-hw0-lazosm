#include <stdio.h>
#include <stdlib.h> // added for the atoll function
#include <string.h> // added for the strcmp function

long long gcd(long long s1, long long s2) {  //this fuction returns in a long long value the gcd(Greatest Common Divisor)of the two long long numbers that are given
    //this is a simple form of the Euclidean Algorithm
    if (s1%s2 == 0){    //we check if s1 mod s2 = 0
        return s2; 
    } else { 
        return gcd(s2, s1 % s2); //otherwise the fuctions calls itself again(until s1 mod s2 = 0)
    }
}

int prim(long long s){ //this function checks if the given number is prime or not 
    if (s == 1){ // not prime
        return 1;
    }
    for(int i = 2;i*i <=s;i++){ 
        if (s % i ==0){
            return 1; // not prime
            break;
        }
    }
    return 0;
}

/*
we do not need to create 2 different fuctions to calculate the encryption/decryption because both values "m" and "c" are provided using scanf
and are the same type, as for e and d we can use if-else in main to call the function with the right variable as they are different 
*/ 
long long encdec(long long cm,long long ed,long long n){ // this fuction calculates and returns the rsa encryption/decryption 
// allthought harder to understand, modular exponentiation makes encdec more efficent
    long long res = 1; 
    while( ed > 0 ){ 
        if (ed%2 == 1){
            res = res*cm %n;
        }
        cm = cm*cm %n;
        ed /= 2; 
    }
    return res;
}

int main(int argc ,char * argv[]){// we save the numbers in a dynamic array (argv[]), and save the count of different strings in the integer (argc)

    if (argc != 6){ // checks if all the values are provided at all
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>"); // if not the program prints out the correct usage 
        return 1; // also returns exit code 1 as requested
    }
        
        if(strcmp(argv[1],"enc")!= 0 && strcmp(argv[1],"dec")!= 0){ //we use the fuction strcmp to check if the given string value is correct , using an and(&&) statement  
            printf("First argument must be 'enc' or 'dec'"); // if not the program prints out the correct syntax
            return 1;        // also returns exit code 1 as requested
        }

        long long e = atoll(argv[2]);  //we convert the given strings(char) (saved in the argv[] array)to long long numbers using the atoll function 
        long long d = atoll(argv[3]);
        long long p = atoll(argv[4]);
        long long q = atoll(argv[5]);
        long long m; // we define m
        scanf("%lld",m); // we use the scanf function to read (user input) m
        if 

        if(e<0|| d<0||p<0||q<0||m<0){ // we check if one or more of the given numbers are negative, using the or(||) statement
            printf("Negative numbers are not allowed"); // if one/more of them is negative,the program prints out the correct usage
            return 1; // also returns exit code 1 as requested
        }

        if (prim(p)){ // we check if e is prime using the prim function 
            printf("not prime"); // if it is not prime, the program prints it
            return 1; // also returns exit code 1 as requested
        }
        if (prim(q)){  // we check if e is prime using the prim function 
            printf("not prime"); // if it is not prime, the program prints it
            return 1; // also returns exit code 1 as requested
        }

        long long N = q * p,fi = (q-1)*(p-1); //we define and set the requested values to N and fi(totient function) 
        
        if (m>N){ //we check if the m is bigger than N 
            printf("Message is larger than N"); // if yes, the program prints it
            return 1; // also returns exit code 1 as requested
        }

        if (gcd(e,fi) != 1){ // we check if e is not coprime with fi using the gcd function
            printf("e is not coprime with f(N)"); //if it's true, the program prints out the error
            return 1; // also returns exit code 1 as requested
        }

        if ((e * d) % fi != 1){  //we check if e and d are not invers
            printf("e * d mod phi(N) is not 1"); // if yes,the program prints out the error
            return 1; // also returns exit code 1 as requested
        }

        if (strcmp(argv[1],"enc")== 0){ //we check if the string(in argv) is enc 
            printf("%lld",encrypt(m,e,N)); // if it's enc, we call the function encdec with the correct values and print the result using printf
        }
        else{ //using else we understand that the string is dec as we checked its input before
            printf("%lld",decrypt(m,d,N)); // if it's dec, we call the function encdec with the correct values(d instead of e) and print the result using printf
        }
    }

    return 0; //if all goes well, the program returns exit code 0 as requested
}

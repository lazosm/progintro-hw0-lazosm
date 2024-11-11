#include <stdio.h>
#include <stdlib.h>

/* 
long long num = strtoll(answer, &endptr, 10);
where answer is a string(char) ,
endptr is the exit from strtoll if not (\'0')then str is not long long [char *notlong;]
10 is the base 
*/


int main(){
    char answer[19];
    long long s1,s2;
    char *notlong;

    while (1){

        printf("Please enter the cost of going left:") ;
        scanf("%18s",answer);

        s1 = strtoll(answer, &notlong, 10);

        if (*notlong == '\0' && *notlong != EOF){

            printf("Please enter the cost of going right:");
            scanf("%17s",answer);

            s2 = strtoll(answer, &notlong, 10);

            if (*notlong == '\0'){

             if (s2 >= s1){
             printf("Go left.\n");
             }
             else{
             printf("go right. \n");
             }

            }
            else {
                return 1;
                break;
            }
        }
        else {
            return 0;
            break;
        }
    }
}




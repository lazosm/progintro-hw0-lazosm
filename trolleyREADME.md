trolley.c is putting the input using scanf directly to a long long variable, the program is not testing for values other than longlong and oef 
trolley01.c is using an array for input and using the strtoll function(<stdlib.h>) it gets more reliable

using vs code and msys64 compiler on windows i have to press ctrl + z 3 times to end the program with EOF
"gcc -O0 -m32 -Wall -Wextra -Werror -pedantic -o trolley trolley.c" returns error, without removing -m32

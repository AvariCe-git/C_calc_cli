/*  This "program" is a really simple two number calculator.
    It can do addition, subraction, multiplication, division
    modulo operation, raise a number the nth power and find 
    the nth root of a number. It accepts 3 arguments from the 
    command line, when it is called. The first number, the 
    option and the second number, in that order with spaces between them. 
    For help, th arguments should be h and 1.
    The options are: + for addition, - for subtraction, x for multiplication, / for division
    % for modulo, ^ for exponentation and r for finding the root of a number, h for help. 
    For subtraction, the first mumber is the minuend and the second is the subtrahend. ex: whatever.exe 1st - 2nd 
    For division, the first number is the dividend and the second is the divisor. ex: whatever.exe 1st / 2nd
    For modulo, the first number is the dividend and the second is the divisor. ex: whatever.exe 1st % 2nd
    For exponentation, the first number is the base and the second is the exponent. ex: whatever.exe 1st ^ 2nd
    For any root, the first number is the radicand and the second is the degree. ex: whatever.exe 1st r 2nd
    Current version 1.1

    2020 Antonios Giannakopoulos, https://github.com/AvariCe-git */


#include <stdio.h>                                                                          // Standard input output
#include <stdlib.h>                                                                         // needed for the atof function 
#include <string.h>                                                                         // needed for the strncmp function
#include <math.h>                                                                           // needed for pow and root functions

void check(char n1[], char praxi[], char n2[]);                                             //Separate function for shits and giggles
int praxeis(double a, char epilogi[], double b);                                            // Calculations will happen here.
int print_help();                                                                           // This function shows the "help" text.


 int main(int argc,char* argv[]){

    check(argv[1],argv[2],argv[3]);                                                         // Calling a separate function because I don't feel comfortable having more than 2 lines in main function
    return 0;

}

void check(char n1[], char praxi[], char n2[]){
    
        if(strcmp(n1,"h") == 0)                                                             // Checks the first argument if help has been called
            print_help();                                                                   // If it has, it calls the appropriate function.
    double a = 0,b = 0;                                                                     // Doubles for almost all the operations                                                                     
    a = atof(n1);                                                                           //  Converting the strings to doubles, using atof because it's easy 
    b = atof(n2);                                                                           //  Same
    praxeis(a,praxi,b);

}

int praxeis(double a, char epilogi[], double b){                                            // Calculations

    int pragma1 = 0, pragma2 = 0;                                                           //  Integers for modulo operation
    if(strncmp(epilogi,"+",1) == 0)                                                         // Check for addition option and print the result, use strncmp because it's easy
        printf("The result of %lf + %lf is:  %lf\n",a,b,a+b);                               // All messages are in greek, because I am greek
    else if(strncmp(epilogi,"-",1) == 0)                                                    // Check for subtraction option and print the result
        printf("The result of %lf - %lf is:  %lf\n",a,b,a-b);    
    else if(strncmp(epilogi,"x",1) == 0)                                                    // Check for multiplication option and print the result, using x instead of * because * doesn't play well  
        printf("The result of %lf * %lf is:  %lf\n",a,b,a*b);                               // being an argument and because it's easy
    else if(strncmp(epilogi,"/",1) == 0){                                                   // Check for division option
        if (b == 0)                                                                         // If the divisor is 0, print rude message and quit
            printf("Divisor is 0\n"); 
        else 
            printf("The result of %lf / %lf is:  %lf\n",a,b,a/b);                           // If the divisor is non zero, print the result
        }
    else if(strncmp(epilogi,"^",1) == 0)                                                    // Check for exponentiation option and print the result
        printf("The result of %lf raised to %lf is:  %lf\n",a,b,pow(a,b));
    else if(strncmp(epilogi,"%",1) == 0){                                                   // Check for modulo option
        if (b == 0)                                                                         // If the divisor is 0, print rude message and quit
            printf("Divisor is 0\n"); 
        else{                                                                               // Convert the doubles to integers and print the result
                pragma1 = a;
                pragma2 = b;
                printf("The remainder of %d / %d  is:  %d\n",pragma1, pragma2,pragma1%pragma2);
        }
    }
            else if(strncmp(epilogi,"r",1) == 0)                                            // Check for the root option and print the result
            printf("The %lfi root of %lf einai:  %lf\n",b,a,pow(a,1.0/b));
    return 0;

}
int print_help(){                                                                           // Prints the "help"

    printf("This so called program is a really simple two number calculator.\n");
    printf("It can do addition, subraction, multiplication, division\n");
    printf("modulo operation, raise a number the nth power and find\n");
    printf("the nth root of a number. It accepts 3 arguments from the\n");
    printf("command line, when it is called. The first number, the\n");
    printf("option and the second number, in that order with spaces between them\n");
    printf("For help, the first argument should be h\n");
    printf("The options are: + for addition, - for subtraction, x for multiplication, / for division\n");
    printf("%% for modulo, ^ for exponentation and r for finding the nth root of any number.\n");
    printf("For subtraction, the first mumber is the minuend and the second is the subtrahend. ex: whatever.exe 1st - 2nd\n");
    printf("For division, the first number is the dividend and the second is the divisor. ex: whatever.exe 1st / 2nd\n");
    printf("For modulo, the first number is the dividend and the second is the divisor. ex: whatever.exe 1st %% 2nd\n");
    printf("For exponentation, the first number is the base and the second is the exponent. ex: whatever.exe 1st ^ 2nd\n");
    printf("For any root, the first number is the radicand and the second is the degree. ex: whatever.exe 1st r 2nd\n");
    printf("Current version 1.1\n");
    printf("2020 Antonios Giannakopoulos, https://github.com/AvariCe-git\n");
    return 0;

}
/*
* author: Estefanio N Santos <estefanions AT gmail DOT com> 
* https://github.com/estefanionsantos/header4c

// example:
#include <stdarg.h>
#include "header4c/printf_header.h"

int main(){
    printfGreen("Lorem Ipsum");
    return 0;
}

*/

#include <cstdio>

#define TX_RED            "\x1B[31m"
#define TX_GREEN          "\x1B[32m"
#define TX_YELLOW         "\x1B[33m"
#define TX_GREENISH_BLUE  "\x1B[36m"
#define TX_RESET          "\033[0m"

void printLn(int num = 1)
{
    int i = 0;

    for (i = 0; i < num; i++) {
        printf("\n");
    }
}

void printDash(int num = 30)
{
    int i = 0;

    for (i = 0; i < num; i++) {
        printf("-");
    }
}

void printDashLn(int num = 30)
{
    printDash(num);
    printLn();
}

void printfLn(const char* format, ...)
{
    va_list args;
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, "\n");
}

void printfSuccessLn(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_GREEN);
    va_start( args, format );
    fprintf( stderr, "Done, ");
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, " :)");
    fprintf( stderr, TX_RESET);
    fprintf( stderr, "\n");
}

void printfWarningLn(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_YELLOW);
    va_start( args, format );
    fprintf( stderr, "Warning, ");
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, " :/");
    fprintf( stderr, TX_RESET);
    fprintf( stderr, "\n");
}

void printfErrorLn(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_RED);
    va_start( args, format );
    fprintf( stderr, "Error, ");
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, " :(");
    fprintf( stderr, TX_RESET);
    fprintf( stderr, "\n");
}

void printfGreen(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_GREEN);
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, TX_RESET);
}

void printfYellow(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_YELLOW);
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, TX_RESET);
}

void printfRed(const char* format, ...)
{
    va_list args;
    fprintf( stderr, TX_RED);
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, TX_RESET);
}

// EOF

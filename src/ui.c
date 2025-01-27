#include <stdio.h> // Include for printf
#include "ui.h"    // Include the header file for the user interface

void display_menu() {
    printf("Calculator Program:\n");
    printf("-----------------------\n");
    printf("Select an operation from the list below:\n");
    printf("+: Addition \n");
    printf("-: Subtraction \n");
    printf("*: Multiplication \n");
    printf("/: Division \n");
    printf("%%: Modulus \n");
    printf("^: Power \n");
    printf("s: Square Root \n");
    printf("e: Logarithm \n");
    printf("l: Logbase10 \n");
    printf("$: sine \n");
    printf("(: cosine \n");
    printf("): tangent \n");
    printf("q: Quit \n");
    printf("h: Display History \n");
    printf("c: Clear History \n");
    printf("-----------------------\n");
}
void display_ascii_art() {
    printf("░█████╗░░█████╗░██╗░░░░░░█████╗░██╗░░░██╗██╗░░░░░░█████╗░████████╗░█████╗░██████╗░\n");
    printf("██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗\n");
    printf("██║░░╚═╝███████║██║░░░░░██║░░╚═╝██║░░░██║██║░░░░░███████║░░░██║░░░██║░░██║██████╔╝\n");
    printf("██║░░██╗██╔══██║██║░░░░░██║░░██╗██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║░░██║██╔══██╗\n");
    printf("╚█████╔╝██║░░██║███████╗╚█████╔╝╚██████╔╝███████╗██║░░██║░░░██║░░░╚█████╔╝██║░░██║\n");
    printf("░╚════╝░╚═╝░░╚═╝╚══════╝░╚════╝░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝\n");
}

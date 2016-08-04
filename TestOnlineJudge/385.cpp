//
// Created by Wayne Tu on 5/20/16.
//

#include <iostream>
#include <cstring>

void swapChar(char *a, char *b);
void rotateRight(char text[], int n);


void swapChar(char* a, char* b) {
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

void rotateRight(char text[], int n) {
    char temp = text[n - 1];
    for (int i = n - 1; i > 0; i--) {
        text[i] = text[i - 1];
    }
    text[0] = temp;
}

int main()
{
    char text[100];
    std::cin >> text;

    int length = strlen(text);
    swapChar(&text[0], &text[length - 1]);

    for (int i = 0; i < 3; i++)
        rotateRight(text, length);

    std::cout << text << std::endl;
    return 0;
}
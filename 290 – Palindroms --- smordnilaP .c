#include <stdio.h>
#include <string.h>

char* strrev(char str[200])
{
    char* p1, * p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int palindrome(char x[200], int length) {

    char y[200];
    strcpy(y, x);
    strrev(y);
    int i;
    for (i = 0; i < length; i++) {
        if (x[i] != y[i]) return 0;
    }
    return 1;
}

char add(char s[200], int base, int counter, int length) {
    int i;
    if (counter > 0) {
        for (i = 0; i < length; i++) {
            if (s[i] <= '9')
                s[i] -= '0';
            else
                s[i] -= 'A' - 10;
        }
    }

    char arr[200];
    int tmp = 0;
    for (i = 0; i < length; i++) {
        arr[i] = (s[length - i - 1] + s[i] + tmp) % base;
        if (arr[i] <= 9)
            arr[i] += '0';
        else
            arr[i] += 'A' - 10;
        tmp = (s[length - i - 1] + s[i] + tmp) / base;
    }

    if (tmp > 0) {
        arr[length] = tmp;
        if (arr[length] <= 9)
            arr[length] += '0';
        else
            arr[length] += 'A' - 10;
        arr[length + 1] = '\0';
        length += 1;
    }
    else
        arr[length] = '\0';

    counter += 1;
    if (palindrome(arr, length) == 0)
        return add(arr, base, counter, length);
    else 
        return counter;

}

int main()
{
    char number[200];
    while (scanf("%s", number) == 1) {
        int length = strlen(number);
        int base = 1;
        int d = palindrome(number, length);
        int i, k;
        for (i = 0; i < length; i++) {
            if (number[i] <= '9') 
                number[i] -= '0';
            else 
                number[i] -= 'A' - 10;
            if (number[i] > base) 
                base = number[i];
        }

        for (k = 15; k > base; k--) {
            if (d == 1) {
                printf("0");
                if (k != 2) 
                    printf(" ");
                continue;
            }
            else {
                printf("%d", add(number, k, 0, length));
                if (k != 2) 
                    printf(" ");
            }
        }

        for (k = 2; k <= base; k++) {
            if (k == base) 
                printf("?");
            else 
                printf("? ");
        }
        printf("\n");
    }

    return 0;
}
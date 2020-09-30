#include<stdio.h>
#include<string.h>

int main()
{
    int N;
    int i;
    scanf("%d", &N);
    
    for(i=1; i<=N; i++)
    {
        int seq;
        scanf("%d,", &seq);
        
        if (seq == 2 || seq == 3 || seq == 5 || seq == 7 || seq == 13 || seq == 17 || seq == 19)
            printf("Yes\n") ;
        else 
            printf("No\n");
    }
}
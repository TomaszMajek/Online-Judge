#include <stdio.h>
#include <stdlib.h>


int fdistance(int x, int company[], int distance[], int dist){
    if(x == company[x]) return dist;
    dist += distance[x];
    x = company[x];
    return fdistance(x, company, distance, dist);
}

int main(){

    int I, J, N;
    int T;

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        int distance[N+1];
        int company[N+1];
        char ch;
        int i,dist;
        for(i = 1; i <=N; i++){
            company[i] = i;
            distance[i] = 0;
        }
        while(scanf("%c", &ch) == 1 && ch !='O'){
            dist=0;
            if(ch == 'E'){
                scanf("%d", &I);
                dist = fdistance(I, company, distance, dist);
                printf("%d\n", dist);
            }
            if(ch == 'I'){
                scanf("%d", &I);
                scanf("%d", &J);
                company[I] = J;
                distance[I] = abs(I-J)%1000;
            }
        }
    }
    return 0;
}

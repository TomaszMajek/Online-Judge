#include<stdio.h>
int main(){

    int n;
    int i,j,k;
    int N,E,T,M;
    int a,b,t;

    scanf("%d",&n);
    while(n > 0){
    scanf("%d %d %d %d", &N,&E,&T,&M);
    int maze[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            maze[i][j] = 1000;
        }
        maze[i][i] = 0;
    }
    while(M > 0){
        scanf("%d %d %d", &a, &b, &t);
        maze[a-1][b-1] = t;
        M--;
    }
    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0; j<N; j++){
                if(maze[i][j] > maze[i][k] + maze[k][j])
                    maze[i][j] = maze[i][k] + maze[k][j];
            }
    int x=0;
    for(i=0;i<N;i++){
        if(maze[i][E-1]<= T || (i==E-1)){
            x++;
        }
    }

    printf("%d\n", x);
    n--;
    if(n > 0) printf("\n");
    }
    return 0;
}

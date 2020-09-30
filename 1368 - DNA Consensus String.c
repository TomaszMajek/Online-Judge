#include <stdio.h>

struct DNA{
    char* name;
    int key;
};

int main(){

    int number_of_strings;
    int length_of_string;
    int N;
    scanf("%d", &N);
    while(N--){
    scanf("%d", &number_of_strings);
    scanf("%d", &length_of_string);

    char string[number_of_strings][length_of_string];
    struct DNA dna[number_of_strings];
    int i,j;
    for(i=0;i < number_of_strings; i++){
    dna[i].name = (char*) malloc ((length_of_string+1)*sizeof(char*));
    scanf("%s", dna[i].name);
    }

    printf("\n");
    char consensus_string[length_of_string];
    int consensus_error=0;
    int maks;

    for(i=0;i < length_of_string; i++){
        int ACGT[4] = {0,0,0,0};
        for(j=0;j< number_of_strings;j++){
            switch (dna[j].name[i]){
            case 'A':
                ACGT[0]++;
                break;
            case 'C':
                ACGT[1]++;
                break;
            case 'G':
                ACGT[2]++;
                break;
            case 'T':
                ACGT[3]++;
                break;
            }
        }
            if(ACGT[0] >= ACGT[1] && ACGT[0] >= ACGT[2] && ACGT[0] >= ACGT[3]){
                    consensus_string[i] =  'A';
                    maks = ACGT[0];
            }
            else if(ACGT[0] <= ACGT[1] && ACGT[1] >= ACGT[2] && ACGT[1] >= ACGT[3]){
                consensus_string[i] =  'C';
                maks = ACGT[1];
            }
            else if(ACGT[2] >= ACGT[1] && ACGT[0] <= ACGT[2] && ACGT[2] >= ACGT[3]){
                consensus_string[i] =  'G';
                maks = ACGT[2];
            }
            else{
                    consensus_string[i] =  'T';
                     maks = ACGT[3];
            }
            consensus_error += number_of_strings - maks;
    }


    consensus_string[length_of_string] = '\0';
    printf("%s\n%d\n", consensus_string, consensus_error);
    }

    return 0;

}

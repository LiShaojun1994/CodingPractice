#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    string P;
    cin >> P;
    P = " " + P;
    int M;
    cin >> M;
    string S;
    cin >> S;
    S = " " + S;
    vector<int> next(N+1,0);
    for (int i = 2,j =0; i <= N+1 ; i++) {
        while (j && P[i] != P[j+1]) {

            j = next[j];
        }
        if (P[i] == P[j+1]) {
            printf("i = %d, j = %d, P[i] = %c, P[j+1] = %c\n",i,j,P[i],P[j+1]);
            j++;
        }
        next[i] = j;
        printf("next[%d] = %d\n",i,next[i]);
    }
    for(int i = 1,j=0;i<=M;i++){
        while(j && S[i] != P[j+1]) j = next[j];
        if(S[i] == P[j+1]) j++;
        if(j == N){
            printf("%d ",i-N);
            j = next[j];
        }
    }
    return 0;
}
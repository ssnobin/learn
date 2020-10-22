#include <stdio.h>

#define maxn 70
static int start[maxn], finish[maxn];

int f(int *P, int i, int peg){
    if (i==0){
        return 0;
    }
    if (P[i] == peg){
        return f(P, i-1, peg);
    }
    int other_peg = 6-P[i]-peg;
    return f(P, i-1, other_peg) + 1 + (1LL<<(i-1)) - 1;
}

int main()
{
    int N;
    int Kase = 1;
    while(scanf("%d", &N)==1 && N > 0){
        int i;
        for(i=1;i<=N;i++){ scanf("%d", &start[i]);}
        for(i=1;i<=N;i++){ scanf("%d", &finish[i]);}
        int k = N;
        while(k >= 1 && start[k]==finish[k])k--;
        long long ans;
        if(k == 0){
            ans = 0;
        }
        else
        {
            int other = 6-start[k]-finish[k];
            ans = f(start, k-1, other) + 1 + f(finish, k-1, other);
        }
        printf("Case %d: %lld\n", Kase++, ans);
    }
    return 0;
}

#include "stdio.h"

/*int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize){*/
/*[>int firstDayBeenInAllRooms(){<]*/
    /*const int mod = 1e9+7;*/
    /*[>printf("%d", mod);<]*/
    /*[>int dp[nextVisitSize+1] = {1,2};<]*/
    /*long long dp[100000 + 1] = {0};*/
    /*[>for(int i = 1; i < nextVisitSize; i ++)<]*/
        /*[>printf("%d\n", dp[i]);<]*/
    /*for (int i = 1; i < nextVisitSize; i++){*/
        /*[>printf("%d\n", nextVisit[i]);<]*/
        /*[>int nv = nextVisit[i-1];<]*/
        /*long long dont_walk = dp[nextVisit[i - 1]];*/
        /*[>printf("%d\n", dont_walk);<]*/
        /*long long result = (2 + 2 * dp[i-1] - dont_walk);*/
        /*dp[i] = (result + mod) % mod;*/
        /*[>printf("i=%d result=%ld\n", i, dp[i]);<]*/
    /*}*/
    /*return (int)dp[nextVisitSize-1];*/
/*}*/

int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize){
    int mod = 1e9+7;
    long long dp[100000 + 1] = {0};
    for (int i = 1; i < nextVisitSize; i++){
        //dp[i-1] is probably bigger then dp[i], because mod
        //so add mod then % mod, otherwise negative number is occurred!!
        dp[i] = (2*dp[i-1] + mod - dp[nextVisit[i-1]] + 2)%mod;
        /*if (i == 94)*/
        printf("%d %lld %lld %d %lld %d\n", i, dp[i], dp[i-1], nextVisit[i-1], dp[nextVisit[i-1]], mod);
        /*61 32310532 303706890 30 575103250 1000000007*/
        /*62 -85567649 32310532 31 150188715 1000000007*/

    }
    return (int)dp[nextVisitSize-1];
}
int main(){
    /*int nextVisit[4] = {0, 0, 0, 0};*/
    int nextVisit[] = {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48};
    int ret = firstDayBeenInAllRooms(nextVisit, 96);
    printf("ret is %d\n", ret);
}

#include <stdio.h>
static int get_cycle(int n){
    if (n == 1){
        return 1;
    }
    int length = 1;
    int next = n;
    while(next!=1){
        if (next % 2 == 0){
            next = next / 2;
        }
        else{
            next = next * 3 + 1;
        }
        length = length + 1;
    }
    return length;
}

int main()
{
    int m,n;
    while(scanf("%d%d", &m, &n) == 2 && m > 0 && n > 0){
        printf("%d %d ", m, n);
        if (m > n){
            int tmp = m;
            m = n;
            n = tmp;
        }
        int max_cycle = 1;
        int i;
        for (i = m; i <= n; i++){
            int cur_cycle = get_cycle(i);
            if (cur_cycle > max_cycle){
                max_cycle = cur_cycle;
            }
        }
        printf("%d\n", max_cycle);
    }
    return 0;
}

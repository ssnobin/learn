#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
bool canConstruct(char * s, int k){
    int table[26] = {0};
    int l = strlen(s);
    for (int i = 0; i < l; i++){
        ++table[s[i] - 'a'];
    }
    int count = 0;
    for (int i = 0; i < 26; i++){
        count += table[i] & 1;
    }
    return count <= k && k <= l;
}
int main()
{

}

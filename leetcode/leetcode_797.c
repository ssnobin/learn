#include "stdlib.h"
#include "string.h"

int path[16];
int *ret[7000];
void helper(int** graph,int cur,int *idx,int graphSize,int i,int *graphColSize,int **returnColumnSizes)
{
    path[i]=cur;
    if(cur==graphSize-1)
    {
        ret[*(idx)]=calloc(16,sizeof(int));
        returnColumnSizes[0][*(idx)]=i+1;
        memcpy(ret[(*idx)++],path,sizeof(int)*(i+1));
    }
    else
        for(int j=0;j<graphColSize[cur];j++)
        {
            helper(graph,graph[cur][j],idx,graphSize,i+1,graphColSize,returnColumnSizes);
        }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
    returnColumnSizes[0]=malloc(sizeof(int)*7000);
    int idx=0;
    helper(graph,0,&idx,graphSize,0,graphColSize,returnColumnSizes);
    *returnSize=idx;
    return ret;
}

int main(){
    /*int **graph cc*/
}

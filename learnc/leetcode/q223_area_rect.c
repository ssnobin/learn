long min(int a, int b){
    if (a<b)
        return a;
    else
        return b;
}

long max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    long area1 = (C-A)*(D-B);
    long area2 = (G-E)*(H-F);
    long x = min(C,G)-max(A,E);
    long y = min(D,H)-max(B,F);
    long x_area = 0;
    if (x>0 && y>0)
        x_area = x*y;
    long sum = area1 + area2;
    long ret = sum - x_area;
    return (int)ret;
}

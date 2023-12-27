#include <stdio.h>
int main(){
    int k;
    scanf("%d", &k);
    int ans = k;
    for(int i = 1; i < k; i++)
        ans += i*(k - i);
    printf("%d\n", ans);
    return 0;
}
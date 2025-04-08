#include <stdio.h>
#define ll long long

int main()
{
    ll n;
    scanf("%lld", &n);

    ll cat = 1;
    ll ans = 1;

    while(cat < n)
    {
        cat <<= 1; 
        // cat *= 2; 동형
        ans++;
    }

    if (n == 0) printf("0");
    else printf("%lld", ans);

    return 0;
}
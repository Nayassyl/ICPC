#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> n;
        bool check = false;
        for (int i = 2; i <= (int)sqrt(2 * n); ++i)
        {
            if ((2 * n) % i== 0)
            {
                a = (2 * n) / i + 1 - i;
                if (a % 2 == 0)
                {
                    a /= 2;
                    printf("%d = %d", n, a);
                    for (int j = 1; j < i; ++j)
                        printf(" + %d", j + a);
                    putchar('\n');
                    check = true;
                    break;
                }
            }
        }
        if (!check)
            printf("IMPOSSIBLE\n");
    }
}

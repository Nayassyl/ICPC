#include <iostream>
using namespace std;
#define MAX 201
bool primes[MAX];
void gen_primes(void)
{
    int i, j;
    for (i = 0; i < MAX; i++)
        primes[i] = 1;
    primes[0] = primes[1] = 0;
    for (i = 2; i * i <= MAX; i++)
    {
        if (primes[i])
        {
            for (j = i * i; j < MAX; j += i)
                primes[j] = 0;
        }
    }
}
int main()
{
    gen_primes();
    int sums[MAX];
    for (int i = 0; i < MAX; i++)
        sums[i] = 0;
    for (int i = 2; i < MAX; i++)
    {
        sums[i] = sums[i - 1] + primes[i];
    }
    int a, b;
    while (cin >> a >> b)
        cout << sums[b] - sums[a - 1] << "\n\n";
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    int X;
    std::cin >> n >> X;

    std::vector<int> difficulties(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> difficulties[i];
    }

    std::sort(difficulties.begin(), difficulties.end(), std::greater<int>());

    long long time = 0;

    while (difficulties[0] > 0 && X > 1) {
        difficulties[0] -= X;
        X = (X + 1) / 2;
        time++;
        std::sort(difficulties.begin(), difficulties.end(), std::greater<int>());
    }

    for(int i = 0; i < n; i++){
        if (difficulties[i] > 0){
            time += difficulties[i];
        }
    }

    std::cout << time;
}
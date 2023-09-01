#include <iostream>
using namespace std;

int climbingStairs(int);

int main() {
    int n = 5;
    int ways = climbingStairs(n);
    cout << "There is " << ways << " differente way(s)" << endl;

    return 0;
}

int climbingStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = climbingStairs(n-1);
    int b = climbingStairs(n-2);
    return a+b;
}
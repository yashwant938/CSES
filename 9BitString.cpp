#include <iostream>
using namespace std;
const int MOD = 1000000007;
int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * (long long)base) % mod;
        }
        base = (base * (long long)base) % mod;
        exp /= 2;
    }
    return result;
}
int count_bit_strings(int n) {
    if (n == 0) return 1; 
    return power(2, n, MOD);
}
int main() {
    int n;
    cin >> n;
    cout << count_bit_strings(n) << endl;
    return 0;
}

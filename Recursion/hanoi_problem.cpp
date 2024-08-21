#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << "->" << n << "->" << b << endl;
        return;
    }
    hanoi(n-1, a, c, b);
    cout << a << "->" << n << "->" << b << endl;
    hanoi(n-1, c, b, a);
}

int main() {
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;

    hanoi(n, a, b, c);

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);

    int a; cin >> a;
    cout << a;

    fclose(input);
    fclose(output);
}
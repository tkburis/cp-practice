#include <bits/stdc++.h>
using namespace std;

int main()
{
    int _, a, b, c, d, e, f, x, y, z;
    cin >> _ >> a >> b >> c >> _ >> d >> e >> f >> _;
    int ln = (a+b+c+d+e+f)/2;
    x = ln-a-b;
    y = ln-c-d;
    z = ln-e-f;
    cout << x << ' ' << a << ' ' << b << '\n';
    cout << c << ' ' << y << ' ' << d << '\n';
    cout << e << ' ' << f << ' ' << z << '\n';
    return 0;
}
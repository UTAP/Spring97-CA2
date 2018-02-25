#include <iostream>
#include <vector>

using namespace std;

long long sum(const vector<int> &v, int i = -1) {
    if(i == -1)
        i = v.size() - 1;
    return (i % 2 ? -1 : 1) * v[i] + (i ? sum(v, i - 1) : 0);
}

int main() {
    int n, temp;
    vector<int> a;
    cin >> n;
    while(n--)
        a.push_back((cin >> temp, temp));
    cout << sum(a) << endl;
    return 0;
}

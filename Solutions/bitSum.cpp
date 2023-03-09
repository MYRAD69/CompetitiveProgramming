#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1e9 + 7
#define ff first
#define ss second
#define N 101
using namespace std;
int main() {
    string a, b;
    int rem = 0;
    char res[2002];
    for (int i = 0; i < 2002; i++)
        res[i] = '0';
    cin >> a >> b;
    if (a.length() < b.length())
        for (int i = 1; i <= b.length() - a.length(); i++)
            a = '0' + a;
    elif (a.length() > b.length())
        for (int i = 1; i <= a.length() - b.length(); i++)
            b = '0' + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1' && b[i] == '1') {
            res[i] = '0';
            rem++;
        }
        elif (a[i] == '0' && b[i] == '0') {
            if (rem >= 1) {
                rem--;
                res[i] = '1';
            }
            else res[i] = '0';
        }
        else res[i] = '1';
    }
    for (int i = 1; i <= rem; i++) {
        res[i + a.length() - 1] = '1';
    }
    reverse(res, res + a.length() + rem);
    for (int i = 0; i < a.length() + rem; i++)
        cout << res[i];
    return 0;
}
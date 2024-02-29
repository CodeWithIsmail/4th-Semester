#include <bits/stdc++.h>
using namespace std;
string encrypt(string a, int shift)
{
    string encrypted = "";
    for (auto c : a)
    {
        char base = isupper(c) ? 'A' : 'a';
        c = ((c - base + shift) % 26) + base;
        encrypted += c;
    }
    return encrypted;
}

string decrypt(string a, int shift)
{
    return encrypt(a, 26 - shift);
}
int main()
{
    int shift;
    string a;
    cin >> a >> shift;
    string encrypted = encrypt(a, shift);
    string decrypted = decrypt(encrypted, shift);
    cout << "Encrypted: " << encrypted << "\n"
         << "Decrypted: " << decrypted;
}
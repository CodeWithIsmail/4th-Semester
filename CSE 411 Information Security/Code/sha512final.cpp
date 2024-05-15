#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string in;
    cin >> in;
    string binary = "";
    //  stringstream bin;
    for (i = 0; i < in.size(); i++)
    {
        binary += bitset<8>(in[i]).to_string();
    }
    //  binary = bin.str();
    cout << binary << "\n";
    int len = binary.length();
    //  cout<<len<<"\n";
    int mod = len % 1024;
    int toAdd;
    if (1024 - mod >= 128)
        toAdd = 1024 - mod;
    else
        toAdd = 2048 - mod;

    int add0 = toAdd - 128 - 1;
    binary += "1";
    for (i = 0; i < add0; i++)
        binary += "0";
    string lengthBit = bitset<128>(len).to_string();
    binary += lengthBit;
    cout << binary << "\n";

    int blockNum = binary.length() / 1024;
    cout << blockNum << "\n";
    //  cout << toAdd << "\n";
}
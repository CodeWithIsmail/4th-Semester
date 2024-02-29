#include <bits/stdc++.h>
using namespace std;
string text, keyword;

string encrypt()
{
    string encrypt = "";
    for (int i = 0; i < text.size(); i++)
    {
        int sum;
        char temp;
        if (isupper(text[i]))
        {
            sum = ((text[i] - 'A') + (keyword[(i % keyword.size())] - 'a')) % 26;
            temp = 'A' + sum;
        }
        else
        {
            sum = ((text[i] - 'a') + (keyword[(i % keyword.size())] - 'a')) % 26;
            temp = 'a' + sum;
        }
        encrypt.push_back(temp);
    }
    return encrypt;
}
string decrypt(string cipherText)
{
    string decrypt = "";
    for (int i = 0; i < cipherText.size(); i++)
    {
        int sum;
        char temp;
        if (isupper(cipherText[i]))
        {
            sum = ((cipherText[i] - 'A') - (keyword[(i % keyword.size())] - 'a') + 26) % 26;
            temp = 'A' + sum;
        }
        else
        {
            sum = ((cipherText[i] - 'a') - (keyword[(i % keyword.size())] - 'a') + 26) % 26;
            temp = 'a' + sum;
        }
        decrypt.push_back(temp);
    }
    return decrypt;
}
int main()
{
    cin >> keyword >> text;
    cout << "Key: " << keyword << "\n";
    string cipherText = encrypt();
    cout << "Cipher Text:" << cipherText << "\n";
    string plainText = decrypt(cipherText);
    cout << "Plain Text:" << plainText << "\n";
}
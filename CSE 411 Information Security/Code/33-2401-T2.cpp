#include <bits/stdc++.h>
using namespace std;

string keyword, text;
map<char, pair<int, int>> index;
char table[5][5];

void tableGen(string key)
{
    map<char, bool> check;
    int row = 0, col = 0, i, j;
    for (auto x : key)
    {
        if (check[x])
            continue;
        table[row][col] = x;
        col++;
        if (col == 5)
        {
            row++;
            col = 0;
        }
        check[x] = true;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (check[i] || i == 'j')
            continue;
        table[row][col] = i;
        col++;
        if (col == 5)
        {
            row++;
            col = 0;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            index[table[i][j]] = {i, j};
        }
    }
}
string encryption(string text)
{
    int in = 0;
    string encrypted = "";
    while (in <= text.size() - 1)
    {
        char char1, char2;
        if (in == text.size() - 1)
            char1 = text.back(), char2 = 'x', in++;
        else
        {
            if (text[in] == text[in + 1])
                char1 = text[in], char2 = 'x', in++;
            else
                char1 = text[in], char2 = text[in + 1], in += 2;
        }

        int row1 = index[char1].first, row2 = index[char2].first, col1 = index[char1].second, col2 = index[char2].second;

        if (row1 == row2)
        {
            int newCol1 = (col1 + 1) % 5, newCol2 = (col2 + 1) % 5;
            encrypted += table[row1][newCol1], encrypted += table[row2][newCol2];
        }
        else if (col1 == col2)
        {
            int newRow1 = (row1 + 1) % 5, newRow2 = (row2 + 1) % 5;
            encrypted += table[newRow1][col1], encrypted += table[newRow2][col2];
        }
        else
        {
            int newCol1 = col2, newCol2 = col1;
            encrypted += table[row1][newCol1], encrypted += table[row2][newCol2];
        }
    }
    return encrypted;
}
string decryption(string cipherText)
{
    int in = 0;
    string decrypted = "";
    for (in = 0; in < cipherText.size() - 1; in += 2)
    {
        char char1 = cipherText[in], char2 = cipherText[in + 1];
        int row1 = index[char1].first, row2 = index[char2].first, col1 = index[char1].second, col2 = index[char2].second;

        if (row1 == row2)
        {
            int newCol1 = (col1 - 1 + 5) % 5, newCol2 = (col2 - 1 + 5) % 5;
            decrypted += table[row1][newCol1], decrypted += table[row2][newCol2];
        }
        else if (col1 == col2)
        {
            int newRow1 = (row1 - 1 + 5) % 5, newRow2 = (row2 - 1 + 5) % 5;
            decrypted += table[newRow1][col1], decrypted += table[newRow2][col2];
        }
        else
        {
            int newCol1 = col2, newCol2 = col1;
            decrypted += table[row1][newCol1], decrypted += table[row2][newCol2];
        }
    }
    return decrypted;
}
int main()
{
    cin >> keyword >> text;
    cout << "Key: " << keyword << "\n";
    tableGen(keyword);
    string cipherText = encryption(text);
    cout << "Cipher Text: " << cipherText << "\n";
    string plainText = decryption(cipherText);
    cout << "Plain Text: " << plainText << "\n";
}
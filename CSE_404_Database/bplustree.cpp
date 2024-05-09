#include <bits/stdc++.h>
using namespace std;

int order, key, hopsize = 0;
struct node
{
    int keyQuantity;
    bool isLeaf;
    string *word, *meaning;
    node *parentNode, *nextNode;
    node **childNodePointers;
};
node *root;

node *createNewNode();
void createNewRoot(node *newRoot, string word, node *leftchild, node *rightchild);
node *searchPosition(node *currentnode, string word);
void addWithParent(node *parent, string word, node *rightchild);
void moveUp(node *parent, string word, node *leftchild, node *rightchild);
void addToLeaf(string word, string meaning);
bool buildTree();
void searchMeaning();

node *createNewNode()
{
    node *newnode = new node();

    newnode->keyQuantity = 0;
    newnode->isLeaf = true;
    newnode->word = new string[order];
    newnode->meaning = new string[order];
    newnode->parentNode = NULL;
    newnode->nextNode = NULL;
    newnode->childNodePointers = new node *[order + 1];
    for (int i = 0; i <= order; i++)
        newnode->childNodePointers[i] = nullptr;

    return newnode;
}

void createNewRoot(node *newRoot, string word, node *leftchild, node *rightchild)
{
    newRoot = createNewNode();
    newRoot->isLeaf = false;
    newRoot->word[0] = word;
    newRoot->keyQuantity++;
    newRoot->childNodePointers[0] = leftchild;
    newRoot->childNodePointers[1] = rightchild;
    leftchild->parentNode = newRoot;
    rightchild->parentNode = newRoot;
    root = newRoot;
}

node *searchPosition(node *currentnode, string word)
{
    while (currentnode->isLeaf == false)
    {
        int targetNode;
        for (targetNode = 0; targetNode < currentnode->keyQuantity; targetNode++)
        {
            if (word < currentnode->word[targetNode])
                break;
        }

        currentnode = currentnode->childNodePointers[targetNode];
        hopsize++;
        //     cout<<hopsize<<"\n";
        // cout << currentnode->word[0] << "\n";
    }

    return currentnode;
}
node *path(node *currentnode, string word)
{
    hopsize = 0;
    while (currentnode->isLeaf == false)
    {
        int targetNode;
        ofstream file;
        file.open("path.txt", ios::app);
        file << hopsize + 1 << " : " << currentnode->word[0] << "\n";
        file.close();
        for (targetNode = 0; targetNode < currentnode->keyQuantity; targetNode++)
        {
            if (word < currentnode->word[targetNode])
                break;
        }

        currentnode = currentnode->childNodePointers[targetNode];

        hopsize++;
    }

    return currentnode;
}
void addWithParent(node *parent, string word, node *rightchild)

{
    int keyIndex = parent->keyQuantity;
    int newInsertIndex;
    if (keyIndex > 0)
    {
        for (newInsertIndex = keyIndex - 1; newInsertIndex >= 0; newInsertIndex--)
        {
            if (word < parent->word[newInsertIndex])
            {
                parent->word[newInsertIndex + 1] = parent->word[newInsertIndex];
                parent->childNodePointers[newInsertIndex + 2] = parent->childNodePointers[newInsertIndex + 1];
            }
            else
                break;
        }
        newInsertIndex++;
    }
    else
        newInsertIndex = 0;
    parent->word[newInsertIndex] = word;
    parent->childNodePointers[newInsertIndex + 1] = rightchild;
    parent->keyQuantity++;
}

void moveUp(node *parent, string word, node *leftchild, node *rightchild)
{
    if (parent == NULL)
    {
        createNewRoot(parent, word, leftchild, rightchild);
        return;
    }
    rightchild->parentNode = parent;
    addWithParent(parent, word, rightchild);

    if (parent->keyQuantity == order)
    {
        // 1 ta beshi hoye gese, so split korte hbe
        node *splittedNewNode = createNewNode();
        splittedNewNode->isLeaf = false;
        int count = parent->keyQuantity, j = 0, index;
        // left biased
        for (index = count - count / 2; index < order; index++)
        {
            splittedNewNode->word[j] = parent->word[index];

            if (j == 0)
            {
                splittedNewNode->childNodePointers[0] = parent->childNodePointers[index];
                splittedNewNode->childNodePointers[0]->parentNode = splittedNewNode;
            }
            splittedNewNode->childNodePointers[j + 1] = parent->childNodePointers[index + 1];
            splittedNewNode->childNodePointers[j + 1]->parentNode = splittedNewNode;

            j++;
        }

        parent->keyQuantity -= (index / 2 + 1);
        splittedNewNode->keyQuantity = index / 2;

        moveUp(parent->parentNode, parent->word[parent->keyQuantity], parent, splittedNewNode);
    }
}
void addToLeaf(string word, string meaning)
{
    node *leaf = searchPosition(root, word);

    int keyIndex = leaf->keyQuantity;
    int newInsertIndex;
    if (keyIndex > 0)
    {
        for (newInsertIndex = keyIndex - 1; newInsertIndex >= 0; newInsertIndex--)
        {
            if (word < leaf->word[newInsertIndex])
            {
                leaf->word[newInsertIndex + 1] = leaf->word[newInsertIndex];
                leaf->meaning[newInsertIndex + 1] = leaf->meaning[newInsertIndex];
            }
            else
                break;
        }
        newInsertIndex++;
    }
    else
        newInsertIndex = 0;
    leaf->word[newInsertIndex] = word;
    leaf->meaning[newInsertIndex] = meaning;
    leaf->keyQuantity++;

    if (leaf->keyQuantity == order)
    {
        // 1 ta beshi hoye gese, so split korte hbe
        node *splittedNewNode = createNewNode();
        int count = leaf->keyQuantity, j = 0, index;
        // left biased
        for (index = count - count / 2; index < order; index++)
        {
            splittedNewNode->word[j] = leaf->word[index];
            splittedNewNode->meaning[j] = leaf->meaning[index];
            j++;
        }

        leaf->keyQuantity -= order / 2;
        splittedNewNode->keyQuantity = order / 2;
        splittedNewNode->nextNode = leaf->nextNode;
        leaf->nextNode = splittedNewNode;

        moveUp(leaf->parentNode, splittedNewNode->word[0], leaf, splittedNewNode);
    }
}

bool buildTree()
{
    string word, meaning;
    root = createNewNode();

    ifstream file;
    file.open("words.txt");
    if (!file)
    {
        printf("file not found\n");
        return false;
    }
    else
    {
        while (file >> word)
        {
            getline(file, meaning);
            addToLeaf(word, meaning);
        }
        file.close();
    }
    return true;
}

void searchMeaning()
{
    int i;
    cout << "\nEnter target word:\n";
    string targetWord;
    cin >> targetWord;

    hopsize = 0;
    node *leaf = searchPosition(root, targetWord);
    path(root, targetWord);
    for (i = 0; i < leaf->keyQuantity; i++)
    {
        if (leaf->word[i] == targetWord)
            break;
    }
    freopen("ans1.txt", "w", stdout);
    if (i == leaf->keyQuantity)
        puts("sorry. no word found");
    else
    {
        cout << targetWord << " => " << leaf->meaning[i] << "\n";
    }
    cout << "hop Size " << hopsize << "\n";
}

int main()
{
    cout << "Enter order: ";
    cin >> order;
    key = order - 1;
    ofstream file;
    file.open("path.txt");
    file << "";
    file.close();
    if (buildTree())
        cout << "tree built successfully";
    else
        cout << "sorry tree couldn't built";

    searchMeaning();
}
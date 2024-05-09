 // balancing in the parent node
    if (parent->totalKeys == numberOfPointer)
    {
        Node *secondNode = createNewNode(); // second node
        secondNode->isLeaf = false;

        int mark = parent->totalKeys, j = 0;

        for (int i = mark - (numberOfPointer / 2); i < numberOfPointer; i++)
        {
            secondNode->english[j] = parent->english[i];
            if (j == 0)
            {
                secondNode->nodePointers[0] = parent->nodePointers[i]; // look up later
                secondNode->nodePointers[0]->parentNode = secondNode;
            }

            secondNode->nodePointers[j + 1] = parent->nodePointers[i + 1];
            secondNode->nodePointers[j + 1]->parentNode = secondNode;
            j++;
        }

        parent->totalKeys -= (mark / 2 + 1);
        secondNode->totalKeys = (mark / 2);

        // move up recursively
        moveUp(parent->parentNode, parent->english[parent->totalKeys], parent, secondNode);
    }
#include <bits/stdc++.h>
using namespace std;

int processQuantity, resourseQuantity;
const int mx = 10000;
int allocation[mx][mx], maxNeed[mx][mx], available[mx], remainNeed[mx][mx];

bool safetyAlgo()
{
    int i, j, round;
    int available2[mx];
    for (j = 1; j <= resourseQuantity; j++)
        available2[j] = available[j];
    vector<int> safeSeq;
    for (i = 1; i <= processQuantity; i++)
    {
        for (j = 1; j <= resourseQuantity; j++)
        {
            remainNeed[i][j] = maxNeed[i][j] - allocation[i][j];
            //  cout << remainNeed[i][j] << " ";
        }
        //   cout << "\n";
    }

    bool done[processQuantity];

    for (round = 1; round <= processQuantity; round++)
    {
        for (i = 1; i <= processQuantity; i++)
        {
            if (!done[i])
            {
                bool pos = true;
                for (j = 1; j <= resourseQuantity; j++)
                {
                    if (available2[j] < remainNeed[i][j])
                    {
                        pos = false;
                        break;
                    }
                }
                if (pos)
                {
                    done[i] = true;
                    for (j = 1; j <= resourseQuantity; j++)
                    {
                        available2[j] += allocation[i][j];
                    }
                    safeSeq.push_back(i);
                }
            }
        }
    }
    cout << "\n";
    for (auto x : safeSeq)
        cout << x << " ";
    cout << "\n";
}

bool resourceReqAlgo(int processNum, int req[])
{
    int i, j;
    bool check1 = true, check2 = true;
    for (i = 1; i <= resourseQuantity; i++)
    {
        if (maxNeed[processNum][i] < req[i])
        {
            check1 = false;
            break;
        }
    }
    if (!check1)
    {
        cout << "Extra request\n";
        return false;
    }

    for (i = 1; i <= resourseQuantity; i++)
    {
        if (available[i] < req[i])
        {
            check2 = false;
            break;
        }
    }
    if (!check2)
    {
        cout << "Not available\n";
        return false;
    }

    for (i = 1; i <= resourseQuantity; i++)
    {
        allocation[processNum][i] += req[i];
        //  cout << allocation[processNum][i] << " ";
    }
    cout << "\n";
    for (i = 1; i <= resourseQuantity; i++)
    {
        available[i] -= req[i];
        //  cout << available[i] << " ";
    }
    cout << "\n";
    for (i = 1; i <= resourseQuantity; i++)
    {
        remainNeed[processNum][i] -= req[i];
        //   cout << remainNeed[processNum][i] << " ";
    }
    //  cout << "\n";
}
int main()
{
    int i, j;
    //   cout << "Enter number of process: ";
    cin >> processQuantity;
    //  cout << "Enter number of resources: ";
    cin >> resourseQuantity;
    // int allocation[processQuantity + 1][resourseQuantity + 1], maxNeed[processQuantity + 1][resourseQuantity + 1], remainNeed[processQuantity + 1][resourseQuantity + 1];
    // int available[resourseQuantity + 1];

    for (i = 1; i <= processQuantity; i++)
    {
        for (j = 1; j <= resourseQuantity; j++)
        {
            //  cout << "Enter allocation of resource " << j << " for process " << i << " : ";
            cin >> allocation[i][j];
        }
    }

    for (i = 1; i <= processQuantity; i++)
    {
        for (j = 1; j <= resourseQuantity; j++)
        {
            //   cout << "Enter Max need of resource " << j << " for process " << i << " : ";
            cin >> maxNeed[i][j];
        }
    }

    // cout << "Enter initial availabilty of resources:\n";
    for (i = 1; i <= resourseQuantity; i++)
    {
        cin >> available[i];
    }
    safetyAlgo();

    int reqProcess;
    cin >> reqProcess;
    int curReq[resourseQuantity + 1];
    for (i = 1; i <= resourseQuantity; i++)
        cin >> curReq[i];
    resourceReqAlgo(reqProcess, curReq);
    safetyAlgo();

    // 336 page
}
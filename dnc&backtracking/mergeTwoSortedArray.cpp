#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[5] = {20, 40, 60, 80, 100};
    int arr2[4] = {10, 30, 50, 70};
    int i = 0, j = 0;
    vector<int> result;
    while (i < 5 && j < 4)
    {
        if (arr1[i] < arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
        }
        else
        {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (j < 4)
    {
        result.push_back(arr2[j]);
        j++;
    }

    while (i < 5)
    {
        result.push_back(arr1[i]);
        i++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}
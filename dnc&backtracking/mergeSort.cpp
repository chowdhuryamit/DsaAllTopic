#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    // vector<int> leftArr;
    // vector<int> rightArr;
    // for (int i = start; i <= mid; i++)
    // {
    //     leftArr.push_back(arr[i]);
    // }
    // for (int i = mid + 1; i <=end; i++)
    // {
    //     rightArr.push_back(arr[i]);
    // }

    // int left = 0;
    // int right = 0;
    // while (left < leftArr.size() && right < rightArr.size())
    // {
    //     if (leftArr[left] < rightArr[right])
    //     {
    //         arr[start] = leftArr[left];
    //         left++;
    //         start++;
    //     }
    //     else
    //     {
    //         arr[start] = rightArr[right];
    //         right++;
    //         start++;
    //     }
    // }
    // while (left < leftArr.size())
    // {
    //     arr[start] = leftArr[left];
    //     left++;
    //     start++;
    // }
    // while (right < rightArr.size())
    // {
    //     arr[start] = rightArr[right];
    //     right++;
    //     start++;
    // }

    vector<int>v;
    int i=start;
    int j=mid+1;
    while(i<=mid and j<=end){
      if (arr[i]<arr[j])
      {
        v.push_back(arr[i]);
        i++;
      }
      else{
        v.push_back(arr[j]);
        j++;
      }
    }
    while (i<=mid)
    {
        v.push_back(arr[i]);
        i++;
    }
    while (j<=end)
    {
        v.push_back(arr[j]);
        j++;
    }
    for (int i = 0,j=start; i < v.size(),j<=end; i++,j++)
    {
       arr[j]=v[i];
    }
    
}

void mergeSort(int arr[], int start, int end)
{
    // base case
    if(start>=end){
        return;
    }
    int mid = (end + start) / 2;
    // left divide
    mergeSort(arr, start, mid);
    // right divide
    mergeSort(arr, mid + 1, end);
    // merge
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {10, 50, 30, 70, 20,885,31,075,4523};
    int arrSize = 9;
    int start = 0;
    int end = arrSize - 1;
    mergeSort(arr, start, end);

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
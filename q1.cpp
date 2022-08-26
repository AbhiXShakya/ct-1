// Name : Abhishek Shakya
// Roll No : 2010991793
// Set - 5
// Question Number : 1

#include <bits/stdc++.h>
using namespace std;

// function to find the length of longest subarray having sum k
int lenOfLongSubarr(int arr[],
                    int n,
                    int k)
{

    // unordered_map 'umap' implemented as hash table
    unordered_map<int, int> umap;
    int sum = 0, maxLen = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {

        // accumulate the sum
        sum += arr[i];

        // when subarray starts from index 0
        if (sum == k)
            maxLen = i + 1;

        // make an entry for 'sum' if it is not present in 'ummap'
        if (umap.find(sum) == umap.end())
            umap[sum] = i;

        // check if 'sum-k' is present in 'umap' or not
        if (umap.find(sum - k) != umap.end())
        {

            // update maxLength
            if (maxLen < (i - umap[sum - k]))
                maxLen = i - umap[sum - k];
        }
    }

    // required maximum length
    return maxLen;
}

int main()
{
    int n;
    cout << "Enter the Number of Elements in Array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter Elements of the Array Saperated by Space: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the Target: ";
    cin >> k;
    int res;

    try
    {
        res = lenOfLongSubarr(arr, n, k);
    }
    catch (exception e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << "The longest subarray length is " << res;

    return 0;
}
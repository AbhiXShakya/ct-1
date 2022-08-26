// Name : Abhishek Shakya
// Roll No : 2010991793
// Set - 5
// Question Number : 2

#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array which have sum 0
vector<pair<int, int>> findTheSubArray(int arr[], int n)
{
    // create map
    unordered_map<int, vector<int>> map;

    // vector of pairs to store subarray starting & ending index
    vector<pair<int, int>> out;

    // maintains sum of elements
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to the sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // No else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}

// function to print all subarrays with sum 0
void print(vector<pair<int, int>> out, int arr[])
{
    for (auto it = out.begin(); it != out.end(); it++)
    {
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Main Function
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

    vector<pair<int, int>> out;

    try
    {
        out = findTheSubArray(arr, n);
    }
    catch (exception e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // if we didn’t find any subarray with 0 sum, then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out, arr);

    return 0;
}
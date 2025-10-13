#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>

using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetweeen = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) / dist == numberInBetweeen * dist)
        {
            numberInBetweeen--;
        }
        cnt += numberInBetweeen;
    }
    return cnt;
}

long double minimizeMaximunDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        {
            low = mid;
        }

        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimizeMaximunDistance(arr, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}

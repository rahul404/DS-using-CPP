/*
    This code returns an index whose value is freater than or equal to x in log n complexity
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<pair<int, int> > Vec;

Vec v;

void Preprocess(vector<int>& input)
{
    int max = input[0];
    v.push_back(make_pair(0, input[0]));
    for (int i = 1; i < input.size(); ++i)
    {
        if (input[i] > max) {
            max = input[i];
            v.push_back(make_pair(i, input[i]));
        }
    }
    /*
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    */
}

int FindGreaterIndex(int n)
{
    int low = 0, high = v.size() - 1;
    int mid;
    while (low < high - 1)
    {
        mid = low + (high - low) / 2;
        if (v[mid].second >= n) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (v[low].second >= n) {
        return v[low].second;
    } else if (v[high].second >= n) {
        return v[high].second;
    }
    return -1;
}


int main()
{
    vector<int> input;
    input.push_back(2);
    input.push_back(10);
    input.push_back(5);
    input.push_back(6);
    input.push_back(80);
    Preprocess(input);
    int n;
    while (cin >> n) {
        cout << FindGreaterIndex(n) << endl;
    }
}
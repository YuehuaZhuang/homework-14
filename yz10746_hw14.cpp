// yz10746_hw14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> compare(vector<int>vec, int lowleft, int highleft, int highright) {
    int min = vec[lowleft];
    int max = vec[lowleft];
    for (int i = lowleft;i <= highleft;i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    for (int i = highleft + 1;i <= highright;i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return { min, max };
}

vector<int> findMinMax(vector<int> vec, int low, int high) {
    if (low == high) {
        return { vec[low] ,vec[high] };
    }
    else if (high - low == 1) {
        if (vec[low] <= vec[high]) {
            return { vec[low] ,vec[high] };
        }
        else {
            return { vec[high] ,vec[low] };
        }
    }
    else {
        int midInd = (low+high) / 2;
        vector<int> leftMinMax = findMinMax(vec, low, midInd);
        vector<int> rightMinMax = findMinMax(vec, midInd + 1, high);
        vector<int> combined = compare(vec, low, midInd, high);
        if (leftMinMax[0] < rightMinMax[0]) {
            combined[0] = leftMinMax[0];
        }
        else {
            combined[0] = rightMinMax[0];
        }
        if (leftMinMax[1] > rightMinMax[1]) {
            combined[1] = leftMinMax[1];
        }
        else {
            combined[1] = rightMinMax[1];
        }
        return combined;
    }
}

void print(vector<int> vec) {
    cout << "The minimum element is " << vec[0] << endl;
    cout << "The maximum element is " << vec[1] << endl;  
}

int main()
{
    cout << "When vector has only one element:" << endl;
    vector<int> list1 = { 1 };
    vector<int> result1 = findMinMax(list1, 0,list1.size()-1);
    print(result1);

    cout << "When vector has two elements:" << endl;
    vector<int> list2 = { 2,1 };
    vector<int> result2 = findMinMax(list2, 0, list2.size()-1);
    print(result2);

    cout << "When vector has more than two elements, and the vector size is even:" << endl;
    vector<int> list3 = { 3, 5, 7, 8, 1, 22, 55555, 0 };
    vector<int> result3 = findMinMax(list3, 0, list3.size()-1);
    print(result3);

    cout << "When vector has more than two elements, and the vector size is odd:" << endl;
    vector<int> list4 = { 6, 333, 476,9,43 };
    vector<int> result4 = findMinMax(list4, 0, list4.size()-1);
    print(result4);
}


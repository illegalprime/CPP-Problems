#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>

using namespace std;

class Sorts
{
private:
    static vector<int>& subVector(vector<int>& v, int start, int end);
    static vector<int>& merge    (vector<int>& v1, vector<int>& v2);
    static inline void swap(std::vector<int>& v, int i, int j, int& temp);
public:
    Sorts();
    static vector<int>& mergeSort(vector<int>& data);
    static void printVector(vector<int>& data);
    static void quickSort(std::vector<int>& v, int start, int end);
    static void quickSort(std::vector<int>& v);
};

#endif

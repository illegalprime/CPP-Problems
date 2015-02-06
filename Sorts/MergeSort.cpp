#include "Sorts.hpp"


int main(int argc, char** argv) {

    int data[] = {332, 5, 6, -3, 8, 97, 0, -50, -800};;
    vector<int> vData(data, data + (sizeof(data) / sizeof(int)));

    cout << "Sorting (Merge Sort): " << endl;
    Sorts::printVector(Sorts::mergeSort(vData));
    return 0;
}

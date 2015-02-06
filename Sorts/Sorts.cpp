#include "Sorts.hpp"

void Sorts::quickSort(std::vector<int>& v, int start, int end) {
    printVector(v);
    if (start == end) {
        return;
    }

    const int pivot = end;
    int i = 0, j = end - 1;
    int temp;

    while (i < j) {
        if (v[i] <= v[pivot]) {
            ++i;
            continue;
        }
        if (v[j] > v[pivot]) {
            --j;
            continue;
        }

        swap(v, i, j, temp);
    }
    if (v[j] > v[pivot]) {
        swap(v, j, pivot, temp);
    }

    quickSort(v, 0,     j);
    quickSort(v, j + 1, end);
}

void Sorts::quickSort(std::vector<int>& v) {
    quickSort(v, 0, v.size() - 1);
}

vector<int>& Sorts::mergeSort(vector<int>& sortable) {
    if (sortable.size() == 1) {
        return *( new std::vector<int>(sortable.begin(), sortable.end()) );
    }

    vector<int>& firstHalf   = subVector(sortable, 0, sortable.size() / 2);// In FS
    vector<int>& lastHalf    = subVector(sortable,    sortable.size() / 2, sortable.size()); // In FS
    vector<int>& firstSorted = mergeSort(firstHalf);            // In Free Space
    vector<int>& lastSorted  = mergeSort(lastHalf);             // In Free Space
    vector<int>& merged      = merge(firstSorted, lastSorted);  // In Free Space

    delete &firstHalf;
    delete &lastHalf;
    delete &firstSorted;
    delete &lastSorted;

    return merged;
}

vector<int>& Sorts::merge(vector<int>& a, vector<int>& b) {
    vector<int>& merged = *( new vector<int>(a.size() + b.size()) );
    int a_i = 0, b_i = 0, m_i = 0;

    for (; a_i < a.size() && b_i < b.size(); ++m_i) {
        if (a[a_i] < b[b_i]) {
            merged[m_i] = a[a_i];
            ++a_i;
        }
        else {
            merged[m_i] = b[b_i];
            ++b_i;
        }
    }

    if (a_i != a.size()) {
        for (; m_i < merged.size(); ++m_i, ++a_i) {
            merged[m_i] = a[a_i];
        }
    }
    else if (b_i != b.size()) {
        for (; m_i < merged.size(); ++m_i, ++b_i) {
            merged[m_i] = b[b_i];
        }
    }

    return merged;
}

vector<int>& Sorts::subVector(vector<int>& v, int start, int end) {
    if (end - start == 0) {
        ++end;
    }

    vector<int>& subv = *( new vector<int>(end - start) );

    for (int i = start, j = 0; i < end; ++i, ++j) { subv[j] = v[i]; }

    return subv;
}

void Sorts::printVector(vector<int>& data) {
    cout << "Vector: [ ";
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl;
}

inline void Sorts::swap(std::vector<int>& v, int i, int j, int& temp) {
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

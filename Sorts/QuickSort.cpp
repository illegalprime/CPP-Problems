#include "Sorts.hpp"

int main(int argc, char** argv) {

  int sortable[] = {332, 5, 6, -3, 8, 97, 0, -50, -800};
  std::vector<int> v(sortable, sortable + sizeof(sortable)/sizeof(int));

  Sorts::quickSort(v);
  Sorts::printVector(v);

  return 0;
}

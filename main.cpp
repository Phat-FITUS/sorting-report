#include "Resources/external_lib.h"
#include "Algorithms/CountingSort.cpp"
#include "Algorithms/MergeSort.cpp"
#include "Algorithms/QuickSort.cpp"
#include "Algorithms/FlashSort.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    int compare, time;

    // CountingSort sort;
    FlashSort sort;
    sort.Run(time, compare);

    cout << "Result stored in output.txt\n";
    cout << "The algorithm executed in " << time << " miliseconds with " << compare << " comparisons\n";

    return 0;
}
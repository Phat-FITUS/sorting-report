#include "Resources/external_lib.h"
#include "Algorithms/CountingSort.cpp"
#include "Algorithms/MergeSort.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    int compare, time;

    // CountingSort sort;
    MergeSort sort;
    sort.Run(time, compare);

    cout << "Result stored in output.txt\n";
    cout << "The algorithm executed in " << time << " miliseconds with " << compare << " comparisons\n";

    return 0;
}
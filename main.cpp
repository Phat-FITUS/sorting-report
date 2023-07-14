#include "Resources/external_lib.h"
#include "Algorithms/Sort.h"
using namespace std;

void Test() {
    int compare, time;

    FlashSort sort;
    sort.Run(time, compare);

    cout << "Result stored in output.txt\n";
    cout << "The algorithm executed in " << time << " miliseconds with " << compare << " comparisons\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1 && strcmp(argv[1], "test")) {
        Test();
    }

    return 0;
}
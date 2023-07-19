#include "Resources/external_lib.h"
#include "Algorithms/Sort.h"
#include "Modes/Mode.h"
using namespace std;

void Test() {
    ull compare, time;

    FlashSort sort;
    sort.Run(time, compare);

    cout << "Result stored in output.txt\n";
    cout << "The algorithm executed in " << time << " miliseconds with " << compare << " comparisons\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-test") == 0) {
            Test();
            return 0;
        }

        if (strcmp(argv[1], "--help") == 0) {
            return 0;
        }

        Mode* mode = NULL;
        if (strcmp(argv[1], "-a") == 0){
            mode = new Algorithm();
        }
        if (strcmp(argv[1], "-c") == 0){
            mode = new Comparison();
        }
        mode->Run(argc, argv);
        delete mode;
    } else {
        cout << "Too few argument. Using tag `--help` for instruction.\n";
    }

    return 0;
}
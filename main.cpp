#include "Resources/external_lib.h"
#include "Algorithms/Sort.h"
#include "Modes/Mode.h"
using namespace std;

void PrintTitle(int option) {
    switch (option) {
        case GenerationType::Random:
            cout << "\nRandom Data type:\n**********************\n\n";
            break;
        case GenerationType::Sorted:
            cout << "\nSorted Data type:\n**********************\n\n";
            break;
        case GenerationType::NearlySorted:
            cout << "\nNearly Sorted Data type:\n**********************\n\n";
            break;
        case GenerationType::Reverse:
            cout << "\nReverse Data type:\n**********************\n\n";
            break;
        default:
            cout << "\nData type option unknown! Use -help for more information!\n";
            return;
    }
}

void SortMeasure(Sort* sort, const char sortName[]) {
    ull compare, time;
    sort->Run(time, compare);

    cout << sortName << " Sort:\nTime: " << time << "\nComparison: " << compare << "\n\n";
}

void Test(char option[]) {
    PrintTitle(stoi(option));

    int dataSize[] = {10000, 30000, 50000, 100000, 300000, 500000};

    for (int& size: dataSize) {
        GenerateData(size, stoi(option), "testing.txt");
        cout << "SIZE: " << size << "\n----------------------------------\n";

        SortMeasure(new BubbleSort("testing.txt"), "Bubble");
        SortMeasure(new CountingSort("testing.txt"), "Counting");
        SortMeasure(new FlashSort("testing.txt"), "Flash");
        SortMeasure(new HeapSort("testing.txt"), "Heap");
        SortMeasure(new InsertionSort("testing.txt"), "Insertion");
        SortMeasure(new MergeSort("testing.txt"), "Merge");
        SortMeasure(new QuickSort("testing.txt"), "Quick");
        SortMeasure(new RadixSort("testing.txt"), "Radix");
        SortMeasure(new SelectionSort("testing.txt"), "Selection");
        SortMeasure(new ShakerSort("testing.txt"), "Shaker");
        SortMeasure(new ShellSort("testing.txt"), "Shell");
    }

}

void help() {
    cout << "For testing purpose: [Execution File] -test [Data order]\n0: Random \n1: Sorted\n2: Nearly Sorted\n3: Reverse\n";
    cout << "To run a sorting algorithm on the given input data:\n[Execution file] -a [Algorithm] [Given input] [Output parameter(s)]\n";
    cout << "To run a sorting algorithm on the data generated automatically with specified size and order:\n[Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n";
    cout << "To run a sorting algorithm on ALL data arrangements of a specified size:\n[Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n";
    cout << "To run two sorting algorithms on the given input:\n[Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]\n";
    cout << "To run two sorting algorithms on the data generated automatically:\n[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-test") == 0) {
            Test(argv[2]);
            return 0;
        }

        if (strcmp(argv[1], "--help") == 0) {
            help();
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
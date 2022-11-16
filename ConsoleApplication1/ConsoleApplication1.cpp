#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, int size, int min, int max, int i) {
    if (i < size) {
        a[i] = min + rand() % (max - min + 1);
        Create(a, size, min, max, i + 1);
    }
}

void Print(int* a, int size, int i) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

void Task1_1(int* a, int size, int& n, int minAbs, int i) {
    if (i < size) {
        if (abs(a[i + 1]) < minAbs) {
            minAbs = abs(a[i + 1]);
            n = i + 1;
        }
        Task1_1(a, size, n, minAbs, i + 1);
    }
}

int Task1_2subSet(int* a, int size, int& index, int i) {
    if (i < size) {
        if (a[i] < 0) {
            index = i;
            return index;
        }
        return Task1_2subSet(a, size, index, i + 1);
    }
}

void Task1_2Complete(int* a, int size, int index, int& sum) {
    if (index < size) {
        sum += abs(a[index]);
        Task1_2Complete(a, size, index + 1, sum);
    }
}

int Task1_3(int* a, int size, int ld, int rd, int count, int i) {
    if (i < size - count) {
        if (ld <= a[i] && a[i] <= rd) {
            for (int j = i; j < size - count - 1; j++) {
                a[j] = a[j + 1];
            }
            a[size - count - 1] = 0;
            i--;
            count++;
        }
        return Task1_3(a, size, ld, rd, count, i + 1);
    }
    return count;
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    cout << "size = "; cin >> size;
    int min = -10; int max = 10;
    int a[size];
    int task1Index = 0;
    int task2Index = 0;
    int sum = 0;

    Create(a, size, min, max, 0);
    Print(a, size, 0);

    int minAbs = a[0];
    Task1_1(a, size, task1Index, minAbs, 0);
    cout << "index minimal Abs = " << task1Index << endl;

    Task1_2subSet(a, size, task2Index, 0);
    Task1_2Complete(a, size, task2Index, sum);
    cout << "sum from the first negative = " << sum << endl;

    int ld, rd;
    cout << "enter min value of interval: "; cin >> ld;
    cout << "enter max value of interval: "; cin >> rd;
    Task1_3(a, size, ld, rd, 0, 0);
    Print(a, size, 0);

    return 0;
}
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Person {
    char name[25]; // имя
    int height;    // рост
    int weight;    // вес
} B;

int answer;
long size_pred;

int main() {
    ifstream fR;
    ofstream fA;
    setlocale(LC_ALL, "rus");
    const char* nameR = "C:\\Users\\пк\\OneDrive\\Документы\\KubSU\\comp nets\\Infile.txt";
    const char* nameA = "C:\\Users\\пк\\OneDrive\\Документы\\KubSU\\comp nets\\Outfile.txt";

    cout << "Сервер работает..." << endl;

    fR.open(nameR, ios::binary);
    fR.seekg(0, ios::end);
    size_pred = fR.tellg(); // Запоминаем начальную позицию в файле запросов
    fR.close();

    while (true) {
        fR.open(nameR, ios::binary);
        fR.seekg(0, ios::end);

        while (size_pred >= fR.tellg()) {
            Sleep(100);
            fR.seekg(0, ios::end);
        }

        fR.seekg(size_pred, ios::beg);
        fR.read((char*)&B, sizeof(B));
        size_pred = fR.tellg();
        fR.close();

        double IMT = (double)B.weight / ((0.01 * B.height) * (0.01 * B.height));
        if (IMT < 18.5) answer = 0;
        else if (IMT < 25) answer = 1;
        else answer = 2;

        fA.open(nameA, ios::binary | ios::app);
        fA.write((char*)&IMT, sizeof(IMT)); // Записываем IMT
        fA.write((char*)&answer, sizeof(answer)); // Записываем категорию
        fA.close();
    }
}

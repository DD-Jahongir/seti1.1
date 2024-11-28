#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Person {
    char name[25];
    int height;
    int weight;
} A;

int main() {
    setlocale(LC_ALL, "rus");
    const char* nameR = "C:\\Users\\пк\\OneDrive\\Документы\\KubSU\\comp nets\\Infile.txt";
    const char* nameA = "C:\\Users\\пк\\OneDrive\\Документы\\KubSU\\comp nets\\Outfile.txt";
    ofstream f_req;
    ifstream f_ans;
    long pred_size;
    int answer;
    double IMT;

    while (true) {
        cout << "Запрос: фамилия, рост (в см), вес (в кг): " << endl;
        cin >> A.name >> A.height >> A.weight;
        f_req.open(nameR, ios::app | ios::binary);
        f_req.write((char*)&A, sizeof(A));
        f_req.close();

        f_ans.open(nameA, ios::binary);
        f_ans.seekg(0, ios::end);
        pred_size = f_ans.tellg();
        while (pred_size >= f_ans.tellg()) {
            Sleep(100);
            f_ans.seekg(0, ios::end);
        }
        f_ans.seekg(pred_size, ios::beg);
        f_ans.read((char*)&IMT, sizeof(IMT)); // Чтение значения IMT
        f_ans.read((char*)&answer, sizeof(answer)); // Чтение категории

        f_ans.close();

        cout << "Ваш ИМТ: " << IMT << endl;
        switch (answer) {
        case 0: cout << "Недостаток веса\n"; break;
        case 1: cout << "Норма\n"; break;
        case 2: cout << "Избыточный вес\n"; break;
        }
    }
}

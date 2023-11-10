#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream ifs("input.txt");
    std::string str((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    string str1;
    char arr[] = { 'а', 'б', 'в','г','д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
    int* frequency = new int[33];
    int* frequencyCopy = new int[33];
    int* topFive = new int[5];



    for (int i = 0; i < 33; i++) {
        frequency[i] = 0;
    }

    for (int i = 0; i < 5; i++) {
        topFive[i] = 0;
    }

    //tolower
    str1 = str;
    transform(str1.begin(), str1.end(), str1.begin(),
        [](unsigned char c) { return std::tolower(c); });

    cout << endl;
    for (int i = 0; i < 33; i++) {

        frequency[i] = std::count(str1.begin(), str1.end(), arr[i]);
        cout << frequency[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < 33; i++) {
        frequencyCopy[i] = frequency[i];
    }

    sort(frequencyCopy, frequencyCopy + 33, greater<int>());
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 33; j++) {

            if (frequency[j] == frequencyCopy[i] && i == 0) {
                topFive[i] = j;
                break;
            }
            if (frequency[j] == frequencyCopy[i] && j != topFive[0] && i == 1) {
                topFive[i] = j;
                break;
            }
            if (frequency[j] == frequencyCopy[i] && j != topFive[0] && j != topFive[1] && i == 2) {
                topFive[i] = j;
                break;
            }
            if (frequency[j] == frequencyCopy[i] && j != topFive[0] && j != topFive[1] && j != topFive[2] && i == 3) {
                topFive[i] = j;
                break;
            }
            if (frequency[j] == frequencyCopy[i] && j != topFive[0] && j != topFive[1] && j != topFive[2] && j != topFive[3] && i == 4) {
                topFive[i] = j;
                break;
            }
        }
    }
    cout << '\n';

    for (int i = 0; i < 5; i++) {
        cout << topFive[i] + 1 << ' ';
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[topFive[i]] << ' ';
    }
    cout << endl;

    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);

        if ((token.find(arr[topFive[0]]) != std::string::npos || token.find(toupper(arr[topFive[0]])) != std::string::npos) && (token.find(arr[topFive[1]]) != std::string::npos || token.find(toupper(arr[topFive[1]])) != std::string::npos) && (token.find(arr[topFive[2]]) != std::string::npos || token.find(toupper(arr[topFive[2]])) != std::string::npos) && (token.find(arr[topFive[3]]) != std::string::npos || token.find(toupper(arr[topFive[3]])) != std::string::npos) && (token.find(arr[topFive[4]]) != std::string::npos || token.find(toupper(arr[topFive[4]])) != std::string::npos)) {
            transform(token.begin(), token.end(), token.begin(),
                [](unsigned char c) { return std::toupper(c); });
            token = token + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
        }
        else {
            if ((token.find(arr[topFive[0]]) != std::string::npos || token.find(toupper(arr[topFive[0]])) != std::string::npos) && (token.find(arr[topFive[1]]) != std::string::npos || token.find(toupper(arr[topFive[1]])) != std::string::npos) && (token.find(arr[topFive[2]]) != std::string::npos || token.find(toupper(arr[topFive[2]])) != std::string::npos) && (token.find(arr[topFive[3]]) != std::string::npos || token.find(toupper(arr[topFive[3]])) != std::string::npos)) {
                transform(token.begin(), token.end(), token.begin(),
                    [](unsigned char c) { return std::toupper(c); });
                token = token + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ")";
            };
            if ((token.find(arr[topFive[0]]) != std::string::npos || token.find(toupper(arr[topFive[0]])) != std::string::npos) && (token.find(arr[topFive[1]]) != std::string::npos || token.find(toupper(arr[topFive[1]])) != std::string::npos) && (token.find(arr[topFive[3]]) != std::string::npos || token.find(toupper(arr[topFive[3]])) != std::string::npos) && (token.find(arr[topFive[4]]) != std::string::npos || token.find(toupper(arr[topFive[4]])) != std::string::npos)) {
                transform(token.begin(), token.end(), token.begin(),
                    [](unsigned char c) { return std::toupper(c); });
                token = token + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
            };
            if ((token.find(arr[topFive[0]]) != std::string::npos || token.find(toupper(arr[topFive[0]])) != std::string::npos) && (token.find(arr[topFive[2]]) != std::string::npos || token.find(toupper(arr[topFive[2]])) != std::string::npos) && (token.find(arr[topFive[3]]) != std::string::npos || token.find(toupper(arr[topFive[3]])) != std::string::npos) && (token.find(arr[topFive[4]]) != std::string::npos || token.find(toupper(arr[topFive[4]])) != std::string::npos)) {
                transform(token.begin(), token.end(), token.begin(),
                    [](unsigned char c) { return std::toupper(c); });
                token = token + "(" + arr[topFive[0]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
            };
            if ((token.find(arr[topFive[1]]) != std::string::npos || token.find(toupper(arr[topFive[1]])) != std::string::npos) && (token.find(arr[topFive[2]]) != std::string::npos || token.find(toupper(arr[topFive[2]])) != std::string::npos) && (token.find(arr[topFive[3]]) != std::string::npos || token.find(toupper(arr[topFive[3]])) != std::string::npos) && (token.find(arr[topFive[4]]) != std::string::npos || token.find(toupper(arr[topFive[4]])) != std::string::npos)) {
                transform(token.begin(), token.end(), token.begin(),
                    [](unsigned char c) { return std::toupper(c); });
                token = token + "(" + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
            };
            if ((token.find(arr[topFive[0]]) != std::string::npos || token.find(toupper(arr[topFive[0]])) != std::string::npos) && (token.find(arr[topFive[1]]) != std::string::npos || token.find(toupper(arr[topFive[1]])) != std::string::npos) && (token.find(arr[topFive[2]]) != std::string::npos || token.find(toupper(arr[topFive[2]])) != std::string::npos) && (token.find(arr[topFive[4]]) != std::string::npos || token.find(toupper(arr[topFive[4]])) != std::string::npos)) {
                transform(token.begin(), token.end(), token.begin(),
                    [](unsigned char c) { return std::toupper(c); });
                token = token + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[4]] + ")";
            }
        }



        str.erase(0, pos + delimiter.length());
        std::ofstream vmdelet_out;                                   //создаем поток 
        vmdelet_out.open("output.txt", std::ios::app);  // открываем файл для записи в конец
        vmdelet_out << token + ' ';                                  // сама запись
        vmdelet_out.close();
        // std::cout << token << std::endl;
    }
    //checking for str
    if ((str.find(arr[topFive[0]]) != std::string::npos || str.find(toupper(arr[topFive[0]])) != std::string::npos) && (str.find(arr[topFive[1]]) != std::string::npos || str.find(toupper(arr[topFive[1]])) != std::string::npos) && (str.find(arr[topFive[2]]) != std::string::npos || str.find(toupper(arr[topFive[2]])) != std::string::npos) && (str.find(arr[topFive[3]]) != std::string::npos || str.find(toupper(arr[topFive[3]])) != std::string::npos) && (str.find(arr[topFive[4]]) != std::string::npos || str.find(toupper(arr[topFive[4]])) != std::string::npos)) {
        transform(str.begin(), str.end(), str.begin(),
            [](unsigned char c) { return std::toupper(c); });
        str = str + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
    }
    else {
        if ((str.find(arr[topFive[0]]) != std::string::npos || str.find(toupper(arr[topFive[0]])) != std::string::npos) && (str.find(arr[topFive[1]]) != std::string::npos || str.find(toupper(arr[topFive[1]])) != std::string::npos) && (str.find(arr[topFive[2]]) != std::string::npos || str.find(toupper(arr[topFive[2]])) != std::string::npos) && (str.find(arr[topFive[3]]) != std::string::npos || str.find(toupper(arr[topFive[3]])) != std::string::npos)) {
            transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            str = str + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ")";
        };
        if ((str.find(arr[topFive[0]]) != std::string::npos || str.find(toupper(arr[topFive[0]])) != std::string::npos) && (str.find(arr[topFive[1]]) != std::string::npos || str.find(toupper(arr[topFive[1]])) != std::string::npos) && (str.find(arr[topFive[3]]) != std::string::npos || str.find(toupper(arr[topFive[3]])) != std::string::npos) && (str.find(arr[topFive[4]]) != std::string::npos || str.find(toupper(arr[topFive[4]])) != std::string::npos)) {
            transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            str = str + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
        };
        if ((str.find(arr[topFive[0]]) != std::string::npos || str.find(toupper(arr[topFive[0]])) != std::string::npos) && (str.find(arr[topFive[2]]) != std::string::npos || str.find(toupper(arr[topFive[2]])) != std::string::npos) && (str.find(arr[topFive[3]]) != std::string::npos || str.find(toupper(arr[topFive[3]])) != std::string::npos) && (str.find(arr[topFive[4]]) != std::string::npos || str.find(toupper(arr[topFive[4]])) != std::string::npos)) {
            transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            str = str + "(" + arr[topFive[0]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
        };
        if ((str.find(arr[topFive[1]]) != std::string::npos || str.find(toupper(arr[topFive[1]])) != std::string::npos) && (str.find(arr[topFive[2]]) != std::string::npos || str.find(toupper(arr[topFive[2]])) != std::string::npos) && (str.find(arr[topFive[3]]) != std::string::npos || str.find(toupper(arr[topFive[3]])) != std::string::npos) && (str.find(arr[topFive[4]]) != std::string::npos || str.find(toupper(arr[topFive[4]])) != std::string::npos)) {
            transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            str = str + "(" + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[3]] + ", " + arr[topFive[4]] + ")";
        };
        if ((str.find(arr[topFive[0]]) != std::string::npos || str.find(toupper(arr[topFive[0]])) != std::string::npos) && (str.find(arr[topFive[1]]) != std::string::npos || str.find(toupper(arr[topFive[1]])) != std::string::npos) && (str.find(arr[topFive[2]]) != std::string::npos || str.find(toupper(arr[topFive[2]])) != std::string::npos) && (str.find(arr[topFive[4]]) != std::string::npos || str.find(toupper(arr[topFive[4]])) != std::string::npos)) {
            transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            str = str + "(" + arr[topFive[0]] + ", " + arr[topFive[1]] + ", " + arr[topFive[2]] + ", " + arr[topFive[4]] + ")";
        }
    }
    std::ofstream vmdelet_out;
    vmdelet_out.open("output.txt", std::ios::app);
    vmdelet_out << str + ' ';
    vmdelet_out.close();

    // std::cout << str << std::endl;
    return 0;
}


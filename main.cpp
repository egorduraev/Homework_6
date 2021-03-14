#include <iostream>
#include <fstream>

int main()
{
    //Задание 1
    std::ofstream f1o("file_1.txt", std::ofstream::app);
    std::ofstream f2o("file_2.txt");
    char * text1 = (char*) malloc(75*sizeof(char));
    char * text2 = (char*) malloc(75*sizeof(char));
    for (int i = 0; i < 75; i++) {
        text1[i] = 'A';
    }
    for (int i = 0; i < 75; i++) {
        text2[i] = 'B';
    }
    f1o<<text1;
    f2o<<text2;
    f2o.close();
    //Задание 2
    std::ifstream f2i("file_2.txt");
    int len = 255;
    char * buffer = new char [len];
    f2i>>buffer;
    f1o<<buffer;
    std::cout<<"Files are merged"<<std::endl;
    f1o.close();
    f2i.close();
    //Задание 3
    std::string text, check;
    std::ofstream t3o("Task_3.txt");
    t3o<<"one two three four five six seven eight nine ten";
    t3o.close();
    std::cout<<"Enter the word: ";
    std::cin>>text;
    char c;
    int i=0;
    int ic1 = 0, ic2 = 0;
    std::ifstream t3i("Task_3.txt");
    std::cout<<"Word search: "<<text<<std::endl;
    while (!t3i.eof()) {
        t3i.get(c);
        if (c == text[i]) {
            check+=c;
            i++;
            ic1++;
        }
        if (text == check && c == ' ') break; //Выход из цикла при совпадении слова
        //Чтобы не допустить сравнения отдельных букв, идет проверка конца слова (разделитель между словами ' ')
        if (ic1 != 0) {
            ic2++;
            if (ic1 != ic2) {
                check = "";
                ic1 = 0;
                ic2 = 0;
                i = 0;
            }
        }
    }
    if (text == check) std::cout<<"true"<<std::endl;
    else std::cout<<"false"<<std::endl;
    return 0;
}

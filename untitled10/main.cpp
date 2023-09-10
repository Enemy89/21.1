#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct statement {
    std::string surname;
    std::string name="0";
    std::string date;
    int money;
};

int main() {
    std::cout << "Enter the command (add - add entry, list - read statement)" << std::endl;
    std::string command;
    std::cin >> command;

    if (command == "add") {
        std::cout << "How many people need to be included in the statement?" << std::endl;
        int count;
        std::cin >> count;
        statement person[count];

        for (int i = 0; i < count; ++i) {
            std::ofstream add("..\\statement.txt", std::ios::app);
            if (add.is_open() == 0) {
                std::cout << "Path no valid!";
                return 0;
            }
            std::cout << "Enter the name and surname of the recipient of the funds"
                         ", the date of issue in the format DD.MM.YYYY, "
                         "the amount of payment in rubles." << std::endl;
            std::cin >> person[i].name >> person[i].surname >> person[i].date >> person[i].money;
            if (person[i].date.length() == 10 && person[i].money > 0 && (std::stoi(person[i].date.substr(0, 2)) > 0 &&
            std::stoi(person[i].date.substr(0, 2)) < 31) &&
                (std::stoi(person[i].date.substr(3, 2)) > 0 &&
                std::stoi(person[i].date.substr(3, 2)) < 13)) {
                add << std::endl << person[i].name << " " << person[i].surname << " " << person[i].date << " " << person[i].money;
                add.close();
            }
            else {
                std::cout<<"Err!";
                return 0;
            }
        }
    } else {
        if (command == "list") {
            std::ifstream list ("..\\statement.txt");
            if (list.is_open()==0) {
                std::cout<<"Path no valid!";
                return 0;
            }
            std::string str, strh;
            while (!list.eof()) {
                getline(list, strh);
                str += strh;
                if (!list.eof()){
                    str += '\n';
                }
            }
            std::cout<<str;

            list.close();
        } else {
            std::cout << "Invalid command!";
            return 0;
        }
    }
}

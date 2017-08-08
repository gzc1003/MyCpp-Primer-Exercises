#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
using namespace std;


struct PeopleInfo {
    string name;
    vector<string> phone;
};


bool valid(const string &phone_number)
{
    for (const auto c : phone_number)
        if (!isdigit(c))
            return false;
    return true;
}

string format(const string &phone_number)
{
    return phone_number.substr(0, 3) + "-" + phone_number.substr(4);
}


int main(int argc, char *argv[])
{
    vector<PeopleInfo> people;
    ifstream input_file(argv[1]);
    string line;
    while (std::getline(input_file, line)) {
        istringstream record(line);
        PeopleInfo person;
        record >> person.name;
        string phone;
        while (record >> phone)
            person.phone.push_back(phone);
        people.push_back(person);
    }

    
    ofstream output_file(argv[2]);

    for (const auto &person : people) {
        ostringstream formatted, invalid;
        for (const auto &number : person.phone) {
            if (valid(number)) {
                formatted << " " << format(number);
            } else {
                invalid << " " << number;
            }
        }
        if (invalid.str().empty()) {
            output_file << person.name << formatted.str() 
                << endl;
        } else {
            cerr << "input error: " << person.name
                << invalid.str() << endl;
        }
    }

    return 0;
}
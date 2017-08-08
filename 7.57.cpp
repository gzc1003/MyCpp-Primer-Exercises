#include <string>

class Account {
public:
    void calculate() { amount += amount * interest_rate; }
    static double rate() { return interest_rate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interest_rate;
    static constexpr double today_rate = 42;
    static double init_rate() { return today_rate; }
};

void Account::rate(double new_rate)
{
    interest_rate = new_rate;
}

double Account::interest_rate = init_rate();
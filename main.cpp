#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class AbstractFunction {
    public:
        virtual void parameters(double first, double second, double third, double fourth) = 0;
        virtual double result() = 0;
    protected:
        double first{}, second{}, third{}, fourth{};
};

class FirstFunction : AbstractFunction {
    public:
        FirstFunction() {
            this->first = 0;
            this->second = 0;
            this->third = 0;
            this->fourth = 0;
        }
        void parameters(double first, double second, double third, double fourth) override {
            this->first = first;
            this->second = second;
            this->third = third;
            this->fourth = fourth;
        }
        double result() override {
            return first * cos(second * fourth) + third;
        }
};
class SecondFunction : AbstractFunction {
    public:
        SecondFunction() {
            this->first = 0;
            this->second = 0;
            this->third = 0;
            this->fourth = 0;
        }
        void parameters(double first, double second, double third, double fourth) override {
            this->first = first;
            this->second = second;
            this->third = third;
            this->fourth = fourth;
        }
        double result() override {
            return first * atan(second * fourth);
        }
};
int main() {
    auto firstClass = new FirstFunction();
    auto secondClass = new SecondFunction();
    double first, second, third, fourth;
    int operationNumber;
    vector<double> results;
    do {
        cout << "1 - Calculate and insert first function result of results vector" << '\n'
             << "2 - Calculate and insert first function result of results vector" << '\n'
             << "3 - Output vector" << '\n'
             << "-1 - Exit" << '\n'
             << '\n' << "Enter the operation of number: "; cin >> operationNumber; cout << '\n';
        switch (operationNumber) {
            case 1 : {
                cout << "Enter the first function parameters: ";
                cin >> first >> second >> third >> fourth;
                cout << '\n';
                firstClass->parameters(first, second, third, fourth);
                cout << "Result: " << firstClass->result() << '\n' << '\n';
                results.push_back(firstClass->result());
                break;
            }
            case 2 : {
                cout << "Enter the second function parameters: ";
                cin >> first >> second >> third >> fourth;
                cout << '\n';
                secondClass->parameters(first, second, third, fourth);
                cout << "Result: " << secondClass->result() << '\n' << '\n';
                results.push_back(secondClass->result());
                break;
            }
            case 3 : {
                cout << "Vector: ";
                for (auto el : results) {
                    cout << el << " ";
                }
                cout << '\n' << '\n';
                break;
            }
            case -1 : {
                break;
            }
            default : cout << "Unknown command! Try again.";
        }
    } while (operationNumber != -1);
    delete firstClass; delete secondClass;
}
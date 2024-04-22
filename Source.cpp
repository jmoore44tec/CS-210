#include <iostream>
#include <iomanip>
#include <cmath>

class InvestmentCalculator {
private:
    double initialInvestment;                               //constructor
    double monthlyDeposit;                                  //monthly deposit amount
    double annualInterest;                                  //annual interest rate
    int numberOfYears;                                      //number of years to calculate for

public:
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears)
        : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), annualInterest(annualInterest), numberOfYears(numberOfYears) {}

    void calculateInvestment() {                            //function to calculate investment
        const int monthsInYear = 12;
        double openingAmount = initialInvestment;           //initialize opening amount
        double total = initialInvestment;                   //initialize total

        std::cout << "Month\tOpening Amount\tDeposited Amount\tTotal\tInterest\tClosing Balance" << std::endl; //header for the table
        for (int i = 1; i <= numberOfYears * monthsInYear; ++i) { //loop for each month
            double interest = (openingAmount + monthlyDeposit) * (annualInterest / 100) / monthsInYear; //calculate interest
            double closingBalance = openingAmount + monthlyDeposit + interest; //calculate closing balance
            std::cout << i << "\t$" << std::fixed << std::setprecision(2) << openingAmount << "\t$" << monthlyDeposit << "\t$"
                << total << "\t$" << interest << "\t$" << closingBalance << std::endl; //display the values in table format
            openingAmount = closingBalance;                 //update opening amount for next iteration
            total += monthlyDeposit;                        //update total for next iteration
        }
    }
};

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;

    std::cout << "Initial Investment Amount: $";                    //user nput
    std::cin >> initialInvestment;
    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;
    std::cout << "Annual Interest (%): ";
    std::cin >> annualInterest;
    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;

    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);  //creates InvestmentCalculator object

    std::cout << "\nInitial Investment Amount: $" << initialInvestment << std::endl;                    //displays input values
    std::cout << "Monthly Deposit: $" << monthlyDeposit << std::endl;
    std::cout << "Annual Interest: %" << annualInterest << std::endl;
    std::cout << "Number of Years: " << numberOfYears << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();

    calculator.calculateInvestment();               //calculates and displays investment

    return 0;
}

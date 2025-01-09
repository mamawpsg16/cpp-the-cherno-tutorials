#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <cctype>
#include <limits>

class ExchangeCalculator {
public:
    ExchangeCalculator() = default;

    double const convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency) {
        double exchangeRate = getCurrencyExchange(fromCurrency, toCurrency);
        if (exchangeRate < 0) {
            std::cerr << "Error: Exchange rate not found for " << fromCurrency << " to " << toCurrency << '\n';
            return 0;
        }
        return amount * exchangeRate;
    }

    void getExchanges() const {
        std::cout << "AVAILABLE EXCHANGES:\n";
        for (const auto& rate : exchangeRates) {
            std::cout << "\t " << rate.first.first << " = " << rate.first.second << '\n';
        }
    }

private:
    double getCurrencyExchange(const std::string& fromCurrency, const std::string& toCurrency) const {
        auto key = std::make_pair(fromCurrency, toCurrency);
        auto it = exchangeRates.find(key);
        return (it != exchangeRates.end()) ? it->second : -1.0;
    }

    struct PairHash {
        template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
    };

    std::unordered_map<std::pair<std::string, std::string>, double, PairHash> exchangeRates = {
        {{"EUR", "BRL"}, 25.5},
        {{"USD", "PHP"}, 55.5},
        {{"JPY", "USD"}, 15},
        {{"JPY", "PHP"}, 30},
    };
};

std::string toUpper(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

//int main() {
//    ExchangeCalculator calculator;
//    bool continueConversion = true;
//
//    while (continueConversion) {
//        double amount = 0;
//        std::string fromCurrency, toCurrency;
//        std::cout << "\n---- Welcome To Villarica Pawnshop ----\n\n";
//
//        calculator.getExchanges();
//
//        std::cout << "\nEnter Amount you want to exchange: ";
//        std::cin >> amount;
//
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//        std::cout << "\nEnter your currency: ";
//        std::getline(std::cin, fromCurrency);
//
//        std::cout << "\nEnter currency to convert from: ";
//        std::getline(std::cin, toCurrency);
//
//        fromCurrency = toUpper(fromCurrency);
//        toCurrency = toUpper(toCurrency);
//
//        std::cout << "\nYou want to exchange " << amount << " from " << fromCurrency << " to " << toCurrency << ".\n";
//
//        double convertedAmount = calculator.convertCurrency(amount, fromCurrency, toCurrency);
//        if (convertedAmount > 0) {
//            std::cout << "\nConverted amount: " << convertedAmount << '\n';
//        }
//
//        // Ask the user if they want to continue
//        std::string userChoice;
//        std::cout << "\nDo you want to make another conversion? (y/n): ";
//        std::getline(std::cin, userChoice);
//
//        // Check user response and continue or exit
//        continueConversion = (userChoice == "y" || userChoice == "Y");
//    }
//
//    std::cout << "\nThank you for using Villarica Pawnshop!\n";
//
//    return 0;
//}

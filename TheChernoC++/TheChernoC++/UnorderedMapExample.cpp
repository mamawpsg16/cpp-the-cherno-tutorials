// C++ program to demonstrate 
// functionality of unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;
#include <vector>

unordered_map<std::string, std::vector<string>> umap;

const unordered_map<std::string, std::vector<string>>& getAppliances() {
    return umap;
}

//int main()
//{
//
//
//    umap["PC Parts"].push_back("Monitor");
//    umap["PC Parts"].push_back("Mouse");
//    umap["PC Parts"].push_back("Keyboard");
//    umap["Electric Fan Parts"].push_back("Elesi");
//    umap["Electric Fan Parts"].push_back("Speed Button");
//
//    unordered_map<std::string, std::vector<string>> appliances = getAppliances();
//
//    for (auto& v : appliances) {
//        std::cout << v.first << ":" << '\n';
//        for (auto& p : v.second) {
//            std::cout << "\t" << p << '\n';
//        }
//    }
//
//}
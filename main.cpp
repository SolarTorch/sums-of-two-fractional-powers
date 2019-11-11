#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream output;
    ostringstream* ost = new ostringstream;
    *ost << setprecision(15);
    output.open("/Users/wisdondeng/Desktop/gap3_with0.csv");
    double power = 3.0/2;
    vector<double>* result = new vector<double>;
    
    if (!output.good()) {
        exit(1);
    }
    for (int i = 0; i < 250; ++i) {
        for (int j = 0; j < 250; ++j) {
            result->push_back(pow(double(i), power) + pow(double(j), power));
        }
    }
    sort(result->begin(), result->end());
    auto it = result->begin();
    auto prev = it;
    double op;
    double upper_bound = pow(250, power);
    while (it!=result->end() && (*it) <= upper_bound) {/* make sure the current value is smaller than 250^\theta*/
        ++it;
        op = *it - *prev;
        *ost << *prev << "," << op <<"\n";
        ++prev;
    }
    output << ost->str();
    output.close();
    delete ost;
    delete result;
    return 0;
}

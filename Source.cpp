#include "logic.h"


int main() {
    try {
        auto data1 = readTSV("data1.tsv");
        auto data2 = readTSV("data2.tsv");

        mergeData(data1, data2);

        auto result = calculateAverage(data1);

        saveToJson(result, "result.json");

        cout << "Done\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

return 0;}

#include "D:\с++\Modul_30.04.2026\logic.h"
#include <gtest/gtest.h>
//ЗАВДАННЯ 1
TEST(listremoving, removeIf) {
    list<int>a{ 1,3,5,7,4,2 };
        even(a);
 
    EXPECT_EQ(a.size(),4);
    EXPECT_EQ(a.begin(), 1);
    EXPECT_EQ(a.end(),7);
}


//ЗАВДАННЯ 2



TEST(TSVTest, ReadCorrectFile) {
    auto data = readTSV("test.tsv");

    EXPECT_EQ(data[1][0], 90);
    EXPECT_EQ(data[2][0], 70);
}

TEST(MergeTest, MergeMaps) {
    map<int, vector<int>> a = { {1, {90}} };
    map<int, vector<int>> b = { {1, {80}}, {2, {70}} };

    mergeData(a, b);

    EXPECT_EQ(a[1].size(), 2);
    EXPECT_EQ(a[2][0], 70);
}

TEST(AverageTest, Calculate) {
    map<int, vector<int>> data = {
        {1, {90, 80}},
        {2, {70}}
    };

    auto result = calculateAverage(data);

    EXPECT_DOUBLE_EQ(result[1], 85.0);
    EXPECT_DOUBLE_EQ(result[2], 70.0);
}

TEST(ExceptionTest, EmptyGrades) {
    map<int, vector<int>> data = { {1, {}} };

    EXPECT_THROW(calculateAverage(data), runtime_error);
}

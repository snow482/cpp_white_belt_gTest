#include <iostream>
#include <string>
#include <map>
#include <gtest/gtest.h>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class BuildingCharCounters{
public:
    map<char, int> BuildCharCounters (const string& str) {
        map<char, int> counters;
        for(char ch : str){
            ++counters[ch];
        }
        return counters;
    }
};

TEST(BuildCharCounters, anagramsReverse){
    {
        // Arrange
        BuildingCharCounters buildingCharCounters;
        string word_1 = "totoma";
        string word_2 = "tomato";
        // Act
        auto w1 = buildingCharCounters.BuildCharCounters(word_1);
        auto w2 = buildingCharCounters.BuildCharCounters(word_2);
        // Assert
        ASSERT_EQ(w1, w2);
    }
}

TEST(BuildCharCounters, anagramsFoward){
    {
        // Arrange
        BuildingCharCounters buildingCharCounters;
        string word_1 = "tomato";
        string word_2 = "tomato";
        // Act
        auto w1 = buildingCharCounters.BuildCharCounters(word_1);
        auto w2 = buildingCharCounters.BuildCharCounters(word_2);
        // Assert
        ASSERT_EQ(w1, w2);
    }
}

TEST(BuildCharCounters, testFailureTrue){
    {
        // Arrange
        BuildingCharCounters buildingCharCounters;
        string word_1 = "tomato";
        string word_2 = "tomata";
        // Act
        auto w1 = buildingCharCounters.BuildCharCounters(word_1);
        auto w2 = buildingCharCounters.BuildCharCounters(word_2);
        // Assert
        ASSERT_NE(w1, w2);
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
/*
int main() {

    int n;
    cin >> n;
        for (int i = 0; i < n; ++i) {
            string word_1, word_2;
            cin >> word_1 >> word_2;
            if(BuildCharCounters(word_1) == BuildCharCounters(word_2)){
                cout << "YES" << endl;
            }else {
                cout << "NO" << endl;
            }
        }

    return 0;
}*/


// how to test a private methods

/*friend class FriendTest;

private:
map<char, int> BuildCharCounters (const string& str) {
    map<char, int> counters;
    for(char ch : str){
        ++counters[ch];
    }
    return counters;
}
};

class FriendTest
{
    void Foo(BuildingCharCounters& buildingCharCounters)
    {
        auto b = buildingCharCounters.BuildCharCounters("134132");
    }
};*/

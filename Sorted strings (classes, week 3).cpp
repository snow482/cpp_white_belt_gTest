#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class SortedStrings{
public:
    void AddString (const string& s){
        v.push_back(s);
    }
    vector<string> GetSortedStrings(){
        std::sort(v.begin(), v.end());
        return v;
    }
    friend class TestFriend;
private:
    vector<string> v;
};

void PrintSortedStrings(SortedStrings& strings){
    for (const string& s :strings.GetSortedStrings()){
        cout << s << " ";
    }
}

class TestFriend{
    public:
        vector<string> GetVector(const SortedStrings& ss){
            return ss.v;
        }
};


TEST(SortedStrings, AddStrings){
    {
        // Arrange
        SortedStrings sortedStrings;
        TestFriend testFriend;
        string testString1 = "first_tomato";
        string testString2 = "third_tomato";
        string testString3 = "second_tomato";
        vector<string> testFullVec = {"first_tomato", "third_tomato", "second_tomato"};

        sortedStrings.AddString(testString1);
        sortedStrings.AddString(testString2);
        sortedStrings.AddString(testString3);
        // Act
        auto vector = testFriend.GetVector(sortedStrings);
        // Assert
        ASSERT_EQ(vector, testFullVec);
    }
}

TEST(SortedStrings, SortStrings){
    {
        // Arrange
        SortedStrings sortedStrings;
        TestFriend testFriend;
        string testString1 = "first_tomato";
        string testString2 = "third_tomato";
        string testString3 = "second_tomato";
        vector<string> testFullVec = {"first_tomato", "second_tomato", "third_tomato"};

        sortedStrings.AddString(testString1);
        sortedStrings.AddString(testString2);
        sortedStrings.AddString(testString3);
        sortedStrings.GetSortedStrings();
        // Act
        auto vector = testFriend.GetVector(sortedStrings);
        // Assert
        ASSERT_EQ(vector, testFullVec);
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

/*int main() {

       SortedStrings strings;

       strings.AddString("first");
       strings.AddString("third");
       strings.AddString("second");
       PrintSortedStrings(strings);

       strings.AddString("second");
       PrintSortedStrings(strings);

    return 0;
    */
}
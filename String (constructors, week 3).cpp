#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


using std::reverse;
using std::map;
using std::vector;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class ReversibleString{
public:
    ReversibleString()= default;
    ReversibleString(const string& s){
        str = s;
    }
    void Reverse(){
        reverse(begin(str), end(str));
    }
    string ToString() const{
        return str;
    }
private:
    string str;
};

TEST(ReversibleString, reverseTest){
    // Arrange
    string rightReversedString = "evil";
    string stringForReverse = "live";
    ReversibleString reversibleString (stringForReverse); // add string for reverse to constructor;
    // Act
    reversibleString.Reverse();
    string s = reversibleString.ToString();
    // Assert
    ASSERT_EQ(rightReversedString, s);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

/*int main(){

    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;



    return 0;*/
}




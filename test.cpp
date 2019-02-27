using namespace std;
#include <bits/stdc++.h>
#include<gtest/gtest.h>

TEST(Testname,incre_by_5){
	//Arrange
	int value=100;
	int increment=5;
	//Act
	value=value+increment;
	//assert
	ASSERT_EQ(value,105);
}
TEST(Testname,incre_by_10){
	//Arrange
	int value=100;
	int increment=10;
	//Act
	value=value+increment;
	//assert
	ASSERT_EQ(value,110);
}
class MyClass{
	int bv;
public:
	MyClass(int _bv){
		bv=_bv;
	}
	void increment(int byValue){
		bv+=byValue;
	}
	int getVal(){
		return bv;
	}
};
struct MyClassTest : public testing::Test{
	MyClass *mc;
	void SetUp(){ mc = new MyClass(100);}
	void TearDown(){ delete mc;}
};
TEST_F(MyClassTest,Increment_by_5){
	mc->increment(5);
	ASSERT_EQ(mc->getVal(),105);
}
TEST_F(MyClassTest,Increment_by_10){
	mc->increment(10);
	ASSERT_EQ(mc->getVal(),110);
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

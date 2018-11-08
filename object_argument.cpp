#include<iostream>
using namespace std;
class test
{
    int num;
    public:
        void getnum();
        void shownum();
        void sum(test,test);
};
void test :: getnum()
{
    cout<< "Enter any number"<<endl;
    cin>>num;
}
void test::shownum()
{
    cout << num<<endl;
}
void test :: sum(test a,test b)
{
    num = a.num + b.num;
}
int main()
{
    test t1,t2,t3;
    t1.getnum();
    t2.getnum();
    t3.sum(t1,t2);
    cout<<"now we are going to show the data in all objects"<<endl;
    cout<<"num of t1 ";t1.shownum();
    cout<<"num of t2 ";t2.shownum();
    cout<<"num of t3 ";t3.shownum();
    return 0;
}
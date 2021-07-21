#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class X
{
public:
    X()
    {
        cout << "construct X" << endl;
    }
    ~X()
    {
        cout << "destruct X" << endl;
    }
};

void testScoped_ptr()
{
	cout << "starting testScoped_ptr() " <<endl;
	boost::scoped_ptr<X> p(new X);
	cout << "exiting testScoped_ptr() " <<endl;
}

void testShared_ptr()
{
	cout << "starting test shared_ptr" << endl;
	boost::shared_ptr<X> p1(new X);
	cout << "p1.use_count() " << p1.use_count() << endl;
	boost::shared_ptr<X> p2(p1);
	cout << "p1.use_count() " << p1.use_count() << endl;
	cout << "p2.use_count() " << p2.use_count() << endl;
	p1.reset();
	cout << "p2.use_count() after p1.reset() " << p2.use_count() << endl;
	p2.reset();
	cout << "p2.use_count() after p2.reset() " << p2.use_count() << endl;
	cout << "exiting test shared_ptr" << endl;
}

void testShared_ptrInVec()
{
	cout <<  "将shared_Ptr放在vector中去代码示例" << endl;
	vector<boost::shared_ptr<X> > vec;
	boost::shared_ptr<X> p(new X);
	cout << "before push_back, p.use_count = " << p.use_count() << endl;
	vec.push_back(p);
	cout << "after push_back, p.use_count = " << p.use_count() << endl;
}
int main(void)
{
    cout << "entering main" << endl;
    
    testScoped_ptr();
    testShared_ptr();
    testShared_ptrInVec();

    cout << "exiting main" << endl;
    
    return 0;
}

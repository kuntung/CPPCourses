#include <iostream>

using std::cout;
using std::endl;
class CObject
{
public:
	virtual void func()
	{
		cout << "CObjec::func() " << endl;
	}
    virtual void Serialize()
    {
        cout << "CObject::Serialize()" << endl;
    }
};

class CDocument : public CObject
{
public:
    CDocument()
    {
        cout << "CDocument() " << endl;
    }
    virtual void Serialize()
    {
        cout << "CDocument::Serialize()" << endl;
    }
    
    CDocument(const CDocument& other)
    {
        cout << "CDocument(const CDocument& other) " << endl;
    }
    int data_1;
};

class CMyDoc : public CDocument
{
public:

    virtual void Serialize()
    {
        cout << "CMyDoc::Serialize() " << endl;
    }

    int data2_;
};

void test1()
{
    CMyDoc mydoc;
    CMyDoc* pmydoc = new CMyDoc;

    cout << "#1 testing" << endl;
    mydoc.func();

    cout << "#2 testing" << endl;
    ((CDocument*)&mydoc)->func();

    cout << "#3 testing" << endl;
    pmydoc->func();

    cout << "#3 testing" << endl;

    ((CDocument)mydoc).func();

}

int main(void)
{
    test1();

    return 0;
}

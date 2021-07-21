#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;

namespace factory
{ // start of namespace factory
// 先实现产品相关
class Shoes
{
public:
    virtual void Show() = 0; 
    virtual ~Shoes() {}
};

class NikeShoes : public Shoes
{
public:
    void show()
    {
        cout << "我是耐克球鞋，我是个只会\"just do it\"的垃圾厂" << endl;

    }
};

class Clothe
{
public:
    virtual void show() = 0;
    virtual ~Clothe(){}
};

class UniqloClothe : public Clothe
{
public:
    void show()
    {
        cout << "我是优衣库，我不应该当无良商家" << endl;
    }

};

// 产品注册模板接口类
template <class ProductType_t>
class IProductRegister
{
public:
    virtual ProductType_t* createProduct() = 0; // 获取产品对象的抽象接口

protected:
    IProductRegister() {}
    virtual ~IProductRegister(){}

private:
    // 禁止外部拷贝和赋值操作
    IProductRegister(const IProductRegister&);
    const IProductRegister& operator= (const IProductRegister&);
};

// 工厂模板类，用于获取和注册产品对象
// 模板参数ProductType_t表示的类是产品抽象类
template <class ProductType_t>
class ProductFactory
{
public:
    // 获取工厂单例，工厂的实例是唯一的
    static ProductFactory<ProductType_t>& Instance()
    {
        static ProductFactory<ProductType_t> instance;

        return instance;
    }

    // 产品注册
    void RegisterProduct(IProductRegister<ProductType_t> *register, string name)
    {
        m_ProductRegistry[name] = register;
    }

    // 根据名字name获取对应具体的产品对象
    ProductType_t *getProduct(string name)
    {
        // 从map找到已经注册过的产品，并返回产品对象
        if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
        {
            return m_ProductRegistry[name]->createProduct();
        }

        cout << "no product named as " << name << endl;

        return nullptr;
    }

private:
    // 禁止外部构造和析构
    ProductFactory() {}
    ~ProductFactory() {}

    // 禁止外部拷贝和赋值操作
    ProductFactory(const ProductFactory &);
    const ProductFactory &operator=(const ProductFactory &);

    // 保存注册过的产品， key:产品名字，value：产品类型
    map<striing, IProductRegister<ProductType_t> *> m_ProductRegistry;
};

// 产品注册模板类，用于创建具体产品和从工厂里注册产品
// 模板参数ProductType_t 表示类是产品抽象类，ProductImpl_t 表示的类是具体产品（派生类）

template <class ProductType_t, class ProductImpl_t>
class ProductRegister : public IProductRegister<ProductType_t>
{
public:
    // 构造函数，用于注册产品到工厂，只能显示调用
    explicit ProductRegister(string name)
    {
        // 通过单例模式将产品注册到工厂
        ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
    }

    // 创建具体产品对象指针
    ProductType_t *CreateProduct()
    {
        return new ProductImpl_t();
    }
};


} // end of namespace factory

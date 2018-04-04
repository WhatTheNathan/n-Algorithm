/**
 * Description:
 * 用C++设计一个不能被集成的类
 */

#include <iostream>

using namespace::std;

class SealedClass {
public:
    static SealedClass* getInstance() {
        return new SealedClass();
    }

    static void DeleteInstance(SealedClass* pInstance) {
        delete pInstance;
    }

private:
    SealedClass() {}
    ~SealedClass() {}
};

int main() {

}

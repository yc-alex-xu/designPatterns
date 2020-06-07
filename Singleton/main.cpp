#include <iostream>
#include <string>
#include <cassert>

class President
{
public:
    static President &GetInstance()
    {
        static President instance;
        return instance;
    }

    President(const President &) = delete;
    President &operator=(const President &) = delete;

private:
    President() {}
};

int main()
{
    const President &president1 = President::GetInstance();
    const President &president2 = President::GetInstance();

    std::cout << "instance 1:" << std::hex << &president1 << std::endl
              << "instance 2:" << &president2 << std::endl; // same address, point to same object.
}

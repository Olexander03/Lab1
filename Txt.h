#ifndef TXT_H
#define TXT_H
#include <string>
#include <vector>

namespace l1
{

    class Txt
    {
    public:
        Txt();
        Txt(const std::string& fileName);
        ~Txt();

        Txt(const Txt& other);
        Txt& operator=(const Txt& other);

        Txt(Txt&& other) noexcept;

        Txt& operator=(Txt&& other) noexcept;

        size_t size();

    private:
        std::vector<std::string> array;
    };
} //namespace l1

#endif // TXT_H

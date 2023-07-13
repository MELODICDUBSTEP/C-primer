//We are going to define a new class named Blob that will hold a collection of elements.
//We want Blob objects that are copies of one another to share the same elements. That is when we copy a Blob, the original and the copy should refer to the same underlying elements.

//One common reason to use dynamic memory is to allow multiple objects to share the same state.

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {return data -> size()};
    bool empty() const {return data -> empty()};
    void push_back(const std::string &t){data -> push_back(t)};
    void pop_back();
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob()
{
    data(std::make_shared<std::vector<std::string>>());
}
StrBlob::StrBlob(std::initializer_list<std::string> il)
{
    data(std::make_shared<std::vector<std::string>>(il));
}
//the constructor takes an initializer_list passes its parameter to the 
//corresponding vector constructor. The constructor initializes the 
//vector's elements by copying the values in the list.

void StrBlob::check(size_type i, const std::string &msg) const
{
    if(i >= data -> size())
    {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back()
{
    check(0, "the vector is empty");
    data -> pop_back();
}

std::string& StrBlob::front()
{
    check(0, "the vector is empty");
    return data -> front();
}

std::string& StrBlob::back()
{
    check(0, "the vector is empty");
    return data -> back();
}


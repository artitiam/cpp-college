#include <iostream>
#include <vector>

template <typename T>
class List
{
private:
    std::vector<T> elems;

public:
    List() {}

    List(const List &other)
    {
        elems = other.elems;
    }

    List &operator=(const List &other)
    {
        if (this != &other)
        {
            elems = other.elems;
        }
        return *this;
    }

    void push_back(const T &x)
    {
        elems.push_back(x);
    }

    size_t size() const
    {
        return elems.size();
    }

    class Iterator
    {
        typename std::vector<T>::iterator it;

    public:
        Iterator(typename std::vector<T>::iterator i) : it(i) {}
        T &operator*() { return *it; }
        Iterator &operator++()
        {
            ++it;
            return *this;
        }
        bool operator==(const Iterator &other) const
        {
            return it == other.it;
        }
        bool operator!=(const Iterator &other) const
        {
            return it != other.it;
        }
    };

    Iterator begin()
    {
        return Iterator(elems.begin());
    }

    Iterator end()
    {
        return Iterator(elems.end());
    }
};

int main()
{
    List<int> lst;
    for (int i = 1; i <= 5; ++i)
    {
        lst.push_back(i);
    }
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
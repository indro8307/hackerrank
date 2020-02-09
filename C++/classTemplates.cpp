/*
https://www.hackerrank.com/challenges/c-class-templates/problem
*/


template <class T>
class AddElements
{
    T elem;
public:
    AddElements(T arg);
    T add(T arg);
};

template <>
class AddElements <string>
{
    string elem;
public:
    AddElements(string arg) 
    {
        elem=arg;
    }
    string concatenate(string arg) 
    {
        return elem+arg;
    }
};

template <class T>
AddElements<T>::AddElements(T arg)
{
    elem = arg;
}

template <class T>
T AddElements<T>::add(T arg)
{
    return elem+arg;
}

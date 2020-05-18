#include <iostream>

using namespace std;

class Set
{
public:
    int elements[100];
    int size = 0;

    Set();
    void input();
    void print();
    bool subset_of(Set);
    Set union_with(Set);
    Set intersection_with(Set);
    Set complement();
    Set difference(Set);
    Set difference_sym(Set);
    void cartesian_prod(Set);

private:
    void addElement(int);
    bool has(int i);
};

Set::Set()
{
}
void Set::input()
{
    int itrCount;
    cout << endl
         << endl
         << "Enter the size of set : ";
    cin >> itrCount;
    cout << "Enter the elements of set : ";
    for (int i = 0; i < itrCount; i++)
    {
        int e;
        cin >> e;
        this->addElement(e);
    }
    cout << endl;
}
bool Set::has(int n)
{
    for (int i = 0; i < size; i++)
    {
        if (n == elements[i])
        {
            return true;
            break;
        }
    }
    return false;
}
void Set::addElement(int n)
{
    if (!has(n))
    {
        elements[size] = n;
        ++size;
    }
}
bool Set::subset_of(Set set)
{
    int count = 0;
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < set.size; j++)
        {
            if (this->elements[i] == set.elements[j])
            {
                count++;
                break;
            }
        }
    }
    if (count == size)
        return true;
    else
        return false;
}
Set Set::union_with(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        temp.addElement(elements[i]);
    }
    for (int i = 0; i < set.size; i++)
    {
        temp.addElement(set.elements[i]);
    }
    return temp;
}
Set Set::intersection_with(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        if (set.has(elements[i]))
            temp.addElement(elements[i]);
    }
    return temp;
}
Set Set::complement()
{
    Set temp;
    return temp;
}
Set Set::difference(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        if (!set.has(elements[i]))
            temp.addElement(elements[i]);
    }
    return temp;
}
Set Set::difference_sym(Set set)
{
    Set unionSet = union_with(set);
    Set intrSet = intersection_with(set);
    return unionSet.difference(intrSet);
}
void Set::cartesian_prod(Set set)
{
    cout << endl
         << "{ ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < set.size; j++)
        {
            cout << "{" << elements[i] << "," << set.elements[j] << "} ";
        }
    }
    cout << "}" << endl
         << endl
         << endl;
}

void Set::print()
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            cout << elements[i];
        else
            cout << "," << elements[i];
    }
    cout << "} ";
}

int main()
{
    Set setA = Set();
    setA.input();
    cout << "--> Set A : ";
    setA.print();
    Set setB = Set();
    setB.input();
    cout << "--> Set B : ";
    setB.print();

    if (setA.subset_of(setB))
        cout << endl
             << endl
             << "--> Set A is a subset of Set B." << endl;
    else
        cout << endl
             << endl
             << "--> Set A is not a subset of Set B." << endl;

    cout << endl
         << "--> Set A union Set B : ";
    setA.union_with(setB).print();

    cout << endl
         << endl
         << "--> Set A intersection Set B : ";
    setA.intersection_with(setB).print();

    cout << endl
         << endl
         << "--> Set A difference Set B : ";
    setA.difference(setB).print();

    cout << endl
         << endl
         << "--> Set A symmetric difference Set B : ";
    setA.difference_sym(setB).print();

    cout << endl
         << endl
         << "--> Cartesian product of Set A and Set B : ";
    setA.cartesian_prod(setB);

    return 0;
}
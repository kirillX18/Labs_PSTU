#include <iostream>

using namespace std;

class Iterator
{
    friend class Vector;
    int* elem;
public:
    Iterator()
    {
        elem = 0;
    }
    Iterator(const Iterator& it)
    {
        elem = it.elem;
    }
    bool operator==(const Iterator& tmp)
    {
        return elem == tmp.elem;
    }
    bool operator!=(const Iterator& tmp)
    {
        return elem != tmp.elem;
    }
    void operator++()
    {
        ++elem;
    }
    void operator--()
    {
        --elem;
    }

    int& operator*()
    {
        return *elem;
    }


};

class Vector
{
    int size;
    int* data;
    Iterator beg;
    Iterator end;
 public:
     Vector(int s)
     {
         size = s;
         data = new int[size];
         for (int i = 0; i < size; i++)
         {
             data[i] = 0;
         }
     }

    Vector(int s, int k)
    {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = k;
        }
    }
    Vector(const Vector& a)
    {
        size = a.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = a.data[i];
        }
    }
    ~Vector()
    {
        delete[] data;
    }

    int& operator[](int index)
    {
        if (index < size) return data[index];
        else cout << "\nError! Index>size";
    }

    int len()
    {
        return size;
    }

    Vector& operator=(const Vector& tmp)
    {
        if (this == &tmp)
        {
            return *this;
        }
        size = tmp.size;
        if (data != 0)
        {
            delete[]data;
        }
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = tmp.data[i];
        }
        return *this;
    }
    
    Vector operator+(const int a) 
    {
        Vector s(size);
        for (int i = 0; i < size; i++)
        {
            s.data[i] += data[i] + a;
        }
        return s;
    }

    friend ostream& operator<<(ostream& out, const Vector& a);
    friend istream& operator>>(istream& in, Vector& a);

    Iterator first()
    {
        beg.elem = &data[0];
        return beg;
    }
    Iterator last()
    {
        end.elem = &data[size];
        return end;
    }
};

ostream& operator<<(ostream& out, const Vector& a)
{
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, Vector& a)
{
    cout << "Введите значения" << endl;
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}

    int main()
    {
        setlocale(LC_ALL, "Russian");
        Vector a(5);
        cout << a << "\n";
        cin >> a;
        cout << a << "\n";
        a[2] = 100;
        cout << a << "\n";
        Vector b(10);
        cout << b << "\n";
        b = a;
        cout << b << "\n";
        Vector c(10);
        c = b + 100;
        cout << c << "\n";
        cout << "Длина а = " << a.len() << endl;
        cout << *(a.first()) << endl;
        Iterator i = a.first();
        ++i;
        cout << *i << endl;
        for (i = a.first(); i != a.last(); ++i)
        {
            cout << *i << endl;
        }
    }
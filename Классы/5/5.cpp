#include <iostream>

using namespace std;

class abstac
{
public:
    virtual void funks() = 0;
};

class Pair  : public abstac
{
protected:
    int first;
    int second;
public:
    Pair()
    {
        first = 0;
        second = 0;
    }
    Pair(int t, int n)
    {
        first = t;
        second = n;
    }
    Pair(const Pair& tem)
    {
       this->first = tem.first;
       this->second = tem.second;
    }
    
    void funks()
    {
        cout << first << " , " << second << endl;
    }
    void setFirst(int f)
    {
        first = f;
    }
    void setSecond(int s)
    {
        second = s;
    }
   
    int getFirst() { return first; }
    int getSecond() { return second; }
    
    Pair& operator=(const Pair& p)
    {
        if (&p == this) return *this;
        first = p.first;
        second = p.second;
        return *this;
    }
    Pair operator*(const Pair tem)
    {
        first = first * tem.first;
        second = second * tem.second;
        return *this;
    }
    
    friend istream& operator>>(istream& in, Pair& tem);
    friend ostream& operator<<(ostream& out, const Pair& tem);
    
    virtual ~Pair()
    {
        
    }
};

istream& operator>>(istream& in, Pair& tem)
{
    cout << "Введите первое число "; in >> tem.first;
    cout << "Введите второе число "; in >> tem.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& tem)
{
    return (out << "(" << tem.first << "," << tem.second << ")");
}


class Rect : public Pair
{
public:
    int S()
    {
        int s;
        s = first * second;
        return s;
    }
    int P()
    {
        int p;
        p = 2 * (first + second);
        return p;
    }
    Rect()
    {
        first = 0;
        second = 0;
    }
    Rect(int f, int s)
    {
        first = f;
        second = s;
    }
    Rect(const Rect& tem)
    {
        first = tem.first;
        second = tem.second;
    }
    Rect& operator=(const Rect& p)
    {
        if (&p == this) return *this;
        first = p.first;
        second = p.second;
        return *this;
    }
    friend istream& operator>>(istream& in, Rect& tem);
    friend ostream& operator<<(ostream& out, const Rect& tem);
    ~Rect()
    {
        
    }
};

istream& operator>>(istream& in, Rect& tem)
{
    cout << "Введите одну ширину "; in >> tem.first;
    cout << "Введите другую длину "; in >> tem.second;
    return in;
}

ostream& operator<<(ostream& out, const Rect& tem)
{
    return (out << "Одна сторона равна " << tem.first << " ; " << "Другая стороная равна " << tem.second);
}

class Vector
{
private:
    abstac** beg;
    int size;
    int cur;
public:
    Vector()
    {
        beg = 0;
        size = 0;
        cur = 0;
    }
    Vector(int n)
    {
        beg = new abstac * [n];
        cur = 0;
        size = n;
    }
    void add(abstac* tem)
    {
        if (cur < size)
        {
            beg[cur] = tem;
            cur++;
        }
    }
    ~Vector()
    {
        if (beg != 0)
        {
            delete[] beg;
        }
        beg = 0;
    }
    friend ostream& operator<<(ostream& out, const Vector& v);
};
ostream& operator<<(ostream& out, const Vector& v)
{
    cout << "Вектор:" << endl;
    if (v.size == 0)
    {
        out << "Empty" << endl;
    }
    abstac** tem = v.beg;
    for (int i = 0; i < v.cur; i++)
    {
        (*tem)->funks();
        tem++;
    }
    return out;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    Vector v(5);
    Pair a;
    cin >> a;
    Rect b;
    cin >> b;
    abstac* tem = &a;
    v.add(tem);
    tem = &b;
    v.add(tem);
    cout << v;
    return 0;
}
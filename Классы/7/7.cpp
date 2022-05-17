#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	T* data;
public:
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = k;
		}
	}
	Vector(const Vector<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}
	~Vector()
	{
		delete[]data;
	}
	T& operator[](int index)
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Индекс больше размера вектора" << endl;
			return data[0];
		}
	}
	int operator()()
	{
		return size;
	}
	Vector& operator=(const Vector<T>& tmp)
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
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
		return *this;
	}
	Vector operator+(const Vector<T> tmp)
	{
		T a(0, 0);
		Vector<T> tmp2(size, a);
		if (size >= tmp.size)
		{
			for (int i = 0; i < tmp.size; i++)
			{
				tmp2.data[i] = data[i] + tmp.data[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				tmp2.data[i] = data[i] + tmp.data[i];
			}
		}
		return tmp2;
	}
	friend ostream& operator<< <>(ostream& out, const Vector<T>& tmp);
	friend istream& operator>> <>(istream& in, Vector<T>& tmp);
};
template <class T>
ostream& operator<< <>(ostream& out, const Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.data[i] << " ";
	}
	return out;
}

template <class T>
istream& operator>> <>(istream& in, Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.data[i];
	}
	return in;
}

class Time
{
private:
	int min;
	int sec;
public:
	Time()
	{
		min = 0;
		sec = 0;
	}
	Time(int m, int s)
	{
		min = m;
		sec = s;
	}
	Time(const Time& t)
	{
		min = t.min;
		sec = t.sec;
	}
	int getMin()
	{
		return min;
	}
	int getSec()
	{
		return sec;
	}
	void setMin(int m)
	{
		min = m;
	}
	void setSec(int s)
	{
		sec = s;
	}
	Time& operator=(const Time& t)
	{
		if (&t == this) {
			return *this;
		}
		min = t.min;
		sec = t.sec;
		return *this;
	}
	Time operator+(Time tmp)
	{
		int tm = min * 60 + tmp.min * 60 + sec + tmp.sec;
		Time tmp2(tm / 60, tm % 60);
		return tmp2;
	}
	friend ostream& operator<<(ostream& out, const Time& tmp);
	friend istream& operator>>(istream& in, Time& tmp);
	~Time()
	{

	}
};

ostream& operator<<(ostream& out, const Time& tmp)
{
	return (out << "(" << tmp.min << " : " << tmp.sec << ")");
}
istream& operator>>(istream& in, Time& tmp)
{
	cout << "\nmin ";
	in >> tmp.min;
	cout << "\nsec ";
	in >> tmp.sec;
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Time t(10, 45);
	cout << t;
	Vector<Time>Q(4, t);
	cin >> Q;
	cout << Q << endl;
	Vector<Time>W(11, t);
	cout << W << endl;
	W = Q;
	cout << W << endl;
	cout << Q[2] << endl;
	cout << "Размер Q = " << Q() << endl;
	Q = Q + W;
	cout << Q << endl;
	return 0;
}
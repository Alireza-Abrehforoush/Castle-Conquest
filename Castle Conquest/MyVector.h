#ifndef MYVECTOR_FJSKDF
#define MYVECTOR_FJSKDF
#include <iostream>
using namespace std;
template <class inputType>
class MyVector
{
protected:
private:
	inputType* arr = nullptr;
	unsigned long long int size = 0;
public:
	MyVector(unsigned long long int size)
	{
		this->size = size;
		this->arr = new inputType[size];
		return;
	}
	MyVector(unsigned long long int size, const inputType& a)
	{
		this->size = size;
		this->arr = new inputType[size];
		for (unsigned long long int i = 0; i < this->size; i++)
		{
			this->arr[i] = a;
		}
		return;
	}
	MyVector(const MyVector& obj)
	{
		this->arr = new inputType[obj.getSize()];
		this->size = obj.getSize();
		for (unsigned long long int i = 0; i < obj.getSize(); i++)
		{
			this->arr[i] = obj.getArray()[i];
		}
	}
	MyVector(MyVector&& obj)
	{
		this->arr = obj.getArray();
		this->size = obj.getSize();
		obj.arr = nullptr;
	}
	inputType& operator[](unsigned long long int index)
	{
		if (index < this->getSize())
		{
			return this->arr[index];
		}
		else
		{
			throw "The index is invalid!";
		}
	}
	inputType* getArray()
	{
		return this->arr;
	}
	void printVector()
	{
		cout << "Printing Vector..." << endl;
		for (unsigned long long int i = 0; i < this->getSize(); i++)
		{
			cout << this->arr[i] << endl;
		}
		return;
	}
	void addFront(const inputType& a)
	{
		inputType* temp = new inputType[size + 1];
		temp[0] = a;
		for (unsigned long long int i = 1; i < size + 1; i++)
		{
			temp[i] = arr[i];
		}
		delete[] this->arr;
		this->arr = temp;
		this->size++;
		return;
	}
	void pushBack(const inputType& a)
	{
		inputType* temp = new inputType[size + 1];
		for (unsigned long long int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = a;
		delete[] this->arr;
		this->arr = temp;
		this->size++;
		return;
	}
	inputType popFront()
	{
		if (this->size > 0)
		{
			inputType a = this->arr[0];
			inputType* temp = new inputType[this->size - 1];
			for (unsigned long long int i = 0; i < this->size - 1; i++)
			{
				temp[i] = this->arr[i + 1];
			}
			delete[] this->arr;
			this->arr = temp;
			this->size--;
			return a;
		}
	}
	inputType popBack()
	{
		if (this->size > 0)
		{
			inputType a = this->arr[size - 1];
			inputType* temp = new inputType[size - 1];
			for (unsigned long long int i = 0; i < this->size - 1; i++)
			{
				temp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp;
			this->size--;
			return a;
		}
	}
	unsigned long long int getSize()
	{
		return this->size;
	}
	void insertIn(const inputType& a, unsigned long long int index)
	{
		inputType* temp = new inputType[size + 1];
		unsigned long long int i = 0;
		for (; i < index; i++)
		{
			temp[i] = this->arr[i];
		}
		temp[index] = a;
		i++;
		for (; i < size + 1; i++)
		{
			temp[i] = this->arr[i - 1];
		}
		delete[] this->arr;
		this->arr = temp;
		this->size++;
		return;
	}
	inputType removeFrom(unsigned long long int index)
	{
		inputType a = this->arr[index];
		inputType* temp = new inputType[size - 1];
		unsigned long long int i = 0;
		for (; i < index; i++)
		{
			temp[i] = this->arr[i];
		}
		for (; i < size - 1; i++)
		{
			temp[i] = this->arr[i + 1];
		}
		delete[] this->arr;
		this->arr = temp;
		this->size--;
		return a;
	}
	long long int search(inputType key)
	{
		long long int index = -1;
		for (unsigned long long int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == key)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	~MyVector()
	{
		this->size = 0;
		delete[] this->arr;
		this->arr = nullptr;
	}
};

#endif
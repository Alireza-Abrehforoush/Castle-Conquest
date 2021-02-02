#ifndef MYVECTOR_FJSKDF
#define MYVECTOR_FJSKDF
#include <iostream>
using namespace std;
template <class inputType>
class MyVector
{
protected:
private:
	inputType* arr;
	unsigned long long int capacity;
	unsigned long long int size;
public:
	MyVector()
		:arr(new inputType[1])
		, capacity(1)
		, size(0)
	{
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
		this->arr = new inputType[obj.getCapacity()];
		this->size = obj.getSize();
		this->capacity = obj.getCapacity();
		for (unsigned long long int i = 0; i < obj.getSize(); i++)
		{
			this->arr[i] = obj.getArray()[i];
		}
	}
	MyVector(MyVector&& obj)
	{
		this->arr = obj.arr;
		this->size = obj.getSize();
		this->capacity = obj.getCapacity();
		obj.arr = nullptr;
	}
	inputType& operator[](unsigned long long int i)
	{
		if (i < this->getSize())
		{
			return this->arr[i];
		}
		else
		{
			throw "The index is invalid!";
		}
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

	void push(const inputType& a)
	{
		if (this->size == this->capacity)
		{
			inputType* temp = new inputType[2 * this->capacity];
			for (int i = 0; i < this->capacity; i++)
			{
				temp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->capacity *= 2;
			this->arr = temp;
		}
		this->arr[this->size] = a;
		this->size++;
	}

	void insert(const inputType& a, int i)
	{
		if (i == this->capacity)
		{
			this->push(a);
		}
		else
		{
			this->arr[i] = a;
		}
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

	void pop()
	{
		this->size--;
		if (this->size < this->capacity / 2)
		{
			inputType* temp = new inputType[this->capacity / 2];
			for (int i = 0; i < this->size; i++)
			{
				temp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp;
		}
	}

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->arr[i] << " ";
		}
		cout << endl;
	}

	inputType* getArray() const
	{
		return this->arr;
	}
	unsigned long long int getSize() const
	{
		return this->size;
	}
	unsigned long long int getCapacity() const
	{
		return this->capacity;
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
		this->capacity = 1;
		delete[] this->arr;
		this->arr = nullptr;
	}
};

#endif
#ifndef MYQUEUE_BHVCTCXWRDWFDWTULDHU
#define MYQUEUE_BHVCTCXWRDWFDWTULDHU
template <class inputType>
class MyQueue
{
protected:
private:
	inputType* queue = nullptr;
	long long int front = -1;
	long long int rear = -1;
	long long int capacity = 0;
public:
	MyQueue(long long int capacity = 10)
	{
		if (capacity > 0)
		{
			this->queue = new inputType[capacity];
			this->front = 0;
			this->rear = 0;
			this->capacity = capacity;
		}
		else throw "Entered value is invalid!";
	}
	MyQueue(const MyQueue& x)
	{
		delete[] this->queue;
		this->queue = new inputType[x.capacity];
		this->front = x.front;
		this->rear = x.rear;
		this->capacity = x.capacity;
		for (long long int i = x.front; i <= x.rear; i++)
		{
			this->queue[i] = x.queue[i];
		}
	}
	MyQueue(MyQueue&& x)
	{
		delete[] this->queue;
		this->queue = x.queue;
		this->front = x.front;
		this->rear = x.rear;
		this->capacity = x.capacity;
	}
	bool isEmpty()
	{
		return this->front == this->rear;
	}
	bool isFull()
	{
		if ((this->rear + 1) % this->capacity == this->front) return true;
		else return false;
	}
	inputType& getFront()
	{
		if (this->isEmpty()) throw "Queue is empty!";
		else
		{
			return this->queue[(this->front + 1) % this->capacity];
		}
	}
	inputType& getRear()
	{
		if (this->isEmpty()) throw "Queue is empty!";
		else
		{
			return this->queue[this->rear];
		}
	}
	void enqueue(const inputType& x)
	{
		if (this->isFull()) throw "Queue is full!";
		else
		{
			this->rear = (this->rear + 1) % this->capacity;
			this->queue[rear] = x;
		}
		return;
	}
	void dequeue()
	{
		if (this->isEmpty()) throw "Queue is empty!";
		else
		{
			this->front = (this->front + 1) % this->capacity;
			this->queue[this->front].~inputType();
		}
		return;
	}
	inline long long int getCapacity() const
	{
		return this->capacity;
	}
	long long int indexOf(const inputType& x) const
	{
		long long int index = -1;
		for (long long int i = this->front + 1; i <= this->rear; i++)
		{
			if (this->queue[i] == x)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	~MyQueue()
	{
		delete[] this->queue;
		this->queue = nullptr;
	}
};

#endif
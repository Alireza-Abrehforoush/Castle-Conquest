#ifndef VERTEX_BHUYVCFR
#define VERTEX_BHUYVCFR
template <class T>
class Vertex
{
protected:
private:
	T data;
	int degree;
public:
	Vertex(T data, int degree = 0)
		:data(data)
		,degree(degree)
	{
	}
	T& getData() const
	{
		return this->data;
	}
	int getDegree() const
	{
		return this->degree;
	}
	void setData(T data)
	{
		this->data = data;
		return;
	}
	void setDegree(int degree = 0)
	{
		this->degree = degree;
		return;
	}
};

#endif
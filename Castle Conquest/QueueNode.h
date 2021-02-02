#ifndef QUEUENODE_BUHBYEUJCBUJ
#define QUEUENODE_BUHBYEUJCBUJ
template <class T>
class QueueNode
{
protected:
private:
    T data;
    QueueNode<T>* next;
    
public:
    QueueNode(const T& data)
        :data(data)
        ,next(nullptr)
    {
    }
    void setData(const T& data)
    {
        this->data = data;
        return;
    }
    void setNext(QueueNode<T>* next)
    {
        this->next = next;
        return;
    }
    T getData() const
    {
        return this->data;
    }
    QueueNode<T>* getNext() const
    {
        return this->next;
    }
    ~QueueNode()
    {
        this->next = nullptr;
    }
};

#endif
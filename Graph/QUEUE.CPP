#include <iostream.h>

#include <alloc.h>

#include <stdlib.h>

 

typedef enum _boolean

{

    true = 1, false = 0

} bool;

 

 

 

template<class T>

class MyQueue

{

    class T *m_data;

    int m_numElements;

 

public:

    MyQueue() : m_data(NULL), m_numElements(0) { }

    ~MyQueue()

    {

      free(m_data);

      m_data = NULL;

      m_numElements = 0;

    }

 

    T front();

    int size()

    {

      return m_numElements;

    }


	int empty();

    bool push(T data);

    bool pop();

    bool Sort();

 

};

 

template<class T>

bool MyQueue<class T>::Sort()

{

      for(int i = 1; i < m_numElements; i++)

      {

          for(int j = 0; j < m_numElements - i; j++)

          {

            if(m_data[j] > m_data[j + 1])

            {

                T temp = m_data[j];

                m_data[j] = m_data[j + 1];

                m_data[j + 1] = temp;

            }

          }

      }

      return true;

}

 

template<class T>

bool MyQueue<class T>::push(T data)

{

      if(m_data == NULL) // root node

      {

          m_numElements = 1;

          m_data = (T*) malloc(sizeof(T));

      }

      else

      {

          m_numElements++;

          m_data = (T*) realloc(m_data, m_numElements * sizeof(T));

      }

 

      m_data[m_numElements - 1] = data;

      return true;

}

 

template<class T>

bool MyQueue<class T>::pop()

{

      if(m_data == NULL) // root node

      {

          return false;



      }

      else

      {

          if(m_numElements == 1)

          {

            // last item

            m_numElements = 0;

            free(m_data);

            m_data = NULL;

          }

          else

          {

            m_numElements--;

            memmove(m_data, &m_data[1], m_numElements * sizeof(T));

            m_data = (T*) realloc(m_data, m_numElements * sizeof(T));

          }

      }

      return true;

}

 

template<class T>

T MyQueue<class T>::front()

{

      if(m_numElements > 0)

          return m_data[0];

      return m_data[0];
}

template<class T>

int MyQueue<class T>::empty(){
	return m_numElements == 0;
}
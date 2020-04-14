#ifndef FCIVECTOR_H_
#define FCIVECTOR_H_

using namespace std ;

template<class T>

class FciVector
{
private:
    T *elements  ;
    int Capacity ;
    int numberOfElements ;

public:

    FciVector()
    {
        numberOfElements=0;
        Capacity = 0;
        elements = NULL ;

    }

    int numberOfElementsGetter()
    {
        return numberOfElements;
    }
    int size()
    {
        return numberOfElements ;
    }
    int capacity()
    {
        return Capacity ;
    }

    bool empty()
    {
        if(numberOfElements==0)
        {
            return true ;
        }
        else
        {
            return false ;
        }

    }

    T& operator[](int index)
    {
           return elements[index] ;
    }
    T* begin()
    {
        return &elements[0] ;
    }
    T& front()
    {
        return elements[0] ;
    }
    T& back()
    {
        return elements[numberOfElements-1] ;
    }

    void insert(T* position,T val )
    {
        bool flag = false ;
        int index = 0 ;

        if(numberOfElements==0)
        {
            Capacity++ ;
            elements = new T[Capacity] ;
            elements[0]=val ;
            numberOfElements++ ;

        }
        else
        {
            for(int i=0 ; i<=numberOfElements; i++)
            {
                if(begin()+i==position)
                {
                    index = i ;
                    flag = true ;
                    break;
                }
            }

            if(numberOfElements==Capacity)
            {
                Capacity*=2+1 ;
                T * arr = new T[Capacity];
                for (int i = 0; i < numberOfElements; i++)
                {
                    arr[i] = elements[i];
                }

                delete[] elements;

                elements = arr;
            }
            if(flag==true)
            {
                for(int i=numberOfElements ; i>index ; i--)
                {
                    elements[i]=elements[i-1];
                }
                elements[index+1]=val ;
                numberOfElements++ ;
            }
            else
            {
                cout<<"Invalid Position\n\n" ;
            }
        }

    }
    void push_back(T val)
    {
        T* end = &elements[numberOfElements-1] ;
        insert(end,val) ;
    }
    void pop_back()
    {
        T* end = &elements[numberOfElements-1] ;
        erase(end) ;
    }
    void clear()
    {
        delete[] elements;

        numberOfElements=0;
        Capacity = 0;
    }
    void erase(T* position)
    {
        bool flag = false ;
        int index = 0 ;

        if(numberOfElements==0)
        {
            cout<<"There is not Elements to Delete "<<endl ;
        }
        else
        {
            for(int i=0; i<numberOfElements; i++)
            {
                if(begin()+i==position)
                {
                    index = i ;
                    flag = true ;
                }
            }

            if(flag)
            {
                for(int i=index ; i<numberOfElements; i++)
                {
                    elements[i]=elements[i+1] ;
                }
                numberOfElements-- ;

            }
            else
            {
                cout<<"Invalid Position \n" ;
            }
        }
    }

};



#endif // FCIVECTOR_H_

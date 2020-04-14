// Name : Ahmed Mostafa AbdElkarim //
// ID : 20180031 //
// Group : 9 //

#include <iostream>
#include "FciVector.h"
#include "student.h"

template<typename T>
void operationMenu(FciVector <T> &) ;

using namespace std;

int StudentNumber = 0 ;
int main()
{

    while(true)
    {
        cout<<endl<<"Insert type of vector you would like to create: "<<endl ;
        cout<<"\t 1. list of integer"<<endl ;
        cout<<"\t 2. list of character"<<endl ;
        cout<<"\t 3. list of string"<<endl ;
        cout<<"\t 4. list of float"<<endl ;
        cout<<"\t 5. list of students"<<endl ;
        cout<<"\t 6. Exit"<<endl ;
        int choice ;
        cout<<"Your Choice: " ;
        cin>> choice ;
        system("cls") ;
        switch(choice)
        {
        case 1:
        {
            FciVector<int>myInt ;
            cout<<"A vector of integer was created successfully.\n\n" ;
            operationMenu(myInt) ;
            break;
        }
        case 2 :
        {
            FciVector<char>myChar ;
            cout<<"A vector of character was created successfully.\n\n" ;
            operationMenu(myChar) ;
            break;
        }
        case 3 :
        {
            FciVector<string>myString ;
            cout<<"A vector of string was created successfully.\n\n" ;
            operationMenu(myString) ;

            break;
        }
        case 4 :
        {
            FciVector<float>myFloat ;
            cout<<"A vector of float was created successfully.\n\n" ;
            operationMenu(myFloat) ;
            break;
        }
        case 5:
            {
                FciVector<student>myStudent ;
                cout<<"A vector of Students was created successfully.\n\n" ;
                operationMenu(myStudent) ;
                break;

            }

        case 6:
        {
            cout<<endl ;
            exit(0);
        }
        default:
        {
            cout<<endl<<"Invalid Inputs"<<endl<<endl  ;
            system("pause");
            system("cls") ;
        }

        }
    }

    return 0;
}

template<typename T>
void operationMenu(FciVector <T> &myvector)
{
    int repeat = 0 ;
    while(repeat==0)
    {
        char urChoice ;
        int choice ;
        cout<<endl<<"What kind of operation would you like to perform?"<<endl ;
        cout<<"\t 1. Add element."<<endl;
        cout<<"\t 2. Remove last element."<<endl;
        cout<<"\t 3. Insert element at certain position."<<endl;
        cout<<"\t 4. Erase element from a certain position."<<endl;
        cout<<"\t 5. Clear."<<endl;
        cout<<"\t 6. Display first element."<<endl;
        cout<<"\t 7. Display last element."<<endl;
        cout<<"\t 8. Display element at certain position."<<endl;
        cout<<"\t 9. Display vector size."<<endl;
        cout<<"\t 10. Display vector capacity."<<endl;
        cout<<"\t 11. Is empty?"<<endl;
        cout<<"\t YourChoice: " ;
        cin>>choice ;

        switch(choice)
        {
        case 1:
        {
            system("cls");
            int number ;
            cout<<"\nHow many elements you would like to add?  \n " ;
            cin>>number;
            for(int i=0; i<number; i++)
            {
                 T ele ;
                cout<<"Insert Your Element: \n" ;
                cin>>ele;
                myvector.push_back(ele) ;
                cout<<endl ;
            }
            break ;
        }
        case 2:
            {
                system("cls");
                myvector.pop_back();
                cout<<"\n last element Removed.\n\n" ;
                break ;
            }
        case 3:
            {
                system("cls");
                int position;
                T ele ;
                cout<<"\nPosition of Element u want to Add : " ;
                cin>>position ;
                cout<<" Enter Element: ";
                cin>>ele ;
                myvector.insert(&myvector[position-1],ele) ;
                cout<<"Your Element Inserted. \n\n" ;
                break ;
            }
        case 4:
            {
                system("cls");
                int position ;
                cout<<"\nPosition of Element u want to remove : " ;
                cin>>position ;
                if(position>=myvector.numberOfElementsGetter()||position<0)
                {
                    cout<<"Invalid Index \n\n" ;
                }else {
                myvector.erase(&myvector[position]) ;
                cout<<"Your Element Removed. \n\n" ;
                }
                break ;
            }
        case 5:
            {
                system("cls");
                myvector.clear() ;
                cout<<"\nNow Vector Is Empty \n\n" ;
                break ;
            }
        case 6:
            {
                system("cls");
                cout<<"\nThe first element is: "<<myvector.front()<<endl<<endl ;
                break;
            }
        case 7:
            {
                system("cls");
                cout<<"\nThe last element is: "<<myvector.back()<<endl<<endl ;
                break ;
            }
        case 8:
            {
                system("cls");
                int index ;
                cout<<"\nEnter the Position: ";
                cin>>index;
                if(index>=myvector.numberOfElementsGetter()||index<0)
                {
                    cout<<"Invalid Index \n\n" ;
                }else {
                cout<<"The element is: "<<myvector[index]<<endl<<endl ;
                }
                break ;
            }
        case 9:
            {
                cout<<"\nThe vector size is: "<<myvector.size()<<endl<<endl ;
                break ;
            }
        case 10:
            {
               cout<<"\nThe vector capacity is: "<<myvector.capacity()<<endl<<endl ;
               break ;
            }
        case 11:
            {
                if(myvector.empty())
                {
                    cout<<"\nYes Its empty \n\n";
                }else{
                    cout<<"\nNo Its not empty \n\n";
                }
                break;
            }
        default:
        {
            cout<<"\nInvalid Input"<<endl ;
            system("pause");
            system("cls") ;
        }
        }

        cout<<"Would you like to perform other operations?  (Y,N) \n" ;
        while(true)
        {
            cin>>urChoice ;
            if(urChoice=='N'||urChoice=='n')
            {
                repeat = 1 ;
                system("cls") ;
                break;
            }
            else if(urChoice=='Y'||urChoice=='y')
            {
                system("cls" );
                break ;

            }
            else
            {
                cout<<"Invalid Char Enter it Again \n\n Your Choice : " ;
            }
        }
    }
}

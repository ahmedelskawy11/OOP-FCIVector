#ifndef STUDENT_H_
#define STUDENT_H_
#include "course.h"
using namespace std ;


class student
{
private:
    string sName  ;
    int sID  ;
    string sDepartment  ;
    FciVector<course>sCourses ;

public:
    student() {}
    student(const string&  x, const int& id, const string& y)
    {
        sName = x;
        sID = id ;
        sDepartment = y;
    }
//    void printInfo()
//    {
//        cout<<endl<<endl ;
//        cout<<"\t Student Name: "<<sName<<endl ;
//        cout<<"\t Student ID: "<<sID<<endl ;
//        cout<<"\t Student Department: "<<sDepartment<<endl ;
//        cout<<endl ;
//        cout<<"\t Courses "<<endl;
//        for(int i=0;i<sCourses.size();i++)
//        {
//                cout<<endl<<"\t\t[ "<<i+1<<" ]" <<endl<<endl ;
//                sCourses[i].printCourseInfo();
//        }
//    }

    void courseDecl(string name,string code,char grade,float point,int year,int semester)
    {
        sCourses.push_back(course(name,code,grade,point,year,semester)) ;
    }

    friend ostream& operator << (ostream &out, student &myStudent)
    {
        out << "\n\t Student Name: "<<myStudent.sName<<endl ;
        out << "\t Student ID:  "<<myStudent.sID<<endl ;
        out << "\t Student Department: "<<myStudent.sDepartment<<endl ;
        out<<endl ;
        out<<"\t Courses "<<endl;
        for (int i=0; i<myStudent.sCourses.size(); i++)
        {
            out<<endl<<"\t\t[ "<<i+1<<" ]" <<endl<<endl ;
            myStudent.sCourses[i].printCourseInfo();
         }
        return out;
    }
    friend istream& operator >> (std::istream& in, student &myStudent)
    {
        int numberOfCourses ;
        cout<<"\n\tStudent name: ";
        in>>myStudent.sName ;
        cout<<"\tStudent ID: ";
        in>>myStudent.sID ;
        cout<<"\tStudent Department: ";
        in>>myStudent.sDepartment ;
        cout<<endl ;
        cout<<"\tNumber of Courses: ";
        in>>numberOfCourses ;
        cout<<endl ;

        for(int i=0; i<numberOfCourses; i++)
        {
            string courseName,courseCode;
            int courseYear,courseSemester;
            float coursePoint;
            char courseGrade;
            cout<<" Course :"<<i+1<<endl ;
            cout<<"\tCourse Name: ";
            in>>courseName;
            cout<<"\tCourse Code: ";
            in>>courseCode ;
            cout<<"\tCourse Grade: " ;
            in>>courseGrade ;
            cout<<"\tCourse point: ";
            in>>coursePoint ;
            cout<<"\tCourse year: ";
            in>>courseYear ;
            cout<<"\tCourse Semester: ";
            in>>courseSemester ;
            myStudent.courseDecl(courseName,courseCode,courseGrade,coursePoint,courseYear,courseSemester);
            cout<<endl<<endl;
        }
        return in;
    }
};


#endif // STUDENT_H_

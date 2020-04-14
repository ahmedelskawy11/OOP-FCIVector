#ifndef COURSE_H_
#define COURSE_H_

using namespace std ;

class course
{
private:
    string courseName;
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear ;
    int courseSemester;
public:
    course(){};
    course(string name,string code,char grade,float point,int year,int semester)
    {
        courseName = name;
        courseCode = code ;
        courseGrade = grade ;
        coursePoint = point ;
        courseYear = year ;
        courseSemester = semester ;

    }

    void printCourseInfo()
    {
        cout<<"\t\tCourse Name: "<< courseName<<endl ;
        cout<<"\t\tCourse Code: "<< courseCode<<endl ;
        cout<<"\t\tCourse Grade: "<< courseGrade<<endl ;
        cout<<"\t\tCourse point: "<< coursePoint<<endl ;
        cout<<"\t\tCourse year: "<< courseYear<<endl ;
        cout<<"\t\tCourse Semester: "<< courseSemester<<endl ;
    }
};


#endif // COURSE_H_

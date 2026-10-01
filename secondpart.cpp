#include <iostream>
#include <string>
#include <map>
//#include <tuple>


using namespace std;


//class Course;

class Person{
    private:
        static int count;    
        int keynumber;                            //keynumber can be whatever eg ID number or sdi etc   
        int age;
        string name;
        string lastname;
    public:
        Person(){
            count++;
            cout<<"constructed"<<endl;
        }
        Person(int k, int a,string n,string l){
            keynumber=k;
            age=a;
            count++;
            name=n; 
            lastname=l; 
            cout<<"person constructed"<<endl;
        }
        ~Person(){
            count--;
            //cout<<"person deconstructed"<<endl;
        }
        static int getcount(){                
            return count;                          //static is sos if you wanna be able to call it not on an instance
        }
};

int Person::count=0;                                                              


class Professor:public Person{
    private:
    public:
        Professor(int k, int a, string n, string l) : Person(k, a, n, l){}
};


class Student;

class Course{
    private:
        Professor* prof;
        Student* stud;     
    public:
        int monades;
        string obligatory;
        string name;
        int semester;      
        Course(int s,int m,string o,string n,Professor* p):semester(s),monades(m),obligatory(o),name(n),prof(p){
            cout<<"course constructed"<<endl;
        }
        void addstudent(Student* s) {
            stud=s;
            cout<<"student added to the course"<<endl;
        }
        void changesem(Course* oldsem,int newsem){
            oldsem->semester=newsem;
        }
};


class Student:public Person{
    private:
        static int posa;
        int monades;
    public:
        static int perasmena;
        map<int,tuple<int,int,string,int,string>> myMap;
        int semester;
        Student(int k, int a, string n, string l, int sem, int mon) : Person(k, a, n, l), semester(sem), monades(mon) {
        }
        void addcourse(Course* cou){
            myMap[posa]=make_tuple(0,0,cou->name,cou->monades,cou->obligatory);   //both grade and perase are 0 in the beginning      
            posa++;
        }
        void degree(){
            if(semester==9 && monades==15 && perasmena==15){                    //the numbers can be whatever the university wants
                cout<<"that student can get the degree now";
            }
            else{
                cout<<"that student can not get the degree now";
            }
        }
};

int Student::posa=0; 
int Student::perasmena=0; 




int main(){  
    cout<<"hello we are now in the beginning of the new semester!"<<endl;

    int studkey=12,studage=19,studsem=1,studmon=10;
    string studname="john",studlast="karras";
    Student s1(studkey,studage,studname,studlast,studsem,studmon);
    int profkey=13,profage=39;
    string profname="makhs",proflast="oskar";
    Professor p1(profkey,profage,profname,proflast);
    int coursem=1,courmon=2;
    string courobl="YES",courname="algebra";
    Professor* courprof=&p1;
    Course c1(coursem,courmon,courobl,courname,courprof);
    
    if (s1.semester>=c1.semester){  
        Student* stu=&s1;   
        c1.addstudent(stu);
        Course* cou=&c1;   
        s1.addcourse(cou);
    }
    
    cout<<"hello we are now at the end of the new semester!";

    studsem++;
    studmon++; 
    int studvathmoscourse=6;
    int perase=(studvathmoscourse>=5)?1:0; 
    Course* cou=&c1;
    if (perase==1 && cou->obligatory=="YES"){
        Student::perasmena++;
    }
    s1.myMap[0]=make_tuple(studvathmoscourse, perase, get<2>(s1.myMap[0]), get<3>(s1.myMap[0]), get<4>(s1.myMap[0]));

    return 0;
}
#include <iostream>
using namespace std;

class Student{

    private:
    int id, year;
    string name;
    char gender;
    double gpa;

    public:
    Student(int si, string sn, double sg, int sy, char sf){
      id=si;
      name=sn;
      gpa=sg;
      year=sy;
      gender=sf;
      }
     Student(){}
    ~Student(){}

    void setid(int i){
		id=i;
	}
    int getid(){
		return id;
	}
    void setname(string n){
		name=n;
	}
    string getname(){
		return name;
	}
    void setgpa(double g){
		gpa=g;
	}
    double getgpa(){
		return gpa;
	}
    void setyear(int y){
		year=y;
	}
    int getyear(){
		return year;
	}
    void setgender(char f){
		gender=f;
	}
    char getgender(){
		return gender;
  }

    void compare(Student s1, Student s2, Student s3, Student s4, Student s5);

    friend bool operator>=(Student &, Student &);
    friend ostream &operator<<( ostream &myout, Student &s);
    friend istream &operator>>( istream &myin, Student &s);
};

void Student::compare(Student s1, Student s2, Student s3, Student s4, Student s5){
  Student max=s1;
  Student students[4]={s2,s3,s4,s5};
  for(int i=0;i<5;i++){
    if(students[i]>=max)
    max=students[i];
  }
  cout<<"Highest GPA belongs to "<<max.name<<":"<<max.gpa<<endl;
}

bool operator>=(Student &st1, Student &st2){
	return (st1.gpa >= st2.gpa);
}
ostream &operator<<(ostream &myout, Student &s){
	myout << "Student ID: " << s.id <<", Name: "<<s.name;
	return myout;
}
istream &operator>>(istream &myin, Student &s){
  cout<<"Enter student information (ID, name, gpa, year, gender)"<<endl;
  myin>>s.id;
  getline(cin>>ws, s.name);
  myin>>s.gpa>>s.year>>s.gender;
  return myin;
}

int main(){
    Student one(1,"Harry Potter",3.4,2,'m');
    Student two(2,"Hermione Granger",3.8,2,'f');
    Student three(3,"Ron Weasley",3.1,2,'m');
    Student four(4,"Draco Malfoy",2.9,2,'m');
    Student five;

    cin>>five;

    cout<<one<<endl;
    cout<<two<<endl;
    cout<<three<<endl;
    cout<<four<<endl;
    cout<<five<<endl;
    
    one.compare(one,two,three,four,five);

system("pause");
return 0;
}
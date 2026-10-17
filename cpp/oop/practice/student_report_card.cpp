#include<iostream>
using namespace std;

class Student {
    private:
        string name;
        int roll_number;
        int marks[3];
        int percentage;

    public:
        Student(string name , int roll_number, int sub1, int sub2, int sub3) {
            if(sub1 < 0 || sub1 > 100) throw "Invalid marks in Subject 1";
            if(sub2 < 0 || sub2 > 100) throw "Invalid marks in Subject 2";
            if(sub3 < 0 || sub3 > 100) throw "Invalid marks in Subject 3";

            this->name = name;
            this->roll_number = roll_number;
            marks[0] = sub1;
            marks[1] = sub2;
            marks[2] = sub3; 
            percentage = (sub1 + sub2 + sub3) / 3;
        }

        int get_percentage() {
            return percentage;
        }

        void display_grade() {
            if(percentage >= 90) cout<<"A+ Grade\n";
            else if(percentage >= 80) cout<<"A Grade\n";
            else if(percentage >= 70) cout<<"B+ Grade\n";
            else if(percentage >= 60) cout<<"B Grade\n";
            else if(percentage >= 50) cout<<"C+ Grade\n";
            else if(percentage >= 40) cout<<"C Grade\n";
            else cout<<"Fail\n";
        }

};

int main () {
    try{
        Student st = Student("Vikas",14,55,600,40);
        cout<<st.get_percentage()<<endl;
        st.display_grade();
    } catch (const char* e) {
        cout<<e<<endl;
    }
}
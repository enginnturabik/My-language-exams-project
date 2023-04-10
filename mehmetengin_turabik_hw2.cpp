#include<iostream>
#include <string>
#include <cmath>
using namespace std;
class Date{
public:
    int day,month,year;
};
class Exam{
public:
    Date date;
    string name;
    double total_score;
    virtual double calculate_total()=0;

    void set_name(string name)
    {
        this->name=name;
    }
    void  set_date(int day,int month,int year)
    {
        date.day=day;
        date.month=month;
        date.year=year;
    }

    void  print_date()
    {
        cout<<date.day<<"/"<<date.month<<"/"<<date.year<<endl;
    }

};

class TOEFL:public Exam{

    int reading;
    int listening;
    int speaking;
    int writing;

public:

    int set_reading(int );
    int set_listening(int );
    int set_speaking(int );
    int set_writing(int );


    string exam_type();

    int get_reading();
    int get_listening();
    int get_speaking();
    int get_writing();




    double calculate_total() override
    {
        int total=reading+listening+speaking+writing;
        return total;
    }
};

int TOEFL::set_reading(int reading)
{
    this->reading =reading;
    return reading;
}

int TOEFL::set_listening(int listening)
{
    this->listening=listening;
    return listening;
}

int TOEFL::set_speaking(int speaking)
{
    this->speaking=speaking;
    return speaking;
}

int TOEFL::set_writing(int writing )
{
    this->writing=writing;
    return writing;
}
string TOEFL::exam_type()
{
return "TOEFL";
}

int TOEFL::get_listening()
{
    return listening;
}

int TOEFL::get_reading()
{
    return reading;
}

int TOEFL::get_writing()
{
    return writing;
}

int TOEFL::get_speaking()
{
    return speaking;
}

class IELTS:public Exam{
    int Reading=0 ,Listening=0,Speaking=0,Writing =0;
public:



    void set_Reading(int );
    void set_Listening(int );
    void set_Speaking(int );
    void set_Writing(int);

    double calculate_total() override
    {
        cout<<"Reading: "<<IELTS_Score(Reading);
        cout<<" Listening: "<<IELTS_Score(Listening);
        cout<<" Speaking: "<<IELTS_Score(Speaking);
        cout<<" Writing: "<<IELTS_Score(Writing)<<endl;

        double band_score_reading= IELTS_Score(Reading);
        double band_score_listening= IELTS_Score(Listening);
        double band_score_writing= IELTS_Score(Writing);
        double band_score_speaking= IELTS_Score(Speaking);
        double  total_score= ::round((band_score_reading+band_score_listening+band_score_speaking+band_score_writing)/4);
        cout<<"Total score: ";
        cout<<total_score;
        return total_score;


    }

    double IELTS_Score(int current) {
        double score;

        if (current == 40) {
            score = 9.0;
        } else if (current == 39) {
            score = 8.5;
        } else if (current == 38) {
            score = 8.0;
        } else if (current >= 36) {
            score = 7.5;
        } else if (current >= 34) {
            score = 7.0;
        } else if (current >= 32) {
            score = 6.5;
        } else if (current >= 30) {
            score = 6.0;
        } else if (current >= 26) {
            score = 5.5;
        } else if (current >= 23) {
            score = 5.0;
        } else if (current >= 19) {
            score = 4.5;
        } else if (current >= 15) {
            score = 4.0;
        } else if (current >= 12) {
            score = 3.5;
        } else if (current >= 8) {
            score = 3.0;
        } else if (current >= 5) {
            score = 2.5;
        } else if (current >= 2) {
            score = 2.0;
        } else if (current == 1) {
            score = 1.0;
        } else {
            score = 0.0;
        }

        return score;

    }

};

void IELTS::set_Reading(int reading)
{
    Reading=reading;
}
void IELTS::set_Listening(int listening)
{
    Listening=listening ;
}
void IELTS::set_Speaking(int speaking)
{
    Speaking=speaking;
}
void IELTS::set_Writing(int writing)
{
    Writing=writing;
}
class Yokdil:public Exam{
    int correct_answers;
public:
    void set_correct_answers(int correct_answers)
            {
                this->correct_answers=correct_answers;
            }

    double calculate_total() override{
        total_score=correct_answers*1.25;
        return total_score;
    }




};

int main(){
    TOEFL toefl;
    IELTS ielts;
    Yokdil yokdil;

    string student_name;
    int day,month,year;
    char exam_type;


    cout<<"Enter name of student :";    //main part
    cin>>student_name;
    cout<<"Enter date of exam:";
    cin>>day>>month>>year;
    cout<<"Enter T for TOEFL,I for IELTS or Y for Yokdil:";
    cin>>exam_type;
    if (exam_type=='T')
    {

        toefl.set_name(student_name);
        toefl.set_date(day,month,year);




        int Reading, Listening,Speaking,Writing;
        cout<<"Enter score for Reading :"<<endl;
        cin>>Reading;
        toefl.set_reading(Reading);

        cout<<"Enter score for Listening :"<<endl;
        cin>>Listening;
        toefl.set_listening(Listening);

        cout<<"Enter score for Speaking :"<<endl;
        cin>>Speaking;
        toefl.set_speaking(Speaking);

        cout<<"Enter score for Writing :"<<endl;
        cin>>Writing;
        toefl.set_writing(Writing);

            cout<<"Name: "<<toefl.name<<" Exam: "<<toefl.exam_type()<<" date of exam: ";
            toefl.print_date();   //print date
            cout<<"Reading: "<<toefl.get_reading()<<" Listening: "<<toefl.get_listening()<<" Speaking:"<<toefl.get_speaking()<<" Writing: "<<toefl.get_writing()<<endl;
            cout<<"Total score: "<<toefl.calculate_total()<<endl;

    }

    if (exam_type=='I')
    {
        int Reading,Listening,Speaking,Writing;

        ielts.set_date(day,month,year);
        ielts.set_name(student_name);


        cout<<"Enter score for Reading: "<<endl;
        cin>>Reading;
        ielts.set_Reading(Reading);
        ielts.IELTS_Score(Reading);

        cout<<"Enter score for Listening: "<<endl;
        cin>>Listening;
        ielts.set_Listening(Listening);

        cout<<"Enter score for Speaking: "<<endl;
        cin>>Speaking;
        ielts.set_Speaking(Speaking);

        cout<<"Enter score for Writing: "<<endl;
        cin>>Writing;
        ielts.set_Writing(Writing);

        cout<<"Name: "<<ielts.name<<" Exam: IELTS "<<"Date of exam: " ;

        ielts.print_date();
        ielts.calculate_total();
    }

        if (exam_type=='Y')
        {
            int  correct_answer;
            yokdil.set_name(student_name);
            yokdil.set_date(day,month,year);

            cout<<"Enter number of correct answers:";
            cin>>correct_answer;
            cout<<"Name: "<<yokdil.name<<" Exam: Yokdil "<<" Date of exam: ";
            yokdil.print_date();
            yokdil.set_correct_answers(correct_answer);
            cout<<"Total score: ";
            cout<<yokdil.calculate_total();
        }





    return 0;
}


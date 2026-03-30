#ifndef DATE_HPP
#define DATE_HPP
using namespace std;

class Date{

    private:

        int day;

        int month;

        int year;

    public:
        
        Date () : day(1), month(1), year(2000) {}

        Date(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
    
        }
    
        int getDay() const {

            return this->day;

        }

        int getMonth() const {

            return this->month;

        }

        int getYear() const {

            return this->year;

        }

        bool operator==(const Date& other) const {

            return (this->day == other.day) && (this->month == other.month) && (this->year == other.year);

        }

};

#endif
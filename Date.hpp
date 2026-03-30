#ifndef DATE_HPP
#define DATE_HPP

class Date{

    private:

        int day;

        int month;

        int year;

        int hour;

        int minutes;

    public:

        int GetDay() {

            return this->day;

        }

        int GetMonth() {

            return this->month;

        }

        int GetYear() {

            return this->year;

        }

        int GetHour() {

            return this->hour;

        }

        int GetMinutes() {

            return this->minutes;

        }

        void SetDay(int newDay) {

            this->day = newDay;

        }

        void SetMonth(int newMonth) {

            this->month = newMonth;

        }

        void SetYear(int newYear) {

            this->year = newYear;

        }

        void SetHour(int newHour) {

            this->hour = newHour;

        }

        void SetMinutes(int newMinutes) {

            this->minutes = newMinutes;

        }

};

#endif
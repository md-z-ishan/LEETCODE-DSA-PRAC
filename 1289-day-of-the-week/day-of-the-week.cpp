class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};

        int totalDays = 4; 

        for(int y = 1971; y < year; y++){
            totalDays += 365;
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                totalDays += 1;
        }

        for(int m = 1; m < month; m++){
            totalDays += monthDays[m-1];
            if(m == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
                totalDays += 1;
        }

        totalDays += day;

        return days[totalDays % 7];

    }
};
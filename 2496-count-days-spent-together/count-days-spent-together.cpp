class Solution {
private:
    int convertToDays(string date) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonths[i];
        }
       
        totalDays += day;
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrival = convertToDays(arriveAlice);
        int aliceLeave = convertToDays(leaveAlice);
        int bobArrival = convertToDays(arriveBob);
        int bobLeave = convertToDays(leaveBob);
        
        int overlapStart = max(aliceArrival, bobArrival);
        int overlapEnd = min(aliceLeave, bobLeave);
        
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};
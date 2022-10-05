#pragma once

using namespace std;

class Solution
{
protected:
    typedef string CarNumber;

    const string NoOut = "23:59 OUT";
public:

    vector<int> CalculateParkingFee(vector<int> fees, vector<string> records);

    void ReadRecods(map<CarNumber, vector<string>>& RecordPerCar, const vector<string>& Records);

    int CalculateFeePerCar(vector<string>& Records, const vector<int>& Fees);
};

vector<int> Solution::CalculateParkingFee(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<CarNumber, vector<string>> RecordPerCar;
    map<CarNumber, int> ChargePerCar;

    ReadRecods(RecordPerCar, records);

    for (pair<const CarNumber, vector<string>>& Car : RecordPerCar) // O(C) C== Number Of CarNumber
    {
        int CarFee = CalculateFeePerCar(Car.second, fees);
        ChargePerCar[Car.first] = CarFee;
    }

    answer.reserve(ChargePerCar.size());
    for (pair<const CarNumber, int>& Car : ChargePerCar) // O(C)
    {
        answer.emplace_back(Car.second);
    }

    return answer;
}

void Solution::ReadRecods(map<CarNumber, vector<string>>& RecordPerCar, const vector<string>& Records) // O(NMlogN) N==Records.size() M==Record.size()
{
    for (const string& Record : Records)
    {
        stringstream Reading(Record);
        string Time, CarNumber, History;
        Reading >> Time >> CarNumber >> History;

        RecordPerCar[CarNumber].push_back(Time + ' ' + History);
    }
}

int Solution::CalculateFeePerCar(vector<string>& Records, const vector<int>& Fees) // O(N)
{
    if (Records.size() & 1)
    {
        Records.push_back(NoOut);
    }
    int TotalFee = Fees[1];
    double TotalTime = 0;
    for (string& Record : Records)
    {
        string Hour = Record.substr(0, 2);
        string Minute = Record.substr(3, 2);
        double Time = stod(Hour) * 60 + stod(Minute);
        if (Record[6] == 'I')
        {
            TotalTime -= Time;
        }
        else if (Record[6] == 'O')
        {
            TotalTime += Time;
        }
    }
    if (TotalTime > Fees[0])
    {
        TotalFee += static_cast<int>(ceil((TotalTime - Fees[0]) / Fees[2]) * Fees[3]);
    }
    return TotalFee;
}


/*
dataset info
        0 - ID (int)
        1 - trans_date_trans_time (date, time, YYYY-MM-DD HH:MM:SS, radi jednostavnosti ovdje se to sprema u string)
        2 - cc_num (double, neki su brojevi spremljeni kao "4.99234639806515E+018" ali nasreću nema problema pri unosu)
        3 - merchant (string, svi imaju fraud_ prefix)
        4 - category  (string)
        5 - amt (float)
        6 - first (string)
        7 - last  (string)
        8 - gender (M/F, spremljeno kao char)
        9 - street (string, sadrži ulicu i kucni broj)
        10 - city (string)
        11 - state (string, 2 slova)
        12 - zip (int)
        13 - lat (float)
        14 - long (float)
        15 - city_pop (int)
        16 - job (string)
        17 - dob (date, YYYY-MM-DD, radi jednostavnosti ovdje se to sprema u string)
        18 - trans_num (hash??? idk, spremam kao string)
        19 - unix_time (double)
        20 - merch_lat (float)
        21 - merch_long (float)
        22 - is_fraud (bool)

        555720 redova
        prvi slog je samo opis podataka
        stupci su razdvojeni zarezom, ali ukoliko neki podatak sadrži zarez taj podatak je u dvostrukim navodnicima
        nema EOL oznaka
*/

// general stuff
#include <iostream>

// file loading
#include <fstream>

// setprecision
#include <iomanip>

// hashmap
#include <map>

// vector
#include <vector>

// find
#include <algorithm>

// chrono time
#include <chrono>
using namespace std::chrono;

std::chrono::time_point<std::chrono::high_resolution_clock> start;
void startTime()
{
    start = high_resolution_clock::now();
}
void stopAndPrintFunctionTime(std::string function_name)
{
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Izvršavanje funkcije " << function_name << " je trajalo " << duration.count() << " mikrosekundi" << std::endl;
    start = high_resolution_clock::now();

}




struct fraud_data
{
    int ID;
    std::string trans_date_trans_time; // (date, time, YYYY-MM-DD HH:MM:SS), should be something proper
    double cc_num;                     // std::setprecision(15)
    std::string merchant;
    std::string category;
    float amt;
    std::string first;
    std::string last;
    char gender;
    std::string street;
    std::string city;
    std::string state;
    int zip;
    float loc_lat;
    float loc_long; // loc_long because putting just long makes the compiler cry inside
    int city_pop;
    std::string job;
    std::string dob; // (date, YYYY-MM-DD), should be something proper
    std::string trans_num;
    double unix_time;
    float merch_lat;
    float merch_long;
    bool is_fraud;

    bool operator==(fraud_data &x)
    {
        if (ID == x.ID)
            if (cc_num == x.cc_num)
                if (trans_date_trans_time == x.trans_date_trans_time)
                    if (merchant == x.merchant)
                        if (category == x.category)
                            if (amt == x.amt)
                                if (first == x.first)
                                    if (last == x.last)
                                        if (gender == x.gender)
                                            if (street == x.street)
                                                if (city == x.city)
                                                    if (state == x.state)
                                                        if (zip == x.zip)
                                                            if (loc_lat == x.loc_lat)
                                                                if (loc_long == x.loc_long)
                                                                    if (city_pop == x.city_pop)
                                                                        if (job == x.job)
                                                                            if (dob == x.dob)
                                                                                if (trans_num == x.trans_num)
                                                                                    if (unix_time == x.unix_time)
                                                                                        if (merch_lat == x.merch_lat)
                                                                                            if (merch_long == x.merch_long)
                                                                                                if (is_fraud == x.is_fraud)
                                                                                                    return true;
        return false;
    }
    bool operator!=(fraud_data &x)
    {
        if (ID == x.ID)
            if (cc_num == x.cc_num)
                if (trans_date_trans_time == x.trans_date_trans_time)
                    if (merchant == x.merchant)
                        if (category == x.category)
                            if (amt == x.amt)
                                if (first == x.first)
                                    if (last == x.last)
                                        if (gender == x.gender)
                                            if (street == x.street)
                                                if (city == x.city)
                                                    if (state == x.state)
                                                        if (zip == x.zip)
                                                            if (loc_lat == x.loc_lat)
                                                                if (loc_long == x.loc_long)
                                                                    if (city_pop == x.city_pop)
                                                                        if (job == x.job)
                                                                            if (dob == x.dob)
                                                                                if (trans_num == x.trans_num)
                                                                                    if (unix_time == x.unix_time)
                                                                                        if (merch_lat == x.merch_lat)
                                                                                            if (merch_long == x.merch_long)
                                                                                                if (is_fraud == x.is_fraud)
                                                                                                    return false;
        return true;
    }
};


void fraud_data_info(fraud_data info)
{
    std::cout << "ID: " << info.ID << std::endl;
    std::cout << "trans_date_trans_time: " << info.trans_date_trans_time << std::endl;
    std::cout << std::setprecision(15) << "cc_num: " << info.cc_num << std::endl;
    std::cout << "merchant: " << info.merchant << std::endl;
    std::cout << "category: " << info.category << std::endl;
    std::cout << "amt: " << info.amt << std::endl;
    std::cout << "first: " << info.first << std::endl;
    std::cout << "last: " << info.last << std::endl;
    std::cout << "gender: " << info.gender << std::endl;
    std::cout << "street: " << info.street << std::endl;
    std::cout << "city: " << info.city << std::endl;
    std::cout << "state: " << info.state << std::endl;
    std::cout << "zip: " << info.zip << std::endl;
    std::cout << "loc_lat: " << info.loc_lat << std::endl;
    std::cout << "loc_long: " << info.loc_long << std::endl;
    std::cout << "city_pop: " << info.city_pop << std::endl;
    std::cout << "job: " << info.job << std::endl;
    std::cout << "dob: " << info.dob << std::endl;
    std::cout << "trans_num: " << info.trans_num << std::endl;
    std::cout << "unix_time: " << info.unix_time << std::endl;
    std::cout << "merch_lat: " << info.merch_lat << std::endl;
    std::cout << "merch_long: " << info.merch_long << std::endl;
    std::cout << "is_fraud: " << info.is_fraud << std::endl;
}

class fraud_database
{
private:
    std::map<int, fraud_data> keyIsID;
    std::multimap<double, fraud_data> keyIsCC_num;
    std::multimap<double, fraud_data> keyIsCity_pop;
    // originalno sam mislio imati max heap i min heap za sve ali zbog veličine dataseta to nije baš pametno
    // plus map i multimap su već sorted
    fraud_data generateEmptyReturnData()
    {
        fraud_data empty;
        empty.ID = -1;
        empty.unix_time = 0;
        empty.trans_date_trans_time = "0000-00-00 00:00:00";
        empty.cc_num = 0;
        empty.merchant = "";
        empty.category = "";
        empty.amt = 0;
        empty.first = "";
        empty.last = "";
        empty.gender = 'M';
        empty.street = "";
        empty.city = "";
        empty.state = "";
        empty.zip = 0;
        empty.loc_lat = 0;
        empty.loc_long = 0;
        empty.city_pop = 0;
        empty.job = "";
        empty.dob = "0000-00-00";
        empty.trans_num = '0';
        empty.merch_lat = 0;
        empty.merch_long = 0;
        empty.is_fraud = 0;
        return empty;
    }
    fraud_data generateEmptyData()
    {
        fraud_data empty = generateEmptyReturnData();
        empty.ID = returnMaxIDValue() + 1;
        return empty;
    }
        
    char stoc(std::string s)
    {
        return s[0];
    }

public:
    /*

            ID

    */

    int returnMaxIDValue()
    {
        return keyIsID.rbegin()->first;
    }
    std::vector<int> returnMaxIDValue(int N)
    {
        std::vector<int> maxIDs;
        auto key = keyIsID.rbegin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(key->first);
            key++;
        }
        return maxIDs;
    }
    fraud_data returnMaxIDData()
    {
        return keyIsID.rbegin()->second;
    }
    std::vector<fraud_data> returnMaxIDData(int N)
    {
        std::vector<fraud_data> maxIDs;
        auto key = keyIsID.rbegin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(key->second);
            key++;
        }
        return maxIDs;
    }
    std::pair<int, fraud_data> returnMaxIDandData()
    {
        return *keyIsID.rbegin();
    }
    std::vector<std::pair<int, fraud_data>> returnMaxIDandData(int N)
    {
        std::vector<std::pair<int, fraud_data>> maxIDs;
        auto key = keyIsID.rbegin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(*key);
            key++;
        }
        return maxIDs;
    }

    int returnMinIDValue()
    {
        return keyIsID.begin()->first;
    }
    std::vector<int> returnMinIDValue(int N)
    {
        std::vector<int> maxIDs;
        auto key = keyIsID.begin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(key->first);
            key++;
        }
        return maxIDs;
    }
    fraud_data returnMinIDData()
    {
        return keyIsID.begin()->second;
    }
    std::vector<fraud_data> returnMinIDData(int N)
    {
        std::vector<fraud_data> maxIDs;
        auto key = keyIsID.begin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(key->second);
            key++;
        }
        return maxIDs;
    }
    std::pair<int, fraud_data> returnMinIDandData()
    {
        return *keyIsID.begin();
    }
    std::vector<std::pair<int, fraud_data>> returnMinIDandData(int N)
    {
        std::vector<std::pair<int, fraud_data>> maxIDs;
        auto key = keyIsID.begin();
        for (int i = 0; i < N; i++)
        {
            maxIDs.push_back(*key);
            key++;
        }
        return maxIDs;
    }

    bool addByID(int ID, fraud_data data)
    {
        data.ID = ID;
        if (searchByID(ID) == true)
            return false;

        keyIsID.insert({data.ID, data});
        keyIsCC_num.insert({data.cc_num, data});
        keyIsCity_pop.insert({data.city_pop, data});
        return true;
    }
    bool addByID(int ID)
    {
        return addByID(ID, generateEmptyData());
    }
    bool addByID(fraud_data data)
    {
        return addByID(data.ID, data);
    }
    bool addByID(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool success = addByID(*data.rbegin());
            data.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByID(std::vector<int> IDs)
    {
        bool allSuccess = true;
        while (!IDs.empty())
        {
            bool success = addByID(*IDs.rbegin());
            IDs.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByID(std::vector<std::pair<int, fraud_data>> IDAndData)
    {
        bool allSuccess = true;
        while (!IDAndData.empty())
        {
            auto iteratorIDData = IDAndData.rbegin();
            bool success = addByID(iteratorIDData->first, iteratorIDData->second);
            IDAndData.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }

    // nema smisla imati search po id i vrijednosti
    bool searchByID(int ID)
    {
        auto search = keyIsID.find(ID);
        if (search != keyIsID.end())
            return true;
        else
            return false;
    }
    bool searchByID(fraud_data data)
    {

        auto search = keyIsID.find(data.ID);
        if (search != keyIsID.end())
        {
                return true;
        }
        else
            return false;
    }
    bool searchByID(std::vector<fraud_data> data)
    {
        while (!data.empty())
        {
            bool searchSuccess = searchByID(*data.rbegin());
            if (searchSuccess == false)
                return false;
            data.pop_back();
        }
        return true;
    }
    bool searchByID(std::vector<int> IDs)
    {
        while (!IDs.empty())
        {
            bool searchSuccess = searchByID(*IDs.rbegin());
            if (searchSuccess == false)
                return false;
            IDs.pop_back();
        }
        return true;
    }

    // Nema smisla imati getIDByFraudData kada to možemo samo povući iz strukture preko fraud_data.id
    // također baš nema smisla imati getIDByID i getFraudDataByFraudData jer tada to više funkcionira kao search
    // ako postoji vraćamo isti podatak, ako ne postoji vraćamo empty
    fraud_data getFraudDataByID(int ID)
    {
        if (searchByID(ID) == true)
        {
            auto search = keyIsID.find(ID);
            return search->second;
        }
        else
        {
            return generateEmptyReturnData();
        }
    }
    std::vector<fraud_data> getFraudDataByID(std::vector<int> IDs)
    {
        std::vector<fraud_data> allData;
        while (!IDs.empty())
        {
            if (searchByID(*IDs.rbegin()) == true)
            {
                auto search = keyIsID.find(*IDs.rbegin());
                allData.push_back(search->second);
            }
            else
            {
                allData.push_back(generateEmptyReturnData());
            }
            IDs.pop_back();
        }
        return allData;
    }

    bool deleteByID(int ID)
    {
        auto searchID = keyIsID.find(ID);
        if (searchID == keyIsID.end())
        {
            return false;
        }
        auto searchCC_num = keyIsCC_num.find(searchID->second.cc_num);
        auto searchCity_pop = keyIsCity_pop.find(searchID->second.city_pop);
        while (true)
        {
            if (searchCC_num->second == searchID->second)
            {
                break;
            }
            if (searchCC_num->second.cc_num != searchID->second.cc_num)
                return false;
            searchCC_num++;
        }
        while (true)
        {
            if (searchCity_pop->second == searchID->second)
            {
                break;
            }
            if (searchCity_pop->second.city_pop != searchID->second.city_pop)
                return false;
            searchCity_pop++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByID(std::vector<int> IDs)
    {
        bool allSuccess = true;
        while (!IDs.empty())
        {
            bool searchSuccess = deleteByID(*IDs.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            IDs.pop_back();
        }
        return allSuccess;
    }
    bool deleteByID(fraud_data data)
    {
        int ID = data.ID;
        auto searchID = keyIsID.find(ID);
        if (searchID == keyIsID.end() || searchID->second != data)
        {
            return false;
        }
        auto searchCC_num = keyIsCC_num.find(searchID->second.cc_num);
        auto searchCity_pop = keyIsCity_pop.find(searchID->second.city_pop);
        while (true)
        {
            if (searchCC_num->second == searchID->second)
            {
                break;
            }
            if (searchCC_num->second.cc_num != searchID->second.cc_num)
                return false;
            searchCC_num++;
        }
        while (true)
        {
            if (searchCity_pop->second == searchID->second)
            {
                break;
            }
            if (searchCity_pop->second.city_pop != searchID->second.city_pop)
                return false;
            searchCity_pop++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByID(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool searchSuccess = deleteByID(*data.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            data.pop_back();
        }
        return allSuccess;
    }

    /*

        cc_num

    */

    double returnMaxCC_numValue()
    {
        return keyIsCC_num.rbegin()->first;
    }
    std::vector<double> returnMaxCC_numValue(int N)
    {
        std::vector<double> MaxCC_nums;
        auto key = keyIsCC_num.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCC_nums.push_back(key->first);
            key++;
        }
        return MaxCC_nums;
    }
    fraud_data returnMaxCC_numData()
    {
        return keyIsCC_num.rbegin()->second;
    }
    std::vector<fraud_data> returnMaxCC_numData(int N)
    {
        std::vector<fraud_data> MaxCC_nums;
        auto key = keyIsCC_num.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCC_nums.push_back(key->second);
            key++;
        }
        return MaxCC_nums;
    }
    std::pair<double, fraud_data> returnMaxCC_numandData()
    {
        return *keyIsCC_num.rbegin();
    }
    std::vector<std::pair<double, fraud_data>> returnMaxCC_numandData(int N)
    {
        std::vector<std::pair<double, fraud_data>> MaxCC_nums;
        auto key = keyIsCC_num.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCC_nums.push_back(*key);
            key++;
        }
        return MaxCC_nums;
    }

    double returnMinCC_numValue()
    {
        return keyIsCC_num.begin()->first;
    }
    std::vector<double> returnMinCC_numValue(int N)
    {
        std::vector<double> MinCC_nums;
        auto key = keyIsCC_num.begin();
        for (int i = 0; i < N; i++)
        {
            MinCC_nums.push_back(key->first);
            key++;
        }
        return MinCC_nums;
    }
    fraud_data returnMinCC_numData()
    {
        return keyIsCC_num.begin()->second;
    }
    std::vector<fraud_data> returnMinCC_numData(int N)
    {
        std::vector<fraud_data> MinCC_nums;
        auto key = keyIsCC_num.begin();
        for (int i = 0; i < N; i++)
        {
            MinCC_nums.push_back(key->second);
            key++;
        }
        return MinCC_nums;
    }
    std::pair<double, fraud_data> returnMinCC_numandData()
    {
        return *keyIsCC_num.begin();
    }
    std::vector<std::pair<double, fraud_data>> returnMinCC_numandData(int N)
    {
        std::vector<std::pair<double, fraud_data>> MinCC_nums;
        auto key = keyIsCC_num.begin();
        for (int i = 0; i < N; i++)
        {
            MinCC_nums.push_back(*key);
            key++;
        }
        return MinCC_nums;
    }

    bool addByCC_num(double cc_num, fraud_data data)
    {
        data.cc_num = cc_num;
        if (searchByID(data.ID) == true)
            return false;

        keyIsID.insert({data.ID, data});
        keyIsCC_num.insert({data.cc_num, data});
        keyIsCity_pop.insert({data.city_pop, data});
        return true;
    }
    bool addByCC_num(double cc_num)
    {
        return addByCC_num(cc_num, generateEmptyData());
    }
    bool addByCC_num(fraud_data data)
    {
        return addByCC_num(data.ID, data);
    }
    bool addByCC_num(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool success = addByCC_num(*data.rbegin());
            data.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByCC_num(std::vector<double> CCNums)
    {
        bool allSuccess = true;
        while (!CCNums.empty())
        {
            bool success = addByCC_num(*CCNums.rbegin());
            CCNums.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByCC_num(std::vector<std::pair<double, fraud_data>> CCNumAndData)
    {
        bool allSuccess = true;
        while (!CCNumAndData.empty())
        {
            auto iteratorCCNumAndData = CCNumAndData.rbegin();
            bool success = addByCC_num(iteratorCCNumAndData->first, iteratorCCNumAndData->second);
            CCNumAndData.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }

    // opet, nema smisla imati search po cc_num i vrijednosti
    bool searchByCC_num(double cc_num)
    {
        auto search = keyIsCC_num.find(cc_num);
        if (search != keyIsCC_num.end())
            return true;
        else
            return false;
    }
    bool searchByCC_num(fraud_data data)
    {

        auto search = keyIsCC_num.find(data.cc_num);
        if (search != keyIsCC_num.end())
        {
                return true;
        }
        else
            return false;
    }
    bool searchByCC_num(std::vector<fraud_data> data)
    {
        while (!data.empty())
        {
            bool searchSuccess = searchByCC_num(*data.rbegin());
            if (searchSuccess == false)
                return false;
            data.pop_back();
        }
        return true;
    }
    bool searchByCC_num(std::vector<double> cc_nums)
    {
        while (!cc_nums.empty())
        {
            bool searchSuccess = searchByCC_num(*cc_nums.rbegin());
            if (searchSuccess == false)
                return false;
            cc_nums.pop_back();
        }
        return true;
    }

    // Nema smisla imati getCC_numByFraudData kada to možemo samo povući iz strukture preko fraud_data.cc_num
    // također baš nema smisla imati getCC_numByCC_num i getFraudDataByFraudData jer tada to više funkcionira kao search
    // ako postoji vraćamo isti podatak, ako ne postoji vraćamo empty
    fraud_data getFraudDataByCC_num(double cc_num)
    {
        if (searchByCC_num(cc_num) == true)
        {
            auto search = keyIsCC_num.find(cc_num);
            return search->second;
        }
        else
        {
            return generateEmptyReturnData();
        }
    }
    std::vector<fraud_data> getFraudDataByCC_num(std::vector<double> cc_nums)
    {
        std::vector<fraud_data> allData;
        while (!cc_nums.empty())
        {
            if (searchByCC_num(*cc_nums.rbegin()) == true)
            {
                auto search = keyIsCC_num.find(*cc_nums.rbegin());
                allData.push_back(search->second);
            }
            else
            {
                allData.push_back(generateEmptyReturnData());
            }
            cc_nums.pop_back();
        }
        return allData;
    }

    bool deleteByCC_num(double cc_num)
    {
        auto searchCC_num = keyIsCC_num.find(cc_num);
        if (searchCC_num == keyIsCC_num.end())
        {
            return false;
        }

        auto searchID = keyIsID.find(searchCC_num->second.ID);
        if (searchID == keyIsID.end())
        {
            return false;
        }
        auto searchCity_pop = keyIsCity_pop.find(searchID->second.city_pop);
        while (true)
        {
            if (searchCity_pop->second == searchCC_num->second)
            {
                break;
            }
            if (searchCity_pop->second.city_pop != searchCC_num->second.city_pop)
                return false;
            searchCity_pop++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByCC_num(std::vector<int> CC_nums)
    {
        bool allSuccess = true;
        while (!CC_nums.empty())
        {
            bool searchSuccess = deleteByCC_num(*CC_nums.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            CC_nums.pop_back();
        }
        return allSuccess;
    }
    bool deleteByCC_num(fraud_data data)
    {
        double cc_num = data.cc_num;
        auto searchCC_num = keyIsCC_num.find(cc_num);
        while (true)
        {
            if (data == searchCC_num->second)
            {
                break;
            }
            if (searchCC_num->second.cc_num != data.city_pop)
                return false;
            searchCC_num++;
        }
        if (searchCC_num == keyIsCC_num.end() || searchCC_num->second != data)
        {
            return false;
        }
        auto searchID = keyIsID.find(searchCC_num->second.ID);
        if (searchID == keyIsID.end())
        {
            return false;
        }
        auto searchCity_pop = keyIsCity_pop.find(searchID->second.city_pop);
        while (true)
        {
            if (searchCity_pop->second == searchCC_num->second)
            {
                break;
            }
            if (searchCity_pop->second.city_pop != searchCC_num->second.city_pop)
                return false;
            searchCity_pop++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByCC_num(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool searchSuccess = deleteByCC_num(*data.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            data.pop_back();
        }
        return allSuccess;
    }

    /*

        city_pop

    */

    double returnMaxCity_popValue()
    {
        return keyIsCity_pop.rbegin()->first;
    }
    std::vector<double> returnMaxCity_popValue(int N)
    {
        std::vector<double> MaxCity_pop;
        auto key = keyIsCity_pop.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCity_pop.push_back(key->first);
            key++;
        }
        return MaxCity_pop;
    }
    fraud_data returnMaxCity_popData()
    {
        return keyIsCity_pop.rbegin()->second;
    }
    std::vector<fraud_data> returnMaxCity_popData(int N)
    {
        std::vector<fraud_data> MaxCity_pop;
        auto key = keyIsCity_pop.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCity_pop.push_back(key->second);
            key++;
        }
        return MaxCity_pop;
    }
    std::pair<double, fraud_data> returnMaxCity_popandData()
    {
        return *keyIsCity_pop.rbegin();
    }
    std::vector<std::pair<double, fraud_data>> returnMaxCity_popandData(int N)
    {
        std::vector<std::pair<double, fraud_data>> MaxCity_pop;
        auto key = keyIsCity_pop.rbegin();
        for (int i = 0; i < N; i++)
        {
            MaxCity_pop.push_back(*key);
            key++;
        }
        return MaxCity_pop;
    }

    double returnMinCity_popValue()
    {
        return keyIsCity_pop.begin()->first;
    }
    std::vector<double> returnMinCity_popValue(int N)
    {
        std::vector<double> MinCity_pop;
        auto key = keyIsCity_pop.begin();
        for (int i = 0; i < N; i++)
        {
            MinCity_pop.push_back(key->first);
            key++;
        }
        return MinCity_pop;
    }
    fraud_data returnMinCity_popData()
    {
        return keyIsCity_pop.begin()->second;
    }
    std::vector<fraud_data> returnMinCity_popData(int N)
    {
        std::vector<fraud_data> MinCity_pop;
        auto key = keyIsCity_pop.begin();
        for (int i = 0; i < N; i++)
        {
            MinCity_pop.push_back(key->second);
            key++;
        }
        return MinCity_pop;
    }
    std::pair<double, fraud_data> returnMinCity_popandData()
    {
        return *keyIsCity_pop.begin();
    }
    std::vector<std::pair<double, fraud_data>> returnMinCity_popandData(int N)
    {
        std::vector<std::pair<double, fraud_data>> MinCity_pop;
        auto key = keyIsCity_pop.begin();
        for (int i = 0; i < N; i++)
        {
            MinCity_pop.push_back(*key);
            key++;
        }
        return MinCity_pop;
    }

    bool addByCity_pop(double city_pop, fraud_data data)
    {
        data.city_pop = city_pop;
        if (searchByID(data.ID) == true)
            return false;

        keyIsID.insert({data.ID, data});
        keyIsCC_num.insert({data.cc_num, data});
        keyIsCity_pop.insert({data.city_pop, data});
        return true;
    }
    bool addByCity_pop(double city_pop)
    {
        return addByCity_pop(city_pop, generateEmptyData());
    }
    bool addByCity_pop(fraud_data data)
    {
        return addByCity_pop(data.ID, data);
    }
    bool addByCity_pop(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool success = addByCity_pop(*data.rbegin());
            data.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByCity_pop(std::vector<double> city_pop)
    {
        bool allSuccess = true;
        while (!city_pop.empty())
        {
            bool success = addByCity_pop(*city_pop.rbegin());
            city_pop.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }
    bool addByCity_pop(std::vector<std::pair<double, fraud_data>> City_popAndData)
    {
        bool allSuccess = true;
        while (!City_popAndData.empty())
        {
            auto iteratorCity_popAndData = City_popAndData.rbegin();
            bool success = addByCity_pop(iteratorCity_popAndData->first, iteratorCity_popAndData->second);
            City_popAndData.pop_back();
            if (success == false)
                allSuccess = false;
        }
        return allSuccess;
    }

    // opet, nema smisla imati search po city_pop i vrijednosti
    bool searchByCity_pop(double city_pop)
    {
        auto search = keyIsCity_pop.find(city_pop);
        if (search != keyIsCity_pop.end())
            return true;
        else
            return false;
    }
    bool searchByCity_pop(fraud_data data)
    {

        auto search = keyIsCity_pop.find(data.city_pop);
        if (search != keyIsCity_pop.end())
        {
            if (data == search->second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool searchByCity_pop(std::vector<fraud_data> data)
    {
        while (!data.empty())
        {
            bool searchSuccess = searchByCity_pop(*data.rbegin());
            if (searchSuccess == false)
                return false;
            data.pop_back();
        }
        return true;
    }
    bool searchByCity_pop(std::vector<double> city_pop)
    {
        while (!city_pop.empty())
        {
            bool searchSuccess = searchByCity_pop(*city_pop.rbegin());
            if (searchSuccess == false)
                return false;
            city_pop.pop_back();
        }
        return true;
    }

    // Nema smisla imati getCity_popByFraudData kada to možemo samo povući iz strukture preko fraud_data.city_pop
    // također baš nema smisla imati getCity_popByCity_pop jer tada to više funkcionira kao već implementirani search
    // ako postoji vraćamo isti podatak (true), ako ne postoji vraćamo empty (false)
    fraud_data getFraudDataByCity_pop(double city_pop)
    {
        if (searchByCity_pop(city_pop) == true)
        {
            auto search = keyIsCity_pop.find(city_pop);
            return search->second;
        }
        else
        {
            return generateEmptyReturnData();
        }
    }
    std::vector<fraud_data> getFraudDataByCity_pop(std::vector<double> city_pop)
    {
        std::vector<fraud_data> allData;
        while (!city_pop.empty())
        {
            if (searchByCC_num(*city_pop.rbegin()) == true)
            {
                auto search = keyIsCity_pop.find(*city_pop.rbegin());
                allData.push_back(search->second);
            }
            else
            {
                allData.push_back(generateEmptyReturnData());
            }
            city_pop.pop_back();
        }
        return allData;
    }

    bool deleteByCity_pop(double city_pop)
    {

        auto searchCity_pop = keyIsCity_pop.find(city_pop);
        if (searchCity_pop == keyIsCity_pop.end())
        {
            return false;
        }

        auto searchID = keyIsID.find(searchCity_pop->second.ID);
        if (searchID == keyIsID.end())
        {
            return false;
        }

        auto searchCC_num = keyIsCC_num.find(searchCity_pop->second.cc_num);
        while (true)
        {
            if (searchCity_pop->second == searchCC_num->second)
            {
                break;
            }
            if (searchCity_pop->second.cc_num != searchCC_num->second.cc_num)
                return false;
            searchCC_num++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByCity_pop(std::vector<int> City_pops)
    {
        bool allSuccess = true;
        while (!City_pops.empty())
        {
            bool searchSuccess = deleteByCity_pop(*City_pops.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            City_pops.pop_back();
        }
        return allSuccess;
    }
    bool deleteByCity_pop(fraud_data data)
    {
        double city_pop = data.city_pop;
        auto searchCity_pop = keyIsCity_pop.find(city_pop);

        while (true)
        {
            if (data == searchCity_pop->second)
            {
                break;
            }
            if (searchCity_pop->second.city_pop != data.city_pop)
                return false;
            searchCity_pop++;
        }

        if (searchCity_pop == keyIsCity_pop.end() || searchCity_pop->second != data)
        {
            return false;
        }

        auto searchID = keyIsID.find(searchCity_pop->second.ID);
        if (searchID == keyIsID.end())
        {
            return false;
        }

        auto searchCC_num = keyIsCC_num.find(searchCity_pop->second.cc_num);
        while (true)
        {
            if (searchCity_pop->second == searchCC_num->second)
            {
                break;
            }
            if (searchCity_pop->second.cc_num != searchCC_num->second.cc_num)
                return false;
            searchCC_num++;
        }
        keyIsID.erase(searchID);
        keyIsCC_num.erase(searchCC_num);
        keyIsCity_pop.erase(searchCity_pop);
        return true;
    }
    bool deleteByCity_pop(std::vector<fraud_data> data)
    {
        bool allSuccess = true;
        while (!data.empty())
        {
            bool searchSuccess = deleteByCity_pop(*data.rbegin());
            if (searchSuccess == false)
                allSuccess = false;
            data.pop_back();
        }
        return allSuccess;
    }

    fraud_database(std::string filename)
    {
        std::fstream file("fraudTest.csv", std::ios::in);
        if (file.is_open())
        {
            std::string currentLine;

            // while there are still lines to be found
            bool newLine = true;
            while (getline(file, currentLine))
            {
                if (newLine) //služi za ignoriranje headera csv datoteke
                {
                    newLine = false;
                }
                else
                {
                    fraud_data newFraud;
                    newFraud.ID = stoi(currentLine.substr(0, currentLine.find(',', 0)));
                    int begin = currentLine.find(',', 0);
                    newFraud.trans_date_trans_time = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    /*
                        begin+1, da dobijem mjesto nakon zareza nakon ida
                        find da nađem zarez koji se nalazi nakon tog mjesta(begin+1)
                        jer find vraća vrijednost mjesta, a ne postoji/nemogu se sjetiti funkcije koja mi dopušta da
                        radim substring od mjesta a do mjesta b (substring ide od mjesta a, n broj mjesta)
                        moram taj od tog finda oduzeti begin+1

                        rinse and repeat za svaki podatak jer ne vidim način kako da ovo pretvorim u petlju

                        jednog dana ću se smijati, sada samo plačem
                    */
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.cc_num = stod(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));

                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    if (currentLine[begin + 1] == '"')
                    {
                        int postNavodnici = currentLine.find('"', begin + 2);
                        newFraud.merchant = currentLine.substr(begin + 1, currentLine.find(',', postNavodnici + 1) - begin - 1);
                        begin = begin + 1 + currentLine.find(',', postNavodnici + 1) - begin - 1;
                    }
                    else
                    {
                        newFraud.merchant = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                        begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    }
                    /*
                        Postoje zarezi u imenima...
                        nasreću možemo preduhitriti zarez jer je on između navodnika
                        ono što sljedi je rezulatat 15-20 minuta patnje
                        sigurno ima boljeg rješenja ali ne želim početi razmišljati o njemu

                        radimo na principu
                        ako je idući char (begin+1) navodnik
                            - tražimo idući navodnik koji se nalazi nakon trenutacanChar+1og mjesta
                            - i onda tražimo zarez koji se nalazi nakon tog navodnika
                        da, mogao bih odmah samo +1 na mjesto navodnika
                        ali iskreno ovako sam siguran da nema još nekakvih lijepih stvari nakon njega
                        znajući ovaj ukleti dataset nakon navodnika možda se još nešto nalazi

                        da, vjerojatno sam mogao ovo pretvoriti u neku funkciju
                        ali se sada bojim dotaknuti ovaj mess jer znam da ću nekako nešto negdje breakati
                        plus koristi se samo još jedanput
                        u tom slučaju mogao sam ovaj cijeli find masterpiece pretvoriti u funkciju
                        ...i pisanjem ovog komentara dao sam samom sebi ideju kako bih to mogao napraviti
                        ako je ovaj komentar još uvijek tu znači da nisam imao vremena pretvoriti find u funkciju
                    */

                    newFraud.category = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);

                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.amt = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.first = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.last = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.gender = stoc(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.street = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.city = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.state = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.zip = stoi(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.loc_lat = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.loc_long = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.city_pop = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));

                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    if (currentLine[begin + 1] == '"')
                    {
                        int postNavodnici = currentLine.find('"', begin + 2);
                        newFraud.job = currentLine.substr(begin + 1, currentLine.find(',', postNavodnici + 1) - begin - 1);
                        begin = begin + 1 + currentLine.find(',', postNavodnici + 1) - begin - 1;
                    }
                    else
                    {
                        newFraud.job = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                        begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    }

                    newFraud.dob = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.trans_num = currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1);
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.unix_time = stod(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.merch_lat = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.merch_long = stof(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));
                    begin = begin + 1 + currentLine.find(',', begin + 1) - begin - 1;
                    newFraud.is_fraud = stoi(currentLine.substr(begin + 1, currentLine.find(',', begin + 1) - begin - 1));

                    keyIsID.insert({newFraud.ID, newFraud});
                    keyIsCC_num.insert({newFraud.cc_num, newFraud});
                    keyIsCity_pop.insert({newFraud.city_pop, newFraud});
                }
            }
        }

        file.close();
    }
};

int main(void)
{
    startTime();
    fraud_database fd("fraudTest.csv");
    stopAndPrintFunctionTime("incijalni unos podatka");
    startTime();
    std::cout << fd.returnMaxIDValue() << std::endl;
    stopAndPrintFunctionTime("returnMaxIDValue");
    startTime();
    fd.addByID({555719, 555720, 555721});
    stopAndPrintFunctionTime("addByID");
    startTime();
    std::cout << fd.returnMaxIDValue() << std::endl;
    stopAndPrintFunctionTime("returnMaxIDValue");
    startTime();
    fd.deleteByID(555721);
    stopAndPrintFunctionTime("deleteByID");
    startTime();
    std::cout << fd.returnMaxIDValue() << std::endl;
    stopAndPrintFunctionTime("returnMaxIDValue");
    startTime();
    std::cout << fd.returnMinIDValue() << std::endl;
    stopAndPrintFunctionTime("returnMinIDValue");
    startTime();
    std::cout << fd.searchByID(123) << std::endl;
    stopAndPrintFunctionTime("searchByID");
    
    startTime();
    std::cout << fd.returnMaxCC_numValue() << std::endl;
    stopAndPrintFunctionTime("returnMaxCC_numValue");

    std::vector<fraud_data> rezultat;
    startTime();
    rezultat = fd.returnMaxCC_numData(1000);
    std::cout << "kod dohvaćanja 1000 podataka" << std::endl;
    stopAndPrintFunctionTime("returnMaxCC_numandData");

    
    startTime();
    std::cout << fd.searchByCC_num(rezultat) << std::endl;
    std::cout << "kod traženja 1000 podataka" << std::endl;
    stopAndPrintFunctionTime("searchByCC_num");

    startTime();
    fd.deleteByCC_num(rezultat);
    std::cout << "kod brisanja 1000 podataka" << std::endl;
    stopAndPrintFunctionTime("deleteByCC_num");
    
    startTime();
    std::cout << fd.returnMaxCC_numValue() << std::endl;
    stopAndPrintFunctionTime("returnMaxCC_numValue");





    // odlučio sam provjeriti postoji li duplicate cc_num
    /*
    std::vector<double> exist;
    for (int i = 0; i <= fd.returnMaxIDValue(); i++)
    {
        fraud_data f = fd.getFraudDataByID(i);
        if (std::find(exist.begin(), exist.end(), f.cc_num) != exist.end())
        {
            std::cout << std::setprecision(15) << "ccnum dupe found" << f.cc_num << std::endl;
            break;
        }
        else
        {
            exist.push_back(f.cc_num);
        }
    }
    exist.clear();*/


    return 0;
}

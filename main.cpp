//define things in columns

        //columns:
        /*
        0 - ID (basic int)
        1 - trans_date_trans_time (date, time, YYYY-MM-DD HH:MM:SS)
        2 - cc_num (int... but some are stored as "4.99234639806515E+018")
        3 - merchant (string, all seem to have the fraud_ prefix)
        4 - category  (string)
        5 - amt (float)
        6 - first (string)
        7 - last  (string)
        8 - gender (saved as M/F)
        9 - street (string, contains house/apartment number)
        10 - city (string)
        11 - state (string, 2 letters)
        12 - zip (int)
        13 - lat (float)
        14 - long (float)
        15 - city_pop (int)
        16 - job (string)
        17 - dob (date, YYYY-MM-DD)
        18 - trans_num (hash?)
        19 - unix_time (int or double, something wholenumber)
        20 - merch_lat (float)
        21 - merch_long (float)
        22 - is_fraud (bool)
        */
       // 555720 rows
       // first row describes everything, skip it
       // columns are divided by ','
       // nothing at EOL


#include <iostream>

//vector
#include <vector>

//file loading
#include <fstream>

//setprecision
#include <iomanip>


struct fraud_data{
    int ID;
    std::string trans_date_trans_time; // (date, time, YYYY-MM-DD HH:MM:SS), should be something proper
    double cc_num; // std::setprecision(15)
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
    float loc_long; //loc_long because putting just long makes me cry inside
    int city_pop;
    std::string job;
    std::string dob; // (date, YYYY-MM-DD), should be something proper
    std::string trans_num;
    double unix_time;
    float merch_lat;
    float merch_long;
    bool is_fraud;
};

int main(int argc, char const *argv[])
{
    //file loading
    std::fstream file("fraud_test.csv", std::ios::in);
    if(file.is_open())
    {

        std::string currentLine;

        //while there are still lines to be found
        while(getline(file,currentLine))
        {
            
        }

    std::cout << "hello world" << std::endl;
    return 0;
}

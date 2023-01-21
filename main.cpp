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

char stoc(std::string s)
{
    return s[0];
}


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

void fraud_data_info(fraud_data info)
{
    std::cout << "ID: " << info.ID << std::endl;
    std::cout << "trans_date_trans_time: " << info.trans_date_trans_time << std::endl;
    std::cout << std::setprecision(15) << "cc_num" << info.cc_num << std::endl;
    std::cout << "merchant: "<<info.merchant << std::endl;
    std::cout << "category: "<<info.category << std::endl;
    std::cout << "amt: "<<info.amt << std::endl;
    std::cout << "first: "<<info.first << std::endl;
    std::cout << "last: "<<info.last << std::endl;
    std::cout << "gender: "<<info.gender << std::endl;
    std::cout << "street: "<<info.street << std::endl;
    std::cout << "city: "<<info.city << std::endl;
    std::cout << "state: "<<info.state << std::endl;
    std::cout << "zip: "<<info.zip << std::endl;
    std::cout << "loc_lat: "<<info.loc_lat << std::endl;
    std::cout << "loc_long: "<<info.loc_long << std::endl;
    std::cout << "city_pop: "<<info.city_pop << std::endl;
    std::cout << "job: " <<info.job << std::endl;
    std::cout << "dob: "<<info.dob << std::endl;
    std::cout << "trans_num: "<<info.trans_num << std::endl;
    std::cout << "unix_time: "<<info.unix_time << std::endl;
    std::cout << "merch_lat: "<<info.merch_lat << std::endl;
    std::cout << "merch_long: "<<info.merch_long << std::endl;
    std::cout << "is_fraud: " <<info.is_fraud << std::endl;
}


int main(int argc, char const *argv[])
{
    //file loading
    std::fstream file("fraudTest.csv", std::ios::in);
    
    std::vector<fraud_data> v1;
    fraud_data a;

    if(file.is_open())
    {

        std::string currentLine;
        
        //while there are still lines to be found
        bool newLine = true;
        while(getline(file,currentLine))
        {
            if(newLine)
            {
                newLine = false;
            }else{
            fraud_data newFraud;
            newFraud.ID = stoi(currentLine.substr(0, currentLine.find(',', 0)));
            int begin = currentLine.find(',',0);
            newFraud.trans_date_trans_time = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            /*
                begin+1, da dobijem mjesto nakon zareza nakon ida
                find da nađem zarez koji se nalazi nakon tog mjesta(begin+1)
                jer find vraća vrijednost mjesta, a ne postoji/nemogu se sjetiti funkcije koja mi dopušta da
                radim substring od mjesta a do mjesta b (substring ide od mjesta a, n broj mjesta)
                moram taj od tog finda oduzeti begin+1

                rinse and repeat za svaki podatak jer ne vidim način kako da ovo pretvorim u petlju

                jednog dana ću se smijati, sada samo plačem
            */
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.cc_num = stod(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.merchant  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
    	    //TODO: add logic for "fraud_ime neko,netki",


            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.category  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            
            /*
            std::cout << newFraud.category << std::endl;
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.amt = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.first  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.last  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.gender = stoc(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.street  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.city  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.state  = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.zip  = stoi(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.loc_lat = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.loc_long = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.city_pop = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.job = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.dob = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.trans_num = currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1);
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.unix_time = stod(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.merch_lat = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.merch_long = stof(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));
            begin = begin+1+currentLine.find(',',begin+1)-begin-1;
            newFraud.is_fraud = stoi(currentLine.substr(begin+1, currentLine.find(',',begin+1)-begin-1));*/
            a = newFraud;
            }
            
            
        }

    }
    std::cout << a.ID << std::endl;
    std::cout << a.trans_date_trans_time << std::endl;

    return 0;
}

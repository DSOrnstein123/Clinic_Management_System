#include "../include/Utils.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

string chuanHoaChu(const string &str)
{
    string res;
    bool vietHoa = true;
    for (char c : str)
    {
        if (isspace(c))
        {
            if (!res.empty() && res.back() != ' ')
                res += ' ';
            vietHoa = true;
        }
        else
        {
            res += vietHoa ? toupper(c) : tolower(c);
            vietHoa = false;
        }
    }
    while (!res.empty() && res.back() == ' ')
        res.pop_back();
    return res;
}

string vietHoa(const string &str)
{
    string res = str;
    transform(res.begin(), res.end(), res.begin(), ::toupper);
    return res;
}

string layThoiGianHienTai()
{
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

void tamDung()
{
    system("pause");
}

void xoaManHinh()
{
    system("cls");
}

int nhapSoNguyen(const string &prompt)
{
    int so;
    while (true)
    {
        cout << prompt;
        if (cin >> so)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return so;
        }
        else
        {
            cout << ">> Loi: vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>


using namespace std;
std::string pP[4][4] = { {"{O-, O+, A-, A+}","{O-, O+, AB-, AB+, B-, B+, A-, A+}","{AB-, AB+, B-, B+, A-, A+}","{O-, O+, A-, A+}"},
                        {"{O-, O+, AB-, AB+, B-, B+, A-, A+}", "{O-, O+, B-, B+}", "{AB-, AB+, B-, B+, A-, A+}", "{O-, O+, B-, B+}"},
                        {"{AB-, AB+, B-, B+, A-, A+}", "{AB-, AB+, B-, B+, A-, A+}", "{AB-, AB+, B-, B+, A-, A+}","{B-, B+, A-, A+}"},
                        {"{O-, O+, A-, A+}", "{O-, O+, B-, B+}", "{B-, B+, A-, A+}", "{O-, O+}"} };

std::string pM[4][4] = { {"{O-, A-}","{O-, AB-, B-, A-}", "{AB-, B-, A-}" ,"{O-, A-}"},
                        {"{O-, AB-, B-, A-}", "{O-, B-}","{AB-, B-, A-}", "{O-, B-}"},
                        {"{AB-, B-, A-}","{AB-, B-, A-}","{AB-, B-, A-}", "{B-, A-}"},
                        {"{O-, A-}","{O-, B-}","{B-, A-}","O-"} };

std::string cP[4][4] = { {"{O-, O+, AB-, AB+, B-, B+, A-, A+}","{AB-, AB+, B-, B+}","{AB-, AB+, B-, B+}","{O-, O+, B-, B+, A-, A+}"},
                        {"{AB-, AB+, A-, A+}", "{O-, O+, AB-, AB+, B-, B+, A-, A+}", "{AB-, AB+, A-, A+}", "{O-, O+, B-, B+, A-, A+}"},
                        {"{O-, O+, AB-, AB+, B-, B+, A-, A+}", "{O-, O+, AB-, AB+, B-, B+, A-, A+}","{AB-, AB+, B-, B+, A-, A+}","IMPOSSIBLE"},
                        {"{AB-, AB+, A-, A+}", "{AB-, AB+, B-, B+}","IMPOSSIBLE", "{O-, O+, B-, B+, A-, A+}"} };

std::string cM[4][4] = { {"{O+, AB+, B+, A+}","{AB+, B+}","{AB+, B+}","{O+, B+, A+}"},
                        {"{AB+, A+}","{O+, AB+, B+, A+}","{AB+, A+}","{O+, B+, A+}"},
                        {"{O+, AB+, B+, A+}", "{O+, AB+, B+, A+}", "{AB+, B+, A+}","IMPOSSIBLE"},
                        {"{AB+, A+}","{AB+, B+}","IMPOSSIBLE","{O+, B+, A+}"} };

void dziecko(string x, string y, int c) {
    int plus_i_minus = 0;
    std::map<string, int> blood;
    std::map<string, int>::iterator b;
    blood["A"] = 0;
    blood["B"] = 1;
    blood["AB"] = 2;
    blood["O"] = 3;
    if (x.substr(x.size() - 1) == "-" && y.substr(y.size() - 1) == "-") plus_i_minus = 1;
    b = blood.find(x.substr(0, x.size() - 1));
    int a = b->second;
    b = blood.find(y.substr(0, y.size() - 1));
    if (plus_i_minus == 0)cout << "Case " << c << ": " << x << " " << y << " " << pP[a][b->second] << endl;
    else cout << "Case " << c << ": " << x << " " << y << " " << pM[a][b->second] << endl;
}

void ojciec(string x, string y, int c) {
    int plus_i_minus = 0;
    std::map<string, int> blood;
    std::map<string, int>::iterator b;
    blood["A"] = 0;
    blood["B"] = 1;
    blood["AB"] = 2;
    blood["O"] = 3;
    if (x.substr(x.size() - 1) == "-" && y.substr(y.size() - 1) == "+") plus_i_minus = 1;
    b = blood.find(x.substr(0, x.size() - 1));
    int a = b->second;
    b = blood.find(y.substr(0, y.size() - 1));
    if (plus_i_minus == 0)cout << "Case " << c << ": " << cP[a][b->second] << " " << x << " " << y << endl;
    else cout << "Case " << c << ": " << cM[a][b->second] << " " << x << " " << y << endl;
}

void matka(string x, string y, int c) {
    int plus_i_minus = 0;
    std::map<string, int> blood;
    std::map<string, int>::iterator b;
    blood["A"] = 0;
    blood["B"] = 1;
    blood["AB"] = 2;
    blood["O"] = 3;
    if (x.substr(x.size() - 1) == "-" && y.substr(y.size() - 1) == "+") plus_i_minus = 1;
    b = blood.find(x.substr(0, x.size() - 1));
    int a = b->second;
    b = blood.find(y.substr(0, y.size() - 1));
    if (plus_i_minus == 0)cout << "Case " << c << ": " << x << " " << cP[a][b->second] << " " << y << endl;
    else cout << "Case " << c << ": " << x << " " << cM[a][b->second] << " " << y << endl;
}

int main() {
    string A, B, C;
    int c = 1;
    while (cin >> A >> B >> C) {
        if (A + B + C == "END") break;
        if (C == "?") dziecko(A, B, c);
        else if (A == "?") ojciec(B, C, c);
        else matka(A, C, c);
        c++;
    }
    return 0;


}

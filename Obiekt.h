//
// Created by Czesław Horyń i Adam Solarz on 18/05/2019.
//
#include <chrono>
#include <iostream>
#include <string>
#include <stack>
#ifndef UNTITLED16_OBIEKT_H
#define UNTITLED16_OBIEKT_H
using namespace std;

class Obiekt {


    // Funkcja zwracająca pierwszeństwo operatorów
public: int pierszenstwo1(char c)
    {
        if(c == '^')
            return 3;
        else if(c == '*' || c == '/')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

// Główna funkcja do konwersji wyrażenia infix
// do zmiany wyrażenia

public: void infixToPostfix1(string s)
    {
        std::stack<char> tso;
        tso.push('O');
        int l = s.length();
        string sno;
        for(int i = 0; i < l; i++)
        {
            // Jeśli zeskanowany znak jest operandem, dodaj go do ciągu wyjściowego.
            if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
                sno+=s[i];

                // Jeśli zeskanowana postać to „(”, wepchnij ją na stos.
            else if(s[i] == '(')

                tso.push('(');

                // Jeśli zeskanowany znak to „), pop i wyślij ciąg ze stosu
                // aż pojawi się „(„ ”).
            else if(s[i] == ')')
            {
                while(tso.top() != 'O' && tso.top() != '(')
                {
                    char c = tso.top();
                    tso.pop();
                    sno += c;
                }
                if(tso.top() == '(')
                {
                    char c = tso.top();
                    tso.pop();
                }
            }

                //Jeśli operator jest skanowany
            else{
                while(tso.top() != 'O' && pierszenstwo1(s[i]) <= pierszenstwo1(tso.top()))
                {
                    char c = tso.top();
                    tso.pop();
                    sno += c;
                }
                tso.push(s[i]);
            }

        }
        // Wyrzuć wszystkie pozostałe elementy ze stosu
        while(tso.top() != 'O')
        {
            char c = tso.top();
            tso.pop();
            sno += c;
        }

        cout << "Postfix: " + sno << endl;

    }

};

#endif //UNTITLED16_OBIEKT_H

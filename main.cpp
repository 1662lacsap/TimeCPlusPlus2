//
// Created by Czesław Horyń i Adam Solarz on 18/05/2019.
//
/* Implementacja C ++ do konwersji wyrażenia infix na postfix */
// Zauważ, że tutaj używamy std :: stack dla operacji Stack
#include <chrono>
#include <iostream>
#include <string>
#include <stack>
#include "Obiekt.h"

// Funkcja zwracająca pierwszeństwo operatorów
int pierszenstwo(char c)
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

void infixToPostfix(string s)
{
    std::stack<char> tso1;
    tso1.push('O');
    int l = s.length();
    string sno;
    for(int i = 0; i < l; i++)
    {
        // Jeśli zeskanowany znak jest operandem, dodaj go do ciągu wyjściowego.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            sno+=s[i];

            // Jeśli zeskanowana postać to „(”, wepchnij ją na stos.
        else if(s[i] == '(')

            tso1.push('(');

        // Jeśli zeskanowany znak to „), pop i wyślij ciąg ze stosu
        // aż pojawi się „(„ ”).
        else if(s[i] == ')')
        {
            while(tso1.top() != 'O' && tso1.top() != '(')
            {
                char c = tso1.top();
                tso1.pop();
                sno += c;
            }
            if(tso1.top() == '(')
            {
                char c = tso1.top();
                tso1.pop();
            }
        }

            //Jeśli operator jest skanowany
        else{
            while(tso1.top() != 'O' && pierszenstwo(s[i]) <= pierszenstwo(tso1.top()))
            {
                char c = tso1.top();
                tso1.pop();
                sno += c;
            }
            tso1.push(s[i]);
        }

    }
    // Wyrzuć wszystkie pozostałe elementy ze stosu
    while(tso1.top() != 'O')
    {
        char c = tso1.top();
        tso1.pop();
        sno += c;
    }

    cout << "Postfix: " + sno << endl;

}

// Program do testowania powyższych funkcji i obiektu
int main()
{
    cout << "" << endl;
    cout<<"Infix: a+b*(c^d-e)^(f+g*h)-i"<<endl;
    //Obiektowo
    cout << "" << endl;
    cout << "Obiektowo:" << endl;
    auto start_time1 = chrono::high_resolution_clock::now();
    string exp1 = "a+b*(c^d-e)^(f+g*h)-i";
    Obiekt o1;
    o1.infixToPostfix1(exp1);
    auto end_time1 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end_time1 - start_time1).count() << " nanosekund";


    cout << "" << endl;
    cout << "" << endl;

    //Proceduralnie

    cout << "Proceduralnie:" << endl;
    auto start_time = chrono::high_resolution_clock::now();
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    auto end_time = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " nanosekund";
    cout << "" << endl;


    return 0;
}
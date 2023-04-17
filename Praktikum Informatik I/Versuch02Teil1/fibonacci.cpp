//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


int fibonacci(int n) // Iterative Version
{
    int previousn = 0 ;
    int currentn = 1 ;
    if (n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)
    {
        int newn = previousn + currentn;
    	previousn = currentn;      //nach jeder Berechnung wird das jeweilige Element zum vorherigen Element.
    	currentn = newn;          //und dann das neu berechnete wird zum Jeweiligen.
    }
    return currentn;
}

int main ()
{
    cout << " Fibonacci - Zahlen von 0 bis 12:" << endl;
    for (int i = 0; i <= 42 ; i ++) // mit 42 wäre es lansgsamer, da die Anzahl der Aufrufe in der Funktion exponentiell wächst.
    {
        cout << "f(" << i << ") = " << fibonacci(i) << endl ;
    }
    return 0;
}

/*Zu 2.2.2.3: Ja, weil die Anzahl der Aufrufe in der Funktion exponentiell wächst. Auf der anderen Seite,
die Funktion mit der iterativen Berechnung wird nur einmal aufgerufen!

Zu 2.2.2.4: Im Grunde liegt es daran, dass der Wertebereich des Datentypen "int" zu klein ist,
als Lösung benutzen wir den Datentypen "unsigned long long".
*/


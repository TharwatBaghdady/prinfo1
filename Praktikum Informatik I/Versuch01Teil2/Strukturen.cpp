/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

struct Person {
		string sNachname;
		string sVorname;
		int iGeburtsjahr;
		int iAlter;
	               };

int main()
{
	struct Person nBenutzer;

	cout << "Geben Sie bitte Ihren Vornamen ein: " << endl;
	cin >> nBenutzer.sVorname;
	cout << "Geben Sie bitte Ihren Nachnamen ein: " << endl;
    cin >> nBenutzer.sNachname;
	cout << "Geben Sie bitte Ihr Geburtsjahr ein: " << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Geben Sie bitte Ihren Alter ein: " << endl;
    cin >> nBenutzer.iAlter;

    struct Person nKopieGesamt= nBenutzer; // Gesamt kopieren
    struct Person nKopieEinzeln;
    // Einzeln kopieren
    nKopieEinzeln.sNachname		= nBenutzer.sNachname;
    nKopieEinzeln.sVorname		= nBenutzer.sVorname;
   	nKopieEinzeln.iGeburtsjahr	= nBenutzer.iGeburtsjahr;
   	nKopieEinzeln.iAlter		= nBenutzer.iAlter;

	cout << "Einzeln kopiert:" << endl;
	cout << "Nachname    = " << nKopieEinzeln.sNachname		<< endl;
	cout << "Vorname     = " << nKopieEinzeln.sVorname		<< endl;
	cout << "Geburtsjahr = " << nKopieEinzeln.iGeburtsjahr	<< endl;
	cout << "Alter       = " << nKopieEinzeln.iAlter		<< endl;

	cout << "Gesamt kopiert:" << endl;
	cout << "Nachname    = " << nKopieGesamt.sNachname	 << endl;
	cout << "Vorname     = " << nKopieGesamt.sVorname	 << endl;
	cout << "Geburtsjahr = " << nKopieGesamt.iGeburtsjahr << endl;
	cout << "Alter       = " << nKopieGesamt.iAlter		 << endl;



    return 0;
    
}

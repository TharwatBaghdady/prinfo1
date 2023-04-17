//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 1.1: Datentypen und Typumwandlung
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// (1)
	int iErste;
	int iZweite;

	cout << "Bitte geben Sie die erste Zahl ein: " << endl;
	cin >> iErste;
	cout << "Bitte geben Sie die zweite Zahl ein: " << endl;
	cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;
	cout << "Summe der beiden Zahlen (als integer): " << iSumme << endl;
	cout << "Erste Zahl durch zweite Zahl (als integer): " << iQuotient << endl;

	// (2)
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;
	cout << "Summe der beiden Zahlen (double): " << dSumme << endl;
	cout << "Erste Zahl durch zweite Zahl (double): " << dQuotient << endl;

	// (3)
	double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = (double) iErste / (double) iZweite; //Casting
	cout << "Summe der beiden Zahlen (Casting): " << dSummeCast << endl;
	cout << "Erste Zahl durch zweite Zahl (Casting): " << dQuotientCast << endl;

	// (4)
	string sVorname;
	string sNachname;

	cout << "Bitte geben Sie Ihren Vornamen ein: " << endl;
	cin >> sVorname;
	cout << "Bitte geben Sie Ihren Nachnamen ein: " << endl;
	cin >> sNachname;

	string sVornameNachname = sVorname + " " + sNachname;
	string sNachnameVorname = sNachname + ", " + sVorname;

	cout << "'Vorname Nachname'-form: " << sVornameNachname << endl;
	cout << "'Name,Vorname'-form: " << sNachnameVorname << endl;

	// (5)
	{
		// (a)
		int iFeld[2] =
		{ 1, 2 };

		// (b)
		int spielfeld[2][3] =
		{
		{ 1, 2, 3 },
		{ 4, 5, 6 } };
		cout << spielfeld[0][0] << " " << spielfeld[0][1] << " "
				<< spielfeld[0][2] << endl;
		cout << spielfeld[1][0] << " " << spielfeld[1][1] << " "
				<< spielfeld[1][2] << endl;

		// (c)
		const int iZweite = 1;
		cout << "iZweite (im Block) = " << iZweite << endl;
	}
	cout << "iZweite (draussen) = " << iZweite << endl;

	// (6)
	int iName1 = (int) sVorname[0];
	int iName2 = (int) sVorname[1]; // so sind die Buchstaben direkt in ASCII gespeichert

	cout << "Erste Buchstabe des Vornamen in ASCII ist '" << iName1 << "'"
			<< endl;
	cout << "Zweite Buchstabe des Vornamen in ASCII ist '" << iName2 << "'"
			<< endl;

	// (7)
	int iName1_pos = (int) toupper(sVorname[0]) % 65;
	int iName2_pos = (int) toupper(sVorname[1]) % 65; // oder mit % 35 ohne toupper
	// Eine andere Methode waere:
	// int iName1_pos= (int)toupper(sVorname[0]) - (int)('A') + 1;
	// int iName2_pos = (int)toupper(sVorname[1]) - (int)('A') + 1;

	cout << "Position der ersten Buchstaben im deutschen Alphabet ist: "
			<< iName1_pos << endl;
	cout << "Position der zweiten Buchstaben im deutschen Alphabet ist:"
			<< iName2_pos << endl;

	return 0;
}


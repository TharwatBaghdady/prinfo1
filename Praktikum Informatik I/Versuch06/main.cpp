/** @mainpage
 *
 * Praktikum Informatik 1 MMXVIII
 * Versuch 6: STL: Standard Template Library
 *
 *
 * @file main.cpp
 *
 * content: main routine
 */

// Versuch 06 wurde von Versuch 05 übernommen und dazu wurden die Fälle 1,2, 3 und 5 modifiziert, 4 und 6 gelöscht, 8 neu hinzugefügt.

#include <iostream>
#include <string>
#include "Student.h"
#include <vector> // vector ist ein Container der STL

using namespace std;

int main()
{
	vector<Student> Studentliste; // definiere einen Vektor mit allen Studenten namens Studentliste, der Datentypen der Klasse Student enthält.

	Student student = Student(); // definiere einen Objekt namens student von der Klasse Student

    char abfrage;
    cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) "; // Soll die Liste vom Computer gefuellt werden?
    cin >> abfrage; // Speichere die Antwort in der Char abfrage ab

    if (abfrage != 'j')  //Eine Standard definierte Liste, falls der Benutzer will, dass der Computer selbst eine Liste fuellt
    {
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		Studentliste.push_back (student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		Studentliste.push_back (student);
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	Studentliste.push_back (student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		Studentliste.push_back (student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
    	Studentliste.push_back (student);
    }

    do // Menue immer ausgeben
    {
         cout << "\nMenue:" <<  endl
                  << "-----------------------------" <<  endl
                  << "(1): Datenelement hinzufuegen" <<  endl
                  << "(2): Datenelement löschen" <<  endl
                  << "(3): Datenbank ausgeben" <<  endl

				  << "(5): Datenbank in umgekehrter Reihenfolge ausgeben" <<  endl
				  << "(8): Datenelement vorne loeschen" <<  endl
                  << "(7): Beenden" <<  endl;
         cin >> abfrage;

        switch (abfrage)
        {
            case '1': //Datenelement hinzufuegen
				{
					unsigned int matNr = 0;
					string name = "";
					string geburtstag = "";
					string Adresse = "";

					cout << "Bitte geben Sie die Daten fuer den neuenStudenten ein.\nName: ";
					cin.ignore(10, '\n');
					getline(cin, name);
					cout << "Geburtsdatum: ";
					getline(cin, geburtstag);
					cout << "Adresse: ";
					getline(cin, Adresse);
					cout << "Matrikelnummer: ";
					cin >> matNr;

					student = Student(matNr, name, geburtstag, Adresse);

					Studentliste.push_back (student);// Neuer Student wird am Ende hinzufügt (push).
				}
				break;
            case '2': //Datenelement löschen
            {
            	if (!Studentliste.empty()){
            	unsigned int zuLoeschendeMatrNr;
            	cout << "Geben Sie bitte die zu loeschende Matrikelnummer ein:\n" << endl;
            	cin >> zuLoeschendeMatrNr;
            	for (vector<Student> :: iterator it = Studentliste.begin() ; it != Studentliste.end(); it++) {
                     if ( it->matNr == zuLoeschendeMatrNr) {
                    	    cout << "Student mit eingegebener Matrielnummer wurde gelöscht: " << endl;
                    	    (*it).ausgabe();
            	            Studentliste.erase(it);
            	            	            	           }
            	     else {continue;}
            	}
            	} else { cout << "Die Liste ist leer!" << endl;}



            }

            	 break;

            case '3': //Datenbank ausgeben
                if(Studentliste.empty())
                {
               	  cout<<"The List is empty!"<< endl;
               break;
                }
                 cout << "Inhalt der Liste:\n";

                for (vector<Student> :: iterator it = Studentliste.begin() ; it != Studentliste.end(); it++)
                {
                	(*it).ausgabe();

                }
                 break;

            case '5': //Datenbank in umgekehrter Reihenfolge ausgeben
            {
						if(Studentliste.empty())
						{
						  cout<<"The List is empty!"<< endl;
					   break;
						}
                            cout << "Liste in umgekehrter Reihenfolge:\n";

                        for (vector<Student> :: reverse_iterator rit = Studentliste.rbegin() ; rit != Studentliste.rend(); rit++)
                                   {
                                       (*rit).ausgabe();
                                   }
            }
               break;

            case '7': //Beenden
            {
                 cout << "Das Programm wird nun beendet";
            }
               break;

            case '8': //Datenelement vorne loeschen
                       {
                    	   if(!Studentliste.empty())
                    	   					{
                    	   						 cout << "Das erste Datenelemt wird entfernt:\n";
                    	   						 Studentliste.front().ausgabe();
                    	   						 Studentliste.erase(Studentliste.begin());
                    	   					}
                    	   					else
                    	   					{

                    	   						 cout << "Die Liste ist leer!\n";
                    	   					}
                                                  }
             break;

            default :
                 cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

    return 0;
        }

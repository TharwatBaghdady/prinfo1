/** @mainpage
 *
 * Praktikum Informatik 1 MMXVIII
 * Versuch 7: überladung
 *
 * @file main.cpp
 *
 * content: main routine
 */

// Versuch 07 wurde von Versuch 06 übernommen, und wurde folgends modifiziert: Überladung von funktionen wie < > == (in Student klasse) und cout cin
// Ausserdem benutzen wir hier die sort algorithmus

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>       // std::vector
#include <algorithm>    // std::sort

using namespace std;


// Der Ausgabe Operator "cout <<" kann  nicht in der Klasse Student definiert werden weil das linke Objekt kein Student ist sondern ein objekt der klasse ostream
ostream& operator <<( ostream& ostr, Student& student)
{
	student.ausgabe(ostr);
	return ostr;
}


int main()
{
	vector<Student> Studentenliste;

	Student student = Student();
    char abfrage;
    cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    cin >> abfrage;

    if (abfrage != 'j')
    {
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		Studentenliste.push_back (student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		Studentenliste.push_back (student);
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	Studentenliste.push_back (student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		Studentenliste.push_back (student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
    	Studentenliste.push_back (student);
    }

    do
    {

         cout << "\nMenue:" <<  endl
                  << "-----------------------------" <<  endl
                  << "(1): Datenelement hinzufügen" <<  endl
                  << "(2): Datenelement abhängen" <<  endl
                  << "(3): Datenbank ausgeben" <<  endl
				  << "(4): Liste sortieren" << endl // STL "sort"
				  << "(5): Einen Student suchen und entfernen" <<  endl
				  << "(6): Datenbank in umgekehrter Reihenfolge ausgeben" << endl // STL "find"
                  << "(7): Beenden" <<  endl;
         cin >> abfrage;

        switch (abfrage)
        {
            case '1':
				{
					unsigned int matNr = 0;
					string name = "";
					string geburtsdatum = "";
					string adrese = "";

					cout << "Bitte geben Sie die Daten fuer den Studenten ein.\nName: ";
					cin.ignore(10, '\n');
					getline( cin, name);
					cout << "Geburtsdatum: ";
					getline( cin, geburtsdatum);
					cout << "Adresse: ";
					getline( cin, adrese);
					cout << "Matrikelnummer: ";
					cin >> matNr;

					student = Student(matNr, name, geburtsdatum, adrese);

					Studentenliste.push_back (student);
				}
				break;

            case '2':
            {
                      	if (!Studentenliste.empty()){
                      	unsigned int zuLoeschendeMatrNr;
                      	cout << "Geben Sie bitte die zu loeschende Matrikelnummer ein:\n" << endl;
                      	cin >> zuLoeschendeMatrNr;
                      	for (vector<Student> :: iterator it = Studentenliste.begin() ; it != Studentenliste.end(); it++) {
                               if ( it->matNr == zuLoeschendeMatrNr) {
                              	    cout << "Student mit eingegebener Matrielnummer wurde gelöscht: " << endl;
                              	    (*it).ausgabe();
                      	            Studentenliste.erase(it);
                      	            	            	           }
                      	     else {continue;}
                      	}
                      	} else { cout << "Die Liste ist leer!" << endl;}



                      }

                      	 break;



            case '3':
                {
                	if(Studentenliste.empty())
                {
               	  cout<<"liste ist leer!"<< endl;
               break;
                }
                 cout << "Inhalt der Liste:\n";

                for (vector<Student> :: iterator it = Studentenliste.begin() ; it != Studentenliste.end(); it++)
                {
                	(*it).ausgabe();
                }

                }
                 break;

            case '4':
            {
                            if(Studentenliste.empty())
                            {
                           	  cout<<"liste ist leer!"<< endl;
                           break;
                            }

                            sort(Studentenliste.begin(), Studentenliste.end());

                            cout << "Inhalt der Liste:\n";

                            for (vector<Student> :: iterator it = Studentenliste.begin() ; it != Studentenliste.end(); it++)
                            {
                            	(*it).ausgabe();
                            }
            }
            break;

            case '5':
            	                        {
            	                        	int x=0;
            	                                        if(Studentenliste.empty())
            	                                        {
            	                                       	  cout<<"Liste ist leer!"<< endl;
            	                                       break;
            	                                        }

            	                                        cout<< "Geben Sie die zu suchende Matrikelnummer ein"<< endl;
            	                                        cin>> x;

            	                                        vector<Student>::iterator it;
            	                                        student = Student(x, "", "", "");
            	                                        it = find (Studentenliste.begin(), Studentenliste.end(), student);

            											if (it != Studentenliste.end()){
            											cout << "Element gefunden in Studentenliste: \n" << *it << '\n';
            	                                        cout << "Das Datenelement wird entfernt\n";
            	                                        Studentenliste.erase (it);
            											}  	 else
            											cout << "Element nicht gefunden in Studentenliste\n";
            	                        }
            	                        break;

            case '6':
            {
            						if(Studentenliste.empty())
            						{
            						  cout<<"list ist leer!"<< endl;
            					   break;
            						}
                                        cout << "Liste in umgekehrter Rheinfolge:\n";

                                    for (vector<Student> :: reverse_iterator rit = Studentenliste.rbegin() ; rit != Studentenliste.rend(); rit++)
                                               {
                                                   (*rit).ausgabe();
                                               }
                        }
                                       break;
            case '7':
                 cout << "Das Programm wird nun beendet";
                break;

            default :
                 cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

    return 0;
}

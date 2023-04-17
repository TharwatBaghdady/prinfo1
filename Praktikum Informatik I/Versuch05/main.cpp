
#include <iostream>
#include <string>

#include "Liste.h"
#include "Student.h"

int main()
{
    List studentenListe;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
		student = Student(34567, "Sophie Klair", "19.04.1979", "Oppenhofallee 3");
		studentenListe.pushBack(student);
		student = Student(74567, "Francesco Bittonti", "03.02.1982", "Oranienstr. 2");
		studentenListe.pushBack(student);
    	student = Student(12345, "Siggi Miggi", "23.04.1993", "Hakuna matata st.50");
    	studentenListe.pushBack(student);
		student = Student(64567, "Zabola Ola", "9.01.1991", "Weidenweg 12");
		studentenListe.pushBack(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "zuzi str.9");
    	studentenListe.pushBack(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Einen bestimmten loeschen" << std::endl
				  << "(6): Datenbank vorne hinzufuegen" << std::endl
                  << "(8): Beenden" << std::endl;
        std::cin >> abfrage;

        switch (abfrage)
        {
            case '1':
				{
					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben Sie die Daten fuer den Studenten ein.\nName: ";
					std::cin.ignore(10, '\n');
					getline(std::cin, name);
					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);
					std::cout << "Adresse: ";
					getline(std::cin, adresse);
					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;

					student = Student(matNr, name, geburtstag, adresse);

					studentenListe.pushBack(student);
				}
				break;
            case '2':
            	{
					//Student delElem = Student();
					bool success = false;
					success = studentenListe.popFront();

					if(success)
					{
						std::cout << "Das erste Datenelementt wird entfernt\n";
						//delElem.ausgabe();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n";
					}
            	}
                break;

            case '3':
                std::cout << "Inhalt der Liste:\n";
                studentenListe.ausgabeVorwaerts();
                break;

            case '4':
            {
            	if(studentenListe.empty()) //Liste ist leer
            	{
                    std::cout<<"Die Liste ist leer!"<<std::endl;
                	break;
                 }
            	else
            	{
            		std::cout << "Liste in umgekehrter Rheinfolge:\n";
            		studentenListe.ausgabeRueckwaerts();
            	}
            } break;

            case '5':
             {
               if(studentenListe.empty()) //liste ist leer
                  {
                 std::cout<<"The List is empty!"<<std::endl;
                   break;
                   }

               unsigned int zuLoeschendeMatrNr;
			   std::cout << "Geben Sie bitte das zu loeschende MatrNr ein :"<<std::endl;
	           std::cin>>zuLoeschendeMatrNr;
			   bool success = false;
			   success =  studentenListe.loeschen(zuLoeschendeMatrNr);

			   if(success)
			      {
				std::cout << "Das Element wird erfolgreich entfernt"<<std::endl;
				  }
		         else
				{
				 std::cout << "Das Element nicht gefunden"<<std::endl;;
				 }
				} break;

            case '6':
            {

            	unsigned int matNr = 0;
            	std::string name = "";
            	std::string geburtstag = "";
            	std::string adresse = "";
            	std::cout << "Bitte geben sie die Daten fuer den neuen Studenten ein.\nName: ";
            	std::cin.ignore(10, '\n');

            	getline(std::cin, name);
            	std::cout << "Geburtsdatum: ";
            	getline(std::cin, geburtstag);
            	std::cout << "Adresse: ";
            	getline(std::cin, adresse);
            	std::cout << "Matrikelnummer: ";
            	std::cin >> matNr;

            	student = Student(matNr, name, geburtstag, adresse);
            	studentenListe.pushFront(student);


            } break;
            case '8':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '8');

    return 0;
}

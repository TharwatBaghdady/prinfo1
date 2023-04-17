/**
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief AUSGABE des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X "; // Spieler1
                    break;
                case 2:
                    std::cout << " O "; // Spieler2
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
	if (posX < 0 || posX >= GROESSE_X || posY < 0 || posY >= GROESSE_Y) // Position nicht auf dem Feld gefunden
{
	return false;
}
else
	return true; //position ist auf dem Feld gefunden
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
        	if (spielfeld[posY + i][posX + j] == gegner)
        				{
        					int new_x = posX+j;
        					int new_y = posY+i;

        					while (new_x >= 0 && new_x < GROESSE_X && new_y >= 0
        							&& new_y < GROESSE_Y)                         // Sobald wir im Spielfeld sind ..
        					{
        						 if (spielfeld[new_y][new_x] == 0) // position ist leer
        						{
        							break;
        						}
        						 else if (spielfeld[new_y][new_x] == aktuellerSpieler) //Zug is gültig, da wir eine Zelle erreicht haben, die mit Spieler erfüllt ist!
        						{
        							return true;
        						}
        							new_x += j; //neue x- und y-Koordinaten zur Überprüfung der nächsten Zelle. i, j sind Konstanten
        							new_y += i;

        					}
        				}        }
    }
    return false; // sonst
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler;

		for (int j = -1; j <= 1; ++j)
		{
			for (int i = -1; i <= 1; ++i)
			{

				if (spielfeld[posY + j][posX + i] != gegner) //Ignoriere die benachbarte Box, die keinen Gegner enthält
				{
					continue;
				}
				int newy = posY + j;
				int newx = posX + i; //newx und newy werden auf den korrekten Pfad zurückgesetzt
				while (newx >= 0 && newx < GROESSE_X && newy >= 0 && newy < GROESSE_Y)
				{
					if (spielfeld[newy][newx] == gegner)
					{
						newy += j;
						newx += i;
						continue; //Geh in diesen Pfad, bis wir eine 0 oder einen Spieler finden
					}
					else if (spielfeld[newy][newx] == aktuellerSpieler) //Spielerposition gefunden!!, Zurück gehen und Zellen umwandeln!
					{
						while (newy != posY || newx != posX)
						{
							newy -= j; //geh zurueck bis posY zu finden
							newx -= i; //geh zurueck bis posX zu finden
							spielfeld[newy][newx] = aktuellerSpieler;
						}
						break;
					}
					else

						break;

				}
			}
		}
}

 /**
 *@brief Diese Funktion gibt die Zahl Der Zug-Moeglichkeiten an
 *@brief Es wird so entschieden werden, dass an alle stellen durch gegangen und die bool funktion zugGueltig gecheckt wird

 * @param spielfeld ist das Feldspiel
 * @param aktuellerSpieler gibt an, zu welchem Spieler Anzahl der Zug-Moeglichkeiten gegeben wird
 * @return (int) gibt an, Anzhal moegliche Zuege eines Spielers
 */

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{










	int count = 0;
		for (int i = 0; i < GROESSE_X; i++)
		{
			for (int j = 0; j < GROESSE_Y; j++)
			{
				if (zugGueltig(spielfeld, aktuellerSpieler, j, i)) //Funktion gibt eine gültige Runde zurück
				{
					count++;
				}
			}
		}
		return count;
}

/**
 * @brief Funktion zum zugAusfuehren von mensch.
 *  Diese Funktion laesst den Spieler mensch einen Zug durchfuehren
 *
 * @param spielfeld ist das aktuelle Fieldspiel
 * @param aktuellerSpieler , welcher Spieler darn ist
 * @return false wenn keine Zuege durchgefuehrt darf, sonst true
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


void spielen(const int spielerTyp[2])
{
	int spielFeld[GROESSE_Y][GROESSE_X];
			initialisiereSpielfeld(spielFeld);
			zeigeSpielfeld(spielFeld);
			int aktuellerSpieler = 1;
			while (moeglicheZuege(spielFeld, 1) > 0 || moeglicheZuege(spielFeld, 2) > 0) //wird gespielt, bis nicht mehr Zuege durchfuehren darf
			{
				bool turn_success = false;
				if (spielerTyp[aktuellerSpieler - 1] == COMPUTER)               //computer spielt??
				{
					turn_success = computerZug(spielFeld, aktuellerSpieler);
				}
				else  //spieler_typ ist mensch!
				{
					turn_success = menschlicherZug(spielFeld, aktuellerSpieler);
				}
				if (turn_success)
				{
					zeigeSpielfeld(spielFeld);
				}
				else
				{
					std::cout << "Spieler " << aktuellerSpieler << " ist nicht in der Lage, einen Zug auszuführen." << std::endl;
				}

				aktuellerSpieler = 3 - aktuellerSpieler; //Wechsel zum anderem Spieler
			}
			std::cout << "KEINE ZUEGE MEHR MÖGLICH!" << std::endl;
			switch (gewinner(spielFeld))
			{
			case 1:
				std::cout << "Gratuliere, Spieler 1 hat gewonnen!";
				break;
			case 2:
				std::cout << "Gratuliere, Spieler 2 hat gewonnen!";
				break;
			default:
				std::cout << "Das Spiel bleibt unentscheiden!";
				break;
			}
}

int main()
{
	if (TEST == 1)
	{
		bool Ergebnis = ganzenTestAusfuehren();
		if (Ergebnis == true)
		{
			std::cout << "ALLE TESTS FUNKTIONIEREN!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "TEST ANNULIERT!" << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	int field[GROESSE_Y][GROESSE_X];
	initialisiereSpielfeld(field);
	zeigeSpielfeld(field);
	int spielerTyp[2] =
	{ COMPUTER, COMPUTER }; //Wird dann Informationen darüber enthalten, ob Spieler mensch (= 1) oder COMPUTER (= 2) sind

	std::string m_oder_c;

	do
	{
		bool falscheEingabe = true;
		char nochmalSpielen = 'S';
		while (falscheEingabe)
		{
			std::cout<< "Bitte geben Sie die zwei Gegner ein" << std::endl;
			std::cout<< "Bitte geben Sie ein: M f�r einen menschlichen Gegner, C f�r einen Computergegner"<< std::endl;
			std::cin >> m_oder_c;
			if (m_oder_c == "MM" || m_oder_c == "mm" )
			{
				spielerTyp[0] = 1;
				spielerTyp[1] = 1;
				falscheEingabe = false;

			}
			else if (m_oder_c == "MC" || m_oder_c == "mc")
			{
				spielerTyp[0] = 1;
				spielerTyp[1] = 2;
				falscheEingabe = false;

			}

			else if (m_oder_c == "CM" || m_oder_c == "cm")
			{
				spielerTyp[0] = 2;
				spielerTyp[1] = 1;
				falscheEingabe = false;

			}
			else if (m_oder_c == "CC" || m_oder_c == "cc")
			{
				spielerTyp[0] = 2;
				spielerTyp[1] = 2;
				falscheEingabe = false;

			}
			else
			{
				std::cout << "falscher input" << std::endl;
			}
		}

		spielen(spielerTyp);
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Geben Sie bitte A, wenn Sie nochmal spielen wollen!" << std::endl;
		std::cin >> nochmalSpielen;
		if (nochmalSpielen != 'A')
			break;
	} while (true);

	return 0;
}

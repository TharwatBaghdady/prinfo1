#include <iostream>
#include <string>
using namespace std;


string verschl(string);
int wortlaenge;
char lookup_array[2][26] = {	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
								{ 'Z', 'B', 'L', 'T', 'C', 'N', 'O', 'G', 'A', 'J', 'F', 'Q', 'S', 'E', 'W', 'I', 'H', 'X', 'K', 'V', 'D', 'R', 'Y', 'P', 'M', 'U' } };
string verschl(string wort){
	wortlaenge = wort.length();
	  for (int n=0; n <= (wortlaenge-1) ; n++) {
      int b_pos = (int)toupper(wort[n])-(int)'A';
	  wort[n] = lookup_array[1][b_pos];          //wählt vom zweiten Element eine Buchstabe
              };
   cout << wort << endl;
	return wort;
	           }

string entschl(string wort){
	wortlaenge = wort.length();

	for (int n=0; n <= (wortlaenge-1) ; n++) { // für jede Buchstabe im eingegebenen Wort
		for(int i=0 ; i<= 25 ;i++){

			if ( toupper(wort[n]) == lookup_array[1][i] ) {
    		    cout <<  lookup_array[0][i];    //wählt vom ersten Element eine Buchstabe
    	   };
       };
              };
	return wort;
	                               }



int main() {
    int antwort;
	string wort_e;
	cout << "Hallo, geben Sie bitte das Wort ein: " << endl;
    cin >> wort_e;
	falscheeingabe:  // Falls der Benutzer eine Eingabe anderes als 1 oder 2, kommt das Programm hier wieder!
	cout << "Wollen Sie dies (1)verschlüsseln oder (2)entschlüsseln? Bitte eine Nummer eingeben:" <<  endl;
	cin >> antwort;

	 if (antwort == 1) {

	cout<< wort_e <<" nach Verschlüsselung lautet:" << endl;
    verschl(wort_e);
	}
	else if (antwort == 2){

		cout<< wort_e << " nach Entschlüsselung lautet:" << endl;
		entschl(wort_e);
	} else {
		 cout << "Bitte nur 1 oder 2 eingeben!" <<  endl;
		goto falscheeingabe;

	}

	}


/*
 * main.cpp
 *
 *  Created on: Aug 22, 2014
 *      Author: pi
 */

#include <iostream>
#include <fstream>
#include "Maneuver.h"
using namespace std;

int main(void)
{
	//Streams zum Einlesen der Werte erzeugen
	ifstream InputFileEight;
	ifstream InputFileCircle;
	ifstream VglFileCircle;
	ifstream VglFileEight;
  Maneuver maneuver;
  maneuver.CalcCircle(2.0, 0.3, 0.04);
  maneuver.LogList("LogFileCircle.txt");

  maneuver.CalcEight(5.0, 1.0, 10.0);
  maneuver.LogList("LogFileEight.txt");
	//Vergleichsdateien oeffnen
	VglFileCircle.open("ListCircleVgl.txt", ios::in);
	if(VglFileCircle.fail())
	{
		cout << "'ListCircleVgl.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}
	VglFileEight.open("ListEightVgl.txt", ios::in);
	if(VglFileEight.fail())
	{
		cout << "'ListEightVgl.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}

	//Inputdatein oeffnen
	InputFileCircle.open("LogFileCircle.txt", ios::in);
	if(InputFileCircle.fail())
	{
		cout << "'LogFileCircle.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}
	InputFileEight.open("LogFileEight.txt", ios::in);
	if(InputFileEight.fail())
	{
		cout << "'LogFileEight.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}

	//Variablen fuer Inputwerte
	double dInput = 0.0;

	//Variablen fuer Vergleichswerte
	double dVgl = 0.0;

	//Varibale zur Uberpruefung, ob Input- und Vergleichsdatei uebereinstimmen
	bool bCorrect = true;

	//Kreis ueberpruefen
	while(!InputFileCircle.eof())
	{
		//Werte aus Inputdatei einlesen
		InputFileCircle >> dInput;

		//Wert aus Vergleichsdatei einlesen
		VglFileCircle >> dVgl;

		if(dInput != dVgl)	bCorrect = false;
	}

	//Ausgabe, ob die Kreis-Inputdatein korrekt ist
	if(bCorrect)
	{
		cout << "Die Datei 'LogFileCircle.txt' wurde korrekt erstellt" << endl;
	}
	else
	{
		cout << "Die Datei 'LogFileCircle.txt' wurde nicht korrekt erstellt" << endl;
	}

	//Acht ueberpruefen
	while(!InputFileEight.eof())
	{
		//Werte aus Inputdatei einlesen
		InputFileEight >> dInput;

		//Wert aus Vergleichsdatei einlesen
		VglFileEight >> dVgl;

		if(dInput != dVgl)	bCorrect = false;
	}

	//Ausgabe, ob die Acht-Inputdatein korrekt ist
	if(bCorrect)
	{
		cout << "Die Datei 'LogFileEight.txt' wurde korrekt erstellt" << endl;
	}
	else
	{
		cout << "Die Datei 'LogFileEight.txt' wurde nicht korrekt erstellt" << endl;
	}

	//Dateien schliessen
	InputFileCircle.close();
	InputFileEight.close();
	VglFileCircle.close();
	VglFileEight.close();

	return 0;
}




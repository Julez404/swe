// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "Liste.h"

//#include "Liste.cpp"

int main()
{
	CWiderstand r1("R1", 5.90, CPunkt(1, 2), 1000);

	CListe BauelementListe(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));

	BauelementListe.addToStart(new CBauelement("Element 2", 5.3, CPunkt(3, -5)));
	BauelementListe.addToStart(new CBauelement("Element 3", 5.3, CPunkt(3, -5)));

	BauelementListe.print();

	/*Test für CListe Temp
	CListe<CBauelement> BauelementListe(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));
	BauelementListe.addEnd(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));
	BauelementListe.addEnd(new CBauelement("Element 2", 5.9, CPunkt(-1, 5)));
	*/




	//----------------
	system("pause");
	return 0;
}
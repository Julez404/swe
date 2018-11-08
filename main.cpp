// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "Liste.h"
//#include "Liste.cpp"

std::string getName(const CBauelement& _bauelement);

std::string getName(const CBauelement& _bauelement) 
{
	return _bauelement.getName();
}


int main()
{
	CWiderstand r1("R1", 5.90, CPunkt(1, 2), 1000);

	CListe BauelementListe;
	BauelementListe.addToStart(new CWiderstand("R1", 1.5, CPunkt(3, 15), 1.5));
	BauelementListe.addToStart(new CSpule("L1", 5.3, CPunkt(7, 1), 0.05));
	BauelementListe.addToStart(new CKap("C1", 5.3, CPunkt(2, 5), 0.0003));
	BauelementListe.addToStart(new CWiderstand("R2", 5.3, CPunkt(8, 11), 13.1));
	BauelementListe.addToStart(new CWiderstand("R3", 5.3, CPunkt(12, 23), 14.1));
	BauelementListe.addToStart(new CSpule("L2", 5.3, CPunkt(17, 4), 0.150));


	BauelementListe.printAllElements();
	std::cout << std::endl;
	std::cout << "Suche Bauteil mit namen R1:" << std::endl;
	std::cout << *BauelementListe.searchName("R1") << std::endl;
	std::cout << *BauelementListe.searchName("R1") << std::endl;
	

	std::string checkName = "C1";
	std::cout << *(BauelementListe.search(checkName,&getName)) << std::endl;

	/*Test für CListe Temp
	CListe<CBauelement> BauelementListe(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));
	BauelementListe.addEnd(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));
	BauelementListe.addEnd(new CBauelement("Element 2", 5.9, CPunkt(-1, 5)));
	*/




	//----------------
	std::cout << std::endl;
	system("pause");
	return 0;
}
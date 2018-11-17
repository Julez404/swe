// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "Liste.h"

std::string getName(const CBauelement& _bauelement);
std::string getName(const CBauelement& _bauelement)
{
	return _bauelement.getName();
}

int main()
{
	std::ofstream bowde;
	double frequency = 50;

	CSpule r1("MSW", 2.5, CPunkt(5, 2), 5);

	CComplex ImpedanzToPrint;
	CBauelement* ElementToPrint;
	std::string NameToFind = "L2";
	CListe* BauelementListe = new CListe;

	BauelementListe->addToEnd(new CWiderstand("R1", 0.35, CPunkt(3, 15), 1.5));
	BauelementListe->addToEnd(new CSpule("L1", 0.81, CPunkt(7, 1), 0.05));
	BauelementListe->addToEnd(new CKap("C1", 0.15, CPunkt(2, 5), 0.0003));
	BauelementListe->addToEnd(new CWiderstand("R2", 0.25, CPunkt(8, 11), 13.1));
	BauelementListe->addToEnd(new CWiderstand("R3", 0.56, CPunkt(12, 23), 14.1));
	BauelementListe->addToEnd(new CSpule("L2", 3.1, CPunkt(17, 4), 0.150));

	BauelementListe->printAllElements();
	std::cout << std::endl;

	bowde.open("bowde.txt", std::ios::out);
	if (bowde.is_open())
	{
		for (int i = 1; i <= 1000; i++) {
			bowde << BauelementListe->getSerialImpedanz(i).getBetrag() << ";" << BauelementListe->getSerialImpedanz(i).getWinkel() << std::endl;
		}
		bowde.close();
	}


	std::cout << "Serial Impedanz for " << frequency << "Hz: " << BauelementListe->getSerialImpedanz(frequency) << std::endl;

	ElementToPrint = BauelementListe->searchName(NameToFind);
	if (ElementToPrint != NULL)
	{
		std::cout << "Impedanz for Element " << NameToFind;
		std::cout << " at " << frequency << "Hz :";
		std::cout << ElementToPrint->getImpedanz(frequency) << std::endl;
	}
	delete BauelementListe;

	std::cout << r1 << std::endl;


	//----------------
	std::cout << std::endl;
	system("pause");
	return 0;
}


/*




// std::cout << BauelementListe->search(std::string("R1"), &getName).getStart() << std::endl;


std::cout << "-- .printAllElements() --" << std::endl;
BauelementListe->searchName("R4");
std::cout << "-------------------------------------" << std::endl;


std::cout << "-- .printAllElements() --"<< std::endl;
BauelementListe->printAllElements();
std::cout << std::endl;

std::cout << "-- << overloaded --" << std::endl;
std::cout << *BauelementListe << std::endl;
std::cout << std::endl;



std::cout << "Suche Bauteil mit namen R1:" << std::endl;
if (BauelementListe->searchName("R1") != NULL)
{
std::cout << *BauelementListe->searchName("R1") << std::endl;
}
std::cout << "Suche Bauteile mit namen R1 (Return CListe)" << std::endl;
if (BauelementListe->searchName("R1") != NULL)
{
CListe listsearch;
//		std::cout << BauelementListe->search(std::string("R1"), &getName).getStart() << std::endl;


//std::cout << BauelementListe->search(std::string("R1"), &getName) << std::endl;
}

std::cout << "--------------------------------" << std::endl;
std::cout << "Delete Last Element" << std::endl;
BauelementListe->delAtEnd();
std::cout << "--------------------------------" << std::endl;


//	std::cout << BauelementListe->search(std::string("R1"), &getName) << std::endl;

delete BauelementListe;





*/
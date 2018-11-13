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

	CListe* BauelementListe = new CListe;

	BauelementListe->addToEnd(new CWiderstand("R1", 1.5, CPunkt(3, 15), 1.5));
	BauelementListe->addToEnd(new CSpule("L1", 5.3, CPunkt(7, 1), 0.05));
	BauelementListe->addToEnd(new CKap("C1", 5.3, CPunkt(2, 5), 0.0003));
	BauelementListe->addToEnd(new CWiderstand("R2", 5.3, CPunkt(8, 11), 13.1));
	BauelementListe->addToEnd(new CWiderstand("R3", 5.3, CPunkt(12, 23), 14.1));
	BauelementListe->addToEnd(new CSpule("L2", 5.3, CPunkt(17, 4), 0.150));


	BauelementListe->printAllElements();
	std::cout << std::endl;
	std::cout << "Suche Bauteil mit namen R1:" << std::endl;
	if (BauelementListe->searchName("R1") != NULL)
	{
		std::cout << *BauelementListe->searchName("R1") << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Delete Last Element" << std::endl;
	BauelementListe->delAtEnd();
	std::cout << "--------------------------------" << std::endl;


	std::cout << "--------------------------------" << std::endl;
	std::cout << "PrintAllElements()" << std::endl;
	std::string checkName = "C1";
	BauelementListe->search(checkName, &getName)->printAllElements();

	std::cout << "--------------------------------" << std::endl; 
	std::cout << "<< Overloaded" << std::endl;
	std::cout << *BauelementListe->search(checkName, &getName) << std::endl;

	std::cout << *BauelementListe->search(std::string("R1"), &getName) << std::endl;

	delete BauelementListe;
	

	//----------------
	std::cout << std::endl;
	system("pause");
	return 0;
}
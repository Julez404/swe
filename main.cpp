// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "Liste.h"
#include "Liste.cpp"

int main()
{
	//Variable Definitions
	std::ofstream plot;

	CWiderstand r1("R1", 0.35, CPunkt(3, 15), 1.5);
	CSpule l1("L1", 0.81, CPunkt(7, 1), 0.05);
	CKap c1("C1", 0.15, CPunkt(2, 5), 0.0003);

	double frequency = 0;
	CComplex Z;

	//Calc Values
	Z = r1.getImpedanz(frequency) + l1.getImpedanz(frequency) + c1.getImpedanz(frequency);

	//Print Values
	std::cout << "Z: " << Z << std::endl;
	std::cout << "|Z|= " << Z.getBetrag() << ", Winkel= " << Z.getWinkel() << std::endl;

	//Print to File
	plot.open("frequenzgang");
	if (plot.is_open())
	{
		plot << "frequency;impedanz" << std::endl;

		for (int i = 1; i < 1000; i++)
		{
			plot << i << ";" << (r1.getImpedanz(i) + l1.getImpedanz(i) + c1.getImpedanz(i)).getBetrag()
				<< std::endl;
		}
		plot.close();
	}

	CListe<CBauelement> BauelementListe(&r1);
	BauelementListe.addEnd(new CBauelement("Element 1", 1.5, CPunkt(1, 2)));
	BauelementListe.addEnd(new CBauelement("Element 2", 5.9, CPunkt(-1, 5)));
	//BauelementListe.getLastEntry();
	delete &r1;



	//----------------
	system("pause");
	return 0;
}
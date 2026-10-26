#include "PmergeMe.hpp"

bool argsIsValid(char *argv[], int argc)
{
	if (argc < 2)
		return (false);

	for (int i = 1; i < argc; i++)
	{
		std::string tmp = argv[i];
		if (tmp.empty())
			return (false);

		for (size_t x = 0; x < tmp.length(); x++)
		{
			if (!std::isdigit(tmp[x]))
				return (false);
		}

		char *end;
		long value = std::strtol(tmp.c_str(), &end, 10);
		if (*end != '\0' || value <= 0 || value > INT_MAX)
			return (false);
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (!argsIsValid(argv, argc)) {
		std::cout << "Error\n";
		return(0);
	}

	PmergeMe pm;
	pm.parseArg(argv, argc);
	pm.sortAndDisplay();


	return (1);
}
/*
ORD_JOHNSON(sequence):

    SI taille(sequence) <= 1:
        RETOURNER sequence

    paires = formerPaires(sequence)

    grands = extraire les grands éléments des paires

    grandsTries = FORD_JOHNSON(grands)

    réordonner les paires selon grandsTries

    mainChain = construire la chaîne principale
    petits = récupérer les petits éléments restants

    ordre = calculer l'ordre d'insertion Jacobsthal

    POUR chaque petit élément dans ordre:
        rechercher sa position par recherche binaire
        insérer le petit élément dans mainChain

    insérer l'éventuel élément impair

    RETOURNER mainChain
*/
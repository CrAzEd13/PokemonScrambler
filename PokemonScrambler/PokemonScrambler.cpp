#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;


int main()
{

    vector<string> Pokemon;

    //read list of pokemon in textfile PokeList.txt, store in vector
    ifstream inFile;
    inFile.open("PokemonList.txt");

    int x = 0;

    string line;
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            inFile >> line;
            Pokemon.push_back(line);
            x++;
        }
    }

    inFile.close();

    //Number of pokemon in list
    int pokemonSize = Pokemon.size();

    //randomly select one of the pokemon
    string chosenPokemon = "";

    // initializes random seed
    srand(time(NULL));

    int randMon = rand() % pokemonSize;
    chosenPokemon = Pokemon[randMon];

    // output
    cout << "Unscrambled Pokemon: " << chosenPokemon << endl << endl;
    cout << "Please wait for the Pokemon name to be scrambled." << endl << endl;

    //scramble the letters of that selected pokemon
    stringstream scrambledPokemon;
    bool repeat[30] = { 0 };

    int letters = chosenPokemon.length();
    int count = 0;
    while (count < letters)
    {
        srand(time(NULL));
        int randLetter = rand() % letters;
        if (count == 0)
        {
            scrambledPokemon << chosenPokemon[randLetter];
            chosenPokemon[randLetter];
            repeat[randLetter] = true;
            count++;
        }
        else
        {
            if (repeat[randLetter] == false)
            {
                scrambledPokemon << chosenPokemon[randLetter];
                repeat[randLetter] = true;
                count++;
            }
        }

    }

    string scrambled;
    scrambledPokemon >> scrambled;

    // writes results into Results.txt
    ofstream outFile;
    outFile.open("Results.txt");
    outFile << "Chosen Pokemon: " << endl;
    outFile << chosenPokemon << endl << endl;
    outFile << "Scrambled Pokemon: " << endl;
    outFile << scrambled << endl;



    //print scrambled
    cout << "Scrambled Pokemon: " << scrambled << endl << endl;

    cout << "Program closing" << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
/*
Ronald, Sean, Leo's CPSC 121 Final Project
Program description:
This program is a Pokedex for the first 151 Pokemon. We've created it in a way that allows for us to add more Pokemon in the future with minimal adjustments.
As well it is made to allow for more specific data to be included if desired. Ex we can include weight, and would only need to add it to each file.
The PokemonList contains 151 text files that display the Pokemon's number, name, and type1 + type2. The program can be searched based off that information and display the results.
*/
int count;
count = 151;

string search;
ifstream file;
//Search through the PokemonList folder that should be included in source file
//Allows to add more Pokemon in future if desired
map <int, string> numNameMap;
for (int i = 1; i <= count; i++) {
    //Iterates starting at 1 to hardcoded max of 151. Can be changed if more are added.
    string fileName = "./PokemonList/" + to_string(i) + ".txt";
    file.open(fileName);
    //Open file + declare variables to get data num, name, type1, type2
    int num;
    string name, type1, type2;
    int evolvesFrom;
    //read from file and assign relevant data to each
    file >> num >> name >> type1 >> type2 >> evolvesFrom;
    //?????
    numNameMap[num] = name;
    file.close();
}


//Introduction to the Pokedex can work. The format that we made allows it so it's easily modifable to add more pokemon if desired without major changes to code.
cout << "This is a Pokedex press Enter to turn it on" << endl;
string pokedex;
pokedex = "on";
cin.ignore();
//TODOclear terminal here
cout << "Pokédex: Hello! I'm a Pokédex, a digital encyclopedia of all known Pokémon." << endl;
cout << "Pokédex: 'You can search by either by name of a pokemon, by it's number, or filter for type'" << endl;


//Main search
while (pokedex == "yes" || pokedex == "on")
{
cout << "Pokedex: 'Enter 'number' to search by number, 'name' to search by the name, or 'type' to filter by type'" << endl;
cin >> search;


//If user enters the word number will conduct a search by number
if (search == "number")
{
    int searchNum;
    cout << "Enter the Pokemon's number that you want to search." << endl;
    //prompt user to enter a number that corresponse to the pokemon's number
    cin >> searchNum;
    //Search for number then display relevant data
    if (numNameMap.find(searchNum) != numNameMap.end())
    {
        // Open the text file for the Pokemon with the given number
        string fileName = "./PokemonList/" + to_string(searchNum) + ".txt";
        file.open(fileName);

        // Declare variables to store the Pokemon's name, type1, and type2
        string namenum, name, type1, type2;
        int evolvesFrom;
        // Read the name, type1, and type2 from the file
        file >> namenum >> name >> type1 >> type2 >> evolvesFrom;


        file.close();

        // Print the Pokemon's name and type
        cout << "Pokemon number: " << namenum << ", This Pokemon is " << name << " and its type is " << type1 << " and " << type2 << endl;
 if (evolvesFrom != 0) {
    cout << name << " evolves from Pokemon number " << evolvesFrom << endl;
}
       
    } else {
        //If number is too high or too low for pokemon, error message
    cout << "That Pokemon is not in this Pokedex trainer." << endl;
    }
} 


else if (search == "name")
{
    string searchName;
    cout << "Enter the Pokemon's name that you want to search." << endl;
    cin >> searchName;
    

    for (auto const& [num, name] : numNameMap)
    {
        if (name == searchName)
        {

            string fileName = "./PokemonList/" + to_string(num) + ".txt";
            file.open(fileName);


            string namenum, name, type1, type2;
            int evolvesFrom;


            file >> namenum >> name >> type1 >> type2 >> evolvesFrom;


            file.close();


            cout << "Pokemon number: " << namenum << ", This Pokemon is " << name << " and its type is " << type1 << " and " << type2 << "." << endl;
            if (evolvesFrom != 0) {
    cout << name << " evolves from Pokemon number " << evolvesFrom << endl;
}
            break;
        } 
    }

    
} else if(search == "type"){
    string searchType;
    cout << "Enter the Pokemon's type that you want to search." << endl;
    cin >> searchType;

    for (int i = 1; i <= count; i++)
    {
        string fileName = "./PokemonList/" + to_string(i) + ".txt";
        file.open(fileName);

        string namenum, name, type1, type2;

        file >> namenum >> name >> type1 >> type2;

        file.close();

        if (type1 == searchType || type2 == searchType)
        {
            cout << "Pokemon number: " << namenum << ", This Pokemon is " << name << endl;
        }
    }
}



 else {
    cout << "invalid search" << endl;
}

cout << "would you like to do another search? (yes, no)" << endl;
cin >> pokedex;

}


  return 0;
}
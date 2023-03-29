//1. Datensatz direkt einlesen nach Kalorienzahlen - direkt Aufsummieren bis Leerzeile -> dann Zuweisung an Elfenobjekt
//----Direktes Aufsummieren bis zum Iterieren hin zu leerer Zeile, STOPP, Zuweisen des Werts an ein Objekt Elfe--
//2. Klasse Elfe enthält: Nummer Elfe und Kalorienanzahl der Elfe, bei Leerzeile muss erst ein Elfenobjekt angelegt werden!
//3. Die angelegten Elfenobjekte nach Kalorienanzahl sortieren, Elfe mit meisten Kalorien am Anfang der Liste 
//-----Erste Elfe mit meisten Kalorien auf cmd ausgeben mit Nummer und Kalorien
//Ordner: C:\\01_Projects\\01_ProgrammingVS\\02_CC++\\SiemensEinarbeitung\\CodingAdventCalendar\\Input.txt
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

class elve
{
    private:
    int number = 0;
    int calories = 0;

    public:
    elve (int number_, int calories_) : number (number_), calories (calories_) {}

    int get_number (){return number;};
    int get_calories () {return calories;};
};

//Functions
list<elve>  calc_calories_reindeer (ifstream & input);

//Templates 
template<class T> T fromString(const string & s)
{
     istringstream stream (s);
     T t;
     stream >> t;
     return t;
}

//sort-instruction
bool compare_calories (elve one , elve two)
{
    return one.get_calories() > two.get_calories();
}

//sort from highest calories to lowest
void search_most_calories (list <elve> elves);


int main ()

{
    ifstream elves_data("C:\\01_Projects\\01_ProgrammingVS\\02_CC++\\SiemensEinarbeitung\\CodingAdventCalendar\\Input.txt");
    list<elve>::iterator i;
    search_most_calories (calc_calories_reindeer(elves_data));

}

//This function should give a list of elves back 
list<elve> calc_calories_reindeer (ifstream & input)

{
    string current_line;
    int sum_calories_reindeer = 0;
    int counter = 0;
    list <elve> elves;
    while (getline(input, current_line))
    {
        if (current_line == "")
        {
            counter += 1;
            //Append elve objet to list
            elve placeholder (counter,sum_calories_reindeer);
            elves.push_back(placeholder);
            sum_calories_reindeer = 0;
        }

        else
        {
            sum_calories_reindeer += fromString<int>(current_line);
        }
    }
   
   //Last reeinder
   counter += 1;
   elve placeholder (counter,sum_calories_reindeer);
   elves.push_back(placeholder);
   return elves;
}

//This functions sorts from most calories to lowest
void search_most_calories (list <elve> elves)
{
   elves.sort (compare_calories);
    cout << "The elve with the most carried calories is...Elve number " << (elves.begin())->get_number() << " with " << 
    (elves.begin())->get_calories() << " calories" << endl;

}


#include <iostream>
using namespace std;

/* /// Projektname: Notendurchschnittrechner und Statusbewerter///
  
  Dieses Projekt dient dem User bei dem Berechenen des Notendurchschnitt und weitere Tools: 
  - Notendurchschnitt von einem Schüler oder mehreren Schülerin
  - Status anzeigen (ob bestanden oder durchgefallen )
  - Notendurchschnitt der ganzen Klassen
  - Beste Note zeigen
 
  

*/

struct stFaecherNoten
{
    float Deutsch, Englisch, Mathe, Sport;

};

struct stSchuelerInfos
{ 
    string Name = "";
    string Klasse = "";
    short Alter = 0;

    stFaecherNoten FaecherNoten = { 0, 0, 0, 0 };

};

void ReadSchuelerInfosUndNoten(stSchuelerInfos &Schueler)

{
    
   
    
    cout << "\nGib bitte deinen Namen: ";
    cin >> Schueler.Name;

    cout << "\nGib bitte dein Alter: ";
    cin >> Schueler.Alter;

    cout << "\nGib bitte deine Klasse: ";
    cin >> Schueler.Klasse;

    cout << "\nGib bitte deine Note in Deutsch: ";
    cin >> Schueler.FaecherNoten.Deutsch;

    while (Schueler.FaecherNoten.Deutsch < 0 || Schueler.FaecherNoten.Deutsch > 100)

    {
        cout << "\nFalsche Eingabe, Gib die Deutsch-Note zwischen 0 und 100: ";
        cin >> Schueler.FaecherNoten.Deutsch;

    }

    cout << "\nGib bitte deine Note in Englisch: ";
    cin >> Schueler.FaecherNoten.Englisch;

    while (Schueler.FaecherNoten.Englisch < 0 || Schueler.FaecherNoten.Englisch > 100)

    {
        cout << "\nFalsche Eingabe, Gib die Englisch-Note zwischen 0 und 100: ";
        cin >> Schueler.FaecherNoten.Englisch;

    }

    cout << "\nGib bitte deine Note in Mathe: ";
    cin >> Schueler.FaecherNoten.Mathe;

    while (Schueler.FaecherNoten.Mathe < 0 || Schueler.FaecherNoten.Mathe > 100)

    {
        cout << "\nFalsche Eingabe, Gib die Mathe-Note zwischen 0 und 100: ";
        cin >> Schueler.FaecherNoten.Mathe;

    }

    cout << "\nGib bitte deine Note in Sport: ";
    cin >> Schueler.FaecherNoten.Sport;

    while (Schueler.FaecherNoten.Sport < 0 || Schueler.FaecherNoten.Sport > 100)

    {
        cout << "\nFalsche Eingabe, Gib die Sport-Note zwischen 0 und 100: ";
        cin >> Schueler.FaecherNoten.Sport;

    }
}

float RechneNotendurchschnitt(stSchuelerInfos Schueler)

{
    float Durchschnitt = (Schueler.FaecherNoten.Deutsch+ Schueler.FaecherNoten.Englisch+ Schueler.FaecherNoten.Mathe+ Schueler.FaecherNoten.Sport) / 4;

   

    return Durchschnitt;
}

string StatusBewertung(float Notendurchschnitt, string bewertung1 = "Bestanden", string bewertung2 = "Durchgefallen")
{
   
    if (Notendurchschnitt >= 50 && Notendurchschnitt <= 100)

     {
        
        return bewertung1;
       
    }
    else
    {
        
        return bewertung2;

    }
}

void PrintEingabenUndBewertung(stSchuelerInfos Schueler)
{
    cout << endl << endl << "__________________________________________" << endl;
    cout << endl << "             {----Schueler----}\n";
    cout << "              Name: " << Schueler.Name << endl;
    cout << "              ALter: " << Schueler.Alter << endl;
    cout << "              Klasse: " << Schueler.Klasse << endl;
    cout << endl << "             {----Noten----}\n";
    cout << "              Deutsch : [" << Schueler.FaecherNoten.Deutsch  << "]" << endl;
    cout << "              Englisch: [" << Schueler.FaecherNoten.Englisch << "]" << endl;
    cout << "              Mathe   : [" << Schueler.FaecherNoten.Mathe    << "]" << endl;
    cout << "              Sport   : [" << Schueler.FaecherNoten.Sport    << "]" << endl;
    cout << endl << "             {----Durchschnitt----}\n";
    float schnitt = RechneNotendurchschnitt(Schueler);

    cout << "             Notendur.: ["     << schnitt <<      "]" << endl;
    cout << endl << "__________________________________________" << endl;

    
    cout << "             Status   : [[[  " << StatusBewertung(schnitt) << "]]]" <<endl<<endl ;
   
}


    int main()
    {
        cout << endl << "________________________________________________Notenverwaltungssystem__________________________________________________" << endl << endl;
        cout << "Made by Amr Haushaby (; after finishing C++ Course Level 1 with ProgrammingAdivces" ;
        cout << endl << "__________________________________________" << endl << "Durchschnitt für Noten zwischen 0 und 100 "<< endl << "__________________________________________" << endl << endl;
        
        int anzahl = 0;
        cout << "Wie viele Schueler willst du eingeben? ";
        cin >> anzahl;

        stSchuelerInfos klasse[100];

        for (int i = 0; i < anzahl; i++) {
            cout << "\n== Schueler " << i + 1 << " eingeben ==\n";
            ReadSchuelerInfosUndNoten(klasse[i]);
        }

        float gesamtDurchschnitt = 0;
        float besteNote = 0;

        for (int i = 0; i < anzahl; i++) {
            cout << "\n== Schueler " << i + 1 << " anzeigen ==\n";
            PrintEingabenUndBewertung(klasse[i]);

            float schnitt = RechneNotendurchschnitt(klasse[i]);
            gesamtDurchschnitt += schnitt;

            if (schnitt > besteNote)
                besteNote = schnitt;
        }

        float klassendurchschnitt = gesamtDurchschnitt / anzahl;
        cout << "\n\n==========================\n";
        cout << "=Klassendurchschnitt: " << klassendurchschnitt << endl;
        cout << "=Beste Durchschnittsnote: " << besteNote << endl;
        cout << "==========================\n";

        return 0;
    }

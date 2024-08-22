#include <iostream>
#include <unordered_map>
#include <regex>
using namespace std;

void naytaNullptr() {
    // nullptr eli nullososoitin on C++11 ominaisuus, joka osoittaa nulliin. Se korvaa NULL:in, koska nullptr on tyypitetty
    int* ptr = nullptr;
    cout << "nullpointer on " << ptr << endl;
}

void naytaAuto() {
    // Auto on C++11 ominaisuus, joka mahdollistaa muuttujan tyypin automaattisen määrittämisen
    auto i = 42;
    auto d = 3.14;
    auto c = 'abc';
    cout << "i on " << i << endl;
    cout << "d on " << d << endl;
    cout << "c on " << c << endl;
}

void naytaFor()
{
    // Range-based for loop on C++11 ominaisuus, joka helpottaa taulukoidenläpikäyntiä
    int arr[] = { 1, 2, 3, 4, 5 };
    for (auto i : arr) {
        cout << i << "\n";
    }
    cout << endl;
}

void naytaFinalOverride()
{
    // Final estää perimisen ja override pakottaa ylikirjoittamaan funktion
    // Override tarkoittaa, että funktiota on pakko ylikirjoittaa perityssä luokassa
    class Ajoneuvo
    {
    public:
        virtual void a() const
        {
            cout << "Joka periytyy ajoneuvosta" << endl;
        }
        // Tätä ei voi ylikirjoittaa
        virtual void b() const final
        {
            cout << "Tämä on final funtkio" << endl;
        }
    };
    class Rekka : public Ajoneuvo
    {
    public:
        void a() const override
        {
            cout << "Tämä on rekka" << endl;
        }
    };
    Rekka rekka;
    rekka.a();
    rekka.b();
}

void naytaLongLongInt()
{
    // Long long int on 64-bittinen kokonaisluku, joka voi olla 9,223,372,036,854,775,807 ja -9,223,372,036,854,775,808 välillä.
    // Long int on vain 32-bittinen kokonaisluku, joka voi olla 2,147,483,647 ja -2,147,483,648 välillä.
    long long int numerosarja = 1234567890123456789;
    long int lyhytsarja = 1234567890123456789;
    cout << "long long int on " << numerosarja << endl;
    cout << "long int on " << lyhytsarja << endl;
}
void naytaHashTaulu()
{
    // Hash-taulu on tietorakenne, joka tallentaa avain-arvo -parit. Tässä tallennetaan numerot sanallisesti numeroihin
    unordered_map<string, int> map = {
        {"yksi", 1},
        {"kaksi", 2},
        {"kolme", 3}
    };
    for (const auto& pari : map)
    {
        cout << pari.first << ": " << pari.second << endl;
    }
}
void naytaSaannollisetLausekkeet()
{
    // std:regex on C++11 standardikirjasto, joka mahdollistaa säännöllisten lausekkeiden käytön
    // Tässä tarkistetaan onko annettu sana numero
    string sana = "123";
    string sana2 ="yksikaksikolme";
    regex r("[0-9]+");
    if (regex_match(sana, r))
    {
        cout << "Sana "<< sana << " on numero" << endl;
    }
    if (!regex_match(sana2, r))
    {
        cout << "Sana "<< sana2 << " ei ole numero" << endl;
    }
}
int main(int argc, char* argv[]) {
    string sana = "123";
    string sana2 ="yksikaksikolme";
    char valinta;
    cout << "Valitse tehtävä (a:sta g:hen)";
    cin >> valinta;

    switch (valinta) {
    case 'a':
        naytaNullptr();
        break;
    case 'b':
        naytaAuto();
        break;
    case 'c':
        naytaFor();
        break;
    case 'd':
        naytaFinalOverride();
        break;
    case 'e':
        naytaLongLongInt();
        break;
    case 'f':
        naytaHashTaulu();
        break;
    case 'g':
        naytaSaannollisetLausekkeet();
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}
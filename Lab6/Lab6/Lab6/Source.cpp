#include <iostream>
#include<cassert>
using namespace std;

//HOMEWORK - Implementati o clasa care sa lucreze cu siruri de caractere, asemeni clasei String din std.
/*class MyString
* {
* char* str;
* int len;
* public:
* -constructor cu 2 parametri
* -constructor de copiere
* -metode de set si get
* -deconstructor
* -supraincarcare operator = 
* };
* - exemplificare in main pentru toate functionalitatile in main:
*  ~ evidentiere apel contructor cu param
*  ~ evidentiere constructor de copiere
*  ~ evidentiere operator =
*/

//ce este un membru static in cadrul unei clase
//apartine clasei, nu obiectelor

class Fractie
{
private:
    //static int x; //inaccesibil - trebuie implementat un setter
    int m_numarator{ 0 };
    int m_numitor{ 1 };
    static int count;



public:
    //static int x;
    // Default constructor
    Fractie(int numarator = 0, int numitor = 1)
        //: m_numarator(numarator), m_numitor(numitor)
    {
        this->m_numitor = numitor; //pt a stii ca trebuie modificat
        this->m_numarator = numarator;

        //m_numitor = m_numitor; //the same thing
        //m_numarator = m_numarator;

        //assert(numitor != 0);
        Fractie::count++;
    }

    // Copy constructor
    Fractie(const Fractie& copy)
        : m_numarator{ copy.m_numarator }, m_numitor{ copy.m_numitor }
    {
        // nu mai este nevoie de verificarea numitorului pentru ca operatiile se fac asupra a doua obiecte existente - au fost verificate in cadrul constructorului
        cout << "S-a apelat constructorul de copiere.\n";
    }

    static void setCount(int count) //modifica fara a avea un obct instantiat
    {
        Fractie::count;
    }

    void setCount0(int count)
    {
        Fractie::count = count;
    }
    // Supraincarcarea operatorului de atribuire:  =
   // Fractie& operator= (const Fractie& fractie);

    //shallow copy - se copiaza doar adresa
    //deep copy - invers

    //void operator= (const Fractie& fractie);

    Fractie& operator= (const Fractie& fractie); // nu se permite efectuarea copiilor prin asignare!
};

int Fractie::count = 0;
//int Fractie::x = 0; //unresolved ext symbol - cand se face compilarea, se cauta valoarea; trebuie sa existe o valoare initiala
// O alta implementare => void??

//void Fractie::operator= (const Fractie& fractie)
//{
//    // se evita autoasignarea - pt ca evitam o operatie reduct
//    if (this == &fractie)
//        return;
//
//    m_numarator = fractie.m_numarator; //este this sau fractie? este this pt ca e tot methoda din cls resp
//    m_numitor = fractie.m_numitor;
//
//
//    return;
//}


// O implementare mai buna - corecta => discutie

Fractie& Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie) //pt ca se creeaza inca o copie
        return *this;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return *this;
}




int main()
{
    Fractie fff(1, 2);
    Fractie fff1;
    fff1 = fff; //nu se apeleaza constructorul de copiere //f1 e this

    Fractie fff2 = fff; //se apeleaza contrcutorul de copiere

    fff2.setCount0(9);
    Fractie::setCount(10);

   Fractie _5p3{ 5, 3 };
    Fractie f = _5p3;
//    Fractie::x = 3;
    Fractie ff;      //cine se apeleaza?
    ff = _5p3; //cine se apeleaza?

    Fractie f1(3,5);
    Fractie f2(2,4);
    Fractie f3(6,9);

    f1 = f2 = f3; //asignare inlantuita - eroare pt ca 
    //f1=f2 -> se returneaza void
    //f1=f2=f3 -> f2 ia valorile lu f3, se ret void
    //f1=void -> se com liniile 57 + 66-77
   
//    f1 = f2;// = f3; //asignare inlantuita
//
//    f1 = f1; // autoasignare
//
//
//    return 0;
}
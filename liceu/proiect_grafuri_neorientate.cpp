#include <iostream>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> //pt system("cls")
#include <string.h>
#include <bits/stdc++.h> // transform function - transforare sir din cartere mari in mici

using namespace std;

//declararea functiilor
/*===================================================================*/
void afisare_nume();
int citeste_optiune_meniu(int max_optiuni);
/*===================================================================*/
void meniu_principal();


/*===================================================================*/
void mp_1_definitii();


/*===================================================================*/
void mp_2_grad_varf();

void m_gr_vf_1_def();

void m_gr_vf_2_vf_izolat();
void vf_izolat_1_def();
void vf_izolat_2_aplicatie();

void m_gr_vf_3_vf_terminal();
void vf_terminal_1_def();
void vf_terminal_2_aplicatie();


/*===================================================================*/
void mp_3_met_reprezentare();
void metode_repr_1_ls_adiacenta();
void metode_repr_2_vect_muchii();

void metode_repr_3_matr_adiacenta();
void matr_adiacenta_1_def();
void matr_adiacenta_2_aplicatie();


/*===================================================================*/
void mp_4_parcurgere() ;
void parcurgere_1_latime();
void parcurgere_2_inaltime();


/*===================================================================*/
void mp_5_conexitate();
void conexitate_1_def();
void conexitate_2_verif_graf_conex();

/*===================================================================*/
void mp_6_graf_hamiltonian();
void hamitonian_1_teorie();
void hamiltonian_2_verificare();


/*===================================================================*/
void mp_7_graf_eulerian();
void eulerian_1_teorie();
void eulerian_2_verificare();

/*===================================================================*/
void mp_8_aplicatii();
void apl_1();
void apl_2();
void apl_3();

/*===================================================================*/
void mp_9_test();
void test();
int intrebare_cu_un_raspuns(char* intrebare, int raspuns_corect);
int intrebare_cu_r_scurt(char* intrebare, string raspuns_corect);
int verifica_raspuns_multiplu(string r_dat, string r_corect);
int intrebare_cu_mm_raspunsuri(char* intrebare, string raspuns_corect);

//Intrebari pentru test - optiunea 9
/*===================================================================
 Intrebari cu un singr raspuns
 ====================================================================*/

char intrebare_1[] = "\
\nIntrebarea 1. Un graf neorientat poate fi arbore numai daca:\n\
1) nu este conex\n\
2) nu contine cicluri\n\
3) are n muchii, unde n este numarul de varfuri\n\
4) contine cicluri\n\
 \n\
Dati raspunsul: "; // r corect: 2

char intrebare_2[] = "\
\nIntrebarea 2. Un graf G=(X,U) neorientat este conex daca si numai daca:\n\
1) pentru orice pereche (x,y) x != y exista un lant de la x la y, x,y € X\n\
2) pentru orice pereche (x,y) x !=y exista o muchie u=[x,y], u € U\n\
3) pentru orice pereche (x,y) x != y exista un drum de la x la y\n\
4) nici un raspuns anterior nu este corect\n\
 \n\
Dati raspunsul: "; // r corect: 1

char intrebare_3[] = "\
\nIntrebarea 3. Precizati care din urmatoarele afirmatii caracterizeaza\n\
matricea de adiacenta asociata unui graf neorientat complet\n\
1) matricea nu este patratica\n\
2) fiecare linie a matricei contine n-1 valori nenule\n\
3) matricea este simetrica fata de diagonala secundara\n\
4) exista cel putin o coloana a matricei care are toate componentele nule\n\
 \n\
Dati raspunsul: "; // r corect: 2

char intrebare_4[] = "\
\nIntrebarea 4. Care dintre urmatoarele afirmatii sunt corecte? \n\
1) intr-un graf neorientat o muchie poate fi adiacenta cu un varf.\n\
2) intr-un graf neorientat doua muchii pot fi adiacente.\n\
3) intr-un graf neorientat o muchie poate fi incidenta cu un varf. \n\
4) intr-un graf neorientat două varfuri pot fi incidente.\n\
 \n\
Dati raspunsul: "; // r corect: 3

/*===================================================================
 Intrebari cu mai multe raspunsuri
 ====================================================================*/

char intrebare_5[] = "\
\nIntrebarea 5. Un graf neorientat cu n varfuri poate fi arbore daca: \n\
1) are n-1 muchii\n\
2) are n+1 muchii\n\
3) este conex, fara cicluri\n\
4) este conex si cu cicluri\n\
\n\
Dati raspunsurile separate de virgula sau spatiu: "; // r corect: 1, 3

char intrebare_6[] = "\
\nIntrebarea 6. Un graf neorientat este eulerian daca: \n\
1) este conex\n\
2) gradul fiecarui varf e nr par\n\
3) are varf izolat\n\
4) nu contine cicluri\n\
\n\
Dati raspunsurile separate de virgula sau spatiu: "; // r corect: 1, 2

char intrebare_7[] = "\
\nIntrebarea 7. Cum se poate parcurge graful: \n\
1) in inaltime\n\
2) in adancime\n\
3) in latime\n\
4) in lungime\n\
\n\
Dati raspunsurile separate de virgula sau spatiu: "; // r corect: 2, 3

/*===================================================================
 Intrebari cu raspuns scurt
 ====================================================================*/

char intrebare_8 [] = "\
\nIntrebare 8. Cum se numeste varful care are gradul 1?\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // terminal

char intrebare_9 [] = "\
\nIntrebare 9. Cum se numeste graful care contine toate varfurile sale fara sa le repete?\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // hamiltonian

char intrebare_10 [] = "\
\nIntrebare 10. Graful in care oricare doua varfuri pot fi extremitatile unui lant se numeste?\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // conex
/*===================================================================
    Citire nume de la tastatura
=====================================================================*/
void afisare_nume() {

    string asteapta_enter; //doar sa avem unde sa punem ce citim cu cin. Nu folosim pentru altceva variabila
    string nume_prenume;
    string clasa;

    cout << "Dati numele: ";
    getline(cin, nume_prenume);
    //asteapta_enter = "";

    cout << "Dati clasa: ";

    //cout << "Apasati tasta ENTER pentru a continua testul!" << endl;
    getline(cin, clasa);

    system("cls");
}
/*===================================================================
   Citire optiuni
=====================================================================*/
int citeste_optiune_meniu(int max_optiuni) {
    int r;
    int incercare = 0;
    cout << "Alegeti o optiune de meniu (ex: 1 / 2 ... )." << endl;
    do {
        if(incercare > 0)
            cout << "Alegeti o optiune de meniu (ex: 1 / 2 ... ). Optiunea selectata: " << r << endl;

        incercare++;
        cin >> r;
    } while ( r < 0 || r > max_optiuni );

    return r;
}
/*============================================================
    MENIU PRINCIPAL
*=============================================================*/
void meniu_principal() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu principal:" << endl << endl;

        cout << "      1. Definitii" << endl << endl;

        cout << "      2. Gradul unui varf" << endl << endl;

        cout << "      3. Metode de reprezentare" << endl << endl;

        cout << "      4. Parcurgere" << endl << endl;

        cout << "      5. Conexitate" << endl << endl;

        cout << "      6. Graf Hamiltonian" << endl << endl;

        cout << "      7. Graf Eulerian" << endl << endl;

        cout << "      8. Aplicatii" << endl << endl;

        cout << "      9. Test" << endl << endl;

        cout << "      10. Iesire" << endl << endl;


        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(10);

        cout << "MP. Ales: " << o << endl;

        switch(o) {
        case 1:
            mp_1_definitii();
            break;

        case 2:
            mp_2_grad_varf();
            break;

        case 3:
            mp_3_met_reprezentare();
            break;

        case 4:
            mp_4_parcurgere();
            break;

        case 5:
            mp_5_conexitate();
            break;

        case 6:
            mp_6_graf_hamiltonian();
            break;

        case 7:
            mp_7_graf_eulerian();
            break;

        case 8:
            mp_8_aplicatii();
            break;

        case 9:
             mp_9_test();
            break;

        case 10:
            cout << "Ati ales optiunea '10' -> Terminare program";
            break;
        }
    } while(o != 10);


}
/*===============================================================
   opt 1 - meniu principal - definitie graf
=================================================================*/
void mp_1_definitii() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Grafuri - definitii" << endl;
    cout << "\n\n\
    Graf neorientat = o pereche ordonata de multimi (X,U), unde:\n\
        -X este o multime finita si nevida (multimea varfurilor sau nodurilor);\n\
        -U este o multime de perechi neordonate de elemente din multimea X (multimea muchiilor).\n\n\n\
    Pentru x, y care sunt in X, (x, y) sau [x, y] reprezinta o muchie.\n\n\n\
    Lant in graful neorientat G = o succesiune de varfuri L = (x1, x2,..., xk), unde x1, x2,..., xk sunt in X\n\
    cu proprietatea ca oricare doua varfuri consecutive sunt adiacente ( adica, exista, in graf, muchiile\n\
    (x1, x2),( x2, x3),..., (xk-1, xk)).\n\n\n\
    Ciclu in graful neorientat G = un lant C = (x1, x2,..., xk), unde x1, x2,..., x sunt in X,\n\
    cu proprietatea ca x1 = xk si muchiile (x1, x2), (x2, x3),..., (xk-1, xk) sunt distincte doua cate doua.\n\n\n\
    Un graf partial al unui graf G este un graf G1=(X, V), cu V inclus sau egal cu U.\n\n\n\
    Un subgraf al unui graf G este un graf G' = (Y, V), cu Y inclus in X si V inclus in U, unde V va contine\n\
    numai muchiile care au ambele extremiati in noua multime Y.\n\n\n\
    Un graf G=(X, U) se numeste graf bipartit daca exista doua multimi nevide A si B astfel incat X = A reunit cu B,\n\
    A intersectat cu B = multimea vida, si orice muchie u a lui G are o extremitate in A iar cealalta in B.\n\
    Multimile A si B formeaza o partitie a lui X.\n\n\
    Un graf bipartit G=(X,U) se numeste bipartit complet daca pentru oricare doua varfuri x din A si y din B,\n\
    exista in graf muchia [x,y]; adica [x,y] aprtine lui U.";


    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;
    /*graf neorientat, muchie, lanţ,
    ciclu, graf parţial, subgraf, graf complet,
    graf bipartit, graf bipartit complet*/

    getch();
    getline(cin, buffer);
}
/*=================================================================
  opt 2 - meniu principal - grad varf
 =================================================================*/
void mp_2_grad_varf() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu gradul unui varf:" << endl << endl;

        cout << "      1. Definitii" << endl << endl;

        cout << "      2. Varf izolat" << endl << endl;

        cout << "      3. Varf terminal" << endl << endl;

        cout << "      4. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(4);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            m_gr_vf_1_def();
            break;

        case 2:
             m_gr_vf_2_vf_izolat();
            break;

        case 3:
            m_gr_vf_3_vf_terminal();
            break;

        case 4:
            cout << "Ati ales optiunea '4' -> revenire la meniul principal";
            break;
        }
    } while(o != 4);
}
/*===================================================================*/
// meniu grad vf - optiunea 1 - definitii
void m_gr_vf_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Gradul unui varf - definitii" << endl;

    cout << "\n\n\
    Gradul varfului x = ( notat d(x) ) reprezinta numarul muchiilor incidente cu varful x.";

    getch();
    getline(cin, buffer);
}
/*===================================================================*/
//meniu grad vf - opt 2 - varf izolat - care deschide un alt meniu
void m_gr_vf_2_vf_izolat() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu varf izolat:" << endl << endl;

        cout << "      1. Definitie" << endl << endl;

        cout << "      2. Aplicatie" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            vf_izolat_1_def();
            break;

        case 2:
            vf_izolat_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}
/*===========================*/
// meniu vf izolat - opt 1 - definitii
void vf_izolat_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Varf izolat - definitie" << endl;
    cout << "\n\n\
    Varf izolat = Un varf care nu este adiacent cu niciun alt varf (gradul sau este 0).";

    getch();
    getline(cin, buffer);
}
/*===========================*/
void vf_izolat_2_aplicatie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Varf izolat - aplicatie" << endl;

    getch();
    getline(cin, buffer);
}
/*===================================================================*/
//meniu grad vf - opt 2 - varf izolat - care deschide un alt meniu
void m_gr_vf_3_vf_terminal() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu varf terminal:" << endl << endl;

        cout << "      1. Definitie" << endl << endl;

        cout << "      2. Aplicatie" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            vf_terminal_1_def();
            break;

        case 2:
            vf_terminal_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}
/*===========================*/
void vf_terminal_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Varf terminal - definitie" << endl;
    cout << "\n\n\
    Varf terminal = Un varf care nu este adiacent decat cu un singur alt varf (gradul sau este 1).";

    getch();
    getline(cin, buffer);
}
/*===========================*/
void vf_terminal_2_aplicatie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Varf terminal - aplicatie" << endl;

    getch();
    getline(cin, buffer);
}
/*======================================================================
 opt 3 - meniu PRINCIPAL - metode reprezentare
=====================================================================*/
void mp_3_met_reprezentare() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu metode de reprezentare:" << endl << endl;

        cout << "      1. Liste de adiacenta" << endl << endl;

        cout << "      2. Vectorul muchiilor" << endl << endl;

        cout << "      3. Matrice de adiacenta" << endl << endl;

        cout << "      4. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(4);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            metode_repr_1_ls_adiacenta();
            break;

        case 2:
            metode_repr_2_vect_muchii();
            break;

        case 3:
            metode_repr_3_matr_adiacenta();
            break;

        case 4:
            cout << "Ati ales optiunea '4' -> revenire la meniul principal";
            break;
        }
    } while(o != 4);
}
/*===================================================================*/
// opt 1 meniu met reprezentare - lista adiacenta
void metode_repr_1_ls_adiacenta() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Lista adiacenta - definitie + program + executie" << endl;
    cout <<"\n\n\
    Lista de adiacenta va contine doua coloane, una cu varfurile grafului, iar cealalta\n\
    cu varfurile adiacente fiecarui varf din graf.";


    getch();
    getline(cin, buffer);
}

/*===================================================================*/
// opt 2 meniu met reprezentare - vectorul muchiilor
void metode_repr_2_vect_muchii() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Vectorul muchiilor - definitie + program + executie" << endl;
    cout <<"\n\n\
    Vectorul muchiilor va contine muchiile grafului, care au ca si parametrii doua varfuri.";

    getch();
    getline(cin, buffer);
}
/*===================================================================*/
// opt 1 meniu met reprezentare - matrice de adiacenta - care deschide alt meniu
void metode_repr_3_matr_adiacenta() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu matrice adiacenta:" << endl << endl;

        cout << "      1. Definitie + Caracteristici" << endl << endl;

        cout << "      2. Aplicatie" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            matr_adiacenta_1_def();
            break;

        case 2:
            matr_adiacenta_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}
/*===========================*/
void matr_adiacenta_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Matrice adiacenta - definitie + caracteristici" << endl;
    cout << "\n\n\
    Este o matrice (A) cu n linii si n coloane, ale carei elemente sunt definite astfel:\n\
    a(i, j) = { 1,  daca i, j apartine lui U, cu i != j sau 0,  in caz contrar\n\n\
    Caracteristicile unei matrice de adiacenta definita pentru un graf neorientat dat:\n\
        - este patratica\n\
        - este binara\n\
        - este simetrica fata de diagonala principala\n\
        - diagonala principala contine doar valori egale cu zero. ";
    getch();
    getline(cin, buffer);
}
/*===========================*/
void matr_adiacenta_2_aplicatie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Matrice adiacenta - aplicatie" << endl;

    getch();
    getline(cin, buffer);
}
/*=====================================================================
  opt 4 - meniu PRINCIPAL - parcurgere
======================================================================*/

void mp_4_parcurgere() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu parcurgere:" << endl << endl;

        cout << "      1. In latime" << endl << endl;

        cout << "      2. In inaltime" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            parcurgere_1_latime();
            break;

        case 2:
            parcurgere_2_inaltime();
            break;

        case 3:

            break;
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";

        }
    } while(o != 3);
}

/*===========================*/
void parcurgere_1_latime() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "In latime - program + executie" << endl;

    getch();
    getline(cin, buffer);
}


/*===========================*/
void parcurgere_2_inaltime() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "In inaltime - program + executie" << endl;

    getch();
    getline(cin, buffer);
}

/*=====================================================================
  opt 5 - meniu PRINCIPAL - Conexitate
======================================================================*/

void mp_5_conexitate() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu conexitate:" << endl << endl;

        cout << "      1. Definitie graf conex, componenta conexa" << endl << endl;

        cout << "      2. Verificare graf conex" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            conexitate_1_def();
            break;

        case 2:
            conexitate_2_verif_graf_conex();
            break;

        case 3:

            break;
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";

        }
    } while(o != 3);
}

/*===========================*/
void conexitate_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Definitie graf conex, componenta conexa - def" << endl;
    cout << "\n\n\
    Graf conex  = oricare doua varfuri ale sale pot fi extremitatile unui lant.\n\n\
    Componenta conexa a unui graf neorientat G = (X, U) este un subgraf G1 = (Y, V) al lui G,\n\
    conex, cu proprietatea ca nu exista niciun lant care sa aiba o extremitate in Y si cealalta in X-Y.";

    getch();
    getline(cin, buffer);
}


/*===========================*/
void conexitate_2_verif_graf_conex() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare graf conex - program + executie" << endl;

    getch();
    getline(cin, buffer);
}

/*=====================================================================
  opt 6 - meniu PRINCIPAL - Graf Hamiltonian
======================================================================*/

void mp_6_graf_hamiltonian() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu graf hamiltonian:" << endl << endl;

        cout << "      1. Teorie" << endl << endl;

        cout << "      2. Verificare" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            hamitonian_1_teorie();
            break;

        case 2:
            hamiltonian_2_verificare();
            break;

        case 3:

            break;
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";

        }
    } while(o != 3);
}

/*===========================*/
void hamitonian_1_teorie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Teorie graf Hamiltonian - def" << endl;
    cout << "\n\n\
    Ciclu hamiltonian intr-un graf neorientat G = un ciclu elementar care contine\n\
    toate varfurile grafului.\n\n\
    Graf hamiltonian = un graf care contine un ciclu hamiltonian.";

    getch();
    getline(cin, buffer);
}


/*===========================*/
void hamiltonian_2_verificare() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare - program + executie" << endl;

    getch();
    getline(cin, buffer);
}

/*=====================================================================
  opt 7 - meniu PRINCIPAL - Graf Eulerian
======================================================================*/

void mp_7_graf_eulerian() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu graf eulerian:" << endl << endl;

        cout << "      1. Teorie" << endl << endl;

        cout << "      2. Verificare" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            eulerian_1_teorie();
            break;

        case 2:
            eulerian_2_verificare();
            break;

        case 3:

            break;
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";

        }
    } while(o != 3);
}

/*===========================*/
void eulerian_1_teorie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Teorie graf Eulerian - def" << endl;
    cout << "\n\n\
    Ciclu eulerian intr-un graf neorientat G = un ciclu elementar care contine\n\
    toate muchiile grafului.\n\n\
    Graf eulerian = un graf care contine un ciclu eulerian.";

    getch();
    getline(cin, buffer);
}


/*===========================*/
void eulerian_2_verificare() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare - program + executie" << endl;

    getch();
    getline(cin, buffer);
}

/*=====================================================================
  opt 8 - meniu PRINCIPAL - Aplicatii
======================================================================*/

void mp_8_aplicatii() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Aplicatii:" << endl << endl;

        cout << "      1. Problema 1" << endl << endl;

        cout << "      2. Problema 2" << endl << endl;

        cout << "      3. Problema 3" << endl << endl;

        cout << "      4. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(4);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            apl_1();
            break;

        case 2:
            apl_2();
            break;

        case 3:
            apl_3();
            break;

        case 4:

            break;
            cout << "Ati ales optiunea '4' -> revenire la meniul principal";

        }
    } while(o != 4);
}

/*===========================*/
void apl_1() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 1" << endl;

    getch();
    getline(cin, buffer);
}


/*===========================*/
void apl_2() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 2" << endl;

    getch();
    getline(cin, buffer);
}

/*===========================*/
void apl_3() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 3" << endl;

    getch();
    getline(cin, buffer);
}

/*===============================================================
   opt 9 - meniu principal - test
=================================================================*/
void mp_9_test() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu

        cout << "      1. Incepe Testul" << endl << endl;

        cout << "      2. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(2);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            test();
            break;

        case 2:

            break;
            cout << "Ati ales optiunea '2' -> revenire la meniul principal";

        }
    } while(o != 2);
}

/*===========================
    FUNCTIE PENTRU TEST GRAFURI
===========================*/
void test() {
    string buffer;
    string golire_buf;
    int punctaj = 0;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Test de verificare a cunostintelor" << endl;
    cout << "Alegeti raspunsul corect la urmatoarele intrebari, introducand cifre:\n\n";

    punctaj += intrebare_cu_un_raspuns(intrebare_1, 2);
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_un_raspuns(intrebare_2, 1);
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_un_raspuns(intrebare_3, 2);
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_un_raspuns(intrebare_4, 3);
    cout << endl <<"punctaj: " << punctaj << endl;

    getline(cin, golire_buf);


    punctaj += intrebare_cu_mm_raspunsuri(intrebare_5, "13");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_mm_raspunsuri(intrebare_6, "12");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_mm_raspunsuri(intrebare_7, "23");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_r_scurt(intrebare_8, "terminal");
    cout << endl << "punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_r_scurt(intrebare_9, "hamiltonian");
    cout << endl << "punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_r_scurt(intrebare_10, "conex");
    cout << endl << "punctaj: " << punctaj << endl;

    getch();
    getline(cin, buffer);
}


/*===================================================================
    Functii de analiza raspunsuri test
=====================================================================*/

int intrebare_cu_un_raspuns(char* intrebare, int raspuns_corect) {
    int punctaj = 0;
    int r; //raspunsul dat de la tastatura

    cout << intrebare;

    do {
        cin >> r;
        if(r != 1 && r != 2 && r != 3 && r != 4) {
            cout << "aceasta varianta  nu exista, introduceti 1, 2, 3 sau 4" << endl;
        } else if(r == raspuns_corect) {
            punctaj = 10;
        } else {
            //cout << "r = " << r << "; raspuns_corect = " << raspuns_corect;
        }

    } while(r != 1 && r != 2 && r != 3 && r != 4);

    cout << "apasati tasta enter pt a trece la intrebarea urmatoare" << endl;
    getch();

    return punctaj;
}

/*===========================*/
int intrebare_cu_r_scurt(char* intrebare, string raspuns_corect) {
    int punctaj = 0;
//transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    string r;

    cout << intrebare;

    getline(cin, r);
    transform(r.begin(), r.end(), r.begin(), ::tolower);

    //cout << "DBG: raspuns primit: " << r << endl;


    if(r == raspuns_corect){
        punctaj = 10;
    }

    cout << "apasati tasta enter pt a trece la intrebarea urmatoare" << endl;
    getch();

    return punctaj;
}

/*===========================*/
int verifica_raspuns_multiplu(string r_dat, string r_corect) {

//    cout << "DBG: *** in verifica_raspuns_multiplu" << endl;

//    cout << "DBG: r_dat: " << r_dat << "; lungime: " << r_dat.length() << endl;
//    cout << "DBG: r_corect: " << r_corect << "; lungime: " << r_corect.size() << endl;

    //return 0;

    int i, j, nr_rasp = 0, nr_r_ok = r_corect.size(), eroare, gasit = 0;

//    cout << "DBG: nr. raspunsuri corecte asteptate: " << nr_r_ok << endl;

    //verific data toate raspunsurile corecte se regasesc in raspunsul dat
    for(i = 0; i < r_corect.size(); i++) {
        //cout << "DBG: raspuns corect: " << r_corect[i] << endl;
        for(j = 0; j < r_dat.size(); j++) {
            if(r_corect[i] == r_dat[j]) {
                //cout << "DBG: gasit raspuns: " << r_corect[i] << endl;
                nr_rasp++;
            }
        }
    }

//    cout << "DBG: nr. raspunsuri bune gasite in raspunsul dat: " << nr_rasp << endl;

    if(nr_r_ok == nr_rasp){
        for(j = 0; j < r_dat.size(); j++) {
            if( r_dat[j] != '1' && r_dat[j] != '2' && r_dat[j] != '3' && r_dat[j] != '4' ) {
                //cout << "DBG: caracter de separare: " << r_dat[j] << endl;
                continue;
            } else {
                eroare = 1;
                for(i = 0; i <r_corect.size(); i++) {
                    if(r_dat[j] == r_corect[i]) {
                        //cout << "DBG: gasit raspuns: " << r_dat[j] << endl;
                        eroare = 0;
                        break; //am gasit raspunsul intre raspunsurile corecte, ies din bucla
                    }
                }
            }
            //cout << "DBG: eroare: " << eroare << endl;
            if(eroare == 1) {
                break; //ies din bucla mare. am gasit un raspuns invalid
            }
        }
    }

    gasit = !eroare; //daca n-am eroare inseamna ca raspunsul dat este corect

//    cout << "DBG: validat raspuns bun: " << gasit << endl;

    return gasit;

}

/*===========================*/
int intrebare_cu_mm_raspunsuri(char* intrebare, string raspuns_corect) {

    int punctaj = 0;
    string r; //raspunsul dat de la tastatura

//    cout << "DBG: *** in intrebare_cu_mm_raspunsuri:" << endl;

    cout << intrebare;

    getline(cin, r);

//    cout << "DBG: raspuns primit: " << r << endl;
//    cout << "DBG: raspuns corect: " << raspuns_corect << endl;

    if(verifica_raspuns_multiplu(r, raspuns_corect) == 1) {
        punctaj = 10;
    }

    cout << "apasati tasta enter pt a trece la intrebarea urmatoare" << endl;
    getch();

    return punctaj;

}

/*===================================================================
   MAIN
===================================================================*/
int main() {
    //int rulare_program = 1;

    afisare_nume();
    meniu_principal();

    return 0;
}

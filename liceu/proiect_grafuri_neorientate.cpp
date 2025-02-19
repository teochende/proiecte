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

int rasturnat_numar(int numar);
int verifica_duplicat(int v[], int n, int numar);

int verifica_matr_adiacenta(int a[][10], int n);
int matrice_patratica(int m, int n);

int parcurgere_pe_latime(int a[][10], int n, int varf);
int parcurgere_pe_latime_si_conexitate(int a[][10], int n, int varf);
void parcurgere_pe_adancime(int a[][10], int n, int varf);
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
void verificare_vf_izolat();

void m_gr_vf_3_vf_terminal();
void vf_terminal_1_def();
void vf_terminal_2_aplicatie();
void verificare_vf_terminal();


/*===================================================================*/
void mp_3_met_reprezentare();
void metode_repr_1_ls_adiacenta();
void ls_adiacenta_aplicatie();

void metode_repr_2_vect_muchii();
void vect_muchii_aplicatie();

void metode_repr_3_matr_adiacenta();
void matr_adiacenta_1_def();
void matr_adiacenta_2_aplicatie();
void prg_matr_adiacenta();


/*===================================================================*/
void mp_4_parcurgere();

void parcurgere_1_latime();
void program_latime();

void parcurgere_2_adancime();
void program_adancime();

/*===================================================================*/
void mp_5_conexitate();
void conexitate_1_def();
void conexitate_2_verif_graf_conex();
void graf_conex_program();

/*===================================================================*/
void mp_6_graf_hamiltonian();
void hamitonian_1_teorie();
void hamiltonian_2_verificare();
void program_hamiltonian();


/*===================================================================*/
void mp_7_graf_eulerian();
void eulerian_1_teorie();
void eulerian_2_verificare();
void program_eulerian();

/*===================================================================*/
void mp_8_aplicatii();

void apl_1();
void program_1();

void apl_2();
void program_2();

void apl_3();
void program_3();

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

/*===================================================================
   Functii ajutatoare pt probleme si aplicatii
=====================================================================*/

/*===========================*/
int verifica_matr_adiacenta(int a[][10], int n) {
    int i, j, ok_diag = 1, ok_el = 1;

    for(i = 1; i <= n; i++) {
        if(a[i][i] != 0) {
            ok_diag = 0;
            cout << "Diagonala principala nu are toate elementele 0: a[" << i << "][" << j << "]" << endl;
        }
    }

    if( ok_diag == 1 ) {
        for(i = 1; i <= n && ok_el == 1; i++) {
            for(j = 1; j <= n; j++) {
                if(a[i][j] != 0 && a[i][j] != 1) {
                    cout << "Element diferit de 1 sau 0: a[" << i << "][" << j << "] = " << a[i][j] << endl;
                    ok_el = 0;
                }
                if(a[i][j] != a[j][i]) {
                    cout << "Matrice nesimetrica: i = " << i << ", j = " << j << ", " << a[i][j] << " != " << a[j][i]<< endl;
                    ok_el = 0;
                }
            }
        }

        if( ok_el == 1 ) {
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}
/*===========================*/
int parcurgere_pe_latime(int a[][10], int n, int varf) {
    int viz[10]; // tin evidenta varfurilor vizitate
    int i, j;
    int ultim = 1;
    int coada[30]; // vom tine aici varfurile parcurse
    int k; // contor coada
    int p; // pointer verificare coada

    //initializare viz
    //fiecare element corespunde nodului cu acelasi index.
    //val = 0 daca nodul a fost vizitat si 0 daca nu a fost vizitat
    //incepem de la 0 - nici un elemant vizitat
    viz[0] = 9;
    for(i = 1; i <= n; i++) {
        viz[i] = 0; // nodul nu este vizitat
    }

    //Varf start
    k = 1;

    viz[varf] = 1;
    coada[k] = varf;
    p = 1; // pozitie curenta coada,
           //unde avem varful pentru care verificam adiacentele

    //de gasit conditie iesire din while
    while( p <= ultim ) {

        for(j = 1; j <= n; j++) {
            if( a[varf][j] == 1 && viz[j] == 0 ) {
                k = k + 1;
                coada[k] = j; // id-ul nodului
                viz[j] = 1;   // am vizitat nodul

                ultim++;  // mai am cel putin un varf de verificat
            }
        }
        p++;
        varf = coada[p];
    }

    cout << "Parcurgere in latime de la nodul: " << coada[1] << endl;
    //cout << "Index ultim element din coada: " << ultim << endl;
    for( i = 1; i <= ultim; i++ ) {
        cout << coada[i] << " ";
    }
    cout << endl;
/*
    if( n != ultim ) {
        cout << "GRAF-ul NU este conex!" << endl;
    } else {
        cout << "GRAF-ul este conex" << endl;
    }
*/

}

/*===========================*/
int parcurgere_pe_latime_si_conexitate(int a[][10], int n, int varf) {
    int viz[10]; // tin evidenta varfurilor vizitate
    int i, j;
    int ultim = 1;
    int coada[30]; // vom tine aici varfurile parcurse
    int k; // contor coada
    int p; // pointer verificare coada

    //initializare viz
    //fiecare element corespunde nodului cu acelasi index.
    //val = 0 daca nodul a fost vizitat si 0 daca nu a fost vizitat
    //incepem de la 0 - nici un elemant vizitat
    viz[0] = 9;
    for(i = 1; i <= n; i++) {
        viz[i] = 0; // nodul nu este vizitat
    }

    //Varf start
    k = 1;

    viz[varf] = 1;
    coada[k] = varf;
    p = 1; // pozitie curenta coada,
           //unde avem varful pentru care verificam adiacentele

    //de gasit conditie iesire din while
    while( p <= ultim ) {

        for(j = 1; j <= n; j++) {
            if( a[varf][j] == 1 && viz[j] == 0 ) {
                k = k + 1;
                coada[k] = j; // id-ul nodului
                viz[j] = 1;   // am vizitat nodul

                ultim++;  // mai am cel putin un varf de verificat
            }
        }
        p++;
        varf = coada[p];
    }
/*
    cout << "Parcurgere in latime de la nodul: " << coada[1] << endl;
    //cout << "Index ultim element din coada: " << ultim << endl;
    for( i = 1; i <= ultim; i++ ) {
        cout << coada[i] << " ";
    }
    cout << endl;
*/

    return ultim;
/*
    if( n != ultim ) {
        cout << "GRAF-ul NU este conex!" << endl;
    } else {
        cout << "GRAF-ul este conex" << endl;
    }
*/

}

/*===========================*/
void parcurgere_pe_adancime(int a[][10], int n, int varf) {
    int viz[10]; // tin evidenta varfurilor vizitate
    int i, j;

    int stiva[20];
    int gasit;

    int coada[30]; // vom tine aici varfurile parcurse
    int k; // contor coada
    int p; // pointer verificare coada

    //initializare viz
    //fiecare element corespunde nodului cu acelasi index.
    //val = 0 daca nodul a fost vizitat si 0 daca nu a fost vizitat
    //incepem de la 0 - nici un elemant vizitat
    viz[0] = 9;
    for(i = 1; i <= n; i++) {
        viz[i] = 0; // nodul nu este vizitat
    }

    //Varf start coada
    k = 1;

    viz[varf] = 1;
    coada[k] = varf;
    p = 1; // pozitie curenta stiva,
    stiva[p] = varf;
    //de gasit conditie iesire din while
    while( p > 0 ) {
        gasit = 0;
        for(j = 1; j <= n && gasit == 0; j++) {
            if( a[varf][j] == 1 && viz[j] == 0 ) {
                gasit = 1;
                varf = j;
            }
        }

        if( gasit == 1 ) {
            k = k + 1;
            coada[k] = varf; //salvare pt afisare
            viz[varf] = 1;   //marchez vizitate
            p++;
            stiva[p] = varf;
        } else {
            p--; //
        }
    }

    cout << "Parcurgere pe adancime de la nodul: " << coada[1] << endl;
    for( i = 1; i <= k; i++ ) {
        cout << coada[i] << " ";
    }
    cout << endl;
}

/*============================*/
int matrice_patratica(int m, int n) {
    if(m == n) {
        return 1;
    } else return 0;
}

/*===========================*/
int rasturnat_numar(int numar) {
    int invers = 0;

    while(numar > 0) {
        invers = invers * 10 + numar%10;
        numar = numar / 10;
    }
    return invers;
}

/*===========================*/
int verifica_duplicat(int v[], int n, int numar) {
    int duplicat = 0;
    for(int i = 0; i < n && duplicat == 0;  i++) {
        if(v[i] == numar || v[i] == rasturnat_numar(numar)) {
            duplicat = 1;
        }
    }
    return duplicat;
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
    cout << " program:\n\
    for(i = 1; i <= n; i++) {\n\
        grad_vf = 0;\n\
        for(j = 1; j <= n; j++) {\n\
            grad_vf = grad_vf + a[i][j];\n\
        }\n\
        if(grad_vf == 0) {\n\
            nr_vf_izolate++;\n\
            cout << 'varf izolat: ' << i << endl;\n\
        }\n\
    }\n\
    if(nr_vf_izolate == 0) cout << 'graful nu contine varfuri izolate'" << endl;
    cout << endl << "executie program: " << endl;

    verificare_vf_izolat();

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt vf_izolat
=================================================*/
void verificare_vf_izolat() {
    int a[10][10];
    int v[45], i, j, n, k = 0, nr_vf_izolate = 0, grad_vf;
    cout << "nr varfuri: "; cin >> n;
    cout << "introduceti matricea de adiacenta a grafului: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1) {
        for(i = 1; i <= n; i++) {
            grad_vf = 0;
            for(j = 1; j <= n; j++) {
                grad_vf = grad_vf + a[i][j];
            }
            if(grad_vf == 0) {
                nr_vf_izolate++;
                cout << "varf izolat: " << i << endl;
            }
        }
        if(nr_vf_izolate == 0) cout << "graful nu contine varfuri izolate";
    } else cout << "matricea nu poate fi matrice de adiacenta";
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

    cout << " program:\n\
    for(i = 1; i <= n; i++) {\n\
        grad_vf = 0;\n\
        for(j = 1; j <= n; j++) {\n\
            grad_vf = grad_vf + a[i][j];\n\
        }\n\
        if(grad_vf == 1) {\n\
            nr_vf_terminale++;\n\
            cout << 'varf terminal: ' << i << endl;\n\
        }\n\
    }\n\
    if(nr_vf_izolate == 0) cout << 'graful nu contine varfuri terminale'" << endl;
    cout << endl << "executie program: " << endl;

    verificare_vf_terminal();

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt vf_terminal
=================================================*/
void verificare_vf_terminal() {
    int a[10][10];
    int v[45], i, j, n, k = 0, nr_vf_terminale = 0, grad_vf;
    cout << "nr varfuri: "; cin >> n;
    cout << "introduceti matricea de adiacenta a grafului: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1) {
        for(i = 1; i <= n; i++) {
            grad_vf = 0;
            for(j = 1; j <= n; j++) {
                grad_vf = grad_vf + a[i][j];
            }
            if(grad_vf == 1) {
                nr_vf_terminale++;
                cout << "varf terminal: " << i << endl;
            }
        }
        if(nr_vf_terminale == 0) cout << "graful nu contine varfuri terminale";
    } else cout << "matricea nu poate fi matrice de adiacenta";
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
    cu varfurile adiacente fiecarui varf din graf." << endl << endl;

    cout << " program:\n\
    for(i = 1; i <= n; i++) {\n\
        cout << i << ': ';\n\
        for(j = 0; j <= n; j++) {\n\
            if(matr[i][j] == 1) cout << j << " ";\n\
        }\n\
        cout << endl;\n\
    }";

    cout << endl << endl << "executie program: " << endl;
    ls_adiacenta_aplicatie();


    getch();
    getline(cin, buffer);
}

/*===============================================
    Program afisare lista adiacenta
=================================================*/
void ls_adiacenta_aplicatie() {
    int n, m, i, j, vf1, vf2, matr[100][100];

    cout << "numar varfuri: "; cin >> n;
    do{
        cout << "numar muchii: ";
        cin >> m;
    } while (m > n*(n-1)/2);

    for(i = 1; i <= n; i ++) {
        for(j = 1; j <= n; j++) {
            matr[i][j] = 0;
        }
    }
    for(i = 0; i < m; i++) {
        cout << "muchie: " << endl;
        do{
            cout << "vf1: "; cin >> vf1;
            cout << "vf2: "; cin >> vf2;
            if(vf1 > n || vf2 > n || vf1 == vf2 || vf1 > vf2) cout << "nu pot fi varfuri; dati alte valoari: " << endl;
        } while(vf1 > n || vf2 > n || vf1 == vf2 || vf1 > vf2);

        matr[vf1][vf2] = 1;
        matr[vf2][vf1] = 1;
        cout << endl;
    }

    cout << endl << endl << "lista de adiacenta: " << endl;
    for(i = 1; i <= n; i++) {
        cout << i << ": ";
        for(j = 0; j <= n; j++) {
            if(matr[i][j] == 1) cout << j << " ";
        }
        cout << endl;
    }
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

    cout << endl << endl << "program:\n\
    struct muchii_graf {\n\
        int vf1, vf2;\n\
    };\n\
    muchii_graf muchii[100];\n\
    for(i = 0; i < m; i++) {\n\
        cout << 'muchie: ' << endl;\n\
        cin >> muchii[i].vf1;\n\
        cin >> muchii[i].vf2;\n\
    }\n\
    cout << 'vectorul muchiilor: ' << endl;\n\
    for(i = 0; i < m; i++) {\n\
        cout <<'(' << muchii[i].vf1 << ', ' << muchii[i].vf2 << ')' << '  ';\n\
    }";

    cout << endl << endl << "executie program: " << endl;
    vect_muchii_aplicatie();

    getch();
    getline(cin, buffer);
}

/*===============================================
    Program afisare vectorul muchiilor
=================================================*/
void vect_muchii_aplicatie() {
    struct muchii_graf {
        int vf1, vf2;
    };
    muchii_graf muchii[100];

    int n, m, i;

    cout << "nuamr varfuri: "; cin >> n;

    do{
        cout << "numar muchii: ";
        cin >> m;
    } while (m > n*(n-1)/2);

    for(i = 0; i < m; i++) {
        cout << "muchie: " << endl;
        do{
            cout << "vf1: "; cin >> muchii[i].vf1;
            cout << "vf2: "; cin >> muchii[i].vf2;
            if(muchii[i].vf1 > n || muchii[i].vf2 > n || muchii[i].vf1 == muchii[i].vf2 || muchii[i].vf1 > muchii[i].vf2) cout << "nu pot fi varfuri; dati alte valoari: " << endl;
        } while(muchii[i].vf1 > n || muchii[i].vf2 > n || muchii[i].vf1 == muchii[i].vf2 || muchii[i].vf1 > muchii[i].vf2);
    }

    cout << "vectorul muchiilor: " << endl;
    for(i = 0; i < m; i++) {
        cout <<"(" << muchii[i].vf1 << ", " << muchii[i].vf2 << ")" << "  ";
    }
}
/*===================================================================*/
// opt 3 meniu met reprezentare - matrice de adiacenta - care deschide alt meniu
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

    cout << endl << "\
    program: \n\
    int matrice_patratica(int m, int n) {\n\
        if(m == n) {\n\
            return 1;\n\
        } else return 0;\n\
    }\n\
    int verifica_matr_adiacenta(int a[][10], int n) {\n\
        int i, j, ok_diag = 0, ok_el;\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 1; j <= n; j++){\n\
                if(i == j && a[i][j] == 0) {\n\
                    ok_diag = 1;\n\
                } else ok_diag = 0;\n\
            }\n\
        }\n\
        if(ok_diag == 1) {\n\
            for(i = 1; i <= n; i++) {\n\
                for(j = 1; j <= n; j++) {\n\
                    if(a[i][j] == a[j][i]) {\n\
                        ok_el = 1;\n\
                    } else ok_el = 0;\n\
                }\n\
            }\n\
            if(ok_el == 1) return 1;\n\
            else return 0;\n\
        } else return 0;\n\
    }\n\
    int main() {\n\
        int n, m, a[10][10], i, j, ok_diag = 0, ok_el;\n\
        cout << 'n: '; cin >> n;\n\
        cout << 'm: '; cin >> m;\n\
        if(matrice_patratica(m, n) == 1) {\n\
            cout << 'citire matrice: ' << endl;\n\
            for(i = 1; i <= n; i++) {\n\
                for(j = 1; j <= n; j++) {\n\
                    cin >> a[i][j];\n\
                }\n\
                cout << endl;\n\
            }\n\
            if(verifica_matr_adiacenta(a, n) == 1) cout << 'este matrice de adiacenta';\n\
            else cout << 'nu este matrice de adiacenta';\n\
        } else cout << 'nu este matrice de adiacenta';\n\
        return 0;\n\
    }";
    cout << endl << endl << "executie: " << endl;

    prg_matr_adiacenta();

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt verificare matrice adiacenta
=================================================*/
void prg_matr_adiacenta() {
    int n, m, a[10][10], i, j, ok_diag = 0, ok_el;
    cout << "n: "; cin >> n;
    cout << "m: "; cin >> m;

    if(matrice_patratica(m, n) == 1) {
        cout << "citire matrice: " << endl;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
            cout << endl;
        }
        if(verifica_matr_adiacenta(a, n) == 1) cout << "este matrice de adiacenta";
        else cout << "nu este matrice de adiacenta";
    } else cout << "nu este matrice de adiacenta";
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

        cout << "      2. In adancime" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            parcurgere_1_latime();
            break;

        case 2:
            parcurgere_2_adancime();
            break;

        case 3:

            break;
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";

        }
    } while(o != 3);
}

/*===============================================*/
void parcurgere_1_latime() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "In latime" << endl;

    cout << "program:\n\
    for(i = 1; i <= n; i++) {\n\
        viz[i] = 0;\n\
    }\n\
    k = 1;\n\
    viz[varf] = 1;\n\
    coada[k] = varf;\n\
    p = 1;\n\
    while( p <= ultim ) {\n\
        for(j = 1; j <= n; j++) {\n\
            if( a[varf][j] == 1 && viz[j] == 0 ) {\n\
                k = k + 1;\n\
                coada[k] = j;\n\
                viz[j] = 1;\n\
                ultim++;\n\
            }\n\
        }\n\
        p++;\n\
        varf = coada[p];\n\
    }\n\
    cout << 'Parcurgere in latime de la nodul: ' << coada[1] << endl;\n\
    for( i = 1; i <= ultim; i++ ) {\n\
        cout << coada[i] << ' ';\n\
    }";

    cout << endl << endl << "executie program: " << endl;

    program_latime();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void program_latime() {
    int n, i, j, a[10][10], varf;
    cout<<"nr varfuri: "; cin>>n;

    cout << "citire matrice: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1){
        cout << "varf de la care parcurgem: "; cin >> varf;
        parcurgere_pe_latime(a, n, varf);
    } else cout << "nu este matrice de adiacenta";
}

/*===============================================*/
void parcurgere_2_adancime() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "In adancime" << endl;

    cout << "program:\n\
    int viz[10];\n\
    int i, j;\n\
    int stiva[20];\n\
    int gasit;\n\
    int coada[30];\n\
    int k;\n\
    int p;\n\
    viz[0] = 9;\n\
    for(i = 1; i <= n; i++) {\n\
        viz[i] = 0;\n\
    }\n\
    k = 1;\n\
    viz[varf] = 1;\n\
    coada[k] = varf;\n\
    p = 1;\n\
    stiva[p] = varf;\n\
    while( p > 0 ) {\n\
        gasit = 0;\n\
        for(j = 1; j <= n && gasit == 0; j++) {\n\
            if( a[varf][j] == 1 && viz[j] == 0 ) {\n\
                gasit = 1;\n\
                varf = j;\n\
            }\n\
        }\n\
        if( gasit == 1 ) {\n\
            k = k + 1;\n\
            coada[k] = varf;\n\
            viz[varf] = 1;\n\
            p++;\n\
            stiva[p] = varf;\n\
        } else {\n\
            p--;\n\
        }\n\
    }\n\
    cout << 'Parcurgere pe adancime de la nodul: ' << coada[1] << endl;\n\
    cout << 'Index ultim element din coada: ' << k << endl;\n\
    for( i = 1; i <= k; i++ ) {\n\
        cout << coada[i] << ' ';\n\
    }\n\
    cout << endl;";

    cout << endl << endl << "executie program: " << endl;
    program_adancime();

    getch();
    getline(cin, buffer);
}
/*===========================*/

void program_adancime() {
    int n, i, j, a[10][10], varf;
    cout<<"nr varfuri: "; cin>>n;

    cout << "citire matrice: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1){
        cout << "varf de la care parcurgem: "; cin >> varf;
        parcurgere_pe_adancime(a, n, varf);
    } else cout << "nu este matrice de adiacenta";
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


/*===============================================*/
void conexitate_2_verif_graf_conex() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare graf conex" << endl;

    cout << "program:\n\
    for(i = 1; i <= n; i++) {\n\
        viz[i] = 0;\n\
    }\n\
    k = 1;\n\
    viz[varf] = 1;\n\
    coada[k] = varf;\n\
    p = 1;\n\
    while( p <= ultim ) {\n\
        for(j = 1; j <= n; j++) {\n\
            if( a[varf][j] == 1 && viz[j] == 0 ) {\n\
                k = k + 1;\n\
                coada[k] = j;\n\
                viz[j] = 1;\n\
                ultim++;\n\
            }\n\
        }\n\
        p++;\n\
        varf = coada[p];\n\
    }\n\
    cout << 'Parcurgere in latime de la nodul: ' << coada[1] << endl;\n\
    for( i = 1; i <= ultim; i++ ) {\n\
        cout << coada[i] << ' ';\n\
    if( n != ultim ) {\n\
        cout << 'GRAF-ul NU este conex!' << endl;\n\
    } else\n\
        cout << 'GRAF-ul este conex' << endl;\n\
    }";

    cout << endl << endl << "executie program: " << endl;

    graf_conex_program();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void graf_conex_program() {
    int n, i, j, a[10][10], varf;
    cout<<"nr varfuri: "; cin>>n;

    cout << "citire matrice: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1){
        //cout << "varf de la care parcurgem: "; cin >> varf;
        varf = 1;
        if(parcurgere_pe_latime_si_conexitate(a, n, varf) != n){
            cout << "GRAFUL NU este conex!" << endl;
        } else cout << "GRAFUL este conex" << endl;
    } else cout << "nu este matrice de adiacenta";
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


/*===============================================*/
void hamiltonian_2_verificare() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare graf Hamiltonian" << endl;

    cout << endl << "program:\n\
    for(i = 1; i <= n; i++){\n\
        grade_vf[i] = 0;\n\
    }\n\
    for(i = 1; i <= n; i++){\n\
        for(j = 1; j <= n; j++) {\n\
            if(a[i][j] == 1){\n\
                grade_vf[i]++;\n\
            }\n\
        }\n\
    }\n\
    if(n >= 3) {\n\
        for(i = 1; i <= n && ok == 1; i++) {\n\
            if(grade_vf[i] <= n/2) ok = 0;\n\
        }\n\
        if(ok == 1) cout << 'GRAF HAMILTONIAN';\n\
        else cout << 'Graful NU este hamiltonian';\n\
    } else cout << 'Graful NU este hamiltonian';";

    cout << endl << endl << "executie program: " << endl;
    program_hamiltonian();

    getch();
    getline(cin, buffer);
}
/*===========================*/
void program_hamiltonian() {
    int a[10][10], n, i, j, grade_vf[10], ok = 1;

    cout<<"nr varfuri: "; cin >> n;

    cout << "citire matrice: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1){
        for(i = 1; i <= n; i++){
            grade_vf[i] = 0;
        }

        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++) {
                if(a[i][j] == 1){
                    grade_vf[i]++;
                }
            }
        }

        if(n >= 3) {
            for(i = 1; i <= n && ok == 1; i++) {
                if(grade_vf[i] >= n/2) ok = 1;
                else ok = 0;
            }

            if(ok == 1) cout << "GRAF HAMILTONIAN";
            else cout << "Graful NU este hamiltonian";
        } else cout << "Graful NU este hamiltonian";

    } else cout << "nu este matrice de adiacenta";
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


/*===============================================*/
void eulerian_2_verificare() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Verificare garf eulerian" << endl;

    cout << endl << "program: \n\
    for(i = 1; i <= n; i++){\n\
        grade_vf[i] = 0;\n\
    }\n\
    for(i = 1; i <= n; i++) {\n\
        for(j = 1; j <= n; j++) {\nb\
            if(a[i][j] == 1){\n\
                grade_vf[i]++;\n\
            }\n\
        }\n\
    }\n\
    for(i = 1; i <= n && ok == 1; i++) {\n\
        if(grade_vf[i] % 2 == 0)\n\
            ok = 1;\n\
        else\n\
            ok = 0;\n\
    }\n\
    if(ok == 1)\n\
        cout << 'GRAF EULERAIN';\n\
    else\n\
        cout << 'Graful NU este EULERAIN'";

    cout << endl << endl << "executie program: " << endl;
    program_eulerian();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void program_eulerian() {
    int a[10][10], n, i, j, grade_vf[10], ok = 1, varf;

    cout<<"nr varfuri: "; cin >> n;

    cout << "citire matrice: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1) {
        //cout << "IF1";
        //cout << n << endl;
        if(parcurgere_pe_latime_si_conexitate( a, n, 1) == n) {
            //cout << "IF2";

            for(i = 1; i <= n; i++){
                grade_vf[i] = 0;
            }

            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    if(a[i][j] == 1){
                        grade_vf[i]++;
                    }
                }
            }

            for(i = 1; i <= n && ok == 1; i++) {
                if(grade_vf[i] % 2 == 0)
                    ok = 1;
                else
                    ok = 0;
            }

            if(ok == 1)
                cout << "GRAF EULERAIN";
            else
                cout << "Graful NU este EULERAIN";

        } else
            cout << "Graful NU este EULERIAN";

    } else {
        //cout << "AICI" << endl;
        cout << "nu este matrice de adiacenta";
    }
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

/*===============================================*/
void apl_1() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 1" << endl;
    cout << "\
    Se defineste o muchie a unui graf neorientat ca o inregistrare cu trei campuri: cele doua varfuri\n\
    extremitati si un cost asociat muchiei (un numar intreg). Definim un graf neorientat ca un vector de\n\
    muchii. Fiind dat vectorul de muchii al unui graf neorientat G=(X, U) cu m muchii si n varfuri, sa se\n\
    afiseze muchia (muchiile) de cost minim." << endl << endl;

    cout << "program:\n\
    struct muchii_graf {\n\
        int vf1, vf2, cost;\n\
    };\n\
    muchii_graf muchie;\n\
    int n, m, i, v_vf1[10], v_vf2[10], v_cost[10], mini;\n\
    cout << 'nuamr varfuri: '; cin >> n;\n\
    do{\n\
        cout << 'numar muchii: ';\n\
        cin >> m;\n\
    } while (m > n*(n-1)/2);\n\
    for(i = 0; i < m; i++){\n\
        cout << 'muchie cu vf1, vf2 si cost: ' << endl;\n\
        do{\n\
            cout << 'vf1: '; cin >> muchie.vf1;\n\
            cout << 'vf2: '; cin >> muchie.vf2;\n\
            if(muchie.vf1 > n || muchie.vf2 > n || muchie.vf1 == muchie.vf2 || muchie.vf1 > muchie.vf2) cout << 'nu pot fi varfuri; dati alte valoari: ' << endl;\n\
        } while(muchie.vf1 > n || muchie.vf2 > n || muchie.vf1 == muchie.vf2 || muchie.vf1 >muchie.vf2);\n\
        v_vf1[i] = muchie.vf1;\n\
        v_vf2[i] = muchie.vf2;\n\
        cin >> muchie.cost;`\n\
        v_cost[i] = muchie.cost;\n\
    }\n\
    mini = v_cost[0];\n\
    for(i = 0; i < m; i++) {\n\
        if(mini > v_cost[i]) {\n\
            mini = v_cost[i];\n\
        }\n\
    }\n\
    for(i = 0; i < m; i++) {\n\
        if(v_cost[i] == mini) {\n\
            cout << 'muchie cu cost minim:   ' << '(' << v_vf1[i] << ', ' << v_vf2[i] << ')' << endl;\n\
        }\n\
    }";

    cout << endl << endl << "executie program: " << endl;
    program_1();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void program_1() {
    struct muchii_graf {
        int vf1, vf2, cost;
    };
    muchii_graf muchie;

    int n, m, i, v_vf1[10], v_vf2[10], v_cost[10], mini;

    cout << "nuamr varfuri: "; cin >> n;

    do{
        cout << "numar muchii: ";
        cin >> m;
    } while (m > n*(n-1)/2);

    for(i = 0; i < m; i++){
        cout << "muchie cu vf1, vf2 si cost: " << endl;
        do{
            cout << "vf1: "; cin >> muchie.vf1;
            cout << "vf2: "; cin >> muchie.vf2;
            if(muchie.vf1 > n || muchie.vf2 > n || muchie.vf1 == muchie.vf2 || muchie.vf1 > muchie.vf2) cout << "nu pot fi varfuri; dati alte valoari: " << endl;
        } while(muchie.vf1 > n || muchie.vf2 > n || muchie.vf1 == muchie.vf2 || muchie.vf1 >muchie.vf2);

        v_vf1[i] = muchie.vf1;
        v_vf2[i] = muchie.vf2;

        cin >> muchie.cost;
        v_cost[i] = muchie.cost;
    }

    mini = v_cost[0];
    for(i = 0; i < m; i++) {
        if(mini > v_cost[i]) {
            mini = v_cost[i];
        }
    }

    for(i = 0; i < m; i++) {
        if(v_cost[i] == mini) {
            cout << "muchie cu cost minim:   " << "(" << v_vf1[i] << ", " << v_vf2[i] << ")" << endl;
        }
    }
}

/*===============================================*/
void apl_2() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 2" << endl;
    cout << "\
    Pentru un grup format din n persoane, se cunosc relatiile de prietenie. Se defineste o relatie de\n\
    prietenie sub forma 'x este prieten cu y'. Sa se afiseze persoana /persoanele din grup care are/au\n\
    cei mai multi prieteni.";

    cout << endl << " program:\n\
        int a[11][11], d[11];\n\
        int n, i, j, maxi;\n\
        char rasp;\n\
        cout << 'nr persoane grup: '; cin >> n;\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = i + 1; j <= n; j++) {\n\
                cout << i << ' este prieten cu ' << j << '? d/n ';\n\
                cin >> rasp;\n\
                if( rasp == 'd' || rasp == 'D') {\n\
                    a[i][j] = 1;\n\
                    a[j][i] = 1;\n\
                } else {\n\
                    if(rasp != 'n' && rasp != 'N') {\n\
                        cout << endl <<'raspunsul nu e valid';\n\
                    }\n\
                }\n\
            }\n\
        }\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 1; j <= n; j++) {\n\
                d[i] = d[i] + a[i][j];\n\
            }\n\
        }\n\
        maxi = d[1];\n\
        for(i = 2; i <= n; i++) {\n\
            if(maxi < d[i]) {\n\
                maxi = d[i];\n\
            }\n\
        }\n\
        for(i = 1; i <= n; i++) {\n\
            if( d[i] == maxi ) cout << endl <<  'cei mai multi prieteni ii are ----> ' <<  i << ' ';\n\
    }";

    cout << endl << endl << "executie program: " << endl;
    program_2();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void program_2() {
    int a[11][11], d[11];
    int n, i, j, maxi;
    char rasp;

    cout << "nr persoane grup: "; cin >> n;

    // fromez matricea de adiacenta
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            cout << i << " este prieten cu " << j << "? d/n ";
            cin >> rasp;
            if( rasp == 'd' || rasp == 'D') {
                a[i][j] = 1;
                a[j][i] = 1;
            } else {
                if(rasp != 'n' && rasp != 'N') {
                    cout << endl << "raspunsul nu e valid" << endl;
                }
            }
        }
    }

    // determinarea gradului varfuri
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            d[i] = d[i] + a[i][j];
        }
    }
    maxi = d[1];

    for(i = 2; i <= n; i++) {
        if(maxi < d[i]) {
            maxi = d[i];
        }
    }
    for(i = 1; i <= n; i++) {
        if( d[i] == maxi ) cout << endl <<  "cei mai multi prieteni ii are ----> " <<  i << " ";
    }
}

/*===============================================*/
void apl_3() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 3" << endl;
    cout << "\
    Se citeste de la tastatura matricea de adiacenta a unui graf neorientat cu n varfuri.\n\
    Sa se scrie muchiile grafului (pe fiecare rand se vor scrie extremitatile unei muchii\n\
    separate prin spatiu).";

    cout << endl << "program:\n\
    int a[10][10];\n\
    int v[45], i, j, n, k = 0;\n\
    cout << 'n: '; cin >> n;\n\
    cout << ' introduceti elemente matrice adiacenta luate pe linie: ' << endl;\n\
    for(i = 1; i <= n; i++) {\n\
        for(j = 1; j <= n; j++) {\n\
            cin >> a[i][j];\n\
        }\n\
        cout << endl;\n\
    }\n\
    if(verifica_matr_adiacenta(a, n) == 1) {\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 1; j <= n; j++) {\n\
                if(a[i][j] != 0) {\n\
                    if(verifica_duplicat(v, k, i*10 + j)) {\n\
                        cout << 'Muchia: ' << i << ' ' << j << ' deja adaugata' << endl;\n\
                    } else {\n\
                        v[k] = i * 10 + j;\n\
                        cout << i << " " << j << endl;\n\
                    }\n\
                    k++;\n\
                }\n\
            }\n\
        }\n\
    } else cout << 'matricea nu poate fi matrice de adiacenta';";


    cout << endl << endl << "executie program: " << endl;
    program_3();

    getch();
    getline(cin, buffer);
}

/*===========================*/
void program_3() {
    int a[10][10];
    int v[45], i, j, n, k = 0;


    cout << "n: "; cin >> n;
    cout << " introduceti elemente matrice adiacenta luate pe linie: " << endl;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cout << endl;
    }

    if(verifica_matr_adiacenta(a, n) == 1) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                //cout << a[i][j] << " ";

                if(a[i][j] != 0) {
                    //cout << " ++++++++ " << i << " " << j << endl;

                    if(verifica_duplicat(v, k, i*10 + j)) {
                        //cout << "Muchia: " << i << " " << j << " deja adaugata" << endl;
                    } else {
                        v[k] = i * 10 + j;
                        cout << i << " " << j << endl;
                    }
                    k++;
                }
            }
            //cout << endl;
        }
    } else cout << "matricea nu poate fi matrice de adiacenta";
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

/*=====================================
    FUNCTIE PENTRU TEST GRAFURI
=======================================*/
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

    cout << endl << endl << "Punctaj final: " << punctaj << " din 100";

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

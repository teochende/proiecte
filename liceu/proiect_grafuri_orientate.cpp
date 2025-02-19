#include <iostream>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> //pt system("cls")
#include <string.h>
#include <bits/stdc++.h> // transform function - transforare sir din cartere mari in mici

using namespace std;
// structura arc necesara pentru lucrul pe vectorul arcelor
struct arc {
    int x;
    int y;
    int cost;
};

arc v_arce[20];

//declararea functiilor
/*===================================================================*/
void afisare_nume();
int citeste_optiune_meniu(int max_optiuni);

// functii ajutatoare
void construire_matr_adiacenta(int a[][20], arc v_arce[20], int n, int m);
void grade_ext( int vect_d_plus[], int a[][20], int n);
void grade_int( int vect_d_minus[], int a[][20], int n);


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
int matrice_patratica(int m, int n);
void construire_matr_adiacenta(int a[][20], arc v_arce[20], int n, int m);
int verifica_matr_adiacenta(int a[][10], int n);
void construire_matr_adiacenta_apl_1(int a[][20], arc v_arce[20], int n, int m);
void drumuri(int a[][20], int d[][20], int m, int n);
void construire_matr_incidenta(int matr_incid[][20], arc v_arce[20], int n, int m);
int graf_tare_conex(int d[20][20], int m, int n);

/*===================================================================*/
void mp_3_met_reprezentare();

void metode_repr_1_ls_adiacenta();
void ls_ad_program();
void apl_ls_adiacenta();

void metode_repr_2_vect_muchii();
void v_muchii_program();
void apl_vect_muchii();

void metode_repr_3_matr_adiacenta();
void matr_adiacenta_1_def();
void matr_adiacenta_2_aplicatie();
void apl_matr_adiacenta();

void metode_repr_4_matr_incidenta();
void matr_incidenta_1_def();
void matr_incidenta_2_aplicatie();
void matr_incidenta_program();

void metode_repr_5_matr_drumuri();
void matr_drumuri_1_def();
void matr_drumuri_2_aplicatie();
void apl_matr_drumuri();

void metode_repr_6_multime_predecesori_succesori();
void multime_pred_succ_1_def();
void multime_pred_succ_2_aplicatie();
void prog_succesori_predecesori();

void metode_repr_7_multime_arce_xy_yx();
void multime_arce_xy_yx_1_def();
void multime_arce_xy_yx_2_aplicatie();
void m_arce_prg();

/*===================================================================*/
void mp_4_conexitate();
void m_conx_def_grf_conx();
void m_conx_componenta_conx();

/*===================================================================*/
void mp_5_tare_conexitate();
void tare_conx_def();
void tare_conx_program();
void apl_graf_tare_conex();

/*===================================================================*/
void mp_6_aplicatii();

void apl_1();
void program_apl_1();

void apl_2();
void program_apl_2();

void apl_3();
void program_apl_3();

/*===================================================================*/
void mp_7_test();
void test();
int intrebare_cu_un_raspuns(char* intrebare, int raspuns_corect);
int intrebare_cu_r_scurt(char* intrebare, string raspuns_corect);
int verifica_raspuns_multiplu(string r_dat, string r_corect);
int intrebare_cu_mm_raspunsuri(char* intrebare, string raspuns_corect);

//Intrebari pentru test - optiunea 7 - de schimbat intrebarile
/*===================================================================
 Intrebari cu un singr raspuns
 ====================================================================*/

char intrebare_1[] = "\
\nIntrebarea 1. Intr-un graf orientat cu n noduri si m arce, matricea de incidenta contine:\n\
1) m linii si n coloane\n\
2) n linii si m coloane\n\
3) m linii si m coloane\n\
4) n linii si n coloane\n\
 \n\
Dati raspunsul: "; // r corect: 2

char intrebare_2[] = "\
\nIntrebarea 2. Intr-un graf orientat, un varf x este izolat daca:\n\
1) d+(x) = 0;\n\
2) d-(x) = 0\n\
3) d+(x) = d-(x)\n\
4) d+(x) = d-(x) = 0\n\
 \n\
Dati raspunsul: "; // r corect: 4

char intrebare_3[] = "\
\nIntrebarea 3. Precizati care din urmatoarele afirmatii caracterizeaza\n\
matricea de adiacenta asociata unui graf orientat\n\
1) matricea este este patratica\n\
2) este simetrica fata de diagonala principala\n\
3) matricea este simetrica fata de diagonala secundara\n\
4) exista cel putin o coloana a matricei care are toate componentele nule\n\
 \n\
Dati raspunsul: "; // r corect: 1

char intrebare_4[] = "\
\nIntrebarea 4. Care dintre urmatoarele afirmatii sunt corecte? \n\
1) intr-un graf orientat o muchie poate fi adiacenta cu un varf.\n\
2) intr-un graf orientat doua muchii pot fi adiacente.\n\
3) intr-un graf orientat o muchie poate fi incidenta cu un varf. \n\
4) intr-un graf orientat două varfuri pot fi incidente.\n\
 \n\
Dati raspunsul: "; // r corect: 3

/*===================================================================
 Intrebari cu mai multe raspunsuri
 ====================================================================*/

char intrebare_5[] = "\
\nIntrebarea 5. Un graf orientat cu n varfuri si m arce are: \n\
1) suma gradelor interioare = m\n\
2) suma gradelor exterioare = suma gradelor interioare\n\
3) niciun raspuns corect\n\
4) suma gardelor interioare = suma gradelor exterioare\n\
\n\
Dati raspunsurile: "; // r corect: 1, 2, 4

char intrebare_6[] = "\
\nIntrebarea 6. Un graf neorientat este eulerian daca: \n\
1) este conex\n\
2) contine un circuit ce trece prin toate arcele\n\
3) are varf izolat\n\
4) nu contine circuite\n\
\n\
Dati raspunsurile: "; // r corect: 1, 2

char intrebare_7[] = "\
\nIntrebarea 7. Cum se poate parcurge graful: \n\
1) cu matricea de adiacenta\n\
2) in adancime\n\
3) in latime\n\
4) cu matricea de incidenta\n\
\n\
Dati raspunsurile: "; // r corect: 2, 3

/*===================================================================
 Intrebari cu raspuns scurt
 ====================================================================*/

char intrebare_8 [] = "\
\nIntrebare 8. Varful cu d+(x) = d-(x) = 0 se numeste varf:\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // izolat

char intrebare_9 [] = "\
\nIntrebare 9. Cum se numeste drumul care contine toate varfurile sale fara sa le repete?\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // hamiltonian

char intrebare_10 [] = "\
\nIntrebare 10. Graful in care oricare doua varfuri pot fi extremitatile unui lant se numeste?\n\
Raspundeti cu un singur cuvant fara a folosi spatiul: "; // conex

/*===================================================================
    Citire nume de la tastatura
=====================================================================*/
void afisare_nume() {

    string buffer; //variabila necesara pentru a putea utilizat getline
    //               - in acest caz doar astept enter


    //stergere ecran - foloseste functie din strlib.h
    system("cls");
    cout << "Chende-Roman Teodora" << endl;
    cout << "Cl: XI C" << endl;
    cout << "Proiect grafuri orientate. Semestrul 2.";

    getline(cin, buffer);

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
/*===============================================*/
//construire matrice adiacenta pe baza vectorului muchiilor

void construire_matr_adiacenta(int a[][20], arc v_arce[20], int n, int m) {
    int i, j;
    for(i = 1; i <= m; i++) {
        cout << "muchie: " << endl;
        do{
            cout << "vf1: "; cin >> v_arce[i].x;
            cout << "vf2: "; cin >> v_arce[i].y;
            //cout << "cost: "; cin >> v_arce[i].cost;
            if(v_arce[i].x == v_arce[i].y || v_arce[i].x > n || v_arce[i].y > n){
                cout << "reintroduceti valorile: " << endl;
            }
        } while(v_arce[i].x == v_arce[i].y || v_arce[i].x > n || v_arce[i].y > n);
        if(a[v_arce[i].x][v_arce[i].y] == 1) {
            cout << "Muchia exista deja. Reintroduceti valorile: ";
            i--;
        } else{
            cout << "muchie buna";
            a[v_arce[i].x][v_arce[i].y] = 1;
        }
        cout << endl;

    }
}
// matr de adiacenta algoritm pt aplicatia 1 unde am nevie si de cost pt fiecare arc
void construire_matr_adiacenta_apl_1(int a[][20], arc v_arce[20], int n, int m) {
    int i, j;
    for(i = 1; i <= m; i++) {
        cout << "muchie: " << endl;
        do{
            cout << "vf1: "; cin >> v_arce[i].x;
            cout << "vf2: "; cin >> v_arce[i].y;
            cout << "cost: "; cin >> v_arce[i].cost;
            if(v_arce[i].x == v_arce[i].y || v_arce[i].x > n || v_arce[i].y > n){
                cout << "reintroduceti valorile: " << endl;
            }
        } while(v_arce[i].x == v_arce[i].y || v_arce[i].x > n || v_arce[i].y > n);
        if(a[v_arce[i].x][v_arce[i].y] == 1) {
            cout << "Muchia exista deja. Reintroduceti valorile: ";
            i--;
        } else{
            cout << "muchie buna";
            a[v_arce[i].x][v_arce[i].y] = 1;
        }
        cout << endl;

    }
}
/*===============================================*/
// calculare gard varfuri

void grade_ext( int vect_d_plus[], int a[][20], int n) {
    int i, j;
    for(i = 1; i <= n; i++) {
        vect_d_plus[i] = 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            vect_d_plus[i] = vect_d_plus[i] + a[i][j];
        }
    }
}

void grade_int( int vect_d_minus[], int a[][20], int n) {
    int i, j;
    for(i = 1; i <= n; i++) {
        vect_d_minus[i] = 0;
    }
    for(j = 1; j <= n; j++) {
        for(i = 1; i <= n; i++) {
            vect_d_minus[j] = vect_d_minus[j] + a[i][j];
        }
    }
}

/*===============================================*/
// verificare matrice petratica

int matrice_patratica(int m, int n) {
    if(m == n) {
        return 1;
    } else return 0;
}

/*===============================================*/
// verificare matrice adiacenta

int verifica_matr_adiacenta(int a[][10], int n) {
    int i, j, ok_el = 1;
    for(i = 1; i <= n && ok_el == 1; i++) {
        for(j = 1; j <= n; j++) {
            if(a[i][j] != 0 && a[i][j] != 1) {
                cout << "Element diferit de 1 sau 0: a[" << i << "][" << j << "] = " << a[i][j] << endl;
                ok_el = 0;
            }
        }
    }

    if( ok_el == 1 ) {
        return 1;
    }
    else
        return 0;
}

/*===============================================*/
// functrie constrire matrice drumuri - pe baza matr adiacenta

void drumuri(int a[][20], int d[][20], int m, int n) {
    int i, j, k;

    for(i = 1; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            d[i][j] = a[i][j];
        }
    }
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(d[i][j] == 0 && i != k && j != k) {
                    d[i][j] = d[i][k] * d[k][j];
                }
            }
        }
    }
}

/*===============================================*/
// functrie constrire matrice incidenta
void construire_matr_incidenta(int matr_incid[][20], arc v_arce[20], int n, int m) {
    int i, j;
    for(i = 1; i <= m; i++) {
        matr_incid[v_arce[i].x][i] = 1;
        matr_incid[v_arce[i].y][i] = -1;
    }
}

/*===============================================*/
// functie veridficare graf tare conex

int graf_tare_conex(int d[20][20], int m, int n) {
    int i, j, ok = 1;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(d[i][j] != 1) {
                ok = 0;
            }
        }
    }

    return ok;
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

        cout << "      4. Conexitate" << endl << endl;

        cout << "      5. Tare conexitate" << endl << endl;

        cout << "      6. Aplicatii" << endl << endl;

        cout << "      7. Test" << endl << endl;

        cout << "      8. Iesire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(8);

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
            mp_4_conexitate();
            break;

        case 5:
            mp_5_tare_conexitate();
            break;

        case 6:
            mp_6_aplicatii();
            break;

        case 7:
            mp_7_test();
            break;

        case 8:
            cout << "Ati ales optiunea '8' -> Terminare program";
            break;

        }
    } while(o != 8);


}

/*===============================================================
   opt 1 - meniu principal - definitie graf orientat
=================================================================*/
void mp_1_definitii() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Grafuri - definitii" << endl;

    cout << "\
    Se numeste graf orientat o pereche ordonata de multimi notata G=(X, U), unde:\n\
    - X este o multime finita si nevida ale carei elemente se numesc noduri sau varfuri;\n\
    - U este o multime de perechi ordonate de elemente distincte din X ale carei elemente se numesc arce.\n\n\
    Fie G=(X, U) un graf orientat. Se numeste graf partial al grafului G, graful orientat G1=(X, U1), \n\
    unde U1 inclus sau egal cu U.\n\
    Pentru a obtine un graf partial al grafului G, se elimina doar arce si se patreaza toate varfurile\n\n\
    Fie G= (X, U) un graf orientat. Se numeste subgraf al grafului G graful orientat G1= (Y, U1)\n\
    unde Y inclus in X iar U1 contine toate arcele din U care au extremitatile in Y.\n\
    Pentru a obtine un subgraf al garfului G, se elimina varfuri si muchiile incidente cu acestea.\n\n\
    Lant = o multime de arce, notata L = (u1 , u2 ,..., uk) cu proprietatea ca oricare doua arce consecutive\n\
    au o extremitate comuna (nu are importanta orientarea arcelor).\n\n\
    Drum = o succesiune de noduri, notata   D = (x1 , x2 ,..., xk), cu proprietatea ca pentru orice 1 < i < k,\n\
    (xi, xi+1) este arc in G.\n\n\
    Circuit = un drum simplu in care extremitatea initiala si finala sunt egale.";


    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;
    /* graf orientat, arc, lanţ, drum,
    circuit. Graf parţial, subgraf*/

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

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            m_gr_vf_1_def();
            break;

        case 2:
            m_gr_vf_2_vf_izolat();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}
/*===================================================================*/
// meniu grad vf - optiunea 1 - definitii
void m_gr_vf_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Gradul unui varf - definitii" << endl;
    cout << "\
    Fie G=(X, U) un graf orientat si x un nod al sau.\n\
    Se numeste grad exterior al nodului x, numarul arcelor de forma (x,y)\n\
    (adica numarul arcelor care ies din x), notat d+(x).\n\n\
    Se numeste grad interior al nodului x, numarul arcelor de forma (y,x)\n\
    (adica numarul arcelor care intra in x), notat d-(x)." << endl;

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


    cout << "   Varf izolat - definitie" << endl;

    cout << endl << "\
    Un nod x se numeste izolat daca d+(x)=d-(x)=0 (are gradul interior si gradul exterior egal cu 0).";

    getch();
    getline(cin, buffer);
}

/*===========================*/
void vf_izolat_2_aplicatie() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");
    int val;

    cout << "   Varf izolat - aplicatie" << endl;

    cout << " program:\n\
    for(i = 1; i <= n; i++) {\n\
        grade_ext( v_d_plus, a, n);\n\
        grade_int( v_d_minus, a, n);\n\
    }\n\
    for(i = 1; i <= n; i++) {\n\
        if(v_d_plus[i] == v_d_minus[i] && v_d_plus[i] == 0) {\n\
            cout << 'varf izolat: ' << i << endl;\n\
            nr_vf_iz ++;\n\
        }\n\
    }\n\
    if(nr_vf_iz == 0) {\n\
        cout << 'in graful dat nu exista varfuri izolate';\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            verificare_vf_izolat();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);


    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt vf_izolat
=================================================*/

void verificare_vf_izolat() {
    int a[20][20] = {0};
    int n , m, i, j, v_d_plus[20], v_d_minus[10], nr_vf_iz = 0;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    // calculez gradul exterior si interior pentru diecare varf si le pun in vectori respectivi
    for(i = 1; i <= n; i++) {
        grade_ext( v_d_plus, a, n);
        grade_int( v_d_minus, a, n);
    }

    // percurg vectorii si verific unde am 0 si in primul si in al doilea vector pe aceeasi pozitie, care reprezinta varfrul
    for(i = 1; i <= n; i++) {
        if(v_d_plus[i] == v_d_minus[i] && v_d_plus[i] == 0) {
            cout << "varf izolat: " << i << endl;
            nr_vf_iz ++;
        }
    }

    if(nr_vf_iz == 0) {
        cout << "in graful dat nu exista varfuri izolate";
    }
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

        cout << "      4. Matrice de incidenta" << endl << endl;

        cout << "      5. Matricea drumurilor" << endl << endl;

        cout << "      6. Multimea succesorilor si predecesorilor" << endl << endl;

        cout << "      7. Multimea arcelor (x,y) , respectiv (y,x)" << endl << endl;

        cout << "      8. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(8);

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
            metode_repr_4_matr_incidenta();
            break;

        case 5:
            metode_repr_5_matr_drumuri();
            break;

        case 6:
            metode_repr_6_multime_predecesori_succesori();
            break;

        case 7:
            metode_repr_7_multime_arce_xy_yx();
            break;

        case 8:
            cout << "Ati ales optiunea '8' -> revenire la meniul principal";
            break;
        }
    } while(o != 8);
}

/*===================================================================*/
// opt 1 meniu met reprezentare - lista adiacenta
void metode_repr_1_ls_adiacenta() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Lista adiacenta - definitie + program + executie" << endl;
    cout << "\n\
    DEFINITIE: \n\
    Pentru un graf orientat cu G = (X, U) se va memora numarul de noduri n si apoi,\n\
    pentru fiecare nod x, lista succesorilor lui x, adica nodurilor y cu proprietatea\n\
    ca exista arcul (x,y)." << endl << endl;

    ls_ad_program();

    getch();
    getline(cin, buffer);
}

/*===============================================*/

void ls_ad_program() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    //system("cls");

    cout << "program:\n\n\
    for(i = 1; i <= n; i++) {\n\
        cout << i<< ': L+: ';\n\
        for(j = 1; j <= n; j++) {\n\
            if(a[i][j] == 1) cout << j << ' ' ;\n\
        }\n\
        cout << endl << '   L-:';\n\
        for(j = 1; j <= m; j++) {\n\
            if(v_arce[j].y == i) {\n\
                cout << v_arce[j].x << ' ';\n\
            }\n\
        }\n\
        cout << endl << endl;\n\
    }"<< endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            apl_ls_adiacenta();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================
    Program afisare lista adiacenta
=================================================*/
void apl_ls_adiacenta() {
    int a[20][20] = {0};
    int n , m, i, j, v_d_plus[20], v_d_minus[10], nr_vf_iz = 0;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    cout << endl << endl << "lista de adiacenta: " << endl;
    for(i = 1; i <= n; i++) {
        cout << i<< ": L+: ";
        for(j = 1; j <= n; j++) {
            if(a[i][j] == 1) cout << j << " ";
        }
        cout << endl << "   L-: ";
        for(j = 1; j <= m; j++) {
            if(v_arce[j].y == i) {
                cout << v_arce[j].x << " ";
            }
        }
        cout << endl << endl;
    }
}
/*===================================================================*/
// opt 2 meniu met reprezentare - vectorul muchiilor
void metode_repr_2_vect_muchii() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Vectorul muchiilor - definitie" << endl << endl;
    cout << "\n\
    Un arc al grafului poate fi memorat sub forma unei inregistrari si,\n\
    pentru toate arcele unui graf orientat dat, avem nevoie de un vector cu astfel de elemente:\n\n\
    struct arc {\n\
        int x;\n\
        int y;\n\
    };\n\
    arc v_arce[20];" << endl << endl;

    v_muchii_program();


    getch();
    getline(cin, buffer);
}

/*===============================================*/
void v_muchii_program() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    //system("cls");


    cout << " Vectorul muchiilor - aplicatie: program:" << endl;
    cout << "\n\
    struct arc {\n\
        int x;\n\
        int y;\n\
    };\n\
    arc v_arce[20];\n\
    for(i = 1; i <= m; i++) {\n\
        cin >> v_arce[i].x;\n\
        cin >> v_arce[i].y;\n\
    }\n\
    for(i = 1; i <= m; i++) {\n\
        cout << v_arce[i].x << v_arce[i].y << endl;\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            apl_vect_muchii();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================
    Program afisare vectorul muchiilor
=================================================*/
void apl_vect_muchii() {
    int a[20][20], n , m, i, j;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout <<"introduceti un numar mai mic decat: " << n * (n-1) << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    cout << "vectorul muchiilor: " << endl;
    for(i = 1; i <= m; i++) {
        cout <<"(" << v_arce[i].x << ", " << v_arce[i].y << ")" << " ";
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
        cout << "   Meniu matrice adiacenta:" << endl << endl;

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


    cout << "   Matrice adiacenta - definitie + caracteristici" << endl;
    cout << "\n\n\
    Este o matrice (A) cu n linii si n coloane, ale carei elemente sunt definite astfel:\n\
    a(i, j) = { 1,  daca i, j apartine lui U, cu i != j sau 0,  in caz contrar\n\n\
    Caracteristicile unei matrice de adiacenta definita pentru un graf neorientat dat:\n\
        - este patratica\n\
        - este binara";

    getch();
    getline(cin, buffer);
}
/*===========================*/
void matr_adiacenta_2_aplicatie() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Matrice adiacenta - aplicatie" << endl;
    cout << endl << "program:\n\
    int matrice_patratica(int m, int n) {\n\
        if(m == n) {\n\
            return 1;\n\
        } else return 0;\n\
    }\n\
    int verifica_matr_adiacenta(int a[][10], int n) {\n\
        int i, j, ok_el = 1;\n\
        for(i = 1; i <= n && ok_el == 1; i++) {\n\
            for(j = 1; j <= n; j++) {\n\
                if(a[i][j] != 0 && a[i][j] != 1) {\n\
                    ok_el = 0;\n\
                }\n\
            }\n\
        }\n\
        if( ok_el == 1 ) {\n\
            return 1;\n\
        }\n\
        else\n\
            return 0;\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            apl_matr_adiacenta();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);


    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt verificare matrice adiacenta - DE ADAUGAT!!!
=================================================*/

void apl_matr_adiacenta() {
    int n, m, a[10][10], i, j;
    cout << "nr linii: "; cin >> n;
    cout << "nr coloane: "; cin >> m;

    if(matrice_patratica(m, n) == 1) {
        cout << "citire matrice: " << endl;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
            cout << endl;
        }
        if(verifica_matr_adiacenta(a, n) == 1)
            cout << "este matrice de adiacenta";
        else
            cout << "nu este matrice de adiacenta";
    } else
        cout << "nu se poate construi matricea de adiacenta -> nr linii != nr coloane";

}

/*===================================================================*/
// opt 4 meniu met reprezentare - matrice de incidenta - care deschide alt meniu
void metode_repr_4_matr_incidenta() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "   Meniu matrice incidenta:" << endl << endl;

        cout << "      1. Definitie + Caracteristici" << endl << endl;

        cout << "      2. Constructie matrice incidenta" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            matr_incidenta_1_def();
            break;

        case 2:
            matr_incidenta_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===========================*/
void matr_incidenta_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Matrice incidenta - definitie + caracteristici" << endl;
    cout << "\n\
    Matricea de incidenta (B) va avea numarul de linii egal cu numarul de varfuri din\n\
    graf iar numarul de coloane este egal cu numarul de arce.\n\
    Aceasta matrice se defineste:\n\
    b(i, j) ={ 1,  daca  varful i este incident exterior cu arcul j\n\
              -1,  dacă varful i este incident interior cu arcul j\n\
               0,  dacă varful i nu este incident cu arcul j\n\n\
    Observatii:\n\
        -pe fiecare coloana a matricei B va exista doar o perche de valori nenule\n\
        (o valoare 1 si o valoare -1)\n\
        -pe linia i, numarul de valori 1 reprezinta gradul exterior al varfului i\n\
        -pe linia i, numarul de valori -1 reprezintă gradul interior al varfului i" << endl;

    getch();
    getline(cin, buffer);
}
/*===========================*/
void matr_incidenta_2_aplicatie() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Matrice incidenta - aplicatie - constrire matrice" << endl;
    cout << "\n\
    program:\n\
    int i, j;\n\
    for(i = 1; i <= m; i++) {\n\
        matr_incid[v_arce[i].x][i] = 1;\n\
        matr_incid[v_arce[i].y][i] = -1;\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            matr_incidenta_program();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt verificare matrice incidenta
=================================================*/
void matr_incidenta_program() {
    int a[20][20] = {0};
    int matr_incid[20][20] = {0};
    int n , m, i, j;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);
    construire_matr_incidenta(matr_incid, v_arce, n, m);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cout << matr_incid[i][j] << "  ";
        }
        cout << endl;
    }
}

/*===================================================================*/
// opt 5 meniu met reprezentare - matrice drumurilor - care deschide alt meniu
void metode_repr_5_matr_drumuri() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "   Meniu matricea drumurilor:" << endl << endl;

        cout << "      1. Definitie + Caracteristici" << endl << endl;

        cout << "      2. Algoritmul Roy Warshall (program + executie)" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            matr_drumuri_1_def();
            break;

        case 2:
            matr_drumuri_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===========================*/
void matr_drumuri_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Matricea drumurilor - definitie + caracteristici" << endl;
    cout << "\n\
    Matricea de drumurilor (D) a grafului este o matrice cu n linii si n coloane si elemente\n\
    0 sau 1, astfel:\n\
    d(i, j) = { 1, daca exista drum de la i la j\n\
                0,  in caz contrar\n\n\
    Observatie: matricea drumurilor pentru un graf orientat tare conex va contine doar alori egale cu 1" << endl;

    getch();
    getline(cin, buffer);
}
/*===========================*/
void matr_drumuri_2_aplicatie() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Matricea drumurilor - Algoritmul Roy Warshall (program + executie) " << endl;
    cout << endl << "program:\
    void drumuri(int a[][20], int d[][20], int m, int n) {\n\
        int i, j, k;\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 0; j <= n; j++) {\n\
                d[i][j] = a[i][j];\n\
            }\n\
        }\n\
        for(k = 1; k <= n; k++) {\n\
            for(i = 1; i <= n; i++) {\n\
                for(j = 1; j <= n; j++) {\n\
                    if(d[i][j] == 0 && i != k && j != k) {\n\
                        d[i][j] = d[i][k] * d[k][j];\n\
                    }\n\
                }\n\
            }\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            apl_matr_drumuri();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt construire matrice drumuri
=================================================*/
void apl_matr_drumuri() {
    int a[20][20] = {0} ;
    int d[20][20] = {0} ;
    int n , m, i, j;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    drumuri(a, d, m, n);
    cout << endl << "matricea drumurilor: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
/*===================================================================*/
// opt 6 meniu met reprezentare - multimea pred + succesori - care deschide alt meniu
void metode_repr_6_multime_predecesori_succesori() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "   Meniu multimea predecesorilor si succesorilor:" << endl << endl;

        cout << "      1. Definitii" << endl << endl;

        cout << "      2. Aplicatie" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            multime_pred_succ_1_def();
            break;

        case 2:
            multime_pred_succ_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===========================*/
void multime_pred_succ_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Multimea predecesorilor si multimea succsorilor - definitii" << endl;
    cout << "\n\n\
    multimea succesorilor(x) = {y | (x, y) apartile lui U)}\n\
    multimea predecesorilor(x) = {y | (y, x) apartile lui U}" << endl << endl;
    getch();
    getline(cin, buffer);
}
/*===========================*/
void multime_pred_succ_2_aplicatie() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Multimea predecesorilor si multimea succsorilor (program + executie) " << endl;
    // afişarea celor două mulţimi pentru fiecare varf in parte + execuţie)

    cout << "\n\
    program:\n\
    for(i = 1; i <= n; i++) {\n\
        cout << i << ' succesori: ';\n\
        for(j = 1; j <= n; j++) {\n\
            if(a[i][j] == 1) cout << j << " ";\n\
        }\n\
        cout << endl << 'predecesori: ';\n\
        for(j = 1; j <= m; j++) {\n\
            if(v_arce[j].y == i) {\n\
                cout << v_arce[j].x << ' ';\n\
            }\n\
        }\n\
        cout << endl << endl\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            prog_succesori_predecesori();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);


    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt multime succesori si predecesori
=================================================*/
void prog_succesori_predecesori() {
    int a[20][20] = {0};
    int n , m, i, j, v_d_plus[20], v_d_minus[10], nr_vf_iz = 0;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    //cout << endl << endl << "lista de adiacenta: " << endl;
    for(i = 1; i <= n; i++) {
        cout << i<< ": succesori" << "(" << i  << ") : ";
        for(j = 1; j <= n; j++) {
            if(a[i][j] == 1) cout << j << " ";
        }
        cout << endl << "   predecesori" << "(" << i  << ") : ";
        for(j = 1; j <= m; j++) {
            if(v_arce[j].y == i) {
                cout << v_arce[j].x << " ";
            }
        }
        cout << endl << endl;
    }
}
/*===================================================================*/
// opt 7 meniu met reprezentare - multime arce x, y si y, x - care deschide alt meniu
void metode_repr_7_multime_arce_xy_yx() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "   Meniu multimea arcelor(x, y) si (y, x):" << endl << endl;

        cout << "      1. Definitii" << endl << endl;

        cout << "      2. Aplicatie" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            multime_arce_xy_yx_1_def();
            break;

        case 2:
            multime_arce_xy_yx_2_aplicatie();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===========================*/
void multime_arce_xy_yx_1_def() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Multimea arcelor(x, y) si (y, x) - definitii" << endl;
    cout << "\n\
    w+ = {(x, y) | (x, y) apartine lui U\n\
    w- = {(y, x) | (y, x) apartine lui U}" << endl << endl;

    getch();
    getline(cin, buffer);
}
/*===========================*/
void multime_arce_xy_yx_2_aplicatie() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Multimea arcelor(x, y) si (y, x) (program + executie) " << endl;
    cout << "\n\
    program:\n\
    for(i = 1; i <= n; i++) {\n\
        cout << i << ': w+ = { ';\n\
        for(j = 1; j <= m; j++) {\n\
            if(v_arce[j].x == i){\n\
                cout <<'(' << v_arce[j].x << ', ' << v_arce[j].y << ')';\n\
            }\n\
        }\n\
        cout << ' }' << endl;\n\
        cout << i << ': w- = { ';\n\
        for(j = 1; j <= m; j++) {\n\
            if(v_arce[j].y == i){\n\
                cout <<'(' << v_arce[j].x << ', ' << v_arce[j].y << ')' << ' ';\n\
            }\n\
        }\n\
        cout <<  '}' << endl;\n\
        cout << endl;\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            m_arce_prg();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt multime arce x, y si y, x
=================================================*/
void m_arce_prg() {
    int a[20][20] = {0};
    int n , m, i, j;
    i = 1;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    for(i = 1; i <= n; i++) {
        cout << i << ": w+ = { ";
        for(j = 1; j <= m; j++) {
            if(v_arce[j].x == i){
                cout <<"(" << v_arce[j].x << ", " << v_arce[j].y << ")" << " ";
            }
        }
        cout << " }" << endl;

        cout << i << ": w- = { ";
        for(j = 1; j <= m; j++) {
            if(v_arce[j].y == i){
                cout <<"(" << v_arce[j].x << ", " << v_arce[j].y << ")" << " ";
            }
        }
        cout << " }" << endl;
        cout << endl;
    }
}

/*=================================================================
  opt 4 - meniu principal - conexitate
 =================================================================*/
void mp_4_conexitate() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu conexitate:" << endl << endl;

        cout << "      1. Definitie graf conex" << endl << endl;

        cout << "      2. Definitie componenta conexa" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            m_conx_def_grf_conx();
            break;

        case 2:
            m_conx_componenta_conx();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===============================================*/
void m_conx_def_grf_conx() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Graf conex - definitie" << endl;
    cout << "\n\
    Fie G = (X, U) un graf orientat. Graful este conex daca oricare ar fi doua varfuri ale sale,\n\
    exista un lant care le are ca extremitati." << endl;


    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}

/*===============================================*/
void m_conx_componenta_conx() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Componenta conexa - definitie" << endl;
    cout << "\n\
    Se numeste componenta conexa a grafului G= (X, U), un subgraf G1 = (Y, U1) a lui G,\n\
    conex, cu proprietatea ca nu exista nici un lant care sa lege un nod din Y cu un nod\n\
    din X-Y (pentru orice nod, nu exista un lant între acel nod si nodurile care fac parte\n\
    din subgraf)." << endl;


    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}

/*=================================================================
  opt 5 - meniu principal - tare conexitate
 =================================================================*/
void mp_5_tare_conexitate() {

    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu tare conexitate:" << endl << endl;

        cout << "      1. Definitie graf tare conex + comonenta tare conexa" << endl << endl;

        cout << "      2. Verificare garf tare conex" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            tare_conx_def();
            break;

        case 2:
            tare_conx_program();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

/*===============================================*/
void tare_conx_def() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Graf tare conex - definitii" << endl;

    cout << "\n\
    Fie G = (X, U) un graf orientat.\n\
    Graful se numeste tare conex daca pentru oricare doua noduri x si y  exista un drum\n\
    de la x la y precum si un drum de la y la x.\n\
    Se numeste componenta tare conexa un subgraf tare conex si maximal in raport cu aceasta calitate.\n\
    ( daca am mai adauga un nod, n-ar mai fi tare conex)" << endl;


    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}
/*===============================================*/
void tare_conx_program() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "   Graf tare conex - verificare - program" << endl;
    cout << "\n\
    void drumuri(int a[][20], int d[][20], int m, int n) {\n\
        int i, j, k;\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 0; j <= n; j++) {\n\
                d[i][j] = a[i][j];\n\
            }\n\
        }\n\
        for(k = 1; k <= n; k++) {\n\
            for(i = 1; i <= n; i++) {\n\
                for(j = 1; j <= n; j++) {\n\
                    if(d[i][j] == 0 && i != k && j != k) {\n\
                        d[i][j] = d[i][k] * d[k][j];\n\
                    }\n\
                }\n\
            }\n\
        }\n\
    }\n\
    int graf_tare_conex(int d[20][20], int m, int n) {\n\
        int i, j, ok = 1;\n\
        for(i = 1; i <= n; i++) {\n\
            for(j = 1; j <= n; j++) {\n\
                if(d[i][j] != 1) {\n\
                    ok = 0;\n\
                }\n\
            }\n\
        }\n\
        return ok;\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            apl_graf_tare_conex();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);



    cout << endl << "Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}

/*===============================================
Program pt verficare graf conex
=================================================*/
void apl_graf_tare_conex() {
    int n, m, i, j;
    int a[20][20] = {0}, d[20][20] = {0};

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "m: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);
    drumuri(a, d, m, n);

    if(graf_tare_conex(d, m, n) == 1) {
        cout << endl << "graf tare conex";
    } else
        cout << endl << "graful NU e tare conex";
}


/*=====================================================================
  opt 6 - meniu PRINCIPAL - Aplicatii
======================================================================*/
void mp_6_aplicatii() {

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
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 1" << endl;
    cout << "\n\
    cerinta:\n\
    Se defineste un arc al unui graf orientat ca o inregistrare cu trei campuri:\n\
    varful din care iese arcul, varful in care intra arcul si un cost asociat arcului\n\
    (un numar intreg). Definim un graf orientat ca un vector de arce.\n\
    Fiind dat vectorul de arce al unui graf orientat G=(X,U) cu m arce si n varfuri,\n\
    sa se construiasca si sa se afiseze matricea de adiacenta, apoi sa se determine\n\
    costul mediu al grafului (media aritmetica a costurilor arcelor).";

    cout << endl << endl << "cod program: " << endl;
    cout << "\
    int a[20][20] = {0}, n, m, i, j, suma = 0, nr_costuri = 0;\n\
    cin >> n;\n\
    do{\n\
        cin >> m;\n\
    } while(m > n*(n-1));\n\
    construire_matr_adiacenta_apl_1(a, v_arce, n, m);\n\
    for(i = 1; i <= n; i++) {\n\
        for(j = 1; j <= n; j++) {\n\
            cout << a[i][j] << ' ';\n\
        }\n\
        cout << endl;\n\
    }\n\
    for(i = 1; i <= m; i++) {\n\
        suma = suma + v_arce[i].cost;\n\
        nr_costuri++;\n\
    }\n\
    cout << suma << endl;\n\
    cout <<  << suma / nr_costuri << endl;" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            program_apl_1();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}
/*===============================================*/
// PROGRAM APLICATIE 1

void program_apl_1() {
    int a[20][20] = {0}, n, m, i, j, suma = 0, nr_costuri = 0;

    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii: ";
        cin >> m;
    } while(m > n*(n-1));


    cout << "n = " << n << ", m = " << m << endl;

    construire_matr_adiacenta_apl_1(a, v_arce, n, m);
    cout << "matrice de adiacenta: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(i = 1; i <= m; i++) {
        suma = suma + v_arce[i].cost;
        nr_costuri++;
    }
    //cout << "suma: " << suma << endl;

    cout << "media costurilor: " << suma / nr_costuri << endl;
}

/*===============================================*/
void apl_2() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 2" << endl;
    cout << "cerinta:\n\
    Sa se realizeze un program prin care, introducand arcele unui graf orientat,\n\
    se calculeze suma gradelor interioare pare " << endl << endl;

    cout << " program:\n\
    int n, m, i, j, v_d_plus[20], v_d_minus[20], s = 0;\n\
    int a[20][20] = {0};\n\
    cout << 'nr varfuri: '; cin >> n;\n\
    do{\n\
        cout << 'nr muchii ( un numar mai mic decat: ' << n * (n-1) << ' )' << endl;\n\
        cout << 'nr muchii: ';\n\
        cin >> m;\n\
    } while(m > n*(n-1));\n\
    construire_matr_adiacenta(a, v_arce, n, m);\n\
    cout << endl;\n\
    grade_int(v_d_minus, a, n);\n\
    for(i = 1; i <= n; i++) {\n\
        if( v_d_minus[i] % 2 == 0){\n\
            s = s + v_d_minus[i];\n\
        }\n\
    }\n\
    cout << 'suma gredelor interioare pare: ' << s; " << endl << endl;

    //cout << endl << endl << "executie program: " << endl;
    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            program_apl_2();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================*/
// PROGRAM APLICATIE 2
void program_apl_2() {
    int n, m, i, j, v_d_plus[20], v_d_minus[20], s = 0;
    int a[20][20] = {0};
    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "nr muchii: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);

    cout << endl;
    grade_int(v_d_minus, a, n);
    for(i = 1; i <= n; i++) {
        if( v_d_minus[i] % 2 == 0){
            s = s + v_d_minus[i];
            //cout << "grad par pentru: " << i << ": " << v_d_minus[i] << endl;
        }
    }
    cout << "suma gredelor interioare pare: " << s;

}

/*===============================================*/
void apl_3() {
    int val;
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");


    cout << "Problema 3" << endl;
    cout << "cerinta:\n\
    Sa se realizeze un program prin care, introducand arcele unui graf orientat,\n\
    se construiasca matricea de adiacenta si sa determine varfurile care au gradul exterior numar impar";
    cout << endl << endl;
    cout << "program:\n\
    int n, m, i, j, v_d_plus[20], v_d_minus[20];\n\
    int a[20][20] = {0};\n\
    cout << 'nr varfuri: '; cin >> n;\n\
    do{\n\
        cout << 'nr muchii ( un numar mai mic decat: ' << n * (n-1) << ' )' << endl;\n\
        cout << 'nr muchii: ';\n\
        cin >> m;\n\
    } while(m > n*(n-1));\n\
    construire_matr_adiacenta(a, v_arce, n, m);\n\
    cout << 'matrice de adiacenta: ' << endl;\n\
    for(i = 1; i <= n; i++) {\n\
        for(j = 1; j <= n; j++) {\n\
            cout << a[i][j] << ' ';\n\
        }\n\
        cout << endl;\n\
    }\n\
    cout << endl;\n\
    grade_ext(v_d_plus, a, n);\n\
    for(i = 1; i <= n; i++) {\n\
        if( v_d_plus[i] % 2 != 0){\n\
            cout << 'varf cu grad exterior numar impar: ' << i << endl;\n\
        }\n\
    }" << endl;

    //cout << endl << endl << "executie program: " << endl;
    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            program_apl_3();
        }
        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            //getch();
            //getline(cin, buffer);
            //getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);

    getch();
    getline(cin, buffer);
}

/*===============================================*/
// PROGRAM APLICATIE 2
void program_apl_3() {
    int n, m, i, j, v_d_plus[20], v_d_minus[20];
    int a[20][20] = {0};
    cout << "nr varfuri: "; cin >> n;
    do{
        cout << "nr muchii ( un numar mai mic decat: " << n * (n-1) << " )" << endl;
        cout << "nr muchii: ";
        cin >> m;
    } while(m > n*(n-1));

    construire_matr_adiacenta(a, v_arce, n, m);
    cout << "matrice de adiacenta: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    grade_ext(v_d_plus, a, n);
    for(i = 1; i <= n; i++) {
        if( v_d_plus[i] % 2 != 0){
            cout << "varf cu grad exterior numar impar: " << i << endl;
        }
    }

}
/*===============================================================
   opt 7 - meniu principal - test
=================================================================*/
void mp_7_test() {

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
// -----> de completat cu functia
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

    punctaj += intrebare_cu_un_raspuns(intrebare_2, 4);
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_un_raspuns(intrebare_3, 1);
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_un_raspuns(intrebare_4, 3);
    cout << endl <<"punctaj: " << punctaj << endl;

    getline(cin, golire_buf);


    punctaj += intrebare_cu_mm_raspunsuri(intrebare_5, "124");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_mm_raspunsuri(intrebare_6, "12");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_mm_raspunsuri(intrebare_7, "23");
    cout << endl <<"punctaj: " << punctaj << endl;

    punctaj += intrebare_cu_r_scurt(intrebare_8, "izolat");
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

#include <iostream>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> //pt system("cls")
#include <string.h>

using namespace std;
int max_elem = 101;
int coada[101], vfc = 0, bc = 0, c_are_el = 0;
int stiva[101], vfs = 0, s_are_el = 0;

//Functii ajutatoare
int citeste_optiune_meniu(int max_optiuni);

//Functii care reprezinta optiuni de meniu sau parte din cerinta proiectului
void afisare_nume();

//mp - meniu principal
void meniu_principal();

// liste
void mp_lista();


void ml_1_creare_ls();
void creare_ls(int v[], int i);

void ml_1_ad_el_ls();
void adaugare(int v[], int n, int i);

void afisc_are_el_ls();
void afisare(int n, int v[], int nr_el);

void elimare_prim_el_ls();
void el_pr_el (int n, int v[], int &nr_el);

void elimare_ultim_el_ls();
void el_ul_el (int n, int v[], int nr_el);

void elimc_are_el_poz_x();
void eliminare_pozitie( int &n_el, int v[], int &x);

void elimc_are_el_elgal_cu_x();
void eliminc_are_el_egal_cu_val(int &n_el, int v[], int x);


//Stiva
void mp_stiva();
void def_stiva();
void operatii_stiva();

void adaugc_are_el_stiva();
void ad_el_stiva(int n, int &vfs, int v[], int x);

void eliminc_are_el_stiva();
void el_stiva(int v[]);

//coada
void creare_coada(int v[], int i);
void mp_coada();
void def_coada();
void operatii_coada();

void adaugc_are_el_coada();
void ad_el_coda(int n, int &bc, int v[], int x);

void eliminc_are_el_coada();
void el_el_coda(int v[]);

/************************************************
    MAIN
 ************************************************/
int main() {
    //int rulare_program = 1;
    afisare_nume();
    meniu_principal();

    return 0;
}




/********************************************
    Functii ajutatoare
 ********************************************/
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

/********************************************
    Functii meniu
 ********************************************/

void afisare_nume() {

    string buffer; //variabila necesara pentru a putea utilizat getline
    //               - in acest caz doar astept enter


    //stergere ecran - foloseste functie din strlib.h
    system("cls");
    cout << "       Chende-Roman Teodora" << endl;
    cout << "       Cl: XI C" << endl;
    cout << "       Proiect Informatica. Semestrul 1. Liste alocate static";

    getline(cin, buffer);
    //getch();
}

// meniu principal
void meniu_principal() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu principal:" << endl << endl;

        cout << "      1. Lista" << endl << endl;

        cout << "      2. Stiva" << endl << endl;

        cout << "      3. Coada" << endl << endl;

        cout << "      4. Iesire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(4);

        cout << "MP. Ales: " << o << endl;

        switch(o) {
        case 1:
            mp_lista();
            break;

        case 2:
            mp_stiva();
            break;

        case 3:
            mp_coada();
            break;

        case 4:
            cout << "Ati ales optiunea '4' -> Terminare program";
            break;
        }
    } while(o != 4);


}

//mp - de la meniu principal

void mp_lista() {
    int o;

    do {
        system("cls");



        //afisare meniu
    cout << "Meniu Liste:" << endl << endl;

    cout << "      1. Crearea unei liste " << endl << endl;

    cout << "      2. Adaugarea unui element" << endl << endl;

    cout << "      3. Afisarea elementelor" << endl << endl;

    cout << "      4. Eliminarea primului element" << endl << endl;

    cout << "      5. Eliminarea ultimului element" << endl << endl;

    cout << "      6. Eliminarea elementului situat pe pozitia X" << endl << endl;

    cout << "      7. Eliminarea elementului egal cu o valoare X" << endl << endl;

    cout << "      8. REVENIRE" << endl << endl;

    cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;

        o = citeste_optiune_meniu(8);

        cout << "MP. Ales: " << o << endl;

        switch(o) {
        case 1:
            ml_1_creare_ls();
            break;

        case 2:
            ml_1_ad_el_ls();
            break;

        case 3:
            afisc_are_el_ls();
            break;

        case 4:
            elimare_prim_el_ls();
            break;

        case 5:
            elimare_ultim_el_ls();
            break;

        case 6:
            elimc_are_el_poz_x();
            break;

        case 7:
            elimc_are_el_elgal_cu_x();
            break;

        case 8:
            cout << "Ati ales optiunea '7' -> Revenire in meniul principal" << endl;
            break;
        }
    } while(o != 8);

}

//meniu liste optiunea 1
void ml_1_creare_ls() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tastatura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, i, val; // i - nr. el vector, n - nr maxim el care pot fi in vector

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void creare_ls(int v[], int &i) { \n\
        int j;\n\
        cout << 'nr elemente: i : '; cin >> i;\n\
        for(j = 0; j < i; j ++) {\n\
            cin >> v[j];\n\
        }\n\
        cout << endl << endl;\n\
        for(j = 0; j < i; j++) {\n\
            cout << v[j] << ' ';\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do{

        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> i;
            } while(i > n);

            creare_ls(v, i);

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

//pogram optione 1
void creare_ls(int v[], int i) { // i = nr el = poz_max + 1
    int j;
    //cout << "nr elemente: i : "; cin >> i;
    for(j = 0; j < i; j ++) {
        cin >> v[j];
    }
    //cout << endl << endl << "DBG: creare_ls. creat: " ;
    for(j = 0; j < i; j++) {
        cout << v[j] << " ";
    }
}

// meniu liste optiunea 2
void ml_1_ad_el_ls() {

    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, i, x, val; // i reprezinta numarul de elemente din vector
    // n reprezinta numarul maxim de elemente care poate fi in vector

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void adaugare(int v[], int n, int& i, int x){\n\
        if (i < n){ \n\
            i++;\n\
            v[i] = x;\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {

            do{
                cout << "executie: " << endl;
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> i;
            } while(i > n);

            creare_ls(v, i);

            //cout << endl << endl << "DBG: lista creata: " ;
            //for(int j = 0; j < i; j++) {
            //    cout << v[j] << " ";
            //}
            cout << endl;
            //cout << endl << endl << "element ce vreti sa fie adaugat: "; cin >> x;

            adaugare(v, n, i);
            i = i + 1;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// prpogram optiune 2
void adaugare(int v[], int n, int i) {
    int j, x;
    if (i < n){
        //i++;
        cout << "el de adaugat: "; cin >> x;
        v[i] = x;
        cout << "adaugat: v[i]: " << v[i] << " unde i = " << i;
        cout << endl;

        //cout << "DBG. adaugare: lista este: ";
        for( j = 0; j <= i; j++) {
            cout << v[j] << " ";
        }

    } else {
        cout << "Lista este plina";
    }

 }

// meniu liste optiunea 3
void afisc_are_el_ls() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void afisare(int n, int v[], int nr_el) {\n\
        int j;\n\
        for(j = 0; j < nr_el; j++) {\n\
            cout << v[j] << " ";\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            creare_ls(v, nr_el);


            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program optiune 3
 void afisare(int n, int v[], int nr_el) {
    int j;
    cout << "DBG: afisare: nr_el: " << nr_el << endl;
    for(j = 0; j < nr_el; j++) {
        cout << v[j] << " ";
    }
 }

 //meniu liste optiunea 4
 void elimare_prim_el_ls() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void el_pr_el (int n, int v[], int &nr_el) {\n\
        int j;\n\
        for (j = 0; j < nr_el - 1; j++) {\n\
           v[j] = v[j+1];\n\
       }\n\
        nr_el--;\n\
        for(j = 0; j < nr_el; j++) {\n\
            cout << v[j] << " ";\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);

            creare_ls(v, nr_el);
            cout << endl << "lista fara primul el: ";
            el_pr_el (n, v, nr_el);
            //afisare(n, v, nr_el);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program optiune 4
void el_pr_el (int n, int v[], int &nr_el) {
    int j;
    for (j = 0; j < nr_el - 1; j++) {
       v[j] = v[j+1];
    }
    nr_el--;

    for(j = 0; j < nr_el; j++) {
        cout << v[j] << " ";
    }
}


// meniu lista optiunea 5
void elimare_ultim_el_ls() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void el_ul_el (int n, int v[], int nr_el) {\n\
        int j;\n\
        nr_el = nr_el - 1;\n\
        for (j = 0; j < nr_el; j++) {\n\
           cout << v[j] << ' ';\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            creare_ls(v, nr_el);
            cout << endl << "lista fara ultimul el: ";
            afisare(n, v, nr_el - 1);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program optiune 5
void el_ul_el (int n, int v[], int nr_el) {
    int j;
    nr_el = nr_el - 1;
    for (j = 0; j < nr_el; j++) {
       cout << v[j] << " ";
    }
}

// meniu lista optiunea 6
void elimc_are_el_poz_x() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void eliminare_pozitie( int &n, int v[], int &x) {\n\
        int i;\n\
        do{\n\
            cout << 'poz de pe care se el element: '; cin >> x;\n\
        } while ( x > n-1 );\n\
        for(i = x; i < n; i++) {\n\
            v[i] = v[i+1];\n\
        }\n\
        n = n-1;\n\
        cout << 'lista finala: ';\n\
        for(i = 0; i < n; i++) {\n\
            cout  << v[i] << " ";\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            creare_ls(v, nr_el);
            eliminare_pozitie( nr_el, v, x);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program optiune 6
void eliminare_pozitie( int &n_el, int v[], int &x) {
    int i;
    do{
        cout << endl << "poz de pe care se el element: "; cin >> x;
    } while ( x > n_el - 1 );
    for(i = x; i < n_el; i++) {
        v[i] = v[i+1];
    }
    n_el = n_el-1;
    cout << "lista finala: ";
    for(i = 0; i < n_el; i++) {
        cout  << v[i] << " ";
    }
}

// meniu lista optiunea 7
void elimc_are_el_elgal_cu_x() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    int v[101], n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
    void eliminc_are_el_egal_cu_val(int &n_el, int v[], int x) {\n\
        int i, j, contor = 0;\n\
        for(i = 0; i < n_el; i++) {\n\
            if(v[i] == x) {\n\
                for(j = i; j < n_el - 1; j++) {\n\
                    v[j] = v[j+1];\n\
                }\n\
                n_el--;\n\
                i--;\n\
            }\n\
        }\n\
        cout << 'lista finala: ';\n\
        for(i = 0; i < n_el; i++) {\n\
            cout  << v[i] << ' ' ;\n\
        }\n\
    }" << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            creare_ls(v, nr_el);
            cout << "valoare element care trebuie eliminat: "; cin >> x;
            eliminc_are_el_egal_cu_val(nr_el, v, x);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}
// program optiune 7
void eliminc_are_el_egal_cu_val(int &n_el, int v[], int x) {
    int i, j, contor = 0;
    //cout << "valoare element care trebuie eliminat: "; cin >> x;
    for(i = 0; i < n_el; i++) {
        if(v[i] == x) {
            for(j = i; j < n_el - 1; j++) {
                v[j] = v[j+1];
            }
            n_el--;
            i--;
        }
    }
    cout << "lista finala: ";
    for(i = 0; i < n_el; i++) {
        cout  << v[i] << " ";
    }
}


// mp Stiva
void creare_stiva(int v[], int i) {
    creare_ls(v, i);
    s_are_el = 1;
    vfs = i-1; // i nr elem; vfs = poz pe care pot adauga un nou element;
}

void mp_stiva() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu Stiva:" << endl << endl;

        cout << "      1. Definitie" << endl << endl;

        cout << "      2. Operatii" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            def_stiva();
            break;

        case 2:
            operatii_stiva();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

// meniu stiva optiunea 1
void def_stiva() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    cout << "   Stiva - definitie\n\n\
        Stiva este o lista pentru care operatiile prin care adaugam un element sau eliminam\n\
        un element se realizeaza la acelasi capat al listei (numit varful stivei).\n\n\
        Observatie: singurele operatii permise asupra unei stive sunt adaugarea unui\n\
        element si eliminarea unui element.\n\n\
        Se noteaza cu AD x, operatia prin care se adauga un element (x) intr-o stiva\n\
        si EL, operatia prin care se elimina un element dintr-o stiva." << endl << endl;

    cout << endl << "   Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}

// meniu stiva optiunea 2
void operatii_stiva() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu opratii stiva:" << endl << endl;

        cout << "      1. Adaugarea unui element" << endl << endl;

        cout << "      2. Eliminarea unui element" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            adaugc_are_el_stiva();
            break;

        case 2:
            eliminc_are_el_stiva();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

// stiva - optiune adaugare elemente
void adaugc_are_el_stiva() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    //int v[101],
    int n, nr_el, x, val, aux;

    cout << "Cod functie:"<< endl;
    cout << "\n\
        void ad_el_stiva(int n, int &vfs, int v[], int x) { \n\
            if(vfs < n) {\n\
                vfs++;\n\
                v[vfs] = x;\n\
            } else cout << 'stiva plina';\n\
        }"\
    << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;

        if(val == 1) {

            cout << "executie: " << endl;
            if(vfs == 0) {
                do{
                    cout << "nr maxim de el: ";
                    cin >> n;
                    cout << "nr de el: "; cin >> nr_el;
                } while( nr_el > n);

                //cout << "varful stivei: " << nr_el - 1 << endl;
                //vfs = nr_el - 1;
                cout << "creare stiva: " << endl;
                creare_stiva(stiva, nr_el);
                //cout << "aici" << endl;
                afisare(n, stiva, vfs + 1);
                //cout << "aici" << endl;
            }

            cout << "val element de adaugat:"; cin >> x;
            ad_el_stiva(n, vfs, stiva, x);
            cout << endl;
            afisare(n, stiva, vfs + 1);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

//program_ad_el_stiva
void ad_el_stiva(int n, int &vfs, int v[], int x) {
        if(vfs < n) {
            if(s_are_el == 1) {
                vfs++;
                v[vfs] = x;
            } else {
                v[vfs] = x;
                s_are_el = 1;
            }

        } else cout << "stiva plina";
}

// stiva - optiunea elimnare elemente
void eliminc_are_el_stiva() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    //int v[101],
    int n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
        void el_stiva(int n, int &vfs, int v[]) {\n\
            if(vfs > 0) {\n\
                vfs = vfs - 1;\n\
            }\n\
        }"
    << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            /*
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            */
            //cout << "varful stivei: " << nr_el - 1 << endl;
            //vfs = nr_el - 1;
            //cout << "creare stiva: " << endl;
            //creare_ls(v, nr_el);
            if(s_are_el == 1) {
                nr_el = vfs + 1;
            } else {
                nr_el = 0;
            }
            cout << endl;
            el_stiva(stiva);
            //cout << endl << "stiva finala: ";
            //afisare(n, stiva, vfs + 1);

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program eliminare elemente Stiva
void el_stiva(int v[]) {
    int i;
    if(vfs > 0) {
        vfs = vfs - 1;
    } else if(s_are_el == 1) {
        s_are_el = 0;
    } else {
        cout << "nu se pot elimina elemente!" << endl;
    }

    if(s_are_el != 0) {
        cout << "stiva finala: ";
        for(i = 0; i <= vfs; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } else {
        cout << "stiva goala!!!" << endl;
    }
}


// mp Coada
void creare_coada(int v[], int i) {
    creare_ls(v, i);
    c_are_el = 1;
    bc = i - 1; // i nr elem; bc = poz pe care pot adauga un nou element;
    cout << "DBG: creare_coada: bc = " << bc << endl;
}

/*
parametrii:
    v[]:  vectorul Coada
Var globale:
    vfc: varful cozii - prima poz ocupata
    bc:  baza cozii - ultima poz ocupata
*/
void afisare_coada(int v[]) {
    int i;
    if(c_are_el == 1) {
        cout << "afisare_coada: coada: ";
        for(i = vfc; i <= bc; i++){
            cout << v[i] << " " ;
        }
        cout << endl;
    }
}

void mp_coada() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu Coada:" << endl << endl;

        cout << "      1. Definitie" << endl << endl;

        cout << "      2. Operatii" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            def_coada();
            break;

        case 2:
            operatii_coada();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

// meniu coada optiunea 1 - definitie
void def_coada() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");
    cout << "   Coada - definite " << endl << endl;
    cout << "    Coada este o lista pentru care operatia de adaugare a unui element se realizeaza pe\n\
    la un capat al listei numit baza cozii iar operatia de eliminare a unui element se realizează la\n\
    celalalt capat al listei, numit varful cozii.\n\n\
    Observatie: operatiile pe care le putem efectua asupra unei liste de tip coada sunt :\n\
    adaugarea unui element si eliminarea unui element in coada." << endl << endl;

    cout << endl << "   Apasati 'Enter' pentru a va intoarce la meniul principal" << endl;

    getch();
    getline(cin, buffer);
}

// meniu coda optiunea 2 - operatii
void operatii_coada() {
    int o;

    do {

        system("cls");

        //int rulare_program = 1;

        //afisare meniu
        cout << "Meniu opratii coada:" << endl << endl;

        cout << "      1. Adaugarea unui element" << endl << endl;

        cout << "      2. Eliminarea unui element" << endl << endl;

        cout << "      3. Revenire" << endl << endl;

        cout << " --- (alegeti cifra (1, 2, ... ) corespunzatoare optiunii dorite) ---" << endl;


        o = citeste_optiune_meniu(3);

        cout << "optiune aleasa: " << o << endl;

        switch(o) {
        case 1:
            adaugc_are_el_coada();
            break;

        case 2:
            eliminc_are_el_coada();
            break;

        case 3:
            cout << "Ati ales optiunea '3' -> revenire la meniul principal";
            break;
        }
    } while(o != 3);
}

// coada optiunea adaugare elemente
void adaugc_are_el_coada() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    //int v[101],
    int n, nr_el, x, val;

    cout << "Cod functie:"<< endl;
    cout << "\n\
        void ad_el_coda(int n, int &bc, int coada[], int x) {\n\
            if(bc < n) {\n\
                bc++;\n\
                v[bc] = x;\n\
            } else cout << 'coada plina';\n\
        }"
    << endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            if(bc == 0) {
                //coada este goala - atunci o creem
                do {
                    cout << "nr maxim de el: ";
                    cin >> n;
                    cout << "nr de el: ";
                    cin >> nr_el;
                } while( nr_el > n);

                //cout << "baza cozii: " << nr_el - 1 << endl;
                //bc = nr_el;

                cout << "creare coada: " << endl;
                creare_coada(coada, nr_el);
                cout << "DBG: adaug el. c. bc:" << bc << endl;
                cout << endl;
                afisare_coada(coada);
            }

            cout << "val element de adaugat:"; cin >> x;
            ad_el_coda(n, bc, coada, x);
            cout << endl;

            afisare_coada(coada);

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while(val != 1 && val != 0);
}

// program ad_el_coada
void ad_el_coda(int n, int &bc, int v[], int x) {
    if(bc < n) {
        //cout << "DBG: ad_el_coada: (inainte) bc: " << bc << ", vfc: " << vfc << endl;
        if(c_are_el == 1) {
            bc++;
            v[bc] = x;
        } else {
            v[bc] = x; //primul element dupa ce coada a fost goala
                       //caz particular: baza = varf si am element aici
            c_are_el = 1;
        }
        //cout << "DBG: ad_el_coada: (dupa)    bc: " << bc << ", vfc: " << vfc << endl;
    } else cout << "coada plina" << endl;
}

void eliminc_are_el_coada() {
    string buffer;
    getline(cin, buffer); // curatare buffer de intrare - tasttura. Avem ceva acolo pt ca suntem bucla meniului principal
    //afiseaza ceva
    system("cls");

    //int v[101],
    int n, x, val, nr_el;
    //int n, nr_el, x, val, bc, vfc = 0;

    cout << "Cod functie:"<< endl;
    cout << "\n\
        void el_el_coda(int n, int &vfc, int coada[], int &bc){\n\
            if(vfc < n && vfc < bc) {\n\
                vfc++;\n\
            } else cout << 'nu se pot elimina elemente';\n\
        }"<< endl << endl;

    cout << "introduceti 1 pt a executa programul" << endl;
    cout << "introduceti 0 pentru a reveni la meniu" << endl;

    do {
        cin >> val;
        if(val == 1) {
            cout << "executie: " << endl;
            /*
            do{
                cout << "nr maxim de el: ";
                cin >> n;
                cout << "nr de el: "; cin >> nr_el;
            } while( nr_el > n);
            */
            //======================================
            //trebuie sa adaug un if
            //daca baza cozii este 0 - nu am elemente
            //coada este goala, nu sterg nimic
            //======================================
            if(c_are_el == 1) {
                nr_el = bc - vfc + 1;
            } else {
                nr_el = 0;
            }
            cout << "nr elem coada: " << nr_el << endl;
            //bc = nr_el - 1;
            //cout << "creare coada: " << endl;
            //creare_ls(coada, nr_el);
            cout << endl;
            el_el_coda(coada);
            cout << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if(val == 0) {
            cout << "Apasati 'Enter' pentru a va intoarce la meniul listelor" << endl;

            getch();
            getline(cin, buffer);
            getline(cin, buffer);
        }

        if( val != 0 && val != 1) cout << "introduceti 0 sau 1" << endl;

    } while (val != 1 && val != 0);
}

// program ad_el_coada
void el_el_coda(int v[]) {
    int i;
    if(vfc < bc) {
        cout << "eliminat element: " << v[vfc] << endl;
        vfc++;
    } else if(c_are_el == 1) {
        //cazul in care vfc = bc dar am element
        //ex: adaug 1 pe poz 0, bc=vfc=0
        //am nevoie de acest if pentru a trata acest caz
        cout << "DBG: el_el_coada: vfc = " << vfc << ", bc = " << bc << " c_are_el: " << c_are_el <<endl;
        cout << "eliminat element: " << v[vfc] << endl;
        c_are_el = 0;
    } else {
        cout << "nu se pot elimina elemente" << endl;
    }

    if(c_are_el != 0) {
        cout << "coada finala: ";
        for( i = vfc; i <= bc; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    } else {
        cout << "coada este goala !!!" << endl;
    }
}

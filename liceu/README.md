[Pagina principala - proiecte](../)

## Cuprins

1. [Stiva si Coada implementate cu array](#stiva-si-coada)
1. [Grafuri neorientate](#Grafuri-neorientate)
1. [Grafuri orientate](#Grafuri-orientate)

In acest director se regasesc principalele proiectele facute in liceu la materia informatica. Acestea sunt realizate in limbajul c/c++.

In cerinta proiectului era specificat explicit ca proiectul sa fie implementat intr-un singur fiser. Acest lucru a dus la fisiere cu foarte multe linii de cod.
Pentru mentananta, este mai bine ca un program cu multe linii de cod sa fie spart in fisiere mai mici. Proiectele de fata au ramas asa cum le-am scris in liceu.

# Proiecte

## Stiva si coada 
[Cuprins](#cuprins)

[fisierul sursa](proiect_vector_stiva_si_coada.cpp)


## Grafuri neorientate
[Cuprins](#cuprins)

[fisierul sursa](proiect_grafuri_neorientate.cpp)


Proiectul descrie notiuni generale despre grafurile neorientate. Este realizat in asa fel incat sa prezinte intr-o maniera interactiva, in linia de comanda, definitii si aplicatii legate de grafuri.

Meniul principal al aplicatiei este:

      1. Definitii
      2. Gradul unui varf
      3. Metode de reprezentare
      4. Parcurgere
      5. Conexitate
      6. Graf Hamiltonian
      7. Graf Eulerian
      8. Aplicatii
      9. Test
      10. Iesire

Sunt acoperite atat teoretic cat si practic:

1. metodele de reprenzentare a grfurilor prin:
  - vector de adiacenta
  - lista de adiacenta
  - matrice de adiacenta

2. Metode de parcurgere a grafurilor neorientate:
  - parcurgere in latime
  - parcurgere in adancime

3. Notiuni de conexitate

Proiectul, de asemenea, contine si o simulare de test grila si cu completare de raspuns cu intrebari despre grafuri neorientate.

Exemplu de intrebari:

    Test de verificare a cunostintelor
    Alegeti raspunsul corect la urmatoarele intrebari, introducand cifre:
    
    Intrebarea 1. Un graf neorientat poate fi arbore numai daca:
    1) nu este conex
    2) nu contine cicluri
    3) are n muchii, unde n este numarul de varfuri
    4) contine cicluri
    
    Dati raspunsul: 2                                         // s-a selectat raspunsul 2
    apasati tasta enter pt a trece la intrebarea urmatoare
    
    punctaj: 10                                               // a fost corect si s-a primit punctajul
    
    Intrebarea 2. Un graf G=(X,U) neorientat este conex daca si numai daca:
    1) pentru orice pereche (x,y) x != y exista un lant de la x la y, x,y Γé¼ X
    2) pentru orice pereche (x,y) x !=y exista o muchie u=[x,y], u Γé¼ U
    3) pentru orice pereche (x,y) x != y exista un drum de la x la y
    4) nici un raspuns anterior nu este corect
    
    Dati raspunsul:

## Grafuri orientate
[Cuprins](#cuprins)

[fisierul sursa](proiect_grafuri_orientate.cpp)


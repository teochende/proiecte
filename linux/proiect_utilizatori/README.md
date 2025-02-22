# Proiect simulare gestiune utilizatori


## Cerinte Proiect

Proiectul final reprezinta o suita de scripturi BASH care sa cuprinda urmatoarele cerinte minime:

Simulati un sistem de management al utilizatorilor prin 3 functionalitati principale:

Inregistrarea unor utilizatori noi

presupune verificarea existentei unui utilizator cu acelasi nume, caz in care inregistrarea nu se efectueaza si se afiseaza un mesaj correspunzator

pentru utilizatorii noi, se solicita detalii precum: adresa email, parola, etc. cu validari de date specifice

inregistrarea unui utilizator nou presupune adaugarea intr-un registru .csv a detaliilor de inregistrare, autogenerarea unui ID unic, crearea unui director "home"

Simularea autentificarii utilizatorilor + logout

aceasta optiune cauta numele de utilizator in registru, si daca exista, solicita parola de access. In cazul in care parola coincide, terminalul navigheaza catre directorul "home" al utilizatorului respectiv iar in registru se actualizeaza un camp "last_login" specific fiecarui utilizator. De asemenea, in contextul de executie parinte, unui variabile array "logged_in_users" se adauga numele de utilizator

functionalitatea de logout presupune stergerea utilizatorului din lista de utilizatori autentificati

Generarea de rapoarte / utilizatori

aceasta functionalitate presupune realizarea pentru un nume de utilizator al unui raport care contorizeaza numarul de fisiere, numarul de directoare si dimensiunea pe disc a fisierelor asociate acelui utilizator. Raportul se genereaza asincron si se gaseste in directorul "home" al fiecarui utilizator.

Evaluarea proiectelor se face live si presupune prezenta tuturor membrilor echipei. Fiecare membru al echipei va primi minim 2 intrebari / solicitari referitoare la proiect. Pentru fiecare intrebare cu raspuns gresit, se scade un punct. Pentru a verifica intelegerea codului si functionarii proiectului, solicitarile pot include modificari minore, live la nivelul functionalitatilor proiectului evaluat.

Creativitatea, adica abilitatea de a include variatii si/sau caracteristici noi in raport cu cerintele minimale, va fi apreciata.




# Ce s-a facut:

 1. programul principal, interactiv in mod text care ne permite sa simulam actiunile de:
     - adaugare
     - stergere
     - afisare
     - login
     - logout
     - etc.
     - shelul aplicatiei utilizatori.sh permite si executia oricarei comenzi valide de linux.
  
  1. Din actiunle care trebuie implementate s-au implementat:
     - adaugare utilizator - cu verificare daca utilizatorul exista deja
                             `*** de implementat *** partea de adaugare director home/utilizator`
     - afisare utilizatori
     - stergere utilizator - ar fi de verificat daca utilizatorul de sters exista

  1. DE IMPLEMENTAT
     - modificare registru.csv sa contina:
         - parola utilizatorului - imediat dupa nume
         - loc pentru last login - ultimul camp din linia de utilizator
             - de vazut daca cream campul last login si-i actualizam valoarea la fiecare login
     - login
         - verificare id, parola,
         - cd in director home/utilizator,
         - adaugare in vector utilizator logat,
         - actualizare registru.csv cu data de logare - last_login
     - logout
         - stergere din vector utilizatori logati
         - iese din home
     - generare rapoarte utilizatori

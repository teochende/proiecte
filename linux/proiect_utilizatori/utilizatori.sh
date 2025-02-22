#!/bin/bash

# https://tldp.org/LDP/abs/html/loops1.html

declare -A arr_utilizatori_logati=()   # vector asociativ, poate avea cheie sir, nu doar numar
nr_u_logati=0
utilizator_curent=''

numar_fisiere=0
numar_directoare=0

# Este nevoie de aceasta variabila care sa pastreze calea proiectului
# Progranu utilizatori.sh ar trebui apelat din directorul unde se gaseste
# acest fisier. Altfel nu va functiona corect.
# Aceasta variabila va contine exact calea completa catre acest director
# adica calea incepand de la root - / - ceva de genul: 
# /home/.../proiect_utilizatori
cale_proiect=$(pwd)

afiseaza() {
    cat "$cale_proiect/registru.csv"
}

# ATENTIE:
# 0  - inseamna succes in shell - codul anterior s-a executat cu succes
# !0 - inseamna eroare
#
# de aceea if 0 / while 0 sunt echivalente cu if(1) / while (1) in "C"
#
nu_exista_utilizator() {
    #echo -n "Verificare utilizator: $1. "
    # -q = quiet - adica nu afiseaza nimic pe ecran
    if grep -q -E "^$1" "$cale_proiect/registru.csv" # -q pentru a nu se afisa nimic
    then
        return 1 # utilizatorul a fost gasit - eroare - nu-l mai putem adauga
    else
        return 0 # utilizatorul nu exista
    fi
}

# adauga <user id>
adauga() {
    echo "Adug user-ul cu id-ul: $1"
    #x=$@

    # in loc sa se dea toti parametrii functiei adauga, pentru a ne asigura ca 
    # toti parametrii sunt adaugati, se poate face in aceasta functie
    # un bloc de cod care 


    #se intra in if daca expresia din if este 0. Invers ca la C
    if nu_exista_utilizator $1
    then

        echo -n "Parola: "
        read parola

        echo -n "Nume: "
        read nume
        # de verificat ca s-a dat informatia

        echo -n "Adresa email: "
        read email
        # de verificat ca s-a dat informatia

        echo -n "Adresa: "
        read adresa
        # de verificat ca s-a dat informatia

        ####
        # de imbunatatit: inlocuire , cu ; daca se pune , in adresa, nume etc.
        ####
        echo "$1,$parola,$nume,$email,$adresa" >> "$cale_proiect/registru.csv"

        mkdir "$cale_proiect/phome/$1"

    else
        echo "EROARE: utilizatorul: $1 exista deja"
    fi

    return 0
}

sterge() {
    if nu_exista_utilizator $1
    then
        echo "!!! utilizatorul: $1 NU exista"
    else
        echo -n "Sigur vreti sa stergeti utilizatorul: $1? [da|nu (implicit nu)]: "
        read x
        if [[ "$x" = "da" ]]
        then
            echo "sterge $1"
            sed -i "/^$1,/d" "$cale_proiect/registru.csv"
            rm -rf phome/$1
        else
            echo "Nu s-a sters utilizatorul $1"
        fi
    fi

    return 0
}

login() {
    if nu_exista_utilizator $1
    then
        echo "!!! utilizatorul: $1 NU exista"
    else
        echo -n "Parola: "
        read parola_user
        #echo "ati tastat: $parola_user"

        # format registru:
        #teo,mar,Teodora Chende, teodora@gmail.com, bucuresti
        #alexa, iepure, Alexa Caramizaru, alexa@gmail.com, Bucuresti

        pass=$(grep -E "^$1" "$cale_proiect/registru.csv" | awk -F ", ?" '{print $2}')
        #echo "pass in fisier: $pass"

        if [ $parola_user == $pass ]
        then
            echo "LOGIN OK $1"
            let nr_u_logati++
            arr_utilizatori_logati[$1]=1  # adaugare utilizator in vector:
                                          # cheia - nume utilizator, valoare 1
            utilizator_curent=$1          # actualizare utilizator curent
            cd "$cale_proiect/phome/$1"   # schimbare director

            # Identific cu grep partea din linia de utilizator din registru
            # pana la amprenta de timp 
            # -E (extende regesp) -o (afiseaza doar) partea din linie care
            #  se potriveste cu expresia de dupa -Eo
            # cauta sablonul / pattern-ul in fisierul registru.csv din calea
            # proiectului
            date_utilizator=$(grep -Eo "^$1,(.*,)*" "$cale_proiect/registru.csv")
            #echo "date utilizator: $date_utilizator"

            # generare amprenta de timp cu comanda date.
            amprenta_timp=$(date +%Y-%m-%d_%H:%M:%S:%3N)
            #echo "ampranta timp: $amprenta_timp"
            
            # am adaugat la sfarsit si ultimele 3 cifre din nanosecunde
            # pot fi utilizatori care se conecteaza in aceeasi secunda
            # nanosecundele ajuta la diferentiere
            #
            # Expresia: /^$1,.*/ in seamna toata linia
            #    - sa inceapa cu id-ul utilizatorului si ,
            #    - .* orice ori de cate ori
            # Intreaga linie este apoi inlocuita cu:
            #  date_utilizator - linia fara partea finala - amprenta de timp
            #    concatenate cu
            #  amprenta_timp - amprenta de timp generata mai sus
            sed -i "s/^$1,.*/$date_utilizator$amprenta_timp/" "$cale_proiect/registru.csv"

        else
            echo "Parola incorecta!"
        fi
    fi

    return 0
}

logout() {
    #echo "Functia logout"
    #echo "Numar utilizatori logati: $nr_u_logati"
    #echo "Utilizatori conectati: ${arr_utilizatori_logati[@]}"
    #echo "Chei array: ${!arr_utilizatori_logati[@]}"

    # pentru logout trebuie facut unset la elementul din vector care are 
    # cheie chiar numele utilizatorului curent
    unset arr_utilizatori_logati[$utilizator_curent]
    for u in ${!arr_utilizatori_logati[@]}
    do
        # facem utilizatorul curent urmatorul utilizator din vectorul
        # de utilizatori conectati
        utilizator_curent=$u
        cd "$cale_proiect/phome/$u"
        break
    done

    if [[ ${#arr_utilizatori_logati[@]} -eq 0 ]]
    then
        utilizator_curent=''
        cd "$cale_proiect"
    fi
}

schimbautilizator() {
    if [[ $1 == '' ]]
    then
        # cu return 1 - am eroare in while datorita erorii de evaluare
        #return 1 # erorare, utilizator nepermis

        # folosesc return 0 si dau un mesaj de atentionare
        echo "EROARE: nu s-a specificat noul utilizator"
        echo "Utilizare:"
        echo "schimbautilizator <id utilizator nou>"
        return 0
    fi

    if [[ arr_utilizatori_logati[$1] -eq 1 ]]
    then
        utilizator_curent=$1
        cd "$cale_proiect/phome/$1"
    else
        login $1
    fi
}

cinesunteu() {
    echo "$utilizator_curent"
}

cinesuntlogati() {
    echo "Utilizatori conectati:"
    # ${arr...[@]}  - valorile din vector
    # ${!arr...[@]} - cheile din vector
    # vectorul folosit este unul asociativ - are ca si chei numele utilizatorului
    # valoarea din vector este 1 si se adauga la login-ul utilizatorului
    # ex: login teo  --- duce la -> arr_utilizatori_logati['teo']=1
    #     logout teo --- se sterge intrarea in vector: unset arr_utilizatori_logati['teo']
    for u in ${!arr_utilizatori_logati[@]}
    do
        echo "$u"
    done
}

: '
    --- Comentariu pe mai multe linii ---
    Functie recursiva care parcurge toate directoarele din directorul dat
    ca parametru si incrementeaza variabilele globale:
     - numar_fisiere
     - numar_directoare

    Functie interna, ajutatoare, pentru a fi apelata in alta functie
'
gaseste_numar_directoare_fisiere() {
    rez_ls=$(ls -a $1) # cu -a pentru a lista si fisierele/directoarele ascunse - care incep cu .
    for el in $rez_ls
    do
        if [ "$el" = "." ] || [ "$el" = ".." ]
        then
            # ignoram directoarele . si .. din fiecare director
            # pentru a evita o bucla infinita
            continue
        fi
        
        cale_nume="$1/$el"
        #echo "DBG. cale_nume: $cale_nume"

        if [ -d "$cale_nume" ]
        then
            #echo "director: $cale_nume"
            gaseste_numar_directoare_fisiere $cale_nume
            let numar_directoare++
        elif [ -f "$cale_nume" ]
        then
            #echo "--- fisier: $cale_nume"
            let numar_fisiere++
        elif [ -h "$cale_nume" ]
        then
            echo "--- link: $cale_nume"
        fi
    done
}

genereaza_raport() {
    # reset contoare
    numar_fisiere=0
    numar_directoare=0

    # gasesc spatiul ocupat
    spatiu_ocupat=$(du -sh $cale_proiect/phome/$utilizator_curent)
    
    # gasesc numarul de fisiere si directoare
    # prin apelul functiei ajutatoare - functia recursiva
    gaseste_numar_directoare_fisiere $cale_proiect/phome/$utilizator_curent
    
    # generez raport
    echo "Raport actualizat: $(date)" > $cale_proiect/phome/$utilizator_curent/raport.txt
    echo "Directorul: $cale_proiect/phome/$utilizator_curent" >> $cale_proiect/phome/$utilizator_curent/raport.txt
    echo "Contine: " >> $cale_proiect/phome/$utilizator_curent/raport.txt
    echo "$numar_directoare, directoare" >> $cale_proiect/phome/$utilizator_curent/raport.txt
    echo "$numar_fisiere, fisiere" >> $cale_proiect/phome/$utilizator_curent/raport.txt
    echo "Spatiu ocupat pe hard-disk: $(echo \"$spatiu_ocupat\" | awk '{print $1}')" >> $cale_proiect/phome/$utilizator_curent/raport.txt
}


vezi_raport() {
    echo "RAPORT:"
    echo "$(cat $cale_proiect/phome/$utilizator_curent/raport.txt)"
}

ajutor() {
    echo ""
    echo "COMENZI:"
    echo ""
    echo "afiseaza                             Afiseaza toti utilizatorii"
    echo "adauga <id utilizator>               Adauga un nou utilizator"
    echo "sterge <id utilizator>               Sterge utilizatorul cu id-ul primit ca parametru"
    echo "login <id utilizator>                Conecteaza utiizatorul."
    echo "logout                               Deconecteaza utilizator curent."
    echo "schimbautilizator <id utilizator>    Schimba utilizatorul curent cu alt utilizator logat"
    echo "cinesunteu                           Afiseaza utilizatorul curent"
    echo "cinesuntlogati                       Afiseaza utilizatorii conectati"
    echo "genereaza_raport                     Genereaza raportul pentru utilizatorul curent"
    echo "vezi_raport                          Vizualizeaza raportul pentru utilizatorul curent"
    echo ""
    echo "ajutor                         Afiseaza comenzile disponibile"
    echo "iesire                         Terminare program"
    echo ""
    echo "<orice comanda shell valida>   ex: cd / ls / ls -la ..."
    echo "*** Exemple comenzi shell ***"
    echo "pwd                            afiseaza directorul curent"
    echo "ls  / ls -la                   afiseaza continutul directorului"
    echo "cd <nume director>             schimba directorul curent"
    echo ""
    return 0
}

while [ 0 ]                           #https://tldp.org/LDP/abs/html/loops1.html
do
    echo -n "proiect-utilizatori:$utilizator_curent> "
    read x
    if [[ "$x" = "iesire" ]]           #https://tldp.org/LDP/abs/html/comparison-ops.html
    then
        break
    else
        if [ "$x" = "genereaza_raport" ]
        then
            echo "Executie asincrona - cu & la sfarsitul comenzii"
            eval $x &
        elif eval $x                     # interpreteaza x ca si comanda si incearca sa execute
        then
            echo -n ""                   # nu afisez nimic doar nu las ramura if fara comanda
        else
            echo "Comanda invalida: $x. Tastati 'ajutor' pentru a vedea comenzile"
        fi
    fi

done
exit 0
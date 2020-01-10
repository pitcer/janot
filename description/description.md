# Projekt ze Wstępu do Programowania w Języku C

## Motywacja

Jednym z powodów, dla których wybrałem kurs języka C, była chęć poznania języka natywnie kompilowanego, umożliwiającego głębszą interakcję z systemem operacyjnym. Jest to dla mnie niezwykle istotne ze względu na to, że Java - język w którym programuję - nie udostępnia zbyt wielu takich funkcji. Istnieje jednak możliwość dodania do Javy natywnych metod zaimplementowanych w C, jednak brak znajomości tego języka dotychczas mi to uniemożliwiał. Teraz dzięki kursowi poznałem C w wystarczającym stopniu, aby móc napisać bibliotekę rozszerzającą Javę o nowe natywne metody. Stwierdziłem, że projekt końcowy to idealny moment, aby podjąć się tego wyzwania.

## Projekt

### Nazwa

Wybrałem nazwę **Janot**, co miało być skrótem od **Java notifications**, gdyż początkowo chciałem zawrzeć w projekcie jedynie obsługę powiadomień systemowych. Okazało się, że jest to dosyć skromna ilość funkcji, więc postanowiłem dodać kolejne. Nie chciałem już jednak zmieniać nazwy repozytorium, więc zostawiłem starą nazwę.

### Działanie

Projekt oparty jest na frameworku **JNI** (Java Native Interface), który umożliwia wywoływanie funkcji napisanych w języku C z poziomu JVM (Java Virtual Machine). Na podstawie zadeklarowanych w Javie metod natywnych, generuje on odpowiadające im pliki nagłówkowe C. Następnie trzeba napisać definicje zadeklarowanych tam funkcji. W procesie kompilacji zostanie utworzony plik `libjanot-native.so` zawierający skompilowany kod C, który następnie trzeba umieścić np. w tym samym folderze co plik wykonywalny Javy, zawierający bibliotekę. Ostatecznie należy uruchomić program z flagą `-Djava.library.path=.`, która ustawia ścieżkę do folderu, zawierającego biblioteki natywne.

### Struktura

Janot to biblioteka złożona z trzech modułów:

* **janot-jvm**
    * Zawiera pliki źródłowe Javy z deklaracjami natywnych metod
    * Będzie używany przez języki kompatybilne z JVM jako biblioteka
* **janot-native**
    * Zawiera pliki źródłowe C razem z ich nagłówkami
    * Pliki zawierają implementacje natywnych metod z modułu poprzedniego modułu
* **janot-example**
    * Zawiera przykłady użycia biblioteki

Struktura projektu zarządzana jest przez **Gradle**, czyli narzędzie umożliwiające automatyzację procesu budowania. Dodaje on między innymi wybrane flagi GCC, dołącza biblioteki oraz kompiluje wszystkie moduły projektu jednym prostym poleceniem.

### Funkcje

Biblioteka ma za zadanie udostępnić programiście różne, niedostępne w Javie funkcje systemowe.

* Funkcje umożliwiające wysyłanie powiadomień systemowych, dostępne w C przez bibliotekę `libnotify`
    * Ustawianie tytułu, opisu, ikony, czasu wyświetlania
* Funkcje umożliwiające tworzenie prostych aplikacji okienkowych, dostępne w C przez bibliotekę `gtk-3.0`
    * Tworzenie okien
    * Dodawanie do okien elementów takich jak przyciski
    * Obsługa wydarzeń

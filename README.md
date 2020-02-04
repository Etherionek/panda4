# Program rozwiązauje podane niżej zadanie oparte na algorytmie B-drzewa

## Treść
Janusz dobry mąż i ojciec postanowił zabrać swoją całą rodzinę na wycieczkę. Wymyślił, że pojadą na spływ kajakami nad Wieprzem w miejscowości Zwierzyniec. Niestety zanim wyruszyli powstał pewien spór pomiędzy członkami rodziny. Nie mogli ustalić listy utworów, które będą im towarzyszyć podczas trasy. Każdy notował wybrane przez siebie utwory na kartce przygotowanej przez Janusza. Niestety dochodziło do sytuacji, gdy jeden członek rodziny skreślał utwory innego, co wzmacniało spór. I tak niektóre utwory były usuwane i dodawane po kilka razy..., a jak pamiętamy Janusz jest bardzo oszczędny i ciągłe marnowanie papieru na kolejne listy utworów doprowadziło go do szewskiej pasji. W związku z powyższym postanowił poprosić Cię o pomoc. Twoim zadaniem jest stworzyć program, który pozwoli modyfikować listę przebojów.

Należy zastosować B-drzewa, dzięki którym wszystkie dane o utworach łatwo zostaną zapisane na dysku twardym. Ponadto Janusz zasugerował, żeby utwory automatycznie ustawiały się w kolejności od najpopularniejszego do tych mniej popularnych. Wskaźnik popularności reprezentowany jest przez unikalne miejsce na światowej liście przebojów. Nasz bohater aby utrudnić innym ciągłe usuwanie utworów poprosił, aby napisany przez Ciebie program wyszukiwał utworów po ich popularności a nie po nazwie.

## WEJŚCIE

Algorytm na wejściu otrzymuje liczbę naturalną N, która mówi o liczbie operacji naszego algorytmu. Operacje dzielimy na A, R oraz S:

A - jest to operacja dodania utworu do naszej listy. W tej operacji algorytm powinien wczytać sekwencję wartości X S, gdzie X jest liczbą naturalną i wskazuje popularność utworu, a S to jednowyrazowa nazwa utworu.

R - jest to operacja usunięcia utworu o wskazanej popularności. W tej operacji algorytm powinien wczytać jedną liczbę naturalną, będącą popularnością utworu.

S - jest to operacja sprawdzania, czy utwór o wskazanej popularności znajduje się na liście. W tej operacji algorytm powinien wczytać jedną liczbę naturalną, będącą popularnością utworu.

## WYJŚCIE

Dla każdej operacji S algorytm powinien wyświetlić odpowiedź:

- jeśli znalazł utwór o danej popularności, powinien wyświetlić nazwę utworu,

- jeśli nie znalazł utworu spełniającego wymagań popularności, powinien wyświetlić '-'.

### PRZYKŁADOWE WEJŚCIE

7

A 11 Utwor1

A 311 Utwor2

S 11

A 12 Utwor3

R 11

S 11

S 12

### PRZYKŁADOWE WYJŚCIE
Utwor1

\-

Utwor3

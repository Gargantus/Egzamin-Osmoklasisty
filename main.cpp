#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

char *tr(char *str)
{
   static char buff[256];
   char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215����󜿟��ʣ�ӌ��";
   if(strlen(str)>=sizeof(buff)) return str;
   char *bf=buff;
   while(*str)
     {
      char *pos=strchr(cp+18,*str);
      *(bf++)=pos?*(pos-18):*str;
      ++str;
     }
   *bf=0;
   return buff;
}

int Segment = 6;

string Przeciwnik;
int Poziom = 1;
int Zycie = 1;
int Zdrowie;
int Magia = 1;
int Sila = 3;
int Wytrzymalosc = 1;
int Szczescie = 1;

int PoziomP;
int PZdrowie;
int PZycie;
int PMagia;
int PSila;
int PWytrzymalosc;
int PSzczescie;
int WstecznePZdrowie;
char wybor;
int i;
int losuj(int l)
{
    srand(time(NULL));
    int liczba = rand()%l+1;
    return liczba;
}
void tekst(string t)
{
    for (i=0; i<t.length(); ++i)
    {
        Sleep(25);
        cout << t.at(i);
    }
    Sleep(1000);
    cout << endl;
}

void walka(string Nazwa,int Poziom)
{
    cout << endl;
    cout << "Atakuje ciebie "<<Nazwa<< " na poziomie " <<Poziom<<"."<<endl;
    cout << endl;
    int Tura = 1;
    while ((Tura != 3) && (Zdrowie != 0))
    {
    //Wyb�r ruchu
    while (Tura == 1)
    {
    cout << "Twoja tura"<<endl;
    cout << "Wybierz ruch"<<endl;
    cout << "1. Ataki"<<endl;
    cout << tr("2. Umiej�tno�ci")<<endl;
    cout << "3. Przedmioty"<<endl;
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    wybor = getch();
    system("cls");
    switch(wybor)
    {
    case '1':
    Tura = 4;
    break;
    case '2':
    cout << tr("Wybierz umiej�tno��")<<endl;
    cout << "Brak XD"<<endl;
    break;
    case '3':
    cout << "Wybierz przedmiot"<<endl;
    cout << "Brak XD"<<endl;
    break;
    default:
    tekst(tr("Nie wiem o co ci chodzi, naucz si� czyta�."));
    break;
    }
    }
    //Ataki fizyczne
    while (Tura == 4)
    {
        cout <<tr("Wybierz atak fizyczny.")<<endl;
        cout <<tr("Wpisz drug� liczb� aby sprawdzi� jego opis.")<<endl;
        cout <<tr("1,4. Szybki atak")<<endl;
        cout <<tr("2,5. Ci�ki atak")<<endl;
        cout <<tr("3,6. Szcz�liwy atak")<<endl;
        Tura = 5;
    }
    while (Tura == 5)
    {
        WstecznePZdrowie = PZdrowie;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        switch(wybor)
        {
        case'1':
        PZdrowie = PZdrowie - Sila*2;
        Tura = 6;
        break;
        case'2':
        if (losuj(100) > 50)
        {
        PZdrowie = PZdrowie - Sila*4;
        }
        Tura = 6;
        break;
        case'3':
        if (losuj(100) < 11)
        {
        PZdrowie = PZdrowie/2;
        }
        Tura = 6;
        break;
        case'4':
        cout <<tr("Ma�o zadaje, ale masz 100% szans na trafienie.")<<endl;
        break;
        case'5':
        cout <<tr("Zadaje dwa razy wi�cej obra�e� od szybkiego ataku, ale masz tylko 50% szans na trafienie.")<<endl;
        break;
        case'6':
        cout <<tr("Odbiera po�ow� zdrowia przeciwnikowi, ekstremalnie ma�e szanse na trafienie.")<<endl;
        break;
        }
    }
    while (Tura == 6)
    {
        system("cls");
        if (PZdrowie < 0)
        {
        PZdrowie = 0;
        }
        if (WstecznePZdrowie-PZdrowie != 0)
        {
        cout << tr("Zadano ")<<WstecznePZdrowie-PZdrowie;
        cout << tr(" punkt�w obra�e�.")<<endl;
        cout <<Nazwa<<tr(" ma teraz ")<<PZdrowie;
        cout <<tr(" punkty zdrowia.")<<endl;
        }
        else
        {
        cout << tr("Chybi�e� noobie");
        }
        if (PZdrowie < 1)
        {
        cout << tr("Wygra�e�!")<<endl;
        Tura = 3;
        }
        else
        {
        Tura = 2;
        Sleep(4000);
        }
    }
    //Tura przeciwnika
    while (Tura == 2)
    {
    system("cls");
    cout << "Tura przeciwnika"<<endl;
    cout << tr("Przeciwnik u�ywa ataku fizycznego")<<endl;
    Zdrowie = Zdrowie - PSila*3;
    if (Zdrowie < 0)
    {
        Zdrowie = 0;
    }
    cout <<Nazwa<<tr(" zada� ci ")<<Zdrowie + PSila*3 - Zdrowie;
    cout <<tr(" punkt�w obra�e�")<<endl;
    cout <<tr("Zosta�o ci ")<<Zdrowie;
    cout <<tr(" punkt�w zdrowia.");
    Sleep(4000);
    Tura = 1;
    system("cls");
    }
    }
    if (Zdrowie == 0)
    {
        if (Nazwa != "Hans")
        {
            cout <<"Umierasz, cofamy czas."<<endl;
            Sleep(2000);
            system("cls");
        }
    }
}

int main()
{
    while (Segment == 0)
    {
    tekst(tr("19 kwietnia 2019"));
    tekst(tr("Budzisz si� po koszmarze z nauczycielk� matematyki."));
    tekst(tr("Przypominasz sobie, �e za 5 minut masz egzamin z polskiego."));
    tekst(tr("W b�yskawicznym tempie zjadasz �niadanie, myjesz z�by i ubierasz si� w garnitur."));
    tekst(tr("Wychodzisz na szybko�ci z mieszkania."));
    tekst(tr("Na klatce zauwa�asz swojego niemieckiego s�siada - Hansa."));
    tekst(tr("Wiesz, �e jest on narkomanem i mama kaza�a ci nic od niego nie bra�."));
    tekst(tr("Proponuje on ci za�ycie narkotyku, jak to on nazywa UberNarkotiken."));
    Segment = 1;
    }
    while (Segment == 1)
    {
    tekst(tr("Za�ywasz, czy odmawiasz?"));
    tekst(tr("1. Za�yj UberNarkotiken"));
    tekst(tr("2. Odm�w Hansowi"));
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    wybor=getch();
    system("cls");

    switch(wybor)
    {
        case'1':
        tekst(tr("Hans podaje ci narkotyk."));
        tekst(tr("Wk�adasz tabletk� z narkotykiem do ust."));
        tekst(tr("Nagle widzisz obrazy przedstawiaj�ce wielkie Niemcy."));
        tekst(tr("Padasz nieprzytomny."));
        Segment = 2;
        break;
        case '2':
        tekst(tr("Hans jest oburzony tym, �e mu odm�wi�e�."));
        tekst(tr("W ramach kary za niepos�usze�stwo idzie ciebie pobi�."));
        Zdrowie = 10*Zycie;
        Przeciwnik = "Hans";
        PoziomP = 99;
        PZdrowie = 999;
        PMagia = 99;
        PSila = 99;
        PWytrzymalosc = 99;
        PSzczescie = 99;
        PZycie = PZdrowie * 5;
        walka(Przeciwnik,PoziomP);
        tekst(tr("Tracisz przytomno��."));
        Segment = 2;
        break;
        default:
        tekst(tr("Nie wiem o co ci chodzi, naucz si� czyta�."));
        break;
    }
    }
    while (Segment == 2)
    {
        tekst(tr("Mija kilka minut."));
        tekst(tr("Budzisz si� na klatce, Hansa ju� nie ma."));
        tekst(tr("Patrzysz na zegarek i widzisz, �e wskaz�wki si� nie ruszaj�."));
        tekst(tr("Pewnie baterie si� wyczerpa�y."));
        tekst(tr("Wychodzisz z bloku i widzisz d�ungl�."));
        tekst(tr("Nie mo�esz si� doczeka� spotkania z tarzanem."));
        tekst(tr("Jednak dziwi ci� fakt, �e w mie�cie jest d�ungla."));
        tekst(tr("Nagle zacz�� ci burcze� brzuch."));
        tekst(tr("Powiniene� co� zje��."));
        Segment = 3;
    }
    while (Segment == 3)
    {
        tekst(tr("Co robisz?"));
        tekst(tr("1. Bierzesz banany z drzewa."));
        tekst(tr("2. Kradniesz banany ma�pie."));
        tekst(tr("3. Dokonujesz degustacji skolopendry."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch (wybor)
        {
            case'1':
            tekst(tr("Przygl�dasz si� bananom na drzewie."));
            tekst(tr("W przesz�o�ci uprawia�e� parkour, wi�c z �atwo�ci� wspinasz si� na bananowca."));
            tekst(tr("Zrywasz i po�ykasz banany w ca�o�ci."));
            tekst(tr("Zauwa�asz burzowe chmury nad tob�."));
            tekst(tr("Trafia w ciebie piorun."));
            tekst(tr("Spadasz na ziemi�."));
            tekst(tr("Nagle przychodzi w�dz plemienia Ikitiki i ka�e ciebie usma�y� na kotleta."));
            tekst(tr("Owijaj� ci r�ce i zabieraj� do swojej wioski."));
            Segment = 4;
            break;
            case'2':
            tekst(tr("Patrzysz si� na ma�p�."));
            tekst(tr("Ma�pa patrzy si� na ciebie."));
            tekst(tr("Podchodzisz do niej i wyzywasz j� na solo."));
            tekst(tr("Nie zauwa�y�e� �e to goryl, ale co tam."));
            Zdrowie = 10*Zycie;
            Przeciwnik = "Goryl";
            PoziomP = 6;
            PZdrowie = 20;
            PMagia = 0;
            PSila = 99999;
            PWytrzymalosc = 1;
            PSzczescie = 2;
            PZycie = PZdrowie * 5;
            walka(Przeciwnik,PoziomP);
            if (Zdrowie != 0)
            {
            tekst(tr("Pokona�e� goryla i zjad�e� jego banany."));
            tekst(tr("Wtedy przychodzi w�dz plemienia Ikitiki i m�wi, �e by�o to ich zwierz� domowe."));
            tekst(tr("Otaczaj� ciebie tubylcy i zabieraj� do wioski, �eby zrobi� z ciebie kotleta."));
            Segment = 4;
            }
            break;
            case'3':
            tekst(tr("Schylasz si� i podnosisz skolopendr� z ziemi."));
            tekst(tr("Powoli wk�adasz j� do gard�a."));
            tekst(tr("Nawet nie musia�e� jej po�yka�, sama wesz�a."));
            tekst(tr("Nagle poczu�e� dziwne sw�dzenie w �o��dku."));
            tekst(tr("To skolopendra przedziurawi�a ci brzuch."));
            tekst(tr("A��."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz si� czyta�."));
            break;
        }
    }
    while (Segment == 4)
    {
        tekst(tr("Tubylcy przyprowadzili ciebie do wioski Ikitiki."));
        tekst(tr("Przywi�zuj� ciebie do pala i stawiaj� nad ogniem."));
        tekst(tr("Zawsze chcia�e� by� opalony jak koledzy."));
        tekst(tr("Nagle tubylcy zacz�li ta�czy� default dance."));
        tekst(tr("Fortnite to twoja ulubiona gra, wi�c cieszy ciebie ten widok."));
        tekst(tr("Po sko�czonym ta�cu tubylcy przynie�li t�uczone ziemniaki i buraczki."));
        tekst(tr("Posypuj� ciebie bu�k� tart� i jajkiem."));
        tekst(tr("Czujesz ju� jak ci si� zw�glaj� plecy."));
        Segment = 5;
    }
    while (Segment == 5)
    {
        tekst(tr("Co robisz?"));
        tekst(tr("1. Prosisz o ziemniaczki na spr�bowanie."));
        tekst(tr("2. Napadasz na tubylc�w za pomoc� bala."));
        tekst(tr("3. Zjadasz sobie kotleta."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch(wybor)
        {
            case'1':
            tekst(tr("Tubylcy zgadzaj� si� na twoje ostatnie �yczenie."));
            tekst(tr("Zjadasz �y�k� ziemniaczk�w."));
            tekst(tr("Nagle czujesz przyp�yw si�y i energii ze zjedzonych bulw."));
            tekst(tr("Robisz si� trzy razy wi�kszy od tubylc�w, a twoje mi�snie s� teraz wi�ksze od nich samych."));
            tekst(tr("Zgniatasz wszystkich tubylc�w opr�cz wodza za pomoc� kciuka."));
            tekst(tr("Pytasz si� zap�akanego wodza gdzie jest droga do szko�y."));
            tekst(tr("Zaleca ci wej�� na g�r� Bingobongo i si� rozej�e�."));
            tekst(tr("Idziesz w stron� g�ry, w mi�dzyczasie twoje cia�o wr�ci�o do normy."));
            tekst(tr("Jeste� u st�p g�ry Ikitiki."));
            tekst(tr("Jest to bardzo stroma g�ra, b�dziesz potrzebowa� jakiego� sprz�tu."));
            tekst(tr("Na ziemi le�y kotwiczka, czapka z helikopterkiem i kartk� z cheatami."));
            Segment = 6;
            break;
            case'2':
            tekst(tr("Wyzwalasz si� z lin i bierzesz bal do r�ki."));
            tekst(tr("Masz szcz�cie, �e tubylcy s� zaj�ci jedzeniem twojego ucha i nic nie widz�."));
            tekst(tr("Tylko jeden ciebie zauwa�a i leci na ciebie z toporem."));
            tekst(tr("Tutaj wstaw walk�."));
            tekst(tr("Po pokonaniu tubylcy z toporem zakrad�e� si� ko�o wodza wioski i ukrad�e� mu map�"));
            tekst(tr("Postanowi�e� uda� si� na g�r� Ikitiki, aby si� rozejrze�."));
            tekst(tr("Jeste� u st�p g�ry Ikitiki."));
            tekst(tr("Jest to bardzo stroma g�ra, b�dziesz potrzebowa� jakiego� sprz�tu."));
            tekst(tr("Na ziemi le�y kotwiczka, czapka z helikopterkiem i kartk� z cheatami."));
            Segment = 6;
            break;
            case'3':
            tekst(tr("Nic nie robisz, czekasz a� tubylcy przygotuj� kotleta."));
            tekst(tr("Po paru minutach daj� ci palec serdeczny do zjedzenia."));
            tekst(tr("Nawet dobry."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz si� czyta�."));
            break;
        }
    }
    while (Segment == 6)
    {

        tekst(tr("Co robisz?"));
        tekst(tr("1. Wspinasz si� za pomoc� kotwiczki."));
        tekst(tr("2. Wlatujesz na g�r� helikopterkiem."));
        tekst(tr("3. U�ywasz cheat�w."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch(wybor)
        {
            case'1':
            tekst(tr("Pr�bujesz dorzuci� kotwiczk� na jak�kolwiek ska��."));
            tekst(tr("Niestety Ikitiki jest codziennie sprz�tana przez lokalnych tubylc�w przez co nie ma tu ani jednej ska�y."));
            tekst(tr("Zacz��e� kopa� g�r� kotwiczk�."));
            tekst(tr("Dokopa�e� si� na sam szczyt."));
            break;
            case'2':
            tekst(tr("Zak�adasz czapk� na g�ow�."));
            tekst(tr("Lecisz sobie w g�r�."));
            tekst(tr("Nagle do twojej czapki dociera komunikat od wojsk lotniczych Ugabugastanu."));
            tekst(tr("Naruszy�e� ich przestrze� powietrzn�."));
            tekst(tr("Ty masz to w jamie nosowej."));
            tekst(tr("Nagle podlatuje murzyn przywi�zany do dw�ch balon�w i mierzy do ciebie z kamienia."));
            tekst(tr("Tutaj wstaw walk�."));
            tekst(tr("Str�ci�e� balony pilota, kt�ry spad� i zwichn�� sobie kostk�."));
            tekst(tr("Bez przeszk�d dolecia�e� na szczyt."));
            break;
            case'3':
            tekst(tr("W��czasz konsol� programu."));
            tekst(tr("Sv cheats on"));
            tekst(tr("Godmode on"));
            tekst(tr("Teleportujesz si� na szczyt g�ry."));
            tekst(tr("Nie zauwa�y�e�, �e admin jest na serwie."));
            tekst(tr("Dosta�e� bana za cheatowanie."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz si� czyta�."));
            break;
        }
    }
    return 0;
}

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
   char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯";
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

int Segment = 9;

string Przeciwnik;
int Poziom = 1;
int Zycie = 10;
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
    float Tura = 1;
    int Zatrucie = 3;
    int Wzmocnienie = 1;
    int Czas = 0;
    while ((Tura != 3) && (Zdrowie != 0))
    {
    //Wybór ruchu
    while (Tura == 1)
    {
    cout << "Twoja tura"<<endl;
    cout << "Wybierz ruch"<<endl;
    cout << "1. Ataki"<<endl;
    if (Czas == 0)
    {
    cout << tr("2. Umiejêtnoœci")<<endl;
    }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    wybor = getch();
    system("cls");
    if (Czas == 0)
    {
    switch(wybor)
    {
    case '1':
    Tura = 4;
    break;
    case '2':
    Tura = 4.5;
    break;
    default:
    tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
    break;
    }
    } else
    {
    switch(wybor)
    {
    case '1':
    Tura = 4;
    break;
    default:
    tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
    break;
    }
    }
    }
    //Umiejêtnoœci
    while (Tura == 4.5)
    {
        cout <<tr("Wybierz umiejêtnoœæ.")<<endl;
        cout <<tr("Wpisz drug¹ liczbê aby sprawdziæ jej opis.")<<endl;
        cout <<tr("Umiejêtnoœci mo¿esz u¿yæ tylko raz na trzy tury")<<endl;
        cout <<tr("1,4. Leczenie")<<endl;
        cout <<tr("2,5. Zatrucie")<<endl;
        cout <<tr("3,6. Uczenie siê")<<endl;
        Tura = 5.5;
    }
    //Ataki fizyczne
    while (Tura == 4)
    {
        cout <<tr("Wybierz atak fizyczny.")<<endl;
        cout <<tr("Wpisz drug¹ liczbê aby sprawdziæ jego opis.")<<endl;
        cout <<tr("1,4. Szybki atak")<<endl;
        cout <<tr("2,5. Ciê¿ki atak")<<endl;
        cout <<tr("3,6. Szczêœliwy atak")<<endl;
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
        PZdrowie = PZdrowie - Sila*2*Wzmocnienie-Zatrucie;
        Tura = 6;
        break;
        case'2':
        if (losuj(100) > 50)
        {
        PZdrowie = PZdrowie - Sila*4*Wzmocnienie-Zatrucie;
        }
        Tura = 6;
        break;
        case'3':
        if (losuj(100) < 11)
        {
        PZdrowie = PZdrowie/2/Wzmocnienie-Zatrucie;
        }
        Tura = 6;
        break;
        case'4':
        cout <<tr("Ma³o zadaje, ale masz 100% szans na trafienie.")<<endl;
        break;
        case'5':
        cout <<tr("Zadaje dwa razy wiêcej obra¿eñ od szybkiego ataku, ale masz tylko 50% szans na trafienie.")<<endl;
        break;
        case'6':
        cout <<tr("Odbiera po³owê zdrowia przeciwnikowi, ekstremalnie ma³e szanse na trafienie.")<<endl;
        break;
        }
    }
    while (Tura == 5.5)
    {
        WstecznePZdrowie = PZdrowie;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        switch (wybor)
        {
        case'1':
        Zdrowie += 50;
        if (Zdrowie > 100)
        {
            Zdrowie = 100;
        }
        Czas = 3;
        Tura = 6;
        break;
        case'2':
        Zatrucie = 3;
        PZdrowie -= Zatrucie;
        Czas = 3;
        Tura = 6;
        break;
        case'3':
        Wzmocnienie = 1.5;
        Czas = 3;
        Tura = 6;
        break;
        case'4':
        cout << tr("Odnawia po³owê twojego zdrowia.")<<endl;
        break;
        case'5':
        cout << tr("Zadawaj przeciwnikowi trzy punkty obra¿eñ co turê.")<<endl;
        break;
        case'6':
        cout << tr("Zwiêksz sobie atak pó³torej razy na trzy tury.")<<endl;
        break;
        default:
        tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
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
        cout << tr(" punktów obra¿eñ.")<<endl;
        cout <<Nazwa<<tr(" ma teraz ")<<PZdrowie;
        cout <<tr(" punkty zdrowia.")<<endl;
        }
        else
        {
            if (Czas != 3)
            {
                cout << tr("Chybi³eœ noobie");
            }
            else
            {
                cout << tr("Czekasz");
            }

        }
        if (PZdrowie < 1)
        {
        cout << tr("Wygra³eœ!")<<endl;
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
    cout << tr("Przeciwnik u¿ywa ataku fizycznego")<<endl;
    Zdrowie = Zdrowie - PSila*3;
    if (Zdrowie < 0)
    {
        Zdrowie = 0;
    }
    cout <<Nazwa<<tr(" zada³ ci ")<<Zdrowie + PSila*3 - Zdrowie;
    cout <<tr(" punktów obra¿eñ")<<endl;
    cout <<tr("Zosta³o ci ")<<Zdrowie;
    cout <<tr(" punktów zdrowia.");
    Sleep(4000);
    Tura = 1;
    system("cls");
    }
    if (Czas != 0)
    {
        Czas -= 1;
    }
    if (Czas == 0)
    {
        Wzmocnienie = 1;
    }
    if (Czas == 0)
    {
        Zatrucie = 0;
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
    tekst(tr("Budzisz siê po koszmarze z nauczycielk¹ matematyki."));
    tekst(tr("Przypominasz sobie, ¿e za 5 minut masz egzamin z polskiego."));
    tekst(tr("W b³yskawicznym tempie zjadasz œniadanie, myjesz zêby i ubierasz siê w garnitur."));
    tekst(tr("Wychodzisz na szybkoœci z mieszkania."));
    tekst(tr("Na klatce zauwa¿asz swojego niemieckiego s¹siada - Hansa."));
    tekst(tr("Wiesz, ¿e jest on narkomanem i mama kaza³a ci nic od niego nie braæ."));
    tekst(tr("Proponuje on ci za¿ycie narkotyku, jak to on nazywa UberNarkotiken."));
    Segment = 1;
    }
    while (Segment == 1)
    {
    tekst(tr("Za¿ywasz, czy odmawiasz?"));
    tekst(tr("1. Za¿yj UberNarkotiken"));
    tekst(tr("2. Odmów Hansowi"));
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    wybor=getch();
    system("cls");

    switch(wybor)
    {
        case'1':
        tekst(tr("Hans podaje ci narkotyk."));
        tekst(tr("Wk³adasz tabletkê z narkotykiem do ust."));
        tekst(tr("Nagle widzisz obrazy przedstawiaj¹ce wielkie Niemcy."));
        tekst(tr("Padasz nieprzytomny."));
        Segment = 2;
        break;
        case '2':
        tekst(tr("Hans jest oburzony tym, ¿e mu odmówi³eœ."));
        tekst(tr("W ramach kary za niepos³uszeñstwo idzie ciebie pobiæ."));
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
        tekst(tr("Tracisz przytomnoœæ."));
        Segment = 2;
        break;
        default:
        tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
        break;
    }
    }
    while (Segment == 2)
    {
        tekst(tr("Mija kilka minut."));
        tekst(tr("Budzisz siê na klatce, Hansa ju¿ nie ma."));
        tekst(tr("Patrzysz na zegarek i widzisz, ¿e wskazówki siê nie ruszaj¹."));
        tekst(tr("Pewnie baterie siê wyczerpa³y."));
        tekst(tr("Wychodzisz z bloku i widzisz d¿unglê."));
        tekst(tr("Nie mo¿esz siê doczekaæ spotkania z tarzanem."));
        tekst(tr("Jednak dziwi ciê fakt, ¿e w mieœcie jest d¿ungla."));
        tekst(tr("Nagle zacz¹³ ci burczeæ brzuch."));
        tekst(tr("Powinieneœ coœ zjeœæ."));
        Segment = 3;
    }
    while (Segment == 3)
    {
        tekst(tr("Co robisz?"));
        tekst(tr("1. Bierzesz banany z drzewa."));
        tekst(tr("2. Kradniesz banany ma³pie."));
        tekst(tr("3. Dokonujesz degustacji skolopendry."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch (wybor)
        {
            case'1':
            tekst(tr("Przygl¹dasz siê bananom na drzewie."));
            tekst(tr("W przesz³oœci uprawia³eœ parkour, wiêc z ³atwoœci¹ wspinasz siê na bananowca."));
            tekst(tr("Zrywasz i po³ykasz banany w ca³oœci."));
            tekst(tr("Zauwa¿asz burzowe chmury nad tob¹."));
            tekst(tr("Trafia w ciebie piorun."));
            tekst(tr("Spadasz na ziemiê."));
            tekst(tr("Nagle przychodzi wódz plemienia Ikitiki i ka¿e ciebie usma¿yæ na kotleta."));
            tekst(tr("Owijaj¹ ci rêce i zabieraj¹ do swojej wioski."));
            Segment = 4;
            break;
            case'2':
            tekst(tr("Patrzysz siê na ma³pê."));
            tekst(tr("Ma³pa patrzy siê na ciebie."));
            tekst(tr("Podchodzisz do niej i wyzywasz j¹ na solo."));
            tekst(tr("Nie zauwa¿y³eœ ¿e to goryl, ale co tam."));
            Zdrowie = 10*Zycie;
            Przeciwnik = "Goryl";
            PoziomP = 6;
            PZdrowie = 20;
            PMagia = 0;
            PSila = 3;
            PWytrzymalosc = 1;
            PSzczescie = 2;
            walka(Przeciwnik,PoziomP);
            if (Zdrowie != 0)
            {
            tekst(tr("Pokona³eœ goryla i zjad³eœ jego banany."));
            tekst(tr("Wtedy przychodzi wódz plemienia Ikitiki i mówi, ¿e by³o to ich zwierzê domowe."));
            tekst(tr("Otaczajê ciebie tubylcy i zabieraj¹ do wioski, ¿eby zrobiæ z ciebie kotleta."));
            Segment = 4;
            }
            break;
            case'3':
            tekst(tr("Schylasz siê i podnosisz skolopendrê z ziemi."));
            tekst(tr("Powoli wk³adasz j¹ do gard³a."));
            tekst(tr("Nawet nie musia³eœ jej po³ykaæ, sama wesz³a."));
            tekst(tr("Nagle poczu³eœ dziwne swêdzenie w ¿o³¹dku."));
            tekst(tr("To skolopendra przedziurawi³a ci brzuch."));
            tekst(tr("A³æ."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
            break;
        }
    }
    while (Segment == 4)
    {
        tekst(tr("Tubylcy przyprowadzili ciebie do wioski Ikitiki."));
        tekst(tr("Przywi¹zuj¹ ciebie do pala i stawiaj¹ nad ogniem."));
        tekst(tr("Zawsze chcia³eœ byæ opalony jak koledzy."));
        tekst(tr("Nagle tubylcy zaczêli tañczyæ default dance."));
        tekst(tr("Fortnite to twoja ulubiona gra, wiêc cieszy ciebie ten widok."));
        tekst(tr("Po skoñczonym tañcu tubylcy przynieœli t³uczone ziemniaki i buraczki."));
        tekst(tr("Posypuj¹ ciebie bu³k¹ tart¹ i jajkiem."));
        tekst(tr("Czujesz ju¿ jak ci siê zwêglaj¹ plecy."));
        Segment = 5;
    }
    while (Segment == 5)
    {
        tekst(tr("Co robisz?"));
        tekst(tr("1. Prosisz o ziemniaczki na spróbowanie."));
        tekst(tr("2. Napadasz na tubylców za pomoc¹ bala."));
        tekst(tr("3. Zjadasz sobie kotleta."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch(wybor)
        {
            case'1':
            tekst(tr("Tubylcy zgadzaj¹ siê na twoje ostatnie ¿yczenie."));
            tekst(tr("Zjadasz ³y¿kê ziemniaczków."));
            tekst(tr("Nagle czujesz przyp³yw si³y i energii ze zjedzonych bulw."));
            tekst(tr("Robisz siê trzy razy wiêkszy od tubylców, a twoje miêsnie s¹ teraz wiêksze od nich samych."));
            tekst(tr("Zgniatasz wszystkich tubylców oprócz wodza za pomoc¹ kciuka."));
            tekst(tr("Pytasz siê zap³akanego wodza gdzie jest droga do szko³y."));
            tekst(tr("Zaleca ci wejœæ na górê Bingobongo i siê rozej¿eæ."));
            tekst(tr("Idziesz w stronê góry, w miêdzyczasie twoje cia³o wróci³o do normy."));
            tekst(tr("Jesteœ u stóp góry Ikitiki."));
            tekst(tr("Jest to bardzo stroma góra, bêdziesz potrzebowa³ jakiegoœ sprzêtu."));
            tekst(tr("Na ziemi le¿y kotwiczka, czapka z helikopterkiem i kartka z cheatami."));
            Segment = 6;
            break;
            case'2':
            tekst(tr("Wyzwalasz siê z lin i bierzesz bal do rêki."));
            tekst(tr("Masz szczêœcie, ¿e tubylcy s¹ zajêci jedzeniem twojego ucha i nic nie widz¹."));
            tekst(tr("Tylko jeden ciebie zauwa¿a i leci na ciebie z toporem."));
            Zdrowie = 10*Zycie;
            Przeciwnik = "Tubylca";
            PoziomP = 8;
            PZdrowie = 50;
            PSila = 4;
            walka(Przeciwnik,PoziomP);
            if (Zdrowie != 0)
            {
            tekst(tr("Po pokonaniu tubylcy z toporem zakrad³eœ siê ko³o wodza wioski i ukrad³eœ mu mapê"));
            tekst(tr("Postanowi³eœ udaæ siê na górê Ikitiki, aby siê rozejrzeæ."));
            tekst(tr("Jesteœ u stóp góry Ikitiki."));
            tekst(tr("Jest to bardzo stroma góra, bêdziesz potrzebowa³ jakiegoœ sprzêtu."));
            tekst(tr("Na ziemi le¿y kotwiczka, czapka z helikopterkiem i kartka z cheatami."));
            Segment = 6;
            }
            break;
            case'3':
            tekst(tr("Nic nie robisz, czekasz a¿ tubylcy przygotuj¹ kotleta."));
            tekst(tr("Po paru minutach daj¹ ci palec serdeczny do zjedzenia."));
            tekst(tr("Nawet dobry."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
            break;
        }
    }
    while (Segment == 6)
    {

        tekst(tr("Co robisz?"));
        tekst(tr("1. Wspinasz siê za pomoc¹ kotwiczki."));
        tekst(tr("2. Wlatujesz na górê helikopterkiem."));
        tekst(tr("3. U¿ywasz cheatów."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch(wybor)
        {
            case'1':
            tekst(tr("Próbujesz dorzuciæ kotwiczkê na jak¹kolwiek ska³ê."));
            tekst(tr("Niestety Ikitiki jest codziennie sprz¹tana przez lokalnych tubylców przez co nie ma tu ani jednej ska³y."));
            tekst(tr("Zacz¹³eœ kopaæ górê kotwiczk¹."));
            tekst(tr("Dokopa³eœ siê na sam szczyt."));
            Segment = 7;
            break;
            case'2':
            tekst(tr("Zak³adasz czapkê na g³owê."));
            tekst(tr("Lecisz sobie w górê."));
            tekst(tr("Nagle do twojej czapki dociera komunikat od wojsk lotniczych Ugabugastanu."));
            tekst(tr("Naruszy³eœ ich przestrzeñ powietrzn¹."));
            tekst(tr("Ty masz to w jamie nosowej."));
            tekst(tr("Nagle podlatuje murzyn przywi¹zany do dwóch balonów i mierzy do ciebie z kamienia."));
            Zdrowie = 10*Zycie;
            Przeciwnik = "Pilot";
            PoziomP = 10;
            PZdrowie = 75;
            PSila = 5;
            walka(Przeciwnik,PoziomP);
            if (Zdrowie != 0)
            {
            tekst(tr("Str¹ci³eœ balony pilota, który spad³ i zwichn¹³ sobie kostkê."));
            tekst(tr("Bez przeszkód dolecia³eœ na szczyt."));
            Segment = 7;
            }
            break;
            case'3':
            tekst(tr("W³¹czasz konsolê programu."));
            tekst(tr("Sv cheats on"));
            tekst(tr("Godmode on"));
            tekst(tr("Teleportujesz siê na szczyt góry."));
            tekst(tr("Nie zauwa¿y³eœ, ¿e admin jest na serwie."));
            tekst(tr("Dosta³eœ bana za cheatowanie."));
            tekst(tr("Umierasz, cofamy czas."));
            Sleep(2000);
            system("cls");
            break;
            default:
            tekst(tr("Nie wiem o co ci chodzi, naucz siê czytaæ."));
            break;
        }
    }
    while (Segment == 7)
    {
        tekst(tr("Rozgl¹dasz siê za swoj¹ szko³¹."));
        tekst(tr("Zauwa¿asz j¹ w oddali."));
        tekst(tr("Zauwa¿asz te¿ bardzo d³ug¹ tyrolkê zmierzaj¹c¹ w stronê szko³y."));
        tekst(tr("Bierzesz pobliski kij i zje¿d¿asz nim na tyrolce."));
        tekst(tr("Zje¿d¿asz ju¿ dobre pare minut."));
        tekst(tr("Nagle spostrzegasz armiê husarzy wzbijaj¹c¹ siê w powietrze."));
        tekst(tr("Ty zawsze spa³eœ na polaku, wiêc lec¹ w twoj¹ stronê."));
        Segment = 8;
    }
    while (Segment == 8)
    {
        tekst(tr("Co robisz?"));
        tekst(tr("1. Rzucasz im kebaba."));
        tekst(tr("2. Recytujesz Pana Tadeusza."));
        tekst(tr("3. Uderzasz ich z kija."));
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        wybor = getch();
        system("cls");
        switch(wybor)
        {
        case'1':
        tekst(tr("Rzuci³eœ kebabem, którego ukrad³eœ tubylcom."));
        tekst(tr("Husarze odwrócili od ciebie uwagê i zaczêli goniæ kebaba."));
        tekst(tr("Jedziesz sobie spokojnie dalej na tyrolce."));
        Segment = 9;
        break;
        case'2':
        tekst(tr("Mówisz husarzom, ¿e udowodnisz swojej polskoœci recytuj¹c s³ynn¹ inwokacjê."));
        tekst(tr("Husarze siê zgadzaj¹."));
        tekst(tr("Zaczynasz."));
        tekst(tr("Lidfo ojd¿yzno moja."));
        tekst(tr("Dy jezdeŸ jag strofie."));
        tekst(tr("Zanim skoñczy³eœ to jeden z husarzy wbi³ ci szablê w mózg."));
        tekst(tr("Umierasz, cofamy czas."));
        Sleep(2000);
        system("cls");
        break;
        case'3':
        tekst(tr("Uderzasz husarza z kija, a ten spada."));
        tekst(tr("W ramach zemsty reszta naciera na ciebie."));
        Zdrowie = 10*Zycie;
        Przeciwnik = "Husarz";
        PoziomP = 15;
        PZdrowie = 100;
        PSila = 6;
        walka(Przeciwnik,PoziomP);
        if (Zdrowie != 0)
        {
        tekst(tr("Pokona³eœ wszystkich husarzy."));
        tekst(tr("Jedziesz sobie spokojnie dalej na tyrolce."));
        Segment = 9;
        }
        break;
        }

    }
    while (Segment == 9)
    {
       tekst(tr("W koñcu docierasz do swojej szko³y."));
       tekst(tr("Po wejœciu do szko³y zmieniasz buty w szatni i zmierzasz do swojej klasy."));
       tekst(tr("Ca³a szko³a jest pusta."));
       tekst(tr("Wchodzisz do swojej klasy i siadasz na ³awce."));
       tekst(tr("Siedzi tam tylko egzaminator."));
       tekst(tr("Tak, to on."));
       tekst(tr("Thanos"));
       tekst(tr("Teraz wszystko wyda³o ci siê jasne."));
       tekst(tr("Thanos chce siê dowiedzieæ gdzie s¹ kamienie nieskoñczonoœci wykorzystuj¹c uczniów."));
       tekst(tr("Zostawi³eœ egzamin pusty i odda³eœ thanosowi."));
       tekst(tr("Thanos siê zdenerwowa³."));
       Zdrowie = 10*Zycie;
       Przeciwnik = "Thanos";
       PoziomP = 15;
       PZdrowie = 125;
       PSila = 6;
       walka(Przeciwnik,PoziomP);
       if (Zdrowie != 0)
       {
       tekst(tr("W koñcu pokona³eœ thanosa i zda³eœ egzamin."));
       tekst(tr("Nagle budzisz siê na klatce."));
       tekst(tr("Patrzysz na zegarek i widzisz, ¿e minê³y trzy godziny."));
       tekst(tr("Na szczêœcie twój tata to haker i w³ama³ siê do CKE."));
       tekst(tr("Dosta³eœ 100% z ka¿dego egzaminu."));
       tekst(tr("Wygra³eœ ¿ycie."));
       }
    }
    return 0;
}

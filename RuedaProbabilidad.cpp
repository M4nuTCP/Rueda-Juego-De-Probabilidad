#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void GraficoRuleta(int bola);
int RetirarIgresar(int dinero);

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    /*Variables ruleta*/

    int bola;
    int apostado;
    int dineroapostado;
    int dinero = 100;
    int x;

    // Variables Para Jugar a la Ruleta
    string novamas;
    string parimpar;
    string rojonegro;
    bool finbucle = false;

    // Variable para salir del Menu
    bool saliRule = false;

    // Cartel de bienvenida
    system("cls");

    std::cout << " /$$$$$$$                            /$$                 /$$$$$$$                   /$$                /$$       /$$ /$$ /$$       /$$                 /$$" << std::endl;
    std::cout << "| $$__  $$                          | $$                | $$__  $$                 | $$               | $$      |__/| $$|__/      | $$                | $$" << std::endl;
    std::cout << "| $$  \\ $$ /$$   /$$  /$$$$$$   /$$$$$$$  /$$$$$$       | $$  \\ $$/$$$$$$  /$$$$$$ | $$$$$$$  /$$$$$$ | $$$$$$$  /$$| $$ /$$  /$$$$$$$  /$$$$$$   /$$$$$$$" << std::endl;
    std::cout << "| $$$$$$$/| $$  | $$ /$$__  $$ /$$__  $$ |____  $$      | $$$$$$$/$$__  $$/$$__  $$| $$__  $$|____  $$| $$__  $$| $$| $$| $$ /$$__  $$ |____  $$ /$$__  $$" << std::endl;
    std::cout << "| $$__  $$| $$  | $$| $$$$$$$$| $$  | $$  /$$$$$$$      | $$____/ $$  \\__/ $$  \\ $$| $$  \\ $$ /$$$$$$$| $$  \\ $$| $$| $$| $$| $$  | $$  /$$$$$$$| $$  | $$" << std::endl;
    std::cout << "| $$  \\ $$| $$  | $$| $$_____/| $$  | $$ /$$__  $$      | $$    | $$     | $$  | $$| $$  | $$/$$__  $$| $$  | $$| $$| $$| $$| $$  | $$ /$$__  $$| $$  | $$" << std::endl;
    std::cout << "| $$  | $$|  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$$      | $$    | $$     |  $$$$$$/| $$$$$$$/  $$$$$$$| $$$$$$$/| $$| $$| $$|  $$$$$$$|  $$$$$$$|  $$$$$$$" << std::endl;
    std::cout << "|__/  |__/ \\______/  \\_______/ \\_______/ \\_______/      |__/    |__/      \\______/ |_______/ \\_______/|_______/ |__/|__/|__/ \\_______/ \\_______/ \\_______/" << std::endl;


    do
    {

        // Menu
        cout << "\n Fichas -> " << dinero << endl
             << endl
             << "1 -> Información " << endl
             << "2 -> Jugar " << endl
             << "3 -> Depositar/Retirar " << endl
             << "4 -> Salir" << endl;
        cin >> x;

        switch (x)
        {
        case 1:
        {
            // Info de como se juega a la ruleta cin>>salirinfo sirve para que pongas cualquier letra y lleve al menu otra vez
            string salirinfo;
            system("cls");
            cout << "La ruleta se remonta al siglo XVII. Fue el matemático francés Blas Pascal quien diseñó la primera versión de este juego" << endl
                 << "con treinta y seis números conocido como 'roulette'.La ruleta consiste en que una bola gira sobre 36 numero y donde cae" << endl
                 << "la bola es donde esta el premio los jugadores deben intentar apostar sus fichas y predecir en que numero va a caer la bola." << endl
                 << "Escribe cualquier letra para salir " << endl;
            cin >> salirinfo;
            system("cls");
        }
        break;

        case 2:
        {

            int x;
            system("cls");
            cout << "¿Como quieres apostar?" << endl
                 << endl
                 << "1 -> Numero" << endl
                 << "2 -> Color" << endl
                 << "3 -> Par/Impar" << endl
                 << "4 -> Numeros" << endl;
            cin >> x;

            switch (x)
            {
            case 1:
            {
                do
                {
                    system("cls");
                    cout << "Fichas disponibles " << dinero << " $ " << endl;
                    cout << endl;

                    // Hacer un menu para jugar y salir al menu

                    do
                    {
                        cout << "Numero -> ";
                        cin >> apostado;

                        if (apostado < 37)
                        {
                            cout << "Fichas -> ";
                            cin >> dineroapostado;

                            if (dineroapostado > dinero)
                            {
                                cout << endl
                                     << "Saldo Insuficiente" << endl
                                     << endl;
                            }
                        }
                        if (apostado >= 37)
                        {
                            cout << endl
                                 << "Escoge un numero del 0-36" << endl
                                 << endl;
                        }

                    } while (dineroapostado > dinero || apostado > 36);

                    cout << endl;

                    bola = rand() % 36;

                    GraficoRuleta(bola);

                    if (bola == apostado) // Bola dentro
                    {
                        dinero = dinero + dineroapostado * 36;
                        cout << endl
                             << "Bola dentro!" << endl;
                    }
                    else // Bola fuera
                    {
                        dinero = dinero - dineroapostado;
                        cout << "Bola fuera!" << endl;
                    }
                    // Proxima bola2

                    cout << endl;
                    cout << "Bola -> " << bola << endl;
                    cout << "Tu numero -> " << apostado << endl
                         << endl;
                    cout << "-----------------" << endl;
                    cout << "Fichas -> " << dinero << " $" << endl
                         << endl;

                    cout << "¿Quieres volver a jugar?" << endl;
                    cin >> novamas;

                } while (novamas != "no" && novamas != "NO" && novamas != "No" && novamas != "nO");

                if (dinero < 0)
                {
                    cout << "Perdiste todo tu dinero , normal";
                    Sleep(3000);
                }

                system("cls");
            }
            break;

            case 2:
            {
                system("cls");
                cout << "Rojos -> 1 - 3 - 5 - 7 - 9 - 12 - 14 - 16 - 18 - 19 - 21 - 23 - 25 - 27 - 30 - 32 - 34 - 36" << endl
                     << "Negros -> 0 - 2 - 4 - 6 - 8 - 10 - 11 - 13 - 15 - 17 - 20 - 22 - 24 - 26 - 28 - 29 - 31 - 33 - 35" << endl;

                do
                {
                    do
                    {
                        finbucle = false;
                        cout << endl;
                        cout << "rojo/negro -> ";
                        cin >> rojonegro;

                        if (rojonegro == "rojo" || rojonegro == "negro")
                        {
                            cout << "Fichas -> ";
                            cin >> dineroapostado;
                            if (dineroapostado < dinero)
                            {
                                finbucle = true;
                            }

                            if (dineroapostado > dinero)
                            {
                                cout << endl
                                     << "Saldo Insuficiente" << endl
                                     << endl;
                            }
                        }
                        else if (rojonegro != "rojo" || rojonegro != "negro")
                        {
                            cout << endl
                                 << "Escribe rojo o negro en minuscula" << endl
                                 << endl;
                        }

                    } while (finbucle == false);

                    cout << endl;

                    bola = rand() % 36;

                    GraficoRuleta(bola);

                    if (bola == 1 || bola == 3 || bola == 5 || bola == 7 || bola == 9 || bola == 12 || bola == 14 || bola == 16 || bola == 18 || bola == 19 || bola == 21 || bola == 23 || bola == 25 | bola == 27 || bola == 30 || bola == 32 || bola == 34 || bola == 36)
                    {

                        cout << "Rojo!" << endl
                             << endl;
                        if (rojonegro == "rojo")
                        {
                            cout << "Bola dentro!" << endl;
                            dinero += dineroapostado;
                        }
                        else if (rojonegro == "negro")
                        {
                            cout << "Bola fuera!" << endl;
                            dinero -= dineroapostado;
                        }
                    }
                    else
                    {
                        cout << "Negro!" << endl
                             << endl;
                        if (rojonegro == "negro")
                        {
                            cout << "Bola dentro!" << endl;
                            dinero += dineroapostado;
                        }
                        else if (rojonegro == "rojo")
                        {
                            cout << "Bola fuera!" << endl;
                            dinero -= dineroapostado;
                        }
                    }
                    cout << endl;
                    cout << "Bola -> " << bola << " " << rojonegro << endl;
                    cout << "Tu apuesta -> " << rojonegro << endl;
                    cout << "-----------------" << endl;
                    cout << "Fichas -> " << dinero << " $" << endl
                         << endl;

                    cout << "¿Quieres volver a jugar?" << endl;
                    cin >> novamas;
                    if (dinero > 0)
                    {
                        cout << "¿Quieres volver a jugar?" << endl;
                        cin >> novamas;
                    }

                } while (novamas != "no" && novamas != "NO" && novamas != "No" && novamas != "nO");
                system("cls");
            }
            break;

            case 3:
            {
                do
                {
                    do
                    {
                        finbucle = false;
                        cout << endl
                             << "par/impar -> ";
                        cin >> parimpar;

                        if (parimpar == "par" || parimpar == "impar")
                        {
                            cout << "Fichas -> ";
                            cin >> dineroapostado;
                            if (dineroapostado < dinero)
                            {
                                finbucle = true;
                            }

                            if (dineroapostado > dinero)
                            {
                                cout << endl
                                     << "Saldo Insuficiente" << endl
                                     << endl;
                            }
                        }
                        else if (parimpar != "par" || parimpar != "imppar")
                        {
                            cout << endl
                                 << "Escribe par o impar en minuscula" << endl
                                 << endl;
                        }

                    } while (finbucle == false);

                    cout << endl;

                    bola = rand() % 36;

                    GraficoRuleta(bola);

                    if (bola == 0 || bola == 2 || bola == 4 || bola == 6 || bola == 8 || bola == 10 || bola == 12 || bola == 14 || bola == 16 || bola == 18 || bola == 20 || bola == 22 || bola == 24 || bola == 26 || bola == 28 || bola == 30 || bola == 32 || bola == 34 || bola == 36)
                    {
                        cout << "Par!" << endl
                             << endl;
                        if (parimpar == "par")
                        {
                            cout << "Bola dentro!" << endl;
                            dinero += dineroapostado;
                        }
                        else if (parimpar == "impar")
                        {
                            cout << "Bola fuera!" << endl;
                            dinero -= dineroapostado;
                        }
                    }
                    else
                    {
                        cout << "Impar!" << endl
                             << endl;
                        if (parimpar == "impar")
                        {
                            cout << "Bola dentro!" << endl;
                            dinero += dineroapostado;
                        }
                        else if (parimpar == "par")
                        {
                            cout << "Bola fuera!" << endl;
                            dinero -= dineroapostado;
                        }
                    }
                    cout << endl;
                    cout << "Bola -> " << bola << " " << parimpar << endl;
                    cout << "Tu apuesta -> " << parimpar << endl;
                    cout << "-----------------" << endl;
                    cout << "Fichas -> " << dinero << " $" << endl
                         << endl;

                    cout << "¿Quieres volver a jugar?" << endl;
                    cin >> novamas;
                    if (dinero > 0)
                    {
                        cout << "¿Quieres volver a jugar?" << endl;
                        cin >> novamas;
                    }
                } while (novamas != "no" && novamas != "NO" && novamas != "No" && novamas != "nO");

                system("cls");
            }
            break;

            case 4:
            {

                int dineros[10];
                int numeros[10];
                int numero;
                int cuantosnumeros;
                int bolafuera;
                bool salircuantonumeros = false;

                do
                {

                    do
                    {

                        system("cls");
                        cout << "Cuantos numeros quieres apostar? ";
                        cin >> cuantosnumeros;
                        if (cuantosnumeros > 10)
                        {
                            cout << "Solo puedes apostar en menos de 10 Numeros" << endl;
                            Sleep(2000);
                        }

                    } while (cuantosnumeros > 10);
                    cout << "Tienes " << dinero << " fichas" << endl
                         << endl;

                    // bools para salir de los dowhile de errores

                    for (int j = 0; j < cuantosnumeros; j++)
                    {
                        bool dineronopermitido = false;
                        bool numeronopermitido = false;
                        do
                        {
                            dineronopermitido = false;
                            numeronopermitido = false;
                            cout << j << " Numero -> ";
                            cin >> numeros[j];
                            cout << j << " Apuesta -> ";
                            cin >> dineros[j];

                            if (numeros[j] > 36)
                            {
                                cout << "El numero tiene que ser menor o igual que 36" << endl;
                            }
                            else if (numeros[j] <= 36)
                            {
                                numeronopermitido = true;
                            }

                            if (dineros[j] > dinero)
                            {
                                cout << "Tu apuesta tiene que ser menor o igual de " << dinero << " , si tienes 0 euros tendras que apostar 0" << endl;
                            }
                            else if (dineros[j] <= dinero)
                            {
                                dineronopermitido = true;
                                dinero -= dineros[j];
                            }

                        } while (dineronopermitido == false && numeronopermitido == false || dineronopermitido != false && numeronopermitido == false || dineronopermitido == false && numeronopermitido != false);
                    }

                    bola = rand() % 36;

                    GraficoRuleta(bola);

                    bolafuera = 0;

                    for (int i = 0; i < cuantosnumeros; i++)
                    {
                        if (bola == numeros[i])
                        {
                            cout << "Bola Dentro!";
                            dinero += dineros[i];
                            bolafuera = 1;
                            numero = numeros[i];
                        }
                    }
                    if (bolafuera == 0)
                    {
                        cout << "Bola fuera!" << endl;

                        for (int j = 0; j < cuantosnumeros; j++)
                        {
                            dinero -= dineros[j];
                        }
                    }
                    cout << endl;
                    cout << "Bola -> " << bola << endl;
                    cout << "Tus Numeros -> ";
                    for (int i = 0; i < cuantosnumeros; i++)
                    {
                        cout << numeros[i] << " ";
                    }

                    cout << endl;
                    cout << "-----------------" << endl;
                    cout << "Fichas -> " << dinero << " $" << endl
                         << endl;
                    if (dinero > 0)
                    {
                        cout << "¿Quieres volver a jugar?" << endl;
                        cin >> novamas;
                    }
                    else if (dinero <= 0)
                    {
                        cout << "Tienes 0 fichas , no puedes jugar , ingresa dinero! " << endl;
                        Sleep(10000);
                        system("cls");
                        for (int i = 0; i < 8; i++)
                        {
                            cout << "Tienes 0 fichas , no puedes jugar , ingresa dinero! " << endl;
                            cout << "Cargando";
                            Sleep(250);
                            system("cls");
                            cout << "Tienes 0 fichas , no puedes jugar , ingresa dinero! " << endl;
                            cout << "Cargando.";

                            Sleep(250);
                            system("cls");
                            cout << "Tienes 0 fichas , no puedes jugar , ingresa dinero! " << endl;
                            cout << "Cargando..";

                            Sleep(250);
                            system("cls");
                            cout << "Tienes 0 fichas , no puedes jugar , ingresa dinero! " << endl;
                            cout << "Cargando...";

                            Sleep(250);
                            system("cls");
                        }
                        novamas = "no";
                    }

                } while (novamas != "no" && novamas != "NO" && novamas != "No" && novamas != "nO");
                system("cls");
            }
            }
            break;
        }
        break;

        case 3:
        {
            int y;
            int deposito;
            int retiro;
            //variables depositar y retirar dinero 

            system("cls");
            cout << "-----------------------" << endl;
            cout << "--DEPOSITAR Y RETIRAR--" << endl;
            cout << "-----------------------" << endl
                 << endl;

            cout << "Fichas disponibles " << dinero << " $ " << endl;
            cout << endl
                 << endl;

            cout << "1 -> Deposito" << endl
                 << "2 -> Retiro" << endl
                 << "3 -> Volver al menu" << endl;
            cin >> y;

            switch (y)
            {
            case 1:
            {
                system("cls");
                cout << "Dinero actual -> " << dinero << endl;
                cout << "¿Cuanto dinero quieres ingresar? -> ";
                cin >> deposito;

                dinero += deposito;
                system("cls");
            }
            break;

            case 2:
            {
                system("cls");
                cout << "Dinero actual -> " << dinero << endl;
                cout << "¿Cuanto dinero quieres retirar? -> ";
                cin >> retiro;

                if (retiro <= dinero)
                {
                    dinero -= retiro;
                }
                else if (retiro > dinero)
                {
                    cout << "No tienes suficiente dinero";
                    Sleep(3000);
                }

                system("cls");
            }
            break;
            case 3:
            {
                system("cls");
            }

            break;
            }
            break;

        case 4:
        {
            //case para salir de la ruleta
            cout << "Tienes " << dinero << " fichas" << endl
                 << "Espero que vuelvas!";
            saliRule = true;
        }
        break;

        default:
            break;
        }
        }

    } while (saliRule == false);

    return 0;
}


//Grafico de la bola girando

void GraficoRuleta(int bola)
{

    if (bola == 0 || bola == 32 || bola == 15 || bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 3 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {

        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35      @       19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     3     " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35         @    19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35           @  19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35            @ 19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                  @ 4     " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                     @ 21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                         @  2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                          @ 25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                          @ 17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                          @ 34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                           @ 6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                          @ 27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                          @ 13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11   " << endl;
        cout << "   33                     30     " << endl;
        cout << "     16                  8       " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                          @ 36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                       @ 11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                   @ 30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                @ 8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16          @       8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16      @           8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16 @                8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33 @                   30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1  @                      11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20 @                          36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14 @                          13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31 @                          27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9  @                          6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22 @                          34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18 @                          17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29 @                          25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7  @                         2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28 @                     21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12 @                  4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35 @            19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35   @          19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35      @       19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     3     " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35         @    19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35           @  19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35            @ 19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                  @ 4     " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                     @ 21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                         @  2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                          @ 25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                          @ 17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                          @ 34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                           @ 6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                          @ 27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                          @ 13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11   " << endl;
        cout << "   33                     30     " << endl;
        cout << "     16                  8       " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                          @ 36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                       @ 11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                   @ 30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                @ 8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16          @       8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16      @           8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16 @                8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33 @                   30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1  @                      11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20 @                          36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14 @                          13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31 @                          27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9  @                          6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22 @                          34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18 @                          17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29 @                          25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7  @                         2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28 @                     21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12 @                  4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35 @            19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35   @          19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
        system("cls");
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35      @       19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     3     " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
    };

    if (bola == 0 || bola == 32 || bola == 15 || bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35      @       19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     3     " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 32 || bola == 15 || bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35         @    19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 15 || bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35           @  19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35           @  19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 19 || bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35            @ 19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 4 || bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                  @ 4     " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 21 || bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                     @ 21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 2 || bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                         @  2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 25 || bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                          @ 25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 17 || bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                          @ 17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 34 || bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                          @ 34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 6 || bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                           @ 6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 27 || bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                          @ 27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 13 || bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                          @ 13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11   " << endl;
        cout << "   33                     30     " << endl;
        cout << "     16                  8       " << endl;
        cout << "        24   5   10   23         " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 36 || bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                          @ 36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 11 || bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                       @ 11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 30 || bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                   @ 30       " << endl;
        cout << "     16                  8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 8 || bola == 23 || bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16                @ 8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 10 || bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16          @       8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 5 || bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16      @           8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 24 || bola == 16 || bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19      " << endl;
        cout << "    12                    4    " << endl;
        cout << "  28                       21  " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36  " << endl;
        cout << "  1                         11    " << endl;
        cout << "   33                     30       " << endl;
        cout << "     16 @                8         " << endl;
        cout << "        24   5   10   23           " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 33 || bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33 @                   30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 1 || bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1  @                      11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 20 || bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20 @                          36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 14 || bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14 @                          13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 31 || bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31 @                          27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 9 || bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9  @                          6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 22 || bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22 @                          34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 18 || bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18 @                          17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 29 || bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29 @                          25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 7 || bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7  @                         2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 28 || bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28 @                     21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 12 || bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35              19       " << endl;
        cout << "    12 @                  4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 35 || bola == 3 || bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35 @            19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
    if (bola == 26)
    {
        system("cls");
        cout << "          3 26 0 32 15          " << endl;
        cout << "       35   @          19       " << endl;
        cout << "    12                    4     " << endl;
        cout << "  28                       21   " << endl;
        cout << " 7                            2 " << endl;
        cout << "29                            25" << endl;
        cout << "18                            17" << endl;
        cout << "22                            34" << endl;
        cout << "9                             6 " << endl;
        cout << "31                            27" << endl;
        cout << "14                            13" << endl;
        cout << "20                            36" << endl;
        cout << "  1                         11  " << endl;
        cout << "   33                     30    " << endl;
        cout << "     16                  8      " << endl;
        cout << "        24   5   10   23        " << endl;
        cout << endl;
        Sleep(1);
    }
}
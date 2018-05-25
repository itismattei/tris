#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
char tris[9];
int arrscelta[9];
void newgriglia()
{
    cout<<endl;
    cout<<"      "<<tris[0]<<"  |  "<<tris[1]<<"  |  "<<tris[2]<<"  "<<endl;
    cout<<"    -----|-----|-----"<<endl;
    cout<<"      "<<tris[3]<<"  |  "<<tris[4]<<"  |  "<<tris[5]<<"  "<<endl;
    cout<<"    -----|-----|-----"<<endl;
    cout<<"      "<<tris[6]<<"  |  "<<tris[7]<<"  |  "<<tris[8]<<"  "<<endl;
    cout<<endl;
}
int input()
{
    int sclt;
    cout<<"    In quale casella vuoi inserire la tua X? ";
    cin>>sclt;
    while(sclt>9 || sclt<1){
        cout<<"    Scegli una casella libera da 1 a 9! ";
        cin>>sclt;
    }
    while(tris[sclt-1]=='X' || tris[sclt-1]== '0'){
        cout<<"    Casella gia' occupata, effettua correttamente la tua scelta! ";
        cin>>sclt;
        while(sclt>9 || sclt<1){
            cout<<"    Scegli una casella libera da 1 a 9! ";
            cin>>sclt;
        }
    }
    return sclt;
}
void tabellino(int c1, int c2, int c3)
{
    cout<<"    Vittorie totali: "<<c1<<endl;
    cout<<"    Vittorie del computer: "<<c2<<endl;
    cout<<"    Pareggi: "<<c3<<endl;
}
char risultato(int turni)
{
    if(arrscelta[0]==1 && arrscelta[1]==1 && arrscelta[2]==1)
        return 'X';
    else if(arrscelta[3]==1 && arrscelta[4]==1 && arrscelta[5]==1)
        return 'X';
    else if(arrscelta[6]==1 && arrscelta[7]==1 && arrscelta[8]==1)
        return 'X';
    else if(arrscelta[0]==1 && arrscelta[3]==1 && arrscelta[6]==1)
        return 'X';
    else if(arrscelta[1]==1 && arrscelta[4]==1 && arrscelta[7]==1)
        return 'X';
    else if(arrscelta[2]==1 && arrscelta[5]==1 && arrscelta[8]==1)
        return 'X';
    else if(arrscelta[2]==1 && arrscelta[4]==1 && arrscelta[6]==1)
        return 'X';
    else if(arrscelta[0]==1 && arrscelta[4]==1 && arrscelta[8]==1)
        return 'X';
    else if(arrscelta[0]==0 && arrscelta[1]==0 && arrscelta[2]==0)
        return '0';
    else if(arrscelta[3]==0 && arrscelta[4]==0 && arrscelta[5]==0)
        return '0';
    else if(arrscelta[6]==0 && arrscelta[7]==0 && arrscelta[8]==0)
        return '0';
    else if(arrscelta[0]==0 && arrscelta[3]==0 && arrscelta[6]==0)
        return '0';
    else if(arrscelta[1]==0 && arrscelta[4]==0 && arrscelta[7]==0)
        return '0';
    else if(arrscelta[2]==0 && arrscelta[5]==0 && arrscelta[8]==0)
        return '0';
    else if(arrscelta[2]==0 && arrscelta[4]==0 && arrscelta[6]==0)
        return '0';
    else if(arrscelta[0]==0 && arrscelta[4]==0 && arrscelta[8]==0)
        return '0';
    else if(turni==9)
        return 'Z';
}
int risposta(char modalita)
{
    int a;
    if(modalita=='f' || modalita=='F')
    {
        a=rand()%9;
        while(arrscelta[a]==1 || arrscelta[a]==0)
            a=rand()%9;
        return a;
    }
    else if(modalita=='m' || modalita=='M' || modalita== 'd' || modalita=='D')
    {
        if(arrscelta[0]==0 && arrscelta[3]==0 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[0]==0 && arrscelta[6]==0 && arrscelta[3]!=1 && arrscelta[3]!=0)
            return 3;
        else if(arrscelta[6]==0 && arrscelta[3]==0 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[1]==0 && arrscelta[4]==0 && arrscelta[7]!=1 && arrscelta[7]!=0)
            return 7;
        else if(arrscelta[1]==0 && arrscelta[7]==0 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[7]==0 && arrscelta[4]==0 && arrscelta[1]!=1 && arrscelta[1]!=0)
            return 1;
        else if(arrscelta[2]==0 && arrscelta[5]==0 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[2]==0 && arrscelta[8]==0 && arrscelta[5]!=1 && arrscelta[5]!=0)
            return 5;
        else if(arrscelta[8]==0 && arrscelta[5]==0 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(arrscelta[0]==0 && arrscelta[1]==0 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(arrscelta[1]==0 && arrscelta[2]==0 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[0]==0 && arrscelta[2]==0 && arrscelta[1]!=1 && arrscelta[1]!=0)
            return 1;
        else if(arrscelta[3]==0 && arrscelta[4]==0 && arrscelta[5]!=1 && arrscelta[5]!=0)
            return 5;
        else if(arrscelta[3]==0 && arrscelta[5]==0 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[4]==0 && arrscelta[5]==0 && arrscelta[3]!=1 && arrscelta[3]!=0)
            return 3;
        else if(arrscelta[6]==0 && arrscelta[7]==0 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[6]==0 && arrscelta[8]==0 && arrscelta[7]!=1 && arrscelta[7]!=0)
            return 7;
        else if(arrscelta[7]==0 && arrscelta[8]==0 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[0]==0 && arrscelta[4]==0 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[4]==0 && arrscelta[8]==0 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[0]==0 && arrscelta[8]==0 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[2]==0 && arrscelta[4]==0 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[2]==0 && arrscelta[6]==0 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[6]==0 && arrscelta[4]==0 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(arrscelta[0]==1 && arrscelta[3]==1 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[0]==1 && arrscelta[6]==1 && arrscelta[3]!=1 && arrscelta[3]!=0)
            return 3;
        else if(arrscelta[6]==1 && arrscelta[3]==1 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[1]==1 && arrscelta[4]==1 && arrscelta[7]!=1 && arrscelta[7]!=0)
            return 7;
        else if(arrscelta[1]==1 && arrscelta[7]==1 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[7]==1 && arrscelta[4]==1 && arrscelta[1]!=1 && arrscelta[1]!=0)
            return 1;
        else if(arrscelta[2]==1 && arrscelta[5]==1 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[2]==1 && arrscelta[8]==1 && arrscelta[5]!=1 && arrscelta[5]!=0)
            return 5;
        else if(arrscelta[8]==1 && arrscelta[5]==1 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(arrscelta[0]==1 && arrscelta[1]==1 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(arrscelta[1]==1 && arrscelta[2]==1 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[0]==1 && arrscelta[2]==1 && arrscelta[1]!=1 && arrscelta[1]!=0)
            return 1;
        else if(arrscelta[3]==1 && arrscelta[4]==1 && arrscelta[5]!=1 && arrscelta[5]!=0)
            return 5;
        else if(arrscelta[3]==1 && arrscelta[5]==1 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[4]==1 && arrscelta[5]==1 && arrscelta[3]!=1 && arrscelta[3]!=0)
            return 3;
        else if(arrscelta[6]==1 && arrscelta[7]==1 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[6]==1 && arrscelta[8]==1 && arrscelta[7]!=1 && arrscelta[7]!=0)
            return 7;
        else if(arrscelta[7]==1 && arrscelta[8]==1 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[0]==1 && arrscelta[4]==1 && arrscelta[8]!=1 && arrscelta[8]!=0)
            return 8;
        else if(arrscelta[4]==1 && arrscelta[8]==1 && arrscelta[0]!=1 && arrscelta[0]!=0)
            return 0;
        else if(arrscelta[0]==1 && arrscelta[8]==1 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[2]==1 && arrscelta[4]==1 && arrscelta[6]!=1 && arrscelta[6]!=0)
            return 6;
        else if(arrscelta[2]==1 && arrscelta[6]==1 && arrscelta[4]!=1 && arrscelta[4]!=0)
            return 4;
        else if(arrscelta[6]==1 && arrscelta[4]==1 && arrscelta[2]!=1 && arrscelta[2]!=0)
            return 2;
        else if(modalita=='d' || modalita=='D'){
            if(arrscelta[1]==1 && arrscelta[3]==1 && arrscelta[0]!=1 && arrscelta[0]!=0)
                return 0;
            else if(arrscelta[5]==1 && arrscelta[7]==1 && arrscelta[8]!=1 && arrscelta[8]!=0)
                return 8;
            else if(arrscelta[3]==1 && arrscelta[7]==1 && arrscelta[6]!=1 && arrscelta[6]!=0)
                return 6;
            else if(arrscelta[5]==1 && arrscelta[1]==1 && arrscelta[2]!=1 && arrscelta[2]!=0)
                return 2;
            else if(arrscelta[0]==1 && arrscelta[8]!=0 && arrscelta[8]!=1)
                return 8;
            else if(arrscelta[8]==1 && arrscelta[0]!=0 && arrscelta[0]!=1)
                return 0;
            else if(arrscelta[2]==1 && arrscelta[6]!=0 && arrscelta[6]!=1)
                return 6;
            else if(arrscelta[6]==1 && arrscelta[2]!=0 && arrscelta[2]!=1)
                return 2;
            else if(arrscelta[4]!=0 && arrscelta[4]!=1)
                return 4;
            else if(arrscelta[0]!=0 && arrscelta[0]!=1)
                return 0;
            else if(arrscelta[2]!=0 && arrscelta[2]!=1)
                return 2;
            else if(arrscelta[6]!=0 && arrscelta[6]!=1)
                return 6;
            else if(arrscelta[8]!=0 && arrscelta[8]!=1)
                return 8;
        }
        else
        {
            a=rand()%9;
            while(arrscelta[a]==1 || arrscelta[a]==0)
                a=rand()%9;
            return a;
        }
    }
}
int main()
{
    int val=0;
    int val2=0;
    int val3=0;
    int val4=0;
    int val5=0;
    char carattere;
    char carattere2;
    char carattere3;
    char carattere4;
    int t=0;
    int c1=0;
    int c2=0;
    int c3=0;
    int sclt;
    char e;
    char modalita;
    string nome;
    string nome2;
    cout<<endl;
    cout<<"    TRIS, THE GAME!   "<<endl;
    cout<<"    Developed by Tommaso Pettinari "<<endl;
    cout<<endl;
    do{
        for(int i=0; i<9; i++)
            arrscelta[i]=2;
        tris[0]='1'; tris[1]='2'; tris[2]='3'; tris[3]='4'; tris[4]='5'; tris[5]='6'; tris[6]='7'; tris[7]='8'; tris[8]='9';
        newgriglia();
        cout<<"    Vuoi giocare contro il computer o contro un secondo giocatore?"<<endl;
        cout<<"    c -> computer - p -> player 2: ";
        cin>>carattere;
        cout<<endl;
        if(carattere=='c'){
            cout<<"    Che livello di difficolta' vuoi impostare? "<<endl;
            cout<<"    Scegli una modalita' tra facile (f), media(m) e difficile(d) "<<endl;
            cout<<"    ";
            cin>>modalita;
            cout<<endl;
            while(val4==0){
                    do{
                cout<<"    PLAYER VS COMPUTER"<<endl;
                        sclt=input();
                        tris[sclt-1]='X';
                        arrscelta[sclt-1]=1;
                        t=t+1;
                        e=risultato(t);
                        if(e=='X'){
                            cout<<endl;
                            cout<<"    Hai vinto la partita, congratulazioni!";
                            sndPlaySound("Applauso.wav", SND_ASYNC);
                            c1=c1+1;
                            val=1;
                        }
                        if(e=='Z'){
                            cout<<endl;
                            cout<<"    E' un pareggio, nessuno e' riuscito a prevalere!";
                            sndPlaySound("Grilli.wav", SND_ASYNC);
                            c3=c3+1;
                            val=1;
                        }
                        //turno PC
                        if(val==0)
                        {
                            sclt=risposta(modalita);
                            tris[sclt]='0';
                            arrscelta[sclt]=0;
                            t=t+1;
                            e=risultato(t);
                            if(e=='0'){
                                cout<<endl;
                                cout<<"    Hai perso la partita, che sfortuna!";
                                sndPlaySound("Boo.wav", SND_ASYNC);
                                c2=c2+1;
                                val=1;
                            }
                        }
                        system("cls");
                        cout<<endl;
                        newgriglia();
                    }while(val==0);
                    cout<<endl;
                    tabellino(c1, c2, c3);
                    cout<<endl;
                    cout<<"    Vuoi continuare a giocare?"<<endl;
                    cout<<"    (y -> yes - n -> no) ";
                    cin>>carattere2;
                    if(carattere2=='y' || carattere2=='Y'){
                        t=0;
                        val=0;
                        tris[0]='1'; tris[1]='2'; tris[2]='3'; tris[3]='4'; tris[4]='5'; tris[5]='6'; tris[6]='7'; tris[7]='8'; tris[8]='9';
                        for(int u=0; u<9; u++)
                            arrscelta[u]=2;
                    }
                    else if(carattere2=='n' || carattere2=='N'){
                        val4=1;
                        t=0;
                        c1=0;
                        c2=0;
                        c3=0;
                        tris[0]='1'; tris[1]='2'; tris[2]='3'; tris[3]='4'; tris[4]='5'; tris[5]='6'; tris[6]='7'; tris[7]='8'; tris[8]='9';
                        for(int u=0; u<9; u++)
                            arrscelta[u]=2;
                    }
                    cout<<endl;
                }
            }
            //pvp
            if(carattere=='p' || carattere=='P'){
                while(val3==0){
                    system("cls");
                    newgriglia();
                    cout<<endl;
                    cout<<"    PLAYER VS PLAYER"<<endl;
                    cout<<"    Il giocatore 1 utilizzera' X, il giocatore 2 invece 0! "<<endl;
                    cout<<endl;
                    cout<<"    Giocatore 1 inserisci il tuo nome: ";
                    cin>>nome;
                    cout<<"    Giocatore 2 inserisci il tuo nome: ";
                    cin>>nome2;
                    do{
                        cout<<endl;
                        cout<<"    TURNO DI "<<nome<<endl;
                        input();
                        sclt=tris[sclt-1]='X';
                        arrscelta[sclt-1]=1;
                        t=t+1;
                        e=risultato(t);
                        system("cls");
                        newgriglia();
                        if(e=='X'){
                            cout<<endl;
                            cout<<"    "<<nome<<" hai vinto la partita, congratulazioni!";
                            cout<<"    "<<nome2<<" hai perso la partita, ritenta e dimostra quanto vali!";
                            sndPlaySound("Applauso2.wav", SND_ASYNC);
                            c1=c1+1;
                            val2=1;
                        }
                        if(e=='Z'){
                            cout<<endl;
                            cout<<"    E' un pareggio!";
                            sndPlaySound("Grilli.wav", SND_ASYNC);
                            c3=c3+1;
                            val2=1;
                        }
                        if(val2==0){
                            cout<<endl;
                            cout<<"    TURNO DI "<<nome2<<endl;
                            input();
                            sclt=tris[sclt-1]='0';
                            arrscelta[sclt-1]=0;
                            t=t+1;
                            e=risultato(t);
                            system("cls");
                            cout<<endl;
                            newgriglia();

                            if(e=='0'){
                                cout<<endl;
                                cout<<"    "<<nome2<<" hai vinto la partita, congratulazioni!"<<endl;
                                cout<<"    "<<nome<<" hai perso la partita, ritenta e dimostra quanto vali!"<<endl;
                                sndPlaySound("Wow.wav", SND_ASYNC);
                                c2=c2+1;
                                val2=1;
                            }
                        }
                    }while(val2==0);
                    cout<<endl;
                    tabellino(c1, c2, c3);
                    cout<<endl;
                    cout<<"    Vuoi giocare ancora?"<<endl;
                    cout<<"    (y -> yes - n -> no) ";
                    cin>>carattere3;
                    if(carattere3=='y' || carattere3=='Y'){
                        val2=0;
                        t=0;
                        tris[0]='1'; tris[1]='2'; tris[2]='3'; tris[3]='4'; tris[4]='5'; tris[5]='6'; tris[6]='7'; tris[7]='8'; tris[8]='9';
                        for(int u=0; u<9; u++)
                            arrscelta[u]=2;
                    }
                    else if(carattere3=='n'){
                        t=0;
                        c1=0;
                        c2=0;
                        c3=0;
                        val3=1;
                        tris[0]='1'; tris[1]='2'; tris[2]='3'; tris[3]='4'; tris[4]='5'; tris[5]='6'; tris[6]='7'; tris[7]='8'; tris[8]='9';
                        for(int u=0; u<9; u++)
                            arrscelta[u]=2;
                    }
                }
            }
            cout<<endl;
            cout<<"    Vuoi giocare ancora o uscire dal gioco?"<<endl;
            cout<<"    (g -> giocare ancora - u -> uscire) ";
            cin>>carattere4;
            if(carattere4=='g' || carattere4=='G')
                val5=0;
            else if(carattere4=='u' || carattere4=='U')
                val5=1;
            cout<<endl;
        }while(val5==0);
    system("PAUSE");
}

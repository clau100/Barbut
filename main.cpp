#include <bits/stdc++.h>
using namespace std;
struct Player{
    int D1{};
    int D2{};
    int credits{};
    string name;
};
Player nr1,nr2;
int s1,s2,nrP,choice,bet;
string R="+-------+",S="|@      |",M="|   @   |",D="|      @|",SD="|@     @|",N="|       |";
void Welcome()
{
    cout<<"Welcome to Barbut"<<endl;
    cout<<"Designed by Claudiu Petrila aka ExitRO"<<endl<<endl;
}
void Rules()
{
    cout<<"This is a gambling game.\nYou play until you have 100 credits (Starting from 10) or until you bust (credits <=0)\n";
    cout<<"First you say if the opponent should go higher or lower than your throws.\nIf they go the way you said, you lose the bet, else you win!\n";
    cout<<"If you throw a 1 1 and you said higer it counts as a 6 6.\nIf you throw a 6 6 and you said lower it counts as a 1 1.\n";
    cout<<"Else, everything is normal.\n";
    choice = -1;
    cout<<"Start playing (1)?";
    cin>>choice;
    while (choice != 1){
        cout<<"Not a valid option";
        cout<<"Start playing (1)?";
        cin>>choice;
    }
}
void GenRandNr()
{
    srand(time(nullptr));
    nr1.D1=rand()%6+1;
    nr1.D2=rand()%6+1;
    nr2.D1=rand()%6+1;
    nr2.D2=rand()%6+1;
}
void DisplayD(int D1,int D2)
{
    cout<<endl<<R<<' '<<R<<endl;
    if (D1==1){
        if(D2==1){
            cout<<N<<' '<<N<<endl<<M<<' '<<M<<endl<<N<<' '<<N<<endl;
        }else if(D2==2){
            cout<<N<<' '<<S<<endl<<M<<' '<<N<<endl<<N<<' '<<D<<endl;
        }else if(D2==3){
            cout<<N<<' '<<D<<endl<<M<<' '<<M<<endl<<N<<' '<<S<<endl;
        }else if(D2==4){
            cout<<N<<' '<<SD<<endl<<M<<' '<<N<<endl<<N<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<N<<' '<<SD<<endl<<M<<' '<<M<<endl<<N<<' '<<SD<<endl;
        }else{
            cout<<N<<' '<<SD<<endl<<M<<' '<<SD<<endl<<N<<' '<<SD<<endl;
        }
    }else if(D1==2){
        if(D2==1){
            cout<<S<<' '<<N<<endl<<N<<' '<<M<<endl<<D<<' '<<N<<endl;
        }else if(D2==2){
            cout<<S<<' '<<S<<endl<<N<<' '<<N<<endl<<D<<' '<<D<<endl;
        }else if(D2==3){
            cout<<S<<' '<<D<<endl<<N<<' '<<M<<endl<<D<<' '<<S<<endl;
        }else if(D2==4){
            cout<<S<<' '<<SD<<endl<<N<<' '<<N<<endl<<D<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<S<<' '<<SD<<endl<<N<<' '<<M<<endl<<D<<' '<<SD<<endl;
        }else{
            cout<<S<<' '<<SD<<endl<<N<<' '<<SD<<endl<<D<<' '<<SD<<endl;
        }
    }else if(D1==3){
        if(D2==1){
            cout<<D<<' '<<N<<endl<<M<<' '<<M<<endl<<S<<' '<<N<<endl;
        }else if(D2==2){
            cout<<D<<' '<<S<<endl<<M<<' '<<N<<endl<<S<<' '<<D<<endl;
        }else if(D2==3){
            cout<<D<<' '<<D<<endl<<M<<' '<<M<<endl<<S<<' '<<S<<endl;
        }else if(D2==4){
            cout<<D<<' '<<SD<<endl<<M<<' '<<N<<endl<<S<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<D<<' '<<SD<<endl<<M<<' '<<M<<endl<<S<<' '<<SD<<endl;
        }else{
            cout<<N<<' '<<SD<<endl<<M<<' '<<SD<<endl<<S<<' '<<SD<<endl;
        }
    }else if(D1==4){
        if(D2==1){
            cout<<SD<<' '<<N<<endl<<N<<' '<<M<<endl<<SD<<' '<<N<<endl;
        }else if(D2==2){
            cout<<SD<<' '<<S<<endl<<N<<' '<<N<<endl<<SD<<' '<<D<<endl;
        }else if(D2==3){
            cout<<SD<<' '<<D<<endl<<N<<' '<<M<<endl<<SD<<' '<<S<<endl;
        }else if(D2==4){
            cout<<SD<<' '<<SD<<endl<<N<<' '<<N<<endl<<SD<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<SD<<' '<<SD<<endl<<N<<' '<<M<<endl<<SD<<' '<<SD<<endl;
        }else{
            cout<<SD<<' '<<SD<<endl<<N<<' '<<SD<<endl<<SD<<' '<<SD<<endl;
        }
    }else if(D1==5){
        if(D2==1){
            cout<<SD<<' '<<N<<endl<<M<<' '<<M<<endl<<SD<<' '<<N<<endl;
        }else if(D2==2){
            cout<<SD<<' '<<S<<endl<<M<<' '<<N<<endl<<SD<<' '<<D<<endl;
        }else if(D2==3){
            cout<<SD<<' '<<D<<endl<<M<<' '<<M<<endl<<SD<<' '<<S<<endl;
        }else if(D2==4){
            cout<<SD<<' '<<SD<<endl<<M<<' '<<N<<endl<<SD<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<SD<<' '<<SD<<endl<<M<<' '<<M<<endl<<SD<<' '<<SD<<endl;
        }else{
            cout<<SD<<' '<<SD<<endl<<M<<' '<<SD<<endl<<SD<<' '<<SD<<endl;
        }
    }else{
        if(D2==1){
            cout<<SD<<' '<<N<<endl<<SD<<' '<<M<<endl<<SD<<' '<<N<<endl;
        }else if(D2==2){
            cout<<SD<<' '<<S<<endl<<SD<<' '<<N<<endl<<SD<<' '<<D<<endl;
        }else if(D2==3){
            cout<<SD<<' '<<D<<endl<<SD<<' '<<M<<endl<<SD<<' '<<S<<endl;
        }else if(D2==4){
            cout<<SD<<' '<<SD<<endl<<SD<<' '<<N<<endl<<SD<<' '<<SD<<endl;
        }else if(D2==5){
            cout<<SD<<' '<<SD<<endl<<SD<<' '<<M<<endl<<SD<<' '<<SD<<endl;
        }else{
            cout<<SD<<' '<<SD<<endl<<SD<<' '<<SD<<endl<<SD<<' '<<SD<<endl;
        }
    }
    cout<<R<<' '<<R<<endl;
}
int main() {
    choice = 0;
    Welcome();
    cout<<"Start playing (1) or Rules (2)?\n";
    cin>>choice;
    while (choice !=1 && choice != 2){
        cout<<"That is not a valid option\n";
        cout<<"Start playing (1) or Rules (2)?\n";
        cin>>choice;
    }
    if (choice == 2){
        Rules();
    }
    cout<<"Play against CPU (1) or against a friend (2)?\n";
    cin>>choice;
    while (choice != 1 && choice != 2){
        cout<<"That is not a valid option.\n";
        cout<<"Play against CPU (1) or against a friend (2)?\n";
        cin>>choice;
    }
    if (choice == 1){
        nr1.credits=10;
        while (nr1.credits>0&&nr1.credits<100){
            for (int i=0;i<20;i++){
                cout<<'\n';
            }
            cout<<"You have "<<nr1.credits<<" credits\n";
            cout<<"Place a bet:\n";
            cin>>bet;
            while(bet<=0||bet>nr1.credits){
                cout<<"You do not have enough credits.\nPlace another bet:\n";
                cin>>bet;
            }
            cout<<"Higher (1) or Lower (2)?\n";
            cin>>choice;
            while (choice !=1 && choice !=2){
                cout<<"That is not a valid option\n";
                cout<<"Higher (1) or Lower (2)?\n";
                cin>>choice;
            }
            GenRandNr();
            cout<<"You threw : ";
            DisplayD(nr1.D1,nr1.D2);
            s1=nr1.D1+nr1.D2;
            cout<<"The CPU threw : ";
            DisplayD(nr2.D1,nr2.D2);
            s2=nr2.D1+nr2.D2;
            if (nr1.D1==nr1.D2&&(nr1.D1==1||nr1.D1==6)){
                if (nr2.D1==nr2.D2&&(nr2.D1==1||nr2.D1==6)){
                    cout<<"It is a TIE.";
                }else{
                    cout<<"You win!";
                    nr1.credits+=bet;
                }
            }else{
                if (nr2.D1==nr2.D2&&(nr2.D1==1||nr2.D1==6)){
                    cout<<"You LOST.";
                    nr1.credits-=bet;
                }else{
                    if (choice==1){
                        if (s2>s1){
                            cout<<"You LOST.";
                            nr1.credits-=bet;
                        }else if (s2==s1){
                            cout<<"It is a TIE.";
                        }else{
                            cout<<"You win!";
                            nr1.credits+=bet;
                        }
                    }else{
                        if (s2<s1){
                            cout<<"You LOST.";
                            nr1.credits-=bet;
                        }else if (s2==s1){
                            cout<<"It is a TIE.";
                        }else{
                            cout<<"You win!";
                            nr1.credits+=bet;
                        }
                    }
                }
            }
            cout<<"\nYou have "<<nr1.credits<<" credits.";
            cout<<"\nPress enter to continue";
            cin.get();
            cin.get();
        }
        if (nr1.credits<=0){
            cout<<"\nYou lost the game!";
            return 0;
        }else{
            cout<<"\nYou won the game!";
            return 0;
        }
    }else{
        nr1.credits=10;nr2.credits=10;
        cout<<"Input the name of the first player without spaces: ";
        cin>>nr1.name;
        cout<<"Input the name of the second player without spaces: ";
        cin>>nr2.name;
        bool ok=false;
        while (min(nr1.credits,nr2.credits)>0&&max(nr1.credits,nr2.credits)<100){
            for (int i=0;i<20;i++){
                cout<<'\n';
            }
            ok=!ok;
            if (ok){
                cout<<nr1.name<<", please place a bet: ";
                cin>>bet;
                while(bet<=0||bet>nr1.credits){
                    cout<<"You do not have enough credits.\nPlace another bet:\n";
                    cin>>bet;
                }
                cout<<nr1.name<<", Higher(1) or Lower(2)?";
                cin>>choice;
                while (choice !=1 && choice !=2){
                    cout<<"That is not a valid option\n";
                    cout<<"Higher (1) or Lower (2)?\n";
                    cin>>choice;
                }
                GenRandNr();
                cout<<nr1.name<<" threw: ";
                DisplayD(nr1.D1,nr1.D2);
                s1=nr1.D1+nr1.D2;
                cout<<nr2.name<<" threw: ";
                DisplayD(nr2.D1,nr2.D2);
                s2=nr2.D1+nr2.D2;
            }else{
                cout<<nr2.name<<", please place a bet: ";
                cin>>bet;
                while(bet<=0||bet>nr2.credits){
                    cout<<"You do not have enough credits.\nPlace another bet:\n";
                    cin>>bet;
                }
                cout<<nr2.name<<", Higher(1) or Lower(2)?";
                cin>>choice;
                while (choice !=1 && choice !=2){
                    cout<<"That is not a valid option\n";
                    cout<<"Higher (1) or Lower (2)?\n";
                    cin>>choice;
                }
                GenRandNr();
                cout<<nr1.name<<" threw: "<<nr1.D1<<' '<<nr1.D2<<'\n';
                s1=nr1.D1+nr1.D2;
                cout<<nr2.name<<" threw: "<<nr2.D1<<' '<<nr2.D2<<'\n';
                s2=nr2.D1+nr2.D2;
            }
            if (nr1.D1==nr1.D2&&(nr1.D1==1||nr1.D1==6)){
                if (nr2.D1==nr2.D2&&(nr2.D1==1||nr2.D1==6)){
                    cout<<"It is a TIE.";
                }else{
                    cout<<nr1.name<<" won!";
                    nr1.credits+=bet;
                    nr2.credits-=bet;
                }
            }else{
                if (nr2.D1==nr2.D2&&(nr2.D1==1||nr2.D1==6)){
                    cout<<nr2.name<<" won!";
                    nr1.credits-=bet;
                    nr2.credits+=bet;
                }else{
                    if (choice==1){
                        if (s2>s1){
                            cout<<nr2.name<<" won";
                            nr1.credits-=bet;
                            nr2.credits+=bet;
                        }else if (s2==s1){
                            cout<<"It is a TIE.";
                        }else{
                            cout<<nr1.name<<" won!";
                            nr1.credits+=bet;
                            nr2.credits-=bet;
                        }
                    }else{
                        if (s2<s1){
                            cout<<nr2.name<<" won!";
                            nr1.credits-=bet;
                            nr2.credits+=bet;
                        }else if (s2==s1){
                            cout<<"It is a TIE.";
                        }else{
                            cout<<nr1.name<<" won!";
                            nr1.credits+=bet;
                            nr2.credits-=bet;
                        }
                    }
                }
            }
            cout<<'\n'<<nr1.name<<" has "<<nr1.credits<<" credits.\n";
            cout<<nr2.name<<" has "<<nr2.credits<<" credits.\n";
            cout<<"Press enter to continue.\n";
            cin.get();
            cin.get();
        }
        if (nr1.credits<0||nr2.credits>=100){
            cout<<nr2.name<<" won the game!";
        }else{
            cout<<nr1.name<<" won the game!";
        }
    }
}

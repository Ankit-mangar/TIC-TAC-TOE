#include <bits/stdc++.h>

using namespace std;
char a[9]={'1','2','3','4','5','6','7','8','9'};
int flag[9]={0,0,0,0,0,0,0,0,0};

void draw()
{
    for(int i=0;i<9;i++){
        if(i==3||i==6||i==9){
            cout<<endl;
            cout<<"+-++-++-+-"<<endl;
        }
        if(a[i]=='X'||a[i]=='O')
            cout<<"|"<<a[i]<<"|";
        else
            cout<<"|"<<" "<<"|";
    }
    cout<<endl;
}
void player1()
{
    a:
    int input;
    cout<<"player 1 enter block no. to put X: ";
    cin>>input;
    if(input>9||input==0){
        cout<<"invalid\n";
        goto a;
    }
    cout<<endl;
    if(flag[input-1]==1){
        cout<<"invalid entry\n";
        goto a;
    }
    else{
        a[input-1]='X';
        flag[input-1]=1;
    }
    draw();
}
void player2()
{
    a:
    int input;
    cout<<"player 2 enter block no. to put O: ";
    cin>>input;
    if(input>9||input==0){
        cout<<"invalid\n";
        goto a;
    }
    cout<<endl;
    if(flag[input-1]==1){
        cout<<"invalid entry\n";
        goto a;
    }
    else{
        a[input-1]='O';
        flag[input-1]=1;
    }
    draw();
}
int check()
{
    if(a[0]==a[1]&&a[1]==a[2]){
        return(1);
    }
    else if(a[3]==a[4]&&a[4]==a[5]){
        return(1);
    }
    else if(a[6]==a[7]&&a[7]==a[8]){
        return(1);
    }
    else if(a[0]==a[4]&&a[4]==a[8]){
        return(1);
    }
    else if(a[6]==a[4]&&a[4]==a[2]){
        return(1);
    }
    else if(a[0]==a[3]&&a[3]==a[6]){
        return(1);
    }
    else if(a[1]==a[4]&&a[4]==a[7]){
        return(1);
    }
    else if(a[2]==a[5]&&a[5]==a[8]){
        return(1);
    }
}
void player()
{
    a:
    int input;
    cout<<"player enter block no. to put X: ";
    cin>>input;
    if(input>9||input==0){
        cout<<"invalid\n";
        goto a;
    }
    cout<<endl;
    if(flag[input-1]==1){
        cout<<"invalid entry\n";
        goto a;
    }
    else{
        a[input-1]='X';
        flag[input-1]=1;
    }
    draw();
}
void comp()
{
    a:
    int input;
    input = (rand() % 9) + 1;
    if(input>9||input==0){
        goto a;
    }
    cout<<endl;
    if(flag[input-1]==1){
        goto a;
    }
    else{
        a[input-1]='O';
        flag[input-1]=1;
    }
    cout<<"computer puts at "<<input<<endl;
    draw();
}
int main()
{
    start:
    for(int i=0;i<=8;i++){
        flag[i]=0;
    }
    for(int i=1;i<=9;i++){
        a[i-1]=i;
    }
    system("cls");
    for(int i=0;i<9;i++){
        if(i==3||i==6||i==9){
            cout<<endl;
            cout<<"+-++-++-+-"<<endl;
        }
        cout<<"|"<<i+1<<"|";
    }
    cout<<endl;
    int n;
    cout<<"press 1 for 2 players"<<endl;
    cout<<"press 2 to play with computer"<<endl;
    cout<<"enter your choice: ";
    cin>>n;
    //cout<<endl;
    if(n==1){
        cout<<"PLAYER 1------> X\n";
        cout<<"PLAYER 2------> O\n";
        for(int i=0;i<9;i++){
            if(i%2==0){
                int inp;
                player1();
                int num=check();
                if(num==1){
                    cout<<"PLAYER 1 WON\n";
                    cout<<"PRESS 1 TO CONTINUE\n";
                    cout<<"PRESS ANY OTHER NO. TO EXIT\n";
                    cin>>inp;
                    if(inp==1)
                        goto start;
                    else
                        exit(0);
                }
            }
            else{
                int inp;
                player2();
                int num=check();
                if(num==1){
                    cout<<"PLAYER 2 WON\n";
                    cout<<"PRESS 1 TO CONTINUE\n";
                    cout<<"PRESS ANY OTHER NO. TO EXIT\n";
                    cin>>inp;
                    if(inp==1)
                        goto start;
                    else
                        exit(0);
                }
            }
        }
    }
    else{
        cout<<"PLAYER ------> X\n";
        cout<<"COMPUTER ------> O\n";
        for(int i=0;i<9;i++){
            if(i%2==0){
                int inp;
                player();
                int num=check();
                if(num==1){
                    cout<<"PLAYER WON\n";
                    cout<<"PRESS 1 TO CONTINUE\n";
                    cout<<"PRESS ANY OTHER NO. TO EXIT\n";
                    cin>>inp;
                    if(inp==1)
                        goto start;
                    else
                        exit(0);
                }
            }
            else{
                int inp;
                comp();
                int num=check();
                if(num==1){
                    cout<<"COMP WON\n";
                    cout<<"PRESS 1 TO CONTINUE\n";
                    cout<<"PRESS ANY OTHER NO. TO EXIT\n";
                    cin>>inp;
                    if(inp==1)
                        goto start;
                    else
                        exit(0);
                }
            }
        }
    }
    int inp;
    cout<<"DRAW\n";
    cout<<"PRESS 1 TO CONTINUE\n";
    cout<<"PRESS ANY OTHER NO. TO EXIT\n";
    cin>>inp;
    if(inp==1)
        goto start;
    else
        exit(0);
    return 0;
}

#include <iostream>
using namespace std;
void initabuleiro(int tabuleiro[][3]); //inicia tabuleiro
char imbloco(int bloco); //cada parte do tabuleiro
void show(int tabuleiro[][3]); //mostra tabuleiro
void jogada(int tabuleiro[][3], int); //Jogada
int checkContinue(int *tabuleiro[3]); //ainda tem espaço?
int checkWin(int *tabuleiro[3]); //alguem ganhou?
int jogo(int tabuleiro[][3]);
void placar(int, int &, int &);

int main() {
  int tabuleiro[3][3];
  int cont=0, jogador1=0, jogador2=0, resultado;
  
  do{
    initabuleiro(tabuleiro);
    resultado = jogo(tabuleiro);
    show(tabuleiro);
    placar (resultado, jogador1, jogador2);

    cout<<"\nJogar novamente?"<<endl;
    cout<<"0. Sair"<<endl;
    cout<<"1. Jogar novamente"<<endl;
    cin>>cont;
  } while(cont);

  return 0;
  
}



void initabuleiro(int tabuleiro[][3]) {
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    tabuleiro[i][j]=0;
}
char imbloco (int bloco) {
  if(bloco == 0)
    return ' ';
  if(bloco == 1)
    return 'X';
  else
    return 'O';
}
void show(int tabuleiro[][3]) {
  cout<<endl;
  for(int row=0;row<3;row++){
    cout<<" "<< imbloco(tabuleiro[row][0]) <<" |";
    cout<<" "<< imbloco(tabuleiro[row][1]) <<" |";
    cout<<" "<< imbloco(tabuleiro[row][2]) <<endl;

    if(row!=2){
      cout<<"___ ___ ___\n"<<endl;
    }
  }
}
void jogada(int tabuleiro[][3], int jogador) {
  int row, col, check;
  do{
    cout<<"Linha: ";
    cin >>row;
    cout<<"Coluna: ";
    cin >>col;
    row--; col--;

    check = tabuleiro[row][col] || row<0 || row>2 || col<0 || col>2;
    if(check)
      cout<<"CASA PREENCHIDA OU FORA DO TABULEIRO"<<endl;
  }
    while(check);

  if(jogador==0)
    tabuleiro[row][col]=1;
  else
    tabuleiro[row][col]=-1;
}
int checkContinue(int tabuleiro[][3]) {
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(tabuleiro[i][j]==0)
        return 1;
  return 0;
}
//verifica se ganhou somando os números de cada jogador na linhas, colunas e diagonais
int checkWin(int tabuleiro[][3]) {
  int row, col, sum;

  for(row=0;row<3;row++){
    sum = 0;

    for(col=0;col<3;col++)
      sum += tabuleiro[row][col];

    if(sum==3)
      return 1;
    if(sum==-3)
      return -1;
  }
  for(col=0;col<3;col++){
    sum=0;

    for(row=0;row<3;row++)
      sum += tabuleiro[row][col];

    if(sum==3)
      return 1;
    if(sum==-3)
      return -1;
  }
  sum = 0;
  for(row=0;row<3;row++)
    sum += tabuleiro[row][row];
  
  if(sum==3)
    return 1;
  if(sum==-3)
    return -1;

  sum= tabuleiro[0][2]+tabuleiro[1][1]+tabuleiro[2][0];
  if(sum==3)
    return 1;
  if(sum==-3)
    return -1;

  return 0;
}

int jogo(int tabuleiro[][3]){
  int turn=0, cont, win;
  
  do{
    show(tabuleiro);
    cout<<"Jogador"<<1+turn%2<<endl;
    jogada(tabuleiro, turn%2);
    turn++;

    cont=checkContinue(tabuleiro);
    win=checkWin(tabuleiro);
  } while(cont && !win);

  if(win==1){
    cout<<"Jogador 1 venceu!\n"<<endl;
    return 1;
  }else
   if(win==-1){
    cout<<"Jogador 2 venceu!\n"<<endl;
    return 2;
  }else
     cout<<"Empate!\n"<<endl;
  return 0;
}
void placar(int resultado, int &jogador1, int &jogador2){
  if(resultado == 1)
    jogador1++;
  if(resultado == 2)
    jogador2++;

  cout<<"PLACAR: "<<endl;
  cout<<jogador1<<" X "<<jogador2<<endl;
}

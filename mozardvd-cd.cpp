#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>


using namespace std;

class IAlugavel
{
    public:
        virtual void ler()=0;
        virtual void mostrar()=0;
        virtual int getCodigo()=0;
        virtual string getProdutora()=0;
        virtual string getMidia()=0;
        virtual int getAno()=0;
        virtual string getGenero()=0;
        virtual string getNome()=0;
        virtual string getTipo()=0;
       
        
};

class Item : public IAlugavel
{
    
        public:
        int cod,ano,valor,qtd;
        string midi,pro,gene,nome,jf;
        void ler(){
            cout<<"codigo: ";
            cin>>cod;
            cout<<"Nome: ";
            cin.ignore();
            getline (cin,nome);
            cout<<"Produtora: ";
           // 
            getline (cin,pro);
            cout<<"midia: ";
            cin.ignore();
            getline (cin,midi);
            cout<<"ano: ";
            cin>>ano;
            cin.ignore();
            cout<<"Genero: ";
            getline (cin,gene);
            //cin.ignore();
        };
      
        int getCodigo(){return cod;};
        string getProdutora(){return pro;};
        string getMidia(){return midi;};
        int getAno(){return ano;};
        string getGenero(){return gene;};
        string getNome(){return nome;}; 
        void mostrar(){};
        string getTipo(){return jf;};
};



class jogo : public virtual Item
{
    public:
    double preco=0,valor;
    int jogadores;
    string plataforma; 
    void ler();
    void calcular();
    int getjogadores(){return jogadores;};
    double getpreco(){return preco;};
    string getplataforma(){return plataforma;};
    string getTipo(){return jf;};
    void mostrar();
    
       
};



void jogo::ler()
{
    Item::ler();
    cout<<"numero de jogadores: ";
    cin>>jogadores;
    cin.ignore();
    cout<<"Plataforma:";
    getline (cin,plataforma);
    if(ano<2020) preco=7;
    else if(ano>=2020) preco=12;
    jf="jogo";
    calcular();
    
    
}

void jogo::calcular()
{
        if(plataforma=="xbox series" || plataforma=="ps5" || plataforma=="nintendo switch" ){preco= preco - 1.0;}
        else{preco = preco - 0.6;}
  
}
void jogo::mostrar()
{
    cout<<"__________________JOGOS___________________________"<<endl;
    cout<<"Nome:"<<getNome()<< setfill('0') << setw(4)<<" cod. "<<getCodigo()<<endl;
    cout<<"produtora:"<<getProdutora()<<setfill(' ') << setw(30) << right<<"  Ano:   "<<getAno()<<endl;
    cout<<"Genero: "<<getGenero()<<setfill(' ') << setw(30) << right<<"  Plataforma: "<<getplataforma()<<endl;
    cout<<"N.jogadores: "<<getjogadores()<<setfill(' ') << setw(30) << right<<" preco: "<<getpreco()<<endl;
}


class filme : public virtual Item
{
    public:
    double preco=0;
    string ator, diretor,jf;
    void ler();
    void aluguei();
    void mostrar();
    string getdiretor(){return diretor;};
    string getator(){return ator;};
    double getpreco(){return preco;};
    string getTipo(){return jf;};
    
    
       
};

void filme::ler()
{
    Item::ler();
    //cin.ignore();
    cout<<"Ator principal: ";
    getline (cin,ator);
    cout<<"diretor: ";
    getline (cin,diretor);
    jf="filme";
    aluguei();
}

void filme::aluguei()
{
        if(ano<2020){preco= 5;}
        else{preco = 7;}
  
}

void filme::mostrar()
{
    cout<<endl<<endl;
    cout << setprecision(2) << fixed;
    cout<<"__________________FILMES___________________________"<<endl;
    cout<<"Nome:"<<getNome()<<"    cod. "<< setfill('0') << setw(4)<<getCodigo()<<endl;
    cout<<"produtora:"<<getProdutora() <<setfill(' ') << setw(30) << right<<"  Ano:   "<<getAno()<<endl;
    cout<<"Genero: "<<getGenero()<<  setfill(' ') << setw(30) << right<<"  Ator principal: "<<getator()<<endl;
    cout<<"diretor: "<<getdiretor()<< setfill(' ') << setw(30)<<right <<" preco: "<<getpreco()<<endl;
    
}

class locadora {
private:
    Item* v[100];
    int qtd;

public:
    locadora();
    virtual ~locadora();
    int achar(int x);
    void inserir(Item *a);
    void remover(int x);
    void alterar(int x);
    void listar();
    void mostrarp();
    void valore(int x);
};

locadora::~locadora(){
    for (int i = 0; i < qtd; i++)
        delete v[i];
}

locadora::locadora(){
    qtd = 0;
}


Item* criar()
{
    int opc;
    do{
        cout<<"_____escolha__um__tipo__de__midia_______"<<endl;
        cout << "1 - jogo" << endl;
        cout << "2 - filme" << endl;
        cout<<"------------------------------------------"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opc;
    } while (opc < 1 || opc > 2);
    switch (opc){
    case 1:
        return new jogo();
    case 2:
        return new filme();
    default:
        cout << endl
             << "Opcao invalida!" << endl;
        exit(0);
    }
}


void locadora::inserir( Item *a){
    v[qtd] = a;
    qtd++;
}

int locadora::achar(int x)
        {
            int i = 0;
            bool achou = 0;
            while ( achou==0 && i < qtd )
            {
                 if ( v[i]->getCodigo() == x )
                    achou = 1;
                 else 
                 i++;
            }
        return achou ? i : -1;
        };


void locadora::valore(int x)
{
    int p=achar(x);
    if(p>-1)
    {
        v[p]->mostrar();
    }
}

void locadora::remover(int x)
        {
            int posicao = achar(x);
            int i;
            if ( posicao > -1 )
                     {
            for ( i = posicao+1 ; i < qtd ; i++, posicao++ )
                    {
                            v[posicao] = v[i];
                    }
                    qtd--;
                 cout << "Removido com sucesso!" << endl;
                 }
                else cout << "Nao foi possivel encontrar!" << endl;
            
        };

void locadora::alterar(int x)
{
    int posicao = achar(x);
    if ( posicao > -1 )
    {
        v[posicao]->ler();
        cout << "Alterada com sucesso!" << endl;
    }
    else 
        cout << "Nao foi possivel encontrar!" << endl;
}

void locadora::listar(){
    cout<<endl<<endl;
    for (int i = 0; i < qtd; i++){
        v[i]->mostrar();
    }
    cout<<endl<<endl;
}

void locadora::mostrarp()
{
    int i, nom = 0, mid = 0,gen=0,jf=0,ano=0;
    cout<<"insira( nome/titulo, genero, jogo/filme, midia ou ano )"<<endl;
    string s,p;
    
    cin.ignore();
    getline(cin,s);
    for(i = 0; i<qtd; i++)
    {
        p=v[i]->getAno();
        if(p==s)ano=1;
        nom = v[i]->getNome().find(s);
        mid = v[i]->getMidia().find(s);
        gen = v[i]->getGenero().find(s);
        jf  = v[i]->getTipo().find(s);
        if (nom > -1 || mid > -1 ||gen >-1 ||jf > -1 || ano > -1) listar();
    }


}


int menu(){
    int opc;
    do{
        cout<<"________________locadora _____________________"<<endl;
        cout << "1. inserir" << endl
             << "2. remover por codigo" << endl
             << "3. alterar por codigo"<<endl
             << "4. listar tudo"<<endl
             << "5. busca"<<endl
             << "6. mostrar pelo valor"<<endl
             << "7. Sair" << endl
             <<"_____________________________________________"<<endl
             << "Escolha uma opcao: ";
        cin >> opc;
    }while (opc < 1 || opc > 7);

    return opc;

}

        
int main()
{
    
    Item* a;
    locadora k;
    int c=0;
    bool treco=false;
    do{
        switch (menu()){
          case 1:
                a = criar();
                a->ler();
                k.inserir(a);
                cout << "Inserida com sucesso!" << endl;
                break;
          case 2:
                cout<<"digite o codigo, por favor:";
                cin>>c;
                k.remover(c);
                break;
         case 3:
                cout<<"digite o codigo, por favor:";
                cin>>c;
                k.alterar(c);
                break;
         case 4:
                k.listar();
                break;
         case 5:
                k.mostrarp();
                break;
        case 6:
                cout<<"digite o codigo, por favor:";
                cin>>c;
                k.valore(c);
                break;
          case 7:
            treco =true;
            cout << "Obrigado por utilizar nosso programa <3" << endl;
        }
    }while(treco!=true);
    return 0;
}



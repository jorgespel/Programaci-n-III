#include <iostream>
using namespace std;

struct Nodo {
    int dato, orden;
    string tipo;
    Nodo *sig, *ant, *izq, *der;
};

Nodo *pila=NULL, *cola=NULL, *fin=NULL, *neg=NULL, *hist=NULL, *bst=NULL;
int pares=0, impares=0, negativos=0, ceros=0, validos=0, cont=1;
int mayor, menor;
bool hay=false, bstOk=false;

Nodo* crear(int x){
    Nodo* n = new Nodo;
    n->dato=x; n->orden=0; n->tipo="";
    n->sig=n->ant=n->izq=n->der=NULL;
    return n;
}

void lista(Nodo*& l, int x){
    Nodo* n=crear(x);
    if(!l) l=n;
    else{
        Nodo* a=l;
        while(a->sig) a=a->sig;
        a->sig=n;
    }
}

void guardarHist(int x, string t){
    Nodo* n=crear(x);
    n->tipo=t;
    n->orden=cont++;

    if(!hist) hist=n;
    else{
        Nodo* a=hist;
        while(a->sig) a=a->sig;
        a->sig=n;
        n->ant=a;
    }
}

void push(int x){
    Nodo* n=crear(x);
    n->sig=pila;
    pila=n;
}

void encolar(int x){
    Nodo* n=crear(x);
    if(!cola) cola=fin=n;
    else{
        fin->sig=n;
        fin=n;
    }
}

Nodo* insBST(Nodo* r, int x){
    if(!r) return crear(x);
    if(x < r->dato) r->izq=insBST(r->izq,x);
    else r->der=insBST(r->der,x);
    return r;
}

void in(Nodo* r){
    if(r){ in(r->izq); cout<<r->dato<<" "; in(r->der); }
}

void pre(Nodo* r){
    if(r){ cout<<r->dato<<" "; pre(r->izq); pre(r->der); }
}

void post(Nodo* r){
    if(r){ post(r->izq); post(r->der); cout<<r->dato<<" "; }
}

void mostrar(Nodo* l){
    if(!l){ cout<<"Vacio\n"; return; }
    while(l){ cout<<l->dato<<" "; l=l->sig; }
    cout<<endl;
}

void mostrarHist(){
    if(!hist){ cout<<"Historial vacio\n"; return; }
    Nodo* a=hist;
    while(a){
        cout<<a->orden<<". "<<a->dato<<" -> "<<a->tipo<<endl;
        a=a->sig;
    }
}

void ingresar(){
    int n,x;
    do{
        cout<<"Cantidad: ";
        cin>>n;
    }while(n<=0);

    for(int i=0;i<n;i++){
        cout<<"Numero: ";
        cin>>x;

        if(x==0){
            ceros++;
            cout<<"Cero rechazado\n";
            continue;
        }

        if(!hay){ mayor=menor=x; hay=true; }
        if(x>mayor) mayor=x;
        if(x<menor) menor=x;

        if(x>0 && x%2==0){
            encolar(x);
            guardarHist(x,"COLA");
            pares++;
        }else if(x>0){
            push(x);
            guardarHist(x,"PILA");
            impares++;
        }else{
            lista(neg,x);
            guardarHist(x,"LISTA SIMPLE");
            negativos++;
        }

        validos++;
        bstOk=false;
    }
}

void construirBST(){
    bst=NULL;
    Nodo* a=hist;

    while(a){
        if(a->dato>0)
            bst=insBST(bst,a->dato);
        a=a->sig;
    }

    if(!bst){
        cout<<"No hay positivos para el BST\n";
        return;
    }

    bstOk=true;
    cout<<"InOrden: "; in(bst);
    cout<<"\nPreOrden: "; pre(bst);
    cout<<"\nPostOrden: "; post(bst);
    cout<<endl;
}

bool buscar(Nodo* r, int x){
    if(!r) return false;
    if(r->dato==x) return true;
    if(x < r->dato) return buscar(r->izq,x);
    return buscar(r->der,x);
}

void eliminarNeg(){
    cout<<"Original: ";
    mostrar(neg);

    int elim=0;

    while(neg && neg->dato>-10){
        Nodo* b=neg;
        neg=neg->sig;
        delete b;
        elim++;
    }

    Nodo* a=neg;
    while(a && a->sig){
        if(a->sig->dato>-10){
            Nodo* b=a->sig;
            a->sig=b->sig;
            delete b;
            elim++;
        }else a=a->sig;
    }

    cout<<"Resultante: ";
    mostrar(neg);
    cout<<"Eliminados: "<<elim<<endl;
}

void estadisticas(){
    cout<<"Pares positivos: "<<pares<<endl;
    cout<<"Impares positivos: "<<impares<<endl;
    cout<<"Negativos: "<<negativos<<endl;
    cout<<"Ceros rechazados: "<<ceros<<endl;
    cout<<"Total validos: "<<validos<<endl;

    if(hay){
        cout<<"Mayor: "<<mayor<<endl;
        cout<<"Menor: "<<menor<<endl;
    }
}

void reorganizar(){
    Nodo *lp=NULL, *lc=NULL;

    while(pila){
        lista(lp,pila->dato);
        Nodo* b=pila;
        pila=pila->sig;
        delete b;
    }

    while(cola){
        lista(lc,cola->dato);
        Nodo* b=cola;
        cola=cola->sig;
        delete b;
    }

    fin=NULL;

    cout<<"Lista de pila: ";
    mostrar(lp);

    cout<<"Lista de cola: ";
    mostrar(lc);

    bst=NULL;

    Nodo* a=lp;
    while(a){ bst=insBST(bst,a->dato); a=a->sig; }

    a=lc;
    while(a){ bst=insBST(bst,a->dato); a=a->sig; }

    cout<<"BST reorganizado InOrden: ";
    in(bst);
    cout<<endl;

    bstOk=true;
}

int main(){
    int op,x;

    do{
        cout << "\n====================================\n";
        cout << "EXAMEN PARCIAL II\n";
        cout << "Estudiante: Jorge Eduardo Espel Melgar \n";
        cout << "Carnet: 9941-24-10596\n";
        cout << "Seccion: B\n";
        cout << "====================================\n";
        cout<<"1.Ingresar\n2.Pila\n3.Cola\n4.Negativos\n5.Historial\n";
        cout<<"6.BST\n7.Eliminar negativos\n8.Buscar BST\n9.Estadisticas\n10.Reorganizar\n11.Salir\n";
        cout<<"Opcion: ";
        cin>>op;

        switch(op){
            case 1: ingresar(); break;
            case 2: cout<<"Pila: "; mostrar(pila); break;
            case 3: cout<<"Cola: "; mostrar(cola); break;
            case 4: cout<<"Negativos: "; mostrar(neg); break;
            case 5: mostrarHist(); break;
            case 6: construirBST(); break;
            case 7: eliminarNeg(); break;
            case 8:
                if(!bstOk) cout<<"Primero construya el BST\n";
                else{
                    cout<<"Valor: "; cin>>x;
                    if(buscar(bst,x)) cout<<"Encontrado\n";
                    else cout<<"No encontrado\n";
                }
                break;
            case 9: estadisticas(); break;
            case 10: reorganizar(); break;
            case 11: cout<<"Fin del programa\n"; break;
            default: cout<<"Opcion invalida\n";
        }

    }while(op!=11);
    return 0;
}
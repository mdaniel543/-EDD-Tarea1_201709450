/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arbolb;

/**
 *
 * @author mdani
 */
public class ArbolB {
    Nodo root;
    int t;

    public ArbolB(int t) {
        this.t = t;
        root = new Nodo(t);
    }
    public void insertar(int key) {
        Nodo r = root;
        //Si el nodo esta lleno lo debe separar antes de insertar
        if (r.n == ((2 * t) - 1)) {
            Nodo s = new Nodo(t);
            root = s;
            s.leaf = false;
            s.n = 0;
            s.child[0] = r;
            split(s, 0, r);
            nonFullInsert(s, key);
        } else {
            nonFullInsert(r, key);
        }
    }
    private void nonFullInsert(Nodo x, int key) {
        //Si es una hoja
        if (x.leaf) {
            int i = x.n; //cantidad de valores del nodo
            //busca la posicion i donde asignar el valor
            while (i >= 1 && key < x.key[i - 1]) {
                x.key[i] = x.key[i - 1];//Desplaza los valores mayores a key
                i--;
            }
            x.key[i] = key;//asigna el valor al nodo
            x.n++; //aumenta la cantidad de elementos del nodo
        } else {
            int j = 0;
            //Busca la posicion del hijo
            while (j < x.n && key > x.key[j]) {
                j++;
            }
            //Si el nodo hijo esta lleno lo separa
            if (x.child[j].n == (2 * t - 1)) {
                split(x, j, x.child[j]);
                if (key > x.key[j]) {
                    j++;
                }
            }
            nonFullInsert(x.child[j], key);
        }
    }
    private void split(Nodo x, int i, Nodo y) {
        //Nodo temporal que sera el hijo i + 1 de x
        Nodo z = new Nodo(t);
        z.leaf = y.leaf;
        z.n = (t - 1);
        //Copia las ultimas (t - 1) claves del nodo y al inicio del nodo z      
        for (int j = 0; j < (t - 1); j++) {
            z.key[j] = y.key[(j + t)];
        }
        //Si no es hoja hay que reasignar los nodos hijos
        if (!y.leaf) {
            for (int k = 0; k < t; k++) {
                z.child[k] = y.child[(k + t)];
            }
        }
        //nuevo tamanio de y                                                    
        y.n = (t - 1);                                                                                                                                 
        //Mueve los hijos de x para darle espacio a z
        for (int j = x.n; j > i; j--) {
            x.child[(j + 1)] = x.child[j];
        }
        //Reasigna el hijo (i+1) de x                                           
        x.child[(i + 1)] = z;                                                  
        //Mueve las claves de x
        for (int j = x.n; j > i; j--) {
            x.key[(j + 1)] = x.key[j];
        }
        //Agrega la clave situada en la mediana                                 
        x.key[i] = y.key[(t - 1)];                                              
        x.n++;                                                                  
    }
    public void showBTree() {
        print(root, 1);
    }
    //Print en preorder
    private void print(Nodo n, int t) {
        if(t == 1){
            tabulacion(t+1);
        }else{
            tabulacion(t);
        }
        n.imprimir();
        //Si no es hoja
        if (!n.leaf) {
            System.out.println();
            //recorre los nodos para saber si tiene hijos
            for (int j = 0; j <= n.n; j++) {
                if (n.child[j] != null) {
                    if(n.key[0] > n.child[j].key[0]){
                        t--;
                        print(n.child[j], t);
                    }else{
                        t++;
                        t++;
                        print(n.child[j], t);
                        t--;
                        t--;
                    }
                    
                }
            }
        }
    }
    private void tabulacion(int t){
        for(int i = 0; i < t; i++){
            System.out.print("\t");
        }
    }
}

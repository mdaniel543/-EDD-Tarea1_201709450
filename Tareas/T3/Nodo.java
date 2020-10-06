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
public class Nodo {
    int n; //numero de claves 
    boolean leaf; // nodo hoja
    int key[]; //almacena las claves 
    Nodo child[]; //referencia a hijos

    public Nodo(int t) {
        this.n = 0;
        this.leaf = true;
        this.key = new int[((2*t)-1)];
        this.child = new Nodo[(2*t)];
    }
    
    public void imprimir() {
        System.out.print("[");
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                System.out.print(key[i] + " | ");
            } else {
                System.out.print(key[i]);
            }
        }
        System.out.print("]");
    }
}

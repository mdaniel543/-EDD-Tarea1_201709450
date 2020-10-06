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
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Grado minimo del Arbol B es t = 2
        //Cada nodo soporta 2t hijos y 2t-1 claves
        int t = 2; //orden N = 4
        //Se crea el Arbol B segun t
        ArbolB arbolB = new ArbolB(t);
        
        int[] valoresUno = {6, 11, 5, 4, 8, 9, 12, 21};
        for(int i=0; i<valoresUno.length; i++) {
            arbolB.insertar(valoresUno[i]);
        }
        //Mostrando arbol B por pantalla en preorden
        System.out.println("\t----El ARBOL B ES:----");
        arbolB.showBTree();
        System.out.println("");
    }
}

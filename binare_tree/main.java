package Ordenacao.binare_tree;

public class main {

    public static void main(String[] args) {
        binary_tree first_Tree = new binary_tree();
        first_Tree.insere_no(10);
        first_Tree.insere_no(12);
        first_Tree.insere_no(13);

        first_Tree.print(first_Tree.raiz);
        System.out.println("Fim first_tree");

        binary_tree secondTree = new binary_tree();

        secondTree.insere_recursivo_final(20);
        secondTree.insere_recursivo_final(30);
        secondTree.print(secondTree.raiz);

    }

}

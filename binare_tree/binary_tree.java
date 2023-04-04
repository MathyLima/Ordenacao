package Ordenacao.binare_tree;

import java.util.Random;

public class binary_tree {
    public binary_node raiz;

    boolean insere_no(int info) {
        if (raiz == null) {
            this.raiz = binary_node.cria_no(info);
            return (raiz != null);
        }
        binary_node aux = raiz;
        while (true) {
            Random gerador = new Random();
            int m = gerador.nextInt(2);
            if (m == 0) {
                if (aux.fe == null) {
                    aux.fe = binary_node.cria_no(info);
                    return (aux.fe != null);
                } else
                    aux = aux.fe;
            } else {
                if (aux.fd == null) {
                    aux.fd = binary_node.cria_no(info);
                    return (aux.fd != null);
                } else {
                    aux = aux.fd;
                }
            }

        }
    }

    boolean insere_recursivo_1parte(binary_node root, int info) {
        root = raiz;
        if (root == null) {
            root = binary_node.cria_no(info);
            return root != null;
        }
        System.out.println("PASSOU");
        Random randomiza = new Random();
        int sorteia = randomiza.nextInt(2);

        if (sorteia == 0) {
            return (insere_recursivo_1parte(root.fe, info));
        } else
            return (insere_recursivo_1parte(root.fd, info));
    }

    boolean insere_recursivo_final(int info) {
        return (insere_recursivo_1parte(raiz, info));
    }

    void print(binary_node no) {
        if (no != null) {
            System.out.println("info = " + no.info);
            print(no.fe);

            print(no.fd);
        }
    }

    binary_node busca(binary_node raiz, int info) {
        if (raiz == null)
            return null;
        if (raiz.info == info)
            return raiz;

        binary_node esquerda = busca(raiz.fe, info);
        if (esquerda != null)
            return esquerda;
        binary_node direita = busca(raiz.fd, info);
        if (direita != null)
            return direita;

        return null;

    }
}

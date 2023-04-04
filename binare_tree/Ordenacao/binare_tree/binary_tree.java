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

        if (this.raiz == null) {
            this.raiz = binary_node.cria_no(info);
            return this.raiz != null;
        }
        if (root.getNoEsq() != null) {
            insere_recursivo_1parte(root.getNoEsq(), info);
        } else {
            this.raiz.fe = binary_node.cria_no(info);
            return this.raiz.fe != null;
        }
        if (root.getNoDir() != null) {
            insere_recursivo_1parte(root.getNoDir(), info);
        } else {
            this.raiz.fd = binary_node.cria_no(info);
            return this.raiz.fd != null;
        }
        return true;
    }

    boolean insere_recursivo_final(int info) {
        return (insere_recursivo_1parte(this.raiz, info));

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

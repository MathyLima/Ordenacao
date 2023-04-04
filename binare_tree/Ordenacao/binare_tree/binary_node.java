
package Ordenacao.binare_tree;

public class binary_node {
    public int info;
    public binary_node fe;
    public binary_node fd;

    binary_node() {
        info = 0;
        fe = null;
        fd = null;
    }

    static binary_node cria_no(int info) {
        binary_node novo_no = new binary_node();
        if (novo_no != null) {
            novo_no.info = info;
            novo_no.fe = null;
            novo_no.fd = null;
        }

        return novo_no;
    }

    public binary_node getNoEsq() {
        return fe;
    }

    public void setNoEsq(int info) {
        this.fe.info = info;
    }

    public binary_node getNoDir() {
        return fd;
    }

    public void setNoDir(int info) {
        this.fd.info = info;
    }

}

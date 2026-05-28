#include <iostream>
#include <string>

using namespace std;

#define T 50

struct Categorias { // REFRI, PIZZA
    int codigo;
    string descricao;
};

struct Produtos { // COCA-COLA, CALABRESA
    int codigo;
    string descricao;
    int codigo_categoria;
    float preco_unitario;
};

struct Ingredientes {
    int codigo;
    string descricao;
    int quant_estoque;
    int quant_estoque_minimo;
    int quant_estoque_maximo;
    float preco_unitario;
};

struct  Clientes {
    int codigo;
    string nome;
    string telefone;
};

struct Garcons {
    int codigo;
    string nome;
};

struct Pedidos {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    //codigo_data
};

struct ItensPedido {
    int codigo_pedido;
    int codigo_produto;
    int quantidade;
};

struct ConsumoIngredientes {
    int codigo_produto;
    int codigo_ingrediente;
    int quantidade_necessaria;
};

void lerCategorias(Categorias *categorias) {
    int encerrar = 0;
    for (int i = 0; encerrar == 0 && i < 5; i++) {

        int codigo;

        cout << "Digite o ID da categoria ou 0 para sair: ";
        cin >> codigo;

        if (codigo == 0) {
            encerrar = 1;
        } else {
            categorias[i].codigo = codigo;
            cout << "Digite a descrição da categoria: ";
            cin >> categorias[i].descricao;
        }
    }
}

void lerProdutos(Produtos *produtos) {
    int encerrar=0;
    for (int i = 0; encerrar == 0 && i < 5; i++) {

        int codigo;

        cout << "Digite o ID do produto ou 0 para sair: ";
        cin >> codigo;

        if (codigo ==0) {
            encerrar = 1;
        } else {
            produtos[i].codigo = codigo;
            cout << "Digite a descricao do produto: ";
            cin >> produtos[i].descricao;

            cout << "Digite o ID da categoria do produto: ";
            cin >> produtos[i].codigo_categoria;

            cout << "Digite o valor unitario do produto: ";
            cin >> produtos[i].preco_unitario;
        }
    }
}

void lerIngredientes (Ingredientes *ingredientes) {
    int encerrar = 0;
    for (int i = 0; encerrar == 0 && i < 5; i++) {
        int codigo;

        cout << "Digite o ID do ingrediente ou 0 para sair: ";
        cin >> codigo;

        if (codigo == 0) {
            encerrar = 1;
        } else {
            ingredientes[i].codigo = codigo;
            cout << "Digite o nome do ingrediente: ";
            cin >> ingredientes[i].descricao;

            cout << "Digite a quantidade em estoque: ";
            cin >> ingredientes[i].quant_estoque;

            cout << "Digite a quantidade mínima do ingrediente";
            cin >> ingredientes[i].quant_estoque_minimo;

            cout << "Digite a quantidade máxima do ingrediente";
            cin >> ingredientes[i].quant_estoque_maximo;

            cout << "Digite o valor unitário do ingrediente";
            cin >> ingredientes[i].preco_unitario;
        }
    }
}

bool buscarClientePorCodigo(Clientes *clientes, int codigo) {

    int i = 0;
    int f = 10;

    int m = ( i + f ) / 2;

    for (; f >= i && codigo != clientes[m].codigo; m = ( i + f) / 2) {
        if (codigo > clientes[m].codigo) {
            i = m + 1;
        } else {
            i = m - 1;
        }
    }
    if (codigo == clientes[m].codigo) {
        return true;
    } else {
        return false;
    }

}

void adicionarCliente (Clientes ATUAL[], int contATUAL, Clientes FINAL[], int &contFINAL) {

    int contNOVO = 0;
    Clientes NOVO[T];

    int encerrar = 0;
    for (int i = 0; encerrar == 0; i++) {

        int codigo;

        if (codigo == 0) {
            encerrar = 1;
        } else {
            if (buscarClientePorCodigo(ATUAL, codigo) == true || buscarClientePorCodigo(NOVO, codigo) == true) {
                cout << "Já existe um cliente cadastrado com o ID: " << codigo << endl;
            } else {
                NOVO[i].codigo = codigo;
                cout << "Digite o nome do novo cliente: ";
                cin >> NOVO[i].nome;
                cout << "Digite o telefone do novo cliente: ";
                cin >> NOVO[i].telefone;
                cout << "O cliente foi cadastrado com sucesso!" << endl;
                contNOVO++;
            }
        }
    }

    int i = 0; // contador de ATUAL
    int j = 0; // contador de NOVO
    int k = 0; // contador de FINAL

    for (; i < contATUAL && j < contNOVO; k++) {
        if (ATUAL[i].codigo < NOVO[j].codigo) {
            FINAL[k].codigo = ATUAL[i].codigo;
            FINAL[k].telefone = ATUAL[i].telefone;
            FINAL[k].nome = ATUAL[i].nome;
            i++;
        } else {
            FINAL[k].codigo = NOVO[j].codigo;
            FINAL[k].telefone = NOVO[j].telefone;
            FINAL[k].nome = NOVO[j].nome;
            j++;
        }
    }

    while (i < contATUAL) {
        FINAL[k].codigo = ATUAL[i].codigo;
        FINAL[k].telefone = ATUAL[i].telefone;
        FINAL[k].nome = ATUAL[i].nome;
        i++;
        k++;
    }

    while (j < contNOVO) {
        FINAL[k].codigo = NOVO[j].codigo;
        FINAL[k].telefone = NOVO[j].telefone;
        FINAL[k].nome = NOVO[j].nome;
        j++;
        k++;
    }
    contFINAL = k;
}



int main() {
    Categorias categorias[5];
    lerCategorias(categorias);
}


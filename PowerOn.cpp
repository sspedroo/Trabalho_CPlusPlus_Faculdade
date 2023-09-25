#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <cstring>

using namespace std;

struct Aluno {
    int cpf;
    string nomeDoAluno;
    string dataDeNascimento;
    float peso;
    float altura;
};

struct IndiceAluno {
    int cpfIndice;
    int enderecoDoAluno;
};

struct Professores {
    int codigoDoProfessor;
    string nomeDoProfessor;
    string enderecoDoProfessor;
    string telefoneDoProfessor;
};

struct IndiceProfessor {
    int codigoProfessor;
    int enderecoProfessor;
};

struct Modalidades{
    int codigoDaModalidade;
    string descricaoDaModalidade;
    int modalidadeCodigoDoProfessor;
    float valorDaAula;
    int limiteDeAlunos;
    int totalDeAlunos;
};

struct IndiceModalidade{
    int codigoModalidade;
    int enderecoModalidade;
};

struct Matricula{
    int codigoDaMatricula;
    int cpfDoAluno;
    int matriculaCodigoDaModalidade;
    int quantidadeDeAulas;
};

struct IndiceMatricula{
    int codigoMatricula;
    int enderecoMatricula;
};

int buscarModalidade(struct IndiceModalidade indiceModalidade[], int contador, int codigoModalidade){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for(; fim >= inicio && codigoModalidade != indiceModalidade[meio].codigoModalidade; meio = (inicio + fim) / 2){
        if(codigoModalidade > indiceModalidade[meio].codigoModalidade){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if(codigoModalidade == indiceModalidade[meio].codigoModalidade){
        return indiceModalidade[meio].enderecoModalidade;
    } else {
        return -1;
    }
}

int buscarAluno(struct IndiceAluno indiceAluno[], int contador, int cpfDoAluno){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for(; fim >= inicio && cpfDoAluno != indiceAluno[meio].cpfIndice; meio = (inicio + fim) / 2){
        if(cpfDoAluno > indiceAluno[meio].cpfIndice){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if(cpfDoAluno == indiceAluno[meio].cpfIndice){
        return indiceAluno[meio].enderecoDoAluno;
    } else {
        return -1;
    }
}

int buscarProfessor(struct IndiceProfessor indiceProfessor[], int contador, int codigoDoProfessor){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for(; fim >= inicio && codigoDoProfessor != indiceProfessor[meio].codigoProfessor; meio = (inicio + fim) / 2){
        if(codigoDoProfessor > indiceProfessor[meio].codigoProfessor){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if(codigoDoProfessor == indiceProfessor[meio].codigoProfessor){
        return indiceProfessor[meio].enderecoProfessor;
    } else {
        return  -1;
    }
    getch();
}

int buscarMatricula(struct IndiceMatricula indiceMatricula[], int contador, int codigoDaMatricula){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for(; fim >= inicio && codigoDaMatricula != indiceMatricula[meio].codigoMatricula; meio = (inicio + fim) / 2){
        if(codigoDaMatricula > indiceMatricula[meio].codigoMatricula){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if(codigoDaMatricula == indiceMatricula[meio].codigoMatricula){
        return indiceMatricula[meio].enderecoMatricula;
    } else {
        return -1;
    }
    getch();
}

float calcularImc(float peso, float altura){
    return peso / (altura * altura);
}

void calcularLucro(struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int contadorModalidades, struct IndiceProfessor indiceProfessor[], struct Professores professores[], int contadorProfessores){
    int codigoDaModalidade = 0;
    cout << "Digite o código da modalidade que deseja saber o faturamento" << endl;
    cin >> codigoDaModalidade;

    int resultadoBuscaModalidade = buscarModalidade(indiceModalidade, contadorModalidades, codigoDaModalidade);
    if(resultadoBuscaModalidade != -1){
        cout << "Descrição: " << modalidades[resultadoBuscaModalidade].descricaoDaModalidade << endl;
    } else {
        cout << "Modalidade não encontrada" << endl;
    }

    int codigoDoProfessorDaModalidade = modalidades[resultadoBuscaModalidade].modalidadeCodigoDoProfessor;
    int resultadoBuscaProfessor = buscarProfessor(indiceProfessor, contadorProfessores, codigoDoProfessorDaModalidade);
    cout <<"Professor: " << professores[resultadoBuscaProfessor].nomeDoProfessor;

}

void inserirNovosAlunos(struct Aluno aluno[], struct IndiceAluno indiceAluno[], int& contador){
    cout << "************* CADASTRAR NOVOS ALUNOS ****************";
    const int tamanhoVetor = 8;

    for (int i = 4; i < tamanhoVetor; i++) {
        while (true) {
            cout << "\n\n*Digite o CPF do aluno (padrão 8888) " << "(digite 0 para sair): ";
            cin >> aluno[i].cpf;
            if(aluno[i].cpf == 0){
                break;
            }
            int validarCpf = buscarAluno(indiceAluno, contador, aluno[i].cpf);
            if(validarCpf != -1){
                cout << "CPF já cadastrado para aluno(a): " << aluno[validarCpf].nomeDoAluno << endl;
            } else {
                break;
            }
        }
        if(aluno[i].cpf == 0){
            break;
        }

            bool nomeAlunoNaoVazio = false;
            while(!nomeAlunoNaoVazio){
                cout << "Nome do Aluno(a): ";
                cin.ignore();
                getline(cin, aluno[i].nomeDoAluno);
                    if(aluno[i].nomeDoAluno != ""){
                        nomeAlunoNaoVazio = true;
                    } else {
                        cout << "Nome do aluno(a) não pode estar vazio!"<<endl;
                        cin.ignore();
                    }
            }

            bool dataDeNascimentoNaoVazia = false;
            while(!dataDeNascimentoNaoVazia){
                cout << "Data de nascimento do Aluno(a): ";
                getline(cin, aluno[i].dataDeNascimento);
                    if (aluno[i].dataDeNascimento != ""){
                        dataDeNascimentoNaoVazia = true;
                    } else {
                        cout << "Data de nascimento do aluno não pode ser vazia!"<<endl;
                        cin.ignore();
                    }
            }

            cout << "Peso do Aluno(a): ";
            cin >> aluno[i].peso;
            cout << "Altura do aluno(a): ";
            cin >> aluno[i].altura;
            float imc = calcularImc(aluno[i].peso, aluno[i].altura);
            cout << "\nO IMC do aluno(a) é: " << imc <<endl;

            if(imc < 18.5 ){
                cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Magreza segundo os padrões IMC" << endl;
            } else if (imc >= 18.5 && imc <= 24.9 ){
            cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Peso normal segundo os padrões IMC" << endl;
            } else if (imc >= 25 && imc <= 29.9){
                cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Sobrepeso segundo os padrões IMC" << endl;
            } else if (imc >= 30 && imc <= 34.9){
                cout << "O aluno " << aluno[i].nomeDoAluno << " está com Obesidade grau I segundo os padrões IMC" << endl;
            } else if (imc >= 35 && imc <= 39.9){
                cout << "O aluno " << aluno[i].nomeDoAluno << " está com Obesidade grau II segundo os padrões IMC" << endl;
            } else {
                cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Obesidade grau III segundo os padrões IMC" << endl;
            }
            //Atualizar o indice
            int j; /* J representa a posição do vetor Indice de Alunos
 *                  para iniciar a logica, o J recebe o contador - 1, isso representa que estamos pegando
 *                  o ultimo elemento do Indice de aluno (então começamos pela ultima posição do indice)
 *                  Depois disso, colocamos a logica que o J é maior ou igual a 0 (se for 0 então é o primeiro elemento
 *                  do indice)
 *                  e perguntamos se o CPF do aluno que estamos inserindo (aluno[i].cpf) é menor que o CPF que está
 *                  no indice de Alunos. Se for menor significa que então precisamos passar o elemento atual do
 *                  indice para frente para liberar espaço para inserir o novo cpf que estamos cadastrando e depois
 *                  diminuimos em um o valor de J, o que significa que estamos indo uma posição para trás para fazer
 *                  a mesma coisa só que no indice anterior e assim por diante
 *                  Quando a condição do Laço(For) não for cumprida então significa que o cpf que estamos inserindo
 *                  não é menor que o cpf que está no indice, então ele deve ser armazenado nessa posição.
 *                  Dai saimos do For e adicionamos o CPF atual que estamos inserindo e a posição dele no array de Aluno
 *                  Fazemos isso dizendo que o indiceAluno[j + 1].campoCpf = cpf inserindo, usamos J + 1 que representa
 *                  o seguinte = "J" é a posição do elemento do Indice de alunos que possui um cpf menor que o que estamos
 *                  inserindo e o "+ 1" é para dizer então que queremos adicionar uma posição a frente desse.
 *                  no endereço, passamos apenas o indice(i) no qual o aluno atual está sendo inserido na tabela(array, vetor)
 */
        for (j = contador - 1; j >= 0 && aluno[i].cpf < indiceAluno[j].cpfIndice; j--) {
            indiceAluno[j + 1] = indiceAluno[j];
        }
        indiceAluno[j + 1].cpfIndice = aluno[i].cpf;
        indiceAluno[j + 1].enderecoDoAluno = i;
        cout << "\n***Aluno cadastrado com Sucesso***" <<endl;
        contador++;
    }
    cout<<"\n\nSaindo da inserção de alunos..." <<endl;
    cin.ignore();
}

void inserirNovosProfessores(struct Professores professores[], struct IndiceProfessor indiceProfessor[], int& contador){
    cout << "\n\n\n************* CADASTRAR NOVOS PROFESSORES ****************";

    const int tamanhoVetor = 8;

    for (int i = 4; i < tamanhoVetor; i++) {
        while(true) {
            cout << "\n\n*Digite o código do professor (padrão 88) " << "(digite 0 para sair): ";
            cin >> professores[i].codigoDoProfessor;
            if(professores[i].codigoDoProfessor == 0){
                break;
            }

            int validaCodigo = buscarProfessor(indiceProfessor, contador, professores[i].codigoDoProfessor);
            if(validaCodigo != -1){
                cout << "Código ja cadastrado para o professor(a): " << professores[validaCodigo].nomeDoProfessor;
            } else {
                break;
            }
        }

        if(professores[i].codigoDoProfessor == 0){
            break;
        }

        bool nomeProfessorNaoVazio = false;
        while(!nomeProfessorNaoVazio){
            cout << "Nome do Professor(a): ";
            cin.ignore();
            getline(cin, professores[i].nomeDoProfessor);
            if(professores[i].nomeDoProfessor != ""){
                nomeProfessorNaoVazio = true;
            } else {
                cout << "Nome do professor não estar vazio!" << endl;
            }
        }

        bool enderecoNaoVazio = false;
        while(!enderecoNaoVazio){
            cout << "Endereço do professor(a): ";
            getline(cin, professores[i].enderecoDoProfessor);
            if(professores[i].enderecoDoProfessor != ""){
                enderecoNaoVazio = true;
            } else {
                cout << "Endereço não pode ser vazio" << endl;
            }
        }

        bool telefoneNaoVazio = false;
        while(!telefoneNaoVazio){
            cout << "Telefone do professor(a): ";
            getline(cin, professores[i].telefoneDoProfessor);
            if(professores[i].telefoneDoProfessor != ""){
                telefoneNaoVazio = true;
            } else {
                cout << "Telefone não pode ser vazio" << endl;
            }
        }

        //Atualizar o indice
        int j; /* J representa a posição do vetor Indice de Alunos
 *                  para iniciar a logica, o J recebe o contador - 1, isso representa que estamos pegando
 *                  o ultimo elemento do Indice de aluno (então começamos pela ultima posição do indice)
 *                  Depois disso, colocamos a logica que o J é maior ou igual a 0 (se for 0 então é o primeiro elemento
 *                  do indice)
 *                  e perguntamos se o CPF do aluno que estamos inserindo (aluno[i].cpf) é menor que o CPF que está
 *                  no indice de Alunos. Se for menor significa que então precisamos passar o elemento atual do
 *                  indice para frente para liberar espaço para inserir o novo cpf que estamos cadastrando e depois
 *                  diminuimos em um o valor de J, o que significa que estamos indo uma posição para trás para fazer
 *                  a mesma coisa só que no indice anterior e assim por diante
 *                  Quando a condição do Laço(For) não for cumprida então significa que o cpf que estamos inserindo
 *                  não é menor que o cpf que está no indice, então ele deve ser armazenado nessa posição.
 *                  Dai saimos do For e adicionamos o CPF atual que estamos inserindo e a posição dele no array de Aluno
 *                  Fazemos isso dizendo que o indiceAluno[j + 1].campoCpf = cpf inserindo, usamos J + 1 que representa
 *                  o seguinte = "J" é a posição do elemento do Indice de alunos que possui um cpf menor que o que estamos
 *                  inserindo e o "+ 1" é para dizer então que queremos adicionar uma posição a frente desse.
 *                  no endereço, passamos apenas o indice(i) no qual o aluno atual está sendo inserido na tabela(array, vetor)
 */
        for (j = contador - 1; j >= 0 && professores[i].codigoDoProfessor < indiceProfessor[j].codigoProfessor; j--) {
            indiceProfessor[j + 1] = indiceProfessor[j];
        }
        indiceProfessor[j + 1].codigoProfessor = professores[i].codigoDoProfessor;
        indiceProfessor[j + 1].enderecoProfessor = i;
        cout << "\n***Professor cadastrado com Sucesso***" <<endl;
        contador++;
    }

    cout<<"\n\nSaindo da inserção de professores...."<<endl;
}

void inserirNovasModalidades(struct Modalidades modalidades[], struct IndiceModalidade indiceModalidade[], struct IndiceProfessor indiceProfessor[], struct Professores professores[], int& contador){
    cout << "\n\n\n************* CADASTRAR NOVAS MODALIDADES ****************";

    const int tamanhoVetor = 8;

    for (int i = 4; i < tamanhoVetor; i++) {
        while (true) {
            cout << "\n\n*Digite o código da Modalidade (padrão 88) " << "(digite 0 para sair): ";
            cin >> modalidades[i].codigoDaModalidade;
            if(modalidades[i].codigoDaModalidade == 0){
                break;
            }
            int validarCodigo = buscarModalidade(indiceModalidade, contador, modalidades[i].codigoDaModalidade);
            if (validarCodigo != -1) {
                cout << "Codigo já cadastrado para Modalidade: " << modalidades[validarCodigo].descricaoDaModalidade;
            } else {
                break;
            }
        }
        if(modalidades[i].codigoDaModalidade == 0){
            break;
        }

        bool descricaoNaoVazia = false;
        while (!descricaoNaoVazia){
            cout << "Descrição da Modalidade: ";
            cin.ignore();
            getline(cin, modalidades[i].descricaoDaModalidade);
            if(modalidades[i].descricaoDaModalidade != ""){
                descricaoNaoVazia = true;
            } else {
                cout << "Descrição não pode ser vazia" << endl;
            }
        }

        cout << "Total de alunos cadastrados na Modalidade: ";
        cin >> modalidades[i].totalDeAlunos;
        cout << "Limite de alunos que podem estar cadastrado na Modalidade: ";
        cin >> modalidades[i].limiteDeAlunos;
        cout << "Valor da aula da Modalidade: ";
        cin >> modalidades[i].valorDaAula;
        cout << "Código do professor da Modalidade: ";
        cin >> modalidades[i].modalidadeCodigoDoProfessor;
        int codigoASerProcurado = modalidades[i].modalidadeCodigoDoProfessor;
        int resultadoBuscarProfessor =  buscarProfessor(indiceProfessor, contador, codigoASerProcurado);
        cout <<"Professor(a): " << professores[resultadoBuscarProfessor].nomeDoProfessor <<endl;

        //Atualizar o indice
        int j; /* J representa a posição do vetor Indice de Alunos
 *                  para iniciar a logica, o J recebe o contador - 1, isso representa que estamos pegando
 *                  o ultimo elemento do Indice de aluno (então começamos pela ultima posição do indice)
 *                  Depois disso, colocamos a logica que o J é maior ou igual a 0 (se for 0 então é o primeiro elemento
 *                  do indice)
 *                  e perguntamos se o CPF do aluno que estamos inserindo (aluno[i].cpf) é menor que o CPF que está
 *                  no indice de Alunos. Se for menor significa que então precisamos passar o elemento atual do
 *                  indice para frente para liberar espaço para inserir o novo cpf que estamos cadastrando e depois
 *                  diminuimos em um o valor de J, o que significa que estamos indo uma posição para trás para fazer
 *                  a mesma coisa só que no indice anterior e assim por diante
 *                  Quando a condição do Laço(For) não for cumprida então significa que o cpf que estamos inserindo
 *                  não é menor que o cpf que está no indice, então ele deve ser armazenado nessa posição.
 *                  Dai saimos do For e adicionamos o CPF atual que estamos inserindo e a posição dele no array de Aluno
 *                  Fazemos isso dizendo que o indiceAluno[j + 1].campoCpf = cpf inserindo, usamos J + 1 que representa
 *                  o seguinte = "J" é a posição do elemento do Indice de alunos que possui um cpf menor que o que estamos
 *                  inserindo e o "+ 1" é para dizer então que queremos adicionar uma posição a frente desse.
 *                  no endereço, passamos apenas o indice(i) no qual o aluno atual está sendo inserido na tabela(array, vetor)
 */
        for (j = contador - 1; j >= 0 && modalidades[i].codigoDaModalidade < indiceModalidade[j].codigoModalidade; j--) {
            indiceModalidade[j + 1] = indiceModalidade[j];
        }
        indiceModalidade[j + 1].codigoModalidade = modalidades[i].codigoDaModalidade;
        indiceModalidade[j + 1].enderecoModalidade = i;
        cout << "\n***Modalidade cadastrada com Sucesso***" <<endl;
        contador++;
    }
    cout << "\n\nSaindo da inserção de modalidades....";
}

void inserirNovasMatriculas(struct Matricula matriculas[], struct IndiceMatricula indiceMatricula[], struct IndiceAluno indiceAluno[], struct Aluno aluno[], struct IndiceModalidade indiceModalidade[], struct  Modalidades modalidades[],int& contador){
    cout << "\n\n\n************* CADASTRAR NOVAS MATRICULAS ****************";

    const int tamanhoVetor = 8;

    for (int i = 4; i < tamanhoVetor; ++i) {
        bool vagaEncontrada = false;

        while (!vagaEncontrada) {
            cout << "\n\n*Digite o código da Matricula" << "(digite 0 para sair): ";
            cin >> matriculas[i].codigoDaMatricula;

            if(matriculas[i].codigoDaMatricula == 0){
                break;
            }

            int validarCodigo = buscarMatricula(indiceMatricula, contador, matriculas[i].codigoDaMatricula);
            if (validarCodigo != -1){
                cout << "Codigo já cadastrado na matricula do CPF: " << matriculas[validarCodigo].cpfDoAluno;
            } else {
                cout << "Digite o CPF do aluno: ";
                cin >> matriculas[i].cpfDoAluno;
                int cpfProcurado = matriculas[i].cpfDoAluno;
                int resultadoBuscaCpf = buscarAluno(indiceAluno, contador, cpfProcurado);
                if(resultadoBuscaCpf != -1){
                    cout << "Nome do Aluno(a): " << aluno[resultadoBuscaCpf].nomeDoAluno<<endl;
                } else {
                    cout << "Aluno(a) não encontrado." <<endl;
                    continue;
                }
            }

            cout << "Digite o código da modalidade: ";
            cin >> matriculas[i].matriculaCodigoDaModalidade;
            int modalidadeProcurada =  matriculas[i].matriculaCodigoDaModalidade;
            int resultadoBuscaModalidade = buscarModalidade(indiceModalidade, contador, modalidadeProcurada);
            if(resultadoBuscaModalidade != -1){
                cout << "Modalidade: " << modalidades[resultadoBuscaModalidade].descricaoDaModalidade<<endl;
            } else {
                cout << "Modalidade não encontrada." << endl;
                continue;
            }
            int pessoasCadastradasNaModalidade = modalidades[resultadoBuscaModalidade].totalDeAlunos;
            int limiteDePessoasNaModalidade = modalidades[resultadoBuscaModalidade].limiteDeAlunos;

            if(pessoasCadastradasNaModalidade < limiteDePessoasNaModalidade){
                cout << "\nHá vagas disponiveis nessa modalidade" << endl;
                modalidades[resultadoBuscaModalidade].totalDeAlunos = modalidades[resultadoBuscaModalidade].totalDeAlunos + 1;
                cout << "\n****Aluno matriculado com sucesso!" << endl;
                cout << "\nAlunos matriculados: " << modalidades[resultadoBuscaModalidade].totalDeAlunos<< endl;
                cout << "Limite de alunos da modalidade: " << limiteDePessoasNaModalidade << endl;
                vagaEncontrada = true;
            } else {
                cout<< "\nNão há vagas disponiveis" << endl;
                cout << "\nAlunos matriculados: " << pessoasCadastradasNaModalidade << endl;
                cout << "Limite de alunos da modalidade: " << limiteDePessoasNaModalidade << endl;
            }

            cout << "Quantidade de aulas: ";
            cin >> matriculas[i].quantidadeDeAulas;

        }
        if(matriculas[i].codigoDaMatricula == 0){
            break;
        }

        int j;
        for (j = contador - 1; j >= 0 && matriculas[i].codigoDaMatricula < indiceMatricula[j].codigoMatricula; j--) {
            indiceMatricula[j + 1] = indiceMatricula[j];
        }
        indiceMatricula[j + 1].codigoMatricula = matriculas[i].codigoDaMatricula;
        indiceMatricula[j + 1].enderecoMatricula = i;
        cout << "\n***Matricula cadastrada com Sucesso***" <<endl;
        contador++;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Aluno aluno[8] = {
            {.cpf = 4444, .nomeDoAluno = "Pedro", .dataDeNascimento = "16/10/1998", .peso = 80, .altura = 1.80 },
            {.cpf = 6666, .nomeDoAluno = "Raquel", .dataDeNascimento = "11/05/2004", .peso = 60, .altura = 1.60 },
            {.cpf = 2222, .nomeDoAluno = "Isabela", .dataDeNascimento = "16/02/2004", .peso = 67, .altura = 1.63 },
            {.cpf = 8888, .nomeDoAluno = "Gabriel", .dataDeNascimento = "21/06/1998", .peso = 92, .altura = 1.80 }
    };

    IndiceAluno indiceAluno[8] ={
            {.cpfIndice = 2222, .enderecoDoAluno = 2},
            {.cpfIndice = 4444, .enderecoDoAluno = 0},
            {.cpfIndice = 6666, .enderecoDoAluno = 1},
            {.cpfIndice = 8888, .enderecoDoAluno = 3}
    };

    Professores professores[8] = {
            {.codigoDoProfessor = 10, .nomeDoProfessor = "Wilson", .enderecoDoProfessor = "Rui Barbosa, 233", .telefoneDoProfessor = "18 99977 - 9999"},
            {.codigoDoProfessor = 30, .nomeDoProfessor = "Luciana", .enderecoDoProfessor = "Vicente de Carvalho, 700", .telefoneDoProfessor = "18 99666 - 6666"},
            {.codigoDoProfessor = 20, .nomeDoProfessor = "Hugo", .enderecoDoProfessor = "André Perine, 33", .telefoneDoProfessor = "18 98181 - 8181"},
            {.codigoDoProfessor = 40, .nomeDoProfessor = "Rafaela", .enderecoDoProfessor = "Luiz Pizza, 2623", .telefoneDoProfessor = "18 99696 - 6969"}
    };

    IndiceProfessor indiceProfessor[8] = {
            {.codigoProfessor = 10, .enderecoProfessor = 0},
            {.codigoProfessor = 20, .enderecoProfessor = 2},
            {.codigoProfessor = 30, .enderecoProfessor = 1},
            {.codigoProfessor = 40, .enderecoProfessor = 3}
    };

    Modalidades modalidades[8] = {
            {.codigoDaModalidade = 100, .descricaoDaModalidade = "Sppining", .modalidadeCodigoDoProfessor = 40, .valorDaAula = 79.90, .limiteDeAlunos = 15, .totalDeAlunos = 14},
            {.codigoDaModalidade = 300, .descricaoDaModalidade = "Musculação", .modalidadeCodigoDoProfessor = 10, .valorDaAula = 60.00, .limiteDeAlunos = 50, .totalDeAlunos = 49},
            {.codigoDaModalidade = 200, .descricaoDaModalidade = "Muay Thai", .modalidadeCodigoDoProfessor = 20, .valorDaAula = 99.90, .limiteDeAlunos = 10, .totalDeAlunos = 8},
            {.codigoDaModalidade = 400, .descricaoDaModalidade = "Pilates", .modalidadeCodigoDoProfessor = 30, .valorDaAula = 110.00, .limiteDeAlunos = 8, .totalDeAlunos = 6}
    };

    IndiceModalidade indiceModalidade[8] = {
            {.codigoModalidade = 100, .enderecoModalidade = 0},
            {.codigoModalidade = 200, .enderecoModalidade = 2},
            {.codigoModalidade = 300, .enderecoModalidade = 1},
            {.codigoModalidade = 400, .enderecoModalidade = 3}
    };

    Matricula matricula[8] = {
            {.codigoDaMatricula = 2, .cpfDoAluno = 044444, .matriculaCodigoDaModalidade = 400, .quantidadeDeAulas = 10 },
            {.codigoDaMatricula = 3, .cpfDoAluno = 055555, .matriculaCodigoDaModalidade = 200, .quantidadeDeAulas = 8},
            {.codigoDaMatricula = 4, .cpfDoAluno = 066666, .matriculaCodigoDaModalidade = 100, .quantidadeDeAulas = 6},
            {.codigoDaMatricula = 1, .cpfDoAluno = 077777, .matriculaCodigoDaModalidade = 300, .quantidadeDeAulas = 4}
    };

    IndiceMatricula indiceMatricula[8] = {
            {.codigoMatricula = 1, .enderecoMatricula = 3},
            {.codigoMatricula = 2, .enderecoMatricula = 0},
            {.codigoMatricula = 3, .enderecoMatricula = 1},
            {.codigoMatricula = 4, .enderecoMatricula = 2}
    };

    int contadorAluno = 4;
    int contadorProfessor = 4;
    int contadorModalidade = 4;
    int contadorMatricula = 4;

    inserirNovosAlunos(aluno, indiceAluno, contadorAluno);
    inserirNovosProfessores(professores, indiceProfessor, contadorProfessor);
    inserirNovasModalidades(modalidades, indiceModalidade, indiceProfessor, professores, contadorModalidade);
    inserirNovasMatriculas(matricula, indiceMatricula, indiceAluno, aluno, indiceModalidade, modalidades, contadorMatricula);


    for (int i = 0; i < 8; ++i) {
        cout << "\nAluno " << i+1 <<" -------- " << "\nNome: " << aluno[i].nomeDoAluno << "\nData de nascimento: " << aluno[i].dataDeNascimento << endl;
        cout << "\n\nProfessor " << i+1 <<" -------- " << "\nNome:" <<professores[i].nomeDoProfessor << "\nCódigo: " << professores[i].codigoDoProfessor <<"\nEndereço: " << professores[i].enderecoDoProfessor << endl;
        cout << "\n\nModalidade " << i+1 <<" -------- " << "\nCódigo: " <<modalidades[i].codigoDaModalidade << "\nDescrição: " << modalidades[i].descricaoDaModalidade <<"\nPreço: " << modalidades[i].valorDaAula << endl;
        cout << "\nMatricula " << i+1 <<" -------- " << "\nCódigo: " <<matricula[i].codigoDaMatricula <<"\nQuantidade de aulas: " << matricula[i].quantidadeDeAulas << endl;
    }

    for (int i = 0; i < 8; ++i) {
        cout << "\nIndiceAluno" << i+1 <<": " << indiceAluno[i].cpfIndice << ", " << indiceAluno[i].enderecoDoAluno << endl;
        cout << "\n\nIndiceProfessor" << i+1 <<": " << indiceProfessor[i].codigoProfessor << ", " << indiceProfessor[i].enderecoProfessor << endl;
        cout << "\n\nIndiceModalidade" << i+1 <<": " << indiceModalidade[i].codigoModalidade << ", " << indiceModalidade[i].enderecoModalidade << endl;
        cout << "\nIndiceMatricula" << i+1 <<": " << indiceMatricula[i].codigoMatricula << ", " << indiceMatricula[i].enderecoMatricula << endl;

    }

    getch();
    return 0;
}

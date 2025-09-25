#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> // pra mexer com arquivos e pastas
#include <limits>     // pra limpar o buffer de entrada

// Protótipos das funções
void menu();
void listar();
void lerArquivo();
void criarArquivo();
void criarPasta();
void remover();

// Função principal
int main() {
    int opcao;

    do {
        menu();
        std::cout << ">> Escolha uma opcao: ";
        std::cin >> opcao;

        if (std::cin.fail()) { // se o usuário não digitar um número
            std::cout << "\nOpção inválida. Por favor, digite um número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcao = -1;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpar buffer do Enter

        switch(opcao) {
            case 1: listar(); break;
            case 2: lerArquivo(); break;
            case 3: criarArquivo(); break;
            case 4: criarPasta(); break;
            case 5: remover(); break;
            case 0: std::cout << "\nSaindo do programa.\n"; break;
            default: std::cout << "\nOpção inválida. Tente novamente.\n"; break;
        }

    } while(opcao != 0);

    return 0;
}

// Menu principal
void menu() {
    // mostrar opções pro usuário
    std::cout << "\n== Gerenciador de Arquivos ==\n";
    std::cout << "1 - Listar arquivos e diretórios\n";
    std::cout << "2 - Ler arquivo\n";
    std::cout << "3 - Criar arquivo\n";
    std::cout << "4 - Criar diretório\n";
    std::cout << "5 - Remover arquivo/diretório\n";
    std::cout << "0 - Sair\n";
}

// Listar arquivos e pastas
void listar() {
    std::cout << "\n-- Itens no diretório atual --\n";
    try {
        for (const auto &entry : std::filesystem::directory_iterator(".")) {
            std::cout << entry.path().filename().string() << std::endl;
        }
    } catch(...) {
        std::cout << "\nErro ao listar arquivos.\n"; // algo deu ruim
    }
}

// Ler arquivo
void lerArquivo() {
    std::string nome;
    std::cout << ">> Digite o nome do arquivo: ";
    std::getline(std::cin, nome);

    std::ifstream arq(nome);
    if(!arq.is_open()) {
        std::cout << "\nErro: Não foi possível abrir o arquivo.\n";
        return;
    }

    std::cout << "\n-- Conteúdo do arquivo --\n";
    std::string linha;
    while(std::getline(arq, linha)) {
        std::cout << linha << std::endl;
    }
    arq.close();
}

// Criar arquivo
void criarArquivo() {
    std::string nome;
    std::cout << ">> Digite o nome do novo arquivo: ";
    std::getline(std::cin, nome);

    std::ofstream arq(nome);
    if(!arq.is_open()) {
        std::cout << "\nErro: Não foi possível criar o arquivo.\n";
        return;
    }

    std::string linha;
    std::cout << ">> Digite o conteúdo do arquivo (Ctrl+D para finalizar):\n";
    while(std::getline(std::cin, linha)) {
        arq << linha << std::endl;
    }
    arq.close();
    std::cout << "\nArquivo criado com sucesso.\n";
}

// Criar pasta
void criarPasta() {
    std::string nome;
    std::cout << ">> Digite o nome do diretório: ";
    std::getline(std::cin, nome);

    // tenta criar a pasta, se já existir, avisa
    if(std::filesystem::create_directory(nome)) {
        std::cout << "\nDiretório criado com sucesso.\n";
    } else {
        std::cout << "\nErro: Diretório já existe ou não pôde ser criado.\n";
    }
}

// Remover arquivo ou pasta
void remover() {
    std::string nome;
    std::cout << ">> Digite o nome do arquivo ou diretório: ";
    std::getline(std::cin, nome);

    try {
        if(std::filesystem::remove(nome)) {
            std::cout << "\nItem removido com sucesso.\n";
        } else {
            std::cout << "\nErro: Item não encontrado ou não pôde ser removido.\n";
        }
    } catch(...) {
        std::cout << "\nErro: Diretórios devem estar vazios para serem removidos.\n";
    }
}

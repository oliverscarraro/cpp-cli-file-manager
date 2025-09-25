# Gerenciador de Arquivos em C++

Um gerenciador de arquivos simples para a linha de comando, desenvolvido em C++17, que permite ao usuário realizar operações básicas no sistema de arquivos, como listar, ler, criar e remover arquivos e diretórios.

A aplicação foi desenvolvida e testada primariamente no ambiente Arch Linux.

---

### ► Funcionalidades

- Listar todos os arquivos e diretórios no local atual.
- Ler e exibir o conteúdo de um arquivo de texto.
- Criar um novo arquivo de texto com conteúdo definido pelo usuário.
- Criar um novo diretório.
- Remover um arquivo ou um diretório vazio.

---

### ► Tecnologias Utilizadas

- **Linguagem:** C++ (utilizando o padrão C++17 para a biblioteca `<filesystem>`)
- **Bibliotecas Padrão:** `<iostream>`, `<fstream>`, `<filesystem>`, `<string>`

---

### ► Compilação e Execução no Arch Linux

**Pré-requisitos:**
- Um ambiente Arch Linux.
- O compilador C++ `g++` e ferramentas de desenvolvimento (`base-devel`).

**1. Instalação das Ferramentas:**
   - Abra o terminal e instale o grupo de pacotes `base-devel`, que inclui o `g++`:
     ```bash
     sudo pacman -S base-devel
     ```

**2. Clonar e Acessar o Repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/cpp-cli-file-manager.git](https://github.com/seu-usuario/cpp-cli-file-manager.git)
   cd cpp-cli-file-manager

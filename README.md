# Sistema de Gerenciamento de Notas v4.1

Este é um sistema em linha de comando (CLI) desenvolvido em **C++** para automação do processo de lançamento, cálculo e persistência de notas escolares. O software foi projetado para professores e administradores acadêmicos realizarem o levantamento de desempenho de turmas de forma rápida, com validação de dados em tempo de execução e armazenamento automatizado dos resultados.

---

## 🚀 Funcionalidades

## Funcionalidades
- Cadastro de alunos e notas por disciplina
- Cálculo de médias por aluno
- Classificação: Aprovado, Recuperação ou Reprovado
- Relatório salvo em arquivo .txt com data e hora
- Leitura de relatório salvo
- Menu "Sobre o sistema"

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++ (Padrão C++11 ou superior)
- **Bibliotecas Standard:** `<iostream>`, `<string>`, `<algorithm>`, `<fstream>`
- **Biblioteca de Sistema:** `<windows.h>` (para manipulação do Console Windows)

---

## 📋 Pré-requisitos

Para compilar e executar este sistema, você precisará de:
1. Um sistema operacional **Windows** (devido à dependência da biblioteca `<windows.h>`).
2. Um compilador C++ instalado no seu sistema (como o **GCC/G++**, **MinGW**, ou integrado a uma IDE como **Code::Blocks**, **Dev-C++** ou **VS Code**).

---

## 🔧 Como Compilar e Executar

Siga os passos abaixo utilizando o terminal (Prompt de Comando ou PowerShell):

1. **Clone ou baixe o arquivo de código** (ex: `main.cpp`).
2. **Abra o terminal** no diretório onde o arquivo está salvo.
3. **Compile o código** executando o seguinte comando:
   ```bash
   g++ main.cpp -o SistemaNotas.exe
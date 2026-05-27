#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qntdAlunos;
    float notas[20][5];
    float media[20];
    int qntdDisciplinas;

    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;

    do
    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qntdAlunos;
    } while (qntdAlunos < 1 || qntdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qntdAlunos; i++)
    {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    do
    {
        cout << "Quantidade de disciplinas (1 a 5): ";
        cin >> qntdDisciplinas;
    } while (qntdDisciplinas < 1 || qntdDisciplinas > 5);

    cin.ignore();

    for (int i = 0; i < qntdAlunos; i++)
    {
        cout << "\nNotas do aluno: " << nomes[i] << endl;
        float soma = 0;
        for (int j = 0; j < qntdDisciplinas; j++)
        {
            do
            {
                cout << "  Disciplina " << j + 1 << " (0 a 10): ";
                cin >> notas[i][j];

            } while (notas[i][j] < 0 || notas[i][j] > 10);

            soma += notas[i][j];
        }
        media[i] = soma / qntdDisciplinas;
    }

    cout << "\n==============================" << endl;
    cout << "RELATÓRIO FINAL:" << endl;
    int alunosAprovados = 0;
    int alunosReprovados = 0;
    int alunosRecuperacao = 0;

    for (int i = 0; i < qntdAlunos; i++)
    {
        cout << nomes[i] << " - Média: " << media[i] << endl;
        if (media[i] >= 7)
        {
            cout << "  Situação: Aprovado" << endl;
            alunosAprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "  Situação: Recuperação" << endl;
            alunosRecuperacao++;
        }
        else
        {
            cout << "  Situação: Reprovado" << endl;
            alunosReprovados++;
        }
    }
    cout << "===============================" << endl;
    cout << "Resumo: " << endl;
    cout << "Alunos aprovados: " << alunosAprovados << endl;
    cout << "Alunos em recuperação: " << alunosRecuperacao << endl;
    cout << "Alunos reprovados: " << alunosReprovados << endl;
    cout << "===============================" << endl;

    // === CORREÇÃO APLICADA AQUI ABAIXO ===
    ofstream arquivo("relatorio_notas.txt");
    if (arquivo.is_open())
    {
        arquivo << "=== RELATÓRIO ===" << endl;
        for (int i = 0; i < qntdAlunos; i++)
        {
            arquivo << nomes[i] << " -  Média: " << media[i] << endl;
            if (media[i] >= 7)
            {
                arquivo << "Aprovado" << endl;
            }
            else if (media[i] >= 5) // O 'else if' agora está corretamente dentro do laço for
            {
                arquivo << "Recuperação" << endl;
            }
            else
            {
                arquivo << "Reprovado" << endl;
            }
        } 

        arquivo << "\nResumo:" << endl;
        arquivo << alunosAprovados << " alunos aprovados" << endl;
        arquivo << alunosRecuperacao << " alunos em recuperação" << endl;
        arquivo << alunosReprovados << " alunos reprovados" << endl;
        
        arquivo.close();
        cout << "Relatório salvo em 'relatorio_notas.txt'" << endl;
    }
    else
    {
        cout << "Erro ao criar o arquivo" << endl;
    }
    
    return 0;
}
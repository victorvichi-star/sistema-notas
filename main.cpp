#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qntdAlunos;
    float notas[20][5];
    float media[20];
    int qntdDisciplinas;
    int opcaoInicial;

    // === INÍCIO DO LAÇO DO MENU ===
    do
    {        
        cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;
        cout << "1 - Novo Relatório" << endl;
        cout << "2 - Ver Relatório " << endl;
        cout << "3 - Sobre o sistema" << endl;
        cout << "4 - Sair do sistema" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcaoInicial;

        if (opcaoInicial == 1)
        {
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
                    else if (media[i] >= 5)
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

                time_t agora = time(0);
                char* dataHora = ctime(&agora);
                arquivo << "Data do relatório: " << dataHora << endl;
                
                arquivo.close();
                cout << "Relatório salvo em 'relatorio_notas.txt'" << endl;
            }
            else
            {
                cout << "Erro ao criar o arquivo" << endl;
            }
            
            cout << endl;
        }
        else if (opcaoInicial == 2)
        {
            ifstream leitura("relatorio_notas.txt");
            if (leitura.is_open())
            {
                string linha;
                while (getline(leitura, linha))
                {
                    cout << linha << endl;
                }
                leitura.close();
            }
            else
            {
                cout << "Nenhum relatório encontrado. Por favor, crie um novo relatório primeiro." << endl;
            }
            
            cout << endl;
            system("pause");
        }
        else if (opcaoInicial == 3)
        {
            cout << "=== SOBRE ===" << endl;
            cout << "Sistema de Notas v4.0 - Desenvolvido por Victor Vichi" << endl;
            cout << "Este sistema permite criar relatórios de notas para até 20 alunos e 5 disciplinas." << endl;
            cout << "As notas são salvas em um arquivo de texto para consulta futura." << endl;
            cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
            cout << "Versão: 4.1" << endl;
            
            cout << endl;
            system("pause");
        }
        else if (opcaoInicial == 4)
        {
            cout << "Saindo do sistema... Até logo!" << endl;
        }
        else
        {
            cout << "Opção inválida! Tente novamente." << endl;
            cout << endl;
            system("pause");
        }

    } while (opcaoInicial != 4);

    return 0;
}
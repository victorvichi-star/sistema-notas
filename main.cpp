#include <iostream>
#include <string>

using namespace std;
int main()
{

//entrada de dados
string nomes[20];
int qtdAlunos;


//processamento de dados

cout << "=== SISTEMA DE NTOAS V4.9 ===" << endl;

do
{
    cout << "Quantidade de alunos (1 a 20): ";
    cin >> qtdAlunos;

} while (qtdAlunos < 1 || qtdAlunos > 20);

cin.ignore(); // Limpa o buffer de entrada
for (int i = 0; i < qtdAlunos; i++)
{
    cout << "Nome do aluno " << i + 1 << ": ";
    getline (cin, nomes[i]);

}



//saída de dados

cout << "\nAlunos cadastrados: " << endl;
for (int i = 0; i < qtdAlunos; i++){
    cout << "  " << i +1 << ". " << nomes[i] << endl;

}


    return 0;
}
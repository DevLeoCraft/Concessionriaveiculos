# Concessionária Optimus - Sistema de Venda de Veículos 🚗

Este é um projeto acadêmico desenvolvido como parte das atividades do curso de Análise e Desenvolvimento de Sistemas, com o objetivo de criar um sistema de gerenciamento para uma concessionária de veículos.

## 🖥️ Sobre o Projeto

O **Sistema de Venda de Veículos** é uma aplicação que permite gerenciar informações de clientes e veículos, incluindo funcionalidades de cadastro, atualização, busca e venda. O sistema também oferece persistência de dados, salvando e carregando informações de um arquivo.

### Funcionalidades:
- **Gestão de Clientes**:
  - Cadastro, atualização, busca e remoção de clientes.
  
- **Gestão de Veículos**:
  - Cadastro, atualização, busca e remoção de veículos.
  - Buscas por modelo e preço de veículos.
  
- **Venda de Veículos**:
  - Permite realizar a venda de um veículo para um cliente e removê-lo do sistema.

- **Persistência de Dados**:
  - Salva e carrega dados de clientes e veículos em arquivos de texto.

## 📁 Estrutura do Projeto

- **`main.c`**: Código principal do sistema, onde todas as operações são executadas.
- **`clientes.txt`**: Arquivo de texto para armazenar informações dos clientes.
- **`veiculos.txt`**: Arquivo de texto para armazenar informações dos veículos.

## 🚀 Funcionalidades

- **Cadastro de Clientes e Veículos**: Permite adicionar novos clientes e veículos ao sistema.
- **Busca e Remoção**: Funcionalidades para buscar e remover registros de clientes e veículos.
- **Venda**: Realiza a venda de veículos, removendo-os do sistema.
- **Persistência**: Salva as informações de clientes e veículos em arquivos para persistência entre execuções.

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**: Para desenvolvimento da lógica e interação com os dados.
- **Arquivos de Texto**: Para armazenamento persistente dos dados de clientes e veículos.

## 📜 Como Usar

1. **Compilação e Execução**: Compile o código com um compilador C, como `gcc`, e execute o programa.
2. **Interface de Menu**: O programa oferece um menu interativo com opções para gerenciar clientes, veículos e realizar vendas.
3. **Armazenamento de Dados**: Os dados são carregados ao iniciar o sistema e salvos ao finalizar.

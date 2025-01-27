//Projeto De Concessionária com sistema de venda de veículos
//Alunos:Emmanuel Guerra Maranhão e Leonardo Antonio Da Silva
//1* Período,ADS,Manhã,2024.2 

//bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100//define o máximo de 100 para veiculo e cliente.

//estrutura para armazenar os dados do cliente
typedef struct {
    char nome[40];
    int idade;  
    char cpf[13];
    char cnh[10];
} Cliente;

//estrutura para armazenar os dados do veículo
typedef struct {
    char modelo[30];
    float valor;
    char placa[10];
} Veiculo;

//essas funções são para manipulação de clientes
void inserirCliente(Cliente clientes[], int *quantidade);// aqui o "*" tanto na função de inserir cliente como veículo indica que  ponteiro utilizado para aumentar.
void removerCliente(Cliente clientes[], int *quantidade);//já aqui o ponteiro serve para diminuir a quantidade de clientes
void buscarCliente(Cliente clientes[], int quantidade);
void listarClientes(Cliente clientes[], int quantidade);
void atualizarCliente(Cliente clientes[], int quantidade);
//nessa ultima função não se faz necessária a utilização de ponteiro,pois altera apenas o array e não quantidade


//essas funções são para manipulação de veículos
void inserirVeiculo(Veiculo veiculos[], int *quantidade);
void removerVeiculo(Veiculo veiculos[], int *quantidade);
void buscarVeiculo(Veiculo veiculos[], int quantidade);
void listarVeiculos(Veiculo veiculos[], int quantidade);
void atualizarVeiculo(Veiculo veiculos[], int quantidade);
void buscarVeiculoPorModelo(Veiculo veiculos[], int quantidade);
void buscarVeiculoPorPreco(Veiculo veiculos[], int quantidade);
//mesma lógica das funções para clientes


// função para realizar venda de veículo ao cliente.
void venderVeiculo(Cliente clientes[], int *qtdClientes, Veiculo veiculos[], int *qtdVeiculos);

// funções para salvar e carregar dados no arquivo.txt
void salvarConcessionaria(Cliente clientes[], int qtdClientes, Veiculo veiculos[], int qtdVeiculos);
void carregarConcessionaria(Cliente clientes[], int *qtdClientes, Veiculo veiculos[], int *qtdVeiculos);

int main() {
    Cliente clientes[MAX]; //array para armazenar clientes
    Veiculo veiculos[MAX]; //array para armazenar veiculos
    int qtdClientes = 0,qtdVeiculos = 0;//os dois contadores iniciam vazios.
    int opcao;

    carregarConcessionaria(clientes, &qtdClientes, veiculos, &qtdVeiculos);
	//carrega os dados do arquivo.txt no início do programa
	
	// menu exibido ao usuário
    do { 
        printf("\n--- Concessionaria Optimus ---\n");
        printf("1. Inserir cliente\n");
        printf("2. Remover cliente\n");
        printf("3. Buscar cliente\n");
        printf("4. Atualizar cliente\n");
        printf("5. Lista de clientes\n");
        printf("6. Inserir veiculo\n");
        printf("7. Remover veiculo\n");
        printf("8. Buscar veiculo\n");
        printf("9. Atualizar veiculo\n");
        printf("10. Lista de veiculos\n");
        printf("11. Buscar veiculo por modelo\n");
        printf("12. Buscar veiculo por preco\n");
        printf("13. Vender veiculo\n");
        printf("14. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
		//scanf de opção que serve ler um número inteiro digitado pelo usuário e armazenar ele na variável opcao.
		
		//o switch case serve pra verificar a opção selecionada e relaciona a algum case que realiza a função correspondente
        switch (opcao) {
            case 1:
                inserirCliente(clientes, &qtdClientes);
                //insere cliente
				break;
            case 2:
                removerCliente(clientes, &qtdClientes);
                //remove cliente
				break;
            case 3:
                buscarCliente(clientes, qtdClientes);
                //busca cliente pelo cpf
				break;
            case 4:
                atualizarCliente(clientes, qtdClientes);
                //atualiza dados do cliente
				break;
            case 5:
                listarClientes(clientes, qtdClientes);
                //lista todos os clientes
				break;
            case 6:
                inserirVeiculo(veiculos, &qtdVeiculos);
				//insere veiculo
			    break;
            case 7:
                removerVeiculo(veiculos, &qtdVeiculos);
                //remove veiculo
				break;
            case 8:
                buscarVeiculo(veiculos, qtdVeiculos);
                //busca veiculo pela placa
				break;
            case 9:
                atualizarVeiculo(veiculos, qtdVeiculos);
                //atualiza dados do veiculo
			    break;
            case 10:
                listarVeiculos(veiculos, qtdVeiculos);
                //lista todos os veiculos
				break;
            case 11:
                buscarVeiculoPorModelo(veiculos, qtdVeiculos);
                //busca veiculos pelo modelo
				break;
            case 12:
                buscarVeiculoPorPreco(veiculos, qtdVeiculos);
                //busca veiculos por um intervalo de preço
				break;
            case 13:
                venderVeiculo(clientes, &qtdClientes, veiculos, &qtdVeiculos);
                //realiza a venda de um veiculo e depois remove do sistema
				break;
            case 14:
                salvarConcessionaria(clientes, qtdClientes, veiculos, qtdVeiculos);
                printf("Saindo do programa...\n");//salva os dados e encerra o programa
                break;
            default:
                printf("Opcao invalida!\n");//o default serve para caso nenhuma das opções válidas serem selecionadas,ele mostra essa mensagem do printf
        }
    } while (opcao != 14);//é o loop que mantem o programa em execução até que o usuario selecione a opção 14,enquanto forem selecionadas outras opções exceto a 14,o programa permanece funcionando.

    return 0;//retorna 0 indicando que funcionou corretamente.
}

//função para inserir os dados dos clientes no sistema
void inserirCliente(Cliente clientes[], int *quantidade) {
    if (*quantidade >= MAX) //verifica se a capacidade de armazenar os clientes está cheia.
	{
        printf("Capacidade maxima atingida!\n");//mensagem exibida caso o armazenamento esteja cheio.
        return;//retorna ao menu
    }

    Cliente novo; //cria uma variável temporaria chamada "novo" do tipo cliente.
    printf("Digite o nome: ");
    scanf("%s", novo.nome);
    printf("Digite a idade: ");
    scanf("%d", &novo.idade);
    printf("Digite o CPF: ");
    scanf("%s", novo.cpf);
    printf("Digite a CNH: ");
    scanf("%s", novo.cnh);
	//pergunta as informações,o usuario insere e depois cada uma é armazenada na struct Cliente.
	
    clientes[*quantidade] = novo;
    (*quantidade)++;//atualiza a quantidade de clientes.
    printf("Cliente inserido com sucesso!\n");
}

//função para remover um cliente pelo cpf.
void removerCliente(Cliente clientes[], int *quantidade) {
    char cpf[13];//variável para armazenar o cpf a ser buscado.
    printf("Digite o CPF do cliente a ser removido: ");
    scanf("%s", cpf);//lê o cpf digitado pelo usuário e armazena na variavel cpf.

	int i;//declara a variável para iterar o array de clientes.
	
    for ( i = 0; i < *quantidade; i++) { 
	 if (strcmp(clientes[i].cpf, cpf) == 0) //verifica se o cpf corresponde 
     /*move os clientes seguintes para preencher a lacuna.*/   {
        	int j;
            for ( j = i; j < *quantidade - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*quantidade)--; //diminui a quantidade de clientes
            printf("Cliente removido com sucesso!\n");
            return;
        }
    }

    printf("Cliente nao encontrado!\n");
}

//função para buscar um cliente pelo cpf.
void buscarCliente(Cliente clientes[], int quantidade) {
    char cpf[13];//variável para armazenar o cpf a ser buscado.
    printf("Digite o CPF do cliente a ser buscado: ");
    scanf("%s", cpf);//lê o cpf digitado pelo usuário e armazena na variavel cpf.
	
	int i;//declara a variável para iterar o array de clientes.
	
    for ( i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) //compara o cpf do cliente com o cpf digitado.
		{
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Idade: %d\n", clientes[i].idade);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("CNH: %s\n", clientes[i].cnh);
            //informações do usuário encontrado.
            return;
        }
    }

    printf("Cliente nao encontrado!\n");
    //mensagem exibida caso o cpf não seja encontrado.
}

//função para listar todos os clientes cadastrados
void listarClientes(Cliente clientes[], int quantidade) {
    if (quantidade == 0) //verifica se há clientes cadastrados.
	{
        printf("Nenhum cliente cadastrado!\n");
        return; //caso não tenha nenhum,retorna ao menu e exibe a mensagem.
    }

    printf("\nLista de clientes:\n");
 	int i;//declara a variável para iterar o array de clientes.
 	
 	//percorre o array de clientes para exibir as informações de cada um
	for ( i = 0; i < quantidade; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("CNH: %s\n", clientes[i].cnh);
    }
}

//função para atualizar os dados do cliente
void atualizarCliente(Cliente clientes[], int quantidade) {
    char cpf[13];//variável para armazenar o cpf a ser buscado.
    printf("Digite o CPF do cliente a ser atualizado: ");
    scanf("%s", cpf);//lê o cpf buscado e armazena na variavel cpf
    
	int i;//declara a variável para iterar o array de clientes.
	
	//percorre a lista de clientes para localizar o cpf
    for ( i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) //verifica se o cpf do cliente é igual ao digitado pelo usuario
		{   //apos encontrar ,permite atualizar as informações do cliente
            printf("Digite o novo nome: ");
            scanf("%s", clientes[i].nome); //lê o novo nome do cliente
            printf("Digite a nova idade: ");
            scanf("%d", &clientes[i].idade); //lê a nova idade do cliente
            printf("Digite a nova CNH: ");
            scanf("%s", clientes[i].cnh); //lê a nova cnh do cliente
            printf("Cliente atualizado com sucesso!\n");
            return;
            //sai da função após a atualização do cliente 
        }
    }

    printf("Cliente nao encontrado!\n");
}

//implementação das funções para veículos
void inserirVeiculo(Veiculo veiculos[], int *quantidade) {
    if (*quantidade >= MAX) //verifica se a capacidade de veiculos está cheia
	{
        printf("Capacidade maxima atingida!\n");
        return; //caso sim,retorna ao menu e exibe a mensagem
    }

    Veiculo novo; //cria uma variável temporaria chamada "novo" do tipo veiculo.
    printf("Digite o modelo: ");
    scanf("%s", novo.modelo); //lê o modelo do carro
    printf("Digite o valor: ");
    scanf("%f", &novo.valor); //lê o valor do carro
    printf("Digite a placa: ");
    scanf("%s", novo.placa); //lê a placa do carro

    veiculos[*quantidade] = novo; //adiciona o veiculo "novo" à posição atual do array
    (*quantidade)++; //aumenta a quantidade de veiculos
    printf("Veiculo inserido com sucesso!\n");
}

void removerVeiculo(Veiculo veiculos[], int *quantidade) {
    char placa[10];//variável para armazenar a placa a ser buscada.
    printf("Digite a placa do veiculo a ser removido: ");
    scanf("%s", placa);//lê a placa buscada e armazena na variavel placa.
    
	int i;//declara a variável para iterar o array de veiculos.	
	
	//percorre a lista de veiculos para localizar a placa
    for ( i = 0; i < *quantidade; i++) 
	 {
        if (strcmp(veiculos[i].placa, placa) == 0)	//verifica se a placa do veiculo é igual ao digitado pelo usuario	
		 { //caso a placa seja encontrada inicia o processo de remoção
            
			int j;//variavel para laço de reorganização
			
			//desloca os veiculos subsequentes uma posição para trás
			for ( j = i; j < *quantidade - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }
            //diminui a quantidade de veiculos
            (*quantidade)--;
            printf("Veiculo removido com sucesso!\n");
            return;//encerra a função após a remoção
        }
    }
	
    printf("Veiculo nao encontrado!\n");
    //caso após o for nenhuma placa tenha sido encontrada,essa mensagem será exibida
}

void buscarVeiculo(Veiculo veiculos[], int quantidade) {
    char placa[10];//variável para armazenar a placa a ser buscada.
    printf("Digite a placa do veiculo a ser buscado: ");
    scanf("%s", placa);//lê a placa buscada e armazena na variavel placa.
    
	int i;//declara a variável para iterar o array de veiculos.
	
    for ( i = 0; i < quantidade; i++)//percorre a lista de veiculos para localizar a placa
	 {
        if (strcmp(veiculos[i].placa, placa) == 0) //verifica se a placa do veiculo é igual ao digitado pelo usuario
		{
            printf("\nVeiculo encontrado:\n");
            printf("Modelo: %s\n", veiculos[i].modelo);
            printf("Valor: %.2f\n", veiculos[i].valor);
            printf("Placa: %s\n", veiculos[i].placa);
            return;
            //exibe as informações do veículo e volta ao menu
        }
    }

    printf("Veiculo nao encontrado!\n");
    //caso após o for nenhuma placa tenha sido encontrada,essa mensagem será exibida
}

void listarVeiculos(Veiculo veiculos[], int quantidade) {
    if (quantidade == 0)//verifica se há veículos cadastrados
	 {
        printf("Nenhum veiculo cadastrado!\n");
        return;
        //caso não haja veículos cadastrados exibe a mensagem e termina a função
    }

    printf("\nLista de veiculos:\n");//inicia a exibição da lista de veículos
    
    int i;//declara a variável para iterar o array de veiculos.
    
    //loop para percorrer os veículos cadastrados
	for ( i = 0; i < quantidade; i++) {
        printf("\n Nome do veiculo %d:\n", i + 1); // i + 1 para numerar a lista a partir de 1, e não de 0.
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Valor: %.2f\n", veiculos[i].valor);
        printf("Placa: %s\n", veiculos[i].placa);
        //exibe todas as informações do veículo
    }
}

//lista para atualizar os dados de um veículo
void atualizarVeiculo(Veiculo veiculos[], int quantidade) {
    char placa[10];//variável para armazenar a placa a ser buscada.
    printf("Digite a placa do veiculo a ser atualizado: ");
    scanf("%s", placa);//lê a placa buscada e armazena na variavel placa.

	int i;//declara a variável para iterar o array de veiculos.
	
    for ( i = 0; i < quantidade; i++)//percorre a lista de veiculos para localizar a placa
	 {
        if (strcmp(veiculos[i].placa, placa) == 0)//verifica se a placa do veiculo é igual ao digitado pelo usuario
		 {
            printf("Digite o novo modelo: ");
            scanf("%s", veiculos[i].modelo);//lê e atualiza o campo "modelo"
            printf("Digite o novo valor: ");
            scanf("%f", &veiculos[i].valor);//lê e atualiza o campo "valor"
            printf("Veiculo atualizado com sucesso!\n");
            return;
            //ao executar com sucesso,finaliza a função
        }
    }

    printf("Veiculo nao encontrado!\n");
     //caso a placa informada não seja encontrada na lista de veículos, exibe uma mensagem de erro;
}

//função que vende o veículo e depois exclui ele do sistema
void venderVeiculo(Cliente clientes[], int *qtdClientes, Veiculo veiculos[], int *qtdVeiculos) {
    if (*qtdVeiculos == 0) {
        printf("Nenhum veiculo disponivel para venda!\n");
        return;
        //caso não haja nenhum veículo,essa mensagem será exibida
    }

    
    Cliente novoCliente; //declara uma variável "novoCliente" do tipo "Cliente",que vai ser usada para armazenar os dados de um cliente.
    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente.idade);
    printf("Digite o CPF do cliente: ");
    scanf("%s", novoCliente.cpf);
    printf("Digite a CNH do cliente: ");
    scanf("%s", novoCliente.cnh);
    //lê e armazena os dados inseridos

    //função que exibe os veículos disponíveis
    listarVeiculos(veiculos, *qtdVeiculos);

    
    char placa[10];//declara uma variável para armazenar a placa do veículo a ser vendido
    printf("Digite a placa do veiculo a ser vendido: ");
    scanf("%s", placa);//lê a placa fornecida pelo usuário.

    int i;//declara a variável para iterar o array de veiculos.
    
    for ( i = 0; i < *qtdVeiculos; i++) //percorre a lista de veiculos para localizar a placa
	{
        if (strcmp(veiculos[i].placa, placa) == 0) //verifica se a placa do veiculo é igual ao digitado pelo usuario
		{
            printf("\nVeiculo vendido com sucesso!\n");
            printf("Modelo: %s\n", veiculos[i].modelo);
            printf("Valor: %.2f\n", veiculos[i].valor);
            printf("Placa: %s\n", veiculos[i].placa);
			//após a operação ser concluida mostra a mensagem do primeiro printf seguida das informações do veículo
            
            int j;//variavel para laço de reorganização
            
            for ( j = i; j < *qtdVeiculos - 1; j++) {
                veiculos[j] = veiculos[j + 1];
                 //desloca o veículo seguinte para o lugar do veículo vendido
            }
            (*qtdVeiculos)--;//diminui a quantidade de veículos e depois finaliza a função

            return;
        }
    }

    printf("Veiculo com a placa %s nao encontrado!\n", placa);
}
//função para buscar veículo por modelo
void buscarVeiculoPorModelo(Veiculo veiculos[], int quantidade) {
    char modelo[30];
    printf("Digite o modelo do veiculo a ser buscado: ");
    scanf("%s", modelo);
    //lê o modelo do veículo fornecido pelo usuário 

    //variável para indicar se o veículo foi encontrado
    int encontrado = 0;
    int i;
    
    for ( i = 0; i < quantidade; i++)//percorre a lista de veiculos para localizar o modelo
	 { 
        if (strcmp(veiculos[i].modelo, modelo) == 0)//verifica se o modelo do veiculo é igual ao digitado pelo usuario
		 {
            printf("\nVeiculo encontrado:\n");
            printf("Modelo: %s\n", veiculos[i].modelo);
            printf("Valor: %.2f\n", veiculos[i].valor);
            printf("Placa: %s\n", veiculos[i].placa);
            //se o modelo for encontrado, exibe as informações do veículo
            encontrado = 1;//indica que o veiculo foi encontrado
        }
    }

    if (!encontrado) {
        printf("Nenhum veiculo com o modelo '%s' encontrado.\n", modelo);
    } //se nenhum veículo com o modelo informado for encontrado,exibe essa mensagem
}

//função para buscar veículo por preço
void buscarVeiculoPorPreco(Veiculo veiculos[], int quantidade) {
    float precoMin, precoMax;
    //declaração das variáveis do preço mínimo e do máximo.
    
    printf("Digite o preco minimo: ");
    scanf("%f", &precoMin);
 	//lê o preço mínimo
    printf("Digite o preco maximo: ");
    scanf("%f", &precoMax);
    //lê o preço máximo

	//variável para indicar se algum veículo foi encontrado pelo intervalo de preço
    int encontrado = 0;
    int i;
    
    for (i = 0; i < quantidade; i++)//percorre a lista de veiculos
	 {
        if (veiculos[i].valor >= precoMin && veiculos[i].valor <= precoMax)//verifica se o valor do veículo está dentro do intervalo informado
		 {
            printf("\nVeiculo encontrado:\n");
            printf("Modelo: %s\n", veiculos[i].modelo);
            printf("Valor: %.2f\n", veiculos[i].valor);
            printf("Placa: %s\n", veiculos[i].placa);
            //se o veículo estiver na faixa de preço,a função exibe suas informações
            encontrado = 1;//marca que ao menos um veículo foi encontrado
        }
    }

    if (!encontrado) {
        printf("Nenhum veiculo encontrado no intervalo de preço %.2f - %.2f.\n", precoMin, precoMax);
    } //se nenhum veículo dentra da faixa de preço for encontrado,exibe essa mensagem
}

//função para salvar os dados dos clientes e veículos
void salvarConcessionaria(Cliente clientes[], int qtdClientes, Veiculo veiculos[], int qtdVeiculos) {
     //abre o arquivo "concessionaria.txt" para escrita.
	FILE *arquivo = fopen("concessionaria.txt", "w");
	
    if (arquivo == NULL)
	 {//verifica se o arquivo foi aberto corretamente ou não
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;//finaliza a função
		 }

    
    fprintf(arquivo, "#CLIENTES\n");//marca onde estão as informações dos clientes.
    int i;
    for ( i = 0; i < qtdClientes; i++) //laço para percorrer e salvar todos os clientes.
	{
        fprintf(arquivo, "%s;%d;%s;%s\n", clientes[i].nome, clientes[i].idade, clientes[i].cpf, clientes[i].cnh);
        //escreve os dados de cada cliente no arquivo,separados por ponto e vírgula.
	 }

    // Salvar veículos
    fprintf(arquivo, "#VEICULOS\n");//marca onde estão as informações dos veículos.
    
    for (i = 0; i < qtdVeiculos; i++)//laço para percorrer e salvar todos os veículos.
	{
        fprintf(arquivo, "%s;%.2f;%s\n", veiculos[i].modelo, veiculos[i].valor, veiculos[i].placa);
        //escreve os dados de cada veiculo no arquivo,separados por ponto e vírgula.
    }

	//fecha o arquivo após a escrita.
    fclose(arquivo);
    printf("Dados salvos em concessionaria.txt com sucesso!\n");
}

//função utilizada para carregar os dados salvos anteriormente.
void carregarConcessionaria(Cliente clientes[], int *qtdClientes, Veiculo veiculos[], int *qtdVeiculos) {
    FILE *arquivo = fopen("concessionaria.txt", "r");//abre o arquivo "concessionaria.txt" para leitura.
    
	if (arquivo == NULL)//verifica se o arquivo foi aberto corretamente ou não.
	 {
        printf("Nenhum arquivo encontrado. Continuando com o sistema vazio...\n");
        return;
    }

    char linha[100];//buffer para armazenar cada linha do arquivo.
    int lendoClientes = 0, lendoVeiculos = 0;//flags para saber qual seção do arquivo está sendo lida.

	//lê o arquivo linha por linha.
    while (fgets(linha, sizeof(linha), arquivo)) {
     //se a linha for "#CLIENTES", muda a flag para ler os dados de clientes.
      if (strncmp(linha, "#CLIENTES", 9) == 0) {
            lendoClientes = 1;
            lendoVeiculos = 0;
            continue;//vai para a próxima linha
            
          //se a linha for "#VEICULOS", muda a flag para ler os dados de veículos.   
        } else if (strncmp(linha, "#VEICULOS", 9) == 0) {
            lendoClientes = 0;
            lendoVeiculos = 1;
            continue;//vai para a próxima linha.
        }
		
		//se estamos lendo a seção de clientes.
      if (lendoClientes) {
            Cliente novo;
            sscanf(linha, "%[^;];%d;%[^;];%[^;\n]", novo.nome, &novo.idade, novo.cpf, novo.cnh);
             //sscanf para ler os dados do cliente da linha.
            clientes[*qtdClientes] = novo;
            //armazena o cliente no array de clientes.
            (*qtdClientes)++;//aumenta a quantidade de clientes.
   } 
   //se estamos lendo a seção de veiculos.
   else if (lendoVeiculos) {
            Veiculo novo;
            sscanf(linha, "%[^;];%f;%[^;\n]", novo.modelo, &novo.valor, novo.placa);
            //sscanf para ler os dados do veiculo da linha.
            veiculos[*qtdVeiculos] = novo;
            (*qtdVeiculos)++;//aumenta a quantidade de veículos.
        }
    }
	//fecha o arquivo após a leitura e exibe a mensagem.
    fclose(arquivo);
    printf("Dados carregados de concessionaria.txt com sucesso!\n");
}



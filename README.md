# data-structure-project

####################################################################################

Para rodar o programa coloque o arquivo de endereço dos correios na pasta principal			<---- (IMPORTANTE)

####################################################################################
Para compilar o programa use o seguinte comando:

g++ edpf.cpp endereco/*.cpp arvoreBinaria/ArvoreBinaria.cpp -o edpf

ou

g++ -v -O2 edpf.cpp endereco/*.cpp arvoreBinaria/ArvoreBinaria.cpp -o edpf

####################################################################################
Para executar use o seguinte comando:

./edpf

####################################################################################

Projeto Final de Estrutura de dados
Isaac Állef Santos Cruz e Marcio Peixoto

Foi feita uma classe chamada “End” que representa o endereço ou seja as informações de cada linha do arquivo de endereços dos correios.

Também foi feita uma classe chamada “EnderecoHelper” que pega as informações de cada linha do arquivo, as coloca em um End e coloca o End em uma estrutura de lista duplamente encadeada usando template e em uma árvore.

Além das estruturas citadas a cima foi utilizado um vetor para guardar o resultado das buscas feitas nessas estruturas que podem retornar varios Ends. Ou seja uma combinação eficiente de duas estruturas.

Também foi feita a gravação em arquivo de cada estrutura e se encontra da pasta “gravado/”.

No “edpf.cpp” que é onde se encontra o main foi feita a análise do tempo de criação, inserção, remoção, busca e gravação de cada estrutura, além de um menu onde se pode inserir, remover, buscar, listar e gravar em cada uma das listas. É mostrado o tempo que cada função levou para ser executada.

Foi constatado que o processo de criação, inserção (no final) e gravação de uma lista duplamente encadeada é mais rápida do que em uma árvore. No entanto na busca, a remoção (exceto no fim e no começo) e inserção ordenada a arvore é superior. A combinação das estruturas se faz muitas vezes necessária, dadas que cada uma tem seus pontos fortes e fracos e são mais eficientes em determinados casos.

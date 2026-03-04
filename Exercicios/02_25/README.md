# EX1.c
```
Recebe 10 números inteiros como entrada e o armazena em um vetor, 
em seguida recebe um outro número inteiro em uma variável
e retorna quais inteiros do vetor são divisíveis pelo inteiro da variável.
```

# EX2.c
```
Crie um vetor que armazena 50 valores, em seguida preenche cada valor
com o resto da divisão de dois números determinados com base em qual 
é a posição do valor do vetor. Por fim, exibe o vetor.
```

# EX3.c
```
Cria um vetor (V) de tamanho 10 e em seguida entra em um loop
que é executado 10 vezes, dentro desse loop, toda vez é
armazenado um valor em uma variavél temp, 
depois chama uma função (vefNum) que recebe como paramêtros
o endereço de temp, o vetor V, e a repetição do loop atual.
Dentro de VefNum, inicia um um loop que repete-se até a repetição
atual do loop de fora, e verifica se o conteúdo de temp é igual
algum dos valores dentro do vetor V, verificando todos os valores
anteriores, sem percorrer valores não preenchidos. Caso o valor seja
igual, ele avisa que já existe esse número e pede para inserir outro,
em seguida chama a própria funcão vefNum novamente, ficando em um loop
até inserir um valor que não foi colocado antes no vetor V. Após
encerrar o loop, o valor de V na posição do loop exterior atual é preenchido
com o valor de temp.
```
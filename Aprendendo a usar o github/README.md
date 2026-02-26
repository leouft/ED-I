# Criando um projeto e mandando para o GitHub

```
git init
```
Cria uma pasta oculta que fica o histórico (deve ser executado no terminal da pasta do projeto).

```
git add .
```
Adiciona todos arquivos do projeto (sempre que criar um arquivo novo, é necessário utilizar git add nome_do_arquivo para adicioná-lo e também ao modificá-lo).

```
git commit -m "Primeiro commit"
```
Cria um commit para o projeto (utilize sempre que atualizar algo já existente no projeto ou criar).


```
Crie um repositório no GitHub vazio.
```

```
git remote add origin url_do_repositorio
```
Conecta-se ao repositório do GitHub.

```
git branch -M main
```
Define o branch principal.

```
git push -u origin main
```
Envia tudo para o GitHub.


# Manter atualizações

```
git add nome_do_arquivo
```
Sempre use ao adicionar novos arquivos.

```
git commit -m "mensagem"
```
Adiciona um commit com a mensagem de alterações.

```
git push
```
Envia pro GitHub.
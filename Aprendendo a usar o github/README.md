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
Sempre use ao adicionar novos arquivos e atualizá-los.

```
git commit -m "mensagem"
```
Adiciona um commit com a mensagem de alterações.

```
git push
```
Envia pro GitHub.

# Baixar atualizações do seu projeto
```
git pull
```
Ele busca o que tiver de diferente do GitHub pro seu local (computador) e baixa tudo.


# Criando um projeto pelo GitHub e mandando pro PC (também serve pra pegar projeto dozotro)
```
Crie um repositório no GitHub e copie o link (ou pegue o link de outro repositório que deseja fazer isso)
```

```
git clone URL_DO_REPOSITORIO
```
Utilize isso no terminal na pasta do seu computador que deseja salvar localmente o projeto,
isso vai trazer TUDO que está nele para o seu local (computador) dentro de uma pasta.

Nesse caso tá pronto só ir mantendo atualizações e baixando atualizações bjoossss.
# Observações

Ao seguir as instruções daqui, já supunho
que você tenha o Git baixado.

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


# Mandando pro PC um repositório do GitHub (também serve pra pegar projeto dozotro)
```
Copie o link do seu repositório pronto (ou pegue o link de outro repositório que deseja fazer isso)
```

```
git clone URL_DO_REPOSITORIO.git
```
Utilize isso no terminal na pasta do seu computador que deseja salvar localmente o projeto,
isso vai trazer TUDO que está nele para o seu local (computador) dentro de uma pasta.

Nesse caso tá pronto se o repositório for teu, só ir mantendo atualizações e baixando atualizações bjoossss.

Caso não, continua:

```
git remote remove origin
git remote add origin URL_DO_SEU_REPOSITORIO
```
Ou seja, crie outro repositório, e rode os códigos.
Isso vai conectar o seu repositório clonado no
seu computador com o novo da sua conta do GitHub.

```
git push -u origin main
```
Envia tudo pro GitHub,
a partir daqui, só manter atualizando.

# Retornar o seu local para uma versão antiga
```
git log --oneline
```
Mostra o histórico de commits (também pode ser visto pelo próprio GitHub).
Irá mostrar algo tipo:
a1b2c3d Atualização tal 2
d4e5f6g Atualização tal
f7g8h9i Primeiro commit
Onde esses codigos iniciais são hash, o que identifica uma commit.

```
git checkout HASH_DO_COMMIT
```
Testa uma versão antiga no computador (local).
Então seus arquivos vão ficar igual essa versão
do commit, mas nao se preocupe, a versão atualizada
ainda está salva no GitHub.
Se quiser salvar essa atualização atual, só
fazer igual as outras vezes.

```
git checkout main
```
Retorna pra versão mais recente que está
no seu repositório do GitHub.

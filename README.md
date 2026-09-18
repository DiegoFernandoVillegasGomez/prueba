# Mi Proyecto


# 1. Inicializa el repositorio local de Git
git init

# 2. Asegúrate de que la rama inicial se llame main
git branch -M main

# 3. Agrega tus archivos iniciales (código base o README.md)
git add .

# 4. Haz tu primer commit
git commit -m "chore: initial commit"

//rama develop

# 1. Crea la rama develop a partir de main
git checkout -b develop

# 2. Sube develop al repositorio remoto
git push -u origin develop

//feature
# 1. Partir siempre desde develop al día
git checkout develop
git pull origin develop
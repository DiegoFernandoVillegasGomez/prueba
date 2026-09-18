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

# 3. Trabajar en el código y guardar cambios
git add .
git commit -m "feat: implement user login endpoint"

# 4. Subir la feature al remoto (para backup o Pull Request)
git push -u origin feature/auth-login
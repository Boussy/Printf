# ft\_printf – Recode du printf en C

## 🚀 Introduction

`ft_printf` est un projet phare de l’école 42.
Il consiste à réimplémenter la fonction **`printf` de la libc**, avec la gestion des conversions principales.

C’est une étape clé pour apprendre à :

* Manipuler les **fonctions variadiques** (`<stdarg.h>`).
* Gérer le **parsing de chaînes** et la modularité du code.
* Implémenter un code robuste, réutilisable et efficace.

---

## 🛠️ Fonctionnalités implémentées

Le projet prend en charge :

* `%c` : caractères
* `%s` : chaînes de caractères
* `%p` : pointeurs (format hexadécimal)
* `%d` / `%i` : entiers signés
* `%u` : entiers non signés
* `%x` / `%X` : hexadécimal min/maj
* `%%` : le caractère `%`

---

## 🤓 Structure du projet

Le projet est découpé en plusieurs parties :

* **`Makefile`** → compile la bibliothèque `libftprintf.a`.
* **`ft_printf.h`** → contient les prototypes et définitions utiles.
* **`srcs/`** → contient le cœur du projet :
      * `parsing.c` → identifie les conversions dans la chaîne de format.
      * `conversion_*.c` → gère chaque type de conversion (`s`, `d`, `x`, etc.).
      * autres fonctions utilitaires pour l’affichage et la gestion mémoire.

---

## 🥸 Subtilités & enjeux du projet

### 🔹 Parsing du format

L’un des points clés est de **parcourir la string format** et de détecter chaque `%`.
Chaque conversion est ensuite redirigée vers la bonne fonction de gestion.

### 🔹 Fonctions variadiques

L’utilisation de `va_list`, `va_start`, `va_arg`, `va_end` est au cœur du projet.
Cela permet de traiter un **nombre variable d’arguments**, comme le fait le vrai `printf`.

### 🔹 Gestion des conversions

Chaque conversion est gérée dans une fonction dédiée (`ft_print_char`, `ft_print_str`, `ft_print_hex`…), ce qui rend le code lisible et modulaire.

### 🔹 Cas particuliers

* `%p` → gestion de `NULL` (affichage `(nil)` par convention).
* `%s` → affichage correct si la chaîne est `NULL`.
* `%d` / `%i` → gestion des bornes (`INT_MIN`, `INT_MAX`).

---

## ✅ Conseils pour refaire le projet

1. Commence par une version **simplifiée** (`%c`, `%s`, `%d`).
2. Ajoute progressivement les autres conversions.
3. Crée un **dispatcher** clair pour rediriger chaque spécificateur vers sa fonction.
4. Teste énormément avec des **cas limites** :

   * `ft_printf("%s", NULL)`
   * `ft_printf("%d", INT_MIN)`
   * `ft_printf("%p", NULL)`
5. Organise ton code dès le début (fichiers séparés, Makefile, header).

---

## 📖 Ressources utiles

* 📌 [Documentation stdarg.h](https://en.cppreference.com/w/c/variadic)
* 📌 [GeeksforGeeks – Implémentation simplifiée de printf](https://www.geeksforgeeks.org/implement-printf-function-in-c/)
* 📌 [Beej’s Guide to C – Variadic Functions](https://beej.us/guide/bgc/html/split/variadic.html)
* 📌 [Vidéo – printf explained](https://www.youtube.com/watch?v=Y7xi5cG0nYE)
* 📌 [42docs – Tests pour ft\_printf](https://github.com/Tripouille/printfTester)

---

## 🎯 Objectif final

À la fin de `ft_printf`, tu auras :

* Une compréhension approfondie des **fonctions variadiques**.
* Une capacité à gérer du **parsing complexe**.
* Un code robuste et **réutilisable dans tes futurs projets** (`minishell`, `cub3d`, etc.).


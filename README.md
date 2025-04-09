# My_Paint

![Version](https://img.shields.io/badge/version-1.0-blue.svg)
![CSFML](https://img.shields.io/badge/CSFML-2.5-green.svg)

## 📋 Description

My_Paint est une application graphique développée en C utilisant la bibliothèque CSFML qui permet de créer des dessins. Inspiré de logiciels comme Paint, il offre une interface intuitive et diverses fonctionnalités de dessin.

## 🖥️ Captures d'écran

<!-- Des captures d'écran peuvent être ajoutées ici -->

## ✨ Fonctionnalités

- **Outils de dessin** :
  - Crayon
  - Brosse (différentes tailles)
  - Gomme
  - Pipette (sélecteur de couleur)
  - Seau de remplissage

- **Palette de couleurs** :
  - 8 couleurs prédéfinies (noir, blanc, rouge, vert, bleu, cyan, magenta, jaune)

- **Barre de menus** :
  - Fichier (nouveau, ouvrir, sauvegarder)
  - Édition (taille du crayon, gomme, brosse)
  - Aide (tutoriel, à propos)

- **Options de taille** :
  - Modification de la taille de l'outil de dessin

- **Gestion de fichiers** :
  - Sauvegarde d'images (formats pris en charge : PNG, JPG, BMP, JPEG)
  - Ouverture d'images existantes
  - Création de nouvelles images

## 🛠️ Prérequis

- GCC
- Make
- CSFML (bibliothèque SFML pour C)

## 📥 Installation

```bash
# Clonez le dépôt
git clone https://github.com/votre-username/Paint.git

# Accédez au répertoire
cd Paint

# Compilez le projet
make
```

## 🚀 Utilisation

Pour lancer l'application :

```bash
./my_paint
```

Pour afficher l'aide :

```bash
./my_paint -h
```

## 📚 Guide d'utilisation

- **Dessiner** : Cliquez et déplacez la souris avec le bouton gauche maintenu
- **Changer de couleur** : Cliquez sur une des couleurs dans la palette à droite
- **Changer la taille** : Utilisez les boutons "+" et "-" dans le menu Édition
- **Gomme** : Activez la gomme dans le menu Édition
- **Sauvegarder** : Menu Fichier > Sauvegarder
- **Créer un nouveau dessin** : Menu Fichier > Nouveau fichier

## 🧪 Structure du projet

```
.
├── about_message.txt      # Message "À propos"
├── help_message.txt       # Message d'aide
├── Makefile               # Makefile principal
├── code/                  # Code source principal
│   ├── asset/             # Ressources graphiques
│   ├── *.c                # Fichiers sources
│   ├── my.h               # En-tête principal
│   └── Makefile           # Makefile pour le code
└── lib/                   # Bibliothèques
    └── my/                # Bibliothèque personnalisée
        ├── *.c            # Fonctions utilitaires
        ├── my.h           # En-tête de la bibliothèque
        └── Makefile       # Makefile pour la bibliothèque
```

## 🤝 Auteurs

- **Anthony Colombani-Gailleur**
- **Yanis Prevost**

Réalisé en mars 2024, Epitech-Marseille.
# Projet d'Interface Homme-Machine : Timebomb

# UFR de Mathématique et d'Informatique | L3 Informatique - S5 Automne 2019




------------------------------------------------------------------------------

## Présentation


Le dépôt Git du projet est accessible en
[cliquant sur ce lien](https://git.unistra.fr/joren.schuster/ihm-projet).

Bienvenue sur cette page du qui regroupe l'ensemble du travail réalisé 
pour le projet *Timebomb*.

Ce projet, qui visait à implémenter le jeu de cartes *Timebomb* sur PC, a été
réalisé par **Guillaume Bequet**, **Samuel Dierstein**,
**Craig Hiernard**, **Arthur Klipfel** et **Joren Schuster** dans le cadre
de l'UE d'Interface Homme-Machine du semestre 5.





------------------------------------------------------------------------------

## Jouer au jeu



Compilation
-----------


Le jeu a été développé sous Windows 10, Mac et sous Linux, et peut être lancé
depuis chacune de ces plateformes.

Pour ce faire, il faut avoir installé :

- **QtCreator** (version 5.9.5)
  Rendez-vous
  [sur cette page](https://download.qt.io/official_releases/qt/5.9/5.9.5/),
  puis téléchargez la version correspondante à votre OS ;

- **QMake** (version 3.1).


**Note :**
Sous Linux, certains paquets sont nécessaires pour que le jeu puisse être
lancé. Avec une distribution basée sur Debian (comme Ubuntu ou Linux Mint), le
gestionnaire `apt` devra être utilisé afin d'installer les paquets suivants :

 - `build-essential`
 - `libglib-dev`




Lancement
---------

Pour lancer le jeu, après avoir compilé à l'aide de QtCreator, il suffit de
lancer l'exécutable qui aura été créé dans le dossier de `build`.




------------------------------------------------------------------------------

## (Autres sections)


Les sections suivantes ont été utiles lors du développement et de la réalisation
du projet. Elles ne sont plus utilisées désormais, mais elles sont toutefois
laissées en libre consultation afin d'en garder une trace.




Organisation et tâches à faire
------------------------------

La page *Trello* récapitulant les tâches à faire est accessible en
[cliquant sur ce lien](https://trello.com/b/0XbpDYb0/timebomb)




Conventions de code
-------------------

- Indentation :
    - accolades en début de ligne
    - tabulations -> espaces
    - taille d'indentation à 4
- Écriture des fonctions/vars/consts en **Anglais** (pour garder 
  l'homogénéité avec les autres fonctions de Qt et du C++) :
    - fonctions et variables en CamelCase : `functionForSomething`
    - constantes : `CONSTANT_FOR_SOMETHING`

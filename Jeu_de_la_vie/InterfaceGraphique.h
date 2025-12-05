#pragma once

// 1. INCLUSIONS DES CLASSES DE LOGIQUE
// Nous incluons Cellule.h car l'interface a besoin de connaître l'état de chaque Cellule.
#include "Jeu_de_la_vie/Cellule.h" 

// 2. INCLUSIONS DES LIBRAIRIES EXTERNES (SFML et utilitaires)
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

class Interface {
private:
    // Variables pour la taille de la fenêtre et l'état du menu
    int largeur_fenetre;
    int longueur_fenetre;
    bool showcredits;
    Font font;

    // Constantes pour le dessin de la grille
    const float CASE_SIZE = 25.0f;
    const float X_OFFSET = 900.0f;
    const float Y_OFFSET = 200.0f;
    const Color CASE_ALIVE_COLOR = Color::Red;
    const Color CASE_DEAD_COLOR = Color::Cyan;
    const Color BORDER_COLOR = Color::Black;

public:
    // CONSTRUCTEUR : initialise les dimensions de la fenêtre
    Interface(int largeur, int longueur);

    // FONCTION PRINCIPALE : Affiche le menu et gère la boucle de la fenêtre
    void MenuBase();

    // DIVERS : Gestion du texte, police et événements
    void SetTxt(Text& txt, string str);
    void SetTxtTitre(Text& txt, string str);
    void SetTxtCredits(Text& txt, string str);
    void LoadFont();
    void inputHandler(Event& event, Window& window);
    void credits(RenderWindow& window);

    // DESSIN : Dessine un bouton et la grille
    bool drawButton(
        RenderWindow& window, float x, float y, float width, float height, const string& label, 
        const string& fontPath, Color bgColor = Color::Blue, Color textColor = Color::White
    );
    
    // Cette fonction prend l'état de la grille et le dessine (utilise Cellule)
    void gameGraph(RenderWindow& window, const vector<vector<Cellule>>& grille);
};
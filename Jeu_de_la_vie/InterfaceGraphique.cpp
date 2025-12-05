#include "InterfaceGraphique.h"
#include "Jeu_de_la_vie/JeuDeLaVie.h"
#include "Jeu_de_la_vie/Cellule.h"
#include "generation.h"

using namespace sf;
using namespace std;

const float CASE_SIZE = 20.0f;
const float X_OFFSET = 100.0f;
const float Y_OFFSET = 200.0f;
const Color CASE_ALIVE_COLOR = Color::Green;
const Color CASE_DEAD_COLOR = Color::Black;
const Color BORDER_COLOR = Color::Blue;

JeuDeLaVie maGrille;
Text txt;
Generation gen(20);

Interface::Interface(int largeur, int longueur)
    : largeur_fenetre(largeur), longueur_fenetre(longueur) {
}

void Interface::MenuBase() {
    string filename = "jeu.txt";
    RenderWindow window(VideoMode(largeur_fenetre, longueur_fenetre), "Jeu de la vie");
    LoadFont();
    showcredits = false;

    if (!maGrille.chargerGrilleDepuisFichier(filename)) {
        cerr << "Erreur : Chargement de la grille échoué !" << endl;
        return;
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("arriere.png")) {
        cerr << "Erreur : Impossible de charger l'image de fond." << endl;
    }

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    FloatRect textureRect = backgroundSprite.getLocalBounds();

    backgroundSprite.setScale(
        static_cast<float>(largeur_fenetre) / textureRect.width,
        static_cast<float>(longueur_fenetre) / textureRect.height
    );

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandler(event, window);
        }

        window.clear(Color::White);
        if (backgroundTexture.isSane()) {
            window.draw(backgroundSprite);
        }

        SetTxtTitre(txt, "BIENVENUE SUR LE JEU DE LA VIE DU GROUPE 2");
        txt.setPosition(window.getSize().x / 2, 60);
        window.draw(txt);

        if (drawButton(window, 100, 300, 350, 150, "Jouer en mode graphique", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            for (int z = 0; z < 100; z++) {
                maGrille.compter_voisin();
                gameGraph(window, maGrille.getGrille());
                gen.incrementer();
                this_thread::sleep_for(std::chrono::seconds(1));

                Event escEvent;
                while (window.pollEvent(escEvent)) {
                    if (escEvent.type == Event::KeyPressed && escEvent.key.code == Keyboard::Escape) {
                        window.close();
                        return;
                    }
                }
            }
        }

        if (drawButton(window, 100, 800, 350, 150, "Jouer en mode console", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            window.close();
        }

        if (drawButton(window, 100, 1300, 350, 150, "Crédits", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            showcredits = true;
        }

        if (showcredits == true) {
            credits(window);
            txt.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);
            window.draw(txt);
        }

        window.display();
    }
}

void Interface::SetTxtTitre(Text& txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold | Text::Underlined);
    FloatRect textBounds = txt.getLocalBounds();
    txt.setOrigin(textBounds.width / 2, textBounds.top);
}

void Interface::SetTxtCredits(Text& txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold | Text::Underlined);
    FloatRect textBounds = txt.getLocalBounds();
    txt.setOrigin(textBounds.width / 2, textBounds.top);
}

void Interface::SetTxt(Text& txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold | Text::Underlined);
}

void Interface::LoadFont() {
    if (!font.loadFromFile("ressources/lobster.ttf")) {
        cerr << "Erreur de chargement de la police." << endl;
    }
}

void Interface::inputHandler(Event& event, Window& window) {
    if (event.type == Event::Closed) {
        window.close();
    }
}

bool Interface::drawButton(RenderWindow& window, float x, float y, float width, float height, const string& label, const string& fontPath, Color bgColor, Color textColor) {
    Font font;
    if (!font.loadFromFile(fontPath)) {
        cerr << "Erreur : Impossible de charger la police : " << fontPath << endl;
        return false;
    }

    RectangleShape buttonShape(Vector2f(width, height));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(bgColor);

    Text buttonText;
    buttonText.setFont(font);
    buttonText.setString(label);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(textColor);

    FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    buttonText.setPosition(x + width / 2, y + height / 2);

    window.draw(buttonShape);
    window.draw(buttonText);

    static bool buttonPressed = false;
    static bool mouseReleased = true;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
            if (mouseReleased && !buttonPressed) {
                buttonPressed = true;
                mouseReleased = false;
                return true;
            }
        }
    }
    else {
        mouseReleased = true;
        buttonPressed = false;
    }

    return false;
}

void Interface::gameGraph(RenderWindow& window, const vector<vector<Cellule>>& grille) {
    if (maGrille.getRows() == 0 || maGrille.getCols() == 0) {
        cerr << "Erreur : La grille n'est pas initialisée !" << endl;
        return;
    }

    for (size_t i = 0; i < grille.size(); ++i) {
        for (size_t j = 0; j < grille[i].size(); ++j) {
            RectangleShape caseShape(Vector2f(CASE_SIZE, CASE_SIZE));
            caseShape.setPosition(X_OFFSET + j * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
            caseShape.setFillColor(grille[i][j].getEtat() ? CASE_ALIVE_COLOR : CASE_DEAD_COLOR);
            window.draw(caseShape);

            caseShape.setOutlineThickness(1);
            caseShape.setOutlineColor(BORDER_COLOR);
            caseShape.setFillColor(Color::Transparent);
            window.draw(caseShape);
        }
    }

    // Ajout des lignes des bordures (omises dans la version courte, mais nécessaires pour le rendu)
    if (!grille.empty()) {
        for (size_t j = 0; j <= grille[0].size(); ++j) {
            VertexArray line(Lines, 2);
            line[0].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET);
            line[1].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET + grille.size() * CASE_SIZE);
            line[0].color = BORDER_COLOR;
            line[1].color = BORDER_COLOR;
            window.draw(line);
        }
    }

    window.display();
}

void Interface::credits(RenderWindow& window) {
    LoadFont();
    SetTxt(txt, "CREDITS :\n- Tilal MESSAOUDI \n- Mickael KING \n- Diego ODDOUX--AUBER\n- Bilel ROUABAH");
    window.display();
}